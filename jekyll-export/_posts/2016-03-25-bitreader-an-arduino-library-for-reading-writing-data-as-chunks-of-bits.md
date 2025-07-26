---
id: 1682
title: 'BitReader &#8211; An arduino library for reading &#038; writing data as chunks of bits'
date: '2016-03-25T20:23:05+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1682'
permalink: '/?p=1682'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Library:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1688/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>BitReader arduino library</a></li>\n</ul>\n</div>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Example:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1691/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>Benchmark demo sample</a></li>\n</ul>\n</div>\n"
hits:
    - '228'
image: /wp-content/uploads/2016/03/Arduino-BitReader-library.jpg
categories:
    - Development
tags:
    - arduino
    - 'arduino library'
    - english
    - 'open source'
---

# Introduction

Here is another arduino library that I have written. As a desktop developer, I am not used to have memory (or even CPU) requirements as most developers will not look at memory consumption as an arduino developer would. Memory &amp; CPU is cheap. If your application is struggling to run on today's computer, it will run smoothly in 1-2 years. As most arduino developers have faced, the amount of memory available on embedded devices is pretty limited. Having a way to save bits or our precious memory is interesting. BitReader is an arduino library that allows one to read or write data as chunks of bits. Skip to the [download section](#Download) for quick download. # Purpose

This BitReader library allows one to read data which is not necessarily aligned on 8, 16 or 32 bits structures. Note that since you are encoding data in binary format (bits), the trade-off is that more code is required to process/decode the data and there is a small performance delay required for decoding the data

The library is useful for storing or decoding data in binary format using the minimum amount of bits. For examples... - [Shorter text strings](#Making_text_strings_shorter)
- [Shorter structures](#Shorter_structuresdefinition)
- [Shorter data arrays](#Make_data_arrays_much_shorter)

# Library features

Possible use are: - Reduces size of data (strings, structures, arrays) in memory to the minimum amount of bits required.
- Help reading/updating bit-field structures.
- Handles bit [serialization ](https://en.wikipedia.org/wiki/Serialization)data to/from buffers.

# Usage

<span style="line-height: 1.5;">Create an instance of *BitReader*, *BitWriter* or *BitAddress* depending on the following optimization switches:</span>- USE\_BITADDRESS\_SETTER\_GETTER
- USE\_SINGLEBIT\_MACROS
- USE\_BITADDRESS\_READ\_WRITE

<span style="line-height: 1.5;">Then assign a reading or writing buffer using the *setBuffer()* method.</span><span style="line-height: 1.5;">Then call the *write()* method for writing bits to the assigned buffer or call the *read()* method for reading bits from the assigned buffer. Each method allows one to specify the amount of bits to read or write.</span>## Making text strings shorter

Storing words composed of only lower case letters, spaces and dots requires only 5 bits per characters instead of 8 bits (which saves 3 bits per character). The phase "*hello my name is antoine. i wrote the bitreader library.*" takes 56 bytes as an array of char but uses 35 bytes as 5 bits chunks. Allow 6 bits per characters and you can also include capital letters and numbers: "*Hello my name is Antoine. I wrote the BitReader library when I was 34 years old.*" takes 80 bytes as an array of char but only requires 60 bytes as 6 bits chunks. ## Shorter structures definition

The library is particularly useful for dealing with [bit-field structures](http://en.cppreference.com/w/cpp/language/bit_field). Consider the following: ```
struct Person {
  char name[10];
  char birthDay;
  char birthMonth;
  short birthYear;
  bool maried;
  char children;
};
```

The *Person* structure requires 16 bytes in memory (10+1+1+2+1+1) or 128 bits. However, using bit-field structure, the *Person* structure can be defined as the following: ```
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
     //uint8_t : 8; //birthYear (high)
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

The *Person2* structure contains the same information as the *Person* structure but instead of using 128 bits in memory it only requires 105 bits (80+5+3+4+1+12). A *Person* could also be defined with masks: ```
struct Person3 {
  uint8_t name[10];
  uint32_t buffer;
};
static const uint32_t MASK_BIRTHDAY = (1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
static const uint32_t MASK_CHILDREN = (1<<7 | 1<<6 | 1<<5);
static const uint32_t MASK_BIRTHMONTH = (1<<11 | 1<<10 | 1<<9 | 1<<8);
static const uint32_t MASK_MARIED = (1<<12);
static const uint32_t MASK_BIRTHYEAR =  (1<<24 | 1<<23 | 1<<22 | 1<<21 | 1<<20 | 1<<19 | 1<<18 | 1<<17 | 1<<16 | 1<<15 | 1<<14 | 1<<13);
static const uint32_t MASK_PADDING = (1<<31 | 1<<30 | 1<<29 | 1<<28 | 1<<27 | 1<<26 | 1<<25);
```

In the last 2 scenarios (*Person2* and *Person3*), the BitReader library allows one to decode a *Person* structure from a binary buffer. ## Make data arrays much shorter

Consider an algorithm that plays a [Morse code](https://en.wikipedia.org/wiki/Morse_code). Morse code defines 3 symbols that can be played: dots, dashes and pauses. For example, the following string "*Hello my name is Antoine. I wrote the BitReader library when I was 34 years old.*" (56 bytes) translate into Morse code as ```
.... . .-.. .-.. --- / -- -.-- / -. .- -- . / .. ... / .- -. 
- --- .. -. . .-.-.- / .. / .-- .-. --- - . / - .... . / -... 
.. - .-. . .- -.. . .-. / .-.. .. -... .-. .- .-. -.-- / .-- 
.... . -. / .. / .-- .- ... / ...-- ....- / -.-- . .- .-. 
... / --- .-.. -.. .-.-.-
```

according to [this translator](http://morsecode.scphillips.com/translator.html). The whole code takes 267 bytes in memory. However, using 2 bits per code, the whole string can be encoded in a char buffer with only 534 bits (~67 bytes). The same concept applies to all numeric array. ## Demo

The following demo show how to use the library: (download the \[download id="1691"\]) ```
sample
```

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA **DISCLAIMER:**This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose. # Download

You can download the BitReader arduino library by clicking on the following link: \[download id="1688" template="button"\]