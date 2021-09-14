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

  1. Open _System Preferences_.
  2. Click on _Software Update_, a new window will open.
  3. Install all updates that are available for macOS Catalina 10.15.

At the time of this writing, the latest version of macOS Catalina is version 10.15.7.

_Note: You can install optional updates by clicking on_ More info... _and selecting updates that are related to Catalina._

&nbsp;

# Set system preferences for developers

## Enable SSH and File sharing

  1. Open _System Preferences_.
  2. Click on _Sharing_.
  3. Set a new _Computer hostname_:
      1. Locate _Computer Name_ field.
      2. Click the _Edit_ button.
      3. Set a meaningful value for the _Local Hostname_. For example `MACDEV01`.
      4. Click the _OK_ button.
  4. Check File Sharing.
      1. Click _Options..._ button.
      2. In _Windows File Sharing_ section, check you account name and enter your account password. This will make sure that shared folders requires a username/password for write access.
      3. Click on _Done_ button.
  5. Check _Remove Login_.
      1. Allow access for _All users_ instead of only for Administrators.
      2. Note your computer _ip address_ in the note _To log in to this computer remotely_.

## Add Terminal icon in Dock

By default, a _Terminal_ icon is not already available in _Dock_. As most developers, you will probably require to use _Terminal_ more than once. Do the following to add _Terminal_ in _Dock_:

  1. Open _Launchpad_.
  2. Expand _Other_ group.
  3. Drag _Terminal_ icon to _Dock_.

## Show address bar in Finder

By default, _Finder_ does not show the address bar (the location of the current directory).

Open a _Terminal_ and enter the following command:

<code>