---
title: AnyRtttl – A feature rich arduino library for playing RTTTL melodies
author: end2end
type: post
date: 2016-05-21T23:20:34+00:00
url: /anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/
featured_image: /wp-content/uploads/2016/05/AnyRtttl-arduino-library-672x378.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Library:</p>
        <ul class="fa-ul">
        <li><a href="/download/1988/"><i class="fa-li fa fa-download" style="position: inherit;"></i>AnyRtttl arduino library</a></li>
        </ul>
        </div>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Examples:</p>
        <ul class="fa-ul">
        <li><a href="/download/1977/"><i class="fa-li fa fa-download" style="position: inherit;"></i>AnyRtttl Non-Blocking.ino</a></li>
        <li><a href="/download/1981/"><i class="fa-li fa fa-download" style="position: inherit;"></i>AnyRtttl Play (16 bits).ino</a></li>
        <li><a href="/download/1979/"><i class="fa-li fa fa-download" style="position: inherit;"></i>AnyRtttl Play (10 bits).ino</a></li>
        <li><a href="/download/1983/"><i class="fa-li fa fa-download" style="position: inherit;"></i>AnyRtttl RTTTL 2 code.ino</a></li>
        </ul>
        </div>
        
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
# <span id="Introduction">Introduction</span>

The following article is about yet another Arduino library that I have written. AnyRtttl is a feature rich arduino library for playing RTTTL melodies. The library offers much more interesting features than relying on the widely available <code class="prettycode">void play_rtttl(char *p)</code> function. The AnyRtttl is a feature rich library which supports all best RTTTL features.<!--more-->

Skip to the [download section][1] for quick download.

# <span id="Purpose">Purpose</span>

See this post for a [quick recall of the RTTTL format][2].

<p class="pleasenote" data-pleasenote="true">
  Note that AnyRtttl library is a port from my <a href="/nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/">NonBlockingRtttl arduino library</a> which is now deprecated since development has stopped.
</p>

After publishing my NonBlockingRtttl arduino library, I started using the library in more complex projects which was requiring other libraries. I quickly ran into the hell of library dependencies and library conflicts. I realized that I needed more features that could help me prototype faster.

Other libraries available which allows you to &#8220;play&#8221; a melody in [RTTTL f][3]ormat suffer the same issue: they are based on blocking APIs or the RTTTL data is not optimized for space.

AnyRtttl is different since it packs multiple RTTTL related features in a single library. It supports [blocking][4] & [non-blocking][5] API which makes it suitable to be used by more advanced algorithm. For instance, when using the non-blocking API, the melody can be stopped when a button is pressed. The library is also compatible with _external Tone libraries_ and it supports highly compressed RTTTL binary formats.

# <span id="Library_features">Library features</span>

Here is a list of all library features:

<li style="text-align: justify;">
  Really small increase in memory & code footprint compared to the usual blocking algorithm.
</li>
<li style="text-align: justify;">
  Blocking & Non-Blocking modes available.
</li>
<li style="text-align: justify;">
  Support custom <code class="prettycode">tone()</code>, <code class="prettycode">noTone()</code>, <code class="prettycode">delay()</code> and <code class="prettycode">millis()</code> functions.
</li>
<li style="text-align: justify;">
  Compatible with external Tone libraries.
</li>
<li style="text-align: justify;">
  Supports highly compressed RTTTL binary format.
</li>
<li style="text-align: justify;">
  Supports RTTTL melodies stored in <em>Program Memory</em> (<code class="prettycode">PROGMEM</code>).
</li>
<li style="text-align: justify;">
  Play two monolithic melodies on two different pins using 2 <a href="https://www.google.com/?q=piezo+buzzer">piezo buzzer</a> with the help of an external Tone library.
</li>

## <span id="Non-Blocking">Non-Blocking</span>

Most of the code that can &#8220;play&#8221; a melody on internet are all build the same way: sequential calls to <code class="prettycode">tone()</code> and <code class="prettycode">delay()</code> functions using hardcoded values. This type of implementation might be good for robots but not for realtime application or projects that needs to monitor pins while the song is playing.

