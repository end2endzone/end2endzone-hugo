---
title: 'win32Arduino: a win32 library that implements most arduino functions'
author: end2end
type: post
date: 2016-05-16T17:15:58+00:00
url: /win32arduino-a-win32-library-that-implements-most-arduino-functions/
featured_image: /wp-content/uploads/2016/05/Arduino-win32Arduino-library.jpg
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
# <span id="Introduction">Introduction</span>

Please note that win32Arduino source code is now moved to GitHub. Source code can be downloaded from [the project&#8217;s GitHub page][1].

![][2]![][3]![][4]![][5]![][6] 

After implementing many arduino library, I realized that unit testing a library is harder than I though. Most of the time, the library does not even require advanced arduino functionalities and could be tested outside of the arduino platform.

The win32Arduino is a solution to this issue.

<!--more-->

Skip to the [download section][7] for quick download.

# <span id="Purpose">Purpose</span>

win32Arduino is a Windows implementation of the most used arduino functions which allows an arduino library developer to unit test his code outside of the arduino platform.

This library allows a windows user to easily test an arduino library using your testing framework of choice. For instance, the unit tests of win32Arduino library are executed using the [Google Test framework][8].

# <span id="Library_features">Library features</span>

Possible use are:

<li style="text-align: justify;">
  Implements most arduino functions.
</li>
<li style="text-align: justify;">
  Allows a developer to tests a library outside of the arduino platform.
</li>
<li style="text-align: justify;">
  Quicker unit test execution.
</li>
<li style="text-align: justify;">
  Supports realtime millis() function or simulated millis() and micros() functions.
</li>

# <span id="Library_dependencies">Library dependencies</span>

No external libraries are required to use the win32Arduino library. However, the [Google Test][8] library is required for self unit testing the library.

Project files are available for Visual Studio 2008 only.

# <span id="Usage">Usage</span>

The following instructions show how to easily test an arduino library using the Google Test framework. It assumes that you are already familiar with the test API.

<li style="text-align: justify;">
  Create an executable project and configure the <code class="prettycode">main()</code> function to launch Google Test&#8217;s <code class="prettycode">RUN_ALL_TESTS()</code> macro.
</li>
<li style="text-align: justify;">
  Create a static library project which will &#8220;wrap&#8221; all the arduino files of the library you need to test.
</li>
<li style="text-align: justify;">
  Modify the static library&#8217;s <code class="prettycode">Additionnal Include Directories</code> to point to win32Arduino library. This allows the wrapping library to resolve all <code class="prettycode">arduino.h</code> includes and all arduino symbols using the win32Arduino library.
</li>

The project should compile properly without errors or unresolved extensions allowing you to properly unit test each functionality.

For unit testing the library, the following environment variables must be defined:

  * GTEST_INCLUDE
  * GTEST\_LIBRARY\_DIR
  * GTEST\_LIBRARY\_X86_DEBUG
  * GTEST\_LIBRARY\_X86_RELEASE
  * GTEST\_LIBRARY\_X64_DEBUG
  * GTEST\_LIBRARY\_X64_RELEASE

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the win32Arduino library by clicking on the following link:

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from <a href="http://github.com/end2endzone/win32Arduino/releases">the project&#8217;s GitHub page</a>.
</p>

 [1]: http://github.com/end2endzone/win32Arduino
 [2]: https://img.shields.io/badge/License-MIT-yellow.svg
 [3]: https://img.shields.io/github/release/end2endzone/win32Arduino.svg
 [4]: https://ci.appveyor.com/api/projects/status/4jhi6oqgaji5e7pl/branch/master?svg=true
 [5]: https://img.shields.io/appveyor/tests/end2endzone/win32Arduino/master.svg
 [6]: https://img.shields.io/github/downloads/end2endzone/win32Arduino/total.svg
 [7]: #Download
 [8]: http://github.com/google/googletest