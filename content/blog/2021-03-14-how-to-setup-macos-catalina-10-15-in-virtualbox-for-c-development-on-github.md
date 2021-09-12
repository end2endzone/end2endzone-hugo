---
title: How to setup macOS Catalina 10.15 in VirtualBox for C++ development on Github.
author: end2end
type: post
date: 2021-03-14T16:42:39+00:00
url: /how-to-setup-macos-catalina-10-15-in-virtualbox-for-c-development-on-github/
featured_image: /wp-content/uploads/2021/03/HOW-TO-SETUP-MACOS-CATALINA-10.15-IN-VIRTUALBOX-FOR-C-DEVELOPMENT-ON-GITHUB-672x378.jpg
hits:
  - 51
categories:
  - Development
tags:
  - c++
  - english

---
# <span id="Introduction">Introduction</span>

This post explains all the instructions required in order to get started with c++ no macOS 10.15 Catalina.

This article assumes that you already have access to a macOS image ISO file and that you already created a macOS virtual machine in VirtualBox.

# <span id="Update_macOS_with_latest_security_updates_and_bug_fixes">Update macOS with latest security updates and bug fixes</span>

Following macOS Catalina 10.15 installation, it is best practice to update the Operating System with the latest software & security update.

  1. Open _System Preferences_.
  2. Click on _Software Update_, a new window will open.
  3. Install all updates that are available for macOS Catalina 10.15.

At the time of this writing, the latest version of macOS Catalina is version 10.15.7.

_Note: You can install optional updates by clicking on_ More info&#8230; _and selecting updates that are related to Catalina._

 

# <span id="Set_system_preferences_for_developers">Set system preferences for developers</span>

## <span id="Enable_SSH_and_File_sharing">Enable SSH and File sharing</span>

  1. Open _System Preferences_.
  2. Click on _Sharing_.
  3. Set a new _Computer hostname_:
      1. Locate _Computer Name_ field.
      2. Click the _Edit_ button.
      3. Set a meaningful value for the _Local Hostname_. For example `MACDEV01`.
      4. Click the _OK_ button.
  4. Check File Sharing.
      1. Click _Options&#8230;_ button.
      2. In _Windows File Sharing_ section, check you account name and enter your account password. This will make sure that shared folders requires a username/password for write access.
      3. Click on _Done_ button.
  5. Check _Remove Login_.
      1. Allow access for _All users_ instead of only for Administrators.
      2. Note your computer _ip address_ in the note _To log in to this computer remotely_.

## <span id="Add_Terminal_icon_in_Dock">Add Terminal icon in Dock</span>

By default, a _Terminal_ icon is not already available in _Dock_. As most developers, you will probably require to use _Terminal_ more than once. Do the following to add _Terminal_ in _Dock_:

  1. Open _Launchpad_.
  2. Expand _Other_ group.
  3. Drag _Terminal_ icon to _Dock_.

## <span id="Show_address_bar_in_Finder">Show address bar in Finder</span>

By default, _Finder_ does not show the address bar (the location of the current directory).

Open a _Terminal_ and enter the following command:

<pre class="wp-block-code"><code>defaults write com.apple.finder _FXShowPosixPathInTitle -bool YES && killall Finder</code></pre>

The command will change the default setting and restart all _Finder_ application instances.

Also, enable the following _View settings_ in _Finder_ :

  1. Click on menu _View_.
  2. Select _Show Path Bar_.
  3. Select _Show Status Bar_.

Source: [How can I get an address bar in Finder?][1]

## <span id="Show_hidden_file_and_folders_in_Finder">Show hidden file and folders in Finder</span>

By default, _Finder_ does not show hidden file and folders. As most developers, you will probably require enable this setting.

Open a _Terminal_ and enter the following command:

<pre class="wp-block-code"><code>defaults write com.apple.Finder AppleShowAllFiles true && killall Finder</code></pre>

The command will change the default setting and restart all _Finder_ application instances.

Source: [How to Show Hidden Files on Mac][2]

# <span id="Xcode">Xcode</span>

