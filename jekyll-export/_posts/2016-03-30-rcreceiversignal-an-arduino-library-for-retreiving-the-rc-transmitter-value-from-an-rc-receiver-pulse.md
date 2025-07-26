---
id: 1251
title: 'RcReceiverSignal: an arduino library for retrieving the RC Transmitter value from an RC Receiver pulse'
date: '2016-03-30T13:05:59+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1251'
permalink: '/?p=1251'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Library:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1792/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"1792\" template=\"title\"]</a></li>\n</ul>\n</div>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Example:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1794/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"1794\" template=\"title\"]</a></li>\n</ul>\n</div>\n"
hits:
    - '1906'
image: /wp-content/uploads/2016/03/Arduino-RcReceiverSignal-library.jpg
categories:
    - Development
    - 'Model Aeronautics'
tags:
    - arduino
    - 'arduino library'
    - english
    - 'open source'
    - RC
    - 'RC transmitter'
---

# Introduction

The following arduino library was written to use the findings found during the ***[Mapping RC Transmitter PWM signal to actual transmitter values](/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/ "Edit “Mapping RC Transmitter PWM signal to actual transmitter values”")*** article. All results were wrapped into a library for ease of use. The RcReceiverSignal is an arduino library that allows one to read a signal sent from a Remote Controlled (RC) receiver. Skip to the [download section](#Download) for quick download.

# Purpose

The RcReceiverSignal library allows one to easily configure an input pin to read a PWM signal sent from a RC receiver by attaching a RcReceiverSignal instance to a pin connected the receiver and automatically monitor each pulse sent by the receiver. It allows the main loop to retrieve the latest received pulse length (PWM) and convert the pulse length back to the actual transmitter signal value (ranging from -150% to 150%). The library supports automatic PWM signal change detection. The library's ability to convert a PWM value to the actual transmitter numeric value is based on empirical tests available at ***[Mapping RC Transmitter PWM signal to actual transmitter values](/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/ "Edit “Mapping RC Transmitter PWM signal to actual transmitter values”").***# Library features

Possible use are:

- Allows one to get the latest PWM value sent from the RC receiver.
- Automatically handles interrupt protection.
- Automatic ISR handling. All required code automatically generated.
- Allows one to convert a pulse length (PWM) back to the original transmitter value.
- Supports multiple Transmitter/Receiver combination: 
    - Spektrum DX9 tx + Spektrum AR8000 rx
    - Spektrum DX9 tx + Orange R620X rx
    - Tactic TTX600 tx + Tactic TR624 rx
    - CCPM Servo Tester
- Supports [eRCaGuy\_Timer2\_Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html) 0.5µs (or the native *micros()* function) for timing calculations.

# Library dependencies

## [PinChangeInt](https://github.com/GreyGnome/PinChangeInt)

This library allows the arduino to attach interrupts on multiple pins.

## [eRCaGuy\_Timer2\_Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)

(optional) This library configures the arduino's timer2 to 0.5µs precision. It is used for a *micros()* function replacement and allows times calculations that are far more precise (8 times!) than the default's 4µs resolution.

# Usage

<span style="line-height: 1.5;">Use the DECLARE\_RECEIVER\_SIGNAL macro to declare an instance of RcReceiverSignal. ie:</span>```
DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);
DECLARE_RECEIVER_SIGNAL(receiver_throttle_handler);
```

<span style="line-height: 1.5;">Each macro will automatically declare the following:</span>- <span style="line-height: 1.5;">RcReceiverSignal receiver\_aux1\_handler;</span>
- <span style="line-height: 1.5;">receiver\_aux1\_handler\_setup() function.</span>
- <span style="line-height: 1.5;">receiver\_aux1\_handler\_pin\_change() ISR function.</span>

<span style="line-height: 1.5;">In the *setup()* function, you need to configure each instance by calling the *receiver\_aux1\_handler\_setup()* function with the interrupt pin as argument. ie:</span>```
receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);
receiver_throttle_handler_setup(RECEIVER_THROTTLE_IN_PIN);
```

<span style="line-height: 1.5;">In the loop function, one can call the *hasChanged() m*ethod </span><span style="line-height: 1.5;">to know if the PWM value has changed since the last call or call the *getPwmValue()* function to get the last PWM value observed by the *RcReceiverSignal* instance.</span><span style="line-height: 1.5;">From a PWM value, one can call the *getSignalValue()* or *getDeviceSignalValue()* methods to convert a given PWM signal from a known device combination to a transmitter value (within -150% to +150%).</span>## Demo

The following demo show how to use the library: (download the \[download id="1794"\])

```
https://www.end2endzone.com/wp-content/uploads/2016/03/RcReceiverSignal-v1.1.203-LedUpdate.ino
```

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA **DISCLAIMER:**This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the RcReceiverSignal arduino library by clicking on the following link: \[download id="1792" template="button"\]