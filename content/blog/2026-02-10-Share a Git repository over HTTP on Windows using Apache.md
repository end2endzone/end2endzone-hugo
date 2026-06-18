---
title: 'Share a Git repository over HTTP on Windows using Apache'
author: end2end
date: 2026-02-10
categories:
  - Tutorial
tags:
  - Tutorial
  - Git
  - Apache
toc: true
toc_default_close: true
---

# Problem / Context

A Git repository should not be shared directly through a Windows shared folder when multiple users need concurrent access.

Although it may appear convenient, concurrent access to the repository can lead to corruption and other consistency issues.

There are safer alternatives. For example:
* Git over HTTP(S)
* Git over SSH
* Dedicated Git server software such as Gitolite, Gitea, or GitLab

*Git over HTTP(S)* is a common solution that can be implemented wiht Apache or Nginx. It provides proper concurrency handling and push/pull operations while remaining relatively easy to deploy in isolated or restricted environments.

This document explains how to expose Git repositories over HTTP using Apache HTTP Server and Git for Windows.

# Solution

The solution described in this document uses:

* Apache HTTP Server
* Git for Windows
* Git's `git-http-backend.exe`

The architecture is straightforward:

| Component               | Purpose                                                   |
| ----------------------- | --------------------------------------------------------- |
| Apache HTTP Server      | Serves HTTP requests                                      |
| git-http-backend.exe    | Implements the Git smart HTTP protocol as a cgibin script |
| Bare repositories       | Storage for Git repositories                              |
| htpasswd authentication | Optional access control                                   |

# Configuration steps

## Install Apache HTTP Server

### Download & Install

1. Open https://httpd.apache.org/download.cgi
2. Click **Files for Microsoft Windows**.
3. Click **Apache Lounge**.
4. Download `httpd-2.4.66-260131-Win64-VS18.zip`.
5. Extract the archive to: `D:\dev\Apache24`.

### Edit "D:\dev\Apache24\conf\httpd.conf"

1. Update ***SRVROOT***.  
   Change line 31 to `Define SRVROOT "D:/dev/Apache24"`.

2. Enable CGI Support.  
   Uncomment the following:
   `# LoadModule cgi_module modules/mod_cgi.so`.

3. Enable executable files for CGI.  
   In section `<IfModule mime_module>`, locate line `AddHandler cgi-script .cgi` and add `AddHandler cgi-script .exe` under *IfModule* node.

4. Configure Git HTTP Backend.  
   Append the following configuration at the end of `httpd.conf`:

   ```
   SetEnv GIT_PROJECT_ROOT D:/dev/repositories
   SetEnv GIT_HTTP_EXPORT_ALL
   
   # Link URLS that starts with /git/ with Git for Windows' cgi-bin's handler.
   ScriptAliasMatch ^/git/(.*) "C:/Program Files/Git/mingw64/libexec/git-core/git-http-backend.   exe/$1"
   
   # Define files under this directory as cgi-bin exe handler.
   <Directory "C:/Program Files/Git/mingw64/libexec/git-core">
     Options +ExecCGI
     AllowOverride None
     Require all granted
   </Directory>
   
   # Enable security with username/password authentification.
   # User names/passwords are from a local list stored in file git-users.htpasswd.
   # git clone and git fetch use git-upload-pack (read‑only). You usually want those open.
   # But It might be better to require authentication when pulling or cloning from a repository    (even in read-only).
   <LocationMatch "^/git/.*/git-upload-pack$">
     AuthType Basic
     AuthName "Git Access"
     AuthUserFile "${SRVROOT}/conf/git-users.htpasswd"
     Require valid-user
   </LocationMatch>
   
   # git push uses git-receive-pack. Restricting that location forces authentication when    someone tries to push.
   <LocationMatch "^/git/.*/git-receive-pack$">
     AuthType Basic
     AuthName "Git Access"
     AuthUserFile "${SRVROOT}/conf/git-users.htpasswd"
     Require valid-user
   </LocationMatch>
   ```

### Create usernames and password file

```bat
htpasswd -c ".\conf\git-users.htpasswd" john
```

The command will request a password for the new user name. For example, use `doe` for password.


### Clone a repository (install repositories)

Git for Windows' git-http-backend.exe requires "bare" repositories.
A bare repository is a cloned repo without the working copy files (only the database).
It "matches" the content of the `.git` directory of a normal cloned repository.

To clone a bare repository:
```bat
cd /d D:\dev\repositories
git clone --bare https://github.com/quartzquark/chess.git
```

The command above will create directory `D:\dev\repositories\chess.git`.

You can also convert a normal repository to a bare repository. This will only keep directory `chess/.git` as directory `chess.git` with the following command:  
`git clone --bare <normal-clone-directory-name> <name-of-bare-repo-directory>.git`.  

For example:

```bat
git clone --bare chess chess.git
```

### Create file `git-daemon-export-ok`

The `git-daemon-export-ok` file is a crucial component of the Git daemon, serving as a whitelist to prevent accidental exposure of repositories. It is an empty file that can be created in the .git directory of a Git repository. This file is not committed with the repository's code but is created to allow the Git daemon to export the repository. The presence of this file is necessary for the Git daemon to function correctly and for clients to clone or fetch from the repository.


From https://git-scm.com/docs/git-daemon :
> It verifies that the directory has the magic file "git-daemon-export-ok", and it will refuse to export any Git directory that hasn’t explicitly been marked for export this way (unless the --export-all parameter is specified). If you pass some directory paths as git daemon arguments, the offers are limited to repositories within those directories.

The following command to creates the file:
```bat
type nul > D:\dev\repositories\chess.git\git-daemon-export-ok
```

## Start Apache

Start Apache manually:

```bat
D:\dev\Apache24\bin\httpd.exe
```

# Testing

## Clone a Repository

Run:

```bash
git clone http://127.0.0.1/git/chess.git
```

Apache should request credentials on the first time.
Username/password are saved to Windows _Credential Manager_, under section `Windows Credential`. Look out for an entry named `git:http://127.0.0.1`, and verify that username is `john`.

## Expected Result

The repository should clone successfully.

# Troubleshooting

## warning: remote HEAD refers to nonexistent ref, unable to checkout

When you clone a reposotory, you may encounter the following warning:

```txt
warning: remote HEAD refers to nonexistent ref, unable to checkout
```

This occurs when the bare repository's `HEAD` points to a branch that does not exist. A common example is when HEAD refers to `refs/heads/master` when the repository actually uses `refs/heads/main`. This occurs when the repository's default branch configured is `master` instead of `main`. The default branch for a repository is stored in file `HEAD`. Print the content of `HEAD` file with the command `cat HEAD` to validate. It should output something similar to `refs/heads/master`. If there is no branch named `master` in this repository, then you shall get the warning message above when cloning the repository.

To fix it, do the following:

  1. Stop Apache's service or process.
  2. Open a Terminal or a Git Bash terminal.
  3. Browse to the bare repository directory.
  4. Check the current state of HEAD pointer with `cat HEAD`.
  5. Print the list of all references with the command `git show-ref`. This will output all existing branches and tags.
  6. Set HEAD to an existing branch. Enter the command `git symbolic-ref HEAD <NEW-REF>` where `<NEW-REF>` is one of the references printed with the previous command.
  For example:
  `git symbolic-ref HEAD refs/heads/main`.
  7. Retart Apache's service or process.
  8. Try to clone the repository again.

The warning should disappear.
