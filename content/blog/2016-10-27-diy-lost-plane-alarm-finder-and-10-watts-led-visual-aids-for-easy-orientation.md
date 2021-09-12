---
title: DIY lost plane alarm finder and 10 watts LED visual aids for easy orientation
author: end2end
type: post
date: 2016-10-27T16:48:23+00:00
url: /diy-lost-plane-alarm-finder-and-10-watts-led-visual-aids-for-easy-orientation/
featured_image: /wp-content/uploads/2016/10/Arduino-Quadcopter-Controler-featured-672x378.jpg
hits:
  - 845
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Fritzing project:</p>
        <ul class="fa-ul">
        <li><a href="/download/2240/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2240" template="title"]</a></li>
        </ul><p class="nomarginbottom">Fritzing parts:</p>
        <ul class="fa-ul">
        <li><a href="/download/2237/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2237" template="title"]</a></li>
        <li><a href="/download/2235/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2235" template="title"]</a></li>
        <li><a href="/download/2233/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2233" template="title"]</a></li>
        </ul>
        <p class="nomarginbottom">Source code files:</p>
        <ul class="fa-ul">
        <li><a href="/download/2263/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2263" template="title"]</a></li>
        </ul>
        </div>
        
categories:
  - Model Aeronautics
tags:
  - arduino
  - diy
  - english
  - open source
  - RC

---
# <span id="Introduction">Introduction</span>

The reason I started this project is because I recently had a bad experience flying a quadcopter too far from me until I was not able to distinguish if the quad was facing me or not. It does not require much distance before a quadcopter looks like a tiny black dot in the sky. Basically, I lost orientation of the quad and I had to land way too far from my takeoff location.

I was in need of more tools (or more ways) to help myself when I will inevitably get into this situation again. The following project explains how I build a DIY solution to help a pilot know a quadcopter orientation when its far away from the point of view and easily locate the quadcopter in case of emergency landing.<!--more-->

# <span id="Background_story">Background story</span>

I have been flying planes for many years now and over time, I learned to increase my skills and I became a nice pilot. I am still new to the RC hobby and I got pulled into flying quadcopters.

Quadcopters are not piloted the same way as planes. They look safer or easier to pilot since you can always slow down and hover if anything gets out of control.

Recently, I had an interesting experience. I was flying my quad for around 3 months and I felt too much confident: I wanted to try doing flips. Coming from a plane world, I though that climbing to a safe altitude would be the best strategy in case something went wrong.

I got carried away and I ended up to a much higher altitude and further away than I was used to. I tried to drop height and drive the quadcopter back to me but it was too late. The wind was so strong that it moved the quad further away and made the quadcopter swirl. I quickly lost  orientation of the quad and had no way to bring it back.

Luckily, a more experienced pilot help me get the quadcopter back to a safe landing zone which was 615 meters away from my takeoff location.

It took me 3 hours to locate the landing site and find the quad which was still intact!

I learn multiple things this day:

<li style="text-align: justify;">
  I was lacking experience and I need much more practice before attempting stupid aerobatics.
</li>
<li style="text-align: justify;">
  Getting altitude for quadcopters is not as safe as for planes.
</li>
<li style="text-align: justify;">
  It is always better to fly with someone more experienced than you are.
</li>
<li style="text-align: justify;">
  I needed a way to know the orientation of the quad when it is over or away from me.
</li>
<li style="text-align: justify;">
  A lost plane alarm buzzer would have helped me find the quadcopter much quicker.
</li>
<li style="text-align: justify;">
  I was in need of a GPS module and a failsafe mode.
</li>

# <span id="Project_summary">Project summary</span>

The DIY solution consist of adding two devices on the quadcopter each device for solving a specific issue.

## <span id="10_watts_LED">10 watts LED</span>

<div id="attachment_2141" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg" rel="attachment wp-att-2141"><img aria-describedby="caption-attachment-2141" loading="lazy" class="wp-image-2141 size-medium" src="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-300x169.jpg" alt="10 Watt LEDs" width="300" height="169" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg 853w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-2141" class="wp-caption-text">
    10 Watt LEDs
  </p>
</div>

The first device is a 10 watts light-emitting diode (LED) mounted to the front of the quadcopter. This option adds to existing visual aids and help the pilot to develop his situation awareness. The front LED allows the pilot to know when the quadcopter is facing him and help the pilot recover in case of lost orientation.

This type of LED is quite bright and provides 900 to 1000 lumens of light which makes it a good candidate to be seen from far away.

As an example, here is a picture of the LED mounted to the quadcopter seen from 333 meters away.

<div id="attachment_2132" style="width: 383px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters.png" rel="attachment wp-att-2132"><img aria-describedby="caption-attachment-2132" loading="lazy" class="wp-image-2132 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters.png" alt="Quadcopter 10 watts LED seen from 333 meters away" width="373" height="209" srcset="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters.png 373w, http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters-150x84.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters-300x168.png 300w" sizes="(max-width: 373px) 100vw, 373px" /></a>
  
  <p id="caption-attachment-2132" class="wp-caption-text">
    Quadcopter 10 watts LED seen from 333 meters away
  </p>
</div>

To help locate the LED location, here is the same point of view with the LED turned off:

