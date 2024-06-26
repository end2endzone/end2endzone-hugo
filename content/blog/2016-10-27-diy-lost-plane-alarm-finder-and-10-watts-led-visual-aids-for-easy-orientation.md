---
title: DIY lost plane alarm finder and 10 watts LED visual aids for easy orientation
author: end2end
date: 2016-10-27T16:48:23+00:00
url: /diy-lost-plane-alarm-finder-and-10-watts-led-visual-aids-for-easy-orientation/
images:
  - src: /wp-content/uploads/2016/10/Arduino-Quadcopter-Controler-featured.jpg
hits:
  - 845
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Fritzing project:
        * [[download id="2240" template="title"]](/download/2240/)Fritzing parts:
        * [[download id="2237" template="title"]](/download/2237/)
        * [[download id="2235" template="title"]](/download/2235/)
        * [[download id="2233" template="title"]](/download/2233/)
        Source code files:
        * [[download id="2263" template="title"]](/download/2263/)
        
categories:
  - Model Aeronautics
tags:
  - arduino
  - diy
  - english
  - open source
  - RC

---
# Introduction

The reason I started this project is because I recently had a bad experience flying a quadcopter too far from me until I was not able to distinguish if the quad was facing me or not. It does not require much distance before a quadcopter looks like a tiny black dot in the sky. Basically, I lost orientation of the quad and I had to land way too far from my takeoff location.

I was in need of more tools (or more ways) to help myself when I will inevitably get into this situation again. The following project explains how I build a DIY solution to help a pilot know a quadcopter orientation when its far away from the point of view and easily locate the quadcopter in case of emergency landing.<!--more-->

# Background story

I have been flying planes for many years now and over time, I learned to increase my skills and I became a nice pilot. I am still new to the RC hobby and I got pulled into flying quadcopters.

Quadcopters are not piloted the same way as planes. They look safer or easier to pilot since you can always slow down and hover if anything gets out of control.

Recently, I had an interesting experience. I was flying my quad for around 3 months and I felt too much confident: I wanted to try doing flips. Coming from a plane world, I though that climbing to a safe altitude would be the best strategy in case something went wrong.

I got carried away and I ended up to a much higher altitude and further away than I was used to. I tried to drop height and drive the quadcopter back to me but it was too late. The wind was so strong that it moved the quad further away and made the quadcopter swirl. I quickly lost  orientation of the quad and had no way to bring it back.

Luckily, a more experienced pilot help me get the quadcopter back to a safe landing zone which was 615 meters away from my takeoff location.

It took me 3 hours to locate the landing site and find the quad which was still intact!

I learn multiple things this day:

* I was lacking experience and I need much more practice before attempting stupid aerobatics.
* Getting altitude for quadcopters is not as safe as for planes.
* It is always better to fly with someone more experienced than you are.
* I needed a way to know the orientation of the quad when it is over or away from me.
* A lost plane alarm buzzer would have helped me find the quadcopter much quicker.
* I was in need of a GPS module and a failsafe mode.

# Project summary

The DIY solution consist of adding two devices on the quadcopter each device for solving a specific issue.

## 10 watts LED