With AnyRtttl non-blocking mode, your program can read/write IOs pins while playing and react on changes. Implementing a &#8220;stop&#8221; or &#8220;next song&#8221; push button is a breeze!

## <span id="ExternalTone_or_Timer_0_libraries">External Tone or Timer #0 libraries</span>

The AnyRtttl library is also flexible by allowing you to use the build-in arduino <code class="prettycode">tone()</code> and <code class="prettycode">noTone()</code> functions or an implementation from any external library which makes it compatible with any _Tone library_ in the market.

The library also supports custom <code class="prettycode">delay()</code> and <code class="prettycode">millis()</code> functions. If a projects requires modification to the microcontroller’s build-in Timer #0, the <code class="prettycode">millis()</code> function may be impacted and behave incorrectly. To maximize compatibility, one can supply a custom function which behaves like the original to prevent altering playback.

## <span id="Binary_RTTTL">Binary RTTTL</span>

The AnyRtttl library also supports playing RTTTL data which is stored as binary data instead of text. This is actually a custom implementation of the RTTTL format. Using these format, one can achieve storing an highly compressed RTTTL melody which saves memory.

See the [Binary RTTTL format definition][6] section for details.

# <span id="Usage">Usage</span>

Define ANY\_RTTTL\_INFO to enable the debugging of the library state on the serial port.

Use ANY\_RTTTL\_VERSION to get the current version of the library.

## <span id="Non-blocking_mode">Non-blocking mode</span>

Call <code class="prettycode">anyrtttl::begin()</code> to setup the AnyRtttl library in non-blocking mode. Then call <code class="prettycode">anyrtttl::play()</code> to update the library&#8217;s state and play notes as required.

Use <code class="prettycode">anyrtttl::done()</code> or <code class="prettycode">anyrtttl::isPlaying()</code> to know if the library is done playing the given song.

Anytime one can call <code class="prettycode">anyrtttl::stop()</code> to stop playing the current song.

<span style="text-decoration: underline;"><span style="font-size: 16pt;">Demo</span></span>

The following demo show how to use the library in non-blocking mode:  
(download 
	<a class="download-link" title="Version 2.0" href="http://www.end2endzone.com/download/1977/" rel="nofollow"> AnyRtttl v2.0 Non-Blocking example (751 downloads) </a>)

<pre class="lang:c++ decode:true" title="AnyRtttl v2.0 Non-Blocking example" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/AnyRtttl-v2.0-NonBlocking-example.ino">sample</pre>

## <span id="Play_16_bits_per_note_RTTTL">Play 16 bits per note RTTTL</span>

Note that this mode requires that an RTTTL melody be already converted to 16-bits per note binary format.

Use the <code class="prettycode">anyrtttl::blocking::play16Bits()</code> API for playing an RTTTL melody encoded as 16 bits per note.

<span style="text-decoration: underline;"><span style="font-size: 16pt;">Demo</span></span>

The following demo show how to use the library with 16-bits per note binary RTTTL:  
(download 
	<a class="download-link" title="Version 2.0" href="http://www.end2endzone.com/download/1981/" rel="nofollow"> AnyRtttl v2.0 Play 16 bits example (704 downloads) </a>)

<pre class="lang:c++ decode:true" title="AnyRtttl v2.0 Play 16 bits example" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/AnyRtttl-v2.0-Play-16-bits-example.ino">sample</pre>

## <span id="Play_10bits_per_note_RTTTL">Play 10 bits per note RTTTL</span>

Note that this mode requires that an RTTTL melody be already converted to 10-bits per note binary format.

Create a function that will be used by AnyRtttl library to read bits as required. The signature of the library must look like this:  
<code class="prettycode">uint16_t function_name(uint8_t numBits)</code>.

