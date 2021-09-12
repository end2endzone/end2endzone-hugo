---
title: Mapping RC Transmitter PWM signal to actual transmitter values
author: end2end
type: post
date: 2016-03-26T20:47:29+00:00
url: /mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/
featured_image: /wp-content/uploads/2016/03/Mapping-RC-Transmitter-PWM-signal-to-actual-transmitter-values-672x378.jpg
hits:
  - 2780
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Data capture sessions:</p>
        <ul class="fa-ul">
        <li><a href="/download/1618/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Spektrum DX9 Tx &amp; Orange R620X Rx</a></li>
        <li><a href="/download/1620/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Spektrum DX9 Tx &amp; Spektrum AR8000 Rx</a></li>
        <li><a href="/download/1614/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Tactic TTX600 Tx &amp; Tactic TR624 Rx</a></li>
        <li><a href="/download/1616/"><i class="fa-li fa fa-download" style="position: inherit;"></i>CCPM Servo Tester</a></li>
        </ul>
        </div>
        
categories:
  - Model Aeronautics
tags:
  - arduino
  - english
  - RC
  - RC transmitter

---
# <span id="Introduction">Introduction</span>

If you ever need to use an RC Transmitter & receiver for a personal project, an easy way to retrieve the signal is to connect the receiver to a micro-controller.

However, decoding the signal to get actual transmitter values is not as easy as it sounds. You need to know the correct encoding and searching on the internet about the subject gives erratic results.

Here is the full article that explains how to correctly map an RC Transmitter PWM signal to actual transmitter values.<!--more-->

# <span id="How_does_it_works">How does it works?</span>

The receiver signal is encoded with a [Pulse Width Modulation][1]. In other way, the transfer of the signal is analog and not digital. This means there is no direct method to read the signal. To accurately read the signal, you need to know the given length of the pulse for each unique transmitter values.

Using benchmark data, I managed to find approximation functions that works for most transmitter values. Multiple benchmark data is available for multiple combination of transmitter and receiver.

# <span id="What_is_expected">What is expected</span>

If you search on the internet, you will find information regarding [servos][2] which typically uses the same &#8220;_kind&#8221;_ of PWM signal.  However, as you will see in the next section, the minimum and maximum values for a servo does not match their counterpart on a RC transmitter.

## <span id="Theoretical_values">Theoretical values</span>

Most information sources about [servo control][3] states that generally the minimum pulse will be about 1 ms wide and the maximum pulse will be 2 ms wide.

The following table shows the theoretical pulse length for each transmitter values:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td colspan="2">
      <b>Expected Transmitter Pulses</b>
    </td>
  </tr>
  
  <tr class="headerrow">
    <td style="width: 100px;" width="60">
      <b>Length (µS)</b>
    </td>
    
    <td style="width: 100px;">
      <b>Value</b>
    </td>
  </tr>
  
  <tr>
    <td style="width: 60px;" width="60">
      1000
    </td>
    
    <td>
      -100%
    </td>
  </tr>
  
  <tr>
    <td>
      1500
    </td>
    
    <td>
      0%
    </td>
  </tr>
  
  <tr>
    <td>
      2000
    </td>
    
    <td>
      100%
    </td>
  </tr>
</table>

## <span id="Extrapolation">Extrapolation</span>

Knowing that a pulse delta time of 1000 µS (from 1000 µS to 2000 µS) is required to identify 200 different steps (from -100% to +100%), it is then safe to assume that each step is 5 µS. With this calculation, the theoretical pulse length of other values should be identified as follows:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td colspan="2">
      <b>Extrapolated Transmitter Pulses</b>
    </td>
  </tr>
  
  <tr class="headerrow">
    <td style="width: 100px;" width="60">
      <b>Length (µS)</b>
    </td>
    
    <td style="width: 100px;" width="60">
      <b>Value</b>
    </td>
  </tr>
  
  <tr>
    <td>
      750
    </td>
    
    <td>
      -150%
    </td>
  </tr>
  
  <tr>
    <td>
      875
    </td>
    
    <td>
      -125%
    </td>
  </tr>
  
  <tr>
    <td>
      1125
    </td>
    
    <td>
      -75%
    </td>
  </tr>
  
  <tr>
    <td>
      1250
    </td>
    
    <td>
      -50%
    </td>
  </tr>
  
  <tr>
    <td>
      1375
    </td>
    
    <td>
      -25%
    </td>
  </tr>
  
  <tr>
    <td>
      1625
    </td>
    
    <td>
      25%
    </td>
  </tr>
  
  <tr>
    <td>
      1750
    </td>
    
    <td>
      50%
    </td>
  </tr>
  
  <tr>
    <td>
      1875
    </td>
    
    <td>
      75%
    </td>
  </tr>
  
  <tr>
    <td>
      2125
    </td>
    
    <td>
      125%
    </td>
  </tr>
  
  <tr>
    <td>
      2250
    </td>
    
    <td>
      150%
    </td>
  </tr>
</table>

<p class="wrong">
  WRONG!
</p>

 

Theoretical values is never as good as real world observations.

# <span id="Capture_methodology">Capture methodology</span>

For the data capture, I used an [Arduino Nano V3][4] micro-controller. With the help of multiple libraries, I created a program to capture each pulse length of critical target point for a given amount of time. Since the length of each pulse is not perfectly constant, I extracted the average pulse length. Matching different points, I calculated multiple trend line formulas in [polynomial][5] format. I then calculate each formula performance against all other points. Finally, I identify the best formula to be used in real projects.

<p class="pleasenote" data-pleasenote="true">
  Note that all raw data capture are available for download as Excel files (*.xlsx) in sections below.
</p>

## <span id="Required_Libraries">Required Libraries</span>

### <span id="PinChangeInt"><a href="https://github.com/GreyGnome/PinChangeInt">PinChangeInt</a></span>

This library allows the arduino to attach interrupts on multiple pins.

### <span id="eRCaGuy_Timer2_Counter"><a href="http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html">eRCaGuy_Timer2_Counter</a></span>

This library configures the arduino&#8217;s timer2 to 0.5µs precision. It is used for a &#8220;micros()&#8221; function replacement and allows times calculations that are far more precise (8 times!) than the default&#8217;s 4µs resolution.

## <span id="PWM_capture_code">PWM capture code</span>

Here is the final arduino code that allowed raw data capture to extract average pulse length for each critical target point:

<pre class="lang:default decode:true " title="RC Transmitter PWM Reader (*.ino)" data-url="http://www.end2endzone.com/wp-content/uploads/2016/02/RcPwmReader-v95.ino">sample</pre>

Download the arduino source code: 
	<a class="download-link" title="Version 1.1" href="http://www.end2endzone.com/download/1582/" rel="nofollow"> RC Transmitter PWM Reader (*.ino) (278 downloads) </a>.

# <span id="Benchmark_results">Benchmark results</span>

The following section show the results of all my data capture sessions. Each device combination show the following information:

<span style="text-decoration: underline;"><span style="font-size: 16pt;"><strong>Table 1</strong> </span></span>

  1. A given transmitter value.
  2. Average pulse length (in µs) for the given transmitter value.
  3. Minimum and Maximum pulse length for the given transmitter value.
  4. Width of pulses in µs (difference between maximum and minimum length)
  5. Middle pulse length. Middle point between minimum and maximum pulses.

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 2<br /></span></strong></span>Table 2 shows selected control points and the polynomial function for the selected points. Multiple polynomial functions are found using different control points.

<p class="pleasenote" data-pleasenote="true">
  Note that pulse length from most devices are not perfectly linear. This means that most of the time, more than 2 control points are required to get a polynomial function that is accurate.
</p>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 3<br /></span></strong></span>Table 3 shows each function&#8217;s performance trying to properly predict a transmitter value from a pulse length. The function that offers the best performance is selected as the final function.

