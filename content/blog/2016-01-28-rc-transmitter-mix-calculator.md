---
title: RC Transmitter Mix Calculator
author: end2end
type: post
date: 2016-01-28T17:43:43+00:00
url: /rc-transmitter-mix-calculator/
featured_image: /wp-content/uploads/2016/01/RC-Transmitter-Mix-Calculator.jpg
hits:
  - 1361
categories:
  - Model Aeronautics
tags:
  - english
  - RC
  - RC transmitter

---
This is an Excel worksheet I created based on the calculations I found for calculating most R/C Transmitter mixes. It is designed to help you identify the effective range of a mix (finding the low, medium and high values).

See my post on [Demystifying RC Transmitter Mixing][1] for more details.<!--more-->

Please note the following calculator is valid on Spektrum Transmitters. I did not verified it&#8217;s validity or accuracy on other transmitters.

# <span id="RC_Transmitter_Mix_Calculator">RC Transmitter Mix Calculator</span>

## <span id="Usage">Usage</span>

Only white cells should be modified.  
Cells in light blue are the final mix values.

## <span id="Screenshot">Screenshot</span>

<table class="MsoNormalTable" style="width: 234.05pt; margin-left: -1.15pt; border-collapse: collapse;" border="0" width="312" cellspacing="0" cellpadding="0">
  <tr style="height: 15.0pt;">
    <td style="width: 234.05pt; border: solid windowtext 1.0pt; background: #FFC000; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" colspan="4" valign="bottom" nowrap="nowrap" width="312">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;">MIXING<br /> CALCULATOR</span></b>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border: solid windowtext 1.0pt; border-top: none; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Switch Pos</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: white;"></span>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: white;">1</span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: white;">2</span>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border: solid windowtext 1.0pt; border-top: none; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Travel</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">100</span>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;"></span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">-100</span>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border-top: none; border-left: solid windowtext 1.0pt; border-bottom: solid black 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" rowspan="2" nowrap="nowrap" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Rates</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">High</span></b>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Low</span></b>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Offset</span></b>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">50</span>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">50</span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: white; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;"></span>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border: solid windowtext 1.0pt; border-top: none; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" nowrap="nowrap" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Offset Values</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">100</span>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;"></span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">-100</span>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border-top: none; border-left: solid windowtext 1.0pt; border-bottom: solid black 1.0pt; border-right: solid windowtext 1.0pt; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" rowspan="2" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Intermediate<br /> Values</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">50</span>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;"></span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;">-50</span>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;"> </span></b>
      </p>
    </td>
    
    <td style="width: 33.7pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <span style="color: black;"></span>
      </p>
    </td>
    
    <td style="width: 49.2pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #BFBFBF; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;"> </span></b>
      </p>
    </td>
  </tr>
  
  <tr style="height: 15.0pt;">
    <td style="width: 114.15pt; border: solid windowtext 1.0pt; border-top: none; background: gray; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="152">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: white;">Final Values</span></b>
      </p>
    </td>
    
    <td style="width: 37.0pt; border-top: none; border-left: none; border-bottom: solid windowtext 1.0pt; border-right: solid windowtext 1.0pt; background: #C5D9F1; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="49">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;">50</span></b>
      </p>
    </td>
    
    <td style="width: 33.7pt; border: none; border-bottom: solid windowtext 1.0pt; background: #C5D9F1; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="45">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;"></span></b>
      </p>
    </td>
    
    <td style="width: 49.2pt; border: solid windowtext 1.0pt; border-top: none; background: #C5D9F1; padding: 0in 5.4pt 0in 5.4pt; height: 15.0pt;" valign="bottom" nowrap="nowrap" width="66">
      <p class="MsoNormal" style="margin-bottom: .0001pt; text-align: center; line-height: normal;" align="center">
        <b><span style="color: black;">-50</span></b>
      </p>
    </td>
  </tr>
</table>

## <span id="Download">Download</span>


	<a class="download-link" title="Version 2.0" href="http://www.end2endzone.com/download/1255/" rel="nofollow"> Mixing Calculator for R/C Transmitter (1107 downloads) </a>

Enjoy!

 [1]: /demystifying-rc-transmitter-mixing/