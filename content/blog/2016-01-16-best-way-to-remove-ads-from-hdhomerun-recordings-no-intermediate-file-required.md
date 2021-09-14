---
title: Best way to remove ads from HDHomeRun recordings (no intermediate file required)
author: end2end
type: post
date: 2016-01-16T22:19:34+00:00
url: /best-way-to-remove-ads-from-hdhomerun-recordings-no-intermediate-file-required/
featured_image: /wp-content/uploads/2015/10/Remove-ads-from-HDHomerun-recording-featured-image.jpg
hits:
  - 1731
categories:
  - Other
tags:
  - english
  - hdhomerun
  - tv

---
# <span id="Introduction">Introduction</span> This guide is a follow up to the post called 

[How to remove ads from HDHomeRun recordings and still encode with Handbrake][1]. I record lots of TV shows using the HDHomeRun. I sometime want to keep recordings on a disk for archiving or to watch later. The following article explains how to remove ads from HDHomeRun recordings and encode the final video with Handbrake without quality loss. The whole process is executed using only FREE tools!<!--more--> With all TV shows comes a bunch of TV ads that I do not want to keep and waste time and disk space for. I encode all my videos using 

[Handbrake][2] because it supports quality based H264 encoding and 5.1 surround sounds but unfortunately, it does not support removing ads. 

# <span id="What8217s_the_trick">What&#8217;s the trick ?</span> The trick is to use VirtualDub&#8217;s frame server ability and other software to create a virtual file instead of an intermediate file as 

[my old guide][3] suggests. This option is much faster (takes 1 minute instead of hours) and uses much less disk space (2 KB instead of 8 GB) since there is no intermediate file to encode. VirtualDub is still required to cut ads as you would normally do. The process is also lossless (it does not add any quality degradation). Once the virtual file is generated (mounted), use Handbrake to encode the final video for best results. 

# <span id="Download_Install_required_software">Download & Install required software</span> The following software must be downloaded and installed: 

<li style="text-align: justify;">
  <a href="http://www.virtualdub.org/download.html">VirtualDub 1.10.4</a>
</li>
<li style="text-align: justify;">
  <a href="http://sourceforge.net/projects/virtualdubffmpeginputplugin/files/">Virtualdub FFMpeg Input Plugin</a>
</li>
<li style="text-align: justify;">
  <a href="http://sourceforge.net/projects/avisynth2/">Avisynth 2.6</a>
</li>
<li style="text-align: justify;">
  <a href="http://www.turtlewar.org/avfs/">AVFS 1.0.0.5 &#8211; Avisynth Virtual File System</a>
</li>
<li style="text-align: justify;">
  <a href="http://www.pismotechnic.com/pfm/">Pismo File Mount Audit Package (build 173)</a>
</li>
<li style="text-align: justify;">
  <a href="https://handbrake.fr/downloads.php">Handbrake 0.10.2</a>
</li>

## <span id="Register_VirtualDub_AVIFile_handler">Register VirtualDub AVIFile handler</span> For the process to work, you must register the AVIFile handler on your computer. After installing VirtualDub, run the following file: 

<img loading="lazy" class="size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/12/auxsetup-exe-icon.png" alt="VirtualDub auxsetup.exe icon" width="16" height="16" />  _auxsetup.exe_. The following dialog will be displayed: 

<div id="attachment_1229" style="width: 538px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg"><img aria-describedby="caption-attachment-1229" loading="lazy" class="size-full wp-image-1229" src="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg" alt="VirtualDub auxsetup.exe Dialog" width="528" height="269" srcset="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg 528w, http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-auxsetup.exe-Dialog.jpg 300w" sizes="(max-width: 528px) 100vw, 528px" /></a>
  
  <p id="caption-attachment-1229" class="wp-caption-text">
    VirtualDub auxsetup.exe Dialog
  </p>
</div> Click on the 

_Install handler_ button and the following dialog will be displayed: 

<div id="attachment_1230" style="width: 476px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg"><img aria-describedby="caption-attachment-1230" loading="lazy" class="size-full wp-image-1230" src="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg" alt="VirtualDub Installing AVIFile frameclient" width="466" height="296" srcset="http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg 466w, http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/12/VirtualDub-Installing-AVIFile-frameclient.jpg 300w" sizes="(max-width: 466px) 100vw, 466px" /></a>
  
  <p id="caption-attachment-1230" class="wp-caption-text">
    VirtualDub Installing AVIFile frameclient
  </p>
