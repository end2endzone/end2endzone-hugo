---
title: AnyRtttl – A feature rich arduino library for playing RTTTL melodies
author: end2end
date: 2016-05-21T23:20:34+00:00
url: /anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/
images:
  - src: /wp-content/uploads/2016/05/AnyRtttl-arduino-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Library:
        * [AnyRtttl arduino library](/download/1988/)
        Examples:
        * [AnyRtttl Non-Blocking.ino](/download/1977/)
        * [AnyRtttl Play (16 bits).ino](/download/1981/)
        * [AnyRtttl Play (10 bits).ino](/download/1979/)
        * [AnyRtttl RTTTL 2 code.ino](/download/1983/)
        
hits:
  - 1282
categories:
  - Development
tags:
  - arduino
  - arduino library
  - english
  - open source
  - rtttl

---
# Introduction

The following article is about yet another Arduino library that I have written. AnyRtttl is a feature rich arduino library for playing RTTTL melodies. The library offers much more interesting features than relying on the widely available `void play_rtttl(char *p)` function. The AnyRtttl is a feature rich library which supports all best RTTTL features.
Skip to the [download section](#Download) for quick download.

# Purpose

See this post for a [quick recall of the RTTTL format](/nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/#Quick_recall_of_the_RTTTL_format).

{{< pleasenote >}}
  Note that AnyRtttl library is a port from my [NonBlockingRtttl arduino library](/nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/) which is now deprecated since development has stopped.
{{< /pleasenote >}}


After publishing my NonBlockingRtttl arduino library, I started using the library in more complex projects which was requiring other libraries. I quickly ran into the hell of library dependencies and library conflicts. I realized that I needed more features that could help me prototype faster.

Other libraries available which allows you to "play" a melody in [RTTTL f](#Quick_recall_of_the_RTTTL_format)ormat suffer the same issue: they are based on blocking APIs or the RTTTL data is not optimized for space.

AnyRtttl is different since it packs multiple RTTTL related features in a single library. It supports [blocking](https://en.wikipedia.org/wiki/Blocking_(computing)) & [non-blocking](http://en.wikipedia.org/wiki/Non-blocking_algorithm) API which makes it suitable to be used by more advanced algorithm. For instance, when using the non-blocking API, the melody can be stopped when a button is pressed. The library is also compatible with _external Tone libraries_ and it supports highly compressed RTTTL binary formats.

# Library features

Here is a list of all library features:

* Really small increase in memory & code footprint compared to the usual blocking algorithm.
* Blocking & Non-Blocking modes available.
* Support custom `tone()`, `noTone()`, `delay()` and `millis()` functions.
* Compatible with external Tone libraries.
* Supports highly compressed RTTTL binary format.
* Supports RTTTL melodies stored in _Program Memory_ (`PROGMEM`).
* Play two monolithic melodies on two different pins using 2 [piezo buzzer](https://www.google.com/?q=piezo+buzzer) with the help of an external Tone library.

## Non-Blocking

Most of the code that can "play" a melody on internet are all build the same way: sequential calls to `tone()` and `delay()` functions using hardcoded values. This type of implementation might be good for robots but not for realtime application or projects that needs to monitor pins while the song is playing.

With AnyRtttl non-blocking mode, your program can read/write IOs pins while playing and react on changes. Implementing a "stop" or "next song" push button is a breeze!

## External Tone or Timer #0 libraries

The AnyRtttl library is also flexible by allowing you to use the build-in arduino `tone()` and `noTone()` functions or an implementation from any external library which makes it compatible with any _Tone library_ in the market.

The library also supports custom `delay()` and `millis()` functions. If a projects requires modification to the microcontroller’s build-in Timer #0, the `millis()` function may be impacted and behave incorrectly. To maximize compatibility, one can supply a custom function which behaves like the original to prevent altering playback.

## Binary RTTTL

The AnyRtttl library also supports playing RTTTL data which is stored as binary data instead of text. This is actually a custom implementation of the RTTTL format. Using these format, one can achieve storing an highly compressed RTTTL melody which saves memory.

See the [Binary RTTTL format definition](#Binary_RTTTL_format_definition) section for details.

# Usage

Define ANY\_RTTTL\_INFO to enable the debugging of the library state on the serial port.

Use ANY\_RTTTL\_VERSION to get the current version of the library.

## Non-blocking mode

Call `anyrtttl::begin()` to setup the AnyRtttl library in non-blocking mode. Then call `anyrtttl::play()` to update the library's state and play notes as required.

Use `anyrtttl::done()` or `anyrtttl::isPlaying()` to know if the library is done playing the given song.

Anytime one can call `anyrtttl::stop()` to stop playing the current song.

Demo

The following demo show how to use the library in non-blocking mode:  
(download 
	[ AnyRtttl v2.0 Non-Blocking example (751 downloads) ](http://www.end2endzone.com/download/1977/ "Version 2.0"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/05/AnyRtttl-v2.0-NonBlocking-example.ino" lang="cpp" >}}

## Play 16 bits per note RTTTL

Note that this mode requires that an RTTTL melody be already converted to 16-bits per note binary format.

Use the `anyrtttl::blocking::play16Bits()` API for playing an RTTTL melody encoded as 16 bits per note.

Demo

The following demo show how to use the library with 16-bits per note binary RTTTL:  
(download 
	[ AnyRtttl v2.0 Play 16 bits example (704 downloads) ](http://www.end2endzone.com/download/1981/ "Version 2.0"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/05/AnyRtttl-v2.0-Play-16-bits-example.ino" lang="cpp" >}}

## Play 10 bits per note RTTTL

Note that this mode requires that an RTTTL melody be already converted to 10-bits per note binary format.

Create a function that will be used by AnyRtttl library to read bits as required. The signature of the library must look like this:  
`uint16_t function_name(uint8_t numBits)`.

Note that this demo uses the [arduino BitReader library](/bitreader-an-arduino-library-for-reading-writing-data-as-chunks-of-bits/) to extract bits from the RTTTL binary buffer. The implementation of `readNextBits()` function delegates the job to the BitReader's `read()` method.

In the `setup()` function, setup the external library that is used for reading bits: `bitreader.setBuffer(tetris10);`

Use the `anyrtttl::blocking::play10Bits()` API for playing an RTTTL melody encoded as 10 bits per note. The 3rd argument of the function requires a pointer to the function extracting bits: `&function_name`.

Demo

The following demo show how to use the library with 10-bits per note binary RTTTL:  
(download 
	[ AnyRtttl v2.0 Play 10 bits example (658 downloads) ](http://www.end2endzone.com/download/1979/ "Version 2.0"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/05/AnyRtttl-v2.0-Play-10-bits-example.ino" lang="cpp" >}}

## Custom Tone function (a.k.a. RTTTL 2 code)

This demo shows how custom functions can be used by the AnyRtttl library. This example shows how to convert an RTTTL melody to arduino code.

First define replacement functions like the following:


```cpp
void serialTone(byte pin, uint16_t frequency, uint32_t duration) {
  Serial.print("tone(");
  Serial.print(pin);
  Serial.print(",");
  Serial.print(frequency);
  Serial.print(",");
  Serial.print(duration);
  Serial.println(");");
}

void serialNoTone(byte pin) {
  Serial.print("noTone(");
  Serial.print(pin);
  Serial.println(");");
}

void serialDelay(uint32_t duration) {
  Serial.print("delay(");
  Serial.print(duration);
  Serial.println(");");
}
```


Each new functions prints the function call & arguments to the serial port.

In the `setup()` function, setup the AnyRtttl library to use the new functions:


```cpp
//Use custom functions
anyrtttl::setToneFunction(&serialTone);
anyrtttl::setNoToneFunction(&serialNoTone);
anyrtttl::setDelayFunction(&serialDelay);
```


Use the `anyrtttl::blocking::play()` API for "playing" an RTTTL melody and monitor the output of the serial port to see the actual arduino code generated by the library.

Demo

The following demo show how to use the library with custom functions:  
(download 
	[ AnyRtttl v2.0 RTTTL 2 code example (657 downloads) ](http://www.end2endzone.com/download/1983/ "Version 2.0"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/05/AnyRtttl-v2.0-Rtttl-2-Code-example.ino" lang="cpp" >}}

# Binary RTTTL format definition<br /> 

The following section defines the field order and size (in bits) required for encoding / decoding of each melody as binary RTTTL.

{{< pleasenote >}}
  Note that all fields definition are defined in LSB to MSB order.
{{< /pleasenote >}}


The first 16 bits stores the RTTTL default section which is defined as the following:

* **Default duration index**, 3 bits, with values within [0, 7] range, matches the index used for `getNoteDurationFromIndex()` API.
* **Default octave index**, 2 bits, with values within [0, 3] range, matches the index used for `getNoteOctaveFromIndex()` API.
* **Beats per minutes (BPM)**, 10 bits, with values within [1, 900].
* **Padding**, 1 bit

Next is each note's of the melody. Each note is encoded as 10 bits (or 16 bits) per note and is defined as the following:

  1. **Duration index**, 3 bits, with values within [0, 7] range,  matches the index used for `getNoteDurationFromIndex()` API.
  2. **Note letter index**, 3 bits, with values within [0, 7] range, matches the index used for `getNoteLetterFromIndex()` API.
  3. **Pound**, 1 bit, defines if the note is pounded or not.
  4. **Dotted**, 1 bit, defines if the note is dotted or not.
  5. **Octave index**, 2 bits, with values within [0, 3] range, matches the index used for `getNoteOctaveFromIndex()` API.
  6. **Padding**, 6 bits, **optional**. See sections below.

{{< pleasenote >}}
  The last field of a note (defined as _Padding_) is an **optional 6 bits** field. The AnyRtttl library supports both 10 bits per note and 16 bits per note definitions. Use the appropriate API for playing both format.
{{< /pleasenote >}}


## 10 bits per note (no padding)

Each RTTTL note is encoded into 10 bits which is the minimum size of a note. This storage method is the best compression method for storing RTTTL melodies and reduces the usage of the dynamic memory to the minimum.

However, since all notes are not aligned on multiple of 8 bits, addressing each note by an offset is impossible which makes the playback harder. Each notes must be [deserialized](http://en.wikipedia.org/wiki/Serialization) one after the other. An additional library is required for deserializing a note from a buffer using blocks of 10 bits which may increase the program storage space footprint.

An external arduino library must also be used to allow the AnyRtttl library to consume bits as needed. The [arduino BitReader library](/bitreader-an-arduino-library-for-reading-writing-data-as-chunks-of-bits/) may be used for handling bit deserialization but any library that can extract a given number of bits from a buffer would work.

## 16 bits per note (with padding)

Each RTTTL note is encoded into 16 bits which is much better than the average 3.28 bytes per note text format. This storage method is optimum for storing RTTTL melodies and reduces the usage of the dynamic memory without increasing to much program storage space.

All notes are aligned on 16 bits. Addressing each note by an offset allows an easy playback. Only the first 10 bits of each 16 bits block is used. The value of the padding field is undefined.

## Playback

The following AnyRtttl blocking APIs are available for playing both format:

* 10 bits per note: `play10Bits()`.
* 16 bits per note: `play16Bits()`.

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the AnyRtttl library by clicking on the following link:


		[ Download "AnyRtttl v2.1.229 arduino library" AnyRtttl-v2.1.229.zip - Downloaded 571 times - 54 KB ](http://www.end2endzone.com/download/1988/)