<div id="attachment_2131" style="width: 383px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters.png" rel="attachment wp-att-2131"><img aria-describedby="caption-attachment-2131" loading="lazy" class="wp-image-2131 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters.png" alt="Quadcopter 10 watts LED OFF" width="373" height="209" srcset="http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters.png 373w, http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters-150x84.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters-300x168.png 300w" sizes="(max-width: 373px) 100vw, 373px" /></a>
  
  <p id="caption-attachment-2131" class="wp-caption-text">
    Quadcopter 10 watts LED OFF
  </p>
</div>

<p class="pleasenote" data-pleasenote="true">
  Note that both images are cropped version of <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/10w-Quadcopter-LED-full-image.jpg">the original image</a> which have a much bigger field-of-view.
</p>

## <span id="Lost_plane_alarm_finder">Lost plane alarm finder</span>

<div id="attachment_2142" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg" rel="attachment wp-att-2142"><img aria-describedby="caption-attachment-2142" loading="lazy" class="wp-image-2142 size-medium" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-300x169.jpg" alt="Piezoelectric Buzzer - Audible Alarm Sound Buzzers" width="300" height="169" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg 854w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-2142" class="wp-caption-text">
    Piezoelectric Buzzer &#8211; Audible Alarm Sound Buzzers
  </p>
</div>

The second device is a 95 decibel (dB) [piezoelectric speaker][1]. This allows the quadcopter to be easily found in case of a crash or an emergency landing. For example, if one enter [Failsafe mode][2], the quadcopter can land immediately (or [Return To Home][3] but that is out of scope) and there is a good chance that it will be far from your takeoff location. Tracking a beep-beep-beep sound is much more easier than estimating the landing location 1 km away.

There are already tons of existing options for a search alarm buzzer on the market, each with their own pros and cons. [Some buzzer][4] must be connected to a dedicated channel and make sound when flipping a switch on your controller. [Others][5] must be connected in series with the throttle channel and rings if the throttle signal has not changed for more than 60 seconds.

However, I prefer the [DIY way][6] since it gives more personal satisfaction and the selected option is always the preferred one for my personal needs.

With the DIY route, the piezo buzzer is much louder reaching peaks of 96 dB instead of 60-70 dB since the piezo is powered by the LiPo battery (in my case a 3S 11.1 volts) instead of a poor 5 volts. The sound volume for piezo buzzer is proportional to the voltage used to power the device meaning that a 4S LiPo battery (14.8v) would make it louder than a 3S LiPo.

## <span id="Microcontroller">Microcontroller</span>

<div id="attachment_2143" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg" rel="attachment wp-att-2143"><img aria-describedby="caption-attachment-2143" loading="lazy" class="wp-image-2143 size-medium" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-300x169.jpg" alt="Arduino Nano v3" width="300" height="169" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg 853w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-2143" class="wp-caption-text">
    Arduino Nano v3
  </p>
</div>

What is different about this project is that it includes an [arduino nano v3][7], which is a microcontroller. The arduino act as the brain between the pilot and the on-board devices. It allows control of both the LED and the piezo buzzer by reading the quadcopter&#8217;s receiver signal and forwarding the pilot commands to each device.

This configuration offers much more possibilities. The most obvious is that each device is controlled by the microcontroller instead of a direct channel. This allows advanced logic to be used to implement more features.

As an example, I don&#8217;t want the LED always turned ON and certainly don&#8217;t need to have the alarm buzzing during the flight when everything is going well. So I had to come up with a way to control both devices with the transmitter.

The big innovation about this project is that **both devices** are controlled by the quadcopter transmitter using only a **single** channel.

As bonus points, with the help of the arduino, the piezo buzzer can be used as a &#8220;cellphone ringtone player&#8221; to ring the geekiest melodies&#8230;

# <span id="Project_data">Project data</span>

## <span id="Components_and_Supplies"><span style="font-size: 24px; font-weight: bold; line-height: 1;">Components and Supplies</span></span>

All the hardware components required for this project are available  for purchase on eBay.

<p class="pleasenote" data-pleasenote="true">
  Note that this project assumes that the arduino will be connected to a Remote Controlled (RC) 6-channels Receiver. This part for the project is then not listed as a &#8216;required&#8217; component.
</p>

The material for this project is as follows:

<table class=" generictable" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td>
      Image
    </td>
    
    <td>
      Description
    </td>
    
    <td>
      Qty
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg" rel="attachment wp-att-2143"><img loading="lazy" class="alignnone wp-image-2143 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-150x84.jpg" alt="Arduino Nano v3" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Arduino Nano v3
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg" rel="attachment wp-att-2142"><img loading="lazy" class="alignnone wp-image-2142 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-150x84.jpg" alt="Piezoelectric Buzzer - Audible Alarm Sound Buzzers" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg 854w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Piezoelectric Buzzer
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg" rel="attachment wp-att-2141"><img loading="lazy" class="alignnone wp-image-2141 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-150x84.jpg" alt="10 Watt LEDs" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      10 Watt LEDs
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg" rel="attachment wp-att-2150"><img loading="lazy" class="alignnone wp-image-2150 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-150x84.jpg" alt="MR16 12v 10w LED Driver" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      MR16 Constant Current LED Driver (12v 10w)
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg" rel="attachment wp-att-2149"><img loading="lazy" class="alignnone wp-image-2149 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-150x84.jpg" alt="IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      N-Channel TO-220AB Power Mosfet<br /> (IRF630N, 200V, 9.3A, 0.30-Ohm)
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable.jpg" rel="attachment wp-att-2154"><img loading="lazy" class="alignnone wp-image-2154 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable-150x126.jpg" alt="20CM Male to Male Servo Extension Lead Wire Cable" width="150" height="126" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable-150x126.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable-300x251.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable-768x643.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable-672x562.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable.jpg 900w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      20cm Male Servo Extension Lead Wire Cable
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector.jpg" rel="attachment wp-att-2148"><img loading="lazy" class="alignnone wp-image-2148 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector-150x84.jpg" alt="Female JST Battery Connector" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Female JST battery connector
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard.jpg" rel="attachment wp-att-2151"><img loading="lazy" class="wp-image-2151 size-thumbnail alignnone" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard-150x84.jpg" alt="Single Side 5x7cm Prototyping Stripboard" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Single Side 5x7cm Prototyping Stripboard
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor.jpg" rel="attachment wp-att-2153"><img loading="lazy" class="alignnone wp-image-2153 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor-150x85.jpg" alt="10k resistor" width="150" height="85" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor-150x85.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor.jpg 300w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      10k Ohm Resistor
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Wire.jpg" rel="attachment wp-att-2146"><img loading="lazy" class="alignnone wp-image-2146 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Wire-150x84.jpg" alt="Wire" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Wire-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Wire-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Wire-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Wire-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Wire.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Wires
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam.jpg" rel="attachment wp-att-2191"><img loading="lazy" class="alignnone size-thumbnail wp-image-2191" src="http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam-150x84.jpg" alt="Wrapping Foam" width="150" height="84" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam.jpg 853w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Wrapping foam
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers.jpg" rel="attachment wp-att-2195"><img loading="lazy" class="alignnone size-thumbnail wp-image-2195" src="http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-150x112.jpg" alt="Wood BBQ Skewers" width="150" height="112" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-150x112.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-300x224.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-768x573.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-1024x765.jpg 1024w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-1446x1080.jpg 1446w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers-672x502.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers.jpg 1800w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      Wood BBQ Skewers
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg" rel="attachment wp-att-1640"><img loading="lazy" class="alignnone wp-image-1640 size-thumbnail" src="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester-150x150.jpg" alt="CCPM Servo Tester" width="150" height="150" srcset="http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester-150x150.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg 250w" sizes="(max-width: 150px) 100vw, 150px" /></a>
    </td>
    
    <td>
      CCPM-Servo-Tester
    </td>
    
    <td>
      1
    </td>
  </tr>
</table>

### <span id="MR16_Constant_Current_LED_Driver">MR16 Constant Current LED Driver</span>

<div id="attachment_2150" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg" rel="attachment wp-att-2150"><img aria-describedby="caption-attachment-2150" loading="lazy" class="size-medium wp-image-2150" src="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-300x169.jpg" alt="MR16 12v 10w LED Driver" width="300" height="169" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg 853w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-2150" class="wp-caption-text">
    MR16 12v 10w LED Driver
  </p>
</div>

The MR16 Constant Current LED Driver is used to drive the 10w LED. It can easily be found on eBay and light stores since the driver is used to power LED lamps which happens to use 10w LEDs.

The controller is not cheap but looks like the best logical choice. On a quadcopter, every grams counts and this driver is very light and it is the smallest form factor circuit that I could find.

I am not that much concerned about power efficiency of the driver since the project is to be mounted to a quadcopter. The small 10w LED is not significant when compared to the 4 brushless motors.

### <span id="N-Channel_Power_Mosfet">N-Channel Power Mosfet</span>

<div id="attachment_2149" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg" rel="attachment wp-att-2149"><img aria-describedby="caption-attachment-2149" loading="lazy" class="size-medium wp-image-2149" src="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-300x169.jpg" alt="IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet" width="300" height="169" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet-672x378.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg 853w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-2149" class="wp-caption-text">
    IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet
  </p>
</div>

My original design only required a single mosfet and was used as a switch to trigger the MR16 LED driver and a simple NPN Transistor (like the 2N2222A) which was also used as a switch to trigger the piezo buzzer. This setup was working fine on the arduino development board which provides 5 volts. However, once I connected the board to my 3S LiPo battery, which is 11.1 volts, the gate of the 2N2222A started leaking from collector to emitter without a signal sent to the base (in other words, the switch was always closed). The piezo buzzer started ringing without me understanding why.

<p class="pleasenote" data-pleasenote="true">
  Please note that your wife may get mad at you if you let the piezo buzzer ring for too long. Better use higher rated transistor!
</p>

I used the IRF630N mosfet for driving both the LED and the piezo buzzer. The mosfet is rated for much higher current and voltage (200V, 9.3A) for this scenario but it is relatively cheap and I had plenty of those at home.

## <span id="Payload">Payload</span>

I didn&#8217;t take the time to calculate the weight of each component individually. Anyway that would not be really helpful since I do not expect anyone to actually try to optimize the circuit by replacing some components by lightweight version.

The total weight of the package is 37.5 grams. This is calculated using a high precision scale and it includes everything that is required for using the controller in the field. In other words, it also includes the wrapping foam the BBQ sticks and wires.

## <span id="Total_cost_of_the_project"><span style="line-height: 1.5;">Total cost of the project</span></span>

This project is really cheap and can be completed with less than 30$.

Here is the detailed price of each items:

<table class=" generictable" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td>
      Item
    </td>
    
    <td>
      Link
    </td>
    
    <td>
      Quantity
    </td>
    
    <td>
      Total
    </td>
  </tr>
  
  <tr>
    <td>
      Arduino Nano v3
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=arduino+nano+v3&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $3.17
    </td>
  </tr>
  
  <tr>
    <td>
      Piezoelectric Buzzer
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=95db+Piezoelectric+Buzzer&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $1.30
    </td>
  </tr>
  
  <tr>
    <td>
      10 Watt LED
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=10w+LED+cool+white&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $1.00
    </td>
  </tr>
  
  <tr>
    <td>
      MR16 Constant Current LED Driver
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=MR16+Constant+Current+LED+Driver&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $2.24
    </td>
  </tr>
  
  <tr>
    <td>
      N-Channel TO-220AB Power Mosfet
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=IRF630N+mosfet&_sop=15">eBay</a>
    </td>
    
    <td>
      2
    </td>
    
    <td>
       $3.52<sup>1</sup>
    </td>
  </tr>
  
  <tr>
    <td>
      Male Servo Extension Lead Wire Cable
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Male+Servo+Extension+Lead+Wire+Cable&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $1.00
    </td>
  </tr>
  
  <tr>
    <td>
      Female JST battery connector
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Female+JST+battery+connector&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
       $1.00
    </td>
  </tr>
  
  <tr>
    <td>
      Single Side 5x7cm Prototyping Stripboard
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Single+Side+5x7cm+Prototyping+Stripboard&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
       $4.56<sup>2</sup>
    </td>
  </tr>
  
  <tr>
    <td>
      10k Ohm Resistor
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=10k+Ohm+Resistor&_sop=15">eBay</a>
    </td>
    
    <td>
      2
    </td>
    
    <td>
       $1.00<sup>3</sup>
    </td>
  </tr>
  
  <tr>
    <td>
      CCPM-Servo-Tester
    </td>
    
    <td>
      <a href="http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=CCPM-Servo-Tester&_sop=15">eBay</a>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      $1.61
    </td>
  </tr>
</table>

Notes:

  1. Bying 5 pieces is cheaper than buying 2 individual pieces.
  2. Lowest price is for 2 pieces.
  3. For a pack of 50 pieces.

Total cost: $20.40

<p class="pleasenote" data-pleasenote="true">
  Note that cost of usual items such as solder paste, soldering iron, multimeter and base material like wrapping foam is not included in the cost of the project.
</p>

## <span id="Preparation_time"><span style="line-height: 1.5;">Preparation time</span></span>

The whole project can be completed in 5 to 8  hours. This is actually a rough estimated time since I did not build a second controller for another quad that I had. The estimation assumes the following:

<li style="text-align: justify;">
  You already have all required components. Most of the waiting about this project comes from the fact that all components are purchased from China and takes 4-5 weeks to arrive. However, once you have all materials, the project starts to build itself at a decent pace.
</li>
<li style="text-align: justify;">
  You have basic soldering skills. The duration of this project may change depending on how much you are comfortable with a soldering iron.
</li>
<li style="text-align: justify;">
  You are familiar with the arduino prototyping platform. This guide will not cover how to compile the code/libraries and upload it to the arduino. There are plenty of guides and tutorials on the internet that can help you on this matter.
</li>

To make this project a reality, I had to invest much more time. Actually, from beginning to the end, it took somewhere between 50 to 80 hours. I had to learn new skills like basic electronics, designing circuits, using Fritzing software and the arduino platform but most of the time was spent on documenting and debugging the code!(there are still improvements, [see below][8]).

I decided to post this project so that others may benefit from my experience. The project can be used as a proof of concept,  all issues that I encountered are already documented and the code for the project is released to the public.

# <span id="Schematics">Schematics</span>

The following section shows the drawings and the schematics used by the controller.

## <span id="Fritzing_files">Fritzing files</span>

<div id="attachment_2266" style="width: 1034px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new.png" rel="attachment wp-att-2266"><img aria-describedby="caption-attachment-2266" loading="lazy" class="size-large wp-image-2266" src="http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-1024x410.png" alt="Fritzing - Open-Source Hardware Initiative Tool" width="1024" height="410" srcset="http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-1024x410.png 1024w, http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-150x60.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-300x120.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-768x307.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-1920x768.png 1920w, http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new-672x269.png 672w" sizes="(max-width: 1024px) 100vw, 1024px" /></a>
  
  <p id="caption-attachment-2266" class="wp-caption-text">
    Fritzing &#8211; Open-Source Hardware Initiative Tool
  </p>
</div>

All drawings and diagrams are build using [Fritzing][9] version 0.9.2b which is an open-source hardware initiative tool that allows developers to document their prototypes and share them with others. The application already features a huge parts library but there is no support for a [Generic Remote Controlled (RC) 6-Channels Receiver][10] and for the [MR16 Constant Current LED Driver][10].

The additional parts which are required for rendering the project are available for download:

<li style="text-align: justify;">
  <a class="download-link" title="" href="http://www.end2endzone.com/download/2237/" rel="nofollow"> MR16 Constant Current LED Driver.fzpz</a>
</li>
<li style="text-align: justify;">
  <a class="download-link" title="" href="http://www.end2endzone.com/download/2235/" rel="nofollow"> Generic 2.4Ghz RC 6ch Receiver (OCRA).fzpz</a>
