---
id: 1185
title: 'Best way to remove ads from HDHomeRun recordings (no intermediate file required)'
date: '2016-01-16T17:19:34+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=1185'
permalink: '/?p=1185'
hits:
    - '2130'
image: /wp-content/uploads/2015/10/Remove-ads-from-HDHomerun-recording-featured-image.jpg
categories:
    - Other
tags:
    - english
    - hdhomerun
    - tv
---

# Introduction

This guide is a follow up to the post called [How to remove ads from HDHomeRun recordings and still encode with Handbrake](/how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/). I record lots of TV shows using the HDHomeRun. I sometime want to keep recordings on a disk for archiving or to watch later. The following article explains how to remove ads from HDHomeRun recordings and encode the final video with Handbrake without quality loss. The whole process is executed using only FREE tools! With all TV shows comes a bunch of TV ads that I do not want to keep and waste time and disk space for. I encode all my videos using [Handbrake](https://handbrake.fr/downloads.php) because it supports quality based H264 encoding and 5.1 surround sounds but unfortunately, it does not support removing ads. # What's the trick ?

The trick is to use VirtualDub's frame server ability and other software to create a virtual file instead of an intermediate file as [my old guide](https://www.end2endzone.com/how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/) suggests. This option is much faster (takes 1 minute instead of hours) and uses much less disk space (2 KB instead of 8 GB) since there is no intermediate file to encode. VirtualDub is still required to cut ads as you would normally do. The process is also lossless (it does not add any quality degradation). Once the virtual file is generated (mounted), use Handbrake to encode the final video for best results. # Download &amp; Install required software

The following software must be downloaded and installed: - [VirtualDub 1.10.4](http://www.virtualdub.org/download.html)
- [Virtualdub FFMpeg Input Plugin](http://sourceforge.net/projects/virtualdubffmpeginputplugin/files/)
- [Avisynth 2.6](http://sourceforge.net/projects/avisynth2/)
- [AVFS 1.0.0.5 - Avisynth Virtual File System](http://www.turtlewar.org/avfs/)
- [Pismo File Mount Audit Package (build 173)](http://www.pismotechnic.com/pfm/)
- [Handbrake 0.10.2](https://handbrake.fr/downloads.php)

## Register VirtualDub AVIFile handler

For the process to work, you must register the AVIFile handler on your computer. After installing VirtualDub, run the following file: ![VirtualDub auxsetup.exe icon](https://www.end2endzone.com/wp-content/uploads/2015/12/auxsetup-exe-icon.png) *auxsetup.exe*. The following dialog will be displayed: \[caption id="attachment\_1229" align="alignnone" width="528"\][![VirtualDub auxsetup.exe Dialog](https://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg) VirtualDub auxsetup.exe Dialog\[/caption\] Click on the *Install handler* button and the following dialog will be displayed: \[caption id="attachment\_1230" align="alignnone" width="466"\][![VirtualDub Installing AVIFile frameclient](https://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg) VirtualDub Installing AVIFile frameclient\[/caption\] Click on *OK* button and you should get the following confirmation message: *AVIFile frameclient install successful*. ## VirtualDub FFMpeg Input Plugin

By default, VirtualDub is only able to read AVI files which is not helpful because my local channels are broadcasting in MPEG2 format. For instance, Montreal's CBFT-DT is broadcasting in HDV 720p, MPEG layer 2, with two AC-3 audio channels. Full [NFO available here](/wp-content/uploads/2015/10/Montreal-CBFT-DT-Codec-NFO.nfo). This plugin allows reading files that are not AVI and works perfectly with Montreal's CBFT-DT MPEG 2 files. The installation is pretty strait forward, simply run the installer and select the location of where VirtualDub is installed. Once the process is completed, you should see the plugin available (\*.vdf) within the *plugins32* folder. ## Avisynth

Avisynth as its name implies is an AVI file generator. The Avisynth web site describes their tool as "*a scripting language and a collection of filters for simple (and not so simple!) non-linear video editing tasks. It frameserves video to applications*". In this scenario, Avisynth is used to parse VirtualDub's frame server reference file (\*.vdr) and wrap the results as an AVI file for AVFS to use. To install, run the installer and follow the on-screen instructions. ## Pismo File Mount Audit Package

"*Pismo File Mount is an operating system extension that enables application controlled virtual and user mode file systems. Using Pismo File Mount, applications can expose all kinds of program and user data through the file system interface*". This software does not have any interaction with the user but it is required by AVFS to create the virtual folder containing the virtual files (\*.AVI, \*.WAV). \[caption id="attachment\_1235" align="alignnone" width="481"\][![Pismo File Mount Audit Package Install](https://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg) Pismo File Mount Audit Package Install\[/caption\] To install, run *pfmap-173-win.exe* and following the on-screen instructions. ## AVFS

AVFS is the heart of the whole process. It allows the user to create a virtual file from an Avisynth script file using the *Pismo File Mount* system extension. "*AVFS is a virtual file system that exposes the output of Avisynth scripts through the file system as a set of virtual media files. This allows Avisynth to feed media applications and converters that do not use the VFW API*". In this scenario, AVFS is used to create the virtual AVI file for Handbrake to use. ### Installing version 1.0.0.5 (and previous versions)

Version 1.0.0.5 (and previous versions) are released with *avfs.dll*. To install, run the following commands: 1. Copy *avfs.dll* to a folder of your choosing. The *c:\\windows* folder will work or use any other folder.
2. Open a *cmd prompt* by clicking on the *Start Menu* and enter *cmd.exe* and press *Enter*.
3. Type *pfm register c:\\windows\\avfs.dll*. This will register *avfs.dll* to the *Prismo File Mount* application.

To uninstall, run the following commands: 1. Open a *cmd prompt* by clicking on the *Start Menu* and enter *cmd.exe* and press *Enter*.
2. Type *pfm unregister c:\\windows\\avfs.dll*.
3. Delete the *c:\\windows\\avfs.dll* file.

### Installing version 1.0.0.6 (and previous versions)

AVSF 1.0.0.6 is not compatible with build 173 of Pismo File Mount. Build 178 must be downloaded to be able to create a virtual file. Version 1.0.0.6 (and future versions) are released with *avfs.exe*. To install, run the following commands: 1. Copy *avfs.exe* to a folder of your choosing. The *c:\\windows* folder will work or use any other folder.

To uninstall, delete the *c:\\windows\\avfs.exe* file. # Instructions

## Chaining application

The basic principle in this procedure is to chain application one after the other. The output from a software becomes the input of the next and so on until the video &amp; audio streams reaches handbrake. The process is as follows: <div class="sectiondiv centerdiv" style="width: 360px;">MPEG2 recording \[icon name="arrow-right" unprefixed\_class="chainarrow"\] VirtualDub \[icon name="arrow-right" unprefixed\_class="chainarrow"\] Editing \[icon name="arrow-right" unprefixed\_class="chainarrow"\] VirtualDub \*.vdscript file (Editing backup) \[icon name="arrow-right" unprefixed\_class="chainarrow"\] VirtualDub frame serving (\*.vdr file) \[icon name="arrow-right" unprefixed\_class="chainarrow"\] Avisynth script (\*.avs) \[icon name="arrow-right" unprefixed\_class="chainarrow"\] AVSF \[icon name="arrow-right" unprefixed\_class="chainarrow"\] Virtual \*.AVI file \[icon name="arrow-right" unprefixed\_class="chainarrow"\] Handbrake encoding.

</div>## Open video file in Virtualdub

\[caption id="attachment\_1157" align="alignnone" width="967"\][![VirtualDub default video](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg) VirtualDub default video\[/caption\] 1. Click on *File* menu.
2. Click on *Open video file...*
3. Browse to your MPEG2 video file.

## Cut ads / video section

Virtualdub is the best video editing application I know. It supports video resizing, splitting, joining, filters but mostly removing ADS! 1. Move the cursor to the first frame of an ad. Note: you can use your keyboard arrows to move 1 frame forward or backward to set the cursor at the exact desired frame.
2. Click on *Edit* menu and select *Set Selection Start* to mark the beginning of the ad. You can also press the [![VirtualDub Set Selection Start](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg) button.
3. Move the cursor to the last frame of the same ad.
4. Click on *Edit* menu and select *Set Selection End* to mark the end of the ad. You can also press the [![VirtualDub Set Selection End](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg) button.
5. This will highlight the area that will be cut out of the final video: \[caption id="attachment\_1162" align="alignnone" width="426"\][![Virtualdub Selection](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg) Virtualdub Selection\[/caption\]
6. Click on *Edit* menu and select *Delete* to remove the selection from the video. You can also press the *Delete* key on your keyboard.
7. Repeat all steps for each ads.
8. Once all ad sections are removed, save your modifications in case something happens.
9. Click on *File* menu and select *Save processing settings...*
10. Save your modifications to a VirtualDub script file (\*.vdscript) file

## Video codec selection

Since we are chaining application one into the other, there is no need to use video codec compression between application. Compressing frames between application will only slow down the speed at which each frames are pushed in the chain. You computer is more than capable dealing with uncompressed frames even in full HD resolution. You also reduce the risk of loosing quality between applications so leave the video compression to "*Uncompressed RGB/YCbCr*". The final video compression will occur within Handbrake. \[caption id="attachment\_1204" align="alignnone" width="541"\][![Virtualdub Uncompressed RGB Video Codec Selection](https://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png) Virtualdub Uncompressed RGB Video Codec Selection\[/caption\] 1. Click on *Video* menu and select *Compression*...
2. Select *Uncompressed RGB/YCbCr*

## Audio codec

There is no need to use any compression codec for the audio. A typical TV show is 45 minutes long which only takes ~2.9 GiB (66 MiB / min) for 5.1 Surround sound and ~495 MiB (11 MiB / min) for Stereo sound. Transferring this amount of data within memory should not be an issue. The final audio compression codec selection will occur within Handbrake. 1. Click on *Audio* menu and select *Full Processing Mode*.

## Start VirtualDub's frame server

Now that your are done editing and removing ads from your video, you need to enable VirtualDub's frame server. 1. Click on *File* menu.
2. Select *Start frame server*...
3. Enter a location for the VirtualDub AVIFile signpost (\*.vdr) file. Click [here](/wp-content/uploads/2015/11/1021_20150405183000.vdr) for a sample file generated by VirtualDub.

The following dialog should be displayed: \[caption id="attachment\_1198" align="alignnone" width="388"\][![VirtualDub Frameserver Options Window](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png) VirtualDub Frameserver Options Window\[/caption\] 1. Leave options as is. It does not matter what you put here.
2. Click on *Start* button to start the frame server.

The following dialog will be displayed: \[caption id="attachment\_1197" align="alignnone" width="394"\][![VirtualDub Frameserver Mode](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png) VirtualDub Frameserver Mode\[/caption\] The frameserver is now ready to provide frames to other applications. Leave the dialog running until the encoding with handbrake is complete. Press *Stop serving* button to return to VirtualDub's editing mode. A safe way to know if VirtualDub is done serving frames is to look at the "*Number of frames served*" value. If it stopped increasing, it means that Handbrake and the frameclient is done processing all frames. **\* Warning:**Pressing *Stop serving* button while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. ### Missing frameclients issue ?

**Note:** if you see "*Frameclients installed: AVIFile only*", you can skip this section. What ? My screenshot says "*Frameclients installed: None*". What does that means ? This message means that your system does not have a valid AVIFile handler installed. You probably missed a step in the [Register VirtualDub AVIFile handler](#Register_VirtualDub_AVIFile_handler) section. ## AviSynth Custom Script

Now that VirtualDub is ready to server frames to the next application, you need to create an AviSynth file that will wrap the VirtualDub AVIFile signpost (\*.vdr) file and generate a valid AVI stream. 1. Create a text file next to the VirtualDub AVIFile signpost (\*.vdr) file with the avs file extension (\*.avs). It is a good practice to use the same path &amp; filename as the \*.vdr file.
2. Enter the following text in the file: *AviSource("full\_path\_to\_vdr")* (replace *full\_path\_to\_vdr* by the actual full path to your vdr file).
3. Save the file.

Here is an example of a valid AviSynth Script file (\*.avs): ```
```

## Workspace

Your workspace should contains 4 files: - The original MPEG2 recording file (\*.mpg)
- The AviSynth Script file (\*.avs)
- The VirtualDub AVIFile signpost file (\*.vdr)
- The VirtualDub editing backup file (\*.vdscript)

\[caption id="attachment\_1196" align="alignnone" width="608"\][![Remove ADS From TV Recording Workspace](https://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png) Remove ADS From TV Recording Workspace\[/caption\] ## Mounting

Mount the \*.avs file as a virtual folder containing the virtual AVI file. ### Using AVFS 1.0.0.5

1. From the File Explorer, right click the AviSynth Script file (\*.avs).
2. Select the *Mount* option.
3. The following dialog will be displayed.

\[caption id="attachment\_1195" align="alignnone" width="391"\][![AVFS Mounting Options](https://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png) AVFS Mounting Options\[/caption\] 1. Select your desired options. The following options is suggested: 
    1. Force read-only mount.
    2. Open after mount.
2. Click the *Mount* button.

If the mounting is successful, the AviSynth Script file (\*.avs) should be removed from the file system and be replaced by a folder with the same name as the file. The new folder contains multiple virtual files: - a copy of the AviSynth Script file (\*.avs).
- an error log (error.log) containing errors found during the mount operation. If there is no error, this file contains video and audio codec properties.
- multiple audio file (\*.wav, \*.w64) with the same encoding. As far as I know, they are all identical.
- an uncompressed video file in the Audio Video Interleave (\*.avi) format.

If you selected the option *Open after mount*, the following window will be displayed: \[caption id="attachment\_1194" align="alignnone" width="608"\][![AVFS 375 GB Virtual AVI File](https://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png) AVFS 375 GB Virtual AVI File\[/caption\] ### Using AVFS 1.0.0.6

Mounting with AVFS 1.0.0.6 requires a different process. 1. Open a new [Command Prompt](http://www.google.ca/?q=open+a+command+prompt&gws_rd=ssl#).
2. Change the current directory to the location where you installed AVFS 1.0.0.6. For example, if AVFS is installed in *F:\\Apps\\avfs\_1.0.0.6,* enter the following command in the prompt: *cd /d F:\\Apps\\avfs\_1.0.0.6*
3. Enter the command to mount the file. For example, if the AVS file is located in folder *G:\\TV*, enter the following command in the prompt: *avfs.exe G:\\TV\\1021\_20150405183000.avs*
4. If command is executed properly, the application should display the following message: *Press CTRL+C to exit.*
5. Leave the application running until the file is completely encoded in Handbrake.
6. Press *CTRL+C* to stop the application properly.

\[caption id="attachment\_1238" align="alignnone" width="597"\][![AVFS 1.0.0.6 running](https://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg) AVFS 1.0.0.6 running\[/caption\] **\* Warning:**Pressing *CTRL+C* key while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. ## Test the virtual AVI file

Make sure that the virtual AVI file is valid. Open the AVI file with a standard video player. The file may take longer than usual to open. While the file is opening or playing, take a look at the VirtualDub Frameserver window. You should see the value of *Number of frames served* increasing: \[caption id="attachment\_1197" align="alignnone" width="394"\][![VirtualDub Frameserver Mode](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)](https://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png) VirtualDub Frameserver Mode\[/caption\] ## Encode final video with Handbrake

The AVI file is now ready for encoding using Handbrake. Enjoy your TV show episode without any ads. Just open the file in Handbrake and encode using your favorite video parameters. \[caption id="attachment\_1168" align="alignnone" width="1015"\][![Handbrake video settings](https://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg)](https://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg) Handbrake video settings\[/caption\] # What you get

In the end, you get a perfectly encoded video without any ADS! A 1 hour recording of Montreal's CBFT-DT which is in 720p MPEG 2 format is 7.72 GB. Removing ads from this recording and encoding with Handbrake using a quality based profile will reduce the file size to 1.20 GB.