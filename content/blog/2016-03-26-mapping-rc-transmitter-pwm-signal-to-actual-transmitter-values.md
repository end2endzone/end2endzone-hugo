---
title: Mapping RC Transmitter PWM signal to actual transmitter values
author: end2end
date: 2016-03-26T20:47:29+00:00
url: /mapping-rc-transmitter-pwm-signal-to-actual-transmitter-values/
images:
  - src: /wp-content/uploads/2016/03/Mapping-RC-Transmitter-PWM-signal-to-actual-transmitter-values.jpg
hits:
  - 2780
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Data capture sessions:
        * [Spektrum DX9 Tx &amp; Orange R620X Rx](/download/1618/)
        * [Spektrum DX9 Tx &amp; Spektrum AR8000 Rx](/download/1620/)
        * [Tactic TTX600 Tx &amp; Tactic TR624 Rx](/download/1614/)
        * [CCPM Servo Tester](/download/1616/)
        
categories:
  - Model Aeronautics
tags:
  - arduino
  - english
  - RC
  - RC transmitter

---
# Introduction

If you ever need to use an RC Transmitter & receiver for a personal project, an easy way to retrieve the signal is to connect the receiver to a micro-controller.

However, decoding the signal to get actual transmitter values is not as easy as it sounds. You need to know the correct encoding and searching on the internet about the subject gives erratic results.

Here is the full article that explains how to correctly map an RC Transmitter PWM signal to actual transmitter values.<!--more-->

# How does it works?

