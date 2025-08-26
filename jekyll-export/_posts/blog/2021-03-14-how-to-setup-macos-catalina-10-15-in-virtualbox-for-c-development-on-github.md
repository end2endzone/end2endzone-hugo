---
title: How to setup macOS Catalina 10.15 in VirtualBox for C++ development on Github.
author: end2end
date: 2021-03-14T16:42:39+00:00
url: /how-to-setup-macos-catalina-10-15-in-virtualbox-for-c-development-on-github/
images:
  - src: /wp-content/uploads/2021/03/HOW-TO-SETUP-MACOS-CATALINA-10.15-IN-VIRTUALBOX-FOR-C-DEVELOPMENT-ON-GITHUB.jpg
hits:
  - 51
categories:
  - Development
tags:
  - c++
  - english

---

# Introduction

This post explains all the instructions required in order to get started with c++ no macOS 10.15 Catalina.

This article assumes that you already have access to a macOS image ISO file and that you already created a macOS virtual machine in VirtualBox.

# Update macOS with latest security updates and bug fixes

Following macOS Catalina 10.15 installation, it is best practice to update the Operating System with the latest software & security update.

1. Open *System Preferences*.
2. Click on *Software Update*, a new window will open.
3. Install all updates that are available for macOS Catalina 10.15.

At the time of this writing, the latest version of macOS Catalina is version 10.15.7.

*Note: You can install optional updates by clicking on* More info... *and selecting updates that are related to Catalina.*

# Set system preferences for developers

## Enable SSH and File sharing

1. Open *System Preferences*.
2. Click on *Sharing*.
3. Set a new *Computer hostname*:
    1. Locate *Computer Name* field.
    2. Click the *Edit* button.
    3. Set a meaningful value for the *Local Hostname*. For example `MACDEV01`.
    4. Click the *OK* button.
4. Check File Sharing.
    1. Click *Options...* button.
    2. In *Windows File Sharing* section, check you account name and enter your account password. This will make sure that shared folders requires a username/password for write access.
    3. Click on *Done* button.
5. Check *Remove Login*.
    1. Allow access for *All users* instead of only for Administrators.
    2. Note your computer *ip address* in the note *To log in to this computer remotely*.

## Add Terminal icon in Dock

By default, a *Terminal* icon is not already available in *Dock*. As most developers, you will probably require to use *Terminal* more than once. Do the following to add *Terminal* in *Dock*:

1. Open *Launchpad*.
2. Expand *Other* group.
3. Drag *Terminal* icon to *Dock*.

## Show address bar in Finder

By default, *Finder* does not show the address bar (the location of the current directory).

Open a *Terminal* and enter the following command:

```
defaults write com.apple.finder _FXShowPosixPathInTitle -bool YES && killall Finder
```

The command will change the default setting and restart all *Finder* application instances.

Also, enable the following *View settings* in *Finder* :

1. Click on menu *View*.
2. Select *Show Path Bar*.
3. Select *Show Status Bar*.

