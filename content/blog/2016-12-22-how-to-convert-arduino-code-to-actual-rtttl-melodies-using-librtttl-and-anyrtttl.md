---
title: How to convert arduino code to actual RTTTL melodies using libRtttl and AnyRtttl
author: end2end
type: post
date: 2016-12-22T18:03:50+00:00
url: /how-to-convert-arduino-code-to-actual-rtttl-melodies-using-librtttl-and-anyrtttl/
featured_image: /wp-content/uploads/2016/11/How-to-convert-arduino-code-to-actual-RTTTL-melodies-using-libRtttl-and-AnyRtttl-672x378.jpg
hits:
  - 866
categories:
  - Development
tags:
  - arduino
  - english
  - open source
  - rtttl

---
# <span id="Introduction">Introduction</span>

The following article is written in order to demonstrate how my arduino libraries [libRtttl][1] & [AnyRtttl][2] can be used to convert arduino code (<code class="prettycode">tone()</code> and <code class="prettycode">delay()</code> functions calls) into actual RTTTL melodies.<!--more-->

This article shows how to convert &#8216;_Game of Throne theme_&#8216;, &#8216;_Star Wars &#8211; The imperial March_&#8216; and most _Super Mario Bros. sound themes_ (Main theme, 1-up life sound, Flagpole fanfare, Death and Game Over sounds) into actual playable RTTTL melodies.

# <span id="Methodology">Methodology</span>

The basic idea is to convert the code to their lowest common denominator which is tone frequencies and duration (delays). The [libRtttl][3] gui program has build-it functionnality to extract the frequencies and delays from arduino code. Using the application, one can convert any melody to RTTTL.

## <span id="Handling_structured_orlogicalcode">Handling structured or logical code</span>

Some programs are written in an optimized fashion where reapeated sections of a melody are extracted into a function. ie: <code class="prettycode">playRefrain()</code>. The function is then called multiple times to play the whole melody. This method is an effective way to reduce code size but [libRtttl][3] gui is unable to parse this code.

Other programs could also use <code class="prettycode">tone()</code> or <code class="prettycode">delay()</code> calls using <code class="prettycode">Constants</code>. A typical usage of this method is to use predefined note names for frequencies which makes the code easier to read. However, constants are also hard to extract by [libRtttl][3] gui which does not yet support this feature.

The following code shows the usage of note names as arguments to the <code class="prettycode">tone()</code> function:

<pre class="lang:c++ decode:true " title="tone() function using constants">tone(8,LA4,Q);
delay(1+Q);
tone(8,LA3,E+S);
delay(1+E+S);</pre>

To hande these kind of program, the following code can be added at the beginning of the program. This code will output all calls to the <code class="prettycode">tone()</code> and <code class="prettycode">delay()</code> functions to the serial port.

<div class="crayon-line">
  <pre class="lang:c++ decode:true" title="Arduino tone and delay functions overrides" data-url="http://www.end2endzone.com/wp-content/uploads/2016/10/Arduino-tone-and-delay-functions-overrides.ino">http://www.end2endzone.com/wp-content/uploads/2016/10/Arduino-tone-and-delay-functions-overrides.ino</pre>
</div>

<div class="crayon-line">
  <div class="su-spacer" style="height:30px">
  </div>
</div>

<div class="crayon-line">
</div>

<p class="pleasenote" data-pleasenote="true">
  Note that the code above is later refered to as &#8220;<em>Arduino tone and delay functions overrides</em>&#8220;.
</p>

# <span id="Samples">Samples</span>

The following section shows example of using libRtttl gui to convert arduino code (<code class="prettycode">tone()</code> and <code class="prettycode">delay()</code> functions calls) into actual RTTTL melodies.

## <span id="Game_of_Throne">Game of Throne</span>

Source code:

  * Youtube: <http://www.youtube.com/watch?v=vrzQU_QbQ5U>
  * Code from pastebin: <http://pastebin.com/q76D0asp>
  * Cache version here: [FULL Game of Thrones Theme Song on Arduino][4]

