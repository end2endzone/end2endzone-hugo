---
id: 1156
title: 'How to remove ads from HDHomeRun recordings and still encode with Handbrake'
date: '2015-10-04T16:41:01+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1156'
permalink: '/?p=1156'
hits:
    - '4789'
image: /wp-content/uploads/2015/10/Remove-ads-from-HDHomerun-recording-featured-image.jpg
categories:
    - Other
tags:
    - english
    - hdhomerun
    - tv
---

# Introduction

I record lots of TV shows using the HDHomeRun. I sometime want to keep recordings on a disk for archiving or to watch later. The following article explains how to remove ads from HDHomeRun recordings and encode the final video with Handbrake without quality loss. The whole process is executed using only FREE tools! With all TV shows comes a bunch of TV ads that I do not want to keep and waste time and disk space for. I encode all my videos using [Handbrake](https://handbrake.fr/downloads.php) because it supports quality based H264 encoding and 5.1 surround sounds but unfortunately, it does not support removing ads. Note that this process is now deprecated as I have a new workflow which does not requires an intermediate file. The new workflow is available at the following address: <https://www.end2endzone.com/best-way-to-remove-ads-from-hdhomerun-recordings-no-intermediate-file-required/>.

# What's the trick ?

The trick is to use a temporary (intermediate) file to cut ads and encode this file with a lossless video codec to prevent any quality degradation. Then use Handbrake to encode the final video for best results.

# Download &amp; Install required software

The following software must be downloaded and installed:

- [VirtualDub 1.10.4](http://www.virtualdub.org/download.html)
- [Virtualdub FFMpeg Input Plugin](http://sourceforge.net/projects/virtualdubffmpeginputplugin/files/)
- [Lagarith Lossless Video Codec v1.3.27](http://lags.leetcode.net/codec.html)
- [Handbrake 0.10.2](https://handbrake.fr/downloads.php)

# Virtualdub FFMpeg Input Plugin

By default, VirtualDub is only able to read AVI files which is not helpful because my local channels are broadcasting in MPEG2 format. For instance, Montreal's CBFT-DT is broadcasting in HDV 720p, MPEG layer 2, with two AC-3 audio channels. Full [NFO available here](/wp-content/uploads/2015/10/Montreal-CBFT-DT-Codec-NFO.nfo). This plugin allows reading files that are not AVI and works perfectly with Montreal's CBFT-DT MPEG 2 files.

# Instructions

## Open video file in Virtualdub

\[caption id="attachment\_1157" align="alignnone" width="967"\][![VirtualDub default video](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg) VirtualDub default video\[/caption\] 1. Click on *File* menu.
2. Click on *Open video file...*
3. Browse to your MPEG2 video file.

## Cut ads / video section

Virtualdub is the best video editing application I know. It support video resizing, splitting, joining, filters but mostly removing ADS! 1. Move the cursor to the first frame of an ad. Note: you can use your keyboard arrows to move 1 frame forward or backward to set the cursor at the exact desired frame.
2. Click on *Edit* menu and select *Set Selection Start* to mark the beginning of the ad. You can also press the [![VirtualDub Set Selection Start](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg) button.
3. Move the cursor to the last frame of the same ad.
4. Click on *Edit* menu and select *Set Selection End* to mark the end of the ad. You can also press the [![VirtualDub Set Selection End](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg) button.
5. This will highlight the area that will be cut out of the final video: \[caption id="attachment\_1162" align="alignnone" width="426"\][![Virtualdub Selection](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg) Virtualdub Selection\[/caption\]
6. Click on *Edit* menu and select *Delete* to remove the selection from the video. You can also press the *Delete* key on your keyboard.
7. Repeat all steps for each ads.

## Lossless video codec

You need to select an appropriate video codec for saving the temporary file. You may be aware that most video codec makes approximation and even tries to encode "movement" in the stream to maximize compression. However, they loose quality (some less than other) during each encoding. To prevent any quality loss, a lossless video codec must be selected. As it's name implies, the Lagarith video codec is lossless which means that it does not loose quality each time you re-encode a new video. \[caption id="attachment\_1163" align="alignnone" width="541"\][![Virtualdub Lagarith Lossless Video Codec Selection](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg) Virtualdub Lagarith Lossless Video Codec Selection\[/caption\] 1. Click on *Video* menu and select *Compression*...
2. Select **Lagarith Lossless Video Codec:**

## Audio codec

There is no need to use any compression codec for the audio. A typical TV show is 45 minutes long which only takes ~2.9 GiB (66 MiB / min) for 5.1 Surround sound and ~495 MiB (11 MiB / min) for Stereo sound. With today's disk space, no compression is as good as lossless compression. 1. Click on *Audio* menu and select *Full Processing Mode*.

## Save a temporary file

\[caption id="attachment\_1164" align="alignnone" width="303"\][![Virtualdub encoding](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg) Virtualdub encoding\[/caption\] 1. Click on File menu and select Save as AVI...
2. Wait for the process to complete.

## Encode final video with Handbrake

Now you got a nice TV show episode without any ads. Just open the file in Handbrake and encode using your favorite video parameters. \[caption id="attachment\_1168" align="alignnone" width="1015"\][![Handbrake video settings](https://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg) Handbrake video settings\[/caption\] # What you get

In the end, you get a perfectly encoded video without any ADS!