</li>
<li style="text-align: justify;">
  <a class="download-link" title="" href="http://www.end2endzone.com/download/2233/" rel="nofollow"> 3S 3600mAh Lipo Battery.fzpz</a>
</li>

The project files are also available for download. Click the following link to get the _Fritzing project files_ for this project:

<li style="text-align: justify;">
  <a class="download-link" title="" href="http://www.end2endzone.com/download/2240/" rel="nofollow"> DIY lost plane alarm finder and 10 watts LED visual aids for easy orientation.fzz</a>
</li>

## <span id="Circuit_Diagram">Circuit Diagram</span>

The following section shows the circuit diagram layout

<div id="attachment_2169" style="width: 1034px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics.png" rel="attachment wp-att-2169"><img aria-describedby="caption-attachment-2169" loading="lazy" class="size-large wp-image-2169" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-1024x681.png" alt="Quadcopter Controller Project - Schematics view" width="1024" height="681" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-1024x681.png 1024w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-150x100.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-300x199.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-768x510.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics-672x447.png 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics.png 1467w" sizes="(max-width: 1024px) 100vw, 1024px" /></a>
  
  <p id="caption-attachment-2169" class="wp-caption-text">
    Quadcopter Controller Project &#8211; Schematics view
  </p>
</div>

## <span id="Breadboard_Layout">Breadboard Layout</span>

The following section shows a breadboard layout view of the circuit.

<div id="attachment_2170" style="width: 1034px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png" rel="attachment wp-att-2170"><img aria-describedby="caption-attachment-2170" loading="lazy" class="wp-image-2170 size-large" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-1024x583.png" alt="Quadcopter Controller Project - Breadboard view" width="1024" height="583" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-1024x583.png 1024w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-150x85.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-300x171.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-768x437.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-672x383.png 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png 1755w" sizes="(max-width: 1024px) 100vw, 1024px" /></a>
  
  <p id="caption-attachment-2170" class="wp-caption-text">
    Quadcopter Controller Project &#8211; Breadboard view
  </p>
</div>

# <span id="Code">Code</span>

The following section defines the required libraries for compiling the main arduino sketch available below.

## <span id="External_libraries"><span style="font-size: 24px; font-weight: bold; line-height: 1;">External libraries</span></span>

The code on the arduino requires multiple external arduino libraries. The following list shows all required software libraries and their related use as part of this project:

<table class=" generictable" style="width: 470px;" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td style="width: 110px;">
      Name
    </td>
    
    <td style="width: 80px;">
      Version
    </td>
    
    <td style="width: 280px;">
      Usage
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/">SoftTimers</a> <sup>5</sup>
    </td>
    
    <td>
      v1.1.219
    </td>
    
    <td>
      Required for all computation and handling of the LED&#8217;s ON and OFF times.
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/">RcReceiverSignal</a> <sup>8</sup>
    </td>
    
    <td>
      v1.2.203
    </td>
    
    <td>
      Required to read PWM signals sent<br /> from the RC Receiver.
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/">AnyRtttl</a> <sup>7</sup>
    </td>
    
    <td>
      v2.1
    </td>
    
    <td>
      Required to play RTTTL melodies data.
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://github.com/GreyGnome/PinChangeInt">PinChangeInt</a>
    </td>
    
    <td>
      version 2402
    </td>
    
    <td>
      RcReceiverSignal library has a dependency<br /> to PinChangeInt library.
    </td>
  </tr>
  
  <tr>
    <td>
      <a href="http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html">eRCaGuy Timer2 Counter</a>
    </td>
    
    <td>
      version 20140709<br /> (last updated<br /> 9 July 2014)
    </td>
    
    <td>
      Required to have a micros() replacement function<br /> which has a 1µs resolution instead of 4µs.
    </td>
  </tr>
</table>

## <span id="Arduino_sketch">Arduino sketch</span>

Here is the brain of the project. Source code!

Click the following to download the example below:  
(download 
	<a class="download-link" title="Version 1.0.240" href="http://www.end2endzone.com/download/2263/" rel="nofollow"> Quad Controller v1.0.240.ino</a>)

<pre class="height-set:true lang:c++ decode:true" title="DIY quadcopter visual aids controller" data-url="http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-v1.0.240.ino">sample</pre>

# <span id="Building_steps"><span style="line-height: 1.5;">Building steps</span></span>

<a href="http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps.png" rel="attachment wp-att-2268"><img loading="lazy" class="alignnone size-full wp-image-2268" src="http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps.png" alt="building-steps" width="630" height="148" srcset="http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps.png 630w, http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps-150x35.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps-300x70.png 300w" sizes="(max-width: 630px) 100vw, 630px" /></a>

The following section explains all the different steps on how to build my DIY quadcopter visual aids controller.

## <span id="Install_code_on_arduino">Install code on arduino</span>

Before attempting run the given code on the arduino, you must first install the required libraries. Please follow the [How to Install a Library][11] guide available on the arduino web site.

Download links for required libraries are available in the [External Libraries][12] or [References][13] sections.

Upload the main arduino sketch to the arduino and proceed with the next step.

## <span id="Setup_transmitter_Tx_mixes">Setup transmitter (Tx) mixes</span>

As explained [above][14],  this project innovation relies on the fact that **both devices** are controlled by the quadcopter transmitter using only a **single channel**. This is achieved by configuring custom mixes on the transmitter.