Modify the code by adding the _&#8220;Arduino tone and delay functions overrides&#8221;_ to the code. Once done, the code should be looking like this:

<pre class="height-set:true height:250 lang:default decode:true" title="GOT - Code modified to extract frequencies & durations" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/FULL-Game-of-Thrones-Theme-Song-on-Arduino-call-extraction-version.ino">http://www.end2endzone.com/wp-content/uploads/2016/05/FULL-Game-of-Thrones-Theme-Song-on-Arduino-call-extraction-version.ino</pre>

which result in the following data outputted on the serial port when executed:

<pre class="height-set:true height:150 width-set:true width:100 width-unit:1 lang:default decode:true" title="Function calls to play Game of Throne theme song on arduino" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/FULL-Game-of-Thrones-Theme-Song-on-Arduino-serial-output.txt">http://www.end2endzone.com/wp-content/uploads/2016/05/FULL-Game-of-Thrones-Theme-Song-on-Arduino-serial-output.txt</pre>

Using libRtttl gui, the above code can be converted to the following RTTTL melody:

<p class="pleasenote" data-pleasenote="true">
  Settings: force default, enable tone() octave offsetting.
</p>

Game of Throne RTTTL:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="Game of Throne RTTTL">GOT:d=32,o=4,b=320:2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.7,p,1c.7,p,4d#7,p,4f7,p,1g7,p,1c7,p,4d#7,p,4f7,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.7,p,1a#.6,p,1d7,p,1d#7,p,1d7,p,1a#6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g6,p,4a#,p,4c5,p,2d5,p,2g6,p,4a#,p,4c5,p,2d5,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4f#,p,2d#6,p,1f6,2p,4g#,p,4g#,p,2f6,p,2c6,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g6,p,4a#,p,4c5,p,2d5,p,2g6,p,4a#,p,4c5,p,2d5,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4g#,p,2a#,p,1d#6,p,2d#6,p,1d6,p,2d6,p,2c6,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#7,p,4f7,p,2g7,p,2c7,p,4d#7,p,4f7,p,2g7,p,2c7,p,4d#7,p,4f7,p,2g7,p</pre>

or the following (by enabling unofficial BPM values) which help have accurate delays between notes:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="Game of Throne RTTTL v2">GOTv2:d=32,o=4,b=336:2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4e5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.6,p,1c.6,p,4d#6,p,4f6,p,1g6,p,1c6,p,4d#6,p,4f6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.6,p,1a#.5,p,4d6,p,4d#6,p,1f6,p,1a#5,p,4d#6,p,4d6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1g.7,p,1c.7,p,4d#7,p,4f7,p,1g7,p,1c7,p,4d#7,p,4f7,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,1f.7,p,1a#.6,p,1d7,p,1d#7,p,1d7,p,1a#6,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g6,p,4a#,p,4c5,p,2d5,p,2g6,p,4a#,p,4c5,p,2d5,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4f#,p,2d#6,p,1f6,2p,4g#,p,4g#,p,2f6,p,2c6,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2c7,p,4d#5,p,4f5,p,2g5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2a#6,p,4d5,p,4d#5,p,2f5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g#6,p,4c5,p,4d5,p,2d#5,p,2g6,p,4a#,p,4c5,p,2d5,p,2g6,p,4a#,p,4c5,p,2d5,p,2d#6,p,4f#,p,4g#,p,2a#,p,2d#6,p,4f#,p,4g#,p,2a#,p,1d#6,p,2d#6,p,1d6,p,2d6,p,2c6,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#5,p,4f5,p,2g5,p,2c5,p,4d#7,p,4f7,p,2g7,p,2c7,p,4d#7,p,4f7,p,2g7,p,2c7,p,4d#7,p,4f7,p,2g7,p</pre>

## <span id="Star_Wars_8211The_imperial_March">Star Wars &#8211; The imperial March</span>