[![10 Watt LEDs](http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg)

10 Watt LEDs

The first device is a 10 watts light-emitting diode (LED) mounted to the front of the quadcopter. This option adds to existing visual aids and help the pilot to develop his situation awareness. The front LED allows the pilot to know when the quadcopter is facing him and help the pilot recover in case of lost orientation.

This type of LED is quite bright and provides 900 to 1000 lumens of light which makes it a good candidate to be seen from far away.

As an example, here is a picture of the LED mounted to the quadcopter seen from 333 meters away.

[![Quadcopter 10 watts LED seen from 333 meters away](http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters.png)](http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-on-from-333-meters.png)

Quadcopter 10 watts LED seen from 333 meters away

To help locate the LED location, here is the same point of view with the LED turned off:

[![Quadcopter 10 watts LED OFF](http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters.png)](http://www.end2endzone.com/wp-content/uploads/2016/06/10w-Quadcopter-LED-turned-off-from-333-meters.png)

Quadcopter 10 watts LED OFF

{{< pleasenote >}}
  Note that both images are cropped version of [the original image](http://www.end2endzone.com/wp-content/uploads/2016/07/10w-Quadcopter-LED-full-image.jpg) which have a much bigger field-of-view.
{{< /pleasenote >}}


## Lost plane alarm finder

[![Piezoelectric Buzzer - Audible Alarm Sound Buzzers](http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg)

Piezoelectric Buzzer - Audible Alarm Sound Buzzers

The second device is a 95 decibel (dB)&nbsp;[piezoelectric speaker](http://en.wikipedia.org/wiki/Piezoelectric_speaker). This allows the quadcopter to be easily found in case of a crash or an emergency landing. For example, if one enter [Failsafe mode](http://wiki.dji.com/en/index.php/Naza-M_Enhanced_Failsafe), the quadcopter can land immediately (or [Return To Home](http://wiki.dji.com/en/index.php/Inspire_1_Pro-Return_to_Home_(RTH))&nbsp;but that is out of scope) and there is a good chance that it will be far from your takeoff location. Tracking a beep-beep-beep sound is much more easier than estimating the landing location 1 km away.

There are already tons of existing options for a search alarm buzzer on the market, each with their own pros and cons. [Some buzzer](http://www.hobbyking.com/hobbyking/store/__14521__HobbyKing_174_Discovery_Buzzer.html) must be connected to a dedicated channel and make sound when flipping a switch on your controller. [Others](http://www.hobbyking.com/hobbyking/store/__13064__Signal_loss_Alarm_Lost_Plane_Finder.html) must be connected in series with the throttle channel and rings if the throttle signal has not changed for more than 60 seconds.

However, I prefer the [DIY way](/tag/diy/) since it gives more personal satisfaction and the selected option is always the preferred one for my personal needs.

With the DIY route, the piezo buzzer is much louder reaching peaks of 96 dB instead of 60-70 dB since the piezo is powered by the LiPo battery (in my case a 3S 11.1 volts) instead of a poor 5 volts. The sound volume for piezo buzzer is proportional to the voltage used to power the device meaning that a 4S LiPo battery (14.8v) would make it louder than a 3S LiPo.

## Microcontroller

[![Arduino Nano v3](http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg)

Arduino Nano v3

What is different about this project is that it includes an [arduino nano v3](http://www.arduino.cc/en/Main/ArduinoBoardNano), which is a microcontroller. The arduino act as the brain between the pilot and the on-board devices. It allows control of both the LED and the piezo buzzer by reading the quadcopter's receiver signal and forwarding the pilot commands to each device.

This configuration offers much more possibilities. The most obvious is that each device is controlled by the microcontroller instead of a direct channel. This allows advanced logic to be used to implement more features.

As an example, I don't want the LED always turned ON and certainly don't need to have the alarm buzzing during the flight when everything is going well. So I had to come up with a way to control both devices with the transmitter.

The big innovation about this project is that **both devices** are controlled by the quadcopter transmitter using only a **single** channel.

As bonus points, with the help of the arduino, the piezo buzzer can be used as a "cellphone ringtone player" to ring the geekiest melodies...

# Project data

## Components and Supplies

All the hardware components required for this project are available  for purchase on eBay.

{{< pleasenote >}}
  Note that this project assumes that the arduino will be connected to a Remote Controlled (RC) 6-channels Receiver. This part for the project is then not listed as a 'required' component.
{{< /pleasenote >}}


The material for this project is as follows:

| Image                                                                                                                                                                                                                                                                                                         | Description                                                           | Qty |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------|-----|
| [![Arduino Nano v3](http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Arduino-Nano-v3.jpg)                                                                                                                                    | Arduino Nano v3                                                       | 1   |
| [![Piezoelectric Buzzer - Audible Alarm Sound Buzzers](http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Piezoelectric-Buzzer-Audible-Alarm-Sound-Buzzers.jpg)                               | Piezoelectric Buzzer                                                  | 1   |
| [![10 Watt LEDs](http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/10-Watt-LEDs.jpg)                                                                                                                                             | 10 Watt LEDs                                                          | 1   |
| [![MR16 12v 10w LED Driver](http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg)                                                                                                            | MR16 Constant Current LED Driver (12v 10w)                            | 1   |
| [![IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet](http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg) | N-Channel TO-220AB Power Mosfet<br /> (IRF630N, 200V, 9.3A, 0.30-Ohm) | 2   |
| [![20CM Male to Male Servo Extension Lead Wire Cable](http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/20CM-Male-Servo-Extension-Lead-Wire-Cable.jpg)                                              | 20cm Male Servo Extension Lead Wire Cable                             | 1   |
| [![Female JST Battery Connector](http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Female-JST-Battery-Connector.jpg)                                                                                             | Female JST battery connector                                          | 1   |
| [![Single Side 5x7cm Prototyping Stripboard](http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Single-Side-5x7cm-Prototyping-Stripboard.jpg)                                                         | Single Side 5x7cm Prototyping Stripboard                              | 1   |
| [![10k resistor](http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/10k-resistor.jpg)                                                                                                                                             | 10k Ohm Resistor                                                      | 2   |
| [![Wire](http://www.end2endzone.com/wp-content/uploads/2016/07/Wire.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/Wire.jpg)                                                                                                                                                                     | Wires                                                                 | 1   |
| [![Wrapping Foam](http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/08/Wrapping-Foam.jpg)                                                                                                                                          | Wrapping foam                                                         | 1   |
| [![Wood BBQ Skewers](http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/08/Wood-BBQ-Skewers.jpg)                                                                                                                                 | Wood BBQ Skewers                                                      | 2   |
| [![CCPM Servo Tester](http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg)                                                                                                                              | CCPM-Servo-Tester                                                     | 1   |


### MR16 Constant Current LED Driver

[![MR16 12v 10w LED Driver](http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/MR16-12v-10w-LED-Driver.jpg)

MR16 12v 10w LED Driver

The MR16 Constant Current LED Driver is used to drive the 10w LED. It can easily be found on eBay and light stores since the driver is used to power LED lamps which happens to use 10w LEDs.

The controller is not cheap but looks like the best logical choice. On a quadcopter, every grams counts and this driver is very light and it is the smallest form factor circuit that I could find.

I am not that much concerned about power efficiency of the driver since the project is to be mounted to a quadcopter. The small 10w LED is not significant when compared to the 4 brushless motors.

### N-Channel Power Mosfet

[![IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet](http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/IRF630N-N-Channel-200V-9.3A-0.30-Ohm-TO-220AB-Power-Mosfet.jpg)

IRF630N N-Channel 200V, 9.3A, 0.30-Ohm TO-220AB Power Mosfet

My original design only required a single mosfet and was used as a switch to trigger the MR16 LED driver and a simple NPN Transistor (like the 2N2222A) which was also used as a switch to trigger the piezo buzzer. This setup was working fine on the arduino development board which provides 5 volts. However, once I connected the board to my 3S LiPo battery, which is 11.1 volts, the gate of the 2N2222A started leaking from collector to emitter without a signal sent to the base (in other words, the switch was always closed). The piezo buzzer started ringing without me understanding why.

{{< pleasenote >}}
  Please note that your wife may get mad at you if you let the piezo buzzer ring for too long. Better use higher rated transistor!
{{< /pleasenote >}}


I used the IRF630N mosfet for driving both the LED and the piezo buzzer. The mosfet is rated for much higher current and voltage (200V, 9.3A) for this scenario but it is relatively cheap and I had plenty of those at home.

## Payload

I didn't take the time to calculate the weight of each component individually. Anyway that would not be really helpful since I do not expect anyone to actually try to optimize the circuit by replacing some components by lightweight version.

The total weight of the package is 37.5 grams. This is calculated using a high precision scale and it includes everything that is required for using the controller in the field. In other words, it also includes the wrapping foam the BBQ sticks and wires.

## Total cost of the project

This project is really cheap and can be completed with less than 30$.

Here is the detailed price of each items:

| Item                                     | Link                                                                                                                    | Quantity | Total             |
|------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|----------|-------------------|
| Arduino Nano v3                          | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=arduino+nano+v3&_sop=15)                          | 1        | $3.17             |
| Piezoelectric Buzzer                     | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=95db+Piezoelectric+Buzzer&_sop=15)                | 1        | $1.30             |
| 10 Watt LED                              | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=10w+LED+cool+white&_sop=15)                       | 1        | $1.00             |
| MR16 Constant Current LED Driver         | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=MR16+Constant+Current+LED+Driver&_sop=15)         | 1        | $2.24             |
| N-Channel TO-220AB Power Mosfet          | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=IRF630N+mosfet&_sop=15)                           | 2        | $3.52<sup>1</sup> |
| Male Servo Extension Lead Wire Cable     | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Male+Servo+Extension+Lead+Wire+Cable&_sop=15)     | 1        | $1.00             |
| Female JST battery connector             | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Female+JST+battery+connector&_sop=15)             | 1        | $1.00             |
| Single Side 5x7cm Prototyping Stripboard | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=Single+Side+5x7cm+Prototyping+Stripboard&_sop=15) | 1        | $4.56<sup>2</sup> |
| 10k Ohm Resistor                         | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=10k+Ohm+Resistor&_sop=15)                         | 2        | $1.00<sup>3</sup> |
| CCPM-Servo-Tester                        | [eBay](http://www.ebay.ca/sch/i.html?LH_BIN=1&_from=R40&_sacat=0&_nkw=CCPM-Servo-Tester&_sop=15)                        | 1        | $1.61             |


Notes:

  1. Bying 5 pieces is cheaper than buying 2 individual pieces.
  2. Lowest price is for 2 pieces.
  3. For a pack of 50 pieces.

Total cost: $20.40

{{< pleasenote >}}
  Note that cost of usual items such as solder paste, soldering iron, multimeter and base material like wrapping foam is not included in the cost of the project.
{{< /pleasenote >}}


## Preparation time

The whole project can be completed in 5 to 8  hours. This is actually a rough estimated time since I did not build a second controller for another quad that I had. The estimation assumes the following:

* You already have all required components. Most of the waiting about this project comes from the fact that all components are purchased from China and takes 4-5 weeks to arrive. However, once you have all materials, the project starts to build itself at a decent pace.
* You have basic soldering skills. The duration of this project may change depending on how much you are comfortable with a soldering iron.
* You are familiar with the arduino prototyping platform. This guide will not cover how to compile the code/libraries and upload it to the arduino. There are plenty of guides and tutorials on the internet that can help you on this matter.

To make this project a reality, I had to invest much more time. Actually, from beginning to the end, it took somewhere between 50 to 80 hours. I had to learn new skills like basic electronics, designing circuits, using Fritzing software and the arduino platform but most of the time was spent on documenting and debugging the code!(there are still improvements, [see below](#Made_anything_differently)).

I decided to post this project so that others may benefit from my experience. The project can be used as a proof of concept,  all issues that I encountered are already documented and the code for the project is released to the public.

# Schematics

The following section shows the drawings and the schematics used by the controller.

## Fritzing files

[![Fritzing - Open-Source Hardware Initiative Tool](http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new.png)](http://www.end2endzone.com/wp-content/uploads/2016/10/fritzing_logo_new.png)

Fritzing - Open-Source Hardware Initiative Tool

All drawings and diagrams are build using [Fritzing](http://fritzing.org/home/)&nbsp;version 0.9.2b which is an open-source hardware initiative tool that allows developers to document their prototypes and share them with others. The application already features a huge parts library but there is no support for a [Generic Remote Controlled (RC) 6-Channels Receiver](#Components_and_Supplies)&nbsp;and for the [MR16 Constant Current LED Driver](#Components_and_Supplies).

The additional parts which are required for rendering the project are available for download:

* [ MR16 Constant Current LED Driver.fzpz](http://www.end2endzone.com/download/2237/)
* [ Generic 2.4Ghz RC 6ch Receiver (OCRA).fzpz](http://www.end2endzone.com/download/2235/)
* [ 3S 3600mAh Lipo Battery.fzpz](http://www.end2endzone.com/download/2233/)

The project files are also available for download. Click the following link to get the _Fritzing project files_ for this project:

* [ DIY lost plane alarm finder and 10 watts LED visual aids for easy orientation.fzz](http://www.end2endzone.com/download/2240/)

## Circuit Diagram

The following section shows the circuit diagram layout

[![Quadcopter Controller Project - Schematics view](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics.png)](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_schematics.png)

Quadcopter Controller Project - Schematics view

## Breadboard Layout

The following section shows a breadboard layout view of the circuit.

[![Quadcopter Controller Project - Breadboard view](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png)](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png)

Quadcopter Controller Project - Breadboard view

# Code

The following section defines the required libraries for compiling the main arduino sketch available below.

## External libraries

The code on the arduino requires multiple external arduino libraries. The following list shows all required software libraries and their related use as part of this project:

| Name                                                                                                                                                                    | Version                                                 | Usage                                                                                             |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| [SoftTimers](http://www.end2endzone.com/softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/)&nbsp;<sup>5</sup>            | v1.1.219                                                | Required for all computation and handling of the LED's ON and OFF times.                          |
| [RcReceiverSignal](http://www.end2endzone.com/rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/)&nbsp;<sup>8</sup> | v1.2.203                                                | Required to read PWM signals sent<br /> from the RC Receiver.                                     |
| [AnyRtttl](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/)&nbsp;<sup>7</sup>                                            | v2.1                                                    | Required to play RTTTL melodies data.                                                             |
| [PinChangeInt](http://github.com/GreyGnome/PinChangeInt)                                                                                                                | version 2402                                            | RcReceiverSignal library has a dependency<br /> to PinChangeInt library.                          |
| [eRCaGuy Timer2 Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)                                          | version 20140709<br /> (last updated<br /> 9 July 2014) | Required to have a micros() replacement function<br /> which has a 1µs resolution instead of 4µs. |


## Arduino sketch

Here is the brain of the project. Source code!

Click the following to download the example below:  
(download 
	[ Quad Controller v1.0.240.ino](http://www.end2endzone.com/download/2263/ "Version 1.0.240"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/10/QuadCtrl-v1.0.240.ino" lang="cpp" >}}

# Building steps

[![building-steps](http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps.png)](http://www.end2endzone.com/wp-content/uploads/2016/10/Building-steps.png)

The following section explains all the different steps on how to build my DIY quadcopter visual aids controller.

## Install code on arduino

Before attempting run the given code on the arduino, you must first install the required libraries. Please follow the [How to Install a Library](http://www.arduino.cc/en/Guide/Libraries#toc2) guide available on the arduino web site.

Download links for required libraries are available in the [External Libraries](#External_libraries) or [References](#References) sections.

Upload the main arduino sketch to the arduino and proceed with the next step.

## Setup transmitter (Tx) mixes

As explained [above](#Microcontroller),  this project innovation relies on the fact that **both devices** are controlled by the quadcopter transmitter using only a **single channel**. This is achieved by configuring custom mixes on the transmitter.

To know more about how mixes can be used to control more than one device with the help of a microcontroller, read the following article:&nbsp;[How to multiplex RC Transmitter switches into a single channel](/how-to-multiplex-rc-transmitter-switches-into-a-single-channel/).

As a reference, here are the mixes that I use for my Spektrum DX9 transmitter:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 240px;" colspan="5" width="220">AUX1 Mix info</td>
    <td style="width: 80px;" colspan="3" width="80">Mix Output</td>
  </tr>
  <tr class="headerrow">
    <td>Number</td>
    <td>Switch</td>
    <td>High</td>
    <td>Low</td>
    <td>Offset</td>
    <td></td>
    <td>1</td>
    <td>2</td>
  </tr>
  <tr>
    <td></td>
    <td>Right knob</td>
    <td>-74</td>
    <td></td>
    <td>-99</td>
    <td>-147</td>
    <td>-73</td>
    <td></td>
  </tr>
  <tr>
    <td>1</td>
    <td>Right knob</td>
    <td></td>
    <td>54</td>
    <td>100</td>
    <td></td>
    <td>-54</td>
    <td>-108</td>
  </tr>
  <tr>
    <td colspan="5"></td>
    <td style="background-color: #f7f497;">-147</td>
    <td style="background-color: #f7f497;">-127</td>
    <td style="background-color: #f7f497;">-108</td>
  </tr>
  <tr>
    <td>2</td>
    <td>H</td>
    <td></td>
    <td>-69</td>
    <td>100</td>
    <td></td>
    <td>-</td>
    <td>138</td>
  </tr>
  <tr>
    <td>3</td>
    <td>G</td>
    <td></td>
    <td>-46</td>
    <td>100</td>
    <td></td>
    <td>46</td>
    <td>92</td>
  </tr>
</table>

{{< pleasenote >}}
  Note that the following mixes must match the [demultiplexing  code](#Arduino_sketch)&nbsp;running on the arduino. If you do not use the code "as is", then you must also adjust your transmitter mixes to reflect the change.
{{< /pleasenote >}}


## Build a prototype

[![DIY Quadcopter lost plane alarm finder and 10w LED visual aids Prototype](http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/07/DIY-Quadcopter-lost-plane-alarm-finder-and-10w-LED-visual-aids-Prototype.jpg)

DIY Quadcopter lost plane alarm finder and 10w LED visual aids Prototype

The purpose of these steps is to evaluate the feasibility of the project by implementing a smaller scale of the project as a proof of concept even though that at this point you should already know that the project is viable since I already completed all steps and the controller is actually running on my personal quadcopter.

### Test the code

[![QuadCtrl - Testing the code in Arduino IDE](http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency.png)](http://www.end2endzone.com/wp-content/uploads/2016/10/QuadCtrl-Arduino-IDE-transparency.png)

QuadCtrl - Testing the code in Arduino IDE

The purpose of this step is to quickly identify issue with the code as no other parts (besides the arduino itself) of the final circuit is used. Code issues are the one that should be addressed first. This step confirms that the arduino is able to read an arbitrary PWM signal and process it.

Build the circuit as showed by the picture above. For reference, the yellow and blue wires matches the blue and orange wire of the breadboard layout. These wires are connected to pins which drives low LEDs instead of high current mosfets. The prototype uses a simple CCPM Servo Tester for emulating the 6-ch receiver. In this configuration, the red LED matches the 10W front LED and the green LED matches the buzzing state.

Power the arduino using USB power. By changing the position of the CCPM Servo tester potentiometer, you should observe different behavior of each LEDs for each position of CCPM tester.

{{< pleasenote >}}
  Note that since the code is already debugged, I do not expect anything to go wrong and things should be addressed easily. If you do observe issues, please verify your connections or the version used by each library dependencies.
{{< /pleasenote >}}


### Tx/Rx prototype integration

For a greater testing, connect your receiver and use your transmitter to change the PWM signal sent to the microcontroller.

This step verifies the quality (or precision of the signal) of the transmitter/receiver pair. It also helps validating that you configured the right mixes in your transmitter to independently control the LED and the buzzer.

### Test each component (optional)

Now that you know that the code is working as expected, you may want to test each components before [soldering them](#Solderingcomponents_on_thestripboard) on the breadboard.

The final step is to integrate all real components to the breadboard prototype and use external 12v power supply (to mimic a 3S LiPo battery).

[![Quadcopter Controller Project - Breadboard view](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png)](http://www.end2endzone.com/wp-content/uploads/2016/07/Quad_Controller_breadboard.png)

Complete the actual circuit as defined in [Breadboard Layout](#Breadboard_Layout)&nbsp;section.

## Solder components

[![QuadCtrl - Soldering components to the stripboard](http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4566.jpg)

QuadCtrl - Soldering components to the stripboard

Define the position of every components on the prototyping stripboard. You should have enough room for all components and if you plan correctly, you may still have space left and be able to cut 1 or 2 cm from the sides to save additional size and weight.

Note that both mosfet do not require a heat sink. However, you may want to fold both mosfet so that the height of the total package is as low as possible so that it may fit properly inside a small cavity of the quadcopter.

Position the arduino's USB port facing outside so that when you need to update the software, you can simply connect the package to a computer without having to disassemble or disconnect the unit from the quadcopter.

For the same reason, solder the male servo extension lead and the JST battery connector to the other side since those will require to be as close as possible to the quadcopter's controller and battery.

Solder each component carefully following the schematics and head to the final step.

## Secure the unit on the quadcopter

[![QuadCtrl - Securing components with wrapping foam](http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/10/IMG_4557.jpg)

QuadCtrl - Securing components with wrapping foam

Once everything is ready for flight, attach the package on the quadcopter. Connect JST battery connector and each signal wire cable.

Since I was planning on removing the device for maintenance, I didn't used glue (or anything permanent) for securing the package to the frame. Instead I used zip ties which are used for both wrapping the foam around the stripboard and attaching to the frame's front grooves.

I also used zip ties to attach the wood BBQ skewers to the pre-drilled holes in the fuselage.

For best result, position the 10w LED below the propeller's wind blast. This will greatly increase the lifespan of the LED since it will always be properly cooled while turned on.

## Final Result

Here is the final result:

[![Arduino Quadcopter LED & Buzzer Controler (final)](http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final.jpg)

Arduino Quadcopter LED & Buzzer Controler (final)

[![Arduino Quadcopter LED & Buzzer Controler (final) - Close Up](http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/08/Arduino-Quadcopter-Controler-final-close-up.jpg)

Arduino Quadcopter LED & Buzzer Controler (final) - Close Up

# Made anything differently?

The features of the device are fulfilling the main objectives and there is no actual need to change anything. However, there are lots of aspect of the design that could be improved. After completing this project, I though of multiple ideas that could bring the design to a higher quality level.

At the beginning of the project, I was not much concerned about weight since I was evaluating the feasibility of the project and I didn't design the device to be something that would actually be flying. Now that it is completed, I would like to put more effort trying to reduce the total weight.

Here are most aspects that I would like to improve:

## Better signal wires

Signal wires could be much improved.

First, they are way too big. The wires for the receiver signal between the 6-ch receiver (Rx) and the arduino could be made smaller. Only a small current is used to carry the signal so there is no need for not using the smallest wires available.

Second, not all wires are actually used. At the beginning of the design, I though of using the arduino to read multiple channels. In the picture above, the red and blue wires were designed to read 2 more PWM signals which would make the arduino able to decode 3 different channels. The blue and red wires are wasted grams I could save.

Finally, the length of the wires is 3-4 times longer than they actually need. When I was prototyping, it was actually convenient to have longer cable that could connect the receiver but once the unit is attached to the quadcopter, the device is almost next to the receiver and the need for longer wires is not much required anymore. The same also applies for the LED wires which had to be folded many times because they were too long.

## Other LED options?

I still doubt that a single super strong LED is the way to go. In the near future, I might consider having multiple on-board middle-range LED and I am curious to see if multiple LEDs would produce more lumens than a single one. In the idea, having 2 or 3 smaller LED may make the whole thing more visible at greater distance. I may investigate other LED options which offers a better watt-to-lumens ratio.

If I ever choose to go with 2 or 3 smaller LED instead of a single super strong LED, I may also get rid of the current limiting circuit. The circuit is not particularly heavy but using smaller LED (which consumes less power), would allow me to replace the circuit by smaller/lighter resistance connected to each LED. I know that each resistance might not be super efficient (lots of heat dissipation) but it is negligible when compared to the enormous amount of energy consumed by the motors. A linear voltage regulator like the [LM317](https://www.google.ca/search?q=lm317&source=lnms&tbm=isch) might also simplify the circuit and prevent too much heat dissipation.

## Smaller form factor

Getting rid of the stripboard would also be in my plans. Now that I know the whole circuit does not required too much connections, I am now thinking of completely removing the stripboard. This would require to hot glue both the mosfets and the current limiting circuit directly to the arduino. If done properly, the amount of hot glue required should be lighter than the stripboard.

At the same time, the device would be smaller which could make it usable on other platforms like ones with a hard shell cover.

## Signal (de)multiplexing nessesary?

Short answer, no.

Actually, I do not require to have an on-board arduino on the quad. There was no actual need to implement signal multiplexing and demultiplexing. To get the same functionality, I could have simply used an 8-channels receiver and the need for multiplexing/demultiplexing would be gone.

The main reason for this project was fun. **_'All work and no play makes Antoine a dull boy'_**. The project turned out more complicated than I first through and I had to invest a lot of my free time to code, test and to make it up to this point. Without the 'fun' part, this project would never went further than ideas on a sheet of paper. If I ever have to rebuild this project, the fun part would still be the first and primary goal of the project!

## Modular design

For maintainability, portability and reusability reasons, it might be interesting to subdivide the device into modules (smaller reusable parts).

For instance the demultiplexor could be a perfect candidate for reusability. It could be reused on other platforms like airplanes to control non-critical flight accessories like landing lights where front, wings and tail lights could be controlled by a single channel.

The LED and buzzer could also be made into modules. Each or both could be modified to be directly connected to a dedicated channel on the receiver. If I ever upgrade the quadcopter to a 8-channels (or more) receiver, I could still use the LED and the buzzer without requiring the demultiplexor part.

# References

Here is the list of all sub-articles that made this project a reality:

Documentation:

  1. [How to multiplex RC Transmitter switches into a single channel](http://www.end2endzone.com/how-to-multiplex-rc-transmitter-switches-into-a-single-channel/).
  2. [Mapping RC Transmitter PWM signal to actual transmitter values](http://www.end2endzone.com/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/).
  3. [Demystifying RC Transmitter Mixing](http://www.end2endzone.com/demystifying-rc-transmitter-mixing/).
  4. [RC Transmitter Mix Calculator](http://www.end2endzone.com/rc-transmitter-mix-calculator/).

Arduino libraries:

* [SoftTimers – A collection of software timers to easily compute elapsed time since an event occurred](http://www.end2endzone.com/softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/).
  1. [libRtttl – A c++ library (with UI) for compressing/optimizing the RTTTL audio format](http://www.end2endzone.com/librtttl-a-c-library-with-ui-for-compressingoptimizing-the-rtttl-audio-format/).
  2. [AnyRtttl – A feature rich arduino library for playing RTTTL melodies](http://www.end2endzone.com/anyrtttl-a-feature-rich-arduino-library-for-playing-rtttl-melodies/).
  3. [RcReceiverSignal: an arduino library for retrieving the RC Transmitter value from an RC Receiver pulse](http://www.end2endzone.com/rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/).

# Notes

none
