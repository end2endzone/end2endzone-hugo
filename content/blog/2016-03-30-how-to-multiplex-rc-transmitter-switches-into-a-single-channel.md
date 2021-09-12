---
title: How to multiplex RC Transmitter switches into a single channel
author: end2end
type: post
date: 2016-03-30T17:15:24+00:00
url: /how-to-multiplex-rc-transmitter-switches-into-a-single-channel/
featured_image: /wp-content/uploads/2016/03/How-to-multiplex-RC-Transmitter-switches-into-a-single-channel-672x378.jpg
hits:
  - 386
Snippet Title:
  - Downloadable content
Snippet:
  - |
    <p>Downloads available in this article:</p>
    <div style="margin-bottom: 18px">
    <p class="nomarginbottom">Cheat sheets:</p>
    <ul class="fa-ul">
    <li><a href="/download/1486/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Multiplexing 2-position switches</a></li>
    <li><a href="/download/1482/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Multiplexing 2-position + 3-position switches</a></li>
    <li><a href="/download/1484/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Multiplexing 3-position switches</a></li>
    <li><a href="/download/1510/"><i class="fa-li fa fa-download" style="position: inherit;"></i>Multiplexing analog &amp; switches</a></li>
    </ul>
    </div>
    <div style="margin-bottom: 18px">
    <p class="nomarginbottom">Code samples:</p>
    <ul class="fa-ul">
    <li><a href="/download/2071/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2071" template="title"]</a></li>
    <li><a href="/download/2069/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2069" template="title"]</a></li>
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
  - RC transmitter

---
# <span id="Introduction">Introduction</span> In a personal project, I wanted to add 2 new devices to an existing quadcopter. The quadcopter was equipped with a 6-channel receiver meaning I only had 1 spare channel to control the 2 devices: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        CH 1
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        Throttle
      </td>
    </tr>
    
    <tr>
      <td class="names">
        CH 2
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        Rudder
      </td>
    </tr>
    
    <tr>
      <td class="names">
        CH 3
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        Ailerons
      </td>
    </tr>
    
    <tr>
      <td class="names">
        CH 4
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        Elevator
      </td>
    </tr>
    
    <tr>
      <td class="names">
        CH 5
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        Flight mode
      </td>
    </tr>
    
    <tr>
      <td class="names">
        CH 6
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        ???
      </td>
    </tr>
  </table>
</div> The following article explains how I manage to solve the issue: 

_How can I control more than one device using a single channel_.<!--more-->