</div> Click on 

_OK_ button and you should get the following confirmation message: _AVIFile frameclient install successful_. 

## <span id="VirtualDub_FFMpeg_Input_Plugin">VirtualDub FFMpeg Input Plugin</span> By default, VirtualDub is only able to read AVI files which is not helpful because my local channels are broadcasting in MPEG2 format. For instance, Montreal&#8217;s CBFT-DT is broadcasting in HDV 720p, MPEG layer 2, with two AC-3 audio channels. Full 

[NFO available here][4]. This plugin allows reading files that are not AVI and works perfectly with Montreal&#8217;s CBFT-DT MPEG 2 files. The installation is pretty strait forward, simply run the installer and select the location of where VirtualDub is installed. Once the process is completed, you should see the plugin available (*.vdf) within the _plugins32_ folder. 

## <span id="Avisynth">Avisynth</span> Avisynth as its name implies is an AVI file generator. The Avisynth web site describes their tool as &#8220;

_a scripting language and a collection of filters for simple (and not so simple!) non-linear video editing tasks. It frameserves video to applications_&#8220;. In this scenario, Avisynth is used to parse VirtualDub&#8217;s frame server reference file (*.vdr) and wrap the results as an AVI file for AVFS to use. To install, run the installer and follow the on-screen instructions. 

## <span id="Pismo_File_MountAudit_Package">Pismo File Mount Audit Package</span> &#8220;

_Pismo File Mount is an operating system extension that enables application controlled virtual and user mode file systems. Using Pismo File Mount, applications can expose all kinds of program and user data through the file system interface_&#8220;. This software does not have any interaction with the user but it is required by AVFS to create the virtual folder containing the virtual files (\*.AVI, \*.WAV). 

<div id="attachment_1235" style="width: 491px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg"><img aria-describedby="caption-attachment-1235" loading="lazy" class="size-full wp-image-1235" src="http://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg" alt="Pismo File Mount Audit Package Install" width="481" height="320" srcset="http://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg 481w, http://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/12/Pismo-File-Mount-Audit-Package-Install.jpg 300w" sizes="(max-width: 481px) 100vw, 481px" /></a>
  
  <p id="caption-attachment-1235" class="wp-caption-text">
    Pismo File Mount Audit Package Install
  </p>
</div> To install, run 

_pfmap-173-win.exe_ and following the on-screen instructions. 

## <span id="AVFS">AVFS</span> AVFS is the heart of the whole process. It allows the user to create a virtual file from an Avisynth script file using the 

_Pismo File Mount_ system extension. &#8220;_AVFS is a virtual file system that exposes the output of Avisynth scripts through the file system as a set of virtual media files. This allows Avisynth to feed media applications and converters that do not use the VFW API_&#8220;. In this scenario, AVFS is used to create the virtual AVI file for Handbrake to use. 

### <span id="Installing_version_1005_and_previous_versions">Installing version 1.0.0.5 (and previous versions)</span> Version 1.0.0.5 (and previous versions) are released with 

_avfs.dll_. To install, run the following commands: 

  1. Copy _avfs.dll_ to a folder of your choosing. The _c:\windows_ folder will work or use any other folder.
  2. Open a _cmd prompt_ by clicking on the _Start Menu_ and enter _cmd.exe_ and press _Enter_.
  3. Type _pfm register c:\windows\avfs.dll_. This will register _avfs.dll_ to the _Prismo File Mount_ application. To uninstall, run the following commands: 

  1. Open a _cmd prompt_ by clicking on the _Start Menu_ and enter _cmd.exe_ and press _Enter_.
  2. Type _pfm unregister c:\windows\avfs.dll_.
  3. Delete the _c:\windows\avfs.dll_ file.

### <span id="Installing_version_1006_and_previous_versions">Installing version 1.0.0.6 (and previous versions)</span> AVSF 1.0.0.6 is not compatible with build 173 of Pismo File Mount. Build 178 must be downloaded to be able to create a virtual file. Version 1.0.0.6 (and future versions) are released with 