<p class="pleasenote" data-pleasenote="true">
  Note that some devices are low quality products and are not always constant or does not provide constant transmitter value.
</p>

# <span id="Devices">Devices</span>

## <span id="Spektrum_DX9_Tx_Orange_R620X_Rx">Spektrum DX9 Tx & Orange R620X Rx</span>

<div id='gallery-8' class='gallery galleryid-1357 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg" title="Spektrum DX9 9-ch RC Tx" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx-150x150.jpg" width="150" height="150" alt="Spektrum DX9 9-ch RC Tx" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1587">
      <span class="imagecaption">Spektrum DX9 9-ch RC Tx</span><br /> <span class="imagedescription">Spektrum DX9 9-ch RC Tx</span><br />
    </dd>
  </dl>
  
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx.jpg" title="Orange R620X 6-ch RC Rx" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx-150x150.jpg" width="150" height="150" alt="Orange R620X 6-ch RC Rx" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1588">
      <span class="imagecaption">Orange R620X 6-ch RC Rx</span><br /> <span class="imagedescription">Orange R620X 6-ch RC Rx</span><br />
    </dd>
  </dl>
  
  <br style='clear: both' />
</div>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 1<br /></span></strong></span>The Spektrum DX9 Tx & Orange R620X Rx shows a PWM range from **827 µs** to **2194 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col /> <col /> <col /> <col span="2" /> <col /> </colgroup> <tr class="headerrow">
    <td colspan="6">
      Spektrum DX9 Tx & Orange R620X Rx
    </td>
  </tr>
  
  <tr class="headerrow">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Min
    </td>
    
    <td>
      Max
    </td>
    
    <td>
      Width
    </td>
    
    <td>
      Middle
    </td>
  </tr>
  
  <tr>
    <td>
      150
    </td>
    
    <td>
      2187.85
    </td>
    
    <td>
      2181
    </td>
    
    <td>
      2194
    </td>
    
    <td>
      13
    </td>
    
    <td>
      2187.5
    </td>
  </tr>
  
  <tr>
    <td>
      149
    </td>
    
    <td>
      2180.73
    </td>
    
    <td>
      2175
    </td>
    
    <td>
      2186
    </td>
    
    <td>
      11
    </td>
    
    <td>
      2180.5
    </td>
  </tr>
  
  <tr>
    <td>
      148
    </td>
    
    <td>
      2178.54
    </td>
    
    <td>
      2173
    </td>
    
    <td>
      2184
    </td>
    
    <td>
      11
    </td>
    
    <td>
      2178.5
    </td>
  </tr>
  
  <tr>
    <td>
      147
    </td>
    
    <td>
      2173.86
    </td>
    
    <td>
      2168
    </td>
    
    <td>
      2180
    </td>
    
    <td>
      12
    </td>
    
    <td>
      2174
    </td>
  </tr>
  
  <tr>
    <td>
      146
    </td>
    
    <td>
      2167.92
    </td>
    
    <td>
      2163
    </td>
    
    <td>
      2173
    </td>
    
    <td>
      10
    </td>
    
    <td>
      2168
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      1961.01
    </td>
    
    <td>
      1956
    </td>
    
    <td>
      1966
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1961
    </td>
  </tr>
  
  <tr>
    <td>
      50
    </td>
    
    <td>
      1732.35
    </td>
    
    <td>
      1727
    </td>
    
    <td>
      1738
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1732.5
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1505.40
    </td>
    
    <td>
      1499
    </td>
    
    <td>
      1512
    </td>
    
    <td>
      13
    </td>
    
    <td>
      1505.5
    </td>
  </tr>
  
  <tr>
    <td>
      -50
    </td>
    
    <td>
      1277.65
    </td>
    
    <td>
      1273
    </td>
    
    <td>
      1284
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1278.5
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1050.22
    </td>
    
    <td>
      1045
    </td>
    
    <td>
      1055
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1050
    </td>
  </tr>
  
  <tr>
    <td>
      -120
    </td>
    
    <td>
      959.43
    </td>
    
    <td>
      954
    </td>
    
    <td>
      964
    </td>
    
    <td>
      10
    </td>
    
    <td>
      959
    </td>
  </tr>
  
  <tr>
    <td>
      -135
    </td>
    
    <td>
      891.52
    </td>
    
    <td>
      887
    </td>
    
    <td>
      896
    </td>
    
    <td>
      9
    </td>
    
    <td>
      891.5
    </td>
  </tr>
  
  <tr>
    <td>
      -146
    </td>
    
    <td>
      841.55
    </td>
    
    <td>
      835
    </td>
    
    <td>
      848
    </td>
    
    <td>
      13
    </td>
    
    <td>
      841.5
    </td>
  </tr>
  
  <tr>
    <td>
      -147
    </td>
    
    <td>
      836.76
    </td>
    
    <td>
      832
    </td>
    
    <td>
      843
    </td>
    
    <td>
      11
    </td>
    
    <td>
      837.5
    </td>
  </tr>
  
  <tr>
    <td>
      -148
    </td>
    
    <td>
      832.02
    </td>
    
    <td>
      827
    </td>
    
    <td>
      837
    </td>
    
    <td>
      10
    </td>
    
    <td>
      832
    </td>
  </tr>
  
  <tr>
    <td>
      -149
    </td>
    
    <td>
      827.47
    </td>
    
    <td>
      822
    </td>
    
    <td>
      833
    </td>
    
    <td>
      11
    </td>
    
    <td>
      827.5
    </td>
  </tr>
  
  <tr>
    <td>
      -150
    </td>
    
    <td>
      826.80
    </td>
    
    <td>
      821
    </td>
    
    <td>
      832
    </td>
    
    <td>
      11
    </td>
    
    <td>
      826.5
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 2<br /></span></strong></span>From these values, I extracted the following polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col /> <col span="4" /> <col /> <col /> <col /> </colgroup> <tr class="headerrow">
    <td>
      Polynomial Equation
    </td>
    
    <td>
      Py1
    </td>
    
    <td>
      Px1
    </td>
    
    <td>
      Py2
    </td>
    
    <td>
      Px2
    </td>
    
    <td>
      a2
    </td>
    
    <td>
      a1
    </td>
    
    <td>
      a0
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      150
    </td>
    
    <td>
      2187.85
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      826.80
    </td>
    
    <td>
    </td>
    
    <td>
      0.220417088
    </td>
    
    <td>
      -332.2399666
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      146
    </td>
    
    <td>
      2167.92
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      891.52
    </td>
    
    <td>
    </td>
    
    <td>
      0.220149733
    </td>
    
    <td>
      -331.2670095
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      100
    </td>
    
    <td>
      1961.01
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      1050.22
    </td>
    
    <td>
    </td>
    
    <td>
      0.219590069
    </td>
    
    <td>
      -330.6178825
    </td>
  </tr>
  
  <tr style="background-color: yellow;">
    <td>
      3
    </td>
    
    <td>
      148
    </td>
    
    <td>
      2178.54
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      832.016
    </td>
    
    <td>
    </td>
    
    <td>
      0.219825269
    </td>
    
    <td>
      -330.8981407
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      146
    </td>
    
    <td>
      2167.92
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      841.548
    </td>
    
    <td>
    </td>
    
    <td>
      0.2201494
    </td>
    
    <td>
      -331.2662873
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      149
    </td>
    
    <td>
      2180.73
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      827.468
    </td>
    
    <td>
    </td>
    
    <td>
      0.220208326
    </td>
    
    <td>
      -331.2153431
    </td>
  </tr>
  
  <tr style="background-color: yellow;">
    <td>
      6
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      -8.0E-08
    </td>
    
    <td>
      0.2203
    </td>
    
    <td>
      -331.37
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 3<br /></span></strong></span>The following table shows details for calculating the performance of each polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col span="16" /> </colgroup> <tr class="headerrow">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Eq0
    </td>
    
    <td>
      Diff 0
    </td>
    
    <td>
      Eq1
    </td>
    
    <td>
      Diff 1
    </td>
    
    <td>
      Eq2
    </td>
    
    <td>
      Diff 2
    </td>
    
    <td>
      Eq3
    </td>
    
    <td>
      Diff 3
    </td>
    
    <td>
      Eq4
    </td>
    
    <td>
      Diff 4
    </td>
    
    <td>
      Eq5
    </td>
    
    <td>
      Diff 5
    </td>
    
    <td>
      Eq6
    </td>
    
    <td>
      Diff 6
    </td>
  </tr>
  
  <tr>
    <td>
      150
    </td>
    
    <td>
      2187.85
    </td>
    
    <td>
      150
    </td>
    
    <td>
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.39
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.19
    </td>
    
    <td style="background-color: yellow;">
      150
    </td>
    
    <td style="background-color: yellow;">
      0.05
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.39
    </td>
    
    <td>
      151
    </td>
    
    <td>
      0.57
    </td>
    
    <td style="background-color: yellow;">
      150
    </td>
    
    <td style="background-color: yellow;">
      0.23
    </td>
  </tr>
  
  <tr>
    <td>
      149
    </td>
    
    <td>
      2180.73
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.57
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.18
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.75
    </td>
    
    <td style="background-color: yellow;">
      <span style="color: #ff0000;">148</span>
    </td>
    
    <td style="background-color: yellow;">
      0.52
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.18
    </td>
    
    <td>
      149
    </td>
    
    <td>
    </td>
    
    <td style="background-color: yellow;">
      149
    </td>
    
    <td style="background-color: yellow;">
      0.34
    </td>
  </tr>
  
  <tr>
    <td>
      148
    </td>
    
    <td>
      2178.54
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.34
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.23
    </td>
    
    <td style="background-color: yellow;">
      148
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.34
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.52
    </td>
    
    <td style="background-color: yellow;">
      148
    </td>
    
    <td style="background-color: yellow;">
      0.18
    </td>
  </tr>
  
  <tr>
    <td>
      147
    </td>
    
    <td>
      2173.86
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.08
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.31
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.26
    </td>
    
    <td style="background-color: yellow;">
      147
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.31
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.49
    </td>
    
    <td style="background-color: yellow;">
      147
    </td>
    
    <td style="background-color: yellow;">
      0.15
    </td>
  </tr>
  
  <tr>
    <td>
      146
    </td>
    
    <td>
      2167.92
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.39
    </td>
    
    <td>
      146
    </td>
    
    <td>
    </td>
    
    <td>
      145
    </td>
    
    <td>
      0.56
    </td>
    
    <td style="background-color: yellow;">
      146
    </td>
    
    <td style="background-color: yellow;">
      0.33
    </td>
    
    <td>
      146
    </td>
    
    <td>
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.18
    </td>
    
    <td style="background-color: yellow;">
      146
    </td>
    
    <td style="background-color: yellow;">
      0.15
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      1961.01
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.45
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td style="background-color: yellow;">
      100
    </td>
    
    <td style="background-color: yellow;">
      0.18
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.45
    </td>
    
    <td>
      101
    </td>
    
    <td>
      0.61
    </td>
    
    <td style="background-color: yellow;">
      100
    </td>
    
    <td style="background-color: yellow;">
      0.33
    </td>
  </tr>
  
  <tr>
    <td>
      50
    </td>
    
    <td>
      1732.35
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.4
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.11
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.21
    </td>
    
    <td style="background-color: yellow;">
      50
    </td>
    
    <td style="background-color: yellow;">
      0.08
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.11
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.26
    </td>
    
    <td style="background-color: yellow;">
      50
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1505.41
    </td>
    
    <td>
    </td>
    
    <td>
      0.42
    </td>
    
    <td>
    </td>
    
    <td>
      0.15
    </td>
    
    <td>
    </td>
    
    <td>
      0.05
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
    
    <td>
    </td>
    
    <td>
      0.15
    </td>
    
    <td>
    </td>
    
    <td>
      0.29
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td style="background-color: yellow;">
      0.09
    </td>
  </tr>
  
  <tr>
    <td>
      -50
    </td>
    
    <td>
      1277.65
    </td>
    
    <td>
      -51
    </td>
    
    <td>
      0.62
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.06
    </td>
    
    <td style="background-color: yellow;">
      -50
    </td>
    
    <td style="background-color: yellow;">
      0.04
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.13
    </td>
    
    <td style="background-color: yellow;">
      -50
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1050.22
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      0.75
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td style="background-color: yellow;">
      -100
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.05
    </td>
    
    <td style="background-color: yellow;">
      -100
    </td>
    
    <td style="background-color: yellow;">
      0.09
    </td>
  </tr>
  
  <tr>
    <td>
      -120
    </td>
    
    <td>
      959.43
    </td>
    
    <td>
      -121
    </td>
    
    <td>
      0.76
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.06
    </td>
    
    <td style="background-color: yellow;">
      -120
    </td>
    
    <td style="background-color: yellow;">
      0.01
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.06
    </td>
    
    <td style="background-color: yellow;">
      -120
    </td>
    
    <td style="background-color: yellow;">
      0.08
    </td>
  </tr>
  
  <tr>
    <td>
      -135
    </td>
    
    <td>
      891.52
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      0.73
    </td>
    
    <td>
      -135
    </td>
    
    <td>
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.15
    </td>
    
    <td style="background-color: yellow;">
      -135
    </td>
    
    <td style="background-color: yellow;">
      0.08
    </td>
    
    <td>
      -135
    </td>
    
    <td>
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.1
    </td>
    
    <td style="background-color: yellow;">
      -135
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
      -146
    </td>
    
    <td>
      841.55
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.75
    </td>
    
    <td>
      -146
    </td>
    
    <td>
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.18
    </td>
    
    <td style="background-color: yellow;">
      -146
    </td>
    
    <td style="background-color: yellow;">
      0.1
    </td>
    
    <td>
      -146
    </td>
    
    <td>
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.1
    </td>
    
    <td style="background-color: yellow;">
      -146
    </td>
    
    <td style="background-color: yellow;">
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
      -147
    </td>
    
    <td>
      836.76
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.8
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.13
    </td>
    
    <td style="background-color: yellow;">
      -147
    </td>
    
    <td style="background-color: yellow;">
      0.04
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.05
    </td>
    
    <td style="background-color: yellow;">
      -147
    </td>
    
    <td style="background-color: yellow;">
      0.09
    </td>
  </tr>
  
  <tr>
    <td>
      -148
    </td>
    
    <td>
      832.02
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.85
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.08
    </td>
    
    <td style="background-color: yellow;">
      -148
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -148
    </td>
    
    <td>
    </td>
    
    <td style="background-color: yellow;">
      -148
    </td>
    
    <td style="background-color: yellow;">
      0.13
    </td>
  </tr>
  
  <tr>
    <td>
      -149
    </td>
    
    <td>
      827.47
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.85
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.09
    </td>
    
    <td style="background-color: yellow;">
      -149
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -149
    </td>
    
    <td>
    </td>
    
    <td style="background-color: yellow;">
      -149
    </td>
    
    <td style="background-color: yellow;">
      0.13
    </td>
  </tr>
  
  <tr>
    <td>
      -150
    </td>
    
    <td>
      826.8
    </td>
    
    <td>
      -150
    </td>
    
    <td>
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.75
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.94
    </td>
    
    <td style="background-color: yellow;">
      <span style="color: #ff0000;">-149</span>
    </td>
    
    <td style="background-color: yellow;">
      0.85
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.75
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.85
    </td>
    
    <td style="background-color: yellow;">
      <span style="color: #ff0000;">-149</span>
    </td>
    
    <td style="background-color: yellow;">
      0.72
    </td>
  </tr>
  
  <tr>
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      8.05
    </td>
    
    <td>
       
    </td>
    
    <td>
      3.04
    </td>
    
    <td>
       
    </td>
    
    <td>
      3.94
    </td>
    
    <td>
       
    </td>
    
    <td style="background-color: lightgreen;">
      2.37
    </td>
    
    <td>
       
    </td>
    
    <td>
      3.04
    </td>
    
    <td>
       
    </td>
    
    <td>
      4.26
    </td>
    
    <td>
       
    </td>
    
    <td style="background-color: lightgreen;">
      2.85
    </td>
  </tr>
