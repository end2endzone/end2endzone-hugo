---
title: libMIDI – A C++ open-source library for generating single tone melodies in MIDI format
author: end2end
date: 2016-04-24T16:42:27+00:00
url: /libmidi-a-c-open-source-library-for-generating-single-tone-melodies-in-midi-format/
images:
  - src: /wp-content/uploads/2016/04/libMidi-cplusplus-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    Downloads available in this article:
    Library:
    * [[download id="1893" template="title"]](/download/1893/)
hits:
  - 808
categories:
  - Development
tags:
  - c++
  - english
  - open source

---

# Introduction

The following article is yet another library that I have written. libMIDI is a c++ library for generating single tone melodies (monolithic melodies) in MIDI format. Skip to the [download section](#Download) for quick download.

# Purpose

I mostly develop on the Windows platform. When I try to generate basic sounds and tone, I use the [Microsoft Beep function](http://msdn.microsoft.com/en-ca/library/windows/desktop/ms679277(v=vs.85).aspx). This API is quite old and is far from accurate when dealing with multiple short duration tones (less than 100ms). Also when you make two consecutive calls to the `Beep()` function will ear a tick sound between each calls. One way to solve this issue is to use the MIDI sound format and use the [Microsoft Windows API to play a MIDI file](http://msdn.microsoft.com/en-us/library/windows/desktop/dd743673(v=vs.85).aspx). The library is develop &amp; design to be lightweight and have a very quick learning curve. It was only designed as a mean to convert melodies made in tones (frequency, duration pairs) to MIDI sound format. The library may be used on other platforms too for generating files which can be played using the platform's own media player. Note that libMIDI library was not written to manipulate the MIDI sound format. There is no plan in improving/updating the library in order to support MIDI file parsing or supporting multiple tracks at once.

# Library

## Functionalities / Features

Possible use are:

- Generate notes using a tone frequency and duration.
- Supports custom delays, volumes, melody name &amp; instruments.
- Defines multiple speed requirements : 
    - Ticks (or pulses) per quarters notes.
    - Tempo (microseconds per quarter note).
    - BPM (beats per minute).
- Simple unit conversion API: 
    - BPM to/from Tempo.
    - Ticks to/from microseconds.

## Requirements

The library has some compilation requirements and library dependencies which are:

- Only Visual Studio 2008 projects files are available. Files can be manually converted to other version as required. Supporting other compilers is not currently planned.
- The [Google Test](http://github.com/google/googletest) v1.6 library is required for running test cases.

# Usage

Each melody is build using a single class called `MidiFile`. Create an instance and sets your basic requirements like name, speed, and MIDI standard, using the appropriate setter functions. Notes can be added one after the other using the `addNote()` method. The melody is built in memory. Once the melody is completed, use the `save()` method to generate a valid MIDI file on disk. For example the following code can be used to generate *Super Mario Bros. 1 up* theme sound:

```
MidiFile f;

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

bool saved = f.save("mario1up.mid");
```

# License

libMIDI Library Copyright (C) 2016 Antoine Beauchamp The code &amp; updates for the library can be found on http://end2endzone.com **AUTHOR/LICENSE:** This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:** This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the libMIDI library by clicking on the following link:

- {{% download old-id="1893" href="https://github.com/end2endzone/libMidi/archive/refs/tags/2.0.0.zip" %}}libMidi v2.0.0.zip{{% /download %}}