The receiver signal is encoded with a [Pulse Width Modulation](https://en.wikipedia.org/wiki/Pulse-width_modulation). In other way, the transfer of the signal is analog and not digital. This means there is no direct method to read the signal. To accurately read the signal, you need to know the given length of the pulse for each unique transmitter values.

Using benchmark data, I managed to find approximation functions that works for most transmitter values. Multiple benchmark data is available for multiple combination of transmitter and receiver.

# What is expected

If you search on the internet, you will find information regarding [servos](https://en.wikipedia.org/wiki/Servo_%28radio_control%29) which typically uses the same "_kind"_ of PWM signal.  However, as you will see in the next section, the minimum and maximum values for a servo does not match their counterpart on a RC transmitter.

## Theoretical values

Most information sources about [servo control](https://en.wikipedia.org/wiki/Servo_control) states that generally the minimum pulse will be about 1 ms wide and the maximum pulse will be 2 ms wide.

The following table shows the theoretical pulse length for each transmitter values:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td colspan="2">**Expected Transmitter Pulses**</td>
  </tr>
  <tr class="headerrow">
    <td style="width: 100px;" width="60">**Length (µS)**</td>
    <td style="width: 100px;">**Value**</td>
  </tr>
  <tr>
    <td style="width: 60px;" width="60">1000</td>
    <td>-100%</td>
  </tr>
  <tr>
    <td>1500</td>
    <td>0%</td>
  </tr>
  <tr>
    <td>2000</td>
    <td>100%</td>
  </tr>
</table>

## Extrapolation

Knowing that a pulse delta time of 1000 µS (from 1000 µS to 2000 µS) is required to identify 200 different steps (from -100% to +100%), it is then safe to assume that each step is 5 µS. With this calculation, the theoretical pulse length of other values should be identified as follows:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td colspan="2">**Extrapolated Transmitter Pulses**</td>
  </tr>
  <tr class="headerrow">
    <td style="width: 100px;" width="60">**Length (µS)**</td>
    <td style="width: 100px;" width="60">**Value**</td>
  </tr>
  <tr>
    <td>750</td>
    <td>-150%</td>
  </tr>
  <tr>
    <td>875</td>
    <td>-125%</td>
  </tr>
  <tr>
    <td>1125</td>
    <td>-75%</td>
  </tr>
  <tr>
    <td>1250</td>
    <td>-50%</td>
  </tr>
  <tr>
    <td>1375</td>
    <td>-25%</td>
  </tr>
  <tr>
    <td>1625</td>
    <td>25%</td>
  </tr>
  <tr>
    <td>1750</td>
    <td>50%</td>
  </tr>
  <tr>
    <td>1875</td>
    <td>75%</td>
  </tr>
  <tr>
    <td>2125</td>
    <td>125%</td>
  </tr>
  <tr>
    <td>2250</td>
    <td>150%</td>
  </tr>
</table>

WRONG!

&nbsp;

Theoretical values is never as good as real world observations.

# Capture methodology

For the data capture, I used an [Arduino Nano V3](https://www.arduino.cc/en/Main/ArduinoBoardNano) micro-controller. With the help of multiple libraries, I created a program to capture each pulse length of critical target point for a given amount of time. Since the length of each pulse is not perfectly constant, I extracted the average pulse length. Matching different points, I calculated multiple trend line formulas in [polynomial](https://en.wikipedia.org/wiki/Polynomial) format. I then calculate each formula performance against all other points. Finally, I identify the best formula to be used in real projects.

{{< pleasenote >}}
  Note that all raw data capture are available for download as Excel files (*.xlsx) in sections below.
{{< /pleasenote >}}


## Required Libraries

### [PinChangeInt](https://github.com/GreyGnome/PinChangeInt)

This library allows the arduino to attach interrupts on multiple pins.

### [eRCaGuy_Timer2_Counter](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)

This library configures the arduino's timer2 to 0.5µs precision. It is used for a "micros()" function replacement and allows times calculations that are far more precise (8 times!) than the default's 4µs resolution.

## PWM capture code

Here is the final arduino code that allowed raw data capture to extract average pulse length for each critical target point:

{{< hightlight-static-file file="/static/wp-content/uploads/2016/02/RcPwmReader-v95.ino" lang="" >}}

Download the arduino source code: 
	[ RC Transmitter PWM Reader (*.ino) (278 downloads) ](http://www.end2endzone.com/download/1582/ "Version 1.1").

# Benchmark results

The following section show the results of all my data capture sessions. Each device combination show the following information:

**Table 1** 

  1. A given transmitter value.
  2. Average pulse length (in µs) for the given transmitter value.
  3. Minimum and Maximum pulse length for the given transmitter value.
  4. Width of pulses in µs (difference between maximum and minimum length)
  5. Middle pulse length. Middle point between minimum and maximum pulses.

**Table 2<br />**Table 2 shows selected control points and the polynomial function for the selected points. Multiple polynomial functions are found using different control points.

{{< pleasenote >}}
  Note that pulse length from most devices are not perfectly linear. This means that most of the time, more than 2 control points are required to get a polynomial function that is accurate.
{{< /pleasenote >}}


**Table 3<br />**Table 3 shows each function's performance trying to properly predict a transmitter value from a pulse length. The function that offers the best performance is selected as the final function.

{{< pleasenote >}}
  Note that some devices are low quality products and are not always constant or does not provide constant transmitter value.
{{< /pleasenote >}}


# Devices

## Spektrum DX9 Tx & Orange R620X Rx

| <!-- -->                                                                                                                                                                                                                                                                                                                 |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [![Spektrum DX9 9-ch RC Tx](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg "Spektrum DX9 9-ch RC Tx")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg) |
| [![Orange R620X 6-ch RC Rx](http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx.jpg "Orange R620X 6-ch RC Rx")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/02/Orange-R620X-6-ch-RC-Rx.jpg) |


**Table 1<br />**The Spektrum DX9 Tx & Orange R620X Rx shows a PWM range from **827 µs** to **2194 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col /> <col /> <col /> <col span="2" /> <col /> </colgroup> <tr class="headerrow">
    <td colspan="6">Spektrum DX9 Tx &&nbsp;Orange R620X Rx</td>
  </tr>
  <tr class="headerrow">
    <td>Tx</td>
    <td>Avg PWM</td>
    <td>Min</td>
    <td>Max</td>
    <td>Width</td>
    <td>Middle</td>
  </tr>
  <tr>
    <td>150</td>
    <td>2187.85</td>
    <td>2181</td>
    <td>2194</td>
    <td>13</td>
    <td>2187.5</td>
  </tr>
  <tr>
    <td>149</td>
    <td>2180.73</td>
    <td>2175</td>
    <td>2186</td>
    <td>11</td>
    <td>2180.5</td>
  </tr>
  <tr>
    <td>148</td>
    <td>2178.54</td>
    <td>2173</td>
    <td>2184</td>
    <td>11</td>
    <td>2178.5</td>
  </tr>
  <tr>
    <td>147</td>
    <td>2173.86</td>
    <td>2168</td>
    <td>2180</td>
    <td>12</td>
    <td>2174</td>
  </tr>
  <tr>
    <td>146</td>
    <td>2167.92</td>
    <td>2163</td>
    <td>2173</td>
    <td>10</td>
    <td>2168</td>
  </tr>
  <tr>
    <td>100</td>
    <td>1961.01</td>
    <td>1956</td>
    <td>1966</td>
    <td>10</td>
    <td>1961</td>
  </tr>
  <tr>
    <td>50</td>
    <td>1732.35</td>
    <td>1727</td>
    <td>1738</td>
    <td>11</td>
    <td>1732.5</td>
  </tr>
  <tr>
    <td></td>
    <td>1505.40</td>
    <td>1499</td>
    <td>1512</td>
    <td>13</td>
    <td>1505.5</td>
  </tr>
  <tr>
    <td>-50</td>
    <td>1277.65</td>
    <td>1273</td>
    <td>1284</td>
    <td>11</td>
    <td>1278.5</td>
  </tr>
  <tr>
    <td>-100</td>
    <td>1050.22</td>
    <td>1045</td>
    <td>1055</td>
    <td>10</td>
    <td>1050</td>
  </tr>
  <tr>
    <td>-120</td>
    <td>959.43</td>
    <td>954</td>
    <td>964</td>
    <td>10</td>
    <td>959</td>
  </tr>
  <tr>
    <td>-135</td>
    <td>891.52</td>
    <td>887</td>
    <td>896</td>
    <td>9</td>
    <td>891.5</td>
  </tr>
  <tr>
    <td>-146</td>
    <td>841.55</td>
    <td>835</td>
    <td>848</td>
    <td>13</td>
    <td>841.5</td>
  </tr>
  <tr>
    <td>-147</td>
    <td>836.76</td>
    <td>832</td>
    <td>843</td>
    <td>11</td>
    <td>837.5</td>
  </tr>
  <tr>
    <td>-148</td>
    <td>832.02</td>
    <td>827</td>
    <td>837</td>
    <td>10</td>
    <td>832</td>
  </tr>
  <tr>
    <td>-149</td>
    <td>827.47</td>
    <td>822</td>
    <td>833</td>
    <td>11</td>
    <td>827.5</td>
  </tr>
  <tr>
    <td>-150</td>
    <td>826.80</td>
    <td>821</td>
    <td>832</td>
    <td>11</td>
    <td>826.5</td>
  </tr>
</table>

**Table 2<br />**From these values, I extracted the following polynomial functions:

| Polynomial Equation | Py1 | Px1     | Py2  | Px2     | a2       | a1          | a0           |
|---------------------|-----|---------|------|---------|----------|-------------|--------------|
|                     | 150 | 2187.85 | -150 | 826.80  |          | 0.220417088 | -332.2399666 |
| 1                   | 146 | 2167.92 | -135 | 891.52  |          | 0.220149733 | -331.2670095 |
| 2                   | 100 | 1961.01 | -100 | 1050.22 |          | 0.219590069 | -330.6178825 |
| 3                   | 148 | 2178.54 | -148 | 832.016 |          | 0.219825269 | -330.8981407 |
| 4                   | 146 | 2167.92 | -146 | 841.548 |          | 0.2201494   | -331.2662873 |
| 5                   | 149 | 2180.73 | -149 | 827.468 |          | 0.220208326 | -331.2153431 |
| 6                   |     |         |      |         | -8.0E-08 | 0.2203      | -331.37      |


**Table 3<br />**The following table shows details for calculating the performance of each polynomial functions:

| Tx   | Avg PWM | Eq0  | Diff 0 | Eq1  | Diff 1 | Eq2  | Diff 2 | Eq3  | Diff 3 | Eq4  | Diff 4 | Eq5  | Diff 5 | Eq6  | Diff 6 |
|------|---------|------|--------|------|--------|------|--------|------|--------|------|--------|------|--------|------|--------|
| 150  | 2187.85 | 150  |        | 150  | 0.39   | 150  | 0.19   | 150  | 0.05   | 150  | 0.39   | 151  | 0.57   | 150  | 0.23   |
| 149  | 2180.73 | 148  | 0.57   | 149  | 0.18   | 148  | 0.75   | 148  | 0.52   | 149  | 0.18   | 149  |        | 149  | 0.34   |
| 148  | 2178.54 | 148  | 0.05   | 148  | 0.34   | 148  | 0.23   | 148  |        | 148  | 0.34   | 149  | 0.52   | 148  | 0.18   |
| 147  | 2173.86 | 147  | 0.08   | 147  | 0.31   | 147  | 0.26   | 147  | 0.03   | 147  | 0.31   | 147  | 0.49   | 147  | 0.15   |
| 146  | 2167.92 | 146  | 0.39   | 146  |        | 145  | 0.56   | 146  | 0.33   | 146  |        | 146  | 0.18   | 146  | 0.15   |
| 100  | 1961.01 | 100  |        | 100  | 0.45   | 100  |        | 100  | 0.18   | 100  | 0.45   | 101  | 0.61   | 100  | 0.33   |
| 50   | 1732.35 | 50   | 0.4    | 50   | 0.11   | 50   | 0.21   | 50   | 0.08   | 50   | 0.11   | 50   | 0.26   | 50   | 0.03   |
|      | 1505.41 |      | 0.42   |      | 0.15   |      | 0.05   |      | 0.03   |      | 0.15   |      | 0.29   |      | 0.09   |
| -50  | 1277.65 | -51  | 0.62   | -50  | 0.01   | -50  | 0.06   | -50  | 0.04   | -50  | 0.01   | -50  | 0.13   | -50  | 0.03   |
| -100 | 1050.22 | -101 | 0.75   | -100 | 0.06   | -100 |        | -100 | 0.03   | -100 | 0.06   | -100 | 0.05   | -100 | 0.09   |
| -120 | 959.43  | -121 | 0.76   | -120 | 0.05   | -120 | 0.06   | -120 | 0.01   | -120 | 0.05   | -120 | 0.06   | -120 | 0.08   |
| -135 | 891.52  | -136 | 0.73   | -135 |        | -135 | 0.15   | -135 | 0.08   | -135 |        | -135 | 0.1    | -135 | 0.03   |
| -146 | 841.55  | -147 | 0.75   | -146 |        | -146 | 0.18   | -146 | 0.1    | -146 |        | -146 | 0.1    | -146 | 0.03   |
| -147 | 836.76  | -148 | 0.8    | -147 | 0.05   | -147 | 0.13   | -147 | 0.04   | -147 | 0.05   | -147 | 0.05   | -147 | 0.09   |
| -148 | 832.02  | -149 | 0.85   | -148 | 0.1    | -148 | 0.08   | -148 |        | -148 | 0.1    | -148 |        | -148 | 0.13   |
| -149 | 827.47  | -150 | 0.85   | -149 | 0.1    | -149 | 0.09   | -149 |        | -149 | 0.1    | -149 |        | -149 | 0.13   |
| -150 | 826.8   | -150 |        | -149 | 0.75   | -149 | 0.94   | -149 | 0.85   | -149 | 0.75   | -149 | 0.85   | -149 | 0.72   |
|      |         |      | 8.05   |      | 3.04   |      | 3.94   |      | 2.37   |      | 3.04   |      | 4.26   |      | 2.85   |


The table above shows two polynomial functions (see highlighted columns) that offers the best performance :

* Function #3 (which has an order of 1) and a sum of 2.37.
* Function #6 (which has an order of 2) and a sum of 2.85.

Even if function #6 has a sum higher than function #3, the accuracy of function #3 is better since only a single control point does not match the expected values. For example, function #3 evaluates a pwm of 2180.73 µs to 148 while function #6 evaluates to 149 which is correct.

The following polynomial function offers the best performance to compute the _Spektrum DX9 RC Transmitter_ value from the _Orange R620X Rx_ pulse length:

f(x) = -8.0e-8*x<sup>2</sup> +&nbsp;0.2203*x – 331.37

Download the 
	[ Spektrum DX9 Tx & Orange R620X Rx (402 downloads) ](http://www.end2endzone.com/download/1618/ "Version 1.0")&nbsp;full data capture.

## Spektrum DX9 Tx &&nbsp;Spektrum AR8000 Rx

| <!-- -->                                                                                                                                                                                                                                                                                                                 |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [![Spektrum DX9 9-ch RC Tx](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg "Spektrum DX9 9-ch RC Tx")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/02/Spektrum-DX9-9-ch-RC-Tx.jpg) |
| [![Spektrum AR8000 Rx](http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1.jpg "Spektrum AR8000 Rx")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/03/Spektrum-AR8000-Rx-1.jpg)                    |


**Table 1<br />**The Spektrum DX9 Tx & Spektrum AR8000 Rx shows a PWM range from **921 µs** to **2129 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="6" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="6">Spektrum DX9 Tx &&nbsp;Spektrum AR8000 Rx</td>
  </tr>
  <tr class="headerrow" data-headerrow="true">
    <td>Tx</td>
    <td>Avg PWM</td>
    <td>Min</td>
    <td>Max</td>
    <td>Width</td>
    <td>Middle</td>
  </tr>
  <tr>
    <td>150</td>
    <td>2123.57</td>
    <td>2119</td>
    <td>2129</td>
    <td>10</td>
    <td>2124.0</td>
  </tr>
  <tr>
    <td>149</td>
    <td>2119.40</td>
    <td>2113</td>
    <td>2124</td>
    <td>11</td>
    <td>2118.5</td>
  </tr>
  <tr>
    <td>148</td>
    <td>2115.38</td>
    <td>2109</td>
    <td>2121</td>
    <td>12</td>
    <td>2115.0</td>
  </tr>
  <tr>
    <td>147</td>
    <td>2111.07</td>
    <td>2105</td>
    <td>2116</td>
    <td>11</td>
    <td>2110.5</td>
  </tr>
  <tr>
    <td>146</td>
    <td>2106.94</td>
    <td>2101</td>
    <td>2111</td>
    <td>10</td>
    <td>2106.0</td>
  </tr>
  <tr>
    <td>100</td>
    <td>1923.78</td>
    <td>1918</td>
    <td>1929</td>
    <td>11</td>
    <td>1923.5</td>
  </tr>
  <tr>
    <td>50</td>
    <td>1724.52</td>
    <td>1720</td>
    <td>1729</td>
    <td>9</td>
    <td>1724.5</td>
  </tr>
  <tr>
    <td></td>
    <td>1525.23</td>
    <td>1520</td>
    <td>1531</td>
    <td>11</td>
    <td>1525.5</td>
  </tr>
  <tr>
    <td>-50</td>
    <td>1325.74</td>
    <td>1319</td>
    <td>1331</td>
    <td>12</td>
    <td>1325.0</td>
  </tr>
  <tr>
    <td>-100</td>
    <td>1126.63</td>
    <td>1122</td>
    <td>1132</td>
    <td>10</td>
    <td>1127.0</td>
  </tr>
  <tr>
    <td>-120</td>
    <td>1047.06</td>
    <td>1041</td>
    <td>1051</td>
    <td>10</td>
    <td>1046.0</td>
  </tr>
  <tr>
    <td>-135</td>
    <td>987.40</td>
    <td>983</td>
    <td>992</td>
    <td>9</td>
    <td>987.5</td>
  </tr>
  <tr>
    <td>-146</td>
    <td>943.40</td>
    <td>939</td>
    <td>948</td>
    <td>9</td>
    <td>943.5</td>
  </tr>
  <tr>
    <td>-147</td>
    <td>939.48</td>
    <td>935</td>
    <td>944</td>
    <td>9</td>
    <td>939.5</td>
  </tr>
  <tr>
    <td>-148</td>
    <td>935.34</td>
    <td>929</td>
    <td>940</td>
    <td>11</td>
    <td>934.5</td>
  </tr>
  <tr>
    <td>-149</td>
    <td>931.24</td>
    <td>926</td>
    <td>936</td>
    <td>10</td>
    <td>931.0</td>
  </tr>
  <tr>
    <td>-150</td>
    <td>927.43</td>
    <td>921</td>
    <td>932</td>
    <td>11</td>
    <td>926.5</td>
  </tr>
</table>

**Table 2<br />**From these values, I extracted the following polynomial functions:

| Polynomial Equation | Py1 | Px1     | Py2  | Px2     | a2       | a1         | a0          |
|---------------------|-----|---------|------|---------|----------|------------|-------------|
|                     | 150 | 2123.57 | -150 | 927.43  |          | 0.25080676 | -382.605213 |
| 1                   | 146 | 2106.94 | -135 | 987.40  |          | 0.25099594 | -382.8344   |
| 2                   | 100 | 1923.78 | -100 | 1126.63 |          | 0.25089444 | -382.665703 |
| 3                   | 148 | 2115.38 | -148 | 935.34  |          | 0.25083895 | -382.619708 |
| 4                   | 146 | 2106.94 | -146 | 943.40  |          | 0.25095742 | -382.75323  |
| 5                   | 149 | 2119.40 | -149 | 931.24  |          | 0.25080797 | -382.563419 |
| 6                   |     |         |      |         | -1.0E-07 | 0.2513     | -382.95     |


**Table 3<br />**Again, calculating the performance of each polynomial functions:

| Tx   | Average PWM | Eq0  | Diff 0 | Eq1  | Diff 1 | Eq2  | Diff 2 | Eq3  | Diff 3 | Eq4  | Diff 4 | Eq5  | Diff 5 | Eq6  | Diff 6 |
|------|-------------|------|--------|------|--------|------|--------|------|--------|------|--------|------|--------|------|--------|
| 150  | 2123.57     | 150  |        | 150  | 0.17   | 150  | 0.13   | 150  | 0.05   | 150  | 0.17   | 150  | 0.04   | 150  | 0.25   |
| 149  | 2119.40     | 149  | 0.04   | 149  | 0.13   | 149  | 0.08   | 149  | 0.01   | 149  | 0.13   | 149  |        | 149  | 0.21   |
| 148  | 2115.38     | 148  | 0.05   | 148  | 0.12   | 148  | 0.07   | 148  |        | 148  | 0.12   | 148  | 0.01   | 148  | 0.2    |
| 147  | 2111.07     | 147  | 0.14   | 147  | 0.04   | 147  | 0.01   | 147  | 0.08   | 147  | 0.03   | 147  | 0.09   | 147  | 0.12   |
| 146  | 2106.94     | 146  | 0.17   | 146  |        | 146  | 0.05   | 146  | 0.12   | 146  |        | 146  | 0.13   | 146  | 0.08   |
| 100  | 1923.78     | 100  | 0.11   | 100  | 0.03   | 100  |        | 100  | 0.06   | 100  | 0.03   | 100  | 0.06   | 100  | 0.13   |
| 50   | 1724.52     | 50   | 0.08   | 50   | 0.01   | 50   | 0.01   | 50   | 0.04   | 50   | 0.03   | 50   | 0.04   | 50   | 0.13   |
|      | 1525.23     |      | 0.07   |      | 0.01   |      | 0.01   |      | 0.03   |      | 0.02   |      | 0.02   |      | 0.11   |
| -50  | 1325.74     | -50  | 0.1    | -50  | 0.08   | -50  | 0.04   | -50  | 0.07   | -50  | 0.05   | -50  | 0.06   | -50  | 0.03   |
| -100 | 1126.63     | -100 | 0.04   | -100 | 0.05   | -100 |        | -100 | 0.02   | -100 | 0.02   | -100 |        | -100 | 0.05   |
| -120 | 1047.06     | -120 |        | -120 | 0.03   | -120 | 0.04   | -120 | 0.02   | -120 | 0.01   | -120 | 0.05   | -120 | 0.07   |
| -135 | 987.40      | -135 | 0.04   | -135 |        | -135 | 0.07   | -135 | 0.06   | -135 | 0.04   | -135 | 0.09   | -135 | 0.09   |
| -146 | 943.40      | -146 | 0.01   | -146 | 0.04   | -146 | 0.03   | -146 | 0.02   | -146 |        | -146 | 0.05   | -146 | 0.04   |
| -147 | 939.48      | -147 | 0.02   | -147 | 0.03   | -147 | 0.05   | -147 | 0.04   | -147 | 0.02   | -147 | 0.07   | -147 | 0.05   |
| -148 | 935.34      | -148 | 0.02   | -148 | 0.07   | -148 | 0.01   | -148 |        | -148 | 0.02   | -148 | 0.03   | -148 | 0.01   |
| -149 | 931.24      | -149 | 0.04   | -149 | 0.1    | -149 | 0.02   | -149 | 0.03   | -149 | 0.05   | -149 |        | -149 | 0.02   |
| -150 | 927.43      | -150 |        | -150 | 0.05   | -150 | 0.02   | -150 | 0.02   | -150 | 0.01   | -150 | 0.04   | -150 | 0.03   |
|      |             |      | 0.93   |      | 0.95   |      | 0.62   |      | 0.67   |      | 0.75   |      | 0.78   |      | 1.59   |


The table above shows two polynomial functions (see highlighted columns) that offers the best performance :

* Function #2 (which has an order of 1) and a sum of 0.62.
* Function #6 (which has an order of 2) and a sum of 1.59.

Function #2 offers the best performance. It is even better than the polynomial function with an order of 3. All control points matches the expected values. This means that Spektrum AR8000 Rx delivers near-perfect and linear PWM values for all given transmitter values.

The following polynomial function offers the best performance to compute the Spektrum DX9 RC Transmitter value from the Spektrum AR8000 Rx pulse length:

f(x) = 0.25089444*x – 382.665703

Download the 
	[ Spektrum DX9 Tx & Spektrum AR8000 Rx (365 downloads) ](http://www.end2endzone.com/download/1620/ "Version 1.0")&nbsp;full data capture.

## Tactic TTX600 Tx &&nbsp;Tactic TR624 Rx

| <!-- -->                                                                                                                                                                                                                                                                                                               |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [![Tactic TTX600 6-ch Tx.jpg](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx.jpg "Tactic TTX600 6-ch Tx.jpg")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TTX600-6-ch-Tx.jpg) |
| [![Tactic TR624 6-ch Rx](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx.jpg "Tactic TR624 6-ch Rx")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/03/Tactic-TR624-6-ch-Rx.jpg)              |


**Notes:<br />**The TTX600 transmitter is not digital. This means that it is hard to reproduce the exact behavior every time. As you can see the result are pretty erratic. Each different channel has a different behavior.

For extracting the data, I assumed that moving _**any**_&nbsp;sticks to the top, bottom, left and right position would always match a perfect 100% (or -100%). Other values (+60%, -60%) are based on the documentation manual which states that high and low dual rates are based on a 100% and 60% ratio.

{{< pleasenote >}}
  Note that each channel section are identified by a unique color which helps to identify the source of each Polynomial Equation.
{{< /pleasenote >}}


**Table 1<br />**The Tactic TTX600 Tx & Tactic TR624 Rx shows a PWM range from **984 µs** to **2030 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="7" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="7">Tactic TTX600 tx &&nbsp;Tactic TR624</td>
  </tr>
  <tr class="headerrow" data-headerrow="true">
    <td>Tx</td>
    <td>Avg PWM</td>
    <td>Min</td>
    <td>Max</td>
    <td>Width</td>
    <td>Middle</td>
    <td>Comment</td>
  </tr>
  <tr style="background-color: lightblue;">
    <td>100</td>
    <td>1969.01</td>
    <td>1962</td>
    <td>1973</td>
    <td>11</td>
    <td>1967.5</td>
    <td>CH1 +100</td>
  </tr>
  <tr style="background-color: lightblue;">
    <td>60</td>
    <td>1793.74</td>
    <td>1789</td>
    <td>1800</td>
    <td>11</td>
    <td>1794.5</td>
    <td>CH1 +60</td>
  </tr>
  <tr style="background-color: lightblue;">
    <td></td>
    <td>1502.62</td>
    <td>1498</td>
    <td>1508</td>
    <td>10</td>
    <td>1503.0</td>
    <td>CH1 0</td>
  </tr>
  <tr style="background-color: lightblue;">
    <td>-60</td>
    <td>1214.30</td>
    <td>1209</td>
    <td>1219</td>
    <td>10</td>
    <td>1214.0</td>
    <td>CH1 -60</td>
  </tr>
  <tr style="background-color: lightblue;">
    <td>-100</td>
    <td>1042.41</td>
    <td>1037</td>
    <td>1046</td>
    <td>9</td>
    <td>1041.5</td>
    <td>CH1 -100</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>100</td>
    <td>2022.89</td>
    <td>2017</td>
    <td>2030</td>
    <td>13</td>
    <td>2023.5</td>
    <td>CH2 +100</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>60</td>
    <td>1838.71</td>
    <td>1834</td>
    <td>1844</td>
    <td>10</td>
    <td>1839.0</td>
    <td>CH2 +60</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td></td>
    <td>1530.52</td>
    <td>1526</td>
    <td>1536</td>
    <td>10</td>
    <td>1531.0</td>
    <td>CH2 0</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>-60</td>
    <td>1230.26</td>
    <td>1226</td>
    <td>1235</td>
    <td>9</td>
    <td>1230.5</td>
    <td>CH2 -60</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>-100</td>
    <td>1048.09</td>
    <td>1043</td>
    <td>1052</td>
    <td>9</td>
    <td>1047.5</td>
    <td>CH2 -100</td>
  </tr>
  <tr style="background-color: #ffffaf;">
    <td>100</td>
    <td>2010.15</td>
    <td>2004</td>
    <td>2016</td>
    <td>12</td>
    <td>2010.0</td>
    <td>CH5 +100</td>
  </tr>
  <tr style="background-color: #ffffaf;">
    <td>-100</td>
    <td>989.31</td>
    <td>985</td>
    <td>995</td>
    <td>10</td>
    <td>990.0</td>
    <td>CH5 -100</td>
  </tr>
  <tr style="background-color: #ffc896;">
    <td>100</td>
    <td>2010.39</td>
    <td>2004</td>
    <td>2016</td>
    <td>12</td>
    <td>2010.0</td>
    <td>CH6 +100</td>
  </tr>
  <tr style="background-color: #ffc896;">
    <td>-100</td>
    <td>989.40</td>
    <td>984</td>
    <td>994</td>
    <td>10</td>
    <td>989.0</td>
    <td>CH6 -100</td>
  </tr>
</table>

**Table 2<br />**From these values, I extracted the following polynomial functions:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td>Polynomial Equation</td>
    <td>Py1</td>
    <td>Px1</td>
    <td>Py2</td>
    <td>Px2</td>
    <td>a2</td>
    <td>a1</td>
    <td>a0</td>
  </tr>
  <tr style="background-color: #ffffaf;">
    <td></td>
    <td>100</td>
    <td>2010.152</td>
    <td>-100</td>
    <td>989.308</td>
    <td></td>
    <td>0.19591632</td>
    <td>-293.821583</td>
  </tr>
  <tr style="background-color: #ffc896;">
    <td>1</td>
    <td>100</td>
    <td>2010.392</td>
    <td>-100</td>
    <td>989.402</td>
    <td></td>
    <td>0.1958883</td>
    <td>-293.81228</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>2</td>
    <td>100</td>
    <td>2022.892</td>
    <td>-100</td>
    <td>1048.088</td>
    <td></td>
    <td>0.20516945</td>
    <td>-315.035638</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>3</td>
    <td>60</td>
    <td>1838.708</td>
    <td>-60</td>
    <td>1230.256</td>
    <td></td>
    <td>0.1972218</td>
    <td>-302.633306</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>4</td>
    <td>100</td>
    <td>2022.892</td>
    <td>-60</td>
    <td>1230.256</td>
    <td></td>
    <td>0.2018581</td>
    <td>-308.337143</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>5</td>
    <td>60</td>
    <td>1838.708</td>
    <td>-100</td>
    <td>1048.088</td>
    <td></td>
    <td>0.20237282</td>
    <td>-312.104526</td>
  </tr>
  <tr>
    <td>6</td>
    <td colspan="4">all control points</td>
    <td>9.00E-06</td>
    <td>0.1755</td>
    <td>-287.34</td>
  </tr>
  <tr>
    <td style="background-color: lightblue;">7</td>
    <td style="background-color: lightblue;" colspan="4">CH1 control points</td>
    <td style="background-color: lightblue;">-3.00E-06</td>
    <td style="background-color: lightblue;">0.2221</td>
    <td style="background-color: lightblue;">-327.22</td>
  </tr>
  <tr style="background-color: #ffc8c8;">
    <td>8</td>
    <td colspan="4">CH2 control points</td>
    <td>-3.00E-06</td>
    <td>0.2135</td>
    <td>-318.97</td>
  </tr>
</table>

**Table 3 (for CH1)<br />**The following table shows details for calculating the performance of each polynomial functions:

| Tx   | Avg PWM | Eq2  | Diff 2 | Eq3 | Diff 3 | Eq4 | Diff 4 | Eq5  | Diff 5 | Eq6 | Diff 6 | Eq7 | Diff 7 | Eq8  | Diff 8 |
|------|---------|------|--------|-----|--------|-----|--------|------|--------|-----|--------|-----|--------|------|--------|
| 100  | 1969.01 | 89   | 11.05  | 86  | 14.3   | 89  | 10.88  | 86   | 13.63  | 93  | 6.89   | 98  | 1.53   | 90   | 10.22  |
| 60   | 1793.74 | 53   | 7.02   | 51  | 8.87   | 54  | 6.26   | 51   | 9.1    | 56  | 3.58   | 62  | 1.52   | 54   | 5.66   |
|      | 1502.62 | -7   | 6.74   | -6  | 6.28   | -5  | 5.02   | -8   | 8.02   | -3  | 3.31   |     | 0.26   | -5   | 4.93   |
| -60  | 1214.30 | -66  | 5.9    | -63 | 3.15   | -63 | 3.22   | -66  | 6.36   | -61 | 0.96   | -62 | 1.95   | -64  | 4.14   |
| -100 | 1042.41 | -101 | 1.17   | -97 | 2.95   | -98 | 2.08   | -101 | 1.15   | -95 | 5.38   | -99 | 1.04   | -100 | 0.32   |
|      |         |      | 31.88  |     | 35.55  |     | 27.46  |      | 38.26  |     | 20.12  |     | 6.3    |      | 25.28  |


**Table 3 (for CH2)<br />**The following table shows details for calculating the performance of each polynomial functions:

| Tx   | Avg PWM | Eq2  | Diff 2 | Eq3 | Diff 3 | Eq4 | Diff 4 | Eq5  | Diff 5 | Eq6 | Diff 6 | Eq7 | Diff 7 | Eq8 | Diff 8 |
|------|---------|------|--------|-----|--------|-----|--------|------|--------|-----|--------|-----|--------|-----|--------|
| 100  | 2022.89 | 100  |        | 96  | 3.67   | 100 |        | 97   | 2.73   | 105 | 4.51   | 110 | 9.79   | 101 | 0.64   |
| 60   | 1838.71 | 62   | 2.21   | 60  |        | 63  | 2.82   | 60   |        | 66  | 5.78   | 71  | 11.01  | 63  | 3.45   |
|      | 1530.52 | -1   | 1.02   | -1  | 0.78   | 1   | 0.61   | -2   | 2.37   | 2   | 2.35   | 6   | 5.68   | 1   | 0.77   |
| -60  | 1230.26 | -63  | 2.62   | -60 |        | -60 |        | -63  | 3.13   | -58 | 2.19   | -59 | 1.48   | -61 | 0.85   |
| -100 | 1048.09 | -100 |        | -96 | 4.07   | -97 | 3.23   | -100 |        | -94 | 6.49   | -98 | 2.26   | -98 | 1.5    |
|      |         |      | 5.85   |     | 8.53   |     | 6.66   |      | 8.23   |     | 21.31  |     | 30.23  |     | 7.21   |


The two tables above shows two polynomial functions (see highlighted columns) that offers the best performance:

  * Function #7 (which has an order of 2) and a sum of 6.3.
  * Function #8 (which has an order of 2) and a sum of 7.21.
  * All polynomial function which has an order of 1 shows terrible prediction performance.

{{< pleasenote >}}
  Note that best function for channel 1 (function #7) shows terrible results when used in calculations of channel 2. That is also for function 8. This means that there is no generic function that can be used for all channel situations. As a proof, function #6 which is based on all observed values for all channels shows terrible results.
{{< /pleasenote >}}


In other words, reading the PWM length or the _Tactic TTX600 Tx & Tactic TR624 Rx combination_&nbsp;can only be used for detecting if the sticks are "up", "centered" or "down" but not really "how much up or down".

The following polynomial functions offers the best performance to compute the Tactic TTX600 Tx transmitter value from the Tactic TR624 Rx pulse length:

Channel 1 :

f(x) = -3.0E-6*x<sup>2</sup> + 0.2221*x – 327.22

Channel 2 :

f(x) = -3.0E-6*x2 + 0.2135*x – 318.97

Download the 
	[ Tactic TTX600 Tx & Tactic TR624 Rx (390 downloads) ](http://www.end2endzone.com/download/1614/ "Version 1.0") full data capture.

## CCPM Servo Tester

| <!-- -->                                                                                                                                                                                                                                                                                   |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [![CCPM Servo Tester](http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg "CCPM Servo Tester")[250x250](http://www.end2endzone.com/wp-content/uploads/2016/03/CCPM-Servo-Tester.jpg) |


**Table 1**  
The CCPM Servo Tester shows a PWM range from **900 µs** to **2210 µs**. The following table shows the details of my data capture session:

<table class="generictable" border="0" cellspacing="0" cellpadding="0" data-generictable="true">
  <colgroup> <col span="7" /> </colgroup> <tr class="headerrow" data-headerrow="true">
    <td colspan="7">CCPM Servo Tester</td>
  </tr>
  <tr class="headerrow" data-headerrow="true">
    <td>Value</td>
    <td>Avg PWM</td>
    <td>Min</td>
    <td>Max</td>
    <td>Width</td>
    <td>Middle</td>
    <td>Comment</td>
  </tr>
  <tr>
    <td>100</td>
    <td>2103.82</td>
    <td>2098</td>
    <td>2110</td>
    <td>12</td>
    <td>2104</td>
    <td>CW</td>
  </tr>
  <tr>
    <td></td>
    <td>1504.75</td>
    <td>1501</td>
    <td>1511</td>
    <td>10</td>
    <td>1506</td>
    <td>CENTER</td>
  </tr>
  <tr>
    <td>-100</td>
    <td>903.77</td>
    <td>900</td>
    <td>909</td>
    <td>9</td>
    <td>904.5</td>
    <td>CCW</td>
  </tr>
</table>

{{< pleasenote >}}
  Note that values for the CCPM Server Tester (100, -100) are assumptions and represents clockwise and counterclockwise positions of the potentiometer. In fact, based on the observed PWM values, the values should be more in the (133, -133) range according the _[Spektrum DX9 Tx & Orange R620X Rx](#Spektrum_DX9_Tx_Orange_R620X_Rx)_&nbsp;results or in (150, -150) range according the _[Spektrum DX9 Tx & Spektrum AR8000 Rx](#Spektrum_DX9_Tx_Spektrum_AR8000_Rx)_ results.
{{< /pleasenote >}}


**Table 2**  
From these values, I extracted the following polynomial functions:

| Polynomial Equation | Py1 | Px1      | Py2  | Px2      | a2      | a1         | a0          |
|---------------------|-----|----------|------|----------|---------|------------|-------------|
|                     | 100 | 2103.82  | -100 | 903.77   |         | 0.16665945 | -250.62214  |
| 1                   | 100 | 2103.824 |      | 1504.752 |         | 0.16692484 | -251.180493 |
| 2                   |     | 1504.752 | -100 | 903.772  |         | 0.16639489 | -250.383041 |
| 3                   |     |          |      |          | 4.0E-07 | 0.1653     | -249.78     |


**Table 3**  
The following table shows details for calculating the performance of each polynomial functions:

| Value | Avg PWM | Eq0  | Diff 0 | Eq1  | Diff 1 | Eq2  | Diff 2 | Eq3  | Diff 3 |
|-------|---------|------|--------|------|--------|------|--------|------|--------|
| 100   | 2103.82 | 100  |        | 100  |        | 100  | 0.32   | 100  | 0.25   |
|       | 1504.75 |      | 0.16   |      |        |      |        |      | 0.14   |
| -100  | 903.77  | -100 |        | -100 | 0.32   | -100 |        | -100 | 0.06   |
|       |         |      | 0.16   |      | 0.32   |      | 0.32   |      | 0.45   |


{{< pleasenote >}}
  Note that only 3 control points are available which means that all performance calculations will always match 2/3 controls points (since the equation is derived from these 2 points). Performance calculations are irrelevant in this particular situation.
{{< /pleasenote >}}


Even if the performance of function #3 seem to be the worst, it seems like it is the one that is the most promising since it takes into account all control points.

The following polynomial function offers the best performance to compute the _CCPM Servo Tester_ pulse length:

f(x) = 4.0E-07*x<sup>2</sup> + 0.1653*x – 249.78

Download the 
	[ CCPM Servo Tester (384 downloads) ](http://www.end2endzone.com/download/1616/ "Version 1.0")&nbsp;full data capture.
