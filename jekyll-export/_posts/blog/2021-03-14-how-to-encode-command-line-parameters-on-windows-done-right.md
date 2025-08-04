---
id: 2459
title: 'How to encode command line parameters on Windows – done right'
date: '2021-03-14T10:49:47+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=2459'
permalink: '/?p=2459'
hits:
    - '425'
image: /wp-content/uploads/2017/06/How-to-encode-command-line-parameters-on-Windows-–-done-right.jpg
categories:
    - Development
tags:
    - english
---

# Introduction

This post is a follow up on command line arguments. I recently published a C++ library ([libArgvCodec](/libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/)) which properly handles all encoding and decoding of command line arguments. It is much safer to use the library than simply wrap each argument with double quotes. This post is about the list of rules that the library implements for encoding and decoding of arguments.

# Using libArgvCodec library

The [libArgvCodec](/libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/) library can be used for free and is released as Open Source. The code is available [here](/download/2480/). Feel free to download the library to use it in your own projects.

# Encoding and Decoding rules

If you do not want to use the library, the following section shows the rules that are implemented into the library for properly handling all situations and special characters. Feel free to use these rules to implement your own library.

## Rule #1 - Delimiters

Tabs or \[space\] characters are argument delimiters (separators) but **\*only\*** when outside a string and outside a caret-string. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| a b c | a | b | c |

## Rule #2 - Strings {#rule2}

Double quotes character (`"`) starts or ends a string. Strings allows one to insert a delimiter (or separators) character to an argument. The double quotes character is omitted from the argument. Note that strings **may** **not** always be ended (the end of the command line may be hit without the end-of-string character)

If a string is juxtaposed to another argument (not separated by a delimiter character), they form the same argument. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| "a b c" | a b c |  |  |
| a" b" c | a b | c |  |
| "a "b c | a b | c |  |

### Rule #2.1 - Plain double quotes