_avfs.exe_. To install, run the following commands: 

  1. Copy _avfs.exe_ to a folder of your choosing. The _c:\windows_ folder will work or use any other folder. To uninstall, delete the 

_c:\windows\avfs.exe_ file. 

# <span id="Instructions">Instructions</span>

## <span id="Chaining_application">Chaining application</span> The basic principle in this procedure is to chain application one after the other. The output from a software becomes the input of the next and so on until the video & audio streams reaches handbrake. The process is as follows: 

<div class="sectiondiv centerdiv" style="width: 360px;">
  <p class="no_margin_no_padding">
    MPEG2 recording <i class="fa fa-arrow-right chainarrow " ></i> VirtualDub <i class="fa fa-arrow-right chainarrow " ></i> Editing <i class="fa fa-arrow-right chainarrow " ></i> VirtualDub *.vdscript file (Editing backup) <i class="fa fa-arrow-right chainarrow " ></i> VirtualDub frame serving (*.vdr file) <i class="fa fa-arrow-right chainarrow " ></i> Avisynth script (*.avs) <i class="fa fa-arrow-right chainarrow " ></i> AVSF <i class="fa fa-arrow-right chainarrow " ></i> Virtual *.AVI file <i class="fa fa-arrow-right chainarrow " ></i> Handbrake encoding.
  </p>
</div>

## <span id="Open_video_file_in_Virtualdub">Open video file in Virtualdub</span>

<div id="attachment_1157" style="width: 977px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg"><img aria-describedby="caption-attachment-1157" loading="lazy" class="wp-image-1157 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg" alt="VirtualDub default video" width="967" height="492" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg 967w, http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-default-video.jpg 672w" sizes="(max-width: 967px) 100vw, 967px" /></a>
  
  <p id="caption-attachment-1157" class="wp-caption-text">
    VirtualDub default video
  </p>
</div>

<li style="text-align: justify;">
  Click on <em>File</em> menu.
</li>
<li style="text-align: justify;">
  Click on <em>Open video file&#8230;</em>
</li>
<li style="text-align: justify;">
  Browse to your MPEG2 video file.
</li>

## <span id="Cut_ads_video_section">Cut ads / video section</span> Virtualdub is the best video editing application I know. It supports video resizing, splitting, joining, filters but mostly removing ADS! 

<li style="text-align: justify;">
  Move the cursor to the first frame of an ad. Note: you can use your keyboard arrows to move 1 frame forward or backward to set the cursor at the exact desired frame.
</li>
<li style="text-align: justify;">
  Click on <em>Edit</em> menu and select <em>Set Selection Start</em> to mark the beginning of the ad. You can also press the <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg"><img loading="lazy" class="alignnone size-full wp-image-1161" src="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-Start.jpg" alt="VirtualDub Set Selection Start" width="22" height="22" /></a> button.
</li>
<li style="text-align: justify;">
  Move the cursor to the last frame of the same ad.
</li>
<li style="text-align: justify;">
  Click on <em>Edit</em> menu and select <em>Set Selection End</em> to mark the end of the ad. You can also press the <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg"><img loading="lazy" class="alignnone size-full wp-image-1160" src="http://www.end2endzone.com/wp-content/uploads/2015/10/VirtualDub-Set-Selection-End.jpg" alt="VirtualDub Set Selection End" width="22" height="22" /></a> button.
</li>
  1. This will highlight the area that will be cut out of the final video: <div id="attachment_1162" style="width: 436px" class="wp-caption alignnone">
      <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg"><img aria-describedby="caption-attachment-1162" loading="lazy" class="size-full wp-image-1162" src="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg" alt="Virtualdub Selection" width="426" height="103" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg 426w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Selection.jpg 300w" sizes="(max-width: 426px) 100vw, 426px" /></a>
      
      <p id="caption-attachment-1162" class="wp-caption-text">
        Virtualdub Selection
      </p>
    </div>

  2. Click on _Edit_ menu and select _Delete_ to remove the selection from the video. You can also press the _Delete_ key on your keyboard.
  3. Repeat all steps for each ads.
  4. Once all ad sections are removed, save your modifications in case something happens.
  5. Click on _File_ menu and select _Save processing settings&#8230;_
  6. Save your modifications to a VirtualDub script file (*.vdscript) file