To know more about how mixes can be used to control more than one device with the help of a microcontroller, read the following article: [How to multiplex RC Transmitter switches into a single channel][15].

As a reference, here are the mixes that I use for my Spektrum DX9 transmitter:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 240px;" colspan="5" width="220">
      AUX1 Mix info
    </td>
    
    <td style="width: 80px;" colspan="3" width="80">
      Mix Output
    </td>
  </tr>
  
  <tr class="headerrow">
    <td>
      Number
    </td>
    
    <td>
      Switch
    </td>
    
    <td>
      High
    </td>
    
    <td>
      Low
    </td>
    
    <td>
      Offset
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      Right knob
    </td>
    
    <td>
      -74
    </td>
    
    <td>
    </td>
    
    <td>
      -99
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      -73
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      Right knob
    </td>
    
    <td>
    </td>
    
    <td>
      54
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      -54
    </td>
    
    <td>
      -108
    </td>
  </tr>
  
  <tr>
    <td colspan="5">
    </td>
    
    <td style="background-color: #f7f497;">
      -147
    </td>
    
    <td style="background-color: #f7f497;">
      -127
    </td>
    
    <td style="background-color: #f7f497;">
      -108
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      H
    </td>
    
    <td>
    </td>
    
    <td>
      -69
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      &#8211;
    </td>
    
    <td>
      138
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      G
    </td>
    
    <td>
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      46
    </td>
    
    <td>
      92
    </td>
  </tr>
</table>

<p class="pleasenote" data-pleasenote="true">
  Note that the following mixes must match the <a href="#Arduino_sketch">demultiplexing  code</a> running on the arduino. If you do not use the code &#8220;as is&#8221;, then you must also adjust your transmitter mixes to reflect the change.
</p>

## <span id="Build_a_prototype">Build a prototype</span>

<div id="attachment_2156" style="width: 810px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype.jpg" rel="attachment wp-att-2156"><img aria-describedby="caption-attachment-2156" loading="lazy" class="wp-image-2156 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype.jpg" alt="DIY Quadcopter lost plane alarm finder and 10w LED visual aids Prototype" width="800" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype.jpg 800w, http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype-150x90.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype-300x180.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype-768x461.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype-672x403.jpg 672w" sizes="(max-width: 800px) 100vw, 800px" /></a>
  
  <p id="caption-attachment-2156" class="wp-caption-text">
    DIY Quadcopter lost plane alarm finder and 10w LED visual aids Prototype
  </p>
</div>

The purpose of these steps is to evaluate the feasibility of the project by implementing a smaller scale of the project as a proof of concept even though that at this point you should already know that the project is viable since I already completed all steps and the controller is actually running on my personal quadcopter.

### <span id="Test_the_code">Test the code</span>

<div id="attachment_2269" style="width: 640px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency.png" rel="attachment wp-att-2269"><img aria-describedby="caption-attachment-2269" loading="lazy" class="size-full wp-image-2269" src="http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency.png" alt="QuadCtrl - Testing the code in Arduino IDE" width="630" height="312" srcset="http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency.png 630w, http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency-150x74.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency-300x149.png 300w" sizes="(max-width: 630px) 100vw, 630px" /></a>
  
  <p id="caption-attachment-2269" class="wp-caption-text">
    QuadCtrl &#8211; Testing the code in Arduino IDE
  </p>
</div>

The purpose of this step is to quickly identify issue with the code as no other parts (besides the arduino itself) of the final circuit is used. Code issues are the one that should be addressed first. This step confirms that the arduino is able to read an arbitrary PWM signal and process it.

Build the circuit as showed by the picture above. For reference, the yellow and blue wires matches the blue and orange wire of the breadboard layout. These wires are connected to pins which drives low LEDs instead of high current mosfets. The prototype uses a simple CCPM Servo Tester for emulating the 6-ch receiver. In this configuration, the red LED matches the 10W front LED and the green LED matches the buzzing state.

Power the arduino using USB power. By changing the position of the CCPM Servo tester potentiometer, you should observe different behavior of each LEDs for each position of CCPM tester.

<p class="pleasenote" data-pleasenote="true">
  Note that since the code is already debugged, I do not expect anything to go wrong and things should be addressed easily. If you do observe issues, please verify your connections or the version used by each library dependencies.
</p>

### <span id="TxRx_prototype_integration">Tx/Rx prototype integration</span>

For a greater testing, connect your receiver and use your transmitter to change the PWM signal sent to the microcontroller.

This step verifies the quality (or precision of the signal) of the transmitter/receiver pair. It also helps validating that you configured the right mixes in your transmitter to independently control the LED and the buzzer.

### <span id="Test_each_component_optional">Test each component (optional)</span>

Now that you know that the code is working as expected, you may want to test each components before [soldering them][16] on the breadboard.

The final step is to integrate all real components to the breadboard prototype and use external 12v power supply (to mimic a 3S LiPo battery).

<a href="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png" rel="attachment wp-att-2170"><img loading="lazy" class="aligncenter size-medium wp-image-2170" src="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-300x171.png" alt="Quadcopter Controller Project - Breadboard view" width="300" height="171" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-300x171.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-150x85.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-768x437.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-1024x583.png 1024w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard-672x383.png 672w, http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png 1755w" sizes="(max-width: 300px) 100vw, 300px" /></a>

