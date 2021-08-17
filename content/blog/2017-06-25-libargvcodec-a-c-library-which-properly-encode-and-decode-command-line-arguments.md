---
title: libArgvCodec – A c++ library which properly encode and decode command line arguments
author: end2end
type: post
date: 2017-06-25T16:02:08+00:00
url: /libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/
featured_image: /wp-content/uploads/2017/06/libArgvCodec-cplusplus-library-672x378.jpg
hits:
  - 243
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Source code:</p>
        <ul class="fa-ul">
        <li><a href="/download/2480/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2480" template="title"]</a></li>
        <li><a href="/download/2482/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2482" template="title"]</a></li>
        </ul>
        </div>
        
categories:
  - Development
tags:
  - c++
  - english
  - open source

---
# <span id="Introduction">Introduction</span>

This post is about a decade old problem: how to properly encode command line arguments. Properly encoding string arguments into a long command line should not be a complicated issue. However, I have seen multiple situations where people wrongfully assume that wrapping each argument with double quotes is &#8216;safe enough&#8217; for most situations. That is simply not true.<!--more-->

This article is about the C++ library libArgvCodec which properly encodes and decodes command line parameters.

Skip to the [download section][1] for quick download.

# <span id="Purpose">Purpose</span>

The purpose of the library is not to handle _Argument Parsing_ and _Argument Validation_ : there are already multiple libraries that can do that and most of them does it pretty well.

However, few of them are actually developed to help a user passing arguments from one application to another. The libArgvCodec library includes arguments and command line encoder and decoder (codecs) that are designed for this particular purpose.

Transferring local variable values to another application through command line arguments is not something that occurs pretty often but if you ever have to deal with this situation, the libArgvCodec library can help you avoid typical encoding pitfalls.

# <span id="Library_features">Library features</span>

Here is a list of all library features:

  * Supports <code class="prettycode">int argc, char* argv[]</code> argument parsing.
  * Supports case sensitive and case insensitive searches within lists of arguments.
  * Quickly identify unknown arguments.
  * Supports any type of argument prefixes like: slashes, single dash,  double dash, etc.
  * Encodes multiple single arguments into a full command line.
  * Decodes a command line into individual arguments.
<li style="text-align: justify;">
  Supports both Windows shell (command prompt) and Windows <a href="http://msdn.microsoft.com/en-us/library/windows/desktop/ms682425(v=vs.85).aspx">CreateProcess()</a> encoding/decoding.
</li>
  * Bulletproof application againts command line injection attacks.

# <span id="Usage">Usage</span>

## <span id="Arguments_validation">Arguments validation</span>

Parsing the list of arguments for validation is easy with the libArgvCodec. Create an instance of the <code class="prettycode">ArgumentList</code> class which encapsulates a list of argument values. Call the <code class="prettycode">init()</code> method using the application&#8217;s <code class="prettycode">argc</code> and <code class="prettycode">argv</code> parameters which initialize the instance with a copy of all the parameters.

Browse through the list of arguments using the <code class="prettycode">getArgument()</code> method or search for a specific parameter using the <code class="prettycode">findIndex()</code> or <code class="prettycode">contains()</code> methods.

Searching for _**options**_ (argument of the type _**/p**_ or **_&#8211;help_** or **_start_**) is easily done with the class using the <code class="prettycode">findOption()</code> method.

Search for **_arguments with values_** for patterns likes _**/name=foo**_ or **_&#8211;count=5_**) using the <code class="prettycode">findValue()</code> method.

Search for _**name and value pairs**_ (arguments whose value is following as another argument) for patterns like **_/product foo_** or **_&#8211;repeat 5_** using the <code class="prettycode">findNextValue()</code> method.

To quickly identify unknown arguments, the class supports **_extract methods_** (one for each find method). Extract method removes the argument from the <code class="prettycode">ArgumentList</code>. Once all know arguments are removed from the list, the remaining ones are considered unknown.

## <span id="Manipulating_an_argument_list">Manipulating an argument list</span>

The <code class="prettycode">ArgumentList</code> class is used as a container for arguments. It supports all CRUD operations:

<li style="text-align: justify;">
  <strong>C</strong>reate (add) with the <code class="prettycode">insert()</code> method.
</li>
<li style="text-align: justify;">
  <strong>R</strong>ead (view) with the <code class="prettycode">getArgument()</code> method.
</li>
<li style="text-align: justify;">
  <strong>U</strong>pdate with the <code class="prettycode">replace()</code> method.
</li>
<li style="text-align: justify;">
  <strong>D</strong>elete with the <code class="prettycode">remove()</code> method.
</li>

## <span id="Encoding_arguments_and_decoding_command_line">Encoding arguments and decoding command line</span>

The encoding and decoding of command line arguments is  with <code class="prettycode">&lt;span style="font-size: medium;">IArgumentEncoder&lt;/span></code> and <code class="prettycode">&lt;span style="font-size: medium;">IArgumentDecoder&lt;/span></code> interfaces. To interact with the interfaces, the <code class="prettycode">ArgumentList</code> class is used as input data or output data.

The library provides the following classes which implements both interfaces:

<li style="text-align: justify;">
  <code class="prettycode">CmdPromptArgumentCodec</code> handles encoding/decoding for the Windows command prompt (shell)
</li>
<li style="text-align: justify;">
  <code class="prettycode">CreateProcessArgumentCodec</code> handles encoding/decoding for the Windows <a href="http://msdn.microsoft.com/en-us/library/windows/desktop/ms682425(v=vs.85).aspx">CreateProcess()</a> api.
</li>

Using these classes, one can fill up an <code class="prettycode">ArgumentList</code> instance and call the <code class="prettycode">encodeCommandLine()</code> method to encode all the arguments in the list into a single command line.

Using the same codec classes, one can &#8216;split&#8217; a command line into multiple arguments using the <code class="prettycode">decodeCommandLine()</code> method which returns a valid <code class="prettycode">ArgumentList</code> with the result.

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the libArgvCodec library by clicking on the following link:  



		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/2480/" rel="nofollow"> Download &ldquo;libArgvCodec v1.0.104 (source code)&rdquo; <small>libArgvCodec-x86-v1.0.104-src.zip &ndash; Downloaded 510 times &ndash; 99 KB</small> </a>


		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/2482/" rel="nofollow"> Download &ldquo;libArgvCodec v1.0.104 binaries (vs2008, x86, portable)&rdquo; <small>libArgvCodec-x86-v1.0.104-portable.zip &ndash; Downloaded 505 times &ndash; 204 KB</small> </a>

 [1]: #Download