---
title: libMIDI – A C++ open-source library for generating single tone melodies in MIDI format
author: end2end
type: post
date: 2016-04-24T16:42:27+00:00
url: /libmidi-a-c-open-source-library-for-generating-single-tone-melodies-in-midi-format/
featured_image: /wp-content/uploads/2016/04/libMidi-cplusplus-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    <p>Downloads available in this article:</p>
    <div style="margin-bottom: 18px">
    <p class="nomarginbottom">Library:</p>
    <ul class="fa-ul">
    <li><a href="/download/1893/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="1893" template="title"]</a></li>
    </ul>
    </div>
hits:
  - 808
categories:
  - Development
tags:
  - c++
  - english
  - open source

---
# <span id="Introduction">Introduction</span>

The following article is yet another library that I have written. libMIDI is a c++ library for generating single tone melodies (monolithic melodies) in MIDI format.<!--more-->

Skip to the [download section][1] for quick download.

# <span id="Purpose">Purpose</span>

I mostly develop on the Windows platform. When I try to generate basic sounds and tone, I use the [Microsoft Beep function][2]. This API is quite old and is far from accurate when dealing with multiple short duration tones (less than 100ms). Also when you make two consecutive calls to the <code class="prettycode">Beep()</code> function will ear a tick sound between each calls.

One way to solve this issue is to use the MIDI sound format and use the [Microsoft Windows API to play a MIDI file][3].

The library is develop & design to be lightweight and have a very quick learning curve. It was only designed as a mean to convert melodies made in tones (frequency, duration pairs) to MIDI sound format.

The library may be used on other platforms too for generating files which can be played using the platform&#8217;s own media player.

<p class="pleasenote" data-pleasenote="true">
  Note that libMIDI library was not written to manipulate the MIDI sound format. There is no plan in improving/updating the library in order to support MIDI file parsing or supporting multiple tracks at once.
</p>

# <span id="Library">Library</span>

## <span id="Functionalities_Features">Functionalities / Features</span>

Possible use are:

<li style="text-align: justify;">
  Generate notes using a tone frequency and duration.
</li>
<li style="text-align: justify;">
  Supports custom delays, volumes, melody name & instruments.
</li>
<li style="text-align: justify;">
  Defines multiple speed requirements : <ul>
    <li style="text-align: justify;">
      Ticks (or pulses) per quarters notes.
    </li>
    <li style="text-align: justify;">
      Tempo (microseconds per quarter note).
    </li>
    <li style="text-align: justify;">
      BPM (beats per minute).
    </li>
  </ul>
</li>

  * Simple unit conversion API: 
      * BPM to/from Tempo.
      * Ticks to/from microseconds.

## <span id="Requirements">Requirements</span>

The library has some compilation requirements and library dependencies which are:

<li style="text-align: justify;">
  Only Visual Studio 2008 projects files are available. Files can be manually converted to other version as required. Supporting other compilers is not currently planned.
</li>
<li style="text-align: justify;">
  The <a href="http://github.com/google/googletest">Google Test</a> v1.6 library is required for running test cases.
</li>

# <span id="Usage">Usage</span>

Each melody is build using a single class called <code class="prettycode">MidiFile</code>. Create an instance and sets your basic requirements like name, speed, and MIDI standard, using the appropriate setter functions. Notes can be added one after the other using the <code class="prettycode">addNote()</code> method. The melody is built in memory. Once the melody is completed, use the <code class="prettycode">save()</code> method to generate a valid MIDI file on disk.

For example the following code can be used to generate _Super Mario Bros. 1 up_ theme sound:

<pre class="lang:c++ decode:true" title="Super Mario Bros. 1-up theme sound">MidiFile f;

f.setMidiType(MidiFile::MIDI_TYPE_0);
f.setInstrument(0x51);
f.setTempo(0x051615);
f.setName("mario1up");
f.setVolume(0x64);

//play mario 1-up melody.
f.addNote(1319,125);
f.addNote(1568,125);
f.addNote(2637,125);
f.addNote(2093,125);
f.addNote(2349,125);
f.addNote(3136,125);

bool saved = f.save("mario1up.mid");</pre>

# <span id="License">License</span>

libMIDI Library  
Copyright (C) 2016 Antoine Beauchamp  
The code & updates for the library can be found on http://end2endzone.com

<span style="color: #aaaaaa;"><strong>AUTHOR/LICENSE:</strong></span>  
This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public  
License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**<span style="color: #aaaaaa;">DISCLAIMER:</span>**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the libMIDI library by clicking on the following link:

  * 
		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/1893/" rel="nofollow"> Download &ldquo;libMIDI-v1.0.0.40.zip&rdquo; <small>libMIDI-v1.0.0.40.zip &ndash; Downloaded 433 times &ndash; 43 KB</small> </a>

 [1]: #Download
 [2]: http://msdn.microsoft.com/en-ca/library/windows/desktop/ms679277(v=vs.85).aspx
 [3]: http://msdn.microsoft.com/en-us/library/windows/desktop/dd743673(v=vs.85).aspx