**Xcode** is [Apple&#8217;s][3] [integrated development environment][4] (IDE) for [macOS][5], used to develop software for macOS.

## <span id="Install_Xcode_application">Install Xcode application</span>

A relatively new version of xcode is required for c++ development on macOS. At the time of this writing, the latest version of xcode is 12 but we do not need to be using the latest version. It is better to use the previous stable version. At the time of this writing, xcode 11.7 is available. This [stackoverflow article][6] defines the location of xcode 11.7 installation package.

  1. Download [Xcode_11.7.xip][7].
  2. Open the file in _Finder_ and double-click on it. Wait for the digital signature to validate. This will extract _Xcode.app_ application file to the _Downloads_ directory.
  3. In _Finder_, move _Xcode.app_ file to _Applications_ folder.
  4. Open LaunchPad and click on Xcode application. This will register Xcode tools with your account.

_Note: you will require a valid Apple ID for downloading the installation package._

## <span id="Verify_Xcode_installation">Verify Xcode installation</span>

To verify that Xcode is properly installed, open a _Terminal_ and enter the command: `system_profiler SPDeveloperToolsDataType`.

The expected output is the following:

<pre class="wp-block-code"><code>Developer:

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
              6.2: (17T255)</code></pre>

Once Xcode is properly registered on the system, you can delete file _Xcode_11.7.xip_.

# <span id="Install_VirtualBox8217s_Guest_Additions">Install VirtualBox&#8217;s Guest Additions</span>

On macOS 10.15 Catalina, _Guest Additions_ cannot be installed by default. The installation cannot be completed as normal because the OS now require packages to be digitally signed. I think this applies to macOS 10.14 Mojave as well. To get around this security limitation, you need to disable **multiple security features** in order to install the package.

To install _Guest Additions_ using VirtualBox version 6.1.16 on Windows 7 to share the clipboard values between the host and the guest. If someone else wants to install this, here is the whole process:

## <span id="Disable_Gatekeeper">Disable Gatekeeper</span>

  1. Be sure to exit _System Preferences_ on your Mac.
  2. Open a Terminal
  3. Enter the command `sudo spctl --master-disable`.

Source: [How to open apps from unidentified developers on Mac in macOS Catalina][8]

## <span id="Check_Gatekeeper_is_disabled">Check Gatekeeper is disabled</span>

  1. Click on _System Preferences_ on your Mac Dock.
  2. Choose _Security & Privacy_.
  3. Look at _Allow apps download from:_, it should be set to `Anywhere`. If it is, you are done.
  4. If not, click the lock icon at the bottom left of the screen.
  5. Choose the `Anywhere` option under _Allow apps downloaded from_. Prior to making the change, this option wasn&#8217;t available.
  6. Click the unlocked lock again to keep the change.

## <span id="Disable_SIP_System_Integrity_Protection_and_allow_Oracle_identifier_for_kext">Disable SIP (System Integrity Protection) and allow Oracle identifier for kext</span>

  1. Restart your computer in _Recovery mode_. In your VM&#8217;s terminal enter the following command :  
    `sudo nvram recovery-boot-mode=unused && sudo shutdown -r now`.
  2. Launch _Terminal_ from the _Utilities_ menu.
  3. Run the command `csrutil disable` which will disable SIP.
  4. Run the command `spctl kext-consent add VB5E2TV963` which will allow Oracle identifier for _kext_.
  5. Restart your computer and exit _Recovery Mode_. In your VM&#8217;s terminal enter the following command :  
    `nvram -d recovery-boot-mode && shutdown -r now`.

_Note: `VB5E2TV963` is the code for oracle._

Source: [Install problem 10.14.5 vBox 6.0][9]

## <span id="Check_SIP_is_disabled">Check SIP is disabled</span>

You can verify that SIP is disabled with the command:  
`csrutil status`  
which should display:  
`System Integrity Protection status: disabled.`.

## <span id="Change_ownership_and_permissions_on_filesystem">Change ownership and permissions on filesystem</span>

Enable writing to `/System/Library/Extensions/`.

In your VM&#8217;s terminal enter the following commands:

<pre class="wp-block-code"><code>sudo mount -uw /
sudo chown :admin /System/Library/Extensions/
sudo chmod 775 /System/Library/Extensions/</code></pre>

Source: [Guest Additions not installing on macOS 10.15 Catalina guests][10]

## <span id="Install_Guest_Additions">Install Guest Additions</span>

At this point, the installation of _Guest Addition_ should succeed. Proceed with normal installation instructions:

  1. On VirtualBox emulation window, click on _Devices_ menu.
  2. Select _Insert Guest Additions CD image&#8230;_ .
  3. In your VM, click on the new CD image on the desktop.
  4. Click on _VBoxDarwinAdditions.pkg_.
  5. Follow the instructions on screen.
  6. A reboot is required after the installation.

## <span id="Check_clipboard_sharing_is_working">Check clipboard sharing is working</span>

Check that clipboard is shared between the host and the guest.

  1. On VirtualBox emulation window, click on _Devices_ menu.
  2. Select menu _Shared Clipboard_ -> _Bidirectional_.
  3. In your VM, open a terminal.
  4. Select text.
  5. Right-click on the selected text and select _Copy_.
  6. On your host, open a note taking application.
  7. Right-click and select _Paste_.

## <span id="Enable_Gatekeeper">Enable Gatekeeper</span>

  1. Be sure to exit _System Preferences_ on your Mac.
  2. Open a Terminal
  3. Enter the command `sudo spctl --master-enable`.

## <span id="Enable_SIP">Enable SIP</span>

  1. Restart your computer in _Recovery mode_.
  2. Launch _Terminal_ from the _Utilities_ menu.
  3. Run the command `csrutil enable` .
  4. Restart your computer.

# <span id="Install_Homebrew">Install Homebrew</span>

[Homebrew][11] is a free and open-source software [package management system][12] that simplifies the installation of software on Apple&#8217;s operating system macOS as well as Linux.

You can install _Homebrew_ with the following commands:

  1. Open a _Terminal_ app.
  2. Enter the command  
    `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`.
  3. You’ll see messages in the _Terminal_ explaining what you need to do to complete the installation process.

Source: [Installing Homebrew on a Mac][13].

# <span id="Install_CMake_command_line_via_Homebrew">Install CMake command line via Homebrew</span>

[CMake][14] is cross-platform free and open-source software for build automation, testing and packaging using a compiler-independent method. CMake is not a build system but rather it&#8217;s a build-system generator.

cmake can be installed with the following command:  
`brew install cmake`

# <span id="Install_CMake_GUI_version">Install CMake (GUI version)</span>

The GUI version of [CMake][14] can be installed with these instructions:

  1. Open [CMake download page][15].
  2. Search for the _Latest Release_ section and then _Binary distributions_ section.
  3. Download the dmg installer for _Mac OS X 10.13 or later_. At the time of this writing, the file [cmake-3.19.6-macos-universal.dmg][16] is available.
  4. Locate the downloaded file in _Finder_ and double-click the file. A new window will open
  5. Drag the CMake triangle icon over the _Applications_ folder, making it available in the _macOS Launchpad_.
  6. Add CMake to your _Dock_ by right-clicking on the icon to bring up the context menu and choosing **Options**, **Keep in Dock**.

# <span id="Install_GCC_via_Homebrew">Install GCC via Homebrew</span>

GCC stands for _GNU Compiler Collections_ which is used to compile mainly C and C++ source code. It can also be used to compile Objective C and Objective C++.

gcc can be installed with the following command:  
`brew install gcc`

Source: [How does one install GCC on a Mac?][17]

# <span id="Register_Xcode_as_current_Command_Line_Tools">Register Xcode as current Command Line Tools</span>

Following the installation of _Xcode_, the application may not be registered on the system as the current _Command Line Tools_.

The cause of the issue is one of the following errors when compiling :

  * fatal error: limits.h: No such file or directory
  * fatal error: &#8216;wchar.h&#8217; file not found
  * The output of command `xcode-select -p` outputs `/Library/Developer/CommandLineTools`.

This is documented as a bug at the following locations:

  * <https://stackoverflow.com/questions/30877659/fatal-error-limits-h-no-such-file-or-directory>
  * <https://github.com/qutip/qutip/issues/1030>
  * <https://stackoverflow.com/questions/62523093/compile-llvm-from-sources-on-macos-catalina-how-to-solve-stdio-h-not-found>
  * <https://github.com/AcademySoftwareFoundation/OpenShadingLanguage/issues/1055>
  * <https://stackoverflow.com/questions/52509602/cant-compile-c-program-on-a-mac-after-upgrade-to-mojave>

The solution is to register (again) Xcode as the current current Command Line Tools:

  1. Open _Launchpad_.
  2. Select _Xcode_.
  3. In _Xcode_ menu, select _Preferences_.
  4. Click on _Locations_ tab.
  5. In _Command Line Tools_ field, select _Xcode 11.7 (11E801a)_.

Validate the change with the command `xcode-select -p` which should output `/Applications/Xcode.app/Contents/Developer`.

Then create a simlink for a missing directory. The instruction is detailed [here][18].  
Enter the following command in a _Terminal_ :  
`ln -s /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk`.

# <span id="Install_Visual_Studio_Code">Install Visual Studio Code</span>

[Visual Studio Code][19] is a freeware source-code editor made by Microsoft for Windows, Linux and macOS. Features include support for debugging, syntax highlighting, intelligent code completion, snippets, code refactoring, and embedded Git. Users can change the theme, keyboard shortcuts, preferences, and install extensions that add additional functionality.

  1. [Download Visual Studio Code][20] for macOS.
  2. Open the browser&#8217;s download list and locate the downloaded archive.
  3. Select the _magnifying glass_ icon to open the archive in _Finder_.
  4. Drag `Visual Studio Code.app` to the `Applications` folder, making it available in the macOS Launchpad.
  5. Add VS Code to your Dock by right-clicking on the icon to bring up the context menu and choosing **Options**, **Keep in Dock**.

Source: [Running Visual Studio Code on macOS][21]

### <span id="Install_required_Extensions">Install required Extensions</span>

  1. Open _Visual Studio Code_.
  2. On the left toolbar, click the _Extensions_ icon.
  3. Search and install the following extensions:
      * C/C++
      * CMake
      * CMake Tools

# <span id="Configure_SSH_keys">Configure SSH keys</span>

If you use GitHub without setting up an SSH key, you&#8217;re really missing out. Using ssh keys allow you to connect to other systems without having to provide a username and password.

## <span id="Find_out_if_you_already_have_ssh_keys_on_your_system">Find out if you already have ssh keys on your system</span>

ssh keys are stored in `$HOME/.ssh` directory. The _private_ and _public_ keys are usually named `id_rsa` and `id_rsa.pub`.

If this directory does not exists on your system and you cannot find these files, you don&#8217;t have ssh keys defined for your system. Continue to the next section for instructions on how to _import_ or _create_ new ssh keys.

If your keys already exist, skip ahead to the [Configure Git for Github][22] section below.

## <span id="Import_existing_generated_keys">Import existing generated keys</span>

_Note: This section is for importing keys that you have generated previously. For example, if you are restoring a system backup, you may like to use the same key as previously. If you did not generate keys for your system, you can skip this section._

`ssh-agent` is a program that starts when you log in and stores your private keys. For it to work properly, it needs to be running and have a copy of your private key.

  1. Make sure that _ssh-agent_ is running with the command :  
    `eval "$(ssh-agent -s)"`  
    The output should look like this:  
    `Agent pid 1030`
  2. Create the _.ssh_ directory in user&#8217;s home directory with the command :  
    `mkdir -p ~/.ssh`
  3. Copy your existing public and private keys to `$HOME/.ssh` directory.
  4. Add your **private** key to _ssh-agent_ with the command :  
    `ssh-add ~/.ssh/your_filename` where _your_filename_ is the name of your private key.

## <span id="Generate_a_new_set_of_keys">Generate a new set of keys</span>

  1. Create the _.ssh_ directory in user&#8217;s home directory with the command :  
    `mkdir -p ~/.ssh`
  2. Create a new pair of keys with the command :  
    `ssh-keygen -o`
  3. Validate the new keys with the command :  
    `ls -al $HOME/.ssh`
  4. Print the content of your public key with the command :  
    `cat ~/.ssh/id_rsa.pub`

The command output should look something like this:

<pre class="wp-block-code"><code>ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAklOUpkDHrfHY17SbrmTIpNLTGK9Tjom/BWDSU
GPl+nafzlHDTYW7hdI4yZ5ew18JH4JW9jbhUFrviQzM7xlELEVf4h9lFX5QVkbPppSwg0cda3
Pbv7kOdJ/MTyBlWXFCR+HAo3FXRitBqxiX1nKhXpHAZsMciLq8V6RjsNAQwdsdMFvSlVK/7XA
t3FaoJoAsncM1Q9x5+3V0Ww68/eIFmb1zuUFljQJKprrX88XypNDvjYNby6vw/Pb0rwert/En
mZ+AW4OZPnTPI89ZPmVMLuayrD2cE86Z/il8b+gw3r3+1nKatmIkjn2so1d01QraTlMqVSsbx
NrRFi9wrf+M7Q==</code></pre>

_Note: SSH keys are always generated as a pair of public (`id_rsa.pub`) and private (`id_rsa`) keys. It&#8217;s extremely important that you **never reveal your private key**, and only use your public key for things like GitHub authentication._

Source: [Git on the Server &#8211; Generating Your SSH Public Key][23].

# <span id="Configure_Git_for_Github">Configure Git for Github</span>

[Git][24] is bundled with Xcode and should be already installed on the system. You can verify if git is installed with the command `git --version`.

## <span id="Set_your_user_global_settings">Set your user global settings</span>

Before make change to a repository, git should be configured with your username and email address.  
Open a _Terminal_ and enter the following commands:

<pre class="wp-block-code"><code>git config --global user.name "myusername"
git config --global user.email "myemailaddress@gmail.com"</code></pre>

Where `myusername` and `myemailaddress@gmail.com` must be replaced with your desired username (preferably one matching your github account) and your email address, respectively.

Source: [Git &#8211; Generating Your SSH Public Key][25]

## <span id="Add_your_public_SSH_key_to_your_Github_account">Add your public SSH key to your Github account</span>

Online Git servers such as _Gitlab_, _Bitbucket_ or _Github_ provides authentication services using ssh keys. As a general rules, you must add your public key to your account. The following instructions shows how to do so with Github.

  1. Copy your public SSH key to the clipboard with the command :  
    `cat ~/.ssh/id_rsa.pub`
  2. Highlight the output of the command and copy to the clipboard.
  3. Go to your [GitHub SSH keys settings][26] page and click the _New SSH key_ button.
  4. Give your key a recognizable title (such as `MACDEV01`) and paste in your public (`id_rsa.pub`) key.

Finally, test your authentication with:

<pre class="wp-block-code"><code>ssh -T git@github.com</code></pre>

If you&#8217;ve followed all of these steps correctly, you should see this message:

<pre class="wp-block-code"><code>The authenticity of host 'github.com (140.82.114.3)' can't be established.
RSA key fingerprint is SHA256:nThbdj6RGJ48dhvldj3gawbEH48DjmV2LviKw6EFFB8.
Are you sure you want to continue connecting (yes/no/&#91;fingerprint])? yes
Warning: Permanently added 'github.com,140.82.114.3' (RSA) to the list of known hosts.
Hi your_user_name! You've successfully authenticated, but GitHub does not provide shell access.</code></pre>

Where `your_user_name` matches your actual Github username.

# <span id="Test_C_compilation_in_Terminal">Test C++ compilation in Terminal</span>

At this point, you should be ready to compile c++ code in _Terminal_. These instructions show how to compile [googletest][27], Google Testing and Mocking Framework.

Checkout the code from github with :

<pre class="wp-block-code"><code>mkdir -p ~/dev
cd ~/dev
git clone "https://github.com/google/googletest.git"
cd googletest</code></pre>

The commands above will create directory `~/dev/googletest` with _googletest_ source code.

Create the _build system_ directory with :

<pre class="wp-block-code"><code>mkdir -p build
cd build
cmake -DCMAKE_INSTALL_PREFIX=~/dev/install -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF -DBUILD_GMOCK=OFF -DBUILD_GTEST=ON ..</code></pre>

Build and install _googletest_ with :

<pre class="wp-block-code"><code>cmake --build . --parallel 4
cmake --build . --target install</code></pre>

This commands above will build googletest with 4 cores and install the library in `~/dev/install` directory.

# <span id="Test_C_compilation_with_Visual_Studio_Code">Test C++ compilation with Visual Studio Code</span>

These instructions show how to compile [zlib][28], a massively spiffy yet delicately unobtrusive compression library.

  1. Open _Visual Studio Code_.
  2. On the left toolbar, click the _Source Control_ icon.
  3. Click on the _Clone Repository_ button.
  4. A [Command Pallet][29] will open.
  5. Enter the following url: `https://github.com/madler/zlib.git` and press `enter`.
  6. Select the location where to checkout the repository. For example, `~/dev`.
  7. Wait for the repository to checkout.
  8. A notification window will appear and ask _Would you like to open the cloned repository?_ Click _Open_ button.
  9. On the left toolbar, click the _CMake_ icon.
 10. At the top of the window, click on _Configure All Projects_ icon.
 11. A _Command Pallet_ will open.
 12. Select _\[Unspecified\] (Let CMake guess what compilers and environment to use)_ option.
 13. Wait for the configuration to complete.
 14. At the top of the window, click on _Build All Projects_ icon.
 15. Wait for the build to complete.
 16. Right-click on the _example_ target and select _Run in Terminal_ menu item.
 17. The Terminal should output the following: `/Users/your_user_name/dev/zlib/build/example zlib version 1.2.11 = 0x12b0, compile flags = 0xa9 uncompress(): hello, hello! gzread(): hello, hello! gzgets() after gzseek: hello! inflate(): hello, hello! large_inflate(): OK after inflateSync(): hello, hello! inflate with dictionary: hello, hello!`

You can also allow the extension to connect to your _personal GitHub account_ in order to checkout your own repositories:

  1. In the _Command Pallet_, select option _Clone from GitHub_.
  2. The extension &#8216;GitHub&#8217; may request your to sign in to GitHub.
      1. Click _Allow_ button.
      2. A _Safari_ window will open which request _Authorization for Visual Studio Code to access GitHub_.
      3. Click _Continue_ button.
      4. Enter your _GitHub credentials_ and click on _Sign In_ button.
      5. Read the given permissions and click on _Authorize github_.
      6. In the _Safari_ window, note _Your Authorization Token_. It should look like the following: `vscode://vscode.github-authentication/did-authenticate?windowid=1&code=ca7506dce69e40699277&state=5c05c8f1-9af0-4630-b257-3fe8adeb9a75`.
      7. To use the token, in _Visual Studio Code_, click _Signing in to github.com&#8230;_ in the status bar.
      8. Paste the token and hit enter.
  3. In Visual Studio Code, allow the extension to open your token url.
      1. Check _Don&#8217;t ask again for this extension_.
      2. Click the _Open_ button.
  4. Select the location where to checkout the repository. For example, `~/dev/mygithubrepositories`.

## <span id="Cloning_GitHub_repo_with_Visual_Studio_Code">Cloning GitHub repo with Visual Studio Code</span>

At the time of this writing, when a user clone one of his own GitHub repository using _Visual Studio Code_, the URL used for cloning is in format `https://github.com/<Username>/<Project>.git` instead of using the url in format `git@github.com:<Username>/<Project>.git`. Using the `https` url force users to enter their GitHub _username_ and _password_ everytime they want to push changes to GitHub.

You can validate the remote origin url with the following command :  
`git config --get remote.origin.url`.

To get around this, one must change the remote url format from `https://github.com/<Username>/<Project>.git` to `git@github.com:<Username>/<Project>.git`. The instructions for this are explained in [Push to GitHub without a password using ssh-key][30].

Enter the following command to change the remote origin url :  
`git remote set-url origin git@github.com:<Username>/<Project>.git`  
where `<Username>` and `<Project>` are replaced with the correct values.

 [1]: https://superuser.com/a/1209218
 [2]: https://www.macworld.co.uk/how-to/show-hidden-files-mac-3520878/
 [3]: https://en.wikipedia.org/wiki/Apple_Inc.
 [4]: https://en.wikipedia.org/wiki/Integrated_development_environment
 [5]: https://en.wikipedia.org/wiki/MacOS
 [6]: https://stackoverflow.com/questions/10335747/how-to-download-xcode-dmg-or-xip-file
 [7]: https://developer.apple.com/services-account/download?path=/Developer_Tools/Xcode_11.7/Xcode_11.7.xip
 [8]: https://www.imore.com/how-open-apps-anywhere-macos-catalina-and-mojave
 [9]: https://forums.virtualbox.org/viewtopic.php?f=8&t=93133#p448593
 [10]: https://www.virtualbox.org/ticket/19047#comment:6
 [11]: http://brew.sh/
 [12]: https://en.wikipedia.org/wiki/Package_manager
 [13]: https://treehouse.github.io/installation-guides/mac/homebrew
 [14]: https://cmake.org/
 [15]: https://cmake.org/download/
 [16]: https://github.com/Kitware/CMake/releases/download/v3.19.6/cmake-3.19.6-macos-universal.dmg
 [17]: https://discussions.apple.com/thread/8336714
 [18]: https://stackoverflow.com/a/63207834
 [19]: https://code.visualstudio.com/
 [20]: https://go.microsoft.com/fwlink/?LinkID=534106
 [21]: https://code.visualstudio.com/docs/setup/mac
 [22]: #configure-git-for-github
 [23]: https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key
 [24]: https://git-scm.com/
 [25]: https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key#_generate_ssh_key
 [26]: https://github.com/settings/keys
 [27]: https://github.com/google/googletest
 [28]: https://github.com/madler/zlib
 [29]: https://code.visualstudio.com/docs/getstarted/userinterface#_command-palette
 [30]: https://stackoverflow.com/questions/14762034/push-to-github-without-a-password-using-ssh-key