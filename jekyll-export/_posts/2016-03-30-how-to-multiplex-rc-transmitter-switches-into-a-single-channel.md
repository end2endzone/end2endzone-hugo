---
id: 1249
title: 'How to multiplex RC Transmitter switches into a single channel'
date: '2016-03-30T13:15:24+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1249'
permalink: '/?p=1249'
hits:
    - '547'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Cheat sheets:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/1486/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>Multiplexing 2-position switches</a></li>\n<li><a href=\"/download/1482/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>Multiplexing 2-position + 3-position switches</a></li>\n<li><a href=\"/download/1484/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>Multiplexing 3-position switches</a></li>\n<li><a href=\"/download/1510/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>Multiplexing analog &amp; switches</a></li>\n</ul>\n</div>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Code samples:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/2071/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2071\" template=\"title\"]</a></li>\n<li><a href=\"/download/2069/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2069\" template=\"title\"]</a></li>\n</ul>\n</div>"
image: /wp-content/uploads/2016/03/How-to-multiplex-RC-Transmitter-switches-into-a-single-channel.jpg
categories:
    - 'Model Aeronautics'
tags:
    - arduino
    - diy
    - english
    - 'open source'
    - RC
    - 'RC transmitter'
---

# Introduction

In a personal project, I wanted to add 2 new devices to an existing quadcopter. The quadcopter was equipped with a 6-channel receiver meaning I only had 1 spare channel to control the 2 devices: <div class="rcchannels">| CH 1 | : | Throttle |
|---|---|---|
| CH 2 | : | Rudder |
| CH 3 | : | Ailerons |
| CH 4 | : | Elevator |
| CH 5 | : | Flight mode |
| CH 6 | : | ??? |