Source: [How can I get an address bar in Finder?](https://superuser.com/a/1209218)

## Show hidden file and folders in Finder

By default, *Finder* does not show hidden file and folders. As most developers, you will probably require enable this setting.

Open a *Terminal* and enter the following command:

```
defaults write com.apple.Finder AppleShowAllFiles true && killall Finder
```

The command will change the default setting and restart all *Finder* application instances.

Source: [How to Show Hidden Files on Mac](https://www.macworld.co.uk/how-to/show-hidden-files-mac-3520878/)

# Xcode

**Xcode** is [Apple's](https://en.wikipedia.org/wiki/Apple_Inc.) [integrated development environment](https://en.wikipedia.org/wiki/Integrated_development_environment) (IDE) for [macOS](https://en.wikipedia.org/wiki/MacOS), used to develop software for macOS.

## Install Xcode application

A relatively new version of xcode is required for c++ development on macOS. At the time of this writing, the latest version of xcode is 12 but we do not need to be using the latest version. It is better to use the previous stable version. At the time of this writing, xcode 11.7 is available. This [stackoverflow article](https://stackoverflow.com/questions/10335747/how-to-download-xcode-dmg-or-xip-file) defines the location of xcode 11.7 installation package.

1. Download [Xcode\_11.7.xip](https://developer.apple.com/services-account/download?path=/Developer_Tools/Xcode_11.7/Xcode_11.7.xip).
2. Open the file in *Finder* and double-click on it. Wait for the digital signature to validate. This will extract *Xcode.app* application file to the *Downloads* directory.
3. In *Finder*, move *Xcode.app* file to *Applications* folder.
4. Open LaunchPad and click on Xcode application. This will register Xcode tools with your account.

*Note: you will require a valid Apple ID for downloading the installation package.*

## Verify Xcode installation

To verify that Xcode is properly installed, open a *Terminal* and enter the command: `system_profiler SPDeveloperToolsDataType`.

The expected output is the following:

```
Developer:

    Developer Tools:

      Version: 11.7 (11E801a)
      Location: /Applications/Xcode.app
      Applications:
          Xcode: 11.7 (16142)
          Instruments: 11.7 (64535.78)
      SDKs:
          iOS:
              13.7: (17H22)
          iOS Simulator:
              13.7: (17H22)
          macOS:
              10.15.6: (19G68)
              19.0:
          tvOS:
              13.4: (17L255)
          tvOS Simulator:
              13.4: (17L255)
          watchOS:
              6.2: (17T255)
          watchOS Simulator:
              6.2: (17T255)
```

Once Xcode is properly registered on the system, you can delete file *Xcode\_11.7.xip*.

# Install VirtualBox's Guest Additions

On macOS 10.15 Catalina, *Guest Additions* cannot be installed by default. The installation cannot be completed as normal because the OS now require packages to be digitally signed. I think this applies to macOS 10.14 Mojave as well. To get around this security limitation, you need to disable **multiple security features** in order to install the package.

To install *Guest Additions* using VirtualBox version 6.1.16 on Windows 7 to share the clipboard values between the host and the guest. If someone else wants to install this, here is the whole process:

## Disable Gatekeeper

1. Be sure to exit *System Preferences* on your Mac.
2. Open a Terminal
3. Enter the command `sudo spctl --master-disable`.

Source: [How to open apps from unidentified developers on Mac in macOS Catalina](https://www.imore.com/how-open-apps-anywhere-macos-catalina-and-mojave)

## Check Gatekeeper is disabled

1. Click on *System Preferences* on your Mac Dock.
2. Choose *Security & Privacy*.
3. Look at *Allow apps download from:*, it should be set to `Anywhere`. If it is, you are done.
4. If not, click the lock icon at the bottom left of the screen.
5. Choose the `Anywhere` option under *Allow apps downloaded from*. Prior to making the change, this option wasn't available.
6. Click the unlocked lock again to keep the change.

## Disable SIP (System Integrity Protection) and allow Oracle identifier for kext

1. Restart your computer in *Recovery mode*. In your VM's terminal enter the following command :  
    `sudo nvram recovery-boot-mode=unused && sudo shutdown -r now`.
2. Launch *Terminal* from the *Utilities* menu.
3. Run the command `csrutil disable` which will disable SIP.
4. Run the command `spctl kext-consent add VB5E2TV963` which will allow Oracle identifier for *kext*.
5. Restart your computer and exit *Recovery Mode*. In your VM's terminal enter the following command :  
    `nvram -d recovery-boot-mode && shutdown -r now`.

*Note: `VB5E2TV963` is the code for oracle.*

Source: [Install problem 10.14.5 vBox 6.0](https://forums.virtualbox.org/viewtopic.php?f=8&t=93133#p448593)

## Check SIP is disabled

You can verify that SIP is disabled with the command:  
`csrutil status`  
which should display:  
`System Integrity Protection status: disabled.`.

## Change ownership and permissions on filesystem

Enable writing to `/System/Library/Extensions/`.

In your VM's terminal enter the following commands:

```
sudo mount -uw /
sudo chown :admin /System/Library/Extensions/
sudo chmod 775 /System/Library/Extensions/
```

Source: [Guest Additions not installing on macOS 10.15 Catalina guests](https://www.virtualbox.org/ticket/19047#comment:6)

## Install Guest Additions

At this point, the installation of *Guest Addition* should succeed. Proceed with normal installation instructions:

1. On VirtualBox emulation window, click on *Devices* menu.
2. Select *Insert Guest Additions CD image...* .
3. In your VM, click on the new CD image on the desktop.
4. Click on *VBoxDarwinAdditions.pkg*.
5. Follow the instructions on screen.
6. A reboot is required after the installation.

## Check clipboard sharing is working

Check that clipboard is shared between the host and the guest.

1. On VirtualBox emulation window, click on *Devices* menu.
2. Select menu *Shared Clipboard* -&gt; *Bidirectional*.
3. In your VM, open a terminal.
4. Select text.
5. Right-click on the selected text and select *Copy*.
6. On your host, open a note taking application.
7. Right-click and select *Paste*.

## Enable Gatekeeper

1. Be sure to exit *System Preferences* on your Mac.
2. Open a Terminal
3. Enter the command `sudo spctl --master-enable`.

## Enable SIP

1. Restart your computer in *Recovery mode*.
2. Launch *Terminal* from the *Utilities* menu.
3. Run the command `csrutil enable` .
4. Restart your computer.

# Install Homebrew

[Homebrew](http://brew.sh/) is a free and open-source software [package management system](https://en.wikipedia.org/wiki/Package_manager) that simplifies the installation of software on Apple's operating system macOS as well as Linux.

You can install *Homebrew* with the following commands:

1. Open a *Terminal* app.
2. Enter the command  
    `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`.
3. You'll see messages in the *Terminal* explaining what you need to do to complete the installation process.

Source: [Installing Homebrew on a Mac](https://treehouse.github.io/installation-guides/mac/homebrew).

# Install CMake command line via Homebrew

[CMake](https://cmake.org/) is cross-platform free and open-source software for build automation, testing and packaging using a compiler-independent method. CMake is not a build system but rather it's a build-system generator.

cmake can be installed with the following command:  
`brew install cmake`

# Install CMake (GUI version)

The GUI version of [CMake](https://cmake.org/) can be installed with these instructions:

1. Open [CMake download page](https://cmake.org/download/).
2. Search for the *Latest Release* section and then *Binary distributions* section.
3. Download the dmg installer for *Mac OS X 10.13 or later*. At the time of this writing, the file [cmake-3.19.6-macos-universal.dmg](https://github.com/Kitware/CMake/releases/download/v3.19.6/cmake-3.19.6-macos-universal.dmg) is available.
4. Locate the downloaded file in *Finder* and double-click the file. A new window will open
5. Drag the CMake triangle icon over the *Applications* folder, making it available in the *macOS Launchpad*.
6. Add CMake to your *Dock* by right-clicking on the icon to bring up the context menu and choosing **Options**, **Keep in Dock**.

# Install GCC via Homebrew

GCC stands for *GNU Compiler Collections* which is used to compile mainly C and C++ source code. It can also be used to compile Objective C and Objective C++.

gcc can be installed with the following command:  
`brew install gcc`

Source: [How does one install GCC on a Mac?](https://discussions.apple.com/thread/8336714)

# Register Xcode as current Command Line Tools

Following the installation of *Xcode*, the application may not be registered on the system as the current *Command Line Tools*.

The cause of the issue is one of the following errors when compiling :

* fatal error: limits.h: No such file or directory
* fatal error: 'wchar.h' file not found
* The output of command `xcode-select -p` outputs `/Library/Developer/CommandLineTools`.

This is documented as a bug at the following locations:

* <https://stackoverflow.com/questions/30877659/fatal-error-limits-h-no-such-file-or-directory>
* <https://github.com/qutip/qutip/issues/1030>
* <https://stackoverflow.com/questions/62523093/compile-llvm-from-sources-on-macos-catalina-how-to-solve-stdio-h-not-found>
* <https://github.com/AcademySoftwareFoundation/OpenShadingLanguage/issues/1055>
* <https://stackoverflow.com/questions/52509602/cant-compile-c-program-on-a-mac-after-upgrade-to-mojave>

The solution is to register (again) Xcode as the current current Command Line Tools:

1. Open *Launchpad*.
2. Select *Xcode*.
3. In *Xcode* menu, select *Preferences*.
4. Click on *Locations* tab.
5. In *Command Line Tools* field, select *Xcode 11.7 (11E801a)*.

Validate the change with the command `xcode-select -p` which should output `/Applications/Xcode.app/Contents/Developer`.

Then create a simlink for a missing directory. The instruction is detailed [here](https://stackoverflow.com/a/63207834).  
Enter the following command in a *Terminal* :  
`ln -s /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk`.

# Install Visual Studio Code

[Visual Studio Code](https://code.visualstudio.com/) is a freeware source-code editor made by Microsoft for Windows, Linux and macOS. Features include support for debugging, syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git. Users can change the theme, keyboard shortcuts, preferences, and install extensions that add additional functionality.

1. [Download Visual Studio Code](https://go.microsoft.com/fwlink/?LinkID=534106) for macOS.
2. Open the browser's download list and locate the downloaded archive.
3. Select the *magnifying glass* icon to open the archive in *Finder*.
4. Drag `Visual Studio Code.app` to the `Applications` folder, making it available in the macOS Launchpad.
5. Add VS Code to your Dock by right-clicking on the icon to bring up the context menu and choosing **Options**, **Keep in Dock**.

Source: [Running Visual Studio Code on macOS](https://code.visualstudio.com/docs/setup/mac)

### Install required Extensions

1. Open *Visual Studio Code*.
2. On the left toolbar, click the *Extensions* icon.
3. Search and install the following extensions:
    - C/C++
    - CMake
    - CMake Tools

# Configure SSH keys

If you use GitHub without setting up an SSH key, you're really missing out. Using ssh keys allow you to connect to other systems without having to provide a username and password.

## Find out if you already have ssh keys on your system

ssh keys are stored in `$HOME/.ssh` directory. The *private* and *public* keys are usually named `id_rsa` and `id_rsa.pub`.

If this directory does not exists on your system and you cannot find these files, you don't have ssh keys defined for your system. Continue to the next section for instructions on how to *import* or *create* new ssh keys.

If your keys already exist, skip ahead to the [Configure Git for Github](#configure-git-for-github) section below.

## Import existing generated keys

*Note: This section is for importing keys that you have generated previously. For example, if you are restoring a system backup, you may like to use the same key as previously. If you did not generate keys for your system, you can skip this section.*

`ssh-agent` is a program that starts when you log in and stores your private keys. For it to work properly, it needs to be running and have a copy of your private key.

1. Make sure that *ssh-agent* is running with the command :  
    `eval "$(ssh-agent -s)"`  
    The output should look like this:  
    `Agent pid 1030`
2. Create the *.ssh* directory in user's home directory with the command :  
    `mkdir -p ~/.ssh`
3. Copy your existing public and private keys to `$HOME/.ssh` directory.
4. Add your **private** key to *ssh-agent* with the command :  
    `ssh-add ~/.ssh/your_filename` where *your\_filename* is the name of your private key.

## Generate a new set of keys

1. Create the *.ssh* directory in user's home directory with the command :  
    `mkdir -p ~/.ssh`
2. Create a new pair of keys with the command :  
    `ssh-keygen -o`
3. Validate the new keys with the command :  
    `ls -al $HOME/.ssh`
4. Print the content of your public key with the command :  
    `cat ~/.ssh/id_rsa.pub`

The command output should look something like this:

```
ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAklOUpkDHrfHY17SbrmTIpNLTGK9Tjom/BWDSU
GPl+nafzlHDTYW7hdI4yZ5ew18JH4JW9jbhUFrviQzM7xlELEVf4h9lFX5QVkbPppSwg0cda3
Pbv7kOdJ/MTyBlWXFCR+HAo3FXRitBqxiX1nKhXpHAZsMciLq8V6RjsNAQwdsdMFvSlVK/7XA
t3FaoJoAsncM1Q9x5+3V0Ww68/eIFmb1zuUFljQJKprrX88XypNDvjYNby6vw/Pb0rwert/En
mZ+AW4OZPnTPI89ZPmVMLuayrD2cE86Z/il8b+gw3r3+1nKatmIkjn2so1d01QraTlMqVSsbx
NrRFi9wrf+M7Q==
```

*Note: SSH keys are always generated as a pair of public (`id_rsa.pub`) and private (`id_rsa`) keys. It's extremely important that you **never reveal your private key**, and only use your public key for things like GitHub authentication.*

Source: [Git on the Server - Generating Your SSH Public Key](https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key).

# Configure Git for Github

[Git](https://git-scm.com/) is bundled with Xcode and should be already installed on the system. You can verify if git is installed with the command `git --version`.

## Set your user global settings

Before make change to a repository, git should be configured with your username and email address.  
Open a *Terminal* and enter the following commands:

```
git config --global user.name "myusername"
git config --global user.email "myemailaddress@gmail.com"
```

Where `myusername` and `myemailaddress@gmail.com` must be replaced with your desired username (preferably one matching your github account) and your email address, respectively.

Source: [Git - Generating Your SSH Public Key](https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key#_generate_ssh_key)

## Add your public SSH key to your Github account

Online Git servers such as *Gitlab*, *Bitbucket* or *Github* provides authentication services using ssh keys. As a general rules, you must add your public key to your account. The following instructions shows how to do so with Github.

1. Copy your public SSH key to the clipboard with the command :  
    `cat ~/.ssh/id_rsa.pub`
2. Highlight the output of the command and copy to the clipboard.
3. Go to your [GitHub SSH keys settings](https://github.com/settings/keys) page and click the *New SSH key* button.
4. Give your key a recognizable title (such as `MACDEV01`) and paste in your public (`id_rsa.pub`) key.

Finally, test your authentication with:

```
ssh -T git@github.com
```

If you've followed all of these steps correctly, you should see this message:

```
The authenticity of host 'github.com (140.82.114.3)' can't be established.
RSA key fingerprint is SHA256:nThbdj6RGJ48dhvldj3gawbEH48DjmV2LviKw6EFFB8.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com,140.82.114.3' (RSA) to the list of known hosts.
Hi your_user_name! You've successfully authenticated, but GitHub does not provide shell access.
```

Where `your_user_name` matches your actual Github username.

# Test C++ compilation in Terminal

At this point, you should be ready to compile c++ code in *Terminal*. These instructions show how to compile [googletest](https://github.com/google/googletest), Google Testing and Mocking Framework.

Checkout the code from github with :

```
mkdir -p ~/dev
cd ~/dev
git clone "https://github.com/google/googletest.git"
cd googletest
```

The commands above will create directory `~/dev/googletest` with *googletest* source code.

Create the *build system* directory with :

```
mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=~/dev/install -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DBUILD_GMOCK=OFF -DBUILD_GTEST=ON ..
```

Build and install *googletest* with :

```
cmake --build . --parallel 4
cmake --build . --target install
```

This commands above will build googletest with 4 cores and install the library in `~/dev/install` directory.

# Test C++ compilation with Visual Studio Code

These instructions show how to compile [zlib](https://github.com/madler/zlib), a massively spiffy yet delicately unobtrusive compression library.

1. Open *Visual Studio Code*.
2. On the left toolbar, click the *Source Control* icon.
3. Click on the *Clone Repository* button.
4. A [Command Pallet](https://code.visualstudio.com/docs/getstarted/userinterface#_command-palette) will open.
5. Enter the following url: `https://github.com/madler/zlib.git` and press `enter`.
6. Select the location where to checkout the repository. For example, `~/dev`.
7. Wait for the repository to checkout.
8. A notification window will appear and ask *Would you like to open the cloned repository?* Click *Open* button.
9. On the left toolbar, click the *CMake* icon.
10. At the top of the window, click on *Configure All Projects* icon.
11. A *Command Pallet* will open.
12. Select *\[Unspecified\] (Let CMake guess what compilers and environment to use)* option.
13. Wait for the configuration to complete.
14. At the top of the window, click on *Build All Projects* icon.
15. Wait for the build to complete.
16. Right-click on the *example* target and select *Run in Terminal* menu item.
17. The Terminal should output the following: `/Users/your_user_name/dev/zlib/build/example zlib version 1.2.11 = 0x12b0, compile flags = 0xa9 uncompress(): hello, hello! gzread(): hello, hello! gzgets() after gzseek: hello! inflate(): hello, hello! large_inflate(): OK after inflateSync(): hello, hello! inflate with dictionary: hello, hello!`

You can also allow the extension to connect to your *personal GitHub account* in order to checkout your own repositories:

1. In the *Command Pallet*, select option *Clone from GitHub*.
2. The extension 'GitHub' may request your to sign in to GitHub.
    1. Click *Allow* button.
    2. A *Safari* window will open which request *Authorization for Visual Studio Code to access GitHub*.
    3. Click *Continue* button.
    4. Enter your *GitHub credentials* and click on *Sign In* button.
    5. Read the given permissions and click on *Authorize github*.
    6. In the *Safari* window, note *Your Authorization Token*. It should look like the following: `vscode://vscode.github-authentication/did-authenticate?windowid=1&code=ca7506dce69e40699277&state=5c05c8f1-9af0-4630-b257-3fe8adeb9a75`.
    7. To use the token, in *Visual Studio Code*, click *Signing in to github.com...* in the status bar.
    8. Paste the token and hit enter.
3. In Visual Studio Code, allow the extension to open your token url.
    1. Check *Don't ask again for this extension*.
    2. Click the *Open* button.
4. Select the location where to checkout the repository. For example, `~/dev/mygithubrepositories`.

## Cloning GitHub repo with Visual Studio Code

At the time of this writing, when a user clone one of his own GitHub repository using *Visual Studio Code*, the URL used for cloning is in format `https://github.com/<Username>/<Project>.git` instead of using the url in format `git@github.com:<Username>/<Project>.git`. Using the `https` url force users to enter their GitHub *username* and *password* everytime they want to push changes to GitHub.

You can validate the remote origin url with the following command :  
`git config --get remote.origin.url`.

To get around this, one must change the remote url format from `https://github.com/<Username>/<Project>.git` to `git@github.com:<Username>/<Project>.git`. The instructions for this are explained in [Push to GitHub without a password using ssh-key](https://stackoverflow.com/questions/14762034/push-to-github-without-a-password-using-ssh-key).

Enter the following command to change the remote origin url :  
`git remote set-url origin git@github.com:<Username>/<Project>.git`  
where `<Username>` and `<Project>` are replaced with the correct values.