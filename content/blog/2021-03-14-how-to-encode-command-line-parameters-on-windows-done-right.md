---
title: How to encode command line parameters on Windows – done right
author: end2end
type: post
date: 2021-03-14T14:49:47+00:00
url: /how-to-encode-command-line-parameters-on-windows-done-right/
featured_image: /wp-content/uploads/2017/06/How-to-encode-command-line-parameters-on-Windows-done-right.jpg
hits:
  - 31
categories:
  - Development
tags:
  - english

---
# <span id="Introduction">Introduction</span>

This post is a follow up on command line arguments. I recently published a C++ library ([libArgvCodec][1]) which properly handles all encoding and decoding of command line arguments. It is much safer to use the library than simply wrap each argument with double quotes.

This post is about the list of rules that the library implements for encoding and decoding of arguments.<!--more-->

# <span id="Using_libArgvCodec_library">Using libArgvCodec library</span>

The [libArgvCodec][1] library can be used for free and is released as Open Source. The code is available [here][2]. Feel free to download the library to use it in your own projects.

# <span id="Encoding_and_Decoding_rules">Encoding and Decoding rules</span>

If you do not want to use the library, the following section shows the rules that are implemented into the library for properly handling all situations and special characters.

Feel free to use these rules to implement your own library.

## <span id="Rule_1_8211_Delimiters">Rule #1 &#8211; Delimiters</span>

Tabs or [space] characters are argument delimiters (separators) but **\*only\*** when outside a string and outside a caret-string.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      a b c
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b
    </td>
    
    <td>
      c
    </td>
  </tr>
</table>

## <span id="Rule_2_8211_Strings"><a id="rule2"></a>Rule #2 &#8211; Strings</span>

