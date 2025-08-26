---
title: svnpropertylog – A script which finds all revisions where a specific subversion property has changed
author: end2end
date: 2016-05-03T16:52:00+00:00
url: /svnpropertylog-a-script-which-finds-all-revisions-where-a-specific-subversion-property-has-changed/
images:
  - src: /wp-content/uploads/2016/05/svnpropertylog-v1.1.29-screenshot.png
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Script:
        * [svnpropertylog (latest version)](/download/1908/)
        
hits:
  - 35
categories:
  - Development
tags:
  - english
  - open source
  - scripts

---
# Purpose

The subversion application does not offer native support for identifying changes to subversion properties as easily as changes to files.

The purpose of this script is to allows a subversion user to find all revisions where a change to a specific property occurred. In other words, it's a "_show log for subversion properties_".
Skip to the [download section](#Download) for quick download.

{{< pleasenote >}}
  Note that **_svnpropertylog_** is only available for Windows and has been tested on Windows 7 only.
{{< /pleasenote >}}


# Usage

The script has 5 command line arguments which are:

* Oldest revision number
* Newest revision number
* File or folder URL
* Property name
* Show property values? ( Must be  or _**1 **_)

## Execution (command line)

The script is written in [VBScript](http://en.wikipedia.org/wiki/VBScript).  Use the following to execute the script from a batch file (*.bat) :


```batch
@echo off
cscript //nologo "%~dp0svnpropertylog.vbs" 9 13 "http://localhost/svn/svnpropertylog/tests/folder" "svn:externals" 1
pause
```


## UI

[![svnpropertylog - Select Subversion Property](/wp-content/uploads/2016/05/svnpropertylog-property-sample.png)](/wp-content/uploads/2016/05/svnpropertylog-property-sample.png)

svnpropertylog - Select Subversion Property

A GUI application is also available. From a [file explorer window](http://upload.wikimedia.org/wikipedia/en/c/cb/Windows_Explorer_Windows_7.png?download), double-click on **_svnpropertylogGui_** and follow on-screen instructions: the UI will prompt the user for each command line argument and then launch the script.

## Output

On execution, the following output is produced by the script:


```
svnpropertylog v1.1
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
Press any key to continue . . .
```


# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download **_svnpropertylog_** by clicking on the following link:


		[ Download "svnpropertylog v1.1.29" svnpropertylog-v1.1.29.zip - Downloaded 346 times - 8 KB ](http://www.end2endzone.com/download/1908/)
