---
id: 1392
title: 'NonBlockingRTTTL &#8211; A non-blocking arduino library for playing RTTTL melodies'
date: '2016-03-20T11:16:54+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1392'
permalink: '/?p=1392'
hits:
    - '1553'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Library:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"http://github.com/end2endzone/NonBlockingRTTTL/releases\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>NonBlockingRtttl arduino library</a></li>\n</ul>\n</div>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Example:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1676/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>NonBlockingRtttl demo sample</a></li>\n</ul>\n</div>\n"
image: /wp-content/uploads/2016/03/Arduino-non-blocking-rtttl-library.jpg
categories:
    - Development
tags:
    - arduino
    - 'arduino library'
    - english
    - 'open source'
    - rtttl
---

# Introduction

The following article is about my first Arduino library that I have written. NonBlockingRTTTL is a non-blocking arduino library for playing RTTTL data. <span style="text-decoration: underline;">**EDIT**</span>: The NonBlockingRtttl arduino library is now moved to GitHub. Source code can be downloaded from the project’s [GitHub page](http://github.com/end2endzone/NonBlockingRTTTL).

EDIT: NonBlockingRTTTL library is now available on the [Arduino Library Manager](http://www.arduino.cc/en/guide/libraries#toc3).

Skip to the [download section](#Download) for quick download. # Purpose

Most code that can be found on the internet that allows you to "play" an [RTTTL ](#Quick_recall_of_the_RTTTL_format)string is build the same way: sequential calls to the tone() function followed by a delay() function. This type of implementation might be good for robots but not for realtime application or projects that needs to monitor pins while the song is playing. This library is [non-blocking](http://en.wikipedia.org/wiki/Non-blocking_algorithm) which make it suitable to be used by more advanced algorithm. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library](http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rogue-code/Arduino-Library-Tone.zip). # Quick recall of the RTTTL format

I recently discovered the Ring Tone Text Transfer Language (RTTTL) audio format which is an audio format for storing single tone (monolithic) melodies. Each melody is composed of successive tone frequencies. The RTTTL format is [human readable](http://stackoverflow.com/questions/568671/why-should-i-use-a-human-readable-file-format) and usually more compressed than note &amp; duration arrays which helps reduce its memory footprint. In the arduino world, melodies are usually written as an array of notes (frequencies) followed by the note's duration (note1, duration1, note2, duration2, ... , noteX, durationX). The format is really suitable for embedded device that are limited in memory which can't store PCM (wav) or even MP3 data. Note that RTTTL can also be spelled RTTL (Ringtone Text Transfer Language). According to my Samsung phone, a ringtone can also be spelled as a single word...

More information on the RTTTL format is available on its [Wikipedia acticle](https://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language). # Library features

Possible use are: - Really small increase in memory &amp; code footprint compared to the usual blocking algorithm.
- Allows your program to read/write IOs pins while playing. Implementing a "stop" or "next song" push buttons is a breeze!

# Usage

Call *rtttl::begin()* to setup the non-blocking RTTTL library. Then call *rtttl::play()* to update the library's state and play notes as required. Use *rtttl::done()* or *rtttl::isPlaying()* to know if the library is done playing the given song. Anytime playing, one can call *rtttl::stop()* to stop playing the current song. Define *RTTTL\_NONBLOCKING\_INFO* to enable the debugging of the library state on the serial port. Use *NONBLOCKINGRTTTL\_VERSION* to read the current version of the library. ## Demo

The following demo show how to use the library: (download the \[download id="1676"\]) ```
sample
```

# License

The following code was written by Antoine Beauchamp. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library](http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rogue-code/Arduino-Library-Tone.zip) which is licensed with the [MIT License](http://www.opensource.org/licenses/mit-license.php). The code &amp; updates for the library can be found at <http://end2endzone.com>. For the original source code for the RTTTL player see: <http://code.google.com/archive/p/rogue-code/wikis/ToneLibraryDocumentation.wiki>. # Download

Please note that download links are now deprecated. Binary version of NonBlockingRtttl library can be downloaded from the project’s [Release page](https://github.com/end2endzone/NonBlockingRTTTL/releases).

EDIT: NonBlockingRTTTL library can now be installed from the [Arduino Library Manager](http://www.arduino.cc/en/guide/libraries#toc3).