</table>

The table above shows two polynomial functions (see highlighted columns) that offers the best performance :

<li style="text-align: justify;">
  Function #3 (which has an order of 1) and a sum of <span style="color: #000000; background-color: lightgreen;">2.37</span>.
</li>
<li style="text-align: justify;">
  Function #6 (which has an order of 2) and a sum of <span style="color: #000000; background-color: lightgreen;">2.85</span>.
</li>

Even if function #6 has a sum higher than function #3, the accuracy of function #3 is better since only a single control point does not match the expected values. For example, function #3 evaluates a pwm of 2180.73 µs to 148 while function #6 evaluates to 149 which is correct.

The following polynomial function offers the best performance to compute the _Spektrum DX9 RC Transmitter_ value from the _Orange R620X Rx_ pulse length:

<p class="polynomialfunction">
  f(x) = -8.0e-8*x<sup>2</sup> + 0.2203*x – 331.37
</p>

Download the 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1618/" rel="nofollow"> Spektrum DX9 Tx & Orange R620X Rx (402 downloads) </a> full data capture.

## <span id="Spektrum_DX9_Tx_Spektrum_AR8000_Rx">Spektrum DX9 Tx & Spektrum AR8000 Rx</span>

<div id='gallery-9' class='gallery galleryid-1357 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg" title="Spektrum DX9 9-ch RC Tx" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx-150x150.jpg" width="150" height="150" alt="Spektrum DX9 9-ch RC Tx" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1587">
      <span class="imagecaption">Spektrum DX9 9-ch RC Tx</span><br /> <span class="imagedescription">Spektrum DX9 9-ch RC Tx</span><br />
    </dd>
  </dl>
  
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1.jpg" title="Spektrum AR8000 Rx" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1-150x150.jpg" width="150" height="150" alt="Spektrum AR8000 Rx" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1776">
      <span class="imagecaption">Spektrum AR8000 Rx</span><br /> <span class="imagedescription">Spektrum AR8000 Rx</span><br />
    </dd>
  </dl>
  
  <br style='clear: both' />