Complete the actual circuit as defined in [Breadboard Layout][17] section.

## <span id="Solder_components">Solder components</span>

<div id="attachment_2271" style="width: 863px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566.jpg" rel="attachment wp-att-2271"><img aria-describedby="caption-attachment-2271" loading="lazy" class="size-full wp-image-2271" src="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566.jpg" alt="QuadCtrl - Soldering components to the stripboard" width="853" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566.jpg 853w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566-672x378.jpg 672w" sizes="(max-width: 853px) 100vw, 853px" /></a>
  
  <p id="caption-attachment-2271" class="wp-caption-text">
    QuadCtrl &#8211; Soldering components to the stripboard
  </p>
</div>

Define the position of every components on the prototyping stripboard. You should have enough room for all components and if you plan correctly, you may still have space left and be able to cut 1 or 2 cm from the sides to save additional size and weight.

Note that both mosfet do not require a heat sink. However, you may want to fold both mosfet so that the height of the total package is as low as possible so that it may fit properly inside a small cavity of the quadcopter.

Position the arduino&#8217;s USB port facing outside so that when you need to update the software, you can simply connect the package to a computer without having to disassemble or disconnect the unit from the quadcopter.

For the same reason, solder the male servo extension lead and the JST battery connector to the other side since those will require to be as close as possible to the quadcopter&#8217;s controller and battery.

Solder each component carefully following the schematics and head to the final step.

## <span id="Securethe_unit_on_the_quadcopter">Secure the unit on the quadcopter</span>

<div id="attachment_2272" style="width: 863px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557.jpg" rel="attachment wp-att-2272"><img aria-describedby="caption-attachment-2272" loading="lazy" class="size-full wp-image-2272" src="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557.jpg" alt="QuadCtrl - Securing components with wrapping foam" width="853" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557.jpg 853w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557-672x378.jpg 672w" sizes="(max-width: 853px) 100vw, 853px" /></a>
  
  <p id="caption-attachment-2272" class="wp-caption-text">
    QuadCtrl &#8211; Securing components with wrapping foam
  </p>
</div>

Once everything is ready for flight, attach the package on the quadcopter. Connect JST battery connector and each signal wire cable.

Since I was planning on removing the device for maintenance, I didn&#8217;t used glue (or anything permanent) for securing the package to the frame. Instead I used zip ties which are used for both wrapping the foam around the stripboard and attaching to the frame&#8217;s front grooves.

I also used zip ties to attach the wood BBQ skewers to the pre-drilled holes in the fuselage.

For best result, position the 10w LED below the propeller&#8217;s wind blast. This will greatly increase the lifespan of the LED since it will always be properly cooled while turned on.

## <span id="Final_Result"><span style="font-size: 26px; font-weight: bold; line-height: 1.3846153846;">Final Result</span></span>

Here is the final result:

<div id="attachment_2192" style="width: 863px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final.jpg" rel="attachment wp-att-2192"><img aria-describedby="caption-attachment-2192" loading="lazy" class="wp-image-2192 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final.jpg" alt="Arduino Quadcopter LED & Buzzer Controler (final)" width="853" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final.jpg 853w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-672x378.jpg 672w" sizes="(max-width: 853px) 100vw, 853px" /></a>
  
  <p id="caption-attachment-2192" class="wp-caption-text">
    Arduino Quadcopter LED & Buzzer Controler (final)
  </p>
</div>

<div id="attachment_2193" style="width: 863px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up.jpg" rel="attachment wp-att-2193"><img aria-describedby="caption-attachment-2193" loading="lazy" class="size-full wp-image-2193" src="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up.jpg" alt="Arduino Quadcopter LED & Buzzer Controler (final) - Close Up" width="853" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up.jpg 853w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up-672x378.jpg 672w" sizes="(max-width: 853px) 100vw, 853px" /></a>
  
  <p id="caption-attachment-2193" class="wp-caption-text">
    Arduino Quadcopter LED & Buzzer Controler (final) &#8211; Close Up
  </p>
</div>

# <span id="Made_anything_differently">Made anything differently?</span>

The features of the device are fulfilling the main objectives and there is no actual need to change anything. However, there are lots of aspect of the design that could be improved. After completing this project, I though of multiple ideas that could bring the design to a higher quality level.

At the beginning of the project, I was not much concerned about weight since I was evaluating the feasibility of the project and I didn&#8217;t design the device to be something that would actually be flying. Now that it is completed, I would like to put more effort trying to reduce the total weight.

Here are most aspects that I would like to improve:

## <span id="Bettersignal_wires">Better signal wires</span>

Signal wires could be much improved.

First, they are way too big. The wires for the receiver signal between the 6-ch receiver (Rx) and the arduino could be made smaller. Only a small current is used to carry the signal so there is no need for not using the smallest wires available.

Second, not all wires are actually used. At the beginning of the design, I though of using the arduino to read multiple channels. In the picture above, the red and blue wires were designed to read 2 more PWM signals which would make the arduino able to decode 3 different channels. The blue and red wires are wasted grams I could save.

Finally, the length of the wires is 3-4 times longer than they actually need. When I was prototyping, it was actually convenient to have longer cable that could connect the receiver but once the unit is attached to the quadcopter, the device is almost next to the receiver and the need for longer wires is not much required anymore. The same also applies for the LED wires which had to be folded many times because they were too long.