## <span id="Video_codec_selection">Video codec selection</span> Since we are chaining application one into the other, there is no need to use video codec compression between application. Compressing frames between application will only slow down the speed at which each frames are pushed in the chain. You computer is more than capable dealing with uncompressed frames even in full HD resolution. You also reduce the risk of loosing quality between applications so leave the video compression to &#8220;

_Uncompressed RGB/YCbCr_&#8220;. The final video compression will occur within Handbrake. 

<div id="attachment_1204" style="width: 551px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png"><img aria-describedby="caption-attachment-1204" loading="lazy" class="wp-image-1204 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png" alt="Virtualdub Uncompressed RGB Video Codec Selection" width="541" height="318" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png 541w, http://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/Virtualdub-Uncompressed-RGB-Video-Codec-Selection.png 300w" sizes="(max-width: 541px) 100vw, 541px" /></a>
  
  <p id="caption-attachment-1204" class="wp-caption-text">
    Virtualdub Uncompressed RGB Video Codec Selection
  </p>
</div>

<li style="text-align: justify;">
  Click on <em>Video</em> menu and select <em>Compression</em>&#8230;
</li>
<li style="text-align: justify;">
  Select <em>Uncompressed RGB/YCbCr </em>
</li>

## <span id="Audio_codec">Audio codec</span> There is no need to use any compression codec for the audio. A typical TV show is 45 minutes long which only takes ~2.9 GiB (66 MiB / min) for 5.1 Surround sound and ~495 MiB (11 MiB / min) for Stereo sound. Transferring this amount of data within memory should not be an issue. The final audio compression codec selection will occur within Handbrake. 

  1. Click on _Audio_ menu and select _Full Processing Mode_.

## <span id="Start_VirtualDub8217s_frame_server">Start VirtualDub&#8217;s frame server</span> Now that your are done editing and removing ads from your video, you need to enable VirtualDub&#8217;s frame server. 

<li style="text-align: justify;">
  Click on <em>File</em> menu.
</li>
<li style="text-align: justify;">
  Select <em>Start frame server</em>&#8230;
</li>
<li style="text-align: justify;">
  Enter a location for the VirtualDub AVIFile signpost (*.vdr) file. Click <a href="/wp-content/uploads/2015/11/1021_20150405183000.vdr">here</a> for a sample file generated by VirtualDub.
</li> The following dialog should be displayed: 

<div id="attachment_1198" style="width: 398px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png"><img aria-describedby="caption-attachment-1198" loading="lazy" class="size-full wp-image-1198" src="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png" alt="VirtualDub Frameserver Options Window" width="388" height="113" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png 388w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-options-window.png 300w" sizes="(max-width: 388px) 100vw, 388px" /></a>
  
  <p id="caption-attachment-1198" class="wp-caption-text">
    VirtualDub Frameserver Options Window
  </p>
</div>

<li style="text-align: justify;">
  Leave options as is. It does not matter what you put here.
</li>
<li style="text-align: justify;">
  Click on <em>Start</em> button to start the frame server.
</li> The following dialog will be displayed: 

<div id="attachment_1197" style="width: 404px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png"><img aria-describedby="caption-attachment-1197" loading="lazy" class="size-full wp-image-1197" src="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png" alt="VirtualDub Frameserver Mode" width="394" height="205" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 394w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 300w" sizes="(max-width: 394px) 100vw, 394px" /></a>
  
  <p id="caption-attachment-1197" class="wp-caption-text">
    VirtualDub Frameserver Mode
  </p>
</div> The frameserver is now ready to provide frames to other applications. Leave the dialog running until the encoding with handbrake is complete. Press 

_Stop serving_ button to return to VirtualDub&#8217;s editing mode. A safe way to know if VirtualDub is done serving frames is to look at the &#8220;_Number of frames served_&#8221; value. If it stopped increasing, it means that Handbrake and the frameclient is done processing all frames. *** Warning:** Pressing _Stop serving_ button while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. 

### <span id="Missing_frameclients_issue">Missing frameclients issue ?</span>