</div>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 1<br /></span></strong></span>The Spektrum DX9 Tx & Spektrum AR8000 Rx shows a PWM range from **921 µs** to **2129 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="6" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="6">
      Spektrum DX9 Tx & Spektrum AR8000 Rx
    </td>
  </tr>
  
  <tr class="headerrow" data-headerrow="true">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Min
    </td>
    
    <td>
      Max
    </td>
    
    <td>
      Width
    </td>
    
    <td>
      Middle
    </td>
  </tr>
  
  <tr>
    <td>
      150
    </td>
    
    <td>
      2123.57
    </td>
    
    <td>
      2119
    </td>
    
    <td>
      2129
    </td>
    
    <td>
      10
    </td>
    
    <td>
      2124.0
    </td>
  </tr>
  
  <tr>
    <td>
      149
    </td>
    
    <td>
      2119.40
    </td>
    
    <td>
      2113
    </td>
    
    <td>
      2124
    </td>
    
    <td>
      11
    </td>
    
    <td>
      2118.5
    </td>
  </tr>
  
  <tr>
    <td>
      148
    </td>
    
    <td>
      2115.38
    </td>
    
    <td>
      2109
    </td>
    
    <td>
      2121
    </td>
    
    <td>
      12
    </td>
    
    <td>
      2115.0
    </td>
  </tr>
  
  <tr>
    <td>
      147
    </td>
    
    <td>
      2111.07
    </td>
    
    <td>
      2105
    </td>
    
    <td>
      2116
    </td>
    
    <td>
      11
    </td>
    
    <td>
      2110.5
    </td>
  </tr>
  
  <tr>
    <td>
      146
    </td>
    
    <td>
      2106.94
    </td>
    
    <td>
      2101
    </td>
    
    <td>
      2111
    </td>
    
    <td>
      10
    </td>
    
    <td>
      2106.0
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      1923.78
    </td>
    
    <td>
      1918
    </td>
    
    <td>
      1929
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1923.5
    </td>
  </tr>
  
  <tr>
    <td>
      50
    </td>
    
    <td>
      1724.52
    </td>
    
    <td>
      1720
    </td>
    
    <td>
      1729
    </td>
    
    <td>
      9
    </td>
    
    <td>
      1724.5
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1525.23
    </td>
    
    <td>
      1520
    </td>
    
    <td>
      1531
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1525.5
    </td>
  </tr>
  
  <tr>
    <td>
      -50
    </td>
    
    <td>
      1325.74
    </td>
    
    <td>
      1319
    </td>
    
    <td>
      1331
    </td>
    
    <td>
      12
    </td>
    
    <td>
      1325.0
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1126.63
    </td>
    
    <td>
      1122
    </td>
    
    <td>
      1132
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1127.0
    </td>
  </tr>
  
  <tr>
    <td>
      -120
    </td>
    
    <td>
      1047.06
    </td>
    
    <td>
      1041
    </td>
    
    <td>
      1051
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1046.0
    </td>
  </tr>
  
  <tr>
    <td>
      -135
    </td>
    
    <td>
      987.40
    </td>
    
    <td>
      983
    </td>
    
    <td>
      992
    </td>
    
    <td>
      9
    </td>
    
    <td>
      987.5
    </td>
  </tr>
  
  <tr>
    <td>
      -146
    </td>
    
    <td>
      943.40
    </td>
    
    <td>
      939
    </td>
    
    <td>
      948
    </td>
    
    <td>
      9
    </td>
    
    <td>
      943.5
    </td>
  </tr>
  
  <tr>
    <td>
      -147
    </td>
    
    <td>
      939.48
    </td>
    
    <td>
      935
    </td>
    
    <td>
      944
    </td>
    
    <td>
      9
    </td>
    
    <td>
      939.5
    </td>
  </tr>
  
  <tr>
    <td>
      -148
    </td>
    
    <td>
      935.34
    </td>
    
    <td>
      929
    </td>
    
    <td>
      940
    </td>
    
    <td>
      11
    </td>
    
    <td>
      934.5
    </td>
  </tr>
  
  <tr>
    <td>
      -149
    </td>
    
    <td>
      931.24
    </td>
    
    <td>
      926
    </td>
    
    <td>
      936
    </td>
    
    <td>
      10
    </td>
    
    <td>
      931.0
    </td>
  </tr>
  
  <tr>
    <td>
      -150
    </td>
    
    <td>
      927.43
    </td>
    
    <td>
      921
    </td>
    
    <td>
      932
    </td>
    
    <td>
      11
    </td>
    
    <td>
      926.5
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 2<br /></span></strong></span>From these values, I extracted the following polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Polynomial Equation
    </td>
    
    <td>
      Py1
    </td>
    
    <td>
      Px1
    </td>
    
    <td>
      Py2
    </td>
    
    <td>
      Px2
    </td>
    
    <td>
      a2
    </td>
    
    <td>
      a1
    </td>
    
    <td>
      a0
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      150
    </td>
    
    <td>
      2123.57
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      927.43
    </td>
    
    <td>
    </td>
    
    <td>
      0.25080676
    </td>
    
    <td>
      -382.605213
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      146
    </td>
    
    <td>
      2106.94
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      987.40
    </td>
    
    <td>
    </td>
    
    <td>
      0.25099594
    </td>
    
    <td>
      -382.8344
    </td>
  </tr>
  
  <tr style="background-color: yellow;">
    <td>
      2
    </td>
    
    <td>
      100
    </td>
    
    <td>
      1923.78
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      1126.63
    </td>
    
    <td>
    </td>
    
    <td>
      0.25089444
    </td>
    
    <td>
      -382.665703
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      148
    </td>
    
    <td>
      2115.38
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      935.34
    </td>
    
    <td>
    </td>
    
    <td>
      0.25083895
    </td>
    
    <td>
      -382.619708
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      146
    </td>
    
    <td>
      2106.94
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      943.40
    </td>
    
    <td>
    </td>
    
    <td>
      0.25095742
    </td>
    
    <td>
      -382.75323
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      149
    </td>
    
    <td>
      2119.40
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      931.24
    </td>
    
    <td>
    </td>
    
    <td>
      0.25080797
    </td>
    
    <td>
      -382.563419
    </td>
  </tr>
  
  <tr style="background-color: yellow;">
    <td>
      6
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      -1.0E-07
    </td>
    
    <td>
      0.2513
    </td>
    
    <td>
      -382.95
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 3<br /></span></strong></span>Again, calculating the performance of each polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="16" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Tx
    </td>
    
    <td>
      Average PWM
    </td>
    
    <td>
      Eq0
    </td>
    
    <td>
      Diff 0
    </td>
    
    <td>
      Eq1
    </td>
    
    <td>
      Diff 1
    </td>
    
    <td>
      Eq2
    </td>
    
    <td>
      Diff 2
    </td>
    
    <td>
      Eq3
    </td>
    
    <td>
      Diff 3
    </td>
    
    <td>
      Eq4
    </td>
    
    <td>
      Diff 4
    </td>
    
    <td>
      Eq5
    </td>
    
    <td>
      Diff 5
    </td>
    
    <td>
      Eq6
    </td>
    
    <td>
      Diff 6
    </td>
  </tr>
  
  <tr>
    <td>
      150
    </td>
    
    <td>
      2123.57
    </td>
    
    <td>
      150
    </td>
    
    <td>
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.17
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.13
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.17
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      150
    </td>
    
    <td>
      0.25
    </td>
  </tr>
  
  <tr>
    <td>
      149
    </td>
    
    <td>
      2119.40
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.13
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.08
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.13
    </td>
    
    <td>
      149
    </td>
    
    <td>
    </td>
    
    <td>
      149
    </td>
    
    <td>
      0.21
    </td>
  </tr>
  
  <tr>
    <td>
      148
    </td>
    
    <td>
      2115.38
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.12
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
      148
    </td>
    
    <td>
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.12
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      148
    </td>
    
    <td>
      0.2
    </td>
  </tr>
  
  <tr>
    <td>
      147
    </td>
    
    <td>
      2111.07
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.14
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.08
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.09
    </td>
    
    <td>
      147
    </td>
    
    <td>
      0.12
    </td>
  </tr>
  
  <tr>
    <td>
      146
    </td>
    
    <td>
      2106.94
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.17
    </td>
    
    <td>
      146
    </td>
    
    <td>
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.12
    </td>
    
    <td>
      146
    </td>
    
    <td>
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.13
    </td>
    
    <td>
      146
    </td>
    
    <td>
      0.08
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      1923.78
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.11
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.13
    </td>
  </tr>
  
  <tr>
    <td>
      50
    </td>
    
    <td>
      1724.52
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.08
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      50
    </td>
    
    <td>
      0.13
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1525.23
    </td>
    
    <td>
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
    </td>
    
    <td>
      0.11
    </td>
  </tr>
  
  <tr>
    <td>
      -50
    </td>
    
    <td>
      1325.74
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.08
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1126.63
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.05
    </td>
  </tr>
  
  <tr>
    <td>
      -120
    </td>
    
    <td>
      1047.06
    </td>
    
    <td>
      -120
    </td>
    
    <td>
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      0.07
    </td>
  </tr>
  
  <tr>
    <td>
      -135
    </td>
    
    <td>
      987.40
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -135
    </td>
    
    <td>
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.06
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.09
    </td>
    
    <td>
      -135
    </td>
    
    <td>
      0.09
    </td>
  </tr>
  
  <tr>
    <td>
      -146
    </td>
    
    <td>
      943.40
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -146
    </td>
    
    <td>
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -146
    </td>
    
    <td>
      0.04
    </td>
  </tr>
  
  <tr>
    <td>
      -147
    </td>
    
    <td>
      939.48
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      0.05
    </td>
  </tr>
  
  <tr>
    <td>
      -148
    </td>
    
    <td>
      935.34
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.07
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -148
    </td>
    
    <td>
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      0.01
    </td>
  </tr>
  
  <tr>
    <td>
      -149
    </td>
    
    <td>
      931.24
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.1
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.03
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -149
    </td>
    
    <td>
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      0.02
    </td>
  </tr>
  
  <tr>
    <td>
      -150
    </td>
    
    <td>
      927.43
    </td>
    
    <td>
      -150
    </td>
    
    <td>
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.05
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.02
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.01
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.04
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      0.03
    </td>
  </tr>
  
  <tr>
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.93
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.95
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.62
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.67
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.75
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.78
    </td>
    
    <td>
       
    </td>
    
    <td>
      1.59
    </td>
  </tr>
