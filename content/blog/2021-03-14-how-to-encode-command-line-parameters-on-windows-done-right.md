---
title: How to encode command line parameters on Windows – done right
author: end2end
date: 2021-03-14T14:49:47+00:00
url: /how-to-encode-command-line-parameters-on-windows-done-right/
images:
  - src: /wp-content/uploads/2017/06/How-to-encode-command-line-parameters-on-Windows-done-right.jpg
hits:
  - 31
categories:
  - Development
tags:
  - english

---
# Introduction

This post is a follow up on command line arguments. I recently published a C++ library ([libArgvCodec](/libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/)) which properly handles all encoding and decoding of command line arguments. It is much safer to use the library than simply wrap each argument with double quotes.

This post is about the list of rules that the library implements for encoding and decoding of arguments.<!--more-->

# Using libArgvCodec library

The [libArgvCodec](/libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/) library can be used for free and is released as Open Source. The code is available [here](/download/2480/). Feel free to download the library to use it in your own projects.

# Encoding and Decoding rules

If you do not want to use the library, the following section shows the rules that are implemented into the library for properly handling all situations and special characters.

Feel free to use these rules to implement your own library.

## Rule #1 - Delimiters

Tabs or [space] characters are argument delimiters (separators) but **\*only\*** when outside a string and outside a caret-string.

Examples:

| Command Line | Arg #1 | Arg #2 | Arg #3 |
|--------------|--------|--------|--------|
| a b c        | a      | b      | c      |


## <span id="Rule_2_8211_Strings"><a id="rule2"></a>Rule #2 - Strings</span>

Double quotes character (`"`) starts or ends a string. Strings allows one to insert a delimiter (or separators) character to an argument. The double quotes character is omitted from the argument.

{{< pleasenote >}}
  Note that strings ***may**&nbsp;**not***&nbsp;always be ended (the end of the command line may be hit without the end-of-string character)
{{< /pleasenote >}}


If a string is juxtaposed to another argument (not separated by a delimiter character), they form the same argument.

Examples:

| Command Line      | Arg #1 | Arg #2 | Arg #3 |
|-------------------|--------|--------|--------|
| "a b c" | a b c  |        |        |
| a" b" c | a b    | c      |        |
| "a "b c | a b    | c      |        |


### Rule #2.1 - Plain double quotes