Note that this demo uses the [arduino BitReader library][7] to extract bits from the RTTTL binary buffer. The implementation of <code class="prettycode">readNextBits()</code> function delegates the job to the BitReader&#8217;s <code class="prettycode">read()</code> method.

In the <code class="prettycode">setup()</code> function, setup the external library that is used for reading bits: <code class="prettycode">bitreader.setBuffer(tetris10);</code>

Use the <code class="prettycode">anyrtttl::blocking::play10Bits()</code> API for playing an RTTTL melody encoded as 10 bits per note. The 3rd argument of the function requires a pointer to the function extracting bits: <code class="prettycode">&function_name</code>.

<span style="text-decoration: underline;"><span style="font-size: 16pt;">Demo</span></span>

The following demo show how to use the library with 10-bits per note binary RTTTL:  
(download 
	<a class="download-link" title="Version 2.0" href="http://www.end2endzone.com/download/1979/" rel="nofollow"> AnyRtttl v2.0 Play 10 bits example (658 downloads) </a>)

<pre class="lang:c++ decode:true" title="AnyRtttl v2.0 Play 10 bits example" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/AnyRtttl-v2.0-Play-10-bits-example.ino">sample</pre>

## <span id="Custom_Tone_functionaka_RTTTL_2_code">Custom Tone function (a.k.a. RTTTL 2 code)</span>

This demo shows how custom functions can be used by the AnyRtttl library. This example shows how to convert an RTTTL melody to arduino code.

First define replacement functions like the following:

<pre class="lang:c++ decode:true" title="Tone replacement functions">void serialTone(byte pin, uint16_t frequency, uint32_t duration) {
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
}</pre>

Each new functions prints the function call & arguments to the serial port.

In the <code class="prettycode">setup()</code> function, setup the AnyRtttl library to use the new functions:

<pre class="lang:c++ decode:true " title="Setup AnyRtttl with custom functions">//Use custom functions
anyrtttl::setToneFunction(&serialTone);
anyrtttl::setNoToneFunction(&serialNoTone);
anyrtttl::setDelayFunction(&serialDelay);</pre>

Use the <code class="prettycode">anyrtttl::blocking::play()</code> API for &#8220;playing&#8221; an RTTTL melody and monitor the output of the serial port to see the actual arduino code generated by the library.

<span style="text-decoration: underline;"><span style="font-size: 16pt;">Demo</span></span>

The following demo show how to use the library with custom functions:  
(download 
	<a class="download-link" title="Version 2.0" href="http://www.end2endzone.com/download/1983/" rel="nofollow"> AnyRtttl v2.0 RTTTL 2 code example (657 downloads) </a>)

<pre class="lang:c++ decode:true" title="AnyRtttl v2.0 RTTTL 2 code example" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/AnyRtttl-v2.0-Rtttl-2-Code-example.ino">sample</pre>

# <span id="Binary_RTTTL_format_definition">Binary RTTTL format definition<span style="font-size: 18pt;"><br /> </span></span>

The following section defines the field order and size (in bits) required for encoding / decoding of each melody as binary RTTTL.

<p class="pleasenote" data-pleasenote="true">
  Note that all fields definition are defined in LSB to MSB order.
</p>

The first 16 bits stores the RTTTL default section which is defined as the following:

<li style="text-align: justify;">
  <span style="text-decoration: underline;"><strong>Default duration index</strong></span>, 3 bits, with values within [0, 7] range, matches the index used for <code class="prettycode">getNoteDurationFromIndex()</code> API.
</li>
<li style="text-align: justify;">
  <span style="text-decoration: underline;"><strong>Default octave index</strong></span>, 2 bits, with values within [0, 3] range, matches the index used for <code class="prettycode">getNoteOctaveFromIndex()</code> API.
</li>
<li style="text-align: justify;">
  <span style="text-decoration: underline;"><strong>Beats per minutes (BPM)</strong></span>, 10 bits, with values within [1, 900].
</li>
<li style="text-align: justify;">
  <span style="text-decoration: underline;"><strong>Padding</strong></span>, 1 bit
