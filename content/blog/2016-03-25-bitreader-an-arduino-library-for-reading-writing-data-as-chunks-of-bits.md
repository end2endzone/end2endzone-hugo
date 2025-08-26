---
title: 'BitReader – An arduino library for reading & writing data as chunks of bits'
author: end2end
date: 2016-03-26T00:23:05+00:00
url: /bitreader-an-arduino-library-for-reading-writing-data-as-chunks-of-bits/
images:
  - src: /wp-content/uploads/2016/03/Arduino-BitReader-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Library:
        * [BitReader arduino library](/download/1688/)
        Example:
        * [Benchmark demo sample](/download/1691/)
        
hits:
  - 146
categories:
  - Development
tags:
  - arduino
  - arduino library
  - english
  - open source

---
# Introduction

Here is another arduino library that I have written.

As a desktop developer, I am not used to have memory (or even CPU) requirements as most developers will not look at memory consumption as an arduino developer would. Memory & CPU is cheap. If your application is struggling to run on today's computer, it will run smoothly in 1-2 years.

As most arduino developers have faced, the amount of memory available on embedded devices is pretty limited. Having a way to save bits or our precious memory is interesting.

BitReader is an arduino library that allows one to read or write data as chunks of bits.
Skip to the [download section](#Download) for quick download.

# Purpose

This BitReader library allows one to read data which is not necessarily aligned on 8, 16 or 32 bits structures.

{{< pleasenote >}}
  Note that since you are encoding data in binary format (bits), the trade-off is that more code is required to process/decode the data and there is a small performance delay required for decoding the data
{{< /pleasenote >}}


The library is useful for storing or decoding data in binary format using the minimum amount of bits. For examples...

* [Shorter text strings](#Making_text_strings_shorter)
* [Shorter structures](#Shorter_structuresdefinition)
* [Shorter data arrays](#Make_data_arrays_much_shorter)

# Library features

Possible use are:

* Reduces size of data (strings, structures, arrays) in memory to the minimum amount of bits required.
* Help reading/updating bit-field structures.
* Handles bit [serialization ](https://en.wikipedia.org/wiki/Serialization)data to/from buffers.

# Usage

Create an instance of _BitReader_, _BitWriter_ or _BitAddress_ depending on the following optimization switches:

* USE_BITADDRESS_SETTER_GETTER
* USE_SINGLEBIT_MACROS
* USE_BITADDRESS_READ_WRITE

Then assign a reading or writing buffer using the _setBuffer()_ method.

Then call the _write()_ method for writing bits to the assigned buffer or call the _read()_ method for reading bits from the assigned buffer. Each method allows one to specify the amount of bits to read or write.

## Making text strings shorter

Storing words composed of only lower case letters, spaces and dots requires only 5 bits per characters instead of 8 bits (which saves 3 bits per character). The phase "_hello my name is antoine. i wrote the bitreader library._" takes 56 bytes as an array of char but uses 35 bytes as 5 bits chunks.

Allow 6 bits per characters and you can also include capital letters and numbers: "_Hello my name is Antoine. I wrote the BitReader library when I was 34 years old._" takes 80 bytes as an array of char but only requires 60 bytes as 6 bits chunks.

## Shorter structures definition

The library is particularly useful for dealing with [bit-field structures](http://en.cppreference.com/w/cpp/language/bit_field). Consider the following:


```cpp
struct Person {
  char name[10];
  char birthDay;
  char birthMonth;
  short birthYear;
  bool maried;
  char children;
};
```


The _Person_ structure requires 16 bytes in memory (10+1+1+2+1+1) or 128 bits. However, using bit-field structure, the _Person_ structure can be defined as the following:


```cpp
struct Person2 {
 uint8_t name[10]; //keep 8 bits per letters for compatibility.
 union
 {
   struct //aligned on 8 bits
   {
     uint8_t birthDay : 5; //from 1 to 31
     uint8_t children : 3; //from 0 to 7. 
     uint8_t birthMonth : 4; //from 1 to 12
     uint8_t maried : 1; //true or false
     //uint8_t : 3; //birthYear (low)
     //uint8_t : 8; //birthYear (high)
   };
   struct //aligned on 32 bits
   {
     uint32_t padding1 :13; //padding for birthDay, children, birthMonth, maried
     uint32_t birthYear :12; //allows years from 0 to 4095.
     //uint16_t : 4; //unused
   };
 };
};
```


The _Person2_ structure contains the same information as the _Person_ structure but instead of using 128 bits in memory it only requires 105 bits (80+5+3+4+1+12).

A _Person_ could also be defined with masks:


```cpp
struct Person3 {
  uint8_t name[10];
  uint32_t buffer;
};
static const uint32_t MASK_BIRTHDAY = (1&lt;&lt;4 | 1&lt;&lt;3 | 1&lt;&lt;2 | 1&lt;&lt;1 | 1&lt;&lt;0);
static const uint32_t MASK_CHILDREN = (1&lt;&lt;7 | 1&lt;&lt;6 | 1&lt;&lt;5);
static const uint32_t MASK_BIRTHMONTH = (1&lt;&lt;11 | 1&lt;&lt;10 | 1&lt;&lt;9 | 1&lt;&lt;8);
static const uint32_t MASK_MARIED = (1&lt;&lt;12);
static const uint32_t MASK_BIRTHYEAR =  (1&lt;&lt;24 | 1&lt;&lt;23 | 1&lt;&lt;22 | 1&lt;&lt;21 | 1&lt;&lt;20 | 1&lt;&lt;19 | 1&lt;&lt;18 | 1&lt;&lt;17 | 1&lt;&lt;16 | 1&lt;&lt;15 | 1&lt;&lt;14 | 1&lt;&lt;13);
static const uint32_t MASK_PADDING = (1&lt;&lt;31 | 1&lt;&lt;30 | 1&lt;&lt;29 | 1&lt;&lt;28 | 1&lt;&lt;27 | 1&lt;&lt;26 | 1&lt;&lt;25);
```


In the last 2 scenarios (_Person2_ and _Person3_), the BitReader library allows one to decode a _Person_ structure from a binary buffer.

## Make data arrays much shorter

Consider an algorithm that plays a [Morse code](https://en.wikipedia.org/wiki/Morse_code). Morse code defines 3 symbols that can be played: dots, dashes and pauses.

For example, the following string "_Hello my name is Antoine. I wrote the BitReader library when I was 34 years old._" (56 bytes) translate into Morse code as


```
.... . .-.. .-.. --- / -- -.-- / -. .- -- . / .. ... / .- -. 
- --- .. -. . .-.-.- / .. / .-- .-. --- - . / - .... . / -... 
.. - .-. . .- -.. . .-. / .-.. .. -... .-. .- .-. -.-- / .-- 
.... . -. / .. / .-- .- ... / ...-- ....- / -.-- . .- .-. 
... / --- .-.. -.. .-.-.-
```


according to [this translator](http://morsecode.scphillips.com/translator.html). The whole code takes 267 bytes in memory. However, using 2 bits per code, the whole string can be encoded in a char buffer with only 534 bits (~67 bytes).

The same concept applies to all numeric array.

## Demo

The following demo show how to use the library:  
(download the 
	[ BitReader v1.0.70 benchmark demo.ino (596 downloads) ](http://www.end2endzone.com/download/1691/ "Version 1.0.70"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/03/BitReader-v1.0.70-benchmark-demo.ino" lang="" >}}

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the BitReader arduino library by clicking on the following link:


		[ Download "BitReader v1.1.110 arduino library" BitReader-v1.1.110.zip - Downloaded 404 times - 10 KB ](http://www.end2endzone.com/download/1688/)