<p class="postedit">
  EDIT: To make all mixing pre-calculations easier, do not hesitate to use my <a href="/rc-transmitter-mix-calculator/">Mixing Calculator for R/C Transmitter</a> (it&#8217;s an Excel Sheet!)
</p> I could have used an 8-channel receiver to solve this but I did not had a free receiver that I could spare. This guide will show you how to multiplex RC transmitter switches (inputs) into a 

**single** channel. <!--=================================================-->

# <span id="Use_a_microcontroller">Use a microcontroller</span> For this type of project, 7 channels is usually required. The easiest method would have been to replace the receiver but since I like the DIY way, I decided to multiplex two switches into the 6th channel and use a microcontroller to read the signal and demultiplex each switches states. 

<p class="pleasenote">
  <strong>Note:</strong> This is only valid if there is a microcontroller connected with the receiver that <em> <strong>you</strong> </em> can program to demultiplex the signal. Do not expect your proprietary flight controller to be able to understand your signal.
</p>

<!--=================================================-->

# <span id="Multiplexing_switches_only">Multiplexing switches (only)</span>

## <span id="Design">Design</span> The following section illustrate the design required for multiplexing as much information as possible into a single channel. 

<!--=================================================-->

### <span id="Create_blocks">Create blocks</span> The generic idea is to divide the whole range of the signal (from -150% to 150%) into blocks or bands. Each block correspond to a unique configuration of all switches. Then you create the required mixes to move/update the signal value to the block corresponding to the switches unique configuration. 

<!--=================================================-->

### <span id="Minimum_number_of_blocks">Minimum number of blocks</span> The following explain what is the minimum number of blocks that are required for multiplexing a given amount of switches. The number of required blocks for a given number of switches is defined by the all the unique combinations that are possible with the switches. To calculate this, you multiply the number of combinations of each switch by each other. For instance: To multiplex three 2-position switches, 8 blocks are required (2\*2\*2) which makes 8 unique combinations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 64px;" rowspan="2">
      <b>Block Number</b>
    </td>
    
    <td colspan="3">
      <b>Switches</b>
    </td>
  </tr>
  
  <tr class="headerrow">
    <td style="width: 60px;" width="60">
      <b>2-pos</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>2-pos</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>2-pos</b>
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
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
  </tr>
</table> To multiplex two 2-position and one 3-position switches, 12 blocks are required (2\*2\*3) which makes 12 unique combinations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 64px;" rowspan="2">
      <b>Block Number</b>
    </td>
    
    <td colspan="3">
      <b>Switches</b>
    </td>
  </tr>
  
  <tr class="headerrow">
    <td style="width: 60px;" width="60">
      <b>2-pos</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>2-pos</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>3-pos</b>
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
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      5
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
      6
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
  </tr>
</table>

<p class="pleasenote">
  Note that each switch also requires a mix for working. The amount of switches you can multiplex is then also limited by the amount of mixes you can define in your transmitter.
</p>

## <span id="Supporting_3-position_switches">Supporting 3-position switches</span> In your design, you will have to decide to support or not 3-position switches. If you do, it will reduce the amount of switches you can multiplex into a single channel since each switches requires 3 blocks instead of 2 blocks. An acceptable compromise is to use this switch as a 2-position switch. Position 1 would then be identical as Position 0 (OFF) and Position 2 would be ON. 

<!--=================================================-->

## <span id="Dead_Zone">Dead Zone</span> Blocks cannot be juxtaposed to each other and dead zones must be inserted between (or within) blocks. This is required since each transmitters and micro-controllers do not offer the same performance and precision. Dead zones are required since a micro-controller might read data from block 5 but the next pulse of the same signal may introduce a 5uS delay, which would correspond to a different block (ie block 6). For instance, if the following blocks are defined: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 60px;" width="60">
      <b>Block</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>Min</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>Max</b>
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -150%
    </td>
    
    <td>
      -141%
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -140%
    </td>
    
    <td>
      -131%
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -130%
    </td>
    
    <td>
      -121%
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -120%
    </td>
    
    <td>
      -111%
    </td>
  </tr>
</table> The difference between -131% (block 1) and -130% (block 2) is ~5uS. If blocks would be juxtaposed, then the micro-controller could sometimes read block 1 and sometimes block 2 which does not mean the same thing at all. This delay might be from the receiver who does not provide a perfect pulse length or from the micro-controller who does not detect the end of the pulse with enough precision. Both errors can be avoided with dead zones. By introducing a dead zone of 5 steps within blocks (of 10 steps), the same blocks would then become something like: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 60px;" width="60">
      <b>Block</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>Min</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>Max</b>
    </td>
    
    <td style="width: 60px;" width="60">
      <b>Mix Target</b>
    </td>
  </tr>
  
  <tr class="deadrow" style="background-color: #c0c0c0;">
    <td>
      DEAD
    </td>
    
    <td>
      -150%
    </td>
    
    <td>
      -148%
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -147%
    </td>
    
    <td>
      -143%
    </td>
    
    <td>
      -145%
    </td>
  </tr>
  
  <tr class="deadrow" style="background-color: #c0c0c0;">
    <td>
      DEAD
    </td>
    
    <td>
      -142%
    </td>
    
    <td>
      -138%
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -137%
    </td>
    
    <td>
      -133%
    </td>
    
    <td>
      -135%
    </td>
  </tr>
  
  <tr class="deadrow" style="background-color: #c0c0c0;">
    <td>
      DEAD
    </td>
    
    <td>
      -132%
    </td>
    
    <td>
      -128%
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -127%
    </td>
    
    <td>
      -123%
    </td>
    
    <td>
      -125%
    </td>
  </tr>
  
  <tr class="deadrow" style="background-color: #c0c0c0;">
    <td>
      DEAD
    </td>
    
    <td>
      -122%
    </td>
    
    <td>
      -113%
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -117%
    </td>
    
    <td>
      -113%
    </td>
    
    <td>
      -115%
    </td>
  </tr>
</table>

<!--=================================================--> The block size must also have a minimum size to account for the same effect. If the block size is too small, the micro-controller might read data from a dead zone and would not know what to do. The more accurate the receiver and the micro-controller, the smaller the block size and dead zone size can be. Mixes should be created to move the actual signal values to target the middle of the effective block area (not the dead zone). See the 

[Mixes][1] section for more details. 

## <span id="Block_size">Block size</span> Based on my observation, the best values for block size and dead zone size are as follow: A block size of 10 steps is big enough to allow multiplexing a high amount of switches while leaving enough space for a reasonable dead zone between blocks. At the same time, a block size of 10 steps allows the blocks to be rounded easily which makes blocks offsets easy to calculate. The acceptable dead zone size (considering the average precision of most micro-controller and receivers), does not need to be bigger than 2 steps. This configuration leaves two blocks spaced by 4 steps which is enough to prevent issues. The following values are then considered &#8220;safe and tested&#8221; to get good and stable results: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        Block size
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        10 steps
      </td>
    </tr>
    
    <tr>
      <td class="names">
        Dead zone
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        2 steps
      </td>
    </tr>
    
    <tr>
      <td class="names">
        Effective size
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        6 steps
      </td>
    </tr>
  </table>
</div>

## <span id="Mixes">Mixes</span> The following section defines mix that are required to implement two basic scenarios. 

<p class="pleasenote">
  Note that you can easily calculate the effect of a given mix by using my <a href="/rc-transmitter-mix-calculator/">RC Transmitter Mix Calculator</a> to identify the minimum, middle and maximum values of a mix.
</p>

### <span id="Four_2-position_switches">Four 2-position switches</span> The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td rowspan="2" width="64">
      Block Number
    </td>
    
    <td style="width: 240px;" colspan="6" width="250">
      Block Offsets
    </td>
    
    <td rowspan="2" width="64">
      Mix Target
    </td>
  </tr>
  
  <tr class="headerrow">
    <td colspan="2">
      Dead
    </td>
    
    <td colspan="2">
      Effective
    </td>
    
    <td colspan="2">
      Dead
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      -143
    </td>
    
    <td>
      -142
    </td>
    
    <td>
      -141
    </td>
    
    <td>
      -146
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -140
    </td>
    
    <td>
      -139
    </td>
    
    <td>
      -138
    </td>
    
    <td>
      -133
    </td>
    
    <td>
      -132
    </td>
    
    <td>
      -131
    </td>
    
    <td>
      -136
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -130
    </td>
    
    <td>
      -129
    </td>
    
    <td>
      -128
    </td>
    
    <td>
      -123
    </td>
    
    <td>
      -122
    </td>
    
    <td>
      -121
    </td>
    
    <td>
      -126
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      -119
    </td>
    
    <td>
      -118
    </td>
    
    <td>
      -113
    </td>
    
    <td>
      -112
    </td>
    
    <td>
      -111
    </td>
    
    <td>
      -116
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      -110
    </td>
    
    <td>
      -109
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      -103
    </td>
    
    <td>
      -102
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      -106
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -99
    </td>
    
    <td>
      -98
    </td>
    
    <td>
      -93
    </td>
    
    <td>
      -92
    </td>
    
    <td>
      -91
    </td>
    
    <td>
      -96
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -89
    </td>
    
    <td>
      -88
    </td>
    
    <td>
      -83
    </td>
    
    <td>
      -82
    </td>
    
    <td>
      -81
    </td>
    
    <td>
      -86
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
      -80
    </td>
    
    <td>
      -79
    </td>
    
    <td>
      -78
    </td>
    
    <td>
      -73
    </td>
    
    <td>
      -72
    </td>
    
    <td>
      -71
    </td>
    
    <td>
      -76
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
      -70
    </td>
    
    <td>
      -69
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      -62
    </td>
    
    <td>
      -61
    </td>
    
    <td>
      -66
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      -60
    </td>
    
    <td>
      -59
    </td>
    
    <td>
      -58
    </td>
    
    <td>
      -53
    </td>
    
    <td>
      -52
    </td>
    
    <td>
      -51
    </td>
    
    <td>
      -56
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      -49
    </td>
    
    <td>
      -48
    </td>
    
    <td>
      -43
    </td>
    
    <td>
      -42
    </td>
    
    <td>
      -41
    </td>
    
    <td>
      -46
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      -40
    </td>
    
    <td>
      -39
    </td>
    
    <td>
      -38
    </td>
    
    <td>
      -33
    </td>
    
    <td>
      -32
    </td>
    
    <td>
      -31
    </td>
    
    <td>
      -36
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -29
    </td>
    
    <td>
      -28
    </td>
    
    <td>
      -23
    </td>
    
    <td>
      -22
    </td>
    
    <td>
      -21
    </td>
    
    <td>
      -26
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      -20
    </td>
    
    <td>
      -19
    </td>
    
    <td>
      -18
    </td>
    
    <td>
      -13
    </td>
    
    <td>
      -12
    </td>
    
    <td>
      -11
    </td>
    
    <td>
      -16
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -9
    </td>
    
    <td>
      -8
    </td>
    
    <td>
      -3
    </td>
    
    <td>
      -2
    </td>
    
    <td>
      -1
    </td>
    
    <td>
      -6
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      7
    </td>
    
    <td>
      8
    </td>
    
    <td>
      9
    </td>
    
    <td>
      5
    </td>
  </tr>
</table> The following mixes must be created to multiplex all switches unique configurations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 240px;" colspan="5" width="220">
      Mix info
    </td>
    
    <td style="width: 80px;" colspan="2" width="80">
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
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      A
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -100
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      A
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      36
    </td>
    
    <td>
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      -36
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      B
    </td>
    
    <td>
    </td>
    
    <td>
      -20
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      20
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      C
    </td>
    
    <td>
    </td>
    
    <td>
      -40
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      D
    </td>
    
    <td>
    </td>
    
    <td>
      -80
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      80
    </td>
  </tr>
</table>

<p class="pleasenote">
  Note that first 2 mix are mapped to switch A. This is required since the minimum value of a High rate mix is -125% which gives a final mix value of -125% at Position 0. The only way to get a lower value (ie -146) would be to offset the mix (by -17) but then the Low rate value would have the same issue.
</p> As you can see, the sum of all combined mixes matches the middle section of each effective block: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td rowspan="2" width="64">
      Block Number
    </td>
    
    <td colspan="4" width="80">
      Switches
    </td>
    
    <td style="width: 220px;" colspan="6" width="200">
      Mixes
    </td>
  </tr>
  
  <tr class="headerrow">
    <td>
      D
    </td>
    
    <td>
      C
    </td>
    
    <td>
      B
    </td>
    
    <td>
      A
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      3
    </td>
    
    <td>
      4
    </td>
    
    <td>
      Sum
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
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -146
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      20
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -126
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
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
      20
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -116
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -106
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -96
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      20
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -86
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
      20
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -76
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -66
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -56
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      20
    </td>
    
    <td>
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -46
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
      20
    </td>
    
    <td>
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -36
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -26
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -16
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      20
    </td>
    
    <td>
      40
    </td>
    
    <td>
      80
    </td>
    
    <td>
      -6
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -36
    </td>
    
    <td>
      20
    </td>
    
    <td>
      40
    </td>
    
    <td>
      80
    </td>
    
    <td>
      4
    </td>
  </tr>
</table> Use the 


	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1486/" rel="nofollow"> Cheat Sheet for Multiplexing four 2-position switches (301 downloads) </a> for calculating all block offset when multiplexing four 2-position switches. 

### <span id="Three_2-position_and_one_3-position_switches">Three 2-position and one 3-position switches</span> The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td rowspan="2" width="64">
      Block Number
    </td>
    
    <td colspan="6" width="250">
      Block Offsets
    </td>
    
    <td rowspan="2" width="64">
      Mix Target
    </td>
  </tr>
  
  <tr class="headerrow">
    <td colspan="2">
      Dead
    </td>
    
    <td colspan="2">
      Effective
    </td>
    
    <td colspan="2">
      Dead
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      -149
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      -143
    </td>
    
    <td>
      -142
    </td>
    
    <td>
      -141
    </td>
    
    <td>
      -146
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -140
    </td>
    
    <td>
      -139
    </td>
    
    <td>
      -138
    </td>
    
    <td>
      -133
    </td>
    
    <td>
      -132
    </td>
    
    <td>
      -131
    </td>
    
    <td>
      -136
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -130
    </td>
    
    <td>
      -129
    </td>
    
    <td>
      -128
    </td>
    
    <td>
      -123
    </td>
    
    <td>
      -122
    </td>
    
    <td>
      -121
    </td>
    
    <td>
      -126
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -120
    </td>
    
    <td>
      -119
    </td>
    
    <td>
      -118
    </td>
    
    <td>
      -113
    </td>
    
    <td>
      -112
    </td>
    
    <td>
      -111
    </td>
    
    <td>
      -116
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      -110
    </td>
    
    <td>
      -109
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      -103
    </td>
    
    <td>
      -102
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      -106
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -99
    </td>
    
    <td>
      -98
    </td>
    
    <td>
      -93
    </td>
    
    <td>
      -92
    </td>
    
    <td>
      -91
    </td>
    
    <td>
      -96
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -89
    </td>
    
    <td>
      -88
    </td>
    
    <td>
      -83
    </td>
    
    <td>
      -82
    </td>
    
    <td>
      -81
    </td>
    
    <td>
      -86
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
      -80
    </td>
    
    <td>
      -79
    </td>
    
    <td>
      -78
    </td>
    
    <td>
      -73
    </td>
    
    <td>
      -72
    </td>
    
    <td>
      -71
    </td>
    
    <td>
      -76
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
      -70
    </td>
    
    <td>
      -69
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      -62
    </td>
    
    <td>
      -61
    </td>
    
    <td>
      -66
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      -60
    </td>
    
    <td>
      -59
    </td>
    
    <td>
      -58
    </td>
    
    <td>
      -53
    </td>
    
    <td>
      -52
    </td>
    
    <td>
      -51
    </td>
    
    <td>
      -56
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      -50
    </td>
    
    <td>
      -49
    </td>
    
    <td>
      -48
    </td>
    
    <td>
      -43
    </td>
    
    <td>
      -42
    </td>
    
    <td>
      -41
    </td>
    
    <td>
      -46
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      -40
    </td>
    
    <td>
      -39
    </td>
    
    <td>
      -38
    </td>
    
    <td>
      -33
    </td>
    
    <td>
      -32
    </td>
    
    <td>
      -31
    </td>
    
    <td>
      -36
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -29
    </td>
    
    <td>
      -28
    </td>
    
    <td>
      -23
    </td>
    
    <td>
      -22
    </td>
    
    <td>
      -21
    </td>
    
    <td>
      -26
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      -20
    </td>
    
    <td>
      -19
    </td>
    
    <td>
      -18
    </td>
    
    <td>
      -13
    </td>
    
    <td>
      -12
    </td>
    
    <td>
      -11
    </td>
    
    <td>
      -16
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -9
    </td>
    
    <td>
      -8
    </td>
    
    <td>
      -3
    </td>
    
    <td>
      -2
    </td>
    
    <td>
      -1
    </td>
    
    <td>
      -6
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      7
    </td>
    
    <td>
      8
    </td>
    
    <td>
      9
    </td>
    
    <td>
      5
    </td>
  </tr>
  
  <tr>
    <td>
      16
    </td>
    
    <td>
      10
    </td>
    
    <td>
      11
    </td>
    
    <td>
      12
    </td>
    
    <td>
      17
    </td>
    
    <td>
      18
    </td>
    
    <td>
      19
    </td>
    
    <td>
      15
    </td>
  </tr>
  
  <tr>
    <td>
      17
    </td>
    
    <td>
      20
    </td>
    
    <td>
      21
    </td>
    
    <td>
      22
    </td>
    
    <td>
      27
    </td>
    
    <td>
      28
    </td>
    
    <td>
      29
    </td>
    
    <td>
      25
    </td>
  </tr>
  
  <tr>
    <td>
      18
    </td>
    
    <td>
      30
    </td>
    
    <td>
      31
    </td>
    
    <td>
      32
    </td>
    
    <td>
      37
    </td>
    
    <td>
      38
    </td>
    
    <td>
      39
    </td>
    
    <td>
      35
    </td>
  </tr>
  
  <tr>
    <td>
      19
    </td>
    
    <td>
      40
    </td>
    
    <td>
      41
    </td>
    
    <td>
      42
    </td>
    
    <td>
      47
    </td>
    
    <td>
      48
    </td>
    
    <td>
      49
    </td>
    
    <td>
      45
    </td>
  </tr>
  
  <tr>
    <td>
      20
    </td>
    
    <td>
      50
    </td>
    
    <td>
      51
    </td>
    
    <td>
      52
    </td>
    
    <td>
      57
    </td>
    
    <td>
      58
    </td>
    
    <td>
      59
    </td>
    
    <td>
      55
    </td>
  </tr>
  
  <tr>
    <td>
      21
    </td>
    
    <td>
      60
    </td>
    
    <td>
      61
    </td>
    
    <td>
      62
    </td>
    
    <td>
      67
    </td>
    
    <td>
      68
    </td>
    
    <td>
      69
    </td>
    
    <td>
      65
    </td>
  </tr>
  
  <tr>
    <td>
      22
    </td>
    
    <td>
      70
    </td>
    
    <td>
      71
    </td>
    
    <td>
      72
    </td>
    
    <td>
      77
    </td>
    
    <td>
      78
    </td>
    
    <td>
      79
    </td>
    
    <td>
      75
    </td>
  </tr>
  
  <tr>
    <td>
      23
    </td>
    
    <td>
      80
    </td>
    
    <td>
      81
    </td>
    
    <td>
      82
    </td>
    
    <td>
      87
    </td>
    
    <td>
      88
    </td>
    
    <td>
      89
    </td>
    
    <td>
      85
    </td>
  </tr>
</table> The following mixes must be created to multiplex all switches unique configurations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 240px;" colspan="5" width="220">
      Mix info
    </td>
    
    <td style="width: 120px;" colspan="3" width="120">
      Mix Output
    </td>
  </tr>
  
  <tr class="headerrow">
    <td width="58">
      Number
    </td>
    
    <td width="48">
      Switch
    </td>
    
    <td width="35">
      High
    </td>
    
    <td width="32">
      Low
    </td>
    
    <td width="46">
      Offset
    </td>
    
    <td width="39">
    </td>
    
    <td width="39">
      1
    </td>
    
    <td width="39">
      2
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      A
    </td>
    
    <td>
    </td>
    
    <td>
      68
    </td>
    
    <td>
      100
    </td>
    
    <td>
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -136
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      A
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
      -100
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      A
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      B
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      C
    </td>
    
    <td>
    </td>
    
    <td>
      -60
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      D
    </td>
    
    <td>
    </td>
    
    <td>
      -120
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
  </tr>
</table>

<p class="pleasenote">
  Note that first 3 mix are mapped to switch A which is the 3-position switch. The first 2 mix are use to get a constant -136 on all positions. Then the 3rd mix moves the signal value over the first 3 blocks (to the previous, current or next block). As far as I know, there is no way to achieve the same result with only 2 mixes.
</p> As you can see, the sum of all combined mixes matches the middle section of each effective block: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td rowspan="2" width="64">
      Block Number
    </td>
    
    <td colspan="4" width="80">
      Switches
    </td>
    
    <td colspan="7" width="240">
      Mixes
    </td>
  </tr>
  
  <tr class="headerrow">
    <td width="20">
      D
    </td>
    
    <td width="20">
      C
    </td>
    
    <td width="20">
      B
    </td>
    
    <td width="20">
      A
    </td>
    
    <td width="35">
    </td>
    
    <td width="35">
      1
    </td>
    
    <td width="35">
      2
    </td>
    
    <td width="35">
      3
    </td>
    
    <td width="35">
      4
    </td>
    
    <td width="35">
      5
    </td>
    
    <td width="35">
      Sum
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
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -146
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
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
      -136
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -126
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
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -116
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -106
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -96
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -86
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -76
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -66
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -56
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -46
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
    </td>
    
    <td>
      -36
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      1
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
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      -26
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      -16
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      -6
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      4
    </td>
  </tr>
  
  <tr>
    <td>
      16
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      14
    </td>
  </tr>
  
  <tr>
    <td>
      17
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      120
    </td>
    
    <td>
      24
    </td>
  </tr>
  
  <tr>
    <td>
      18
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      34
    </td>
  </tr>
  
  <tr>
    <td>
      19
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      44
    </td>
  </tr>
  
  <tr>
    <td>
      20
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      54
    </td>
  </tr>
  
  <tr>
    <td>
      21
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -136
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      64
    </td>
  </tr>
  
  <tr>
    <td>
      22
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      -68
    </td>
    
    <td>
      -68
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      74
    </td>
  </tr>
  
  <tr>
    <td>
      23
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      -136
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      60
    </td>
    
    <td>
      120
    </td>
    
    <td>
      84
    </td>
  </tr>
</table> Use the 


	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1482/" rel="nofollow"> Cheat Sheet for Multiplexing three 2-position and one 3-position switches (331 downloads) </a> for calculating all block offset when multiplexing three 2-position switches and one 3-position switch. 

### <span id="Three_3-position_switches">Three 3-position switches</span> The following table shows the signal range and the middle of the effective area for each block. Again, it is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow">
    <td rowspan="2" width="64">
      Block Number
    </td>
    
    <td style="width: 250px;" colspan="6" width="250">
      Block Offsets
    </td>
    
    <td rowspan="2" width="64">
      Mix Target
    </td>
  </tr>
  
  <tr class="headerrow">
    <td colspan="2">
      Dead
    </td>
    
    <td colspan="2">
      Effective
    </td>
    
    <td colspan="2">
      Dead
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -134
    </td>
    
    <td>
      -133
    </td>
    
    <td>
      -132
    </td>
    
    <td>
      -127
    </td>
    
    <td>
      -126
    </td>
    
    <td>
      -125
    </td>
    
    <td>
      -130
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -124
    </td>
    
    <td>
      -123
    </td>
    
    <td>
      -122
    </td>
    
    <td>
      -117
    </td>
    
    <td>
      -116
    </td>
    
    <td>
      -115
    </td>
    
    <td>
      -120
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -114
    </td>
    
    <td>
      -113
    </td>
    
    <td>
      -112
    </td>
    
    <td>
      -107
    </td>
    
    <td>
      -106
    </td>
    
    <td>
      -105
    </td>
    
    <td>
      -110
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -104
    </td>
    
    <td>
      -103
    </td>
    
    <td>
      -102
    </td>
    
    <td>
      -97
    </td>
    
    <td>
      -96
    </td>
    
    <td>
      -95
    </td>
    
    <td>
      -100
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      -94
    </td>
    
    <td>
      -93
    </td>
    
    <td>
      -92
    </td>
    
    <td>
      -87
    </td>
    
    <td>
      -86
    </td>
    
    <td>
      -85
    </td>
    
    <td>
      -90
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      -84
    </td>
    
    <td>
      -83
    </td>
    
    <td>
      -82
    </td>
    
    <td>
      -77
    </td>
    
    <td>
      -76
    </td>
    
    <td>
      -75
    </td>
    
    <td>
      -80
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
      -74
    </td>
    
    <td>
      -73
    </td>
    
    <td>
      -72
    </td>
    
    <td>
      -67
    </td>
    
    <td>
      -66
    </td>
    
    <td>
      -65
    </td>
    
    <td>
      -70
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
      -64
    </td>
    
    <td>
      -63
    </td>
    
    <td>
      -62
    </td>
    
    <td>
      -57
    </td>
    
    <td>
      -56
    </td>
    
    <td>
      -55
    </td>
    
    <td>
      -60
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
      -54
    </td>
    
    <td>
      -53
    </td>
    
    <td>
      -52
    </td>
    
    <td>
      -47
    </td>
    
    <td>
      -46
    </td>
    
    <td>
      -45
    </td>
    
    <td>
      -50
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      -44
    </td>
    
    <td>
      -43
    </td>
    
    <td>
      -42
    </td>
    
    <td>
      -37
    </td>
    
    <td>
      -36
    </td>
    
    <td>
      -35
    </td>
    
    <td>
      -40
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      -34
    </td>
    
    <td>
      -33
    </td>
    
    <td>
      -32
    </td>
    
    <td>
      -27
    </td>
    
    <td>
      -26
    </td>
    
    <td>
      -25
    </td>
    
    <td>
      -30
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      -24
    </td>
    
    <td>
      -23
    </td>
    
    <td>
      -22
    </td>
    
    <td>
      -17
    </td>
    
    <td>
      -16
    </td>
    
    <td>
      -15
    </td>
    
    <td>
      -20
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      -14
    </td>
    
    <td>
      -13
    </td>
    
    <td>
      -12
    </td>
    
    <td>
      -7
    </td>
    
    <td>
      -6
    </td>
    
    <td>
      -5
    </td>
    
    <td>
      -10
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      -4
    </td>
    
    <td>
      -3
    </td>
    
    <td>
      -2
    </td>
    
    <td>
      3
    </td>
    
    <td>
      4
    </td>
    
    <td>
      5
    </td>
    
    <td>
      1
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      6
    </td>
    
    <td>
      7
    </td>
    
    <td>
      8
    </td>
    
    <td>
      13
    </td>
    
    <td>
      14
    </td>
    
    <td>
      15
    </td>
    
    <td>
      11
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
      16
    </td>
    
    <td>
      17
    </td>
    
    <td>
      18
    </td>
    
    <td>
      23
    </td>
    
    <td>
      24
    </td>
    
    <td>
      25
    </td>
    
    <td>
      21
    </td>
  </tr>
  
  <tr>
    <td>
      16
    </td>
    
    <td>
      26
    </td>
    
    <td>
      27
    </td>
    
    <td>
      28
    </td>
    
    <td>
      33
    </td>
    
    <td>
      34
    </td>
    
    <td>
      35
    </td>
    
    <td>
      31
    </td>
  </tr>
  
  <tr>
    <td>
      17
    </td>
    
    <td>
      36
    </td>
    
    <td>
      37
    </td>
    
    <td>
      38
    </td>
    
    <td>
      43
    </td>
    
    <td>
      44
    </td>
    
    <td>
      45
    </td>
    
    <td>
      41
    </td>
  </tr>
  
  <tr>
    <td>
      18
    </td>
    
    <td>
      46
    </td>
    
    <td>
      47
    </td>
    
    <td>
      48
    </td>
    
    <td>
      53
    </td>
    
    <td>
      54
    </td>
    
    <td>
      55
    </td>
    
    <td>
      51
    </td>
  </tr>
  
  <tr>
    <td>
      19
    </td>
    
    <td>
      56
    </td>
    
    <td>
      57
    </td>
    
    <td>
      58
    </td>
    
    <td>
      63
    </td>
    
    <td>
      64
    </td>
    
    <td>
      65
    </td>
    
    <td>
      61
    </td>
  </tr>
  
  <tr>
    <td>
      20
    </td>
    
    <td>
      66
    </td>
    
    <td>
      67
    </td>
    
    <td>
      68
    </td>
    
    <td>
      73
    </td>
    
    <td>
      74
    </td>
    
    <td>
      75
    </td>
    
    <td>
      71
    </td>
  </tr>
  
  <tr>
    <td>
      21
    </td>
    
    <td>
      76
    </td>
    
    <td>
      77
    </td>
    
    <td>
      78
    </td>
    
    <td>
      83
    </td>
    
    <td>
      84
    </td>
    
    <td>
      85
    </td>
    
    <td>
      81
    </td>
  </tr>
  
  <tr>
    <td>
      22
    </td>
    
    <td>
      86
    </td>
    
    <td>
      87
    </td>
    
    <td>
      88
    </td>
    
    <td>
      93
    </td>
    
    <td>
      94
    </td>
    
    <td>
      95
    </td>
    
    <td>
      91
    </td>
  </tr>
  
  <tr>
    <td>
      23
    </td>
    
    <td>
      96
    </td>
    
    <td>
      97
    </td>
    
    <td>
      98
    </td>
    
    <td>
      103
    </td>
    
    <td>
      104
    </td>
    
    <td>
      105
    </td>
    
    <td>
      101
    </td>
  </tr>
  
  <tr>
    <td>
      24
    </td>
    
    <td>
      106
    </td>
    
    <td>
      107
    </td>
    
    <td>
      108
    </td>
    
    <td>
      113
    </td>
    
    <td>
      114
    </td>
    
    <td>
      115
    </td>
    
    <td>
      111
    </td>
  </tr>
  
  <tr>
    <td>
      25
    </td>
    
    <td>
      116
    </td>
    
    <td>
      117
    </td>
    
    <td>
      118
    </td>
    
    <td>
      123
    </td>
    
    <td>
      124
    </td>
    
    <td>
      125
    </td>
    
    <td>
      121
    </td>
  </tr>
  
  <tr>
    <td>
      26
    </td>
    
    <td>
      126
    </td>
    
    <td>
      127
    </td>
    
    <td>
      128
    </td>
    
    <td>
      133
    </td>
    
    <td>
      134
    </td>
    
    <td>
      135
    </td>
    
    <td>
      131
    </td>
  </tr>
</table> The following mixes must be created to multiplex all switches unique configurations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td style="width: 240px;" colspan="5" width="220">
      Mix info
    </td>
    
    <td style="width: 120px;" colspan="3" width="120">
      Mix Output
    </td>
  </tr>
  
  <tr class="headerrow">
    <td width="58">
      Number
    </td>
    
    <td width="48">
      Switch
    </td>
    
    <td width="35">
      High
    </td>
    
    <td width="32">
      Low
    </td>
    
    <td width="46">
      Offset
    </td>
    
    <td width="39">
    </td>
    
    <td width="39">
      1
    </td>
    
    <td width="39">
      2
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      A
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      B
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      C
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -90
    </td>
    
    <td>
    </td>
    
    <td>
      -90
    </td>
    
    <td>
    </td>
    
    <td>
      90
    </td>
  </tr>
</table>

<p class="pleasenote">
  Note that only 3 mix is required for multiplexing three 3-position switches. Mixes are also centered around 0 (instead of starting at -150).
</p> As you can see, the sum of all combined mixes matches the middle section of each effective block: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col span="8" /> </colgroup> <tr class="headerrow">
    <td style="width: 64px;" rowspan="2" width="64">
      Block Number
    </td>
    
    <td style="width: 120px;" colspan="3" width="60">
      Switches
    </td>
    
    <td style="width: 160px;" colspan="4" width="60">
      Mixes
    </td>
  </tr>
  
  <tr class="headerrow">
    <td>
      C
    </td>
    
    <td>
      B
    </td>
    
    <td>
      A
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      Sum
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
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -130
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -120
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -110
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -100
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -90
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -80
    </td>
  </tr>
  
  <tr>
    <td>
      6
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -70
    </td>
  </tr>
  
  <tr>
    <td>
      7
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -60
    </td>
  </tr>
  
  <tr>
    <td>
      8
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      -90
    </td>
    
    <td>
      -50
    </td>
  </tr>
  
  <tr>
    <td>
      9
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
      -40
    </td>
  </tr>
  
  <tr>
    <td>
      10
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
  </tr>
  
  <tr>
    <td>
      11
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
    </td>
    
    <td>
      -20
    </td>
  </tr>
  
  <tr>
    <td>
      12
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
  </tr>
  
  <tr>
    <td>
      13
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      14
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      10
    </td>
  </tr>
  
  <tr>
    <td>
      15
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      20
    </td>
  </tr>
  
  <tr>
    <td>
      16
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
  </tr>
  
  <tr>
    <td>
      17
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
  </tr>
  
  <tr>
    <td>
      18
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      50
    </td>
  </tr>
  
  <tr>
    <td>
      19
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      60
    </td>
  </tr>
  
  <tr>
    <td>
      20
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      -30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      70
    </td>
  </tr>
  
  <tr>
    <td>
      21
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
    </td>
    
    <td>
      90
    </td>
    
    <td>
      80
    </td>
  </tr>
  
  <tr>
    <td>
      22
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      90
    </td>
    
    <td>
      90
    </td>
  </tr>
  
  <tr>
    <td>
      23
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
    </td>
    
    <td>
      90
    </td>
    
    <td>
      100
    </td>
  </tr>
  
  <tr>
    <td>
      24
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      110
    </td>
  </tr>
  
  <tr>
    <td>
      25
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      120
    </td>
  </tr>
  
  <tr>
    <td>
      26
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
      2
    </td>
    
    <td>
      10
    </td>
    
    <td>
      30
    </td>
    
    <td>
      90
    </td>
    
    <td>
      130
    </td>
  </tr>
</table> Use the 


	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1484/" rel="nofollow"> Cheat Sheet for Multiplexing three 3-position switches (339 downloads) </a> for calculating all block offset when multiplexing three 3-position switches. 

## <span id="Decoding">Decoding</span> Decoding the switches configuration is relatively easy: First identify the block number matching the signal&#8217;s value using a sequence of &#8220;

_if_&#8221; statements. Then, update switches state based on the currently selected block. Refer to tables above for offsets & switches states for each selected block. 

<p class="pleasenote">
  Note that if you get a signal value that is within the dead zone, it probably means that you have an issue with your transmitter mixes. Verify your mixes and try again.
</p> Since reading switches states does not imply any analog value, you do not really care if the signal value is within the effective area (or not) so clamping is not necessary beside detecting instability issue in the signal. However, in the low probability that you get a signal within a dead zone, then the first dead zone should be considered as if you read the first value of the effective area and the last dead zone as the last value of the effective area. 

### <span id="Required_Libraries">Required Libraries</span>

<span style="text-decoration: underline;"><span style="font-size: 16pt;"><a href="https://github.com/GreyGnome/PinChangeInt">PinChangeInt </a></span></span>This library allows the arduino to attach interrupts on multiple pins. <span style="text-decoration: underline;"><span style="font-size: 16pt;"><a href="http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html">eRCaGuy_Timer2_Counter </a></span></span>(optional) This library configures the arduino&#8217;s timer2 to 0.5µs precision. It is used for a _micros()_ function replacement and allows times calculations that are far more precise (8 times!) than the default&#8217;s 4µs resolution. 

### <span id="Code_sample">Code sample</span> The following arduino code (*.ino) can be used to demultiplex the three scenarios above: 

<pre class="height-set:true lang:c++ decode:true" title="Demultiplex discrete values from a RC Transmitter PWM Signal" data-url="http://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexDiscrete.ino">http://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexDiscrete.ino</pre>

### <span id="Sample_data">Sample data</span>

<div id='gallery-12' class='gallery galleryid-1249 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-4x-2-position-switches-Data-Capture-Sample.png" title="Demultiplexing four 2-position switches : Sample data" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-4x-2-position-switches-Data-Capture-Sample-150x141.png" width="150" height="141" alt="Demultiplexing four 2-position switches : Sample data" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-4x-2-position-switches-Data-Capture-Sample.png" rel="nolightbox" target="_blank">559x527</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1477">
      <span class="imagecaption">Demultiplexing four 2-position switches : Sample data</span><br />
    </dd>
  </dl>
  
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample.png" title="Demultiplexing a 3-Position and three 2-Position switches : Sample data" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample-150x145.png" width="150" height="145" alt="Demultiplexing a 3-Position and three 2-Position switches : Sample data" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample.png" rel="nolightbox" target="_blank">539x520</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1479">
      <span class="imagecaption">Demultiplexing a 3-Position and three 2-Position switches : Sample data</span><br /> <span class="imagedescription">Demultiplexing a 3-Position and three 2-Position switches : Sample data</span><br />
    </dd>
  </dl>
  
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-3-Position-switches-Data-Capture-Sample.png" title="Demultiplexing three 3-Position switches : Sample data" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-3-Position-switches-Data-Capture-Sample-150x145.png" width="150" height="145" alt="Demultiplexing three 3-Position switches : Sample data" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-3x-3-Position-switches-Data-Capture-Sample.png" rel="nolightbox" target="_blank">533x514</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1489">
      <span class="imagecaption">Demultiplexing three 3-Position switches : Sample data</span><br /> <span class="imagedescription">Demultiplexing three 3-Position switches : Sample data</span><br />
    </dd>
  </dl>
  
  <br style="clear: both" />
</div>

# <span id="Multiplexing_an_analog_input_and_switches">Multiplexing an analog input and switches</span>

## <span id="Design-2">Design</span> Including an analog value (usually a rotating knob) into the multiplexed signal is also possible. However, only a single analog value can be multiplexed. 

<p class="pleasenote">
  Please note that including an analog value reduces the number of switches that can be multiplexed into the signal.
</p>

## <span id="Define_resolution">Define resolution</span> Defining the resolution of the analog value means that you must choose the granularity of the value. By default the analog value has at least 200 different values and ranges from -100% to +100%. Since you also want to multiplex switches into the same signal, the resolution must be reduced from 200 different values to a lot less. To support a desired resolution, multiple blocks will need to be sacrificed. I do recommend a resolution of 40 steps (with values from 0 to 39) which is a nice resolution to allow enough details and can also be subdivided into other zones. 

## <span id="What8217s_different">What&#8217;s different</span> The design for including an analog value is different than having only switches. 

### <span id="Block_size-2">Block size</span> Block size must be increased to allow the desired resolution. The higher the resolution, the less switches you can multiplex. The block size must be big enough to fit both dead zones and the desired resolution. 

### <span id="Dead_zone">Dead zone</span> A dead zone of 3 steps is also suggested. For instance, to support a resolution of 40 different steps, the block size must be of 46 steps (3+40+3=46). The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 46 steps and a dead zone of 3 steps which makes the effective block size to 40 steps: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col span="7" /> </colgroup> <tr class="headerrow">
    <td rowspan="2">
      Block Number
    </td>
    
    <td colspan="6">
      Block Offsets
    </td>
  </tr>
  
  <tr class="headerrow">
    <td colspan="2" width="80">
      Dead
    </td>
    
    <td colspan="2" width="80">
      Effective
    </td>
    
    <td colspan="2" width="80">
      Dead
    </td>
  </tr>
  
  <tr>
    <td>
    </td>
    
    <td>
      -150
    </td>
    
    <td>
      -148
    </td>
    
    <td>
      -147
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      -107
    </td>
    
    <td>
      -105
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
      -104
    </td>
    
    <td>
      -102
    </td>
    
    <td>
      -101
    </td>
    
    <td>
      -62
    </td>
    
    <td>
      -61
    </td>
    
    <td>
      -59
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
      -58
    </td>
    
    <td>
      -56
    </td>
    
    <td>
      -55
    </td>
    
    <td>
      -16
    </td>
    
    <td>
      -15
    </td>
    
    <td>
      -13
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      -12
    </td>
    
    <td>
      -10
    </td>
    
    <td>
      -9
    </td>
    
    <td>
      30
    </td>
    
    <td>
      31
    </td>
    
    <td>
      33
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      34
    </td>
    
    <td>
      36
    </td>
    
    <td>
      37
    </td>
    
    <td>
      76
    </td>
    
    <td>
      77
    </td>
    
    <td>
      79
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      80
    </td>
    
    <td>
      82
    </td>
    
    <td>
      83
    </td>
    
    <td>
      122
    </td>
    
    <td>
      123
    </td>
    
    <td>
      125
    </td>
  </tr>
</table>

<div class="pleasenote">
  Note that only 6 blocks can be defined using a block size of 46 steps. These blocks only allows 2 sub configurations for multiplexing switches: 
  
  <ul>
    <li>
      2-position switch + 3-position switch
    </li>
    <li>
      Two 2-position switches
    </li>
  </ul>
</div>

## <span id="Mixes-2">Mixes</span> When multiplexing an analog value, mixes do not have to target the middle of the block&#8217;s effective zone (as with switches) since the signal&#8217;s value can move within the whole effective area of the block. Assuming the first configuration (2-pos + 3-pos), the following mixes must be created to multiplex all switches unique configurations: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col /> <col /> <col /> <col /> <col /> <col span="3" /> </colgroup> <tr class="headerrow">
    <td style="width: 240px;" colspan="5">
      Mix info
    </td>
    
    <td style="width: 120px;" colspan="3">
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
      RKnob
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
      RKnob
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
    <td>
      2
    </td>
    
    <td>
      A
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
      B
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

<p class="pleasenote">
  Note that first 2 mix are mapped to the right knob to reach the effective range of the first block (-147% to -108%). Switch B is a 3-position switch and offsets the analog range between block 0 to 2. Then the 3rd mix, assigned to Switch A (2-position), offsets the 3 effective block of switch B to block 0-2 or 3-5.
</p> As you can see, the sum of all combined mixes matches the middle section of each effective block: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <colgroup> <col /> <col span="2" /> <col /> <col span="5" /> </colgroup> <tr class="headerrow">
    <td style="width: 64px;" rowspan="2">
      Block Number
    </td>
    
    <td style="width: 100px;" colspan="3">
      Switches
    </td>
    
    <td style="width: 160px;" colspan="5">
      Mixes
    </td>
  </tr>
  
  <tr class="headerrow">
    <td>
      A
    </td>
    
    <td>
      B
    </td>
    
    <td>
      RKnob
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      3
    </td>
    
    <td>
      Sum
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
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -147
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
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      46
    </td>
    
    <td>
      -101
    </td>
  </tr>
  
  <tr>
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      1
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
    </td>
    
    <td>
      46
    </td>
    
    <td>
      -62
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      92
    </td>
    
    <td>
      -55
    </td>
  </tr>
  
  <tr>
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      2
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
    </td>
    
    <td>
      92
    </td>
    
    <td>
      -16
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
      138
    </td>
    
    <td>
    </td>
    
    <td>
      -9
    </td>
  </tr>
  
  <tr>
    <td>
      3
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      138
    </td>
    
    <td>
    </td>
    
    <td>
      30
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
      138
    </td>
    
    <td>
      46
    </td>
    
    <td>
      37
    </td>
  </tr>
  
  <tr>
    <td>
      4
    </td>
    
    <td>
      1
    </td>
    
    <td>
      1
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      138
    </td>
    
    <td>
      46
    </td>
    
    <td>
      76
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
    </td>
    
    <td>
      -147
    </td>
    
    <td>
    </td>
    
    <td>
      138
    </td>
    
    <td>
      92
    </td>
    
    <td>
      83
    </td>
  </tr>
  
  <tr>
    <td>
      5
    </td>
    
    <td>
      1
    </td>
    
    <td>
      2
    </td>
    
    <td>
      40
    </td>
    
    <td>
    </td>
    
    <td>
      -108
    </td>
    
    <td>
      138
    </td>
    
    <td>
      92
    </td>
    
    <td>
      122
    </td>
  </tr>
</table> Use the 


	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/1510/" rel="nofollow"> Cheat Sheet for Multiplexing an Analog Knob with a 2-position and a 3-position switch (309 downloads) </a> for calculating all block offset when multiplexing an analog value with a 2-position and a 3-position switch. 

## <span id="Decoding-2">Decoding</span> Decoding an analog value with switches configuration is different: First identify the block number matching the signal&#8217;s value using a sequence of &#8220;if&#8221; statements. Then 

[clamp][2] the value within the effective block area. This is required since the signal can get close to a dead zone (or even reach a dead zone!). To get the actual analog value, you must also offset the block&#8217;s effective range to get a constant 0-39 range. Finally, update switches state based on the currently selected block. Refer to tables above for offsets & switches states for each selected block. 

<p class="pleasenote">
  Note that reading a value (with the micro-controller) that is outside the analog effective area should be considered the same as reading an analog value of 0 or 39 depending on the closest dead zone.
</p>

### <span id="Code_sample-2">Code sample</span> The following arduino code (*.ino) can be used to demultiplex the scenario above: 

<pre class="height-set:true lang:c++ decode:true" title="Demultiplex an analog value from a RC Transmitter PWM Signal" data-url="http://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexAnalog.ino">http://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexAnalog.ino</pre>

### <span id="Sample_data-2">Sample data</span>

<div id='gallery-13' class='gallery galleryid-1249 gallery-columns-3 gallery-size-thumbnail gallery1'>
  <dl class="gallery-item">
    <dt class="gallery-icon">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-Analog-Knob-with-1x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample.png" title="Demultiplexing an analog knob with a 2-Position and a 3-Position switch : Sample data" rel="gallery1"><img src="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-Analog-Knob-with-1x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample-146x150.png" width="146" height="150" alt="Demultiplexing an analog knob with a 2-Position and a 3-Position switch : Sample data" /></a><span><a class="void" href="http://www.end2endzone.com/wp-content/uploads/2016/02/Multiplexing-Analog-Knob-with-1x-2-Position-and-1x-3-Position-switches-Data-Capture-Sample.png" rel="nolightbox" target="_blank">498x510</a></span>
    </dt>
    
    <dd class="gallery-caption" id="caption1519">
      <span class="imagecaption">Demultiplexing an analog knob with a 2-Position and a 3-Position switch : Sample data</span><br /> <span class="imagedescription">Demultiplexing an analog knob with a 2-Position and a 3-Position switch : Sample data</span><br />
    </dd>
  </dl>
  
  <br style='clear: both' />
</div>

 [1]: #Mixes
 [2]: https://www.google.com/?q=clamp+integer+c%2B%2B