---
title: 'MSBuildReorder: How to reorder a Visual Studio build log for easy reading'
author: end2end
type: post
date: 2015-01-31T01:27:33+00:00
url: /msbuildreorder-how-to-reorder-a-visual-studio-build-log-for-easy-reading/
featured_image: /wp-content/uploads/2015/01/MSBuildReorder-How-to-reorder-a-Visual-Studio-build-log-for-easy-reading-672x378.png
hits:
  - 62
categories:
  - Development
tags:
  - c++
  - english
  - Freeware
  - msbuild
  - visual studio

---
# <span id="MSBuildReorder">MSBuildReorder</span>

<p class="postedit">
  Please note that MSBuildReorder source code is now moved to GitHub. Source code can be downloaded from <a href="http://github.com/end2endzone/msbuildreorder">the project&#8217;s GitHub page</a>.
</p>

![][1]![][2]![][3]![][4]![][5] 

<span style="line-height: 1.5;">MSBuildReorder is a tool for &#8220;reordering&#8221; (buildorder) a multi-process C++ build log. It allows a developer to convert the build log as if it was generated with a single processor.</span><!--more-->

Building a solution that has multiple projects can quickly become bloated with too many lines that are not related to each other. For this reason, finding the actual cause of a build fail is harder than it should be.  MSBuildReorder is able to read the log and reorder the projects in a sequential order.

It&#8217;s main features are:

  * <span style="line-height: 1.5;">Supports both msbuild and Visual Studio 2008 (and over) build logs.</span>
  * <span style="line-height: 1.5;">Useful for <a href="http://en.wikipedia.org/wiki/Continuous_integration">Continuous Integration (CI)</a> servers (build servers).</span>
  * <span style="line-height: 1.5;">Allows quicker identification of the project that caused an error.</span>
  * Command line support.

<span style="line-height: 1.5;"><strong>Usage:<br /> </strong></span><span style="line-height: 1.5;">msbuildreorder [input file] [output file]</span>

  * **input file**: Path to the input build log file to reorder.
  * **<span style="line-height: 1.5;">output file</span>**: Path of the output reordered build log file.

# <span id="Screenshot"><span style="line-height: 1.5;">Screenshot</span></span>

<div id="attachment_641" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot.png"><img aria-describedby="caption-attachment-641" loading="lazy" class="size-medium wp-image-641" src="http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot-300x130.png" alt="msbuildreorder screenshot" width="300" height="130" srcset="http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot-300x130.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot-150x65.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot-672x291.png 672w, http://www.end2endzone.com/wp-content/uploads/2015/01/msbuildreorder-screenshot.png 773w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-641" class="wp-caption-text">
    msbuildreorder screenshot
  </p>
</div>

# <span id="Download"><span style="line-height: 1.5;">Download</span></span>

You can download MSBuildReorder by clicking on the following link:

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from <a href="http://github.com/end2endzone/msbuildreorder/releases">the project&#8217;s GitHub page</a>.
</p>

# <span id="Sample"><span style="line-height: 1.5;">Sample</span></span>

The following shows a multi-process build log compiling [libprotobuf][6]. MSBuildReorder can be used to reorder the multi-threaded log on a <span style="line-height: 1.5;"><a href="http://en.wikipedia.org/wiki/Continuous_integration">Continuous Integration (CI)</a></span> server.

<pre title="lib protobuf normal build log" class="lang:c++ decode:true " data-url="/wp-content/uploads/2015/01/libprotobuf.build_.log"></pre>

Reordered build log:

<pre title="lib protobuf ordered build log" class="lang:default decode:true " data-url="/wp-content/uploads/2015/01/libprotobuf.buildorder.log"></pre>

# <span id="Compatible_with"><span style="line-height: 1.5;">Compatible with</span></span>

<span style="line-height: 1.5;">MSBuildReorder is only available for the Windows platform and has been tested with the following version of Windows:</span>

  * Windows XP
  * <span style="text-align: justify; line-height: 1.5;">Windows Vista</span>
  * <span style="text-align: justify; line-height: 1.5;">Windows 7</span>

# <span id="Minimum_system_requirements">Minimum system requirements</span>

  * 100% PC compatible
  * <span style="text-align: justify; line-height: 1.5;">Pentium II, 300 mhz</span>
  * <span style="text-align: justify; line-height: 1.5;">256 Mb RAM</span>
  * <span style="text-align: justify; line-height: 1.5;">5 Mb free disk space</span>

# <span id="License">License</span>

<span lang="EN-US">MSBuildReorder is being distributed as Freeware for personal, commercial use, non-profit organization, and educational purpose. It may be included with CD-ROM/DVD-ROM distributions. You are NOT allowed to make a charge for distributing this Software (either for profit or merely to recover your media and distribution costs) whether as a stand-alone product, or as part of a compilation or anthology, nor to use it for supporting your business or customers. It may be distributed freely on any website or through any other distribution mechanism, as long as no part of it is changed in any way.</span>

The full license is available [here][7].

# <span id="History_of_changes">History of changes</span>

Version 1.0 &#8211; First public release

 [1]: https://img.shields.io/badge/License-MIT-yellow.svg
 [2]: https://img.shields.io/github/release/end2endzone/msbuildreorder.svg
 [3]: https://ci.appveyor.com/api/projects/status/911ry08o97ubv506/branch/master?svg=true
 [4]: https://img.shields.io/appveyor/tests/end2endzone/msbuildreorder/master.svg
 [5]: https://img.shields.io/github/downloads/end2endzone/msbuildreorder/total.svg
 [6]: http://code.google.com/p/protobuf/
 [7]: http://www.end2endzone.com/wp-content/uploads/2015/01/MSBuildReorder-EULA.htm