</table>

The table above shows two polynomial functions (see highlighted columns) that offers the best performance :

<li style="text-align: justify;">
  Function #2 (which has an order of 1) and a sum of <span style="color: #000000; background-color: lightgreen;">0.62</span>.
</li>
<li style="text-align: justify;">
  Function #6 (which has an order of 2) and a sum of <span style="color: #000000; background-color: lightgreen;">1.59</span>.
</li>

Function #2 offers the best performance. It is even better than the polynomial function with an order of 3. All control points matches the expected values. This means that Spektrum AR8000 Rx delivers near-perfect and linear PWM values for all given transmitter values.

The following polynomial function offers the best performance to compute the Spektrum DX9 RC Transmitter value from the Spektrum AR8000 Rx pulse length:

<p class="polynomialfunction">
  f(x) = 0.25089444*x – 382.665703
</p>

Download the 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1620/" rel="nofollow"> Spektrum DX9 Tx & Spektrum AR8000 Rx (365 downloads) </a> full data capture.

## <span id="Tactic_TTX600_Tx_Tactic_TR624_Rx">Tactic TTX600 Tx & Tactic TR624 Rx</span>

<div id='gallery-10' class='gallery galleryid-1357 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx.jpg" title="Tactic TTX600 6-ch Tx.jpg" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx-150x150.jpg" width="150" height="150" alt="Tactic TTX600 6-ch Tx.jpg" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1633">
      <span class="imagecaption">Tactic TTX600 6-ch Tx.jpg</span><br /> <span class="imagedescription">Tactic TTX600 6-ch Tx.jpg</span><br />
    </dd>
  </dl>
  
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx.jpg" title="Tactic TR624 6-ch Rx" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx-150x150.jpg" width="150" height="150" alt="Tactic TR624 6-ch Rx" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1634">
      <span class="imagecaption">Tactic TR624 6-ch Rx</span><br /> <span class="imagedescription">Tactic TR624 6-ch Rx</span><br />
    </dd>
  </dl>
  
  <br style='clear: both' />
</div>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Notes:<br /></span></strong></span>The TTX600 transmitter is not digital. This means that it is hard to reproduce the exact behavior every time. As you can see the result are pretty erratic. Each different channel has a different behavior.

