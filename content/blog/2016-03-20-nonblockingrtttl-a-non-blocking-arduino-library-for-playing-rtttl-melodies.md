---
title: NonBlockingRTTTL – A non-blocking arduino library for playing RTTTL melodies
author: end2end
type: post
date: 2016-03-20T15:16:54+00:00
url: /nonblockingrtttl-a-non-blocking-arduino-library-for-playing-rtttl-melodies/
featured_image: /wp-content/uploads/2016/03/Arduino-non-blocking-rtttl-library.jpg
hits:
  - 1262
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Library:</p>
        <ul class="fa-ul">
        <li><a href="http://github.com/end2endzone/NonBlockingRTTTL/releases"><i class="fa-li fa fa-download" style="position: inherit;"></i>NonBlockingRtttl arduino library</a></li>
        </ul>
        </div>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Example:</p>
        <ul class="fa-ul">
        <li><a href="/download/1676/"><i class="fa-li fa fa-download" style="position: inherit;"></i>NonBlockingRtttl demo sample</a></li>
        </ul>
        </div>
        
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

The following article is about my first Arduino library that I have written. NonBlockingRTTTL is a non-blocking arduino library for playing RTTTL data.<!--more-->

<p class="postedit">
  <span style="text-decoration: underline;"><strong>EDIT</strong></span>: The NonBlockingRtttl arduino library is now moved to GitHub. Source code can be downloaded from the project’s <a href="http://github.com/end2endzone/NonBlockingRTTTL">GitHub page</a>.
</p>

<p class="postedit">
  EDIT: NonBlockingRTTTL library is now available on the <a href="http://www.arduino.cc/en/guide/libraries#toc3">Arduino Library Manager</a>.
</p>

Skip to the [download section][1] for quick download.

# <span id="Purpose">Purpose</span>

Most code that can be found on the internet that allows you to &#8220;play&#8221; an [RTTTL][2] string is build the same way: sequential calls to the tone() function followed by a delay() function. This type of implementation might be good for robots but not for realtime application or projects that needs to monitor pins while the song is playing.

This library is [non-blocking][3] which make it suitable to be used by more advanced algorithm. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library][4].

# <span id="Quick_recall_of_the_RTTTL_format">Quick recall of the RTTTL format</span>

I recently discovered the Ring Tone Text Transfer Language (RTTTL) audio format which is an audio format for storing single tone (monolithic)  melodies. Each melody is composed of successive tone frequencies.

The RTTTL format is [human readable][5] and usually more compressed than note & duration arrays which helps reduce its memory footprint.

In the arduino world, melodies are usually written as an array of notes (frequencies) followed by the note&#8217;s duration (note1, duration1, note2, duration2, &#8230; ,  noteX, durationX).

The format is really suitable for embedded device that are limited in memory which can&#8217;t store PCM (wav) or even MP3 data.

<p class="pleasenote" data-pleasenote="true">
  Note that RTTTL can also be spelled RTTL (Ringtone Text Transfer Language). According to my Samsung phone, a ringtone can also be spelled as a single word&#8230;
</p>

More information on the RTTTL format is available on its [Wikipedia acticle][6].

# <span id="Library_features">Library features</span>

Possible use are:

<li style="text-align: justify;">
  Really small increase in memory & code footprint compared to the usual blocking algorithm.
</li>
<li style="text-align: justify;">
  Allows your program to read/write IOs pins while playing. Implementing a &#8220;stop&#8221; or &#8220;next song&#8221; push buttons is a breeze!
</li>

# <span id="Usage">Usage</span>

Call _rtttl::begin()_ to setup the non-blocking RTTTL library. Then call _rtttl::play()_ to update the library&#8217;s state and play notes as required.

Use _rtttl::done()_ or _rtttl::isPlaying()_ to know if the library is done playing the given song. Anytime playing, one can call _rtttl::stop()_ to stop playing the current song.

Define _RTTTL\_NONBLOCKING\_INFO_ to enable the debugging of the library state on the serial port. Use _NONBLOCKINGRTTTL_VERSION_ to read the current version of the library.

## <span id="Demo">Demo</span>

The following demo show how to use the library:  
(download the 
	<a class="download-link" title="Version 1.0.101" href="http://www.end2endzone.com/download/1676/" rel="nofollow"> NonBlockingRtttl demo sample (738 downloads) </a>)

<pre class="lang:c++ decode:true" title="NonBlockingRtttl demo sample v1.0.101.ino" data-url="http://www.end2endzone.com/wp-content/uploads/2016/03/NonBlockingRtttl-demo-v1.0.101.ino">sample</pre>

# <span id="License">License</span>

The following code was written by Antoine Beauchamp. The non-blocking RTTTL library is a port of the RTTTL example from the [Tone library][4] which is licensed with the [MIT License][7].

The code & updates for the library can be found at <http://end2endzone.com>.

For the original source code for the RTTTL player see: <http://code.google.com/archive/p/rogue-code/wikis/ToneLibraryDocumentation.wiki>.

# <span id="Download">Download</span>

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of NonBlockingRtttl library can be downloaded from the project’s <a href="https://github.com/end2endzone/NonBlockingRTTTL/releases">Release page</a>.
</p>

<p class="postedit">
  EDIT: NonBlockingRTTTL library can now be installed from the <a href="http://www.arduino.cc/en/guide/libraries#toc3">Arduino Library Manager</a>.
</p>

 [1]: #Download
 [2]: #Quick_recall_of_the_RTTTL_format
 [3]: http://en.wikipedia.org/wiki/Non-blocking_algorithm
 [4]: http://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rogue-code/Arduino-Library-Tone.zip
 [5]: http://stackoverflow.com/questions/568671/why-should-i-use-a-human-readable-file-format
 [6]: https://en.wikipedia.org/wiki/Ring_Tone_Transfer_Language
 [7]: http://www.opensource.org/licenses/mit-license.php