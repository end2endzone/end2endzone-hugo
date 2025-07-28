---
id: 602
title: 'MSBuildReorder: How to reorder a Visual Studio build log for easy reading'
date: '2015-01-30T20:27:33+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=602'
permalink: '/?p=602'
hits:
    - '97'
image: /wp-content/uploads/2015/01/MSBuildReorder-How-to-reorder-a-Visual-Studio-build-log-for-easy-reading.png
categories:
    - Development
tags:
    - c++
    - english
    - Freeware
    - msbuild
    - 'visual studio'
---

# MSBuildReorder

Please note that MSBuildReorder source code is now moved to GitHub. Source code can be downloaded from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder).

![](https://img.shields.io/badge/License-MIT-yellow.svg) ![](https://img.shields.io/github/release/end2endzone/msbuildreorder.svg) ![](https://ci.appveyor.com/api/projects/status/911ry08o97ubv506/branch/master?svg=true) ![](https://img.shields.io/appveyor/tests/end2endzone/msbuildreorder/master.svg) ![](https://img.shields.io/github/downloads/end2endzone/msbuildreorder/total.svg)MSBuildReorder is a tool for "reordering" (buildorder) a multi-process C++ build log. It allows a developer to convert the build log as if it was generated with a single processor.Building a solution that has multiple projects can quickly become bloated with too many lines that are not related to each other. For this reason, finding the actual cause of a build fail is harder than it should be. MSBuildReorder is able to read the log and reorder the projects in a sequential order.

It's main features are:

- Supports both msbuild and Visual Studio 2008 (and over) build logs.
- Useful for [Continuous Integration (CI)](http://en.wikipedia.org/wiki/Continuous_integration) servers (build servers).
- Allows quicker identification of the project that caused an error.
- Command line support.

**Usage:** msbuildreorder \[input file\] \[output file\]

- **input file**: Path to the input build log file to reorder.
- **output file**: Path of the output reordered build log file.

# Screenshot

\[caption id="attachment\_641" align="alignnone" width="300"\][![msbuildreorder screenshot](https://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot-300x130.png)](https://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot.png) msbuildreorder screenshot\[/caption\]

# Download

You can download MSBuildReorder by clicking on the following link: Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder/releases).

# Sample

The following shows a multi-process build log compiling [libprotobuf](http://code.google.com/p/protobuf/). MSBuildReorder can be used to reorder the multi-threaded log on a [Continuous Integration (CI)](http://en.wikipedia.org/wiki/Continuous_integration) server.

```
```

Reordered build log:

```
```

# Compatible with

MSBuildReorder is only available for the Windows platform and has been tested with the following version of Windows:

- Windows XP
- Windows Vista
- Windows 7

# Minimum system requirements

- 100% PC compatible
- Pentium II, 300 mhz
- 256 Mb RAM
- 5 Mb free disk space

# License

<span lang="EN-US">MSBuildReorder is being distributed as Freeware for personal, commercial use, non-profit organization, and educational purpose. It may be included with CD-ROM/DVD-ROM distributions. You are NOT allowed to make a charge for distributing this Software (either for profit or merely to recover your media and distribution costs) whether as a stand-alone product, or as part of a compilation or anthology, nor to use it for supporting your business or customers. It may be distributed freely on any website or through any other distribution mechanism, as long as no part of it is changed in any way.</span>The full license is available [here](https://www.end2endzone.com/wp-content/uploads/2015/01/MSBuildReorder-EULA.htm).

# History of changes

Version 1.0 - First public release