For extracting the data, I assumed that moving _**any**_ sticks to the top, bottom, left and right position would always match a perfect 100% (or -100%). Other values (+60%, -60%) are based on the documentation manual which states that high and low dual rates are based on a 100% and 60% ratio.

<p class="pleasenote" data-pleasenote="true">
  Note that each channel section are identified by a unique color which helps to identify the source of each Polynomial Equation.
</p>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 1<br /></span></strong></span>The Tactic TTX600 Tx & Tactic TR624 Rx shows a PWM range from **984 µs** to **2030 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="7" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="7">
      Tactic TTX600 tx & Tactic TR624
    </td>
  </tr>
  
  <tr class="headerrow" data-headerrow="true">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Min
    </td>
    
    <td>
      Max
    </td>
    
    <td>
      Width
    </td>
    
    <td>
      Middle
    </td>
    
    <td>
      Comment
    </td>
  </tr>
  
  <tr style="background-color: lightblue;">
    <td>
      100
    </td>
    
    <td>
      1969.01
    </td>
    
    <td>
      1962
    </td>
    
    <td>
      1973
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1967.5
    </td>
    
    <td>
      CH1 +100
    </td>
  </tr>
  
  <tr style="background-color: lightblue;">
    <td>
      60
    </td>
    
    <td>
      1793.74
    </td>
    
    <td>
      1789
    </td>
    
    <td>
      1800
    </td>
    
    <td>
      11
    </td>
    
    <td>
      1794.5
    </td>
    
    <td>
      CH1 +60
    </td>
  </tr>
  
  <tr style="background-color: lightblue;">
    <td>
    </td>
    
    <td>
      1502.62
    </td>
    
    <td>
      1498
    </td>
    
    <td>
      1508
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1503.0
    </td>
    
    <td>
      CH1 0
    </td>
  </tr>
  
  <tr style="background-color: lightblue;">
    <td>
      -60
    </td>
    
    <td>
      1214.30
    </td>
    
    <td>
      1209
    </td>
    
    <td>
      1219
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1214.0
    </td>
    
    <td>
      CH1 -60
    </td>
  </tr>
  
  <tr style="background-color: lightblue;">
    <td>
      -100
    </td>
    
    <td>
      1042.41
    </td>
    
    <td>
      1037
    </td>
    
    <td>
      1046
    </td>
    
    <td>
      9
    </td>
    
    <td>
      1041.5
    </td>
    
    <td>
      CH1 -100
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      100
    </td>
    
    <td>
      2022.89
    </td>
    
    <td>
      2017
    </td>
    
    <td>
      2030
    </td>
    
    <td>
      13
    </td>
    
    <td>
      2023.5
    </td>
    
    <td>
      CH2 +100
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      60
    </td>
    
    <td>
      1838.71
    </td>
    
    <td>
      1834
    </td>
    
    <td>
      1844
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1839.0
    </td>
    
    <td>
      CH2 +60
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
    </td>
    
    <td>
      1530.52
    </td>
    
    <td>
      1526
    </td>
    
    <td>
      1536
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1531.0
    </td>
    
    <td>
      CH2 0
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      -60
    </td>
    
    <td>
      1230.26
    </td>
    
    <td>
      1226
    </td>
    
    <td>
      1235
    </td>
    
    <td>
      9
    </td>
    
    <td>
      1230.5
    </td>
    
    <td>
      CH2 -60
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      -100
    </td>
    
    <td>
      1048.09
    </td>
    
    <td>
      1043
    </td>
    
    <td>
      1052
    </td>
    
    <td>
      9
    </td>
    
    <td>
      1047.5
    </td>
    
    <td>
      CH2 -100
    </td>
  </tr>
  
  <tr style="background-color: #ffffaf;">
    <td>
      100
    </td>
    
    <td>
      2010.15
    </td>
    
    <td>
      2004
    </td>
    
    <td>
      2016
    </td>
    
    <td>
      12
    </td>
    
    <td>
      2010.0
    </td>
    
    <td>
      CH5 +100
    </td>
  </tr>
  
  <tr style="background-color: #ffffaf;">
    <td>
      -100
    </td>
    
    <td>
      989.31
    </td>
    
    <td>
      985
    </td>
    
    <td>
      995
    </td>
    
    <td>
      10
    </td>
    
    <td>
      990.0
    </td>
    
    <td>
      CH5 -100
    </td>
  </tr>
  
  <tr style="background-color: #ffc896;">
    <td>
      100
    </td>
    
    <td>
      2010.39
    </td>
    
    <td>
      2004
    </td>
    
    <td>
      2016
    </td>
    
    <td>
      12
    </td>
    
    <td>
      2010.0
    </td>
    
    <td>
      CH6 +100
    </td>
  </tr>
  
  <tr style="background-color: #ffc896;">
    <td>
      -100
    </td>
    
    <td>
      989.40
    </td>
    
    <td>
      984
    </td>
    
    <td>
      994
    </td>
    
    <td>
      10
    </td>
    
    <td>
      989.0
    </td>
    
    <td>
      CH6 -100
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 2<br /></span></strong></span>From these values, I extracted the following polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Polynomial Equation
    </td>
    
    <td>
      Py1
    </td>
    
    <td>
      Px1
    </td>
    
    <td>
      Py2
    </td>
    
    <td>
      Px2
    </td>
    
    <td>
      a2
    </td>
    
    <td>
      a1
    </td>
    
    <td>
      a0
    </td>
  </tr>
  
  <tr style="background-color: #ffffaf;">
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2010.152
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      989.308
    </td>
    
    <td>
    </td>
    
    <td>
      0.19591632
    </td>
    
    <td>
      -293.821583
    </td>
  </tr>
  
  <tr style="background-color: #ffc896;">
    <td>
      1
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2010.392
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      989.402
    </td>
    
    <td>
    </td>
    
    <td>
      0.1958883
    </td>
    
    <td>
      -293.81228
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      2
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2022.892
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      1048.088
    </td>
    
    <td>
    </td>
    
    <td>
      0.20516945
    </td>
    
    <td>
      -315.035638
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      3
    </td>
    
    <td>
      60
    </td>
    
    <td>
      1838.708
    </td>
    
    <td>
      -60
    </td>
    
    <td>
      1230.256
    </td>
    
    <td>
    </td>
    
    <td>
      0.1972218
    </td>
    
    <td>
      -302.633306
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      4
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2022.892
    </td>
    
    <td>
      -60
    </td>
    
    <td>
      1230.256
    </td>
    
    <td>
    </td>
    
    <td>
      0.2018581
    </td>
    
    <td>
      -308.337143
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      5
    </td>
    
    <td>
      60
    </td>
    
    <td>
      1838.708
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      1048.088
    </td>
    
    <td>
    </td>
    
    <td>
      0.20237282
    </td>
    
    <td>
      -312.104526
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td colspan="4">
      all control points
    </td>
    
    <td>
      9.00E-06
    </td>
    
    <td>
      0.1755
    </td>
    
    <td>
      -287.34
    </td>
  </tr>
  
  <tr>
    <td style="background-color: lightblue;">
      7
    </td>
    
    <td style="background-color: lightblue;" colspan="4">
      CH1 control points
    </td>
    
    <td style="background-color: lightblue;">
      -3.00E-06
    </td>
    
    <td style="background-color: lightblue;">
      0.2221
    </td>
    
    <td style="background-color: lightblue;">
      -327.22
    </td>
  </tr>
  
  <tr style="background-color: #ffc8c8;">
    <td>
      8
    </td>
    
    <td colspan="4">
      CH2 control points
    </td>
    
    <td>
      -3.00E-06
    </td>
    
    <td>
      0.2135
    </td>
    
    <td>
      -318.97
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 3 (for CH1)<br /></span></strong></span>The following table shows details for calculating the performance of each polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="16" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Eq2
    </td>
    
    <td>
      Diff 2
    </td>
    
    <td>
      Eq3
    </td>
    
    <td>
      Diff 3
    </td>
    
    <td>
      Eq4
    </td>
    
    <td>
      Diff 4
    </td>
    
    <td>
      Eq5
    </td>
    
    <td>
      Diff 5
    </td>
    
    <td>
      Eq6
    </td>
    
    <td>
      Diff 6
    </td>
    
    <td>
      Eq7
    </td>
    
    <td>
      Diff 7
    </td>
    
    <td>
      Eq8
    </td>
    
    <td>
      Diff 8
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      1969.01
    </td>
    
    <td>
      89
    </td>
    
    <td>
      11.05
    </td>
    
    <td>
      86
    </td>
    
    <td>
      14.3
    </td>
    
    <td>
      89
    </td>
    
    <td>
      10.88
    </td>
    
    <td>
      86
    </td>
    
    <td>
      13.63
    </td>
    
    <td>
      93
    </td>
    
    <td>
      6.89
    </td>
    
    <td style="background-color: yellow;">
      98
    </td>
    
    <td style="background-color: yellow;">
      1.53
    </td>
    
    <td>
      90
    </td>
    
    <td>
      10.22
    </td>
  </tr>
  
  <tr>
    <td>
      60
    </td>
    
    <td>
      1793.74
    </td>
    
    <td>
      53
    </td>
    
    <td>
      7.02
    </td>
    
    <td>
      51
    </td>
    
    <td>
      8.87
    </td>
    
    <td>
      54
    </td>
    
    <td>
      6.26
    </td>
    
    <td>
      51
    </td>
    
    <td>
      9.1
    </td>
    
    <td>
      56
    </td>
    
    <td>
      3.58
    </td>
    
    <td style="background-color: yellow;">
      62
    </td>
    
    <td style="background-color: yellow;">
      1.52
    </td>
    
    <td>
      54
    </td>
    
    <td>
      5.66
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1502.62
    </td>
    
    <td>
      -7
    </td>
    
    <td>
      6.74
    </td>
    
    <td>
      -6
    </td>
    
    <td>
      6.28
    </td>
    
    <td>
      -5
    </td>
    
    <td>
      5.02
    </td>
    
    <td>
      -8
    </td>
    
    <td>
      8.02
    </td>
    
    <td>
      -3
    </td>
    
    <td>
      3.31
    </td>
    
    <td style="background-color: yellow;">
    </td>
    
    <td style="background-color: yellow;">
      0.26
    </td>
    
    <td>
      -5
    </td>
    
    <td>
      4.93
    </td>
  </tr>
  
  <tr>
    <td>
      -60
    </td>
    
    <td>
      1214.30
    </td>
    
    <td>
      -66
    </td>
    
    <td>
      5.9
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      3.15
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      3.22
    </td>
    
    <td>
      -66
    </td>
    
    <td>
      6.36
    </td>
    
    <td>
      -61
    </td>
    
    <td>
      0.96
    </td>
    
    <td style="background-color: yellow;">
      -62
    </td>
    
    <td style="background-color: yellow;">
      1.95
    </td>
    
    <td>
      -64
    </td>
    
    <td>
      4.14
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1042.41
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      1.17
    </td>
    
    <td>
      -97
    </td>
    
    <td>
      2.95
    </td>
    
    <td>
      -98
    </td>
    
    <td>
      2.08
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      1.15
    </td>
    
    <td>
      -95
    </td>
    
    <td>
      5.38
    </td>
    
    <td style="background-color: yellow;">
      -99
    </td>
    
    <td style="background-color: yellow;">
      1.04
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.32
    </td>
  </tr>
  
  <tr>
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      31.88
    </td>
    
    <td>
       
    </td>
    
    <td>
      35.55
    </td>
    
    <td>
       
    </td>
    
    <td>
      27.46
    </td>
    
    <td>
       
    </td>
    
    <td>
      38.26
    </td>
    
    <td>
       
    </td>
    
    <td>
      20.12
    </td>
    
    <td>
       
    </td>
    
    <td style="background-color: lightgreen;">
      6.3
    </td>
    
    <td>
       
    </td>
    
    <td>
      25.28
    </td>
  </tr>