Source code:

  * Instructables: <http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/>
  * Code from pasted: <http://pasted.co/e525c1b2>
  * Cache version here: <a href="http://www.end2endzone.com/wp-content/uploads/2016/05/Star_Wars_-_The_imperial_March.ino" rel="">Star_Wars_-_The_imperial_March</a>

Modify the code by adding the &#8220;_Arduino tone and delay functions overrides_&#8221; to the code. Once done, the code should be looking like this:

<pre class="height-set:true height:250 width-set:true width:100 width-unit:1 lang:c++ decode:true" title="Star Wars - The imperial March - Code modified to extract frequencies & durations" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/Star_Wars_-_The_imperial_March-modified.ino">http://www.end2endzone.com/wp-content/uploads/2016/05/Star_Wars_-_The_imperial_March-modified.ino</pre>

which result in the following data outputted on the serial port:

<pre class="height-set:true height:150 width-set:true width:100 width-unit:1 lang:c++ decode:true" title="Function calls to play Star Wars - The imperial March song on arduino" data-url="http://www.end2endzone.com/wp-content/uploads/2016/05/Star_Wars_-_The_imperial_March-function-calls.txt">http://www.end2endzone.com/wp-content/uploads/2016/05/Star_Wars_-_The_imperial_March-function-calls.txt</pre>

Using libRtttl gui, the above code can be converted to the following RTTTL melody:

<p class="pleasenote" data-pleasenote="true">
  Settings: force default, enable tone() octave offsetting
</p>

Star Wars &#8211; The imperial March RTTTL:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="The Imperial March RTTTL">unknown:d=4,o=5,b=180:a.4,a.4,a.4,f4,16c.,a.4,f4,16c.,2a.4,e.,e.,e.,f,16c.,g#.4,f4,16c.,2a.4,a.,a4,16a.4,a.,g#,16g.,16f#.,16e.,8f.,8p.,8a#.4,d#.,d,16c#.,16c.,16b.4,8c.,8p.,8f.4,g#.4,f4,16a.4,c.,a4,16c.,2e.,a.,a4,16a.4,a.,g#,16g.,16f#.,16e.,8f.,8p.,8a#.4,d#.,d,16c#.,16c.,16b.4,8c.,8p.,8f.4,g#.4,f4,16c.,a.4,f4,16c.,2a.4</pre>

or the following (by enabling unofficial BPM values) which help have accurate delays between notes:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="The Imperial March RTTTL v2">unknown:d=8,o=5,b=120:4a4,4a4,4a4,f.4,16c,4a4,f.4,16c,2a4,4e,4e,4e,f.,16c,4g#4,f.4,16c,2a4,4a,a.4,16a4,4a,g#.,16g,16f#,16e,f,p,a#4,4d#,d.,16c#,16c,16b4,c,p,f4,4g#4,f.4,16a4,4c,a.4,16c,2e,4a,a.4,16a4,4a,g#.,16g,16f#,16e,f,p,a#4,4d#,d.,16c#,16c,16b4,c,p,f4,4g#4,f.4,16c,4a4,f.4,16c,2a4</pre>

## <span id="Super_Mario_Bros_themes">Super Mario Bros. themes</span>

Source code:

  * GitHub: <https://github.com/tsukisan/Arduino/blob/master/WiiClassicSoundboard/WiiClassicSoundboard.ino>
  * Code from GitHub: <https://raw.githubusercontent.com/tsukisan/Arduino/master/WiiClassicSoundboard/WiiClassicSoundboard.ino>
  * Cache version here: <a href="http://www.end2endzone.com/wp-content/uploads/2016/11/WiiClassicSoundboard.ino" rel="">WiiClassicSoundboard &#8211; Super Mario Bros. themes</a>

Modify the code by adding the &#8220;_Arduino tone and delay functions overrides_&#8221; to the code. Once done, the code should be looking like this:

<pre class="height-set:true height:250 width-set:true width:100 width-unit:1 lang:c++ decode:true" title="WiiClassicSoundboard - Super Mario Bros. themes - Code modified to extract frequencies & durations" data-url="http://www.end2endzone.com/wp-content/uploads/2016/11/WiiClassicSoundboard-Super-Mario-Bros.-themes-modified.ino">http://www.end2endzone.com/wp-content/uploads/2016/11/WiiClassicSoundboard-Super-Mario-Bros.-themes-modified.ino</pre>

which result in the following data outputted on the serial port:

<pre class="height-set:true height:150 width-set:true width:100 width-unit:1 lang:c++ decode:true" title="Function calls to play Super-Mario-Bros. theme songs on arduino" data-url="http://www.end2endzone.com/wp-content/uploads/2016/11/Super-Mario-Bros.-themes-function-calls.txt">http://www.end2endzone.com/wp-content/uploads/2016/11/Super-Mario-Bros.-themes-function-calls.txt</pre>

<p class="pleasenote" data-pleasenote="true">
  Note that output contains the following function calls: <code class="prettycode">tone(12,0,something);</code>. Unfortunately, the libRtttl does not properly identify these lines as &#8220;silence pin 12&#8221; but they can safely be removed from the output without any issue.
</p>

Using libRtttl gui, the above code can be converted to the following RTTTL melodies:

<p class="pleasenote" data-pleasenote="true">
  Settings: force default, enable tone() octave offsetting
</p>

Super Mario Bros. themes RTTTL:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="Super Mario Bros. themes RTTTL">theme:d=8,o=4,b=355:e.5,32p.,e.5,32p.,4p,e.5,32p.,4p,c.5,32p.,e.5,32p.,4p,g.5,32p.,2p,g.,32p.
life:d=8,o=4,b=450:e.5,32p.,g.5,32p.,e.6,32p.,c.6,32p.,d.6,32p.,g.6,32p.
flagpole:d=8,o=4,b=450:f#.,32p.,c.5,32p.,e.5,32p.,g.5,32p.,c.6,32p.,e.6,32p.,2g6,p.,2e6,p.,g#.,32p.,c.5,32p.,d#.5,32p.,g#.5,32p.,c.6,32p.,d#.6,32p.,2g#6,p.,2d#6,p.,a#.,32p.,d.5,32p.,f.5,32p.,a#.5,32p.,d.6,32p.,f.6,32p.,2a#6,p.,b.6,32p.,b.6,32p.,b.6,32p.,1c7,4p
death:d=32,o=4,b=355:c.5,p,c#.5,p,16d.5,p,2p,1p,8b.,p.,8f.5,p.,4p,8f.5,p.,4f5,16p,4e5,16p,4d5,16p,8c.5,p.,8e.,p.,4p,8e.,p.,8c.,p.
gameover:d=4,o=4,b=355:8c.5,32p.,p,p,8g.,32p.,2p,e.,8p,a,16p,b,16p,a,16p,g#,16p,a#,16p,g#,16p,8g.,32p.,8f.,32p.,g.,8p
</pre>

or the following (by enabling unofficial BPM values) which help have accurate delays between notes:

<pre class="height-set:true width-set:true width:100 width-unit:1 wrap:true lang:default decode:true" title="Super Mario Bros. themes RTTTL v2">theme: (identical)
life: (identical)
flagpole: (identical)
death:d=16,o=4,b=706:c.5,32p,c#.5,32p,8d.5,32p.,1p,1p.,4b.,p.,4f.5,p.,2p,4f.5,p.,2f5,8p,2e5,8p,2d5,8p,4c.5,p.,4e.,p.,2p,4e.,p.,4c.,p.
gameover: (identical)</pre>

 [1]: /librtttl-a-c-library-with-ui-for-compressingoptimizing-the-rtttl-audio-format/
 [2]: /anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/
 [3]: http://www.end2endzone.com/librtttl-a-c-library-with-ui-for-compressingoptimizing-the-rtttl-audio-format/
 [4]: http://www.end2endzone.com/wp-content/uploads/2016/05/FULL-Game-of-Thrones-Theme-Song-on-Arduino.ino