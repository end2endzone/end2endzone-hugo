---
title: 'RcReceiverSignal: an arduino library for retrieving the RC Transmitter value from an RC Receiver pulse'
author: end2end
date: 2016-03-30T17:05:59+00:00
url: /rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/
images:
  - src: /wp-content/uploads/2016/03/Arduino-RcReceiverSignal-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Library:
        * [[download id="1792" template="title"]](/download/1792/)
        Example:
        * [[download id="1794" template="title"]](/download/1794/)
        
hits:
  - 1609
categories:
  - Development
  - Model Aeronautics
tags:
  - arduino
  - arduino library
  - english
  - open source
  - RC
  - RC transmitter

---
# Introduction

The following arduino library was written to use the findings found during the _**[Mapping RC Transmitter PWM signal to actual transmitter values](/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/){.row-title}**_&nbsp;article. All results were wrapped into a library for ease of use.

The RcReceiverSignal is an arduino library that allows one to read a signal sent from a Remote Controlled (RC) receiver.

Skip to the [download section](#Download) for quick download.

# Purpose

The RcReceiverSignal library allows one to easily configure an input pin to read a PWM signal sent from a RC receiver by attaching a RcReceiverSignal instance to a pin connected the receiver and automatically monitor each pulse sent by the receiver.

It allows the main loop to retrieve the latest received pulse length (PWM) and convert the pulse length back to the actual transmitter signal value (ranging from -150% to 150%).

The library supports automatic PWM signal change detection. The library's ability to convert a PWM value to the actual transmitter numeric value is based on empirical tests available at _**[Mapping RC Transmitter PWM signal to actual transmitter values](/mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/){.row-title}.**_

# Library features

Possible use are:

* Allows one to get the latest PWM value sent from the RC receiver.
* Automatically handles interrupt protection.
* Automatic ISR handling. All required code automatically generated.
* Allows one to convert a pulse length (PWM) back to the original transmitter value.
<li>
  Supports multiple Transmitter/Receiver combination: <li>
      Spektrum DX9 tx + Spektrum AR8000 rx
    </li>
    * Spektrum DX9 tx +&nbsp;Orange R620X rx
    * Tactic TTX600 tx +&nbsp;Tactic TR624 rx
    * CCPM Servo Tester
</li>

* Supports [eRCaGuy_Timer2_Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)&nbsp;0.5µs (or the native _micros()_ function)&nbsp;for timing calculations.

# Library dependencies

## [PinChangeInt](https://github.com/GreyGnome/PinChangeInt)

This library allows the arduino to attach interrupts on multiple pins.

## [eRCaGuy_Timer2_Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)

(optional)  
This library configures the arduino's timer2 to 0.5µs precision. It is used for a _micros()_&nbsp;function replacement and allows times calculations that are far more precise (8 times!) than the default's 4µs resolution.

# Usage

Use the DECLARE_RECEIVER_SIGNAL macro to declare an instance of RcReceiverSignal. ie:


```cpp
DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);
DECLARE_RECEIVER_SIGNAL(receiver_throttle_handler);
```


Each macro will automatically declare the following:

* RcReceiverSignal receiver_aux1_handler;
* receiver_aux1_handler_setup() function.
* receiver_aux1_handler_pin_change() ISR function.

In the _setup()_ function, you need to configure each instance by calling the _receiver_aux1_handler_setup()_ function with the interrupt pin as argument. ie:


```cpp
receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);
receiver_throttle_handler_setup(RECEIVER_THROTTLE_IN_PIN);
```


In the loop function, one can call the _hasChanged() m_ethod to know if the PWM value has changed since the last call or call the _getPwmValue()_ function to get the last PWM value observed by the _RcReceiverSignal_ instance.

From a PWM value, one can call the _getSignalValue()_ or _getDeviceSignalValue()_ methods to convert a given PWM signal from a known device combination to a transmitter value (within -150% to +150%).

## Demo

The following demo show how to use the library:  
(download the 
	[ RcReceiverSignal v1.1.203 LedUpdate demo.ino (572 downloads) ](http://www.end2endzone.com/download/1794/ "Version 1.1.203"))

{{< hightlight-static-file file="/static/wp-content/uploads/2016/03/RcReceiverSignal-v1.1.203-LedUpdate.ino" lang="" >}}

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the RcReceiverSignal arduino library by clicking on the following link:


		[ Download "RcReceiverSignal arduino library v1.1.203" RcReceiverSignal-v1.1.203.zip - Downloaded 664 times - 59 KB ](http://www.end2endzone.com/download/1792/)