</table>

<span style="text-decoration: underline;"><strong><span style="font-size: 16pt;">Table 3 (for CH2)<br /></span></strong></span>The following table shows details for calculating the performance of each polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> <col /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Tx
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Eq2
    </td>
    
    <td>
      Diff 2
    </td>
    
    <td>
      Eq3
    </td>
    
    <td>
      Diff 3
    </td>
    
    <td>
      Eq4
    </td>
    
    <td>
      Diff 4
    </td>
    
    <td>
      Eq5
    </td>
    
    <td>
      Diff 5
    </td>
    
    <td>
      Eq6
    </td>
    
    <td>
      Diff 6
    </td>
    
    <td>
      Eq7
    </td>
    
    <td>
      Diff 7
    </td>
    
    <td>
      Eq8
    </td>
    
    <td>
      Diff 8
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      2022.89
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      96
    </td>
    
    <td>
      3.67
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      97
    </td>
    
    <td>
      2.73
    </td>
    
    <td>
      105
    </td>
    
    <td>
      4.51
    </td>
    
    <td>
      110
    </td>
    
    <td>
      9.79
    </td>
    
    <td style="background-color: yellow;">
      101
    </td>
    
    <td style="background-color: yellow;">
      0.64
    </td>
  </tr>
  
  <tr>
    <td>
      60
    </td>
    
    <td>
      1838.71
    </td>
    
    <td>
      62
    </td>
    
    <td>
      2.21
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      63
    </td>
    
    <td>
      2.82
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      66
    </td>
    
    <td>
      5.78
    </td>
    
    <td>
      71
    </td>
    
    <td>
      11.01
    </td>
    
    <td style="background-color: yellow;">
      63
    </td>
    
    <td style="background-color: yellow;">
      3.45
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1530.52
    </td>
    
    <td>
      -1
    </td>
    
    <td>
      1.02
    </td>
    
    <td>
      -1
    </td>
    
    <td>
      0.78
    </td>
    
    <td>
      1
    </td>
    
    <td>
      0.61
    </td>
    
    <td>
      -2
    </td>
    
    <td>
      2.37
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2.35
    </td>
    
    <td>
      6
    </td>
    
    <td>
      5.68
    </td>
    
    <td style="background-color: yellow;">
      1
    </td>
    
    <td style="background-color: yellow;">
      0.77
    </td>
  </tr>
  
  <tr>
    <td>
      -60
    </td>
    
    <td>
      1230.26
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      2.62
    </td>
    
    <td>
      -60
    </td>
    
    <td>
    </td>
    
    <td>
      -60
    </td>
    
    <td>
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      3.13
    </td>
    
    <td>
      -58
    </td>
    
    <td>
      2.19
    </td>
    
    <td>
      -59
    </td>
    
    <td>
      1.48
    </td>
    
    <td style="background-color: yellow;">
      -61
    </td>
    
    <td style="background-color: yellow;">
      0.85
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      1048.09
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -96
    </td>
    
    <td>
      4.07
    </td>
    
    <td>
      -97
    </td>
    
    <td>
      3.23
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -94
    </td>
    
    <td>
      6.49
    </td>
    
    <td>
      -98
    </td>
    
    <td>
      2.26
    </td>
    
    <td style="background-color: yellow;">
      -98
    </td>
    
    <td style="background-color: yellow;">
      1.5
    </td>
  </tr>
  
  <tr>
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      5.85
    </td>
    
    <td>
       
    </td>
    
    <td>
      8.53
    </td>
    
    <td>
       
    </td>
    
    <td>
      6.66
    </td>
    
    <td>
       
    </td>
    
    <td>
      8.23
    </td>
    
    <td>
       
    </td>
    
    <td>
      21.31
    </td>
    
    <td>
       
    </td>
    
    <td>
      30.23
    </td>
    
    <td>
       
    </td>
    
    <td style="background-color: lightgreen;">
      7.21
    </td>
  </tr>