## <span id="Other_LED_options">Other LED options?</span>

I still doubt that a single super strong LED is the way to go. In the near future, I might consider having multiple on-board middle-range LED and I am curious to see if multiple LEDs would produce more lumens than a single one. In the idea, having 2 or 3 smaller LED may make the whole thing more visible at greater distance. I may investigate other LED options which offers a better watt-to-lumens ratio.

If I ever choose to go with 2 or 3 smaller LED instead of a single super strong LED, I may also get rid of the current limiting circuit. The circuit is not particularly heavy but using smaller LED (which consumes less power), would allow me to replace the circuit by smaller/lighter resistance connected to each LED. I know that each resistance might not be super efficient (lots of heat dissipation) but it is negligible when compared to the enormous amount of energy consumed by the motors. A linear voltage regulator like the [LM317][18] might also simplify the circuit and prevent too much heat dissipation.

## <span id="Smaller_form_factor">Smaller form factor</span>

Getting rid of the stripboard would also be in my plans. Now that I know the whole circuit does not required too much connections, I am now thinking of completely removing the stripboard. This would require to hot glue both the mosfets and the current limiting circuit directly to the arduino. If done properly, the amount of hot glue required should be lighter than the stripboard.

At the same time, the device would be smaller which could make it usable on other platforms like ones with a hard shell cover.

## <span id="Signal_demultiplexing_nessesary">Signal (de)multiplexing nessesary?</span>

Short answer, no.

Actually, I do not require to have an on-board arduino on the quad. There was no actual need to implement signal multiplexing and demultiplexing. To get the same functionality, I could have simply used an 8-channels receiver and the need for multiplexing/demultiplexing would be gone.

The main reason for this project was fun. **_&#8216;All work and no play makes Antoine a dull boy&#8217;_**. The project turned out more complicated than I first through and I had to invest a lot of my free time to code, test and to make it up to this point. Without the &#8216;fun&#8217; part, this project would never went further than ideas on a sheet of paper. If I ever have to rebuild this project, the fun part would still be the first and primary goal of the project!

## <span id="Modular_design">Modular design</span>

For maintainability, portability and reusability reasons, it might be interesting to subdivide the device into modules (smaller reusable parts).

For instance the demultiplexor could be a perfect candidate for reusability. It could be reused on other platforms like airplanes to control non-critical flight accessories like landing lights where front, wings and tail lights could be controlled by a single channel.

The LED and buzzer could also be made into modules. Each or both could be modified to be directly connected to a dedicated channel on the receiver. If I ever upgrade the quadcopter to a 8-channels (or more) receiver, I could still use the LED and the buzzer without requiring the demultiplexor part.

# <span id="References">References</span>

Here is the list of all sub-articles that made this project a reality:

Documentation:

  1. [How to multiplex RC Transmitter switches into a single channel][19].
  2. [Mapping RC Transmitter PWM signal to actual transmitter values][20].
  3. [Demystifying RC Transmitter Mixing][21].
  4. [RC Transmitter Mix Calculator][22].

Arduino libraries:

<li value="5">
  <a href="http://www.end2endzone.com/softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/">SoftTimers – A collection of software timers to easily compute elapsed time since an event occurred</a>.
</li>
  1. [libRtttl – A c++ library (with UI) for compressing/optimizing the RTTTL audio format][23].
  2. [AnyRtttl – A feature rich arduino library for playing RTTTL melodies][24].
  3. [RcReceiverSignal: an arduino library for retrieving the RC Transmitter value from an RC Receiver pulse][25].

# <span id="Notes">Notes</span>

none

 [1]: http://en.wikipedia.org/wiki/Piezoelectric_speaker
 [2]: http://wiki.dji.com/en/index.php/Naza-M_Enhanced_Failsafe
 [3]: http://wiki.dji.com/en/index.php/Inspire_1_Pro-Return_to_Home_(RTH)
 [4]: http://www.hobbyking.com/hobbyking/store/__14521__HobbyKing_174_Discovery_Buzzer.html
 [5]: http://www.hobbyking.com/hobbyking/store/__13064__Signal_loss_Alarm_Lost_Plane_Finder.html
 [6]: /tag/diy/
 [7]: http://www.arduino.cc/en/Main/ArduinoBoardNano
 [8]: #Made_anything_differently
 [9]: http://fritzing.org/home/
 [10]: #Components_and_Supplies
 [11]: http://www.arduino.cc/en/Guide/Libraries#toc2
 [12]: #External_libraries
 [13]: #References
 [14]: #Microcontroller
 [15]: /how-to-multiplex-rc-transmitter-switches-into-a-single-channel/
 [16]: #Solderingcomponents_on_thestripboard
 [17]: #Breadboard_Layout
 [18]: https://www.google.ca/search?q=lm317&source=lnms&tbm=isch
 [19]: http://www.end2endzone.com/how-to-multiplex-rc-transmitter-switches-into-a-single-channel/
 [20]: http://www.end2endzone.com/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/
 [21]: http://www.end2endzone.com/demystifying-rc-transmitter-mixing/
 [22]: http://www.end2endzone.com/rc-transmitter-mix-calculator/
 [23]: http://www.end2endzone.com/librtttl-a-c-library-with-ui-for-compressingoptimizing-the-rtttl-audio-format/
 [24]: http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/
 [25]: http://www.end2endzone.com/rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/