Plain double quotes character (`"`) must be escaped with `&lt;strong>\"&lt;/strong>` (or escaped with `&lt;strong>""&lt;/strong>`) and does not end the string. (If not escaped, they act as strings markers ([Rule #2](#rule2)).

Characters escaped with `&lt;strong>\"&lt;/strong>` can be seen inside or outside strings but characters escaped with `&lt;strong>""&lt;/strong>` can **\*only\*** be seen inside a string.

Examples:

| Command Line                  | Arg #1    | Arg #2  | Arg #3 |
|-------------------------------|-----------|---------|--------|
| a \"b c                  | a         | "b | c      |
| "a \"b" c      | a "b | c       |        |
| "a ""b" c | a "b | c       |        |
| a ""b c             | a         | b       | c      |
| """"      | "    |         |        |


### Rule #2.2 - Caret-String

`&lt;strong>^"&lt;/strong>` sequence starts or ends a caret-string. Caret-strings are different than normal strings. Caret-strings may be ended with an unescaped `&lt;strong>"&lt;/strong>` character. Caret-string may not be ended.

{{< pleasenote >}}
  Note that caret-strings ***may**&nbsp;**not***&nbsp;always be ended (the end of the command line may be hit without the end-of-string character)
{{< /pleasenote >}}


If a caret-string is juxtaposed to another argument (not separated by a delimiter character), they are part of the same argument.

Examples:

| Command Line        | Arg #1 | Arg #2 | Arg #3 |
|---------------------|--------|--------|--------|
| ^"a b^" c | a b    | c      |        |
| ^"a b" c  | a b    | c      |        |
| ^"a b^"c  | a bc   |        |        |
| a^"b c^"  | ab c   |        |        |
| ^"a b c^" | a b c  |        |        |
| a^" b^" c | a b    | c      |        |
| ^"a ^"b c | a b    | c      |        |


### <span id="Rule_23_8211_Plain_double_quotes_Caret-String"><a id="rule2_3"></a>Rule #2.3 - Plain double quotes  (Caret-String)</span>

Plain double quotes character (`"`) must be escaped with `&lt;strong>\^"&lt;/strong>` when inside a caret-string.

{{< pleasenote >}}
  Note that `&lt;strong>\^"&lt;/strong>` characters sequence can also be visible outside a string.
{{< /pleasenote >}}


Examples:

| Command Line                 | Arg #1      | Arg #2   | Arg #3 |
|------------------------------|-------------|----------|--------|
| ^"a \^" b^" c | a " b  | c        |        |
| ^"a \" b^" c  | a " b^ | c        |        |
| a b\^"c                 | a           | b"c |        |


## Rule #3 - The \ character

Plain `&lt;strong>\&lt;/strong>` character must be escaped with `&lt;strong>\\&lt;/strong>`&nbsp;if they precedes a `&lt;strong>"&lt;/strong>` character or `&lt;strong>^"&lt;/strong>` character sequence. (string or caret-string termination).

Examples:

| Command Line               | Arg #1      | Arg #2 | Arg #3 |
|----------------------------|-------------|--------|--------|
| a\\b                       | a\\b        |        |        |
| "a\\b"           | a\\b        |        |        |
| a\\"b c               | a\b c       |        |        |
| a\"b c                | a"b    | c      |        |
| a\\"b c"         | a\b c       |        |        |
| "a\\\"b c"  | a\"b c |        |        |
| a\\^"b c              | a\b c       |        |        |
| a\\^"b c"        | a\b c       |        |        |
| "a\\\^"b c" | a\\\^b      | c      |        |


## Rule #4 - Shell characters

The following characters are **special shell characters**:  
**&**, **<**, **>**, **(**, **)**, **|**, **%** or **!**

### Rule #4.1 (in string)

Shell characters must be read as plain text when inside a string.

Examples:

| Command Line         | Arg #1 | Arg #2 | Arg #3 |
|----------------------|--------|--------|--------|
| "a < b" c  | a < b  | c      |        |
| "a ^< b" c | a ^< b | c      |        |


### Rule #4.2 (in caret-string)

Plain shell characters must be escaped with `&lt;strong>^&lt;/strong>` when inside a caret-string or outside a string.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">Command Line</td>
    <td style="width: 125px;" width="112">Arg #1</td>
    <td width="86">Arg #2</td>
    <td width="86">Arg #3</td>
  </tr>
  <tr>
    <td>a ^< b</td>
    <td>a</td>
    <td>
       <
    </td>
    <td>b</td>
  </tr>
  <tr>
    <td>^"a ^< b^" c</td>
    <td>a < b</td>
    <td>c</td>
    <td></td>
  </tr>
  <tr>
    <td>^"a < b^" c</td>
    <td colspan="3">The system cannot find the file specified.</td>
  </tr>
  <tr>
    <td>^"a & b^" c</td>
    <td colspan="3">'b"' is not recognized as an internal or external command, operable program or batch file.</td>
  </tr>
  <tr>
    <td>^"a &whoami^"</td>
    <td colspan="3">outputs: %USERDOMAIN%\%USERNAME%</td>
  </tr>
</table>

### Rule #4.3 (Escaped non-shell characters)

Non-shell characters that are escaped with `&lt;strong>^&lt;/strong>` when inside a caret-string or outside a string and must be read as plain characters.

Examples:

| Command Line        | Arg #1 | Arg #2 | Arg #3 |
|---------------------|--------|--------|--------|
| ^a^b ^c             | ab     | c      |        |
| "^a^b" ^c | ^a^b   |        |        |


## Rule #5 - Empty arguments

Empty arguments must be specified with `&lt;strong>""&lt;/strong>` (enclosed by two consecutive delimiters).

{{< pleasenote >}}
  Note that empty arguments can also be specified with `&lt;strong>^"^"&lt;/strong>` or a combination of the two.
{{< /pleasenote >}}


Examples:

| Command Line       | Arg #1  | Arg #2  | Arg #3  |
|--------------------|---------|---------|---------|
| a "" b   | a       | [empty] | c       |
| "" a b   | [empty] | a       | b       |
| a b ""   | a       | b       | [empty] |
| a ^"^" b | a       | [empty] | b       |
| ^"^" a b | [empty] | a       | b       |
| a b ^"^" | a       | b       | [empty] |
| a ^"" b  | a       | [empty] | b       |
| ^"" a b  | [empty] | a       | b       |
| a b ^""  | a       | b       | [empty] |


## <span id="Rule_6_8211_Juxtaposed_strings"><a id="rule6"></a>Rule #6 - Juxtaposed strings</span>

Two juxtaposed strings (not separated by a delimiter character), will insert a plain double quotes character (`"`) between each other.

This rule applies to normal strings, caret-strings, or any combinations.

Examples:

| Command Line                       | Arg #1                                         | Arg #2 | Arg #3 |
|------------------------------------|------------------------------------------------|--------|--------|
| "a b""c d"     | a b"c d<br /> (as with [rule #2](#rule2)) |        |        |
| ^"a b^"^"c d^" | a b"c d                                   |        |        |
| ^"a b^""c d"   | a b"c d                                   |        |        |
| "a b"^"c d^"   | a b"c d                                   |        |        |
| "a b^"^"c d"   | a b^"c d                                  |        |        |


## Rule #7 - Any other characters

All other characters must be read as plain text.

## Exceptions:

### Exception #1

`&lt;strong>\"&lt;/strong>` characters sequence inside a caret-string. This formatting is against [rule #2.3](#rule2_3)&nbsp;which states that double quote character `"` should be entered as `\^"`&nbsp;or againt [rule #3](#rule3) which states that `\` characters should be entered as `\\"`.

Erroneous `&lt;strong>\"&lt;/strong>` sequence in a caret-string should be read as **_[end caret-string]_** and **_[start string]_** which as of [rule #6](#rule6)&nbsp;also inserts a plain `"` character.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">Command Line</td>
    <td style="width: 125px;" width="112">Arg #1</td>
    <td width="86">Arg #2</td>
    <td width="86">Arg #3</td>
  </tr>
  <tr>
    <td>
      ^"test\"<test&whoami^"
    </td>
    <td>
       test"<test&whoami^
    </td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>^"ab cd \" ef^"</td>
    <td>ab cd " ef^</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>^"ab cd \^" ef^"</td>
    <td>ab cd " ef</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>^"ab cd \\" ef^"</td>
    <td>ab cd \</td>
    <td>ef^</td>
    <td></td>
  </tr>
</table>

# Samples

Using the list of rules above, one can encode the following arguments into a fully qualified command line.

# Decoding samples

The following table shows multiple examples of command lines which decodes into multiple arguments.

{{< pleasenote >}}
  Note that some command lines are malformed or incomplete. The libArgvCodec library properly handle both cases.
{{< /pleasenote >}}


{{< pleasenote >}}
  Also note that some command line contains shell command (whoami and echo) which are used to demonstrate that libArgvCodec is secure and protects againts command line injection attacks.
{{< /pleasenote >}}


For the list of all verification tests executed with libArgvCodec, please see the source code of the libargvcodectest project.

| Command Line                           | Arg #1               | Arg #2      | Arg #3 |
|----------------------------------------|----------------------|-------------|--------|
| aaa"                              | aaa                  |             |        |
| aaa\"                             | aaa"            |             |        |
| aaa\\"                            | aaa\                 |             |        |
| aaa\\\"                           | aaa\"           |             |        |
| "aaa\"                       | aaa"            |             |        |
| "aaa\\"                      | aaa\                 |             |        |
| "aaa\\\"                     | aaa\"           |             |        |
| a"bc                              | abc                  |             |        |
| a"bc\                             | abc\                 |             |        |
| a"bc\\                            | abc\\                |             |        |
| a"bc\\\                           | abc\\\               |             |        |
| a"bc\"d                      | abc"d           |             |        |
| a"bc\\ ddd" e                | abc\\ ddd            | e           |        |
| a"bc\"\ ddd" e          | abc"\ ddd       | e           |        |
| ab\\c d                                | ab\\c                | d           |        |
| ab\\ c                                 | ab\\                 | c           |        |
| \\ab c                                 | \\ab                 | c           |        |
| a ""bc\"o" e" | a                    | bc"o e |        |
| a "bc\"o" e"       | a                    | bc"o   | e      |
| "a"""b             | a"b             |             |        |
| "a"""b"       | a"b             |             |        |
| "a\"b"                  | a"b             |             |        |
| "a""" b"      | a"              | b           |        |
| """                     | "               |             |        |
| """"               | "               |             |        |
| """""         | ""         |             |        |
| """"""   | ""         |             |        |
| ^"ab cd\^"^&echo foo^"  | ab cd"&echo foo |             |        |
| "ab cd\^"^&echo foo^"   | ab cd\^&echo         | foo         |        |
| ^"ab cd\^" ee"          | ab cd" ee       |             |        |
| "ab cd\" ee"            | ab cd" ee       |             |        |
| "ab cd\^" ee"           | ab cd\^              | ee          |        |
| "a^b" c                      | a^b                  | c           |        |
| ^"a^b" c                     | ab                   | c           |        |
| ^"ab^" c                     | ab                   | c           |        |
| ^"ab^"" c               | ab" c           |             |        |
| a \bb c                                | a                    | \bb         | c      |
| a \"bb c" d                  | a                    | "bb    | c d    |
| a ^"bb^" c" d           | a                    | bb          | c d    |
| a \"b c                           | a                    | "b     | c      |
| a""b c                       | ab                   | c           |        |
| a\"b c                            | a"b             | c           |        |
| "a""b" c           | a"b             | c           |        |
| "a\"b" c                | a"b             | c           |        |
| a ^"" b                      | a                    |             | b      |
| a ^"^" b                     | a                    |             | b      |
| ^"" a                        |                      | a           |        |
| ^"^" a                       |                      | a           |        |
| ^"test\^"^&whoami^"     | test"&whoami    |             |        |
| ^"test\\^"^&whoami^"    | test\&whoami         |             |        |
| ^"test\"^&whoami^"      | test"^&whoami^  |             |        |
| a\\\\"b                           | a\\b                 |             |        |
| ^"a\\\\"b"              | a\\b                 |             |        |
| ^"a\^\^\\"b"            | a\\b                 |             |        |
| ^"a\^\\^\"b"            | a\\b                 |             |        |
| ^"a\^\\\^"b"            | a\\b                 |             |        |

