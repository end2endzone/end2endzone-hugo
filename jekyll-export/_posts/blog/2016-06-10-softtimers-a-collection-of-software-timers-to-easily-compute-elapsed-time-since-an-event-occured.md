---
title: SoftTimers – A collection of software timers to easily compute elapsed time since an event occurred
author: end2end
date: 2016-06-10T20:14:19+00:00
url: /softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/
images:
  - src: /wp-content/uploads/2016/06/Arduino-SoftTimers-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    Downloads available in this article:
    Library:
    * [[download id="2089" template="title"]](/download/2089/)
    Examples:
    * [[download id="2109" template="title"]](/download/2109/)
    * [[download id="2105" template="title"]](/download/2105/)
    * [[download id="2107" template="title"]](/download/2107/)
    * [[download id="2111" template="title"]](/download/2111/)
hits:
  - 827
categories:
  - Development
tags:
  - arduino
  - arduino library
  - c++
  - english
  - open source

---

# Introduction

The following article is about my simplest library that I wrote for the arduino: *SoftTimers*. The *SoftTimers* arduino library allows one to properly time multiple events and know when each "timer" expires meaning that an action is required. Skip to the [download section](#Download) for quick download. When I first learned programming the arduino, I learned the "*hello world*" of the arduino: turning a LED on and off. As expected, I used `delay()` to define how long the LED should be on and off. However, this approach is bad since it break the "realtime" property of the software to react to other event. If I want to make the LED instantly turn off when pressing a button, I had to wait for the delay to complete before processing the button. (I know you could use interrupts and update with LED pin within the interrupt but that is out of scope for now.) Another issue is extensibility. Making 3 LEDs blink at different time interval is much harder with delays. How about 40 LEDs? Impossible? This is where SoftTimers arduino library becomes helpful.

# Purpose

The SoftTimers allows one to properly time multiple events and know when each "timer" expires meaning that an action is required. In this example above, a SoftTimer expires when it is time to toggle an LED. SoftTimers also provide the elapsed time since an event occurred. In case of an interruption, the elapsed time can be used as debugging information. It can also be used as a countdown information displayed to the user. The library regroups basic timer functionalities into a single class. The usual way to get the same functionality is to create multiple variables for each single timer. This way is hard to maintain when you need multiple timers are required to run at the same time. SoftTimer classes are designed to be keep "simple &amp; stupid". No software interrupts. Non-blocking. Each timer must be polled within the loop() to know their status.

# Library features

Here is a list of all library features:

- Provides the non-blocking equivalent to blocking `delay()` function.
- Each timers encapsulate its own expiration (timeout) time.
- Provides elapsed time, remaining time and progress (in percentage) APIs.
- Supports milliseconds, microseconds or any other arbitrary time with external time counting function.
- Provides expiration loop count API (as if timer never expire and automatically `reset()`) to easily implement toggling, and time based state machines.
- Automatically handles `micros()` an `millis()` overflows / wrap around special cases.

# Usage

## Basic Usage

Call `setTimeOutTime()` to setup the non-blocking SoftTimer then call `reset()` to restart the internal counter. Within the `loop()`, use `hasTimedOut()` to know if the timer has expired. At any moment, call `getElapsedTime()` to get the absolute elapsed time since the last `reset()`.

## Fade a LED

Fading a LED like [arduino's Built-in Fade Example](https://www.arduino.cc/en/Tutorial/Fade) is trivial using SoftTimers. The library helps in defining the constant speed at which the LED will fade by defining the total length of the process and by easily mapping the timer "progress" to the amount of fade (PWM) used with the output pin. All of this in a non-blocking manner. The following example increases the intensity of a LED from OFF to ON in 1 second and then decreases the intensity of the LED back to OFF in 1 second.

Demo:

Click the following to download the example below:

{{% download old-id="2109" href="/wp-content/uploads/2016/06/SoftTimers-v1.1.219-FadeLed-demo.ino" %}}SoftTimers-v1.1.219-FadeLed-demo.ino{{% /download %}}

{{< hightlight-static-file file="/static/wp-content/uploads/2016/06/SoftTimers-v1.1.219-FadeLed-demo.ino" lang="cpp" >}}

## Countdown or Elapsed time

Any program that need to display a countdown or compute the elapsed time between two events can also benefit from SoftTimers. The following example runs a countdown of 5 seconds and then turns a LED on.

Demo:

Click the following to download the example below:

{{% download old-id="2105" href="/wp-content/uploads/2016/06/SoftTimers-v1.1.219-Countdown-demo.ino" %}}SoftTimers-v1.1.219-Countdown-demo.ino{{% /download %}}

{{< hightlight-static-file file="/static/wp-content/uploads/2016/06/SoftTimers-v1.1.219-Countdown-demo.ino" lang="cpp" >}}

## Timed repetitive cycles

SoftTimer library also help reducing repetitive timed cycles to their simplest non-blocking form. SoftTimer library automatically computes current cycle index. Any toggling or cycle scenarios can be implemented with very few lines of code. The following example implements a system where a single HIGH pin must be cycled every second within multiple pins as defined by the following loop:

- set pin 8, 9 and 13 to LOW, LOW and HIGH respectively and then wait 1 second.
- set pin 8, 9 and 13 to HIGH, LOW and LOW respectively and then wait 1 second.
- set pin 8, 9 and 13 to LOW, HIGH and LOW respectively and then wait 1 second.
- repeat the cycle forever...

Demo:

Click the following to download the example below:

{{% download old-id="2107" href="/wp-content/uploads/2016/06/SoftTimers-v1.1.219-CycleHighPin-demo.ino" %}}SoftTimers-v1.1.219-CycleHighPin-demo.ino{{% /download %}}

{{< hightlight-static-file file="/static/wp-content/uploads/2016/06/SoftTimers-v1.1.219-CycleHighPin-demo.ino" lang="cpp" >}}

## Timed restricted state machines

SoftTimer library allows one to make an easy abstraction of time when dealing with timed restricted state machines. The following example implement an hypothetical state machine where each state has a maximum duration:

- State #1 - IDLE (1000 ms)
- State #2 - LISTENING (200 ms)
- State #3 - SYNCHRONIZING (500 ms)
- State #4 - UPDATING (300 ms)
- State #1 ....

Demo:

Click the following to download the example below:

{{% download old-id="2111" href="/wp-content/uploads/2016/06/SoftTimers-v1.1.219-StateMachine-demo.ino" %}}SoftTimers-v1.1.219-StateMachine-demo.ino{{% /download %}}

{{< hightlight-static-file file="/static/wp-content/uploads/2016/06/SoftTimers-v1.1.219-StateMachine-demo.ino" lang="cpp" >}}

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA **DISCLAIMER:**This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download the SoftTimers arduino library by clicking on the following link:

{{% download old-id="2089" href="https://github.com/end2endzone/SoftTimers/archive/refs/tags/2.1.0.zip" %}}SoftTimers v2.1.0.zip{{% /download %}}
