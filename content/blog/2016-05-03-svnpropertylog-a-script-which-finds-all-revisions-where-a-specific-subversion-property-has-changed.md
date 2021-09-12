---
title: svnpropertylog – A script which finds all revisions where a specific subversion property has changed
author: end2end
type: post
date: 2016-05-03T16:52:00+00:00
url: /svnpropertylog-a-script-which-finds-all-revisions-where-a-specific-subversion-property-has-changed/
featured_image: /wp-content/uploads/2016/05/svnpropertylog-v1.1.29-screenshot.png
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Script:</p>
        <ul class="fa-ul">
        <li><a href="/download/1908/"><i class="fa-li fa fa-download" style="position: inherit;"></i>svnpropertylog (latest version)</a></li>
        </ul>
        </div>
        
hits:
  - 35
categories:
  - Development
tags:
  - english
  - open source
  - scripts

---
# <span id="Purpose">Purpose</span>

The subversion application does not offer native support for identifying changes to subversion properties as easily as changes to files.

The purpose of this script is to allows a subversion user to find all revisions where a change to a specific property occurred. In other words, it&#8217;s a &#8220;_show log for subversion properties_&#8220;.<!--more-->

Skip to the [download section][1] for quick download.

<p class="pleasenote" data-pleasenote="true">
  Note that <strong><em>svnpropertylog</em></strong> is only available for Windows and has been tested on Windows 7 only.
</p>

# <span id="Usage">Usage</span>

The script has 5 command line arguments which are:

<li style="text-align: justify;">
  Oldest revision number
</li>
<li style="text-align: justify;">
  Newest revision number
</li>
<li style="text-align: justify;">
  File or folder URL
</li>
<li style="text-align: justify;">
  Property name
</li>
<li style="text-align: justify;">
  Show property values? ( Must be <strong><em></em></strong> or <em><strong>1 </strong></em>)
</li>

## <span id="Execution_command_line">Execution (command line)</span>

The script is written in [VBScript][2].  Use the following to execute the script from a batch file (*.bat) :

<pre class="lang:batch decode:true " title="Windows Batch file">@echo off
cscript //nologo "%~dp0svnpropertylog.vbs" 9 13 "http://localhost/svn/svnpropertylog/tests/folder" "svn:externals" 1
pause
</pre>

## <span id="UI">UI</span>

<div id="attachment_1918" style="width: 373px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/05/svnpropertylog-property-sample.png" rel="attachment wp-att-1918"><img aria-describedby="caption-attachment-1918" loading="lazy" class="size-full wp-image-1918" src="http://www.end2endzone.com/wp-content/uploads/2016/05/svnpropertylog-property-sample.png" alt="svnpropertylog - Select Subversion Property" width="363" height="221" srcset="http://www.end2endzone.com/wp-content/uploads/2016/05/svnpropertylog-property-sample.png 363w, http://www.end2endzone.com/wp-content/uploads/2016/05/svnpropertylog-property-sample-150x91.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/05/svnpropertylog-property-sample-300x183.png 300w" sizes="(max-width: 363px) 100vw, 363px" /></a>
  
  <p id="caption-attachment-1918" class="wp-caption-text">
    svnpropertylog &#8211; Select Subversion Property
  </p>
</div>

A GUI application is also available. From a <a href="http://upload.wikimedia.org/wikipedia/en/c/cb/Windows_Explorer_Windows_7.png?download" target="_blank" rel="noopener">file explorer window</a>, double-click on **_svnpropertylogGui_** and follow on-screen instructions: the UI will prompt the user for each command line argument and then launch the script.

## <span id="Output">Output</span>

On execution, the following output is produced by the script:

<pre class="lang:default decode:true" title="Sample execution">svnpropertylog v1.1
Extracting property svn:externals within revision 9 to 13 from http://localhost/svn/svnpropertylog/tests/folder...
Extracting... 0%
Extracting... 25%
Extracting... 50%
Extracting... 75%
Extracting... 100%
Comparing properties...
Property svn:externals has been changed in revision 13
===============================================================================
revision: 13
http://localhost/svn/svnpropertylog/tests/sample.txt@8 sample.txt
http://localhost/svn/svnpropertylog/tests@7 tests


===============================================================================
Property svn:externals has been changed in revision 10
===============================================================================
revision: 10
http://localhost/svn/svnpropertylog/tests/sample.txt@8 sample.txt


===============================================================================
Press any key to continue . . .</pre>

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download **_svnpropertylog_** by clicking on the following link:


		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/1908/" rel="nofollow"> Download &ldquo;svnpropertylog v1.1.29&rdquo; <small>svnpropertylog-v1.1.29.zip &ndash; Downloaded 346 times &ndash; 8 KB</small> </a>

 [1]: #Download
 [2]: http://en.wikipedia.org/wiki/VBScript