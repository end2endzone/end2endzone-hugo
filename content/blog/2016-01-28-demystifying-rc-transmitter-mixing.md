---
title: Demystifying RC Transmitter Mixing
author: end2end
type: post
date: 2016-01-28T17:44:31+00:00
url: /demystifying-rc-transmitter-mixing/
featured_image: /wp-content/uploads/2016/01/Demystifying-RC-Transmitter-Mixing-672x378.jpg
hits:
  - 10038
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">RC Transmitter Mix Calculator:</p>
        <ul class="fa-ul">
        <li><a href="/download/1255/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="1255" template="title"]</a></li>
        </ul>
        </div>
        
categories:
  - Model Aeronautics
tags:
  - english
  - RC
  - RC transmitter

---
# <span id="Introduction">Introduction</span> If you look on the internet for &#8220;mixing&#8221;, you will usually find posts and articles of people asking for things like &#8220;what is the best mix I should use for this or that&#8221; which I think is not helpful. I think it is far more helpful to actually understand what mixing is and how it can help you improve your skills as a pilot. Lately I wanted to understand how mixing could help me in a personal project. I took this opportunity to learn something new and try to demystifying RC Transmitter Mixing.

<!--more-->

<p class="postedit">
  EDIT: To make all mixing pre-calculations easier, do not hesitate to use my <a href="/rc-transmitter-mix-calculator/">Mixing Calculator for R/C Transmitter</a> (it&#8217;s an Excel Sheet!)
</p> I am really new to mixing. I have flown all my planes without ever used any mix. This is mostly because I have never had the need to use some (I&#8217;ve always been trying to make adjustment manually with the sticks to improve my skills). 

<p class="pleasenote" data-pleasenote="true">
  As a side note, I have never touch anything related to helicopter mixing which looks more complicated and is not covered here.
</p>

# <span id="What_is_mixing">What is mixing ?</span> According to the 

[User Manual of the Spektrum DX9 Instruction Manual][1], this is the definition of Mixing: 

<div class="quotesection">
  Mixing allows control input for a channel to affect more than one channel at a time. Mixing functions support: 
  
  <ul style="text-align: justify;">
    <li>
      Mixing a channel to another channel.
    </li>
    <li>
      Mixing a channel to itself.
    </li>
    <li>
      Assigning offset to a channel
    </li>
    <li>
      Linking primary to secondary trim.
    </li>
  </ul> These mixes are available for each model memory. Select a channel for master and slave. Inputs for the Master Channel control both the master and Slave Channels. For example, Elevator to Flap makes elevator the Master Channel and flap the Slave Channel. Change the offset value to move the effective center position of the Slave Channel. Positive or negative value determines the direction of the offset. Offset is not available for curve mixes.
</div> In other words, mixing allows you to affect a Slave Channel based on the input of another (master). By mastering the art of mixing, you will reduce the amount of small corrections you make to get the desired flight pattern. A mix is composed of the following: 

  * Master & Slave Channels.
  * High and Low rates value.
  * An offset value.
  * A trim value (not always, not covered in this article) All mix properties shall be in the following range: 

  * High and Low rates shall be in the range -125 to +125.
  * Offset shall be in the range -100 to +100.
  * Minimum calculated mix value shall be -150.
  * Maximum calculated mix value shall be +150. Mixes can also be enabled or disabled based on a switch. This is useful to get different behavior based for instance on a flight mode. Multiple mixes can also be combined (see 

[Combining mixes][2]) into the same Slave Channel to get different effects. 

# <span id="When_to_not_use_mixes">When to not use mixes</span> There is a lot of situations where using mixes is not recommended: 

<li style="text-align: justify;">
  If you are flying a &#8220;trainer&#8221;. It is called a trainer for a reason. It means you should train yourself as a pilot to make the corrections yourself.
</li>
<li style="text-align: justify;">
  If you are a new pilot (flying for less than 2-3 years). Using mixes wont make you a better pilot. In fact it will make things worst. Is is only recommended to learn to fly first without any help from your transmitter and then experiment at a higher skill level.
</li> Using mixes is not the best thing for the development of your skills. Learn to fly without any mix first to learn the proper technique. As for personal development, it is far more rewarding to not use mixes at all. It will pay off and you will thank yourself in the future. Keep in mind that mixes does not solve everything. In fact, the more mixes you have, the bigger your problem could get. If you add a Ailerons to Rudder mix to get good coordinated turns, imagine trying to land in a cross wind situation or flying inverted. Things can get ugly pretty quick. It is also strongly suggested to assign a switch to a mix in order to toggle the mix ON and OFF. This way, if something is wrong with the mix, you can get back to the normal behavior of your transmitter. 

# <span id="Basicmixes">Basic mixes</span> There are some basic mixes that you may be interested into. Here are some example: 

## <span id="Throttle_toElevator">Throttle to Elevator</span> In order to keep the same altitude, the amount of elevator may differ depending on your true air speed. By mixing a certain amount of Throttle into the Elevator, this can be adjusted automatically by the transmitter. 

## <span id="Rudder_toAilerons">Rudder to Ailerons</span> When turning, you usually add a little bit of Rudder to keep the same altitude and make a good coordinated turn. Adding a Rudder to Aileron mix will reduce this effect. This configuration also keeps the ailerons from moving free for greater turns. Keep in mind that this mix may not be recommended. Most trained pilot does not use this kind of mix. Using this mix in calm or medium breeze wind will help but as soon as the wind condition change you will still require good rudder skills to make those turns look nice. I personally never used this one. IMO what defines a good pilot from a great pilot is how he masters the rudder. 

# <span id="Advanced_Mixes">Advanced Mixes</span>

## <span id="DifferentialThrust">Differential Thrust</span> This is for a twin engine plane where each ESC is controlled by a separate channel: left engine channel and right engine channel. Throttle is assigned to Left Engine Channel, a mix is used to drive the Right Engine Channel from Throttle. Another mix is used to mix Rudder into Left or Right Engine Channel. When Rudder is centered, both throttle channels are equals. When Rudder is moved to right, the left engine channel increase power. When Rudder is moved to left, the right engine channel increase power. 

## <span id="Ailerons_toFlaps">Ailerons to Flaps</span> This one is only available if your flaps can move up. It wont work if your flaps only goes down. Mixing your ailerons to your flaps will allow your flaps to follow its matching aileron effectively turning the whole trailing edge of the wing into one long aileron. This is useful for some high aerobatic maneuvers. 

## <span id="Flaps_toElevator">Flaps to Elevator</span> Mix a small amount of Flaps in Elevator (the opposite way) to prevent the &#8220;bump&#8221; caused by enabling the flaps. 

# <span id="Useful_mixes">Useful mixes</span>

## <span id="Cancelling_a_switch">Cancelling a switch</span> A mix can also be used to cancel a switch assigned to a channel. If you need to invalidate/ignore a switch, a mix can cancel out the effect. In other words, the assigned channel will be reset to 0 (center position) what ever the switch position is. Use the following mix values to cancel a switch: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        High
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        100%
      </td>
    </tr>
    
    <tr>
      <td>
        Low
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
    
    <tr>
      <td>
        Offset
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
  </table>
</div> This trick can come valuable in some situation. 

## <span id="Forcing_a_value">Forcing a value</span> A mix can be used to force a given value to a channel. A typical use is triggering Failsafe flight mode. Say you have the following flight modes: 

**\[gps\] \[failsafe\] \[attitude\] \[failsafe\] [manual]**. Assuming that the first Failsafe mode is identical to the second Failsafe, you need to assign two 2-position switches to implement all possible modes. In this case, no mix is required. Another way of implementing this is to use a 3-position switch and assign the **[gps]**, **[attitude]** and **[manual]** flight modes to this switch and use a second 2-position switch as a &#8220;panic&#8221; switch that triggers \[Failsafe\] (while also disabling the flight mode switch). A mix is required to cancel out the first switch and a second mix to force the flight mode channel to move to [Failsafe] position. See also [Cancelling a switch][3]. 

## <span id="Throttle_cut_mix">Throttle cut mix</span> By combining 

[Cancelling a switch][3] and [Forcing a value][4] mixes, one can create mixes slaved to Throttle to achieve a _Throttle Cut_ safety by forcing the Throttle channel to -150 which disables the Throttle stick and prevents propeller injuries. 

# <span id="Generic_mixes">Generic mixes</span>

## <span id="Positive_only_mix">Positive only mix</span> Use the following mix to cancel the negative portion of a switch resulting in an effective range of 0% to 100%. 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        High
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        50%
      </td>
    </tr>
    
    <tr>
      <td>
        Low
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
    
    <tr>
      <td>
        Offset
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
  </table>
</div>

## <span id="Parabolic_mix">Parabolic mix</span> Use the following to get an effective range of 100% to 0% to 100%. 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        High
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        100%
      </td>
    </tr>
    
    <tr>
      <td>
        Low
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
    
    <tr>
      <td>
        Offset
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
  </table>
</div> In other words: 

  * A knob will show 100% when completely clockwise or counter clockwise but show 0% when halfway turned.
  * A 3-position switch will show 100% in Position 0 and Position 2 but 0% in Position 1.
  * A 2-position switch will always show 100%.

## <span id="Inverted_polarity_mix">Inverted polarity mix</span> Use the following to invert the polarity of a switch or a knob resulting in an effective range from +100 to -100 instead of -100 to +100. 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        High
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        100%
      </td>
    </tr>
    
    <tr>
      <td>
        Low
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
    
    <tr>
      <td>
        Offset
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
  </table>
</div> This feature may be required if a transmitter does not support native inverting for the desired switch. A possible use to this kind of mix is for handling ailerons when each aileron have their own servo and channel. 

# <span id="The_Mathematical_calculations">The Mathematical calculations</span>

## <span id="The_equation">The equation</span>

<p class="pleasenote">
  <strong>Note:</strong> The following is an extract of how the Spektrum transmitters calculate mixes. Please note that your mileage could vary if you use a different kind of transmitter.
</p> A 3-position switch will define 3 values for a given mix: Position 0, Position 1 and Position 2 while a 2-position switch will define 2 values for a mix: Position 0 and Position 1. Position 0 of a 2-position switch matches Position 0 of a 3-position switch and Position 1 of a 2-position switch matches Position 2 of a 3-position switch. The following table list position matches: 

<table class="generictable" border="0" cellspacing="0" cellpadding="0">
  <tr class="headerrow">
    <td colspan="2">
      Switch types
    </td>
  </tr>
  
  <tr class="headerrow">
    <td style="width: 80px;" width="80">
      3-position
    </td>
    
    <td style="width: 80px;" width="80">
      2-position
    </td>
  </tr>
  
  <tr>
    <td>
      Position 0
    </td>
    
    <td>
      Position 0
    </td>
  </tr>
  
  <tr>
    <td>
      Position 1
    </td>
    
    <td>
    </td>
  </tr>
  
  <tr>
    <td>
      Position 2
    </td>
    
    <td>
      Position 1
    </td>
  </tr>
</table> The following equation will help you solve an endless issue: How to calculate a mix boundaries: 

<div class="quotesection">
  <p style="text-align: justify;">
    OffsetTravel = (switch default travel (see below)) &#8211; Offset if OffsetTravel < 0 SwitchMixValue = OffsetTravel / 100 * Low rate else SwitchMixValue = OffsetTravel / 100 * High rate
  </p>
</div> A 3-position switch has the following default travel values: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        Position 0
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
    
    <tr>
      <td>
        Position 1
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
    
    <tr>
      <td>
        Position 2
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        +100%
      </td>
    </tr>
  </table>
</div> And a 2-position switch has the following default travel values: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        Position 0
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        -100%
      </td>
    </tr>
    
    <tr>
      <td>
        Position 1
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        +100%
      </td>
    </tr>
  </table>
</div> For instance, the following mix: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        High
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        50%
      </td>
    </tr>
    
    <tr>
      <td>
        Low
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        50%
      </td>
    </tr>
    
    <tr>
      <td>
        Offset
      </td>
      
      <td class="sign">
        =
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
  </table>
</div> assigned to a 3-position switch, will add the following values to its Slave Channel: 

<div class="rcchannels">
  <table cellspacing="0" cellpadding="0">
    <tr>
      <td class="names">
        Position 0
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        +50%
      </td>
    </tr>
    
    <tr>
      <td>
        Position 1
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        0%
      </td>
    </tr>
    
    <tr>
      <td>
        Position 2
      </td>
      
      <td class="sign">
        :
      </td>
      
      <td class="values">
        -50%
      </td>
    </tr>
  </table>
</div> The easiest way to calculate a mix boundaries is to use this 

[Excel Worksheet][5]. 

## <span id="Combining_mixes">Combining mixes</span>

### <span id="Mixes_of_the_same_Slave_Channel_are_combined">Mixes of the same Slave Channel are combined</span> All mixes assigned to the same Slave Channel are combined (added to each other). In other words, if a first mix ranges from -100 to +100 is assigned to AUX1 and a second mix which is also assigned to AUX1 ranges from -25 to +25, then AUX1 effective range will be -125 to +125. 

### <span id="Mixes_are_combined_with_assigned_switches">Mixes are combined with assigned switches</span> If a switch is assigned to the same Slave Channel as other mixes, they will be combined. In other words, if switch G is assigned to AUX1 and has travel set to range from -130 to +130 and a mix that ranges from -20 to +20 is also assigned to AUX1, then AUX1 effective range will be -150 to +150. 

### <span id="Combining_mixes_to_multiplex_multiple_switches">Combining mixes to multiplex multiple switches</span> Mixes can also be used to multiplex multiple inputs into a single channel. This procedure is covered in its own article: 

_**[ARTICLE TO BE PUBLISHED SOON]**_. 

# <span id="Other_lectures">Other lectures</span> Here is more information to better understand mixing: 

  * [Solving the DX8 spectrum mix setting mystery][6] (or [here][7])
  * [Mixing &#8211; DX9 Wiki &#8211; Wikia][8]

 [1]: http://www.horizonhobby.com/pdf/SPMR9900-Manual_EN.pdf
 [2]: #Combining_mixes
 [3]: #Cancelling_a_switch
 [4]: #Forcing_a_value
 [5]: /rc-transmitter-mix-calculator/
 [6]: http://www.helifreak.com/showpost.php?s=bf5c92b4901bbc01862159e89eb118c8&p=5479009&postcount=14
 [7]: http://www.helifreak.com/showthread.php?p=5370251
 [8]: http://dx9.wikia.com/wiki/Mixing