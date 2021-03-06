---
title: libRtttl – A c++ library (with UI) for compressing/optimizing the RTTTL audio format
author: end2end
date: 2016-05-28T15:18:35+00:00
url: /librtttl-a-c-library-with-ui-for-compressingoptimizing-the-rtttl-audio-format/
images:
  - src: /wp-content/uploads/2016/05/libRtttl-cplusplus-library.jpg
hits:
  - 307
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Library binaries:
        * [[download id="1863" template="title"]](/download/1863/)
        * [[download id="1861" template="title"]](/download/1861/)
        * [[download id="1859" template="title"]](/download/1859/)
        * [[download id="1857" template="title"]](/download/1857/)
        Source code:
        * [[download id="2035" template="title"]](/download/2035/)
        
categories:
  - Development
tags:
  - arduino
  - english
  - open source
  - rtttl

---
# Introduction

The following article is about another library that I have written: libRtttl is a c++ library for manipulating the RTTTL audio format.

<!--more-->

Skip to the [download section](#Download) for quick download.

See this post for a [quick recall of the RTTTL format](/nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/#Quick_recall_of_the_RTTTL_format).

{{< postedit >}}
  Edit: for a better understanding and examples of what libRTTTL can do, please see this post:&nbsp;**[How to convert arduino code to actual RTTTL melodies using libRtttl and AnyRtttl](http://www.end2endzone.com/how-to-convert-arduino-code-to-actual-rtttl-melodies-using-librtttl-and-anyrtttl/ "Edit “How to convert arduino code to actual RTTTL melodies using libRtttl and AnyRtttl”").**
{{< /postedit >}}


# Purpose

RTTTL songs available on the internet are not optimized for the smallest size. Still they are readable by a human but they are far from optimized for the arduino embedded device. Most RTTTL song can be optimized (without quality loss) and have their size reduced by ~20%. Conversion to binary allows even better compression but it wont be human readable anymore.

The library also allows one to convert an RTTTL song to hardcoded function calls (`tone()` and `delay()` calls). This is really useful if your dynamic memory is almost completely full and you would like to move the load from dynamic memory to program storage space.

The UI (rtttlOptimizerGui)&nbsp;also features a basic RTTTL player. The quality of the playback is limited but it allows one to prove that a compression did not changed the song's melody.

# Library

## Functionalities / Features

Possible use are:

* Optimize an existing RTTTL melodies.
<li style="text-align: left;">
  Convert RTTTL melodies to other format: <li>
      MIDI.
    </li>
    * Arduino `tone()` and `delay()` function calls.
    * Binary format (10 bits per note) for maximum compression (minimum size).
    * Binary format (16 bits per note) for quick note offset addressing and minimum code footprint.
</li>

* Convert arduino `tone()` and `delay()`&nbsp;function calls back to a valid RTTTL melody.
* Allow relaxed RTTTL settings for easier conversions.

{{< pleasenote >}}
  Note that RTTTL binary format requires an external arduino library for playback. The [AnyRtttl library](/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/) supports all common RTTTL format including the binary format generated by this library.
{{< /pleasenote >}}


## Requirements

The library has some compilation requirements and library dependencies which are:

### libRtttl

* Only Visual Studio 2008 projects files are available. Files can be manually moved to other platforms or IDE as required. Supporting other compilers is not currently planned.
* Requires code from [BitReader](/bitreader-an-arduino-library-for-reading-writing-data-as-chunks-of-bits/)&nbsp;and [AnyRtttl](/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/) arduino libraries, [libMidi](/libmidi-a-c-open-source-library-for-generating-single-tone-melodies-in-midi-format/)&nbsp;and [win32Arduino](/win32arduino-a-win32-library-that-implements-most-arduino-functions/)&nbsp;win32 library which are all already included in source code.
* The [Google Test](http://github.com/google/googletest) v1.6 library is required for running test cases.

### rtttlOptimizerGui

* Requires the [wxWidgets Cross-Platform GUI Library](http://www.wxwidgets.org/)&nbsp;v2.8.12 for compiling.
* The UI design files must be edited with [wxFormBuilder](http://sourceforge.net/projects/wxformbuilder/)&nbsp; v3.0.57 (a RAD tool for wxWidgets GUI design). This tools is not required for compilation.
* [NSIS: Nullsoft Scriptable Install System](http://sourceforge.net/projects/nsis/)&nbsp;is required for generating the installation package.
* The Play RTTTL & RTTTL 2 MIDI functionalities require the Windows platform for runtime.
* The code uses some compiler-dependent instructions for debugging the UI under Windows.
* All non-portable code is protected with `#ifdef _WIN32` to be cross-platform friendly.

# Usage

All functionalities of the library are available through the UI.

Start the UI by launching rtttlOptimizerGui.exe.

[![rtttlOptimizerGui with default options](http://www.end2endzone.com/wp-content/uploads/2016/04/rtttlOptimizerGui-with-default-options.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/04/rtttlOptimizerGui-with-default-options.jpg)

rtttlOptimizerGui with default options

Copy & paste the input data in the Command Input text area. Click on one of the available command buttons. The output result will be displayed in the Command Output area.

## Optimize

Copy &&nbsp;paste a valid song in RTTTL format in the Command Input section.  
Press the Optimize button to compress the RTTTL code to its shortest form.

During optimization, the library will convert the input RTTTL song to "_raw_" data and re-encode the result back to RTTTL using all possible combinations of default duration, default octave and BPM (Beats per minute).

From all combination possibilities, the library will select the shortest one. For example, the following RTTTL code from _The Legend of Zelda _:


```
Zelda1:d=4,o=5,b=125:a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,
8p,8f6,16f.6,16f#6,16g#.6,2a#.6,16a#.6,16g#6,16f#.6,
8g#.6,16f#.6,2f6,f6,8d#6,16d#6,16f6,2f#6,8f6,8d#6,8c#6,
16c#6,16d#6,2f6,8d#6,8c#6,8c6,16c6,16d6,2e6,g6,8f6,16f,
16f,8f,16f,16f,8f,16f,16f,8f,8f,a#,f.,8a#,16a#,16c6,
16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,c#7,c7,
2a6,f6,2f#.6,a#6,a6,2f6,f6,2f#.6,a#6,a6,2f6,d6,2d#.6,
f#6,f6,2c#6,a#,c6,16d6,2e6,g6,8f6,16f,16f,8f,16f,16f,
8f,16f,16f,8f,8f
```


can be optimized to the following code:


```
Zelda1:d=8,o=6,b=250:2a#5,2f.5,4a#5,a#5,c,d,d#,1f,4p,4f,f.,2p,
1f#,g#.,1a#.,a#.,g#,f#.,4g#.,f#.,1f,2f,4d#,d#,2p,1f,1f#,4f,4d#,
4c#,c#,d#,1f,4d#,4c#,4c,c,d,1e,2p,2g,4f,f5,f5,4f5,f5,f5,4f5,f5,f5,
4f5,4f5,2a#5,2f.5,4a#5,a#5,c,d,d#,2p,2f,4p,4f,f.,f#,g#.,1a#.,
2c#7,2c7,1a,2f,1f#.,2a#,2a,1f,2f,2p,2f#.,2a#,2a,1f,2d,1d#.,2f#,
2f,1c#,2a#5,2c,d,1e,2g,4f,f5,f5,4f5,2p,1f5,f5,4f5,f5,f5,4f5,4f5
```


which reduces the original code length by 89 bytes (from 446 bytes to 357 bytes), that is a 19.95% size reduction.

## Play RTTTL

Copy & paste a valid song in RTTTL format in the Command Input section.  
Press the Play RTTTL button to play the melody.

{{< pleasenote >}}
  Note that application will momentary freeze during the playback. The application will respond again once the melody is done playing.
{{< /pleasenote >}}


## RTTTL to MIDI

Copy & paste a valid song in RTTTL format in the Command Input section.  
Press the RTTTL 2 MIDI button to convert the melody to the MIDI sound format and automatically play the melody.

{{< pleasenote >}}
  Note that MIDI sound format offers much better playback capabilities and sound quality than beeping each tone. See my post about my MIDI library for more details: [libMIDI - A C++ open-source library for generating single tone melodies in MIDI format](/libmidi-a-c-open-source-library-for-generating-single-tone-melodies-in-midi-format/).
{{< /pleasenote >}}


## tone() to RTTTL

Copy & paste a valid song in arduino code (`tone()` and `delay()`&nbsp;function calls)&nbsp;in the Command Input section.  
Press the tone() 2 RTTTL button to encode the melody into RTTTL.

For example, the following arduino code:


```
void playArkanoid(int pin) {
  tone(pin, 1568, 214);
  delay(215);
  delay(107);
  tone(pin, 1568, 160);
  delay(161);
  tone(pin, 1865, 856);
  delay(857);
  delay(53);
  tone(pin, 1760, 214);
  delay(215);
  tone(pin, 1568, 214);
  delay(215);
  tone(pin, 1397, 214);
  delay(215);
  tone(pin, 1760, 214);
  delay(215);
  tone(pin, 1568, 856);
  delay(857);
  noTone(pin);
}
```


is encoded into the following RTTTL code:


```
unknown:d=8,o=6,b=140:g,16p,16g.,2a#,32p,a,g,f,a,2g
```


This feature is useful for moving data from program storage space to dynamic memory.

## RTTTL to tone()

Copy & paste a valid song in RTTTL format in the Command Input section.  
Press the RTTTL 2 tone() button to decode the input song to "_raw_" data (note with frequency and duration) and generate the arduino code required to play the song.

This process is really useful if your dynamic memory is almost completely full and you would like to move the load from dynamic memory to program storage space.

For instance, the RTTTL code from _Super Mario Bros. - 1-up sound_&nbsp;:

`mario1up:d=16,o=7,b=180:e.6,g.6,e.,c.,d.,g.`

generates the following arduino code:


```cpp
void playMario1up(int pin) {
  tone(pin, 1319, 124);
  delay(125);
  tone(pin, 1568, 124);
  delay(125);
  tone(pin, 2637, 124);
  delay(125);
  tone(pin, 2093, 124);
  delay(125);
  tone(pin, 2349, 124);
  delay(125);
  tone(pin, 3136, 124);
  delay(125);
  noTone(pin);
}
```


## RTTTL to Binary (10 bits)

Copy & paste a valid song in RTTTL format in the Command Input section.  
Press the RTTTL 2 Binary (10 bits)&nbsp;button to decode the input RTTTL song and encode the same melody into a binary RTTTL format where each note is encoded into 10 bits. The bits definition is already documented in section [RTTTL binary format definition](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/#Binary_RTTTL_format_definition)&nbsp;of [AnyRtttl library](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/) post.

The [AnyRtttl](/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/)&nbsp;library can be used to play the compressed RTTTL data.

For example, the RTTTL code for playing _Tetris_&nbsp;theme song:


```
tetris:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,
8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a,8p,d6,8f6,a6,8g6,
8f6,e6,8e6,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,a
```


is compressed to the following :

{{< hightlight-static-file file="/static/wp-content/uploads/2016/04/Tetris-theme-RTTTL-encoded-as-10-bits-notes.ino" lang="cpp" >}}

which reduces the original code length by 104 bytes (from 159 bytes to 55 bytes), that is a 65% size reduction.

## RTTTL to Binary (16 bits)

Copy & paste a valid song in RTTTL format in the Command Input section.  
Press the RTTTL 2 Binary (16 bits)&nbsp;button to decode the input RTTTL song and encode the same melody into a binary RTTTL format where each note is encoded into 16 bits. The bits definition is already documented in section [RTTTL binary format definition](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/#Binary_RTTTL_format_definition)&nbsp;of [AnyRtttl library](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/) post.

The [AnyRtttl](/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/)&nbsp;library can be used to play the compressed RTTTL data.

For example, the same RTTTL code for playing _Tetris_&nbsp;theme song:


```
tetris:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,
8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a,8p,d6,8f6,a6,8g6,
8f6,e6,8e6,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,a
```


is compressed to the following :

{{< hightlight-static-file file="/static/wp-content/uploads/2016/04/Tetris-theme-RTTTL-encoded-as-16-bits-notes.ino" lang="cpp" >}}

which reduces the original code length by 73 bytes (from 159 bytes to 86 bytes), that is a 46%&nbsp;size reduction.

# License

libRTTTL Library /&nbsp;rtttlOptimizer  
Copyright (C) 2016 Antoine Beauchamp  
The code & updates for the library can be found on http://end2endzone.com

**AUTHOR/LICENSE:**  
This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public  
License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the libRTTTL library /&nbsp;rtttlOptimizer by clicking on the following links:


		[ Download "rtttlOptimizer v1.2.195 Source Code" rtttlOptimizer-v1.2.195-src.zip - Downloaded 343 times - 186 KB ](http://www.end2endzone.com/download/2035/)


		[ Download "rtttlOptimizer v1.2.195 win32 portable" rtttlOptimizer-v1.2.195-win32-portable.zip - Downloaded 350 times - 720 KB ](http://www.end2endzone.com/download/1863/)


		[ Download "rtttlOptimizer v1.2.195 win32 Setup" rtttlOptimizer-v1.2.195-win32-Setup.exe - Downloaded 453 times - 834 KB ](http://www.end2endzone.com/download/1861/)


		[ Download "rtttlOptimizer v1.2.195 x64 portable" rtttlOptimizer-v1.2.195-x64-portable.zip - Downloaded 350 times - 847 KB ](http://www.end2endzone.com/download/1859/)


		[ Download "rtttlOptimizer v1.2.195 x64 Setup" rtttlOptimizer-v1.2.195-x64-Setup.exe - Downloaded 482 times - 969 KB ](http://www.end2endzone.com/download/1857/)