Plain double quotes character (`"`) must be escaped with `<strong>\"</strong>` (or escaped with `<strong>""</strong>`) and does not end the string. (If not escaped, they act as strings markers ([Rule #2](#rule2)). Characters escaped with `<strong>\"</strong>` can be seen inside or outside strings but characters escaped with `<strong>""</strong>` can **\*only\*** be seen inside a string. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| a \\"b c | a | "b | c |
| "a \\"b" c | a "b | c |  |
| "a ""b" c | a "b | c |  |
| a ""b c | a | b | c |
| """" | " |  |  |

### Rule #2.2 - Caret-String

`<strong>^"</strong>` sequence starts or ends a caret-string. Caret-strings are different than normal strings. Caret-strings may be ended with an unescaped `<strong>"</strong>` character. Caret-string may not be ended. Note that caret-strings **may** **not** always be ended (the end of the command line may be hit without the end-of-string character)

If a caret-string is juxtaposed to another argument (not separated by a delimiter character), they are part of the same argument. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| ^"a b^" c | a b | c |  |
| ^"a b" c | a b | c |  |
| ^"a b^"c | a bc |  |  |
| a^"b c^" | ab c |  |  |
| ^"a b c^" | a b c |  |  |
| a^" b^" c | a b | c |  |
| ^"a ^"b c | a b | c |  |

### Rule #2.3 - Plain double quotes (Caret-String) {#rule2_3}

Plain double quotes character (`"`) must be escaped with `<strong>\^"</strong>` when inside a caret-string. Note that `<strong>\^"</strong>` characters sequence can also be visible outside a string.

Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| ^"a \\^" b^" c | a " b | c |  |
| ^"a \\" b^" c | a " b^ | c |  |
| a b\\^"c | a | b"c |  |

## Rule #3 - The \\ character

Plain `<strong>\</strong>` character must be escaped with `<strong>\\</strong>` if they precedes a `<strong>"</strong>` character or `<strong>^"</strong>` character sequence. (string or caret-string termination). Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| a\\\\b | a\\\\b |  |  |
| "a\\\\b" | a\\\\b |  |  |
| a\\\\"b c | a\\b c |  |  |
| a\\"b c | a"b | c |  |
| a\\\\"b c" | a\\b c |  |  |
| "a\\\\\\"b c" | a\\"b c |  |  |
| a\\\\^"b c | a\\b c |  |  |
| a\\\\^"b c" | a\\b c |  |  |
| "a\\\\\\^"b c" | a\\\\\\^b | c |  |

## Rule #4 - Shell characters

The following characters are **special shell characters**: **&amp;**, **&lt;**, **&gt;**, **(**, **)**, **|**, **%** or **!**

### Rule #4.1 (in string)

Shell characters must be read as plain text when inside a string. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| "a &lt; b" c | a &lt; b | c |  |
| "a ^&lt; b" c | a ^&lt; b | c |  |

### Rule #4.2 (in caret-string)

Plain shell characters must be escaped with `<strong>^</strong>` when inside a caret-string or outside a string. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| a ^&lt; b | a | &lt; | b |
| ^"a ^&lt; b^" c | a &lt; b | c |  |
| ^"a &lt; b^" c | The system cannot find the file specified. |
| ^"a &amp; b^" c | 'b"' is not recognized as an internal or external command, operable program or batch file. |
| ^"a &amp;whoami^" | outputs: %USERDOMAIN%\\%USERNAME% |

### Rule #4.3 (Escaped non-shell characters)

Non-shell characters that are escaped with `<strong>^</strong>` when inside a caret-string or outside a string and must be read as plain characters. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| ^a^b ^c | ab | c |  |
| "^a^b" ^c | ^a^b |  |  |

## Rule #5 - Empty arguments

Empty arguments must be specified with `<strong>""</strong>` (enclosed by two consecutive delimiters). Note that empty arguments can also be specified with `<strong>^"^"</strong>` or a combination of the two.

Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| a "" b | a | \[empty\] | c |
| "" a b | \[empty\] | a | b |
| a b "" | a | b | \[empty\] |
| a ^"^" b | a | \[empty\] | b |
| ^"^" a b | \[empty\] | a | b |
| a b ^"^" | a | b | \[empty\] |
| a ^"" b | a | \[empty\] | b |
| ^"" a b | \[empty\] | a | b |
| a b ^"" | a | b | \[empty\] |

## Rule #6 - Juxtaposed strings {#rule6}

Two juxtaposed strings (not separated by a delimiter character), will insert a plain double quotes character (`"`) between each other. This rule applies to normal strings, caret-strings, or any combinations. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| "a b""c d" | a b"c d (as with [rule #2](#rule2)) |  |  |
| ^"a b^"^"c d^" | a b"c d |  |  |
| ^"a b^""c d" | a b"c d |  |  |
| "a b"^"c d^" | a b"c d |  |  |
| "a b^"^"c d" | a b^"c d |  |  |

## Rule #7 - Any other characters

All other characters must be read as plain text.

## Exceptions:

### Exception #1

`<strong>\"</strong>` characters sequence inside a caret-string. This formatting is against [rule #2.3](#rule2_3) which states that double quote character `"` should be entered as `\^"` or againt [rule #3](#rule3) which states that `\` characters should be entered as `\\"`. Erroneous `<strong>\"</strong>` sequence in a caret-string should be read as ***\[end caret-string\]*** and ***\[start string\]*** which as of [rule #6](#rule6) also inserts a plain `"` character. Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| ^"test\\"&lt;test&amp;whoami^" | test"&lt;test&amp;whoami^ |  |  |
| ^"ab cd \\" ef^" | ab cd " ef^ |  |  |
| ^"ab cd \\^" ef^" | ab cd " ef |  |  |
| ^"ab cd \\\\" ef^" | ab cd \\ | ef^ |  |

# Samples

Using the list of rules above, one can encode the following arguments into a fully qualified command line.

# Decoding samples

The following table shows multiple examples of command lines which decodes into multiple arguments. Note that some command lines are malformed or incomplete. The libArgvCodec library properly handle both cases.

Also note that some command line contains shell command (whoami and echo) which are used to demonstrate that libArgvCodec is secure and protects againts command line injection attacks.

For the list of all verification tests executed with libArgvCodec, please see the source code of the libargvcodectest project.

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|---|---|---|---|
| aaa" | aaa |  |  |
| aaa\\" | aaa" |  |  |
| aaa\\\\" | aaa\\ |  |  |
| aaa\\\\\\" | aaa\\" |  |  |
| "aaa\\" | aaa" |  |  |
| "aaa\\\\" | aaa\\ |  |  |
| "aaa\\\\\\" | aaa\\" |  |  |
| a"bc | abc |  |  |
| a"bc\\ | abc\\ |  |  |
| a"bc\\\\ | abc\\\\ |  |  |
| a"bc\\\\\\ | abc\\\\\\ |  |  |
| a"bc\\"d | abc"d |  |  |
| a"bc\\\\ ddd" e | abc\\\\ ddd | e |  |
| a"bc\\"\\ ddd" e | abc"\\ ddd | e |  |
| ab\\\\c d | ab\\\\c | d |  |
| ab\\\\ c | ab\\\\ | c |  |
| \\\\ab c | \\\\ab | c |  |
| a ""bc\\"o" e" | a | bc"o e |  |
| a "bc\\"o" e" | a | bc"o | e |
| "a"""b | a"b |  |  |
| "a"""b" | a"b |  |  |
| "a\\"b" | a"b |  |  |
| "a""" b" | a" | b |  |
| """ | " |  |  |
| """" | " |  |  |
| """"" | "" |  |  |
| """""" | "" |  |  |
| ^"ab cd\\^"^&amp;echo foo^" | ab cd"&amp;echo foo |  |  |
| "ab cd\\^"^&amp;echo foo^" | ab cd\\^&amp;echo | foo |  |
| ^"ab cd\\^" ee" | ab cd" ee |  |  |
| "ab cd\\" ee" | ab cd" ee |  |  |
| "ab cd\\^" ee" | ab cd\\^ | ee |  |
| "a^b" c | a^b | c |  |
| ^"a^b" c | ab | c |  |
| ^"ab^" c | ab | c |  |
| ^"ab^"" c | ab" c |  |  |
| a \\bb c | a | \\bb | c |
| a \\"bb c" d | a | "bb | c d |
| a ^"bb^" c" d | a | bb | c d |
| a \\"b c | a | "b | c |
| a""b c | ab | c |  |
| a\\"b c | a"b | c |  |
| "a""b" c | a"b | c |  |
| "a\\"b" c | a"b | c |  |
| a ^"" b | a |  | b |
| a ^"^" b | a |  | b |
| ^"" a |  | a |  |
| ^"^" a |  | a |  |
| ^"test\\^"^&amp;whoami^" | test"&amp;whoami |  |  |
| ^"test\\\\^"^&amp;whoami^" | test\\&amp;whoami |  |  |
| ^"test\\"^&amp;whoami^" | test"^&amp;whoami^ |  |  |
| a\\\\\\\\"b | a\\\\b |  |  |
| ^"a\\\\\\\\"b" | a\\\\b |  |  |
| ^"a\\^\\^\\\\"b" | a\\\\b |  |  |
| ^"a\\^\\\\^\\"b" | a\\\\b |  |  |
| ^"a\\^\\\\\\^"b" | a\\\\b |  |  |