</li>

Next is each note&#8217;s of the melody. Each note is encoded as 10 bits (or 16 bits) per note and is defined as the following:

  1. <span style="text-decoration: underline;"><strong>Duration index</strong></span>, 3 bits, with values within [0, 7] range,  matches the index used for <code class="prettycode">getNoteDurationFromIndex()</code> API.
  2. <span style="text-decoration: underline;"><strong>Note letter index</strong></span>, 3 bits, with values within [0, 7] range, matches the index used for <code class="prettycode">getNoteLetterFromIndex()</code> API.
  3. <span style="text-decoration: underline;"><strong>Pound</strong></span>, 1 bit, defines if the note is pounded or not.
  4. <span style="text-decoration: underline;"><strong>Dotted</strong></span>, 1 bit, defines if the note is dotted or not.
  5. <span style="text-decoration: underline;"><strong>Octave index</strong></span>, 2 bits, with values within [0, 3] range, matches the index used for <code class="prettycode">getNoteOctaveFromIndex()</code> API.
  6. <span style="text-decoration: underline;"><strong>Padding</strong></span>, 6 bits, **optional**. See sections below.

<p class="pleasenote" data-pleasenote="true">
  The last field of a note (defined as <em>Padding</em>) is an <strong>optional 6 bits</strong> field. The AnyRtttl library supports both 10 bits per note and 16 bits per note definitions. Use the appropriate API for playing both format.
</p>

## <span id="10_bits_per_note_no_padding">10 bits per note (no padding)</span>

Each RTTTL note is encoded into 10 bits which is the minimum size of a note. This storage method is the best compression method for storing RTTTL melodies and reduces the usage of the <span class="texthighlight1">dynamic memory</span> to the minimum.

However, since all notes are not aligned on multiple of 8 bits, addressing each note by an offset is impossible which makes the playback harder. Each notes must be [deserialized][8] one after the other. An additional library is required for deserializing a note from a buffer using blocks of 10 bits which may increase the <span class="texthighlight1">program storage space</span> footprint.

An external arduino library must also be used to allow the AnyRtttl library to consume bits as needed. The [arduino BitReader library][7] may be used for handling bit deserialization but any library that can extract a given number of bits from a buffer would work.

## <span id="16_bits_per_note_with_padding">16 bits per note (with padding)</span>

Each RTTTL note is encoded into 16 bits which is much better than the average 3.28 bytes per note text format. This storage method is optimum for storing RTTTL melodies and reduces the usage of the <span class="texthighlight1">dynamic memory</span> without increasing to much <span class="texthighlight1">program storage space</span>.

All notes are aligned on 16 bits. Addressing each note by an offset allows an easy playback. Only the first 10 bits of each 16 bits block is used. The value of the padding field is undefined.

## <span id="Playback">Playback</span>

The following AnyRtttl blocking APIs are available for playing both format:

<li style="text-align: justify;">
  10 bits per note: <code class="prettycode">play10Bits()</code>.
</li>
<li style="text-align: justify;">
  16 bits per note: <code class="prettycode">play16Bits()</code>.
</li>

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the AnyRtttl library by clicking on the following link:


		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/1988/" rel="nofollow"> Download &ldquo;AnyRtttl v2.1.229 arduino library&rdquo; <small>AnyRtttl-v2.1.229.zip &ndash; Downloaded 571 times &ndash; 54 KB</small> </a>

 [1]: #Download
 [2]: /nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/#Quick_recall_of_the_RTTTL_format
 [3]: #Quick_recall_of_the_RTTTL_format
 [4]: https://en.wikipedia.org/wiki/Blocking_(computing)
 [5]: http://en.wikipedia.org/wiki/Non-blocking_algorithm
 [6]: #Binary_RTTTL_format_definition
 [7]: /bitreader-an-arduino-library-for-reading-writing-data-as-chunks-of-bits/
 [8]: http://en.wikipedia.org/wiki/Serialization