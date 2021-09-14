---
title: 'RcReceiverSignal: an arduino library for retrieving the RC Transmitter value from an RC Receiver pulse'
author: end2end
type: post
date: 2016-03-30T17:05:59+00:00
url: /rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/
featured_image: /wp-content/uploads/2016/03/Arduino-RcReceiverSignal-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Library:</p>
        <ul class="fa-ul">
        <li><a href="/download/1792/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="1792" template="title"]</a></li>
        </ul>
        </div>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Example:</p>
        <ul class="fa-ul">
        <li><a href="/download/1794/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="1794" template="title"]</a></li>
        </ul>
        </div>
        
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
# <span id="Introduction">Introduction</span>

The following arduino library was written to use the findings found during the _**[Mapping RC Transmitter PWM signal to actual transmitter values][1]{.row-title}**_ article. All results were wrapped into a library for ease of use.

The RcReceiverSignal is an arduino library that allows one to read a signal sent from a Remote Controlled (RC) receiver.<!--more-->

Skip to the [download section][2] for quick download.

# <span id="Purpose">Purpose</span>

The RcReceiverSignal library allows one to easily configure an input pin to read a PWM signal sent from a RC receiver by attaching a RcReceiverSignal instance to a pin connected the receiver and automatically monitor each pulse sent by the receiver.

It allows the main loop to retrieve the latest received pulse length (PWM) and convert the pulse length back to the actual transmitter signal value (ranging from -150% to 150%).

The library supports automatic PWM signal change detection. The library&#8217;s ability to convert a PWM value to the actual transmitter numeric value is based on empirical tests available at _**[Mapping RC Transmitter PWM signal to actual transmitter values][1]{.row-title}.**_

# <span id="Library_features">Library features</span>

Possible use are:

<li style="text-align: justify;">
  Allows one to get the latest PWM value sent from the RC receiver.
</li>
<li style="text-align: justify;">
  Automatically handles interrupt protection.
</li>
<li style="text-align: justify;">
  Automatic ISR handling. All required code automatically generated.
</li>
<li style="text-align: justify;">
  Allows one to convert a pulse length (PWM) back to the original transmitter value.
</li>
<li style="text-align: justify;">
  Supports multiple Transmitter/Receiver combination: <ul>
    <li style="text-align: justify;">
      Spektrum DX9 tx + Spektrum AR8000 rx
    </li>
    <li style="text-align: justify;">
      Spektrum DX9 tx + Orange R620X rx
    </li>
    <li style="text-align: justify;">
      Tactic TTX600 tx + Tactic TR624 rx
    </li>
    <li style="text-align: justify;">
      CCPM Servo Tester
    </li>
  </ul>
</li>

<li style="text-align: justify;">
  Supports <a href="http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html">eRCaGuy_Timer2_Counter</a> 0.5µs (or the native <em>micros()</em> function) for timing calculations.
</li>

# <span id="Library_dependencies">Library dependencies</span>

## <span id="PinChangeInt"><a href="https://github.com/GreyGnome/PinChangeInt">PinChangeInt</a></span>

This library allows the arduino to attach interrupts on multiple pins.

## <span id="eRCaGuy_Timer2_Counter"><a href="http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html">eRCaGuy_Timer2_Counter</a></span>

(optional)  
This library configures the arduino&#8217;s timer2 to 0.5µs precision. It is used for a _micros()_ function replacement and allows times calculations that are far more precise (8 times!) than the default&#8217;s 4µs resolution.

# <span id="Usage">Usage</span>

<span style="line-height: 1.5;">Use the DECLARE_RECEIVER_SIGNAL macro to declare an instance of RcReceiverSignal. ie:</span>

<pre class="lang:c++ decode:true">DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);
DECLARE_RECEIVER_SIGNAL(receiver_throttle_handler);
</pre>

<span style="line-height: 1.5;">Each macro will automatically declare the following:</span>

<li style="text-align: justify;">
  <span style="line-height: 1.5;">RcReceiverSignal receiver_aux1_handler;</span>
</li>
<li style="text-align: justify;">
  <span style="line-height: 1.5;">receiver_aux1_handler_setup() function.</span>
</li>
<li style="text-align: justify;">
  <span style="line-height: 1.5;">receiver_aux1_handler_pin_change() ISR function.</span>
</li>

<span style="line-height: 1.5;">In the <em>setup()</em> function, you need to configure each instance by calling the <em>receiver_aux1_handler_setup()</em> function with the interrupt pin as argument. ie:</span>

<pre class="lang:c++ decode:true">receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);
receiver_throttle_handler_setup(RECEIVER_THROTTLE_IN_PIN);</pre>

<span style="line-height: 1.5;">In the loop function, one can call the <em>hasChanged() m</em>ethod </span><span style="line-height: 1.5;">to know if the PWM value has changed since the last call or call the <em>getPwmValue()</em> function to get the last PWM value observed by the <em>RcReceiverSignal</em> instance.</span>

<span style="line-height: 1.5;">From a PWM value, one can call the <em>getSignalValue()</em> or <em>getDeviceSignalValue()</em> methods to convert a given PWM signal from a known device combination to a transmitter value (within -150% to +150%).</span>

## <span id="Demo">Demo</span>

The following demo show how to use the library:  
(download the 
	<a class="download-link" title="Version 1.1.203" href="http://www.end2endzone.com/download/1794/" rel="nofollow"> RcReceiverSignal v1.1.203 LedUpdate demo.ino (572 downloads) </a>)

<pre class="lang:default decode:true" title="RcReceiverSignal v1.1.203 LedUpdate.ino" data-url="http://www.end2endzone.com/wp-content/uploads/2016/03/RcReceiverSignal-v1.1.203-LedUpdate.ino">http://www.end2endzone.com/wp-content/uploads/2016/03/RcReceiverSignal-v1.1.203-LedUpdate.ino</pre>

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the RcReceiverSignal arduino library by clicking on the following link:


		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/1792/" rel="nofollow"> Download &ldquo;RcReceiverSignal arduino library v1.1.203&rdquo; <small>RcReceiverSignal-v1.1.203.zip &ndash; Downloaded 664 times &ndash; 59 KB</small> </a>

 [1]: /mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/ "Edit “Mapping RC Transmitter PWM signal to actual transmitter values”"
 [2]: #Download