Double quotes character (<code class="prettycode">"</code>) starts or ends a string. Strings allows one to insert a delimiter (or separators) character to an argument. The double quotes character is omitted from the argument.

<p class="pleasenote" data-pleasenote="true">
  Note that strings <strong>*may</strong> <strong>not*</strong> always be ended (the end of the command line may be hit without the end-of-string character)
</p>

If a string is juxtaposed to another argument (not separated by a delimiter character), they form the same argument.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a b c&#8221;
    </td>
    
    <td>
       a b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221; b&#8221; c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a &#8220;b c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
</table>

### <span id="Rule_21_8211_Plain_double_quotes">Rule #2.1 &#8211; Plain double quotes</span>

Plain double quotes character (<code class="prettycode">"</code>) must be escaped with <code class="prettycode">&lt;strong>\"&lt;/strong></code> (or escaped with <code class="prettycode">&lt;strong>""&lt;/strong></code>) and does not end the string. (If not escaped, they act as strings markers ([Rule #2][3]).

Characters escaped with <code class="prettycode">&lt;strong>\"&lt;/strong></code> can be seen inside or outside strings but characters escaped with <code class="prettycode">&lt;strong>""&lt;/strong></code> can **\*only\*** be seen inside a string.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      a \&#8221;b c
    </td>
    
    <td>
       a
    </td>
    
    <td>
      &#8220;b
    </td>
    
    <td>
      c
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a \&#8221;b&#8221; c
    </td>
    
    <td>
       a &#8220;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a &#8220;&#8221;b&#8221; c
    </td>
    
    <td>
      a &#8220;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a &#8220;&#8221;b c
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b
    </td>
    
    <td>
      c
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221;&#8221;&#8221;
    </td>
    
    <td>
      &#8220;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
</table>

### <span id="Rule_22_8211_Caret-String">Rule #2.2 &#8211; Caret-String</span>

<code class="prettycode">&lt;strong>^"&lt;/strong></code> sequence starts or ends a caret-string. Caret-strings are different than normal strings. Caret-strings may be ended with an unescaped <code class="prettycode">&lt;strong>"&lt;/strong></code> character. Caret-string may not be ended.

<p class="pleasenote" data-pleasenote="true">
  Note that caret-strings <strong>*may</strong> <strong>not*</strong> always be ended (the end of the command line may be hit without the end-of-string character)
</p>

If a caret-string is juxtaposed to another argument (not separated by a delimiter character), they are part of the same argument.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;a b^&#8221; c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;a b&#8221; c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;a b^&#8221;c
    </td>
    
    <td>
       a bc
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       a^&#8221;b c^&#8221;
    </td>
    
    <td>
      ab c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a b c^&#8221;
    </td>
    
    <td>
       a b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a^&#8221; b^&#8221; c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a ^&#8221;b c
    </td>
    
    <td>
      a b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
</table>

### <span id="Rule_23_8211_Plain_double_quotes_Caret-String"><a id="rule2_3"></a>Rule #2.3 &#8211; Plain double quotes  (Caret-String)</span>

Plain double quotes character (<code class="prettycode">"</code>) must be escaped with <code class="prettycode">&lt;strong>\^"&lt;/strong></code> when inside a caret-string.

<p class="pleasenote" data-pleasenote="true">
  Note that <code class="prettycode">&lt;strong>\^"&lt;/strong></code> characters sequence can also be visible outside a string.
</p>

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a \^&#8221; b^&#8221; c
    </td>
    
    <td>
       a &#8221; b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a \&#8221; b^&#8221; c
    </td>
    
    <td>
       a &#8221; b^
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a b\^&#8221;c
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b&#8221;c
    </td>
    
    <td>
    </td>
  </tr>
</table>

## <span id="Rule_3_8211_The_character">Rule #3 &#8211; The \ character</span>

Plain <code class="prettycode">&lt;strong>\&lt;/strong></code> character must be escaped with <code class="prettycode">&lt;strong>\\&lt;/strong></code> if they precedes a <code class="prettycode">&lt;strong>"&lt;/strong></code> character or <code class="prettycode">&lt;strong>^"&lt;/strong></code> character sequence. (string or caret-string termination).

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      a\\b
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a\\b&#8221;
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       a\\&#8221;b c
    </td>
    
    <td>
       a\b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a\&#8221;b c
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a\\&#8221;b c&#8221;
    </td>
    
    <td>
       a\b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a\\\&#8221;b c&#8221;
    </td>
    
    <td>
      a\&#8221;b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       a\\^&#8221;b c
    </td>
    
    <td>
       a\b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a\\^&#8221;b c&#8221;
    </td>
    
    <td>
      a\b c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a\\\^&#8221;b c&#8221;
    </td>
    
    <td>
       a\\\^b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
</table>

## <span id="Rule_4_8211_Shell_characters">Rule #4 &#8211; Shell characters</span>

The following characters are **special shell characters**:  
**&**, **<**, **>**, **(**, **)**, **|**, **%** or **!**

### <span id="Rule_41in_string">Rule #4.1 (in string)</span>

Shell characters must be read as plain text when inside a string.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a < b&#8221; c
    </td>
    
    <td>
      a < b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a ^< b&#8221; c
    </td>
    
    <td>
       a ^< b
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
</table>

### <span id="Rule_42_in_caret-string">Rule #4.2 (in caret-string)</span>

Plain shell characters must be escaped with <code class="prettycode">&lt;strong>^&lt;/strong></code> when inside a caret-string or outside a string.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
       a ^< b
    </td>
    
    <td>
       a
    </td>
    
    <td>
       <
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a ^< b^&#8221; c
    </td>
    
    <td>
       a < b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a < b^&#8221; c
    </td>
    
    <td colspan="3">
        The system cannot find the file specified.
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a & b^&#8221; c
    </td>
    
    <td colspan="3">
      &#8216;b&#8221;&#8216; is not recognized as an internal or external command, operable program or batch file.
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a &whoami^&#8221;
    </td>
    
    <td colspan="3">
      outputs: %USERDOMAIN%\%USERNAME%
    </td>
  </tr>
</table>

### <span id="Rule_43_Escaped_non-shell_characters">Rule #4.3 (Escaped non-shell characters)</span>

Non-shell characters that are escaped with <code class="prettycode">&lt;strong>^&lt;/strong></code> when inside a caret-string or outside a string and must be read as plain characters.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
       ^a^b ^c
    </td>
    
    <td>
      ab
    </td>
    
    <td>
       c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;^a^b&#8221; ^c
    </td>
    
    <td>
       ^a^b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
</table>

## <span id="Rule_5_8211_Empty_arguments">Rule #5 &#8211; Empty arguments</span>

Empty arguments must be specified with <code class="prettycode">&lt;strong>""&lt;/strong></code> (enclosed by two consecutive delimiters).

<p class="pleasenote" data-pleasenote="true">
  Note that empty arguments can also be specified with <code class="prettycode">&lt;strong>^"^"&lt;/strong></code> or a combination of the two.
</p>

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      a &#8220;&#8221; b
    </td>
    
    <td>
       a
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
      c
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221; a b
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
       a
    </td>
    
    <td>
       b
    </td>
  </tr>
  
  <tr>
    <td>
      a b &#8220;&#8221;
    </td>
    
    <td>
       a
    </td>
    
    <td>
      b
    </td>
    
    <td>
       [empty]
    </td>
  </tr>
  
  <tr>
    <td>
      a ^&#8221;^&#8221; b
    </td>
    
    <td>
      a
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
       b
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;^&#8221; a b
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
       a
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
       a b ^&#8221;^&#8221;
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b
    </td>
    
    <td>
      [empty]
    </td>
  </tr>
  
  <tr>
    <td>
       a ^&#8221;&#8221; b
    </td>
    
    <td>
      a
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;&#8221; a b
    </td>
    
    <td>
       [empty]
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
      a b ^&#8221;&#8221;
    </td>
    
    <td>
      a
    </td>
    
    <td>
      b
    </td>
    
    <td>
      [empty]
    </td>
  </tr>
</table>

## <span id="Rule_6_8211_Juxtaposed_strings"><a id="rule6"></a>Rule #6 &#8211; Juxtaposed strings</span>

Two juxtaposed strings (not separated by a delimiter character), will insert a plain double quotes character (<code class="prettycode">"</code>) between each other.

This rule applies to normal strings, caret-strings, or any combinations.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a b&#8221;&#8221;c d&#8221;
    </td>
    
    <td>
       a b&#8221;c d<br /> (as with <a href="#rule2">rule #2</a>)
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;a b^&#8221;^&#8221;c d^&#8221;
    </td>
    
    <td>
      a b&#8221;c d
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       ^&#8221;a b^&#8221;&#8221;c d&#8221;
    </td>
    
    <td>
      a b&#8221;c d
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a b&#8221;^&#8221;c d^&#8221;
    </td>
    
    <td>
       a b&#8221;c d
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
       &#8220;a b^&#8221;^&#8221;c d&#8221;
    </td>
    
    <td>
      a b^&#8221;c d
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
</table>

## <span id="Rule_7_8211_Any_other_characters">Rule #7 &#8211; Any other characters</span>

All other characters must be read as plain text.

## <span id="Exceptions"><span style="font-size: 24px; font-weight: bold;">Exceptions:</span></span>

### <span id="Exception_1">Exception #1</span>

<code class="prettycode">&lt;strong>\"&lt;/strong></code> characters sequence inside a caret-string. This formatting is against [rule #2.3][4] which states that double quote character <code class="prettycode">"</code> should be entered as <code class="prettycode">\^"</code> or againt [rule #3][5] which states that <code class="prettycode">\</code> characters should be entered as <code class="prettycode">\\"</code>.

Erroneous <code class="prettycode">&lt;strong>\"&lt;/strong></code> sequence in a caret-string should be read as **_[end caret-string]_** and **_[start string]_** which as of [rule #6][6] also inserts a plain <code class="prettycode">"</code> character.

Examples:

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;test\&#8221;<test&whoami^&#8221;
    </td>
    
    <td>
       test&#8221;<test&whoami^
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab cd \&#8221; ef^&#8221;
    </td>
    
    <td>
      ab cd &#8221; ef^
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab cd \^&#8221; ef^&#8221;
    </td>
    
    <td>
      ab cd &#8221; ef
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab cd \\&#8221; ef^&#8221;
    </td>
    
    <td>
      ab cd \
    </td>
    
    <td>
      ef^
    </td>
    
    <td>
    </td>
  </tr>
</table>

# <span id="Samples">Samples</span>

Using the list of rules above, one can encode the following arguments into a fully qualified command line.

# <span id="Decoding_samples">Decoding samples</span>

The following table shows multiple examples of command lines which decodes into multiple arguments.

<p class="pleasenote" data-pleasenote="true">
  Note that some command lines are malformed or incomplete. The libArgvCodec library properly handle both cases.
</p>

<p class="pleasenote" data-pleasenote="true">
  Also note that some command line contains shell command (whoami and echo) which are used to demonstrate that libArgvCodec is secure and protects againts command line injection attacks.
</p>

For the list of all verification tests executed with libArgvCodec, please see the source code of the libargvcodectest project.

<table class=" generictable" width="455" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td width="158">
      Command Line
    </td>
    
    <td style="width: 125px;" width="112">
      Arg #1
    </td>
    
    <td width="86">
      Arg #2
    </td>
    
    <td width="86">
      Arg #3
    </td>
  </tr>
  
  <tr>
    <td>
      aaa&#8221;
    </td>
    
    <td>
      aaa
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      aaa\&#8221;
    </td>
    
    <td>
      aaa&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      aaa\\&#8221;
    </td>
    
    <td>
      aaa\
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      aaa\\\&#8221;
    </td>
    
    <td>
      aaa\&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;aaa\&#8221;
    </td>
    
    <td>
      aaa&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;aaa\\&#8221;
    </td>
    
    <td>
      aaa\
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;aaa\\\&#8221;
    </td>
    
    <td>
      aaa\&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc
    </td>
    
    <td>
      abc
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\
    </td>
    
    <td>
      abc\
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\\
    </td>
    
    <td>
      abc\\
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\\\
    </td>
    
    <td>
      abc\\\
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\&#8221;d
    </td>
    
    <td>
      abc&#8221;d
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\\ ddd&#8221; e
    </td>
    
    <td>
      abc\\ ddd
    </td>
    
    <td>
      e
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;bc\&#8221;\ ddd&#8221; e
    </td>
    
    <td>
      abc&#8221;\ ddd
    </td>
    
    <td>
      e
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ab\\c d
    </td>
    
    <td>
      ab\\c
    </td>
    
    <td>
      d
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ab\\ c
    </td>
    
    <td>
      ab\\
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      \\ab c
    </td>
    
    <td>
      \\ab
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a &#8220;&#8221;bc\&#8221;o&#8221; e&#8221;
    </td>
    
    <td>
      a
    </td>
    
    <td>
      bc&#8221;o e
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a &#8220;bc\&#8221;o&#8221; e&#8221;
    </td>
    
    <td>
      a
    </td>
    
    <td>
      bc&#8221;o
    </td>
    
    <td>
      e
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a&#8221;&#8221;&#8221;b
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a&#8221;&#8221;&#8221;b&#8221;
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a\&#8221;b&#8221;
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a&#8221;&#8221;&#8221; b&#8221;
    </td>
    
    <td>
      a&#8221;
    </td>
    
    <td>
      b
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221;&#8221;
    </td>
    
    <td>
      &#8220;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221;&#8221;&#8221;
    </td>
    
    <td>
      &#8220;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221;&#8221;&#8221;&#8221;
    </td>
    
    <td>
      &#8220;&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;&#8221;&#8221;&#8221;&#8221;&#8221;
    </td>
    
    <td>
      &#8220;&#8221;
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab cd\^&#8221;^&echo foo^&#8221;
    </td>
    
    <td>
      ab cd&#8221;&echo foo
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;ab cd\^&#8221;^&echo foo^&#8221;
    </td>
    
    <td>
      ab cd\^&echo
    </td>
    
    <td>
      foo
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab cd\^&#8221; ee&#8221;
    </td>
    
    <td>
      ab cd&#8221; ee
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;ab cd\&#8221; ee&#8221;
    </td>
    
    <td>
      ab cd&#8221; ee
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;ab cd\^&#8221; ee&#8221;
    </td>
    
    <td>
      ab cd\^
    </td>
    
    <td>
      ee
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a^b&#8221; c
    </td>
    
    <td>
      a^b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a^b&#8221; c
    </td>
    
    <td>
      ab
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab^&#8221; c
    </td>
    
    <td>
      ab
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;ab^&#8221;&#8221; c
    </td>
    
    <td>
      ab&#8221; c
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a \bb c
    </td>
    
    <td>
      a
    </td>
    
    <td>
      \bb
    </td>
    
    <td>
      c
    </td>
  </tr>
  
  <tr>
    <td>
      a \&#8221;bb c&#8221; d
    </td>
    
    <td>
      a
    </td>
    
    <td>
      &#8220;bb
    </td>
    
    <td>
      c d
    </td>
  </tr>
  
  <tr>
    <td>
      a ^&#8221;bb^&#8221; c&#8221; d
    </td>
    
    <td>
      a
    </td>
    
    <td>
      bb
    </td>
    
    <td>
      c d
    </td>
  </tr>
  
  <tr>
    <td>
      a \&#8221;b c
    </td>
    
    <td>
      a
    </td>
    
    <td>
      &#8220;b
    </td>
    
    <td>
      c
    </td>
  </tr>
  
  <tr>
    <td>
      a&#8221;&#8221;b c
    </td>
    
    <td>
      ab
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a\&#8221;b c
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a&#8221;&#8221;b&#8221; c
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      &#8220;a\&#8221;b&#8221; c
    </td>
    
    <td>
      a&#8221;b
    </td>
    
    <td>
      c
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a ^&#8221;&#8221; b
    </td>
    
    <td>
      a
    </td>
    
    <td>
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
      a ^&#8221;^&#8221; b
    </td>
    
    <td>
      a
    </td>
    
    <td>
    </td>
    
    <td>
      b
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;&#8221; a
    </td>
    
    <td>
    </td>
    
    <td>
      a
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;^&#8221; a
    </td>
    
    <td>
    </td>
    
    <td>
      a
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;test\^&#8221;^&whoami^&#8221;
    </td>
    
    <td>
      test&#8221;&whoami
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;test\\^&#8221;^&whoami^&#8221;
    </td>
    
    <td>
      test\&whoami
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;test\&#8221;^&whoami^&#8221;
    </td>
    
    <td>
      test&#8221;^&whoami^
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      a\\\\&#8221;b
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a\\\\&#8221;b&#8221;
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a\^\^\\&#8221;b&#8221;
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a\^\\^\&#8221;b&#8221;
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      ^&#8221;a\^\\\^&#8221;b&#8221;
    </td>
    
    <td>
      a\\b
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
</table>

 [1]: /libargvcodec-a-c-library-which-properly-encode-and-decode-command-line-arguments/
 [2]: /download/2480/
 [3]: #rule2
 [4]: #rule2_3
 [5]: #rule3
 [6]: #rule6