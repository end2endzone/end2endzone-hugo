---
title: 'win32Arduino: a win32 library that implements most arduino functions'
author: end2end
date: 2016-05-16T17:15:58+00:00
url: /win32arduino-a-win32-library-that-implements-most-arduino-functions/
images:
  - src: /wp-content/uploads/2016/05/Arduino-win32Arduino-library.jpg
hits:
  - 163
categories:
  - Development
tags:
  - arduino
  - arduino library
  - english
  - open source

---
# Introduction

Please note that win32Arduino source code is now moved to GitHub. Source code can be downloaded from [the project's GitHub page](http://github.com/end2endzone/win32Arduino).

![](https://img.shields.io/badge/License-MIT-yellow.svg) ![](https://img.shields.io/github/release/end2endzone/win32Arduino.svg) ![](https://ci.appveyor.com/api/projects/status/4jhi6oqgaji5e7pl/branch/master?svg=true) ![](https://img.shields.io/appveyor/tests/end2endzone/win32Arduino/master.svg) ![](https://img.shields.io/github/downloads/end2endzone/win32Arduino/total.svg)

After implementing many arduino library, I realized that unit testing a library is harder than I though. Most of the time, the library does not even require advanced arduino functionalities and could be tested outside of the arduino platform.

The win32Arduino is a solution to this issue.

Skip to the [download section](#Download) for quick download.

# Purpose

win32Arduino is a Windows implementation of the most used arduino functions which allows an arduino library developer to unit test his code outside of the arduino platform.

This library allows a windows user to easily test an arduino library using your testing framework of choice. For instance, the unit tests of win32Arduino library are executed using the [Google Test framework](http://github.com/google/googletest).

# Library features

Possible use are:

* Implements most arduino functions.
* Allows a developer to tests a library outside of the arduino platform.
* Quicker unit test execution.
* Supports realtime millis() function or simulated millis() and micros() functions.

# Library dependencies

No external libraries are required to use the win32Arduino library. However, the [Google Test](http://github.com/google/googletest) library is required for self unit testing the library.

Project files are available for Visual Studio 2008 only.

# Usage

The following instructions show how to easily test an arduino library using the Google Test framework. It assumes that you are already familiar with the test API.

1. Create an executable project and configure the `main()` function to launch Google Test's `RUN_ALL_TESTS()` macro.
2. Create a static library project which will "wrap" all the arduino files of the library you need to test.
3. Modify the static library's `Additionnal Include Directories` to point to win32Arduino library. This allows the wrapping library to resolve all `arduino.h` includes and all arduino symbols using the win32Arduino library.

The project should compile properly without errors or unresolved extensions allowing you to properly unit test each functionality.

For unit testing the library, the following environment variables must be defined:

* GTEST\_INCLUDE
* GTEST\_LIBRARY\_DIR
* GTEST\_LIBRARY\_X86\_DEBUG
* GTEST\_LIBRARY\_X86\_RELEASE
* GTEST\_LIBRARY\_X64\_DEBUG
* GTEST\_LIBRARY\_X64\_RELEASE

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the win32Arduino library by clicking on the following link:

{{< pleasenote >}}
  Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from [the project's GitHub page](http://github.com/end2endzone/win32Arduino/releases).
{{< /pleasenote >}}
