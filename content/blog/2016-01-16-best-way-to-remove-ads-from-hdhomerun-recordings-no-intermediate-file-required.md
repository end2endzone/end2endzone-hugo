---
title: Best way to remove ads from HDHomeRun recordings (no intermediate file required)
author: end2end
date: 2016-01-16T22:19:34+00:00
url: /best-way-to-remove-ads-from-hdhomerun-recordings-no-intermediate-file-required/
images:
  - src: /wp-content/uploads/2015/10/Remove-ads-from-HDHomerun-recording-featured-image.jpg
hits:
  - 1731
categories:
  - Other
tags:
  - english
  - hdhomerun
  - tv

---
# Introduction
This guide is a follow up to the post called 

[How to remove ads from HDHomeRun recordings and still encode with Handbrake](/how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/). I record lots of TV shows using the HDHomeRun. I sometime want to keep recordings on a disk for archiving or to watch later. The following article explains how to remove ads from HDHomeRun recordings and encode the final video with Handbrake without quality loss. The whole process is executed using only FREE tools!

With all TV shows comes a bunch of TV ads that I do not want to keep and waste time and disk space for. I encode all my videos using 

[Handbrake](https://handbrake.fr/downloads.php) because it supports quality based H264 encoding and 5.1 surround sounds but unfortunately, it does not support removing ads. 

# What's the trick ?
The trick is to use VirtualDub's frame server ability and other software to create a virtual file instead of an intermediate file as 

[my old guide](http://www.end2endzone.com/how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/)&nbsp;suggests. This option is much faster (takes 1 minute instead of hours) and uses much less disk space (2 KB instead of 8 GB) since there is no intermediate file to encode. VirtualDub is still required to cut ads as you would normally do. The process is also lossless (it does not add any quality degradation). Once the virtual file is generated (mounted), use Handbrake to encode the final video for best results. 

# Download & Install required software
The following software must be downloaded and installed: 

* [VirtualDub 1.10.4](http://www.virtualdub.org/download.html)
* [Virtualdub FFMpeg Input Plugin](http://sourceforge.net/projects/virtualdubffmpeginputplugin/files/)
* [Avisynth 2.6](http://sourceforge.net/projects/avisynth2/)
* [AVFS 1.0.0.5 - Avisynth Virtual File System](http://www.turtlewar.org/avfs/)
* [Pismo File Mount Audit Package (build 173)](http://www.pismotechnic.com/pfm/)
* [Handbrake 0.10.2](https://handbrake.fr/downloads.php)

## Register VirtualDub AVIFile handler
For the process to work, you must register the AVIFile handler on your computer. After installing VirtualDub, run the following file: 

![VirtualDub auxsetup.exe icon](/wp-content/uploads/2015/12/auxsetup-exe-icon.png)  _auxsetup.exe_. The following dialog will be displayed: 

[![VirtualDub auxsetup.exe Dialog](/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg)](/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg)

VirtualDub auxsetup.exe Dialog
Click on the 

_Install handler_ button and the following dialog will be displayed: 

[![VirtualDub Installing AVIFile frameclient](/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg)](/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg)

VirtualDub Installing AVIFile frameclient
Click on 

_OK_ button and you should get the following confirmation message: _AVIFile frameclient install successful_. 

## VirtualDub FFMpeg Input Plugin
By default, VirtualDub is only able to read AVI files which is not helpful because my local channels are broadcasting in MPEG2 format. For instance, Montreal's CBFT-DT is broadcasting in HDV 720p, MPEG layer 2, with two AC-3 audio channels. Full 

[NFO available here](/wp-content/uploads/2015/10/Montreal-CBFT-DT-Codec-NFO.nfo). This plugin allows reading files that are not AVI and works perfectly with Montreal's CBFT-DT MPEG 2 files. The installation is pretty strait forward, simply run the installer and select the location of where VirtualDub is installed. Once the process is completed, you should see the plugin available (*.vdf) within the _plugins32_ folder. 

## Avisynth
Avisynth as its name implies is an AVI file generator. The Avisynth web site describes their tool as "

_a scripting language and a collection of filters for simple (and not so simple!) non-linear video editing tasks. It frameserves video to applications_". In this scenario, Avisynth is used to parse VirtualDub's frame server reference file (*.vdr) and wrap the results as an AVI file for AVFS to use. To install, run the installer and follow the on-screen instructions. 

## Pismo File Mount Audit Package
"

_Pismo File Mount is an operating system extension that enables application controlled virtual and user mode file systems. Using Pismo File Mount, applications can expose all kinds of program and user data through the file system interface_". This software does not have any interaction with the user but it is required by AVFS to create the virtual folder containing the virtual files (\*.AVI, \*.WAV). 

[![Pismo File Mount Audit Package Install](/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg)](/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg)

Pismo File Mount Audit Package Install
To install, run 

_pfmap-173-win.exe_ and following the on-screen instructions. 

## AVFS
AVFS is the heart of the whole process. It allows the user to create a virtual file from an Avisynth script file using the 

_Pismo File Mount_ system extension. "_AVFS is a virtual file system that exposes the output of Avisynth scripts through the file system as a set of virtual media files. This allows Avisynth to feed media applications and converters that do not use the VFW API_". In this scenario, AVFS is used to create the virtual AVI file for Handbrake to use. 

### Installing version 1.0.0.5 (and previous versions)
Version 1.0.0.5 (and previous versions) are released with 

_avfs.dll_. To install, run the following commands: 

  1. Copy _avfs.dll_ to a folder of your choosing. The _c:\windows_ folder will work or use any other folder.
  2. Open a _cmd prompt_ by clicking on the _Start Menu_ and enter _cmd.exe_ and press _Enter_.
  3. Type _pfm register c:\windows\avfs.dll_. This will register _avfs.dll_ to the _Prismo File Mount_ application. To uninstall, run the following commands: 

  1. Open a _cmd prompt_ by clicking on the _Start Menu_ and enter _cmd.exe_ and press _Enter_.
  2. Type _pfm unregister c:\windows\avfs.dll_.
  3. Delete the _c:\windows\avfs.dll_ file.

### Installing version 1.0.0.6 (and previous versions)
AVSF 1.0.0.6 is not compatible with build 173 of Pismo File Mount. Build 178 must be downloaded to be able to create a virtual file. Version 1.0.0.6 (and future versions) are released with 

_avfs.exe_. To install, run the following commands: 

  1. Copy _avfs.exe_ to a folder of your choosing. The _c:\windows_ folder will work or use any other folder. To uninstall, delete the 

_c:\windows\avfs.exe_ file. 

# Instructions

## Chaining application
The basic principle in this procedure is to chain application one after the other. The output from a software becomes the input of the next and so on until the video & audio streams reaches handbrake. The process is as follows: 

MPEG2 recording  VirtualDub  Editing  VirtualDub *.vdscript file (Editing backup)&nbsp; VirtualDub frame serving (*.vdr file)  Avisynth script (*.avs)  AVSF  Virtual *.AVI file  Handbrake encoding.

## Open video file in Virtualdub

[![VirtualDub default video](/wp-content/uploads/2015/10/VirtualDub-default-video.jpg)](/wp-content/uploads/2015/10/VirtualDub-default-video.jpg)

VirtualDub default video

* Click on _File_ menu.
* Click on _Open video file..._
* Browse to your MPEG2 video file.

## Cut ads / video section
Virtualdub is the best video editing application I know. It supports video resizing, splitting, joining, filters but mostly removing ADS! 

* Move the cursor to the first frame of an ad. Note: you can use your keyboard arrows to move 1 frame forward or backward to set the cursor at the exact desired frame.
* Click on _Edit_ menu and select _Set Selection Start_ to mark the beginning of the ad. You can also press the [![VirtualDub Set Selection Start](/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg)](/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg) button.
* Move the cursor to the last frame of the same ad.
* Click on _Edit_ menu and select _Set Selection End_ to mark the end of the ad. You can also press the [![VirtualDub Set Selection End](/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg)](/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg) button.
  1. This will highlight the area that will be cut out of the final video: [![Virtualdub Selection](/wp-content/uploads/2015/10/Virtualdub-Selection.jpg)](/wp-content/uploads/2015/10/Virtualdub-Selection.jpg)
    
    Virtualdub Selection

  2. Click on _Edit_ menu and select _Delete_ to remove the selection from the video. You can also press the _Delete_ key on your keyboard.
  3. Repeat all steps for each ads.
  4. Once all ad sections are removed, save your modifications in case something happens.
  5. Click on _File_ menu and select _Save processing settings..._
  6. Save your modifications to a VirtualDub script file (*.vdscript) file

## Video codec selection
Since we are chaining application one into the other, there is no need to use video codec compression between application. Compressing frames between application will only slow down the speed at which each frames are pushed in the chain. You computer is more than capable dealing with uncompressed frames even in full HD resolution. You also reduce the risk of loosing quality between applications so leave the video compression to "

_Uncompressed RGB/YCbCr_". The final video compression will occur within Handbrake. 

[![Virtualdub Uncompressed RGB Video Codec Selection](/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png)](/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png)

Virtualdub Uncompressed RGB Video Codec Selection

* Click on _Video_ menu and select _Compression_...
* Select _Uncompressed RGB/YCbCr _

## Audio codec
There is no need to use any compression codec for the audio. A typical TV show is 45 minutes long which only takes ~2.9 GiB (66 MiB / min) for 5.1 Surround sound and ~495 MiB (11 MiB / min) for Stereo sound. Transferring this amount of data within memory should not be an issue. The final audio compression codec selection will occur within Handbrake. 

  1. Click on _Audio_ menu and select _Full Processing Mode_.

## Start VirtualDub's frame server
Now that your are done editing and removing ads from your video, you need to enable VirtualDub's frame server. 

* Click on _File_ menu.
* Select _Start frame server_...
* Enter a location for the VirtualDub AVIFile signpost (*.vdr) file. Click [here](/wp-content/uploads/2015/11/1021_20150405183000.vdr) for a sample file generated by VirtualDub. The following dialog should be displayed: 

[![VirtualDub Frameserver Options Window](/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png)](/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png)

VirtualDub Frameserver Options Window

* Leave options as is. It does not matter what you put here.
* Click on _Start_ button to start the frame server. The following dialog will be displayed: 

[![VirtualDub Frameserver Mode](/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)](/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)

VirtualDub Frameserver Mode
The frameserver is now ready to provide frames to other applications. Leave the dialog running until the encoding with handbrake is complete. Press 

_Stop serving_ button to return to VirtualDub's editing mode. A safe way to know if VirtualDub is done serving frames is to look at the "_Number of frames served_" value. If it stopped increasing, it means that Handbrake and the frameclient is done processing all frames. *** Warning:** Pressing _Stop serving_&nbsp;button while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. 

### Missing frameclients issue ?

**Note:** if you see "_Frameclients installed: AVIFile only_", you can skip this section. What ? My screenshot says "_Frameclients installed: None_". What does that means ? This message means that your system does not have a valid AVIFile handler installed. You probably missed a step in the [Register VirtualDub AVIFile handler](#Register_VirtualDub_AVIFile_handler) section. 

## AviSynth Custom Script
Now that VirtualDub is ready to server frames to the next application, you need to create an AviSynth file that will wrap the VirtualDub AVIFile signpost (*.vdr) file and generate a valid AVI stream. 

  1. Create a text file next to the VirtualDub AVIFile signpost (\*.vdr) file with the avs file extension (\*.avs). It is a good practice to use the same path & filename as the *.vdr file.
  2. Enter the following text in the file: _AviSource("full\_path\_to_vdr")_ (replace _full\_path\_to_vdr_&nbsp;by the actual full path to your vdr file).
  3. Save the file. Here is an example of a valid AviSynth Script file (*.avs): 

{{< hightlight-static-file file="/static/wp-content/uploads/2015/11/1021_20150405183000.avs" lang="cpp" >}}

## Workspace
Your workspace should contains 4 files: 

  * The original MPEG2 recording file (*.mpg)
  * The AviSynth Script file (*.avs)
  * The VirtualDub AVIFile signpost file (*.vdr)
  * The VirtualDub editing backup file (*.vdscript)

[![Remove ADS From TV Recording Workspace](/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png)](/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png)

Remove ADS From TV Recording Workspace

## Mounting
Mount the *.avs file as a virtual folder containing the virtual AVI file. 

### Using AVFS 1.0.0.5

* From the File Explorer, right click the AviSynth Script file (*.avs).
* Select the _Mount_ option.
* The following dialog will be displayed.

[![AVFS Mounting Options](/wp-content/uploads/2015/11/AVFS-Mounting-Options.png)](/wp-content/uploads/2015/11/AVFS-Mounting-Options.png)

AVFS Mounting Options

<li>
  Select your desired options. The following options is suggested: <ol>
    <li>
      Force read-only mount.
    </li>
    * Open after mount.
  </ol>
</li>

* Click the _Mount_ button. If the mounting is successful, the AviSynth Script file (*.avs) should be removed from the file system and be replaced by a folder with the same name as the file. The new folder contains multiple virtual files: 

* a copy of the AviSynth Script file (*.avs).
* an error log (error.log) containing errors found during the mount operation. If there is no error, this file contains video and audio codec properties.
* multiple audio file (*.wav, *.w64) with the same encoding. As far as I know, they are all identical.
* an uncompressed video file in the Audio Video Interleave (*.avi) format. If you selected the option 

_Open after mount_, the following window will be displayed: 

[![AVFS 375 GB Virtual AVI File](/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png)](/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png)

AVFS 375 GB Virtual AVI File

### Using AVFS 1.0.0.6
Mounting with AVFS 1.0.0.6 requires a different process. 

* Open a new [Command Prompt](http://www.google.ca/?q=open+a+command+prompt&gws_rd=ssl#).
  1. Change the current directory to the location where you installed AVFS 1.0.0.6. For example, if AVFS is installed in _F:\Apps\avfs_1.0.0.6,_ enter the following command in the prompt: _cd /d F:\Apps\avfs_1.0.0.6_
* Enter the command to mount the file. For example, if the AVS file is located in folder _G:\TV_, enter the following command in the prompt: _avfs.exe G:\TV\1021_20150405183000.avs_
* If command is executed properly, the application should display the following message: _Press CTRL+C to exit._
* Leave the application running until the file is completely encoded in Handbrake.
* Press _CTRL+C_ to stop the application properly.

[![AVFS 1.0.0.6 running](/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg)](/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg)

AVFS 1.0.0.6 running

*** Warning:** Pressing _CTRL+C_ key while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. 

## Test the virtual AVI file
Make sure that the virtual AVI file is valid. Open the AVI file with a standard video player. The file may take longer than usual to open. While the file is opening or playing, take a look at the VirtualDub Frameserver window. You should see the value of 

_Number of frames served_ increasing: 

[![VirtualDub Frameserver Mode](/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)](/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png)

VirtualDub Frameserver Mode

## Encode final video with Handbrake
The AVI file is now ready for encoding using Handbrake. Enjoy your TV show episode without any ads. Just open the file in Handbrake and encode using your favorite video parameters. 

[![Handbrake video settings](/wp-content/uploads/2015/10/Handbrake-video-settings.jpg)](/wp-content/uploads/2015/10/Handbrake-video-settings.jpg)

Handbrake video settings

# What you get
In the end, you get a perfectly encoded video without any ADS! A 1 hour recording of Montreal's CBFT-DT which is in 720p MPEG 2 format is 7.72 GB.  Removing ads from this recording and encoding with Handbrake using a quality based profile will reduce the file size to 1.20 GB.
