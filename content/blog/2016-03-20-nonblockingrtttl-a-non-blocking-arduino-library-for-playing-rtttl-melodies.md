---
title: NonBlockingRTTTL – A non-blocking arduino library for playing RTTTL melodies
author: end2end
date: 2016-03-20T15:16:54+00:00
url: /nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/
images:
  - src: /wp-content/uploads/2016/03/Arduino-non-blocking-rtttl-library.jpg
hits:
  - 1262
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Library:
        * [NonBlockingRtttl arduino library](http://github.com/end2endzone/NonBlockingRTTTL/releases)
        Example:
        * [NonBlockingRtttl demo sample](/download/1676/)
        
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

The following article is about my first Arduino library that I have written. NonBlockingRTTTL is a non-blocking arduino library for playing RTTTL data.
{{< postedit >}}
  **EDIT**: The NonBlockingRtttl arduino library is now moved to GitHub. Source code can be downloaded from the project’s [GitHub page](http://github.com/end2endzone/NonBlockingRTTTL).
{{< /postedit >}}


{{< postedit >}}
  EDIT: NonBlockingRTTTL library is now available on the [Arduino Library Manager](http://www.arduino.cc/en/guide/libraries#toc3).
{{< /postedit >}}


Skip to the [download section](#Download) for quick download.

# Purpose

Most code that can be found on the internet that allows you to "play" an [RTTTL](#Quick_recall_of_the_RTTTL_format) string is build the same way: sequential calls to the tone() function followed by a delay() function. This type of implementation might be good for robots but not for realtime application or projects that needs to monitor pins while the song is playing.

This library is [non-blocking](http://en.wikipedia.org/wiki/Non-blocking_algorithm)&nbsp;which make it suitable to be used by more advanced algorithm. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library](http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rogue-code/Arduino-Library-Tone.zip).

# Quick recall of the RTTTL format

I recently discovered the Ring Tone Text Transfer Language (RTTTL) audio format which is an audio format for storing single tone (monolithic)  melodies. Each melody is composed of successive tone frequencies.

The RTTTL format is [human readable](http://stackoverflow.com/questions/568671/why-should-i-use-a-human-readable-file-format) and usually more compressed than note &&nbsp;duration arrays which helps reduce its memory footprint.

In the arduino world, melodies are usually written as an array of notes (frequencies) followed by the note's duration (note1, duration1, note2, duration2, ... ,  noteX, durationX).

The format is really suitable for embedded device that are limited in memory which can't store PCM (wav) or even MP3 data.

{{< pleasenote >}}
  Note that RTTTL can also be spelled RTTL (Ringtone Text Transfer Language). According to my Samsung phone, a ringtone can also be spelled as a single word...
{{< /pleasenote >}}


More information on the RTTTL format is available on its [Wikipedia acticle](https://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language).

# Library features

Possible use are:

* Really small increase in memory & code footprint compared to the usual blocking algorithm.
* Allows your program to read/write IOs pins while playing. Implementing a "stop" or "next song" push buttons is a breeze!

# Usage

Call _rtttl::begin()_ to setup the non-blocking RTTTL library. Then call _rtttl::play()_ to update the library's state and play notes as required.

Use _rtttl::done()_ or _rtttl::isPlaying()_ to know if the library is done playing the given song. Anytime playing, one can call _rtttl::stop()_ to stop playing the current song.

Define _RTTTL\_NONBLOCKING\_INFO_ to enable the debugging of the library state on the serial port. Use _NONBLOCKINGRTTTL_VERSION_ to read the current version of the library.

## Demo

The following demo show how to use the library:  
(download the 
	[ NonBlockingRtttl demo sample (738 downloads) ](http://www.end2endzone.com/download/1676/ "Version 1.0.101"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/03/NonBlockingRtttl-demo-v1.0.101.ino" lang="cpp" >}}

# License

The following code was written by Antoine Beauchamp. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library](http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rogue-code/Arduino-Library-Tone.zip)&nbsp;which is licensed with the [MIT License](http://www.opensource.org/licenses/mit-license.php).

The code & updates for the library can be found at <http://end2endzone.com>.

For the original source code for the RTTTL player see: <http://code.google.com/archive/p/rogue-code/wikis/ToneLibraryDocumentation.wiki>.

# Download

{{< pleasenote >}}
  Please note that download links are now deprecated. Binary version of NonBlockingRtttl library can be downloaded from the project’s [Release page](https://github.com/end2endzone/NonBlockingRTTTL/releases).
{{< /pleasenote >}}


{{< postedit >}}
  EDIT: NonBlockingRTTTL library can now be installed from the [Arduino Library Manager](http://www.arduino.cc/en/guide/libraries#toc3).
{{< /postedit >}}

