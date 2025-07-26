---
id: 2282
title: 'libArgvCodec – A c++ library which properly encode and decode command line arguments'
date: '2017-06-25T12:02:08+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=2282'
permalink: '/?p=2282'
hits:
    - '485'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Source code:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/2480/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2480\" template=\"title\"]</a></li>\n<li><a href=\"/download/2482/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2482\" template=\"title\"]</a></li>\n</ul>\n</div>\n"
image: /wp-content/uploads/2017/06/libArgvCodec-cplusplus-library.jpg
categories:
    - Development
tags:
    - c++
    - english
    - 'open source'
---

# Introduction

This post is about a decade old problem: how to properly encode command line arguments. Properly encoding string arguments into a long command line should not be a complicated issue. However, I have seen multiple situations where people wrongfully assume that wrapping each argument with double quotes is 'safe enough' for most situations. That is simply not true. This article is about the C++ library libArgvCodec which properly encodes and decodes command line parameters. Skip to the [download section](#Download) for quick download.

# Purpose

The purpose of the library is not to handle *Argument Parsing* and *Argument Validation* : there are already multiple libraries that can do that and most of them does it pretty well. However, few of them are actually developed to help a user passing arguments from one application to another. The libArgvCodec library includes arguments and command line encoder and decoder (codecs) that are designed for this particular purpose. Transferring local variable values to another application through command line arguments is not something that occurs pretty often but if you ever have to deal with this situation, the libArgvCodec library can help you avoid typical encoding pitfalls.

# Library features

Here is a list of all library features: - Supports `int argc, char* argv[]` argument parsing.
- Supports case sensitive and case insensitive searches within lists of arguments.
- Quickly identify unknown arguments.
- Supports any type of argument prefixes like: slashes, single dash, double dash, etc.
- Encodes multiple single arguments into a full command line.
- Decodes a command line into individual arguments.
- Supports both Windows shell (command prompt) and Windows [CreateProcess()](http://msdn.microsoft.com/en-us/library/windows/desktop/ms682425(v=vs.85).aspx) encoding/decoding.
- Bulletproof application againts command line injection attacks.

# Usage

## Arguments validation

Parsing the list of arguments for validation is easy with the libArgvCodec. Create an instance of the `ArgumentList` class which encapsulates a list of argument values. Call the `init()` method using the application's `argc` and `argv` parameters which initialize the instance with a copy of all the parameters. Browse through the list of arguments using the `getArgument()` method or search for a specific parameter using the `findIndex()` or `contains()` methods. Searching for ***options*** (argument of the type ***/p*** or ***--help*** or ***start***) is easily done with the class using the `findOption()` method. Search for ***arguments with values*** for patterns likes ***/name=foo*** or ***--count=5***) using the `findValue()` method. Search for ***name and value pairs*** (arguments whose value is following as another argument) for patterns like ***/product foo*** or ***--repeat 5*** using the `findNextValue()` method. To quickly identify unknown arguments, the class supports ***extract methods*** (one for each find method). Extract method removes the argument from the `ArgumentList`. Once all know arguments are removed from the list, the remaining ones are considered unknown.

## Manipulating an argument list

The `ArgumentList` class is used as a container for arguments. It supports all CRUD operations: - **C**reate (add) with the `insert()` method.
- **R**ead (view) with the `getArgument()` method.
- **U**pdate with the `replace()` method.
- **D**elete with the `remove()` method.

## Encoding arguments and decoding command line

The encoding and decoding of command line arguments is with `<span style="font-size: medium;">IArgumentEncoder</span>` and `<span style="font-size: medium;">IArgumentDecoder</span>` interfaces. To interact with the interfaces, the `ArgumentList` class is used as input data or output data. The library provides the following classes which implements both interfaces: - `CmdPromptArgumentCodec` handles encoding/decoding for the Windows command prompt (shell)
- `CreateProcessArgumentCodec` handles encoding/decoding for the Windows [CreateProcess()](http://msdn.microsoft.com/en-us/library/windows/desktop/ms682425(v=vs.85).aspx) api.

Using these classes, one can fill up an `ArgumentList` instance and call the `encodeCommandLine()` method to encode all the arguments in the list into a single command line. Using the same codec classes, one can 'split' a command line into multiple arguments using the `decodeCommandLine()` method which returns a valid `ArgumentList` with the result.

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA **DISCLAIMER:**This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the libArgvCodec library by clicking on the following link: \[download id="2480" template="button"\] \[download id="2482" template="button"\]