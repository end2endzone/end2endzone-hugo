---
title: How to remove ads from HDHomeRun recordings and still encode with Handbrake
author: end2end
type: post
date: 2015-10-04T20:41:01+00:00
url: /how-to-remove-ads-from-hdhomerun-recordings-and-still-encode-with-handbrake/
featured_image: /wp-content/uploads/2015/10/Remove-ads-from-HDHomerun-recording-featured-image.jpg
hits:
  - 3885
categories:
  - Other
tags:
  - english
  - hdhomerun
  - tv

---
# <span id="Introduction">Introduction</span>

I record lots of TV shows using the HDHomeRun. I sometime want to keep recordings on a disk for archiving or to watch later. The following article explains how to remove ads from HDHomeRun recordings and encode the final video with Handbrake without quality loss. The whole process is executed using only FREE tools!<!--more-->

With all TV shows comes a bunch of TV ads that I do not want to keep and waste time and disk space for. I encode all my videos using [Handbrake][1] because it supports quality based H264 encoding and 5.1 surround sounds but unfortunately, it does not support removing ads.

<p class="postedit">
  Note that this process is now deprecated as I have a new workflow which does not requires an intermediate file. The new workflow is available at the following address: <a href="http://www.end2endzone.com/best-way-to-remove-ads-from-hdhomerun-recordings-no-intermediate-file-required/">http://www.end2endzone.com/best-way-to-remove-ads-from-hdhomerun-recordings-no-intermediate-file-required/</a>.
</p>

# <span id="What8217s_the_trick">What&#8217;s the trick ?</span>

The trick is to use a temporary (intermediate) file to cut ads and encode this file with a lossless video codec to prevent any quality degradation. Then use Handbrake to encode the final video for best results.

# <span id="Download_Install_required_software">Download & Install required software</span>

The following software must be downloaded and installed:

<li style="text-align: justify;">
  <a href="http://www.virtualdub.org/download.html">VirtualDub 1.10.4</a>
</li>
<li style="text-align: justify;">
  <a href="http://sourceforge.net/projects/virtualdubffmpeginputplugin/files/">Virtualdub FFMpeg Input Plugin</a>
</li>
<li style="text-align: justify;">
  <a href="http://lags.leetcode.net/codec.html">Lagarith Lossless Video Codec v1.3.27</a>
</li>
<li style="text-align: justify;">
  <a href="https://handbrake.fr/downloads.php">Handbrake 0.10.2</a>
</li>

# <span id="Virtualdub_FFMpeg_Input_Plugin">Virtualdub FFMpeg Input Plugin</span>

By default, VirtualDub is only able to read AVI files which is not helpful because my local channels are broadcasting in MPEG2 format. For instance, Montreal&#8217;s CBFT-DT is broadcasting in HDV 720p, MPEG layer 2, with two AC-3 audio channels. Full [NFO available here][2].

This plugin allows reading files that are not AVI and works perfectly with Montreal&#8217;s CBFT-DT MPEG 2 files.

# <span id="Instructions">Instructions</span>

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

## <span id="Cut_ads_video_section">Cut ads / video section</span>

Virtualdub is the best video editing application I know. It support video resizing, splitting, joining, filters but mostly removing ADS!

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

## <span id="Lossless_video_codec">Lossless video codec</span>

You need to select an appropriate video codec for saving the temporary file. You may be aware that most video codec makes approximation and even tries to encode &#8220;movement&#8221; in the stream to maximize compression. However, they loose quality (some less than other) during each encoding. To prevent any quality loss, a lossless video codec must be selected. As it&#8217;s name implies, the Lagarith video codec is lossless which means that it does not loose quality each time you re-encode a new video.

<div id="attachment_1163" style="width: 551px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg"><img aria-describedby="caption-attachment-1163" loading="lazy" class="wp-image-1163 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg" alt="Virtualdub Lagarith Lossless Video Codec Selection" width="541" height="318" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg 541w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-Video-Codec-Selection.jpg 300w" sizes="(max-width: 541px) 100vw, 541px" /></a>
  
  <p id="caption-attachment-1163" class="wp-caption-text">
    Virtualdub Lagarith Lossless Video Codec Selection
  </p>
</div>

<li style="text-align: justify;">
  Click on <em>Video</em> menu and select <em>Compression</em>&#8230;
</li>
<li style="text-align: justify;">
  Select <em><em>Lagarith Lossless Video Codec:<br /> </em></em>
</li>

## <span id="Audio_codec">Audio codec</span>

There is no need to use any compression codec for the audio. A typical TV show is 45 minutes long which only takes ~2.9 GiB (66 MiB / min) for 5.1 Surround sound and ~495 MiB (11 MiB / min) for Stereo sound. With today&#8217;s disk space, no compression is as good as lossless compression.

  1. Click on _Audio_ menu and select _Full Processing Mode_.

## <span id="Save_a_temporary_file">Save a temporary file</span>

<div id="attachment_1164" style="width: 313px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg"><img aria-describedby="caption-attachment-1164" loading="lazy" class="size-full wp-image-1164" src="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg" alt="Virtualdub encoding" width="303" height="368" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg 303w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg 124w, http://www.end2endzone.com/wp-content/uploads/2015/10/Virtualdub-encoding.jpg 247w" sizes="(max-width: 303px) 100vw, 303px" /></a>
  
  <p id="caption-attachment-1164" class="wp-caption-text">
    Virtualdub encoding
  </p>
</div>

<li style="text-align: justify;">
  Click on File menu and select Save as AVI&#8230;
</li>
<li style="text-align: justify;">
  Wait for the process to complete.
</li>

## <span id="Encode_final_video_with_Handbrake">Encode final video with Handbrake</span>

Now you got a nice TV show episode without any ads. Just open the file in Handbrake and encode using your favorite video parameters.

<div id="attachment_1168" style="width: 1025px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg"><img aria-describedby="caption-attachment-1168" loading="lazy" class="wp-image-1168 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg" alt="Handbrake video settings" width="1015" height="675" srcset="http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 1015w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2015/10/Handbrake-video-settings.jpg 672w" sizes="(max-width: 1015px) 100vw, 1015px" /></a>
  
  <p id="caption-attachment-1168" class="wp-caption-text">
    Handbrake video settings
  </p>
</div>

# <span id="What_you_get">What you get</span>

In the end, you get a perfectly encoded video without any ADS!

 [1]: https://handbrake.fr/downloads.php
 [2]: /wp-content/uploads/2015/10/Montreal-CBFT-DT-Codec-NFO.nfo