</div>The following article explains how I manage to solve the issue: *How can I control more than one device using a single channel*. EDIT: To make all mixing pre-calculations easier, do not hesitate to use my [Mixing Calculator for R/C Transmitter](/rc-transmitter-mix-calculator/) (it's an Excel Sheet!)

I could have used an 8-channel receiver to solve this but I did not had a free receiver that I could spare. This guide will show you how to multiplex RC transmitter switches (inputs) into a **single** channel.

# Use a microcontroller

For this type of project, 7 channels is usually required. The easiest method would have been to replace the receiver but since I like the DIY way, I decided to multiplex two switches into the 6th channel and use a microcontroller to read the signal and demultiplex each switches states. **Note:** This is only valid if there is a microcontroller connected with the receiver that  ***you***  can program to demultiplex the signal. Do not expect your proprietary flight controller to be able to understand your signal.

# Multiplexing switches (only)

## Design

The following section illustrate the design required for multiplexing as much information as possible into a single channel.

### Create blocks

The generic idea is to divide the whole range of the signal (from -150% to 150%) into blocks or bands. Each block correspond to a unique configuration of all switches. Then you create the required mixes to move/update the signal value to the block corresponding to the switches unique configuration.

### Minimum number of blocks

The following explain what is the minimum number of blocks that are required for multiplexing a given amount of switches. The number of required blocks for a given number of switches is defined by the all the unique combinations that are possible with the switches. To calculate this, you multiply the number of combinations of each switch by each other. For instance: To multiplex three 2-position switches, 8 blocks are required (2\*2\*2) which makes 8 unique combinations: | **Block Number** | **Switches** |
|---|---|
| **2-pos** | **2-pos** | **2-pos** |
| 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 |
| 2 | 0 | 1 | 0 |
| 3 | 0 | 1 | 1 |
| 4 | 1 | 0 | 0 |
| 5 | 1 | 0 | 1 |
| 6 | 1 | 1 | 0 |
| 7 | 1 | 1 | 1 |

To multiplex two 2-position and one 3-position switches, 12 blocks are required (2\*2\*3) which makes 12 unique combinations: | **Block Number** | **Switches** |
|---|---|
| **2-pos** | **2-pos** | **3-pos** |
| 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 |
| 2 | 0 | 0 | 2 |
| 3 | 0 | 1 | 0 |
| 4 | 0 | 1 | 1 |
| 5 | 0 | 1 | 2 |
| 6 | 1 | 0 | 0 |
| 7 | 1 | 0 | 1 |
| 8 | 1 | 0 | 2 |
| 9 | 1 | 1 | 0 |
| 10 | 1 | 1 | 1 |
| 11 | 1 | 1 | 2 |

Note that each switch also requires a mix for working. The amount of switches you can multiplex is then also limited by the amount of mixes you can define in your transmitter.

## Supporting 3-position switches

In your design, you will have to decide to support or not 3-position switches. If you do, it will reduce the amount of switches you can multiplex into a single channel since each switches requires 3 blocks instead of 2 blocks. An acceptable compromise is to use this switch as a 2-position switch. Position 1 would then be identical as Position 0 (OFF) and Position 2 would be ON.

## Dead Zone

Blocks cannot be juxtaposed to each other and dead zones must be inserted between (or within) blocks. This is required since each transmitters and micro-controllers do not offer the same performance and precision. Dead zones are required since a micro-controller might read data from block 5 but the next pulse of the same signal may introduce a 5uS delay, which would correspond to a different block (ie block 6). For instance, if the following blocks are defined: | **Block** | **Min** | **Max** |
|---|---|---|
| 0 | -150% | -141% |
| 1 | -140% | -131% |
| 2 | -130% | -121% |
| 3 | -120% | -111% |

The difference between -131% (block 1) and -130% (block 2) is ~5uS. If blocks would be juxtaposed, then the micro-controller could sometimes read block 1 and sometimes block 2 which does not mean the same thing at all. This delay might be from the receiver who does not provide a perfect pulse length or from the micro-controller who does not detect the end of the pulse with enough precision. Both errors can be avoided with dead zones. By introducing a dead zone of 5 steps within blocks (of 10 steps), the same blocks would then become something like: | **Block** | **Min** | **Max** | **Mix Target** |
|---|---|---|---|
| DEAD | -150% | -148% |  |
| 0 | -147% | -143% | -145% |
| DEAD | -142% | -138% |  |
| 1 | -137% | -133% | -135% |
| DEAD | -132% | -128% |  |
| 2 | -127% | -123% | -125% |
| DEAD | -122% | -113% |  |
| 3 | -117% | -113% | -115% |

The block size must also have a minimum size to account for the same effect. If the block size is too small, the micro-controller might read data from a dead zone and would not know what to do. The more accurate the receiver and the micro-controller, the smaller the block size and dead zone size can be. Mixes should be created to move the actual signal values to target the middle of the effective block area (not the dead zone). See the [Mixes](#Mixes) section for more details.

## Block size

Based on my observation, the best values for block size and dead zone size are as follow: A block size of 10 steps is big enough to allow multiplexing a high amount of switches while leaving enough space for a reasonable dead zone between blocks. At the same time, a block size of 10 steps allows the blocks to be rounded easily which makes blocks offsets easy to calculate. The acceptable dead zone size (considering the average precision of most micro-controller and receivers), does not need to be bigger than 2 steps. This configuration leaves two blocks spaced by 4 steps which is enough to prevent issues. The following values are then considered "safe and tested" to get good and stable results: <div class="rcchannels">| Block size | : | 10 steps |
|---|---|---|
| Dead zone | : | 2 steps |
| Effective size | : | 6 steps |

</div>## Mixes

The following section defines mix that are required to implement two basic scenarios. Note that you can easily calculate the effect of a given mix by using my [RC Transmitter Mix Calculator](/rc-transmitter-mix-calculator/) to identify the minimum, middle and maximum values of a mix.

### Four 2-position switches

The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: | Block Number | Block Offsets | Mix Target |
|---|---|---|
| Dead | Effective | Dead |
| 0 | -150 | -149 | -148 | -143 | -142 | -141 | -146 |
| 1 | -140 | -139 | -138 | -133 | -132 | -131 | -136 |
| 2 | -130 | -129 | -128 | -123 | -122 | -121 | -126 |
| 3 | -120 | -119 | -118 | -113 | -112 | -111 | -116 |
| 4 | -110 | -109 | -108 | -103 | -102 | -101 | -106 |
| 5 | -100 | -99 | -98 | -93 | -92 | -91 | -96 |
| 6 | -90 | -89 | -88 | -83 | -82 | -81 | -86 |
| 7 | -80 | -79 | -78 | -73 | -72 | -71 | -76 |
| 8 | -70 | -69 | -68 | -63 | -62 | -61 | -66 |
| 9 | -60 | -59 | -58 | -53 | -52 | -51 | -56 |
| 10 | -50 | -49 | -48 | -43 | -42 | -41 | -46 |
| 11 | -40 | -39 | -38 | -33 | -32 | -31 | -36 |
| 12 | -30 | -29 | -28 | -23 | -22 | -21 | -26 |
| 13 | -20 | -19 | -18 | -13 | -12 | -11 | -16 |
| 14 | -10 | -9 | -8 | -3 | -2 | -1 | -6 |
| 15 | 0 | 1 | 2 | 7 | 8 | 9 | 5 |

The following mixes must be created to multiplex all switches unique configurations: | Mix info | Mix Output |
|---|---|
| Number | Switch | High | Low | Offset | 0 | 1 |
| 0 | A | -100 | 100 | 0 | -100 | -100 |
| 1 | A | -46 | 36 | 0 | -46 | -36 |
| 2 | B | 0 | -20 | 0 | 0 | 20 |
| 3 | C | 0 | -40 | 0 | 0 | 40 |
| 4 | D | 0 | -80 | 0 | 0 | 80 |

Note that first 2 mix are mapped to switch A. This is required since the minimum value of a High rate mix is -125% which gives a final mix value of -125% at Position 0. The only way to get a lower value (ie -146) would be to offset the mix (by -17) but then the Low rate value would have the same issue.

As you can see, the sum of all combined mixes matches the middle section of each effective block: | Block Number | Switches | Mixes |
|---|---|---|
| D | C | B | A | 0 | 1 | 2 | 3 | 4 | Sum |
| 0 | 0 | 0 | 0 | 0 | -100 | -46 | 0 | 0 | 0 | -146 |
| 1 | 0 | 0 | 0 | 1 | -100 | -36 | 0 | 0 | 0 | -136 |
| 2 | 0 | 0 | 1 | 0 | -100 | -46 | 20 | 0 | 0 | -126 |
| 3 | 0 | 0 | 1 | 1 | -100 | -36 | 20 | 0 | 0 | -116 |
| 4 | 0 | 1 | 0 | 0 | -100 | -46 | 0 | 40 | 0 | -106 |
| 5 | 0 | 1 | 0 | 1 | -100 | -36 | 0 | 40 | 0 | -96 |
| 6 | 0 | 1 | 1 | 0 | -100 | -46 | 20 | 40 | 0 | -86 |
| 7 | 0 | 1 | 1 | 1 | -100 | -36 | 20 | 40 | 0 | -76 |
| 8 | 1 | 0 | 0 | 0 | -100 | -46 | 0 | 0 | 80 | -66 |
| 9 | 1 | 0 | 0 | 1 | -100 | -36 | 0 | 0 | 80 | -56 |
| 10 | 1 | 0 | 1 | 0 | -100 | -46 | 20 | 0 | 80 | -46 |
| 11 | 1 | 0 | 1 | 1 | -100 | -36 | 20 | 0 | 80 | -36 |
| 12 | 1 | 1 | 0 | 0 | -100 | -46 | 0 | 40 | 80 | -26 |
| 13 | 1 | 1 | 0 | 1 | -100 | -36 | 0 | 40 | 80 | -16 |
| 14 | 1 | 1 | 1 | 0 | -100 | -46 | 20 | 40 | 80 | -6 |
| 15 | 1 | 1 | 1 | 1 | -100 | -36 | 20 | 40 | 80 | 4 |

Use the \[download id="1486"\] for calculating all block offset when multiplexing four 2-position switches.

### Three 2-position and one 3-position switches

The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: | Block Number | Block Offsets | Mix Target |
|---|---|---|
| Dead | Effective | Dead |
| 0 | -150 | -149 | -148 | -143 | -142 | -141 | -146 |
| 1 | -140 | -139 | -138 | -133 | -132 | -131 | -136 |
| 2 | -130 | -129 | -128 | -123 | -122 | -121 | -126 |
| 3 | -120 | -119 | -118 | -113 | -112 | -111 | -116 |
| 4 | -110 | -109 | -108 | -103 | -102 | -101 | -106 |
| 5 | -100 | -99 | -98 | -93 | -92 | -91 | -96 |
| 6 | -90 | -89 | -88 | -83 | -82 | -81 | -86 |
| 7 | -80 | -79 | -78 | -73 | -72 | -71 | -76 |
| 8 | -70 | -69 | -68 | -63 | -62 | -61 | -66 |
| 9 | -60 | -59 | -58 | -53 | -52 | -51 | -56 |
| 10 | -50 | -49 | -48 | -43 | -42 | -41 | -46 |
| 11 | -40 | -39 | -38 | -33 | -32 | -31 | -36 |
| 12 | -30 | -29 | -28 | -23 | -22 | -21 | -26 |
| 13 | -20 | -19 | -18 | -13 | -12 | -11 | -16 |
| 14 | -10 | -9 | -8 | -3 | -2 | -1 | -6 |
| 15 | 0 | 1 | 2 | 7 | 8 | 9 | 5 |
| 16 | 10 | 11 | 12 | 17 | 18 | 19 | 15 |
| 17 | 20 | 21 | 22 | 27 | 28 | 29 | 25 |
| 18 | 30 | 31 | 32 | 37 | 38 | 39 | 35 |
| 19 | 40 | 41 | 42 | 47 | 48 | 49 | 45 |
| 20 | 50 | 51 | 52 | 57 | 58 | 59 | 55 |
| 21 | 60 | 61 | 62 | 67 | 68 | 69 | 65 |
| 22 | 70 | 71 | 72 | 77 | 78 | 79 | 75 |
| 23 | 80 | 81 | 82 | 87 | 88 | 89 | 85 |

The following mixes must be created to multiplex all switches unique configurations: | Mix info | Mix Output |
|---|---|
| Number | Switch | High | Low | Offset | 0 | 1 | 2 |
| 0 | A | 0 | 68 | 100 | 0 | -68 | -136 |
| 1 | A | -68 | 0 | -100 | -136 | -68 | 0 |
| 2 | A | -10 | -10 | 0 | -10 | 0 | 10 |
| 3 | B | 0 | -30 | 0 | 0 |  | 30 |
| 4 | C | 0 | -60 | 0 | 0 |  | 60 |
| 5 | D | 0 | -120 | 0 | 0 |  | 120 |

Note that first 3 mix are mapped to switch A which is the 3-position switch. The first 2 mix are use to get a constant -136 on all positions. Then the 3rd mix moves the signal value over the first 3 blocks (to the previous, current or next block). As far as I know, there is no way to achieve the same result with only 2 mixes.

As you can see, the sum of all combined mixes matches the middle section of each effective block: | Block Number | Switches | Mixes |
|---|---|---|
| D | C | B | A | 0 | 1 | 2 | 3 | 4 | 5 | Sum |
| 0 | 0 | 0 | 0 | 0 | 0 | -136 | -10 | 0 | 0 | 0 | -146 |
| 1 | 0 | 0 | 0 | 1 | -68 | -68 | 0 | 0 | 0 | 0 | -136 |
| 2 | 0 | 0 | 0 | 2 | -136 | 0 | 10 | 0 | 0 | 0 | -126 |
| 3 | 0 | 0 | 1 | 0 | 0 | -136 | -10 | 30 | 0 | 0 | -116 |
| 4 | 0 | 0 | 1 | 1 | -68 | -68 | 0 | 30 | 0 | 0 | -106 |
| 5 | 0 | 0 | 1 | 2 | -136 | 0 | 10 | 30 | 0 | 0 | -96 |
| 6 | 0 | 1 | 0 | 0 | 0 | -136 | -10 | 0 | 60 | 0 | -86 |
| 7 | 0 | 1 | 0 | 1 | -68 | -68 | 0 | 0 | 60 | 0 | -76 |
| 8 | 0 | 1 | 0 | 2 | -136 | 0 | 10 | 0 | 60 | 0 | -66 |
| 9 | 0 | 1 | 1 | 0 | 0 | -136 | -10 | 30 | 60 | 0 | -56 |
| 10 | 0 | 1 | 1 | 1 | -68 | -68 | 0 | 30 | 60 | 0 | -46 |
| 11 | 0 | 1 | 1 | 2 | -136 | 0 | 10 | 30 | 60 | 0 | -36 |
| 12 | 1 | 0 | 0 | 0 | 0 | -136 | -10 | 0 | 0 | 120 | -26 |
| 13 | 1 | 0 | 0 | 1 | -68 | -68 | 0 | 0 | 0 | 120 | -16 |
| 14 | 1 | 0 | 0 | 2 | -136 | 0 | 10 | 0 | 0 | 120 | -6 |
| 15 | 1 | 0 | 1 | 0 | 0 | -136 | -10 | 30 | 0 | 120 | 4 |
| 16 | 1 | 0 | 1 | 1 | -68 | -68 | 0 | 30 | 0 | 120 | 14 |
| 17 | 1 | 0 | 1 | 2 | -136 | 0 | 10 | 30 | 0 | 120 | 24 |
| 18 | 1 | 1 | 0 | 0 | 0 | -136 | -10 | 0 | 60 | 120 | 34 |
| 19 | 1 | 1 | 0 | 1 | -68 | -68 | 0 | 0 | 60 | 120 | 44 |
| 20 | 1 | 1 | 0 | 2 | -136 | 0 | 10 | 0 | 60 | 120 | 54 |
| 21 | 1 | 1 | 1 | 0 | 0 | -136 | -10 | 30 | 60 | 120 | 64 |
| 22 | 1 | 1 | 1 | 1 | -68 | -68 | 0 | 30 | 60 | 120 | 74 |
| 23 | 1 | 1 | 1 | 2 | -136 | 0 | 10 | 30 | 60 | 120 | 84 |

Use the \[download id="1482"\] for calculating all block offset when multiplexing three 2-position switches and one 3-position switch.

### Three 3-position switches

The following table shows the signal range and the middle of the effective area for each block. Again, it is calculated using a block size of 10 steps and a dead zone of 2 steps which makes the effective block size to 6 steps: | Block Number | Block Offsets | Mix Target |
|---|---|---|
| Dead | Effective | Dead |
| 0 | -134 | -133 | -132 | -127 | -126 | -125 | -130 |
| 1 | -124 | -123 | -122 | -117 | -116 | -115 | -120 |
| 2 | -114 | -113 | -112 | -107 | -106 | -105 | -110 |
| 3 | -104 | -103 | -102 | -97 | -96 | -95 | -100 |
| 4 | -94 | -93 | -92 | -87 | -86 | -85 | -90 |
| 5 | -84 | -83 | -82 | -77 | -76 | -75 | -80 |
| 6 | -74 | -73 | -72 | -67 | -66 | -65 | -70 |
| 7 | -64 | -63 | -62 | -57 | -56 | -55 | -60 |
| 8 | -54 | -53 | -52 | -47 | -46 | -45 | -50 |
| 9 | -44 | -43 | -42 | -37 | -36 | -35 | -40 |
| 10 | -34 | -33 | -32 | -27 | -26 | -25 | -30 |
| 11 | -24 | -23 | -22 | -17 | -16 | -15 | -20 |
| 12 | -14 | -13 | -12 | -7 | -6 | -5 | -10 |
| 13 | -4 | -3 | -2 | 3 | 4 | 5 | 1 |
| 14 | 6 | 7 | 8 | 13 | 14 | 15 | 11 |
| 15 | 16 | 17 | 18 | 23 | 24 | 25 | 21 |
| 16 | 26 | 27 | 28 | 33 | 34 | 35 | 31 |
| 17 | 36 | 37 | 38 | 43 | 44 | 45 | 41 |
| 18 | 46 | 47 | 48 | 53 | 54 | 55 | 51 |
| 19 | 56 | 57 | 58 | 63 | 64 | 65 | 61 |
| 20 | 66 | 67 | 68 | 73 | 74 | 75 | 71 |
| 21 | 76 | 77 | 78 | 83 | 84 | 85 | 81 |
| 22 | 86 | 87 | 88 | 93 | 94 | 95 | 91 |
| 23 | 96 | 97 | 98 | 103 | 104 | 105 | 101 |
| 24 | 106 | 107 | 108 | 113 | 114 | 115 | 111 |
| 25 | 116 | 117 | 118 | 123 | 124 | 125 | 121 |
| 26 | 126 | 127 | 128 | 133 | 134 | 135 | 131 |

The following mixes must be created to multiplex all switches unique configurations: | Mix info | Mix Output |
|---|---|
| Number | Switch | High | Low | Offset | 0 | 1 | 2 |
| 0 | A | -10 | -10 | 0 | -10 | 0 | 10 |
| 1 | B | -30 | -30 | 0 | -30 | 0 | 30 |
| 2 | C | -90 | -90 | 0 | -90 | 0 | 90 |

Note that only 3 mix is required for multiplexing three 3-position switches. Mixes are also centered around 0 (instead of starting at -150).

As you can see, the sum of all combined mixes matches the middle section of each effective block: | Block Number | Switches | Mixes |
|---|---|---|
| C | B | A | 0 | 1 | 2 | Sum |
| 0 | 0 | 0 | 0 | -10 | -30 | -90 | -130 |
| 1 | 0 | 0 | 1 | 0 | -30 | -90 | -120 |
| 2 | 0 | 0 | 2 | 10 | -30 | -90 | -110 |
| 3 | 0 | 1 | 0 | -10 | 0 | -90 | -100 |
| 4 | 0 | 1 | 1 | 0 | 0 | -90 | -90 |
| 5 | 0 | 1 | 2 | 10 | 0 | -90 | -80 |
| 6 | 0 | 2 | 0 | -10 | 30 | -90 | -70 |
| 7 | 0 | 2 | 1 | 0 | 30 | -90 | -60 |
| 8 | 0 | 2 | 2 | 10 | 30 | -90 | -50 |
| 9 | 1 | 0 | 0 | -10 | -30 | 0 | -40 |
| 10 | 1 | 0 | 1 | 0 | -30 | 0 | -30 |
| 11 | 1 | 0 | 2 | 10 | -30 | 0 | -20 |
| 12 | 1 | 1 | 0 | -10 | 0 | 0 | -10 |
| 13 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 14 | 1 | 1 | 2 | 10 | 0 | 0 | 10 |
| 15 | 1 | 2 | 0 | -10 | 30 | 0 | 20 |
| 16 | 1 | 2 | 1 | 0 | 30 | 0 | 30 |
| 17 | 1 | 2 | 2 | 10 | 30 | 0 | 40 |
| 18 | 2 | 0 | 0 | -10 | -30 | 90 | 50 |
| 19 | 2 | 0 | 1 | 0 | -30 | 90 | 60 |
| 20 | 2 | 0 | 2 | 10 | -30 | 90 | 70 |
| 21 | 2 | 1 | 0 | -10 | 0 | 90 | 80 |
| 22 | 2 | 1 | 1 | 0 | 0 | 90 | 90 |
| 23 | 2 | 1 | 2 | 10 | 0 | 90 | 100 |
| 24 | 2 | 2 | 0 | -10 | 30 | 90 | 110 |
| 25 | 2 | 2 | 1 | 0 | 30 | 90 | 120 |
| 26 | 2 | 2 | 2 | 10 | 30 | 90 | 130 |

Use the \[download id="1484"\] for calculating all block offset when multiplexing three 3-position switches.

## Decoding

Decoding the switches configuration is relatively easy: First identify the block number matching the signal's value using a sequence of "*if*" statements. Then, update switches state based on the currently selected block. Refer to tables above for offsets &amp; switches states for each selected block. Note that if you get a signal value that is within the dead zone, it probably means that you have an issue with your transmitter mixes. Verify your mixes and try again.

Since reading switches states does not imply any analog value, you do not really care if the signal value is within the effective area (or not) so clamping is not necessary beside detecting instability issue in the signal. However, in the low probability that you get a signal within a dead zone, then the first dead zone should be considered as if you read the first value of the effective area and the last dead zone as the last value of the effective area.

### Required Libraries

<span style="text-decoration: underline;"><span style="font-size: 16pt;">[PinChangeInt ](https://github.com/GreyGnome/PinChangeInt)</span></span>This library allows the arduino to attach interrupts on multiple pins. <span style="text-decoration: underline;"><span style="font-size: 16pt;">[eRCaGuy\_Timer2\_Counter ](http://www.electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html)</span></span>(optional) This library configures the arduino's timer2 to 0.5µs precision. It is used for a *micros()* function replacement and allows times calculations that are far more precise (8 times!) than the default's 4µs resolution.

### Code sample

The following arduino code (\*.ino) can be used to demultiplex the three scenarios above:

```
https://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexDiscrete.ino
```

### Sample data

\[gallery link="file" ids="1477,1479,1489"\] # Multiplexing an analog input and switches

## Design

Including an analog value (usually a rotating knob) into the multiplexed signal is also possible. However, only a single analog value can be multiplexed. Please note that including an analog value reduces the number of switches that can be multiplexed into the signal.

## Define resolution

Defining the resolution of the analog value means that you must choose the granularity of the value. By default the analog value has at least 200 different values and ranges from -100% to +100%. Since you also want to multiplex switches into the same signal, the resolution must be reduced from 200 different values to a lot less. To support a desired resolution, multiple blocks will need to be sacrificed. I do recommend a resolution of 40 steps (with values from 0 to 39) which is a nice resolution to allow enough details and can also be subdivided into other zones.

## What's different

The design for including an analog value is different than having only switches.

### Block size

Block size must be increased to allow the desired resolution. The higher the resolution, the less switches you can multiplex. The block size must be big enough to fit both dead zones and the desired resolution.

### Dead zone

A dead zone of 3 steps is also suggested. For instance, to support a resolution of 40 different steps, the block size must be of 46 steps (3+40+3=46). The following table shows the signal range and the middle of the effective area for each block. It is calculated using a block size of 46 steps and a dead zone of 3 steps which makes the effective block size to 40 steps: | Block Number | Block Offsets |
|---|---|
| Dead | Effective | Dead |
| 0 | -150 | -148 | -147 | -108 | -107 | -105 |
| 1 | -104 | -102 | -101 | -62 | -61 | -59 |
| 2 | -58 | -56 | -55 | -16 | -15 | -13 |
| 3 | -12 | -10 | -9 | 30 | 31 | 33 |
| 4 | 34 | 36 | 37 | 76 | 77 | 79 |
| 5 | 80 | 82 | 83 | 122 | 123 | 125 |

<div class="pleasenote">Note that only 6 blocks can be defined using a block size of 46 steps. These blocks only allows 2 sub configurations for multiplexing switches: - 2-position switch + 3-position switch
- Two 2-position switches

</div>## Mixes

When multiplexing an analog value, mixes do not have to target the middle of the block's effective zone (as with switches) since the signal's value can move within the whole effective area of the block. Assuming the first configuration (2-pos + 3-pos), the following mixes must be created to multiplex all switches unique configurations: | Mix info | Mix Output |
|---|---|
| Number | Switch | High | Low | Offset | 0 | 1 | 2 |
| 0 | RKnob | -74 | 0 | -99 | -147 | -73 | 0 |
| 1 | RKnob | 0 | 54 | 100 | 0 | -54 | -108 |
| 2 | A | 0 | -69 | 100 | 0 |  | 138 |
| 3 | B | 0 | -46 | 100 | 0 | 46 | 92 |

Note that first 2 mix are mapped to the right knob to reach the effective range of the first block (-147% to -108%). Switch B is a 3-position switch and offsets the analog range between block 0 to 2. Then the 3rd mix, assigned to Switch A (2-position), offsets the 3 effective block of switch B to block 0-2 or 3-5.

As you can see, the sum of all combined mixes matches the middle section of each effective block: | Block Number | Switches | Mixes |
|---|---|---|
| A | B | RKnob | 0 | 1 | 2 | 3 | Sum |
| 0 | 0 | 0 | 0 | -147 | 0 | 0 | 0 | -147 |
| 0 | 0 | 0 | 40 | 0 | -108 | 0 | 0 | -108 |
| 1 | 0 | 1 | 0 | -147 | 0 | 0 | 46 | -101 |
| 1 | 0 | 1 | 40 | 0 | -108 | 0 | 46 | -62 |
| 2 | 0 | 2 | 0 | -147 | 0 | 0 | 92 | -55 |
| 2 | 0 | 2 | 40 | 0 | -108 | 0 | 92 | -16 |
| 3 | 1 | 0 | 0 | -147 | 0 | 138 | 0 | -9 |
| 3 | 1 | 0 | 40 | 0 | -108 | 138 | 0 | 30 |
| 4 | 1 | 1 | 0 | -147 | 0 | 138 | 46 | 37 |
| 4 | 1 | 1 | 40 | 0 | -108 | 138 | 46 | 76 |
| 5 | 1 | 2 | 0 | -147 | 0 | 138 | 92 | 83 |
| 5 | 1 | 2 | 40 | 0 | -108 | 138 | 92 | 122 |

Use the \[download id="1510"\] for calculating all block offset when multiplexing an analog value with a 2-position and a 3-position switch.

## Decoding

Decoding an analog value with switches configuration is different: First identify the block number matching the signal's value using a sequence of "if" statements. Then [clamp](https://www.google.com/?q=clamp+integer+c%2B%2B) the value within the effective block area. This is required since the signal can get close to a dead zone (or even reach a dead zone!). To get the actual analog value, you must also offset the block's effective range to get a constant 0-39 range. Finally, update switches state based on the currently selected block. Refer to tables above for offsets &amp; switches states for each selected block. Note that reading a value (with the micro-controller) that is outside the analog effective area should be considered the same as reading an analog value of 0 or 39 depending on the closest dead zone.

### Code sample

The following arduino code (\*.ino) can be used to demultiplex the scenario above:

```
https://www.end2endzone.com/wp-content/uploads/2016/03/MultiplexDemultiplexAnalog.ino
```

### Sample data

\[gallery link="file" ids="1519"\]