**Note:** if you see &#8220;_Frameclients installed: AVIFile only_&#8220;, you can skip this section. What ? My screenshot says &#8220;_Frameclients installed: None_&#8220;. What does that means ? This message means that your system does not have a valid AVIFile handler installed. You probably missed a step in the [Register VirtualDub AVIFile handler][5] section. 

## <span id="AviSynth_Custom_Script">AviSynth Custom Script</span> Now that VirtualDub is ready to server frames to the next application, you need to create an AviSynth file that will wrap the VirtualDub AVIFile signpost (*.vdr) file and generate a valid AVI stream. 

  1. Create a text file next to the VirtualDub AVIFile signpost (\*.vdr) file with the avs file extension (\*.avs). It is a good practice to use the same path & filename as the *.vdr file.
  2. Enter the following text in the file: _AviSource(&#8220;full\_path\_to_vdr&#8221;)_ (replace _full\_path\_to_vdr_ by the actual full path to your vdr file).
  3. Save the file. Here is an example of a valid AviSynth Script file (*.avs): 

<pre class="lang:c++ decode:true" title="A valid AviSynth Script file" data-url="/wp-content/uploads/2015/11/1021_20150405183000.avs"></pre>

## <span id="Workspace">Workspace</span> Your workspace should contains 4 files: 

  * The original MPEG2 recording file (*.mpg)
  * The AviSynth Script file (*.avs)
  * The VirtualDub AVIFile signpost file (*.vdr)
  * The VirtualDub editing backup file (*.vdscript)

<div id="attachment_1196" style="width: 618px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png"><img aria-describedby="caption-attachment-1196" loading="lazy" class="size-full wp-image-1196" src="http://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png" alt="Remove ADS From TV Recording Workspace" width="608" height="396" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png 608w, http://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/Remove-ADS-From-TV-Recording-Workspace.png 300w" sizes="(max-width: 608px) 100vw, 608px" /></a>
  
  <p id="caption-attachment-1196" class="wp-caption-text">
    Remove ADS From TV Recording Workspace
  </p>
</div>

## <span id="Mounting">Mounting</span> Mount the *.avs file as a virtual folder containing the virtual AVI file. 

### <span id="Using_AVFS_1005">Using AVFS 1.0.0.5</span>

<li style="text-align: justify;">
  From the File Explorer, right click the AviSynth Script file (*.avs).
</li>
<li style="text-align: justify;">
  Select the <em>Mount</em> option.
</li>
<li style="text-align: justify;">
  The following dialog will be displayed.
</li>

<div id="attachment_1195" style="width: 401px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png"><img aria-describedby="caption-attachment-1195" loading="lazy" class="wp-image-1195 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png" alt="AVFS Mounting Options" width="391" height="422" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png 391w, http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png 139w, http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-Mounting-Options.png 278w" sizes="(max-width: 391px) 100vw, 391px" /></a>
  
  <p id="caption-attachment-1195" class="wp-caption-text">
    AVFS Mounting Options
  </p>
</div>

<li style="text-align: justify;">
  Select your desired options. The following options is suggested: <ol>
    <li style="text-align: justify;">
      Force read-only mount.
    </li>
    <li style="text-align: justify;">
      Open after mount.
    </li>
  </ol>
</li>

<li style="text-align: justify;">
  Click the <em>Mount</em> button.
</li> If the mounting is successful, the AviSynth Script file (*.avs) should be removed from the file system and be replaced by a folder with the same name as the file. The new folder contains multiple virtual files: 

<li style="text-align: justify;">
  a copy of the AviSynth Script file (*.avs).
</li>
<li style="text-align: justify;">
  an error log (error.log) containing errors found during the mount operation. If there is no error, this file contains video and audio codec properties.
</li>
<li style="text-align: justify;">
  multiple audio file (*.wav, *.w64) with the same encoding. As far as I know, they are all identical.
</li>
<li style="text-align: justify;">
  an uncompressed video file in the Audio Video Interleave (*.avi) format.
</li> If you selected the option 

_Open after mount_, the following window will be displayed: 

<div id="attachment_1194" style="width: 618px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png"><img aria-describedby="caption-attachment-1194" loading="lazy" class="wp-image-1194 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png" alt="AVFS 375 GB Virtual AVI File" width="608" height="396" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png 608w, http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/AVFS-375-GB-Virtual-AVI-File.png 300w" sizes="(max-width: 608px) 100vw, 608px" /></a>
  
  <p id="caption-attachment-1194" class="wp-caption-text">
    AVFS 375 GB Virtual AVI File
  </p>
</div>

### <span id="Using_AVFS_1006">Using AVFS 1.0.0.6</span> Mounting with AVFS 1.0.0.6 requires a different process. 

<li style="text-align: justify;">
  Open a new <a href="http://www.google.ca/?q=open+a+command+prompt&gws_rd=ssl#">Command Prompt</a>.
</li>
  1. Change the current directory to the location where you installed AVFS 1.0.0.6. For example, if AVFS is installed in _F:\Apps\avfs_1.0.0.6,_ enter the following command in the prompt: _cd /d F:\Apps\avfs_1.0.0.6_
<li style="text-align: justify;">
  Enter the command to mount the file. For example, if the AVS file is located in folder <em>G:\TV</em>, enter the following command in the prompt: <em>avfs.exe G:\TV\1021_20150405183000.avs</em>
</li>
<li style="text-align: justify;">
  If command is executed properly, the application should display the following message: <em>Press CTRL+C to exit.</em>
</li>
<li style="text-align: justify;">
  Leave the application running until the file is completely encoded in Handbrake.
</li>
<li style="text-align: justify;">
  Press <em>CTRL+C</em> to stop the application properly.
</li>

<div id="attachment_1238" style="width: 607px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg"><img aria-describedby="caption-attachment-1238" loading="lazy" class="size-full wp-image-1238" src="http://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg" alt="AVFS 1.0.0.6 running" width="597" height="299" srcset="http://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg 597w, http://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/12/AVFS-1.0.0.6-running.jpg 300w" sizes="(max-width: 597px) 100vw, 597px" /></a>
  
  <p id="caption-attachment-1238" class="wp-caption-text">
    AVFS 1.0.0.6 running
  </p>
</div>

*** Warning:** Pressing _CTRL+C_ key while the frame server is serving frames to Handbrake might corrupt your output (compressed) video. 

## <span id="Test_the_virtual_AVI_file">Test the virtual AVI file</span> Make sure that the virtual AVI file is valid. Open the AVI file with a standard video player. The file may take longer than usual to open. While the file is opening or playing, take a look at the VirtualDub Frameserver window. You should see the value of 

_Number of frames served_ increasing: 

<div id="attachment_1197" style="width: 404px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png"><img aria-describedby="caption-attachment-1197" loading="lazy" class="size-full wp-image-1197" src="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png" alt="VirtualDub Frameserver Mode" width="394" height="205" srcset="http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 394w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/11/VirtualDub-frameserver-mode.png 300w" sizes="(max-width: 394px) 100vw, 394px" /></a>
  
  <p id="caption-attachment-1197" class="wp-caption-text">
    VirtualDub Frameserver Mode
  </p>
</div>

## <span id="Encode_final_video_with_Handbrake">Encode final video with Handbrake</span> The AVI file is now ready for encoding using Handbrake. Enjoy your TV show episode without any ads. Just open the file in Handbrake and encode using your favorite video parameters. 

<div id="attachment_1168" style="width: 1025px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg"><img aria-describedby="caption-attachment-1168" loading="lazy" class="wp-image-1168 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg" alt="Handbrake video settings" width="1015" height="675" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 1015w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 672w" sizes="(max-width: 1015px) 100vw, 1015px" /></a>
  
  <p id="caption-attachment-1168" class="wp-caption-text">
    Handbrake video settings
  </p>
</div>

# <span id="What_you_get">What you get</span> In the end, you get a perfectly encoded video without any ADS! A 1 hour recording of Montreal&#8217;s CBFT-DT which is in 720p MPEG 2 format is 7.72 GB.  Removing ads from this recording and encoding with Handbrake using a quality based profile will reduce the file size to 1.20 GB.

 [1]: /how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/
 [2]: https://handbrake.fr/downloads.php
 [3]: http://www.end2endzone.com/how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/
 [4]: /wp-content/uploads/2015/10/Montreal-CBFT-DT-Codec-NFO.nfo
 [5]: #Register_VirtualDub_AVIFile_handler