</table>

The two tables above shows two polynomial functions (see highlighted columns) that offers the best performance:

  * Function #7 (which has an order of 2) and a sum of <span style="color: #000000; background-color: lightgreen;">6.3</span>.
  * Function #8 (which has an order of 2) and a sum of <span style="color: #000000; background-color: lightgreen;">7.21</span>.
  * All polynomial function which has an order of 1 shows terrible prediction performance.

<p class="pleasenote" data-pleasenote="true">
  Note that best function for channel 1 (function #7) shows terrible results when used in calculations of channel 2. That is also for function 8. This means that there is no generic function that can be used for all channel situations. As a proof, function #6 which is based on all observed values for all channels shows terrible results.
</p>

In other words, reading the PWM length or the _Tactic TTX600 Tx & Tactic TR624 Rx combination_ can only be used for detecting if the sticks are &#8220;up&#8221;, &#8220;centered&#8221; or &#8220;down&#8221; but not really &#8220;how much up or down&#8221;.

The following polynomial functions offers the best performance to compute the Tactic TTX600 Tx transmitter value from the Tactic TR624 Rx pulse length:

Channel 1 :

<p class="polynomialfunction">
  f(x) = -3.0E-6*x<sup>2</sup> + 0.2221*x – 327.22
</p>

Channel 2 :

<p class="polynomialfunction">
  f(x) = -3.0E-6*x2 + 0.2135*x – 318.97
</p>

Download the 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1614/" rel="nofollow"> Tactic TTX600 Tx & Tactic TR624 Rx (390 downloads) </a> full data capture.

## <span id="CCPM_Servo_Tester">CCPM Servo Tester</span>

<div id='gallery-11' class='gallery galleryid-1357 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg" title="CCPM Servo Tester" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester-150x150.jpg" width="150" height="150" alt="CCPM Servo Tester" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg" rel="nolightbox" target="_blank">250x250</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1640">
      <span class="imagecaption">CCPM Servo Tester</span><br /> <span class="imagedescription">CCPM Servo Tester</span><br />
    </dd>
  </dl>
  
  <br style='clear: both' />
</div>

<span style="text-decoration: underline; font-size: 16pt;"><strong>Table 1</strong></span>  
The CCPM Servo Tester shows a PWM range from **900 µs** to **2210 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="7" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="7">
      CCPM Servo Tester
    </td>
  </tr>
  
  <tr class="headerrow" data-headerrow="true">
    <td>
      Value
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Min
    </td>
    
    <td>
      Max
    </td>
    
    <td>
      Width
    </td>
    
    <td>
      Middle
    </td>
    
    <td>
      Comment
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      2103.82
    </td>
    
    <td>
      2098
    </td>
    
    <td>
      2110
    </td>
    
    <td>
      12
    </td>
    
    <td>
      2104
    </td>
    
    <td>
      CW
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1504.75
    </td>
    
    <td>
      1501
    </td>
    
    <td>
      1511
    </td>
    
    <td>
      10
    </td>
    
    <td>
      1506
    </td>
    
    <td>
      CENTER
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      903.77
    </td>
    
    <td>
      900
    </td>
    
    <td>
      909
    </td>
    
    <td>
      9
    </td>
    
    <td>
      904.5
    </td>
    
    <td>
      CCW
    </td>
  </tr>
</table>

<p class="pleasenote" data-pleasenote="true">
  Note that values for the CCPM Server Tester (100, -100) are assumptions and represents clockwise and counterclockwise positions of the potentiometer. In fact, based on the observed PWM values, the values should be more in the (133, -133) range according the <em><a href="#Spektrum_DX9_Tx_Orange_R620X_Rx">Spektrum DX9 Tx & Orange R620X Rx</a></em> results or in (150, -150) range according the <em><a href="#Spektrum_DX9_Tx_Spektrum_AR8000_Rx">Spektrum DX9 Tx & Spektrum AR8000 Rx</a></em> results.
</p>

<span style="text-decoration: underline; font-size: 16pt;"><strong>Table 2</strong></span>  
From these values, I extracted the following polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Polynomial Equation
    </td>
    
    <td>
      Py1
    </td>
    
    <td>
      Px1
    </td>
    
    <td>
      Py2
    </td>
    
    <td>
      Px2
    </td>
    
    <td>
      a2
    </td>
    
    <td>
      a1
    </td>
    
    <td>
      a0
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2103.82
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      903.77
    </td>
    
    <td>
    </td>
    
    <td>
      0.16665945
    </td>
    
    <td>
      -250.62214
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      100
    </td>
    
    <td>
      2103.824
    </td>
    
    <td>
    </td>
    
    <td>
      1504.752
    </td>
    
    <td>
    </td>
    
    <td>
      0.16692484
    </td>
    
    <td>
      -251.180493
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      1504.752
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      903.772
    </td>
    
    <td>
    </td>
    
    <td>
      0.16639489
    </td>
    
    <td>
      -250.383041
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      4.0E-07
    </td>
    
    <td>
      0.1653
    </td>
    
    <td>
      -249.78
    </td>
  </tr>
</table>

<span style="text-decoration: underline; font-size: 16pt;"><strong>Table 3</strong></span>  
The following table shows details for calculating the performance of each polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="10" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>
      Value
    </td>
    
    <td>
      Avg PWM
    </td>
    
    <td>
      Eq0
    </td>
    
    <td>
      Diff 0
    </td>
    
    <td>
      Eq1
    </td>
    
    <td>
      Diff 1
    </td>
    
    <td>
      Eq2
    </td>
    
    <td>
      Diff 2
    </td>
    
    <td>
      Eq3
    </td>
    
    <td>
      Diff 3
    </td>
  </tr>
  
  <tr>
    <td>
      100
    </td>
    
    <td>
      2103.82
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.32
    </td>
    
    <td>
      100
    </td>
    
    <td>
      0.25
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      1504.75
    </td>
    
    <td>
    </td>
    
    <td>
      0.16
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      0.14
    </td>
  </tr>
  
  <tr>
    <td>
      -100
    </td>
    
    <td>
      903.77
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.32
    </td>
    
    <td>
      -100
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      0.06
    </td>
  </tr>
  
  <tr>
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.16
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.32
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.32
    </td>
    
    <td>
       
    </td>
    
    <td>
      0.45
    </td>
  </tr>
</table>

<p class="pleasenote" data-pleasenote="true">
  Note that only 3 control points are available which means that all performance calculations will always match 2/3 controls points (since the equation is derived from these 2 points). Performance calculations are irrelevant in this particular situation.
</p>

Even if the performance of function #3 seem to be the worst, it seems like it is the one that is the most promising since it takes into account all control points.

The following polynomial function offers the best performance to compute the _CCPM Servo Tester_ pulse length:

<p class="polynomialfunction">
  f(x) = 4.0E-07*x<sup>2</sup> + 0.1653*x – 249.78
</p>

Download the 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1616/" rel="nofollow"> CCPM Servo Tester (384 downloads) </a> full data capture.

 [1]: https://en.wikipedia.org/wiki/Pulse-width_modulation
 [2]: https://en.wikipedia.org/wiki/Servo_%28radio_control%29
 [3]: https://en.wikipedia.org/wiki/Servo_control
 [4]: https://www.arduino.cc/en/Main/ArduinoBoardNano
 [5]: https://en.wikipedia.org/wiki/Polynomial