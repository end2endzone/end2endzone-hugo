---
title: How to make a time-lapse video with free tools and a DSLR camera
author: end2end
date: 2015-03-15T19:50:02+00:00
url: /how-to-make-a-time-lapse-video-with-free-tools-and-a-dslr-camera/
images:
  - src: /wp-content/uploads/2015/02/How-to-make-a-time-lapse-video-with-free-tools-and-a-DSLR-camera.jpg
hits:
  - 2694
categories:
  - Photography
tags:
  - english
  - gimp
  - time lapse
  - VirtualDub
  - Windows movie maker

---

# Introduction

[Time-lapse photography](http://en.wikipedia.org/wiki/time-lapse_photography) is a wonderful effect to make your images alive instead of static because you can make a plain (or almost boring) event and make it so much more dramatic. However, it is something that usually needs a lot of time investment to get something acceptable. Considering my family was planning to decorate the Christmas tree during the weekend, I decided to take my camera and capture the whole event in a time-lapse video. To get a nice video, you need to prepare yourself before taking the shots because if you don’t, you can end up with a bad picture set and have a hard time merging all pictures together. The following article will explains how I managed to make a nice time-lapse video with a DSLR using only free software. Click here to jump to the [Final Results](#Final_results) section and see the video.

# Prepare you gears

## Mandatory gears for time-lapse videos

### Tripod

This one is obvious. You need a tripod to make sure that all images are aligned the same directions. The field of view must be identical for all captured images. You do not want to see the background of the event moving during the video but only your subject.

### Intervalometer

An intervalometer is a remote trigger with the added capacity to trigger the camera shutter at regular intervals. It is mandatory if you want to do time-lapse image capturing. It is not used to reduce camera shake since the photographer does not take any actions on the camera during the capturing process.

## Useful stuff

### Calculator

A calculator is useful if you go out in the field for your capturing session. For most time-lapse projects related to capturing the nature, it would be wise to bring a camera with you for calculating the perfect interval for your desired effect. See the section [*Calculating the best interval*](#Calculating_the_bestinterval) for details.

## Tools you won’t need

### Flashes

If you think you may need a flash for taking your shots, you might have to reconsider your project. If your intervals are too short (the elapsed time between each photos), the flash might not have the time to recharge between each shots. If your intervals are long enough to have your flash recharged, it means that the subject could be positioned differently in the scene resulting in great highlight changes which is really hard to correct in post-production. Another issue that the flash might cause is flickering. If your scene is not well lighted, there is a high chance that you end up with lots of flickering during the [merging phase](#Combining_photos_into_a_movie). The exposition will vary a lot between each shots and that would not be pleasant to watch. Some plugins can help to reduce flickering but it is always better to think about this in pre-production than dealing with it in post-production. I am unable to think of a suitable scenario where a flash would be required that also requires long intervals like 5 minutes or more.

# Check your calculations

Don't go out and try to shot anything as quickly as possible. I recommend that you take the time to think and evaluate what is the best interval (time between each photos) for your needs. Is it going to be seconds, minutes or even hours between each shots ? That would greatly change how you need to prepare yourself.

# Smooth or hard movement transitions?

## Smooth transitions

Smooth transitions between each photos means a short interval between each capture. Is is used when you want your subject to move slowly or show few changes between each frame so the user can understand the subject movement over time. A high frame rate (at least 24 fps, 30 fps is best) in the final video is required for smooth transitions. If you make your calculations for a video that is too smooth, the subject will appear frozen which is not something that we want on a time-lapse video. Usual examples are melting ice, clouds or sunsets/sunrise, or mostly any kind or subject movement.

## Hard transitions

As opposed to smooth transitions, hard transitions between each photos means a longer time interval between each capture. It is used in situation where the user do not have to follow movement like when you want to show the different steps or the increasing progress of a project. A low frame rate (between 1 fps to 15 fps) in the final video would result to a final video with hard transitions. If you make your calculations for a video with too hard transitions, the viewer could get confused about what just happened since frames have a tendency to "jump" from one to another. Usual examples are building constructions or rotting fruits.

## Calculating the best interval

Once you have defined what kind of transitions you want, and the "amount" of movement you want to show in your final video, here's how to perfectly define the right interval time to get very smooth or hard transitions. You first need to define the following:

* How long does the real event last ?
* How long the final video would be ?
* What is the final video frame rate ? That is 15 or less for hard and 24 and over for smooth.

Now open [Photography time-lapse calculator](/wp-content/uploads/2015/02/Photography-time-lapse-calculator.xls) (that's an Excel sheet) and take a look at the "interval calculator". Use the same number in the appropriate fields and the sheet will do the math to give you the perfect interval time for the desired smooth/hard transition effect.

# Gear setup

## Use manual focus

Set your camera in manual focus. This is also mandatory if your intervals are really close (less than 10 seconds). If you set your camera in auto focus, lets say to capture the movement of your subject when it moves closer and away from the camera, you will end up with some pictures with a blurry background and some with a clear background and that would not be interesting to watch. Also, the auto-focus of your camera can take as much as 1-2 seconds and that delay would be added to the intervals between each shots. You are much better to use a narrower aperture to increase the dept of field instead of using auto-focus. It also saves battery power :)

## Set camera in manual mode

You need to set your camera in manual mode. The objective is to have an identical exposure over all your frames (pictures) during the whole capturing period. The only way to expect this is to use the manual mode in your DSLR. All other modes will make assumptions or estimation of what is the best value for ISO/Aperture/Shutter speed and you may not always get the same value which would create slight variations in the final image exposure. The same applies for any priority modes.

### Shutter speeds

almost any shutter speed is good for doing time-lapse videos. However, make sure you select a shutter speed that is appropriate for the situation. If your shutter speed that is too fast/quick, all your images will appear frozen which would result in a consecutive list of frozen action images. If your final video have a medium to low frame rate, you could make use of this by selecting a slow shutter speed (read 1/60th to 1/30th). That shutter speed range would create motion blur in your image and ease the transition between 2 video frames.

### Aperture

Set your aperture as wide as possible (that means the lowest f number as possible) to allows a maximum amount of light to enter the camera. Take consideration for allowing a proper [depth of field](http://www.google.com/?q=aperture+depth+of+field) for your video. If your subject is close to the camera, a wider depth of field is required (to have both the background and the subject at focus) so a narrow aperture (high f number) would be better. If you are capturing a background or a nature scene, the widest aperture would allow more light to come in without sacrificing anything at focus.

### ISO

As usual, set your ISO to the lowest possible value that is reasonable for giving the right exposure.

## Shoot in JPG

Set your camera to shoot in JPG not RAW. RAW is really nice for stills but it is way too heavy for multiple captures and considerably reduces your recording time. Besides, you don't really need RAW for time-lapse videos. An average RAW file takes about 26.75 MiB and considering you may be capturing stills at 15 seconds intervals, you will only be able to record 570 frames. In other words, you will only be able to record an event of 2 hours and 22 minutes before fulling the memory card. If you are capturing at 10 seconds interval, that's only 1 hour and 35 minutes of real-time recording before fulling the memory card! Here's the calculations: 16 GB = 16000000000 bytes = 15258 MiB 15258 MiB / 26.75 MiB per photo = 570 frames 570 photos @ 1 frame per 15 seconds = 142.5 minutes = 02:22:30 of real-time recording. 570 photos @ 1 frame per 10 seconds = 95 minutes = 01:35:30 of real-time recording. During this shooting, I use RAW captures without thinking much about this. I had to invest too much time converting and resizing images to JPG. I also had to change the 16 GB memory card for another one at the end of the video which explains why the view angle changes at the end. Save yourself the trouble and use the JPG captures.

## Set reduced image capture size

This step is optional but doing so could reduce the amount of time in post-processing. If you already know the resolution of the final video (480p, 720p, 1080p, 4K), you can set the camera to automatically resize images to the appropriate resolution that matches the final video resolution. You can also decide to skip this step and reduce images size during post-processing with your [favorite image editor](http://www.gimp.org/downloads/) with the help of a [batch plugin](http://members.ozemail.com.au/~hodsond/dbp.html) or use a live [resize filter](#Applying_additional_filters_optional) when importing images into the video software.

## Turn off Image stabilization (IS)

As usual, since you are using a tripod, set Image Stabilization to off.

## Configure appropriate white balance

Turn off auto white balance. This is required to reduce flickering to a minimum. It is better to have flickering because the amount of light in the room was varying over time than having your camera trying to detect the best white balance on every capture. Try on auto once, look at the value and use the same for all other captures. In other words, it is best to set all auto features of your camera to off for the same reasons.

## Connect your intervalometer

Connect your intervalometer and configure the appropriate interval time calculated previously for capturing frames.

# Capture your scene

Now is the time to take as much shoot as needed for properly capturing your subject's movement or change over time. In the meantime, get yourself a coffee, start downloading required softwares or watch a movie and come back in a hour or so :)

# Prepare your image files

After the capturing session is completed and you have transferred all your images to your PC, it is time to make sure your files are prepared for the final product.

## Verify the image sequence order

In order to import the images to a video application, all images must have the same pattern: a common prefix with a sequential increasing number. All images have to be named in a continuous image sequence. However, in some scenarios, this list could be broken or require modifications. Here's some situation that might happened which would require special attention.

### Reordering, fixing image counter wrap around

In the low probability that you started shooting pictures when your camera's file name counter was close to wrapping around (say IMG\_9xxx.jpg), you might end up with a broken sequence. That means you will have your first block which is IMG\_9000.jpg to IMG\_9999.jpg and your second block which is IMG\_0000.jpg to IMG\_2345.jpg. Most (if not all) video software will try to import each block as independent blocks. To prevent this, you need to reorder your images to a single continuous image sequence. In other words, you basically need to reorder each block to the following:

* IMG\_0000.jpg \[...\] IMG\_2345.jpg renamed to IMG\_1000.jpg \[...\] IMG\_3345.jpg
* IMG\_9000.jpg \[...\] IMG\_9999.jpg renamed to IMG\_0000.jpg \[...\] IMG\_0999.jpg

to get the target range IMG\_0000.jpg \[...\] IMG\_3345.jpg.

The easiest way to do this is to use the following script. Copy and paste the content of the following window and create a file located next to the images called "rename.vbs".

{{< pleasenote >}}
  Take note that the .vbs file extension is mandatory for Windows to recognize the file as a runnable script.
{{< /pleasenote >}}

{{< hightlight-static-file file="/static/wp-content/uploads/2015/02/Reorder-photography-blocks.vbs" lang="vb" >}}

The script will ask for the required parameters and take care of the issue and all the renaming. Once executed, you will have a single block of continuous images: IMG\_0000.jpg \[...\] IMG\_3345.jpg. Note: This script is only available for the Windows platform.

### Deleting erroneous images

If you see an erroneous image or an image that would break the flow of movement, you may have to delete an image from the sequence. Let say that during the capturing session, you had to check your camera and accidentally moved your hand in front of the lens. IMG\_3400.jpg is now a nice black picture of your hand... If you ever have to delete an image, you need to restore the natural sequence order for the video software to recognize the whole sequence. For every image deleted, you need to copy &amp; paste the previous image and rename it using the name of the deleted image. In the previous example, if you want to delete IMG\_3400.jpg, you first delete IMG\_3400.jpg, then copy IMG\_3399.jpg and name it IMG\_3400.jpg. If you want to delete multiple frames, lets say IMG\_3050.jpg to IMG\_3069.jpg (20 frames), it is best to restore the sequence using both IMG\_3049.jpg and IMG\_3070.jpg to create a smaller hole/gap. That is deleting IMG\_3050.jpg through IMG\_3059.jpg and using IMG\_3049.jpg for restoration of the first half and deleting IMG\_3060.jpg through IMG\_3069.jpg and using IMG\_3070.jpg for restoration of the second half. Please take note that deleting pictures actually creates an artificial hole/gap in the final video timeline and may result to a hard transition.

### Resize your images

This step is optional but it is suggested to resize your images to help Windows Movie Maker or VirtualDub to load all images into your project. It is a good idea to resize all your images to match the final resolution of your movie (that is 720p or 1080p pixels high). The best way to resize your images is to use [David's Batch Processor 1.1.8](http://members.ozemail.com.au/~hodsond/dbp.html) plugin for [Gimp](http://www.gimp.org/downloads/) and follow theses steps:

1. Open Gimp.
2. Click on ***Filters\\Batch Process...*** menu to launch David's Batch Processor.
3. Import your images into David's Batch Processor: 
    1. In the ***Input tab***, click the Add Files button and browse to your images location. ie *G:\\Temp\\timelapse\\noel2014*
    2. Select all your images and press the Add button. That will import all your images. This process may take some time. Please be patient.
    3. Once completed, press the Close button to close the file dialog.
4. Enable Resizing for all your images 
    1. Click on the ***Resize tab***.
    2. Check the ***Enable*** check box.
    3. Select the ***Absolute*** option. That will enable the second section.
    4. Enter the final resolution of your movie. 
        1. Use a *Width* of 1280 and a *Height* of 720 for a 720p resolution or
        2. Use a *Width* of 1920 and a *Height* of 1080 for a 1080p resolution.
    5. Select ***Inside*** for the *Fit* property.
    
    
    1. Define where your resized images will be saved 
        1. Click on the ***Rename tab***.
        2. Click on Select Dir button and select a new output folder. ie: *G:\\Temp\\timelapse\\noel2014Resize*
        3. Once completed, press the Open button to close the folder dialog.
        4. You should see your target folder listed next to the field ***To Directory***.
    2. Define the image format of the resized images 
        1. Click on the ***Output tab***.
        2. Select the following values for each fields: 
            1. Format: JPG
            2. Quality: 0.85
            3. Smoothing: 0.00
            4. Optimize: checked.
            5. Progressive: unchecked.
            6. Sampling: 2x2
            7. Baseline: checked.
            8. Restarts: 0
            9. Algorithm: Integer
    3. Press the Start button to start resizing your images.
    4. Wait for the process to complete.

[![David Batch Processor Done](/wp-content/uploads/2015/02/David-Batch-Processor-Done-234x300.png "David Batch Processor Done")](/wp-content/uploads/2015/02/David-Batch-Processor-Done.png)

# Combining photos into a movie

In the next sections, I will explain 2 methods that you can use to combine photos into a movie. Each methods has their own required list of software and has their pros and cons.

## Windows Movie Maker

This sections explains how to process your captured images into a video using Windows Movie Maker.

[![Windows Movie Maker screenshot](/wp-content/uploads/2015/02/Windows-Movie-Maker-300x163.jpg "Windows Movie Maker screenshot")](/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg)

### Download required files

* Windows Movie Maker [online installer](http://windows.microsoft.com/en-ca/windows-live/download-windows-essentials) / [offline installer](http://windows.microsoft.com/en-ca/windows-live/essentials-install-offline-faq) download.
* or the older version [Windows Movie Maker 2.6](http://www.microsoft.com/en-us/download/details.aspx?id=34).

Download and install each software before processing to the next steps.

### Add photos to movie timeline

All your images are ready. Now is the time to import them in Windows Movie Maker by following theses steps:

1. Open ***Windows Movie Maker***.
2. Importing all images 
    1. Press the ***Add videos and photos*** button.
    2. Select all your images and press the Open button.
3. Set the appropriate frame rate 
    1. Right-click on the ***timeline*** and select the option ***Select All***.
    2. Press ***Ctrl+A*** key to select all.
    3. Click on the ***Edit tab***.
    4. Locate the ***Duration*** field. That is the time in seconds where the frame will remain visible.
    5. Based on the calculation you made in section [Calculating the best interval](#Calculating_the_bestinterval), set the appropriate duration to match your desired frame rate with the following formula: Duration = 1 / fps. 
        1. Here are quick calculations:1 fps = 1 second 2 fps = 0,5 second 10 fps = 0,1 second 15 fps = 0,066666667 second 16 fps = 0,0625 second 20 fps = 0,05 second 24 fps = 0,041666667 second 30 fps = 0,033333333 second

### Adding an audio track

Windows Movie Maker supports adding an audio track to the video. You can use an audio file or the audio of another video as an audio track. To add an audio track, follow theses steps:

1. Left-click on the ***timeline*** and move the cursor to the beginning of the timeline.
2. Click on ***Add Music*** button in the ribbon toolbar.
3. Browse the audio or video file and click on Open button.
4. You should see a new track with a green background on the timeline view.

If you do not have an audio file on your computer, you can try to find some on the [Creative Commons Search (Music)](http://search.creativecommons.org/) site.

### Saving to MP4 file

Now that your composition is complete, save your project into an MP4 video by following theses steps:

1. Click on ***Save Movie*** button in the ribbon toolbar.
2. Select the export settings that matches your needs and file size. For maximum quality, save your movie using the ***For high-definition display*** setting.

[![Windows Movie Maker Export Completed](/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed-300x120.png "Windows Movie Maker Export Completed")](/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png)

## VirtualDub

This sections explains how to process your captured images into a video using VirtualDub.

### Download required files

* [VirtualDub](http://virtualdub.sourceforge.net/) (latest version).
* [Lagarith Lossless Video Codec](http://lags.leetcode.net/codec.html)
* [VirtualDub MSU Deflicker filter ](http://www.compression.ru/video/deflicker/index_en.html)or [Deflicker Filter for VirtualDub](http://neuron2.net/deflick/flick.html)
* [HandBrake](https://handbrake.fr/downloads.php)
* [FadeFX 1.2](http://home.earthlink.net/~tacosalad/video/fadefx.htm) - Fade Effects for VirtualDub

Download and install each software before processing to the next steps.

### Importing

Importing your images as a video in VirtualDub is also really easy: simply follow theses steps:

1. Start VirtualDub.
2. Click on ***File/Open video file*** menu.
3. In the Open file dialog, make sure that ***Automatically load linked segments*** is checked.
4. Select the first image of the sequence and click the Open button. VirtualDub will automatically detect the next images and will update the timeline accordingly.
5. Verify that the timeline length (in video frames) matches the total number of captured images in your project.

[![VirtualDub editing](/wp-content/uploads/2015/03/VirtualDub-editing-300x135.png "VirtualDub editing")](/wp-content/uploads/2015/03/VirtualDub-editing.png)

### Configure Frame Rate

1. Click on ***Video/Frame Rate*** menu. That will open the Video frame rate control dialog.
2. Select ***Change frame rate to (fps)*** and enter the value you calculated in section [Calculating the best interval](#Calculating_the_bestinterval).

### Lossless video codec

VirtualDub output uncompressed AVI files by default which is not an option considering the resolution of the video. It needs to be configured to use a [video codec](http://en.wikipedia.org/wiki/Video_codec) for compressing the video. Since this guide will handle re-encoding using Handbrake, it is suggested to use a lossless video codec to prevent loosing any quality while exporting your video from VirtualDub to Handbrake. The best lossless video codec available is [Lagarith Lossless Video Codec](http://lags.leetcode.net/codec.html). Here are the steps for configuring the codec:

1. Click on ***Video/Compression*** menu. That will open the ***Select video compression*** dialog.
2. Select ***Lagarith Lossless Codec*** and press the Configure button.
3. Check ***Use Multithreading*** and ***Prevent Upsampling When Decoding***.

### Reducing flickering

Flickering occurs when the exposition between each video frame is not identical which gives the fading effect that you may see. That is why your should shoot in manual: to reduce flickering to a minimum. If you see flickering in your video, a filter can be applied to the video to reduce it. Here are the steps for configuring the filter:

1. Click on ***Video/Filters*** menu. That will open the ***Filter*** dialog.
2. Click on the Add button. That will open the ***Add Filter*** dialog.
3. Click on the Load button and ***browse*** to the location where you extracted one of the ***deflicker filter (\*.vdf)***
4. Press the OK Button.
5. Configure the filter parameters and press the OK button.

[![VirtualDub Deflicker filter](/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter-300x208.png "VirtualDub Deflicker filter")](/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png)

### Applying additional filters (optional)

If you want to add fade-in or fade-off effects you can use the FadeFX filter with the following:

1. Click on ***Video/Filters*** menu. That will open the ***Filter*** dialog.
2. Click on the Add button. That will open the ***Add Filter*** dialog.
3. Click on the Load button and ***browse*** to the location where you extracted one of the ***fadefx filter (\*.vdf)***
4. Press the OK Button.
5. Configure the filter parameters and press the OK button.

[![VirtualDub Fade In Fade Out filter](/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter-300x208.png "VirtualDub Fade In Fade Out filter")](/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png)

### Adding an audio track

VirtualDub also support adding an audio track from an external audio file. VirtualDub works best with ***WAV*** of ***MP3*** audio file. Here are the steps for adding an audio file to your video:

1. Click on ***Audio/Audio from other file*** menu. That will open the ***Open an audio file*** dialog.
2. ***B******rowse*** to the location of the audio file add *and click the Open button.*
3. If you are importing an MP3 file, ***select*** the type of bitrate of the file. That is CBR or VBR. In case you do not know, select ***Autodetect***.
4. Press the OK Button.

For free creative commons licensed music, visit the following link: [Creative Commons Search (Music)](http://search.creativecommons.org/).

### Saving to temporary \*.avi file

As explained in the [Lossless video codec](#Lossless_video_codec) section, VirtualDub is not the best software for encoding your video (compressing). It is better to use Handbrake for this task. To save your video without loosing any detail or data, a temporary AVI file must be created.

1. Click on ***File/Save as AVI*** menu. That will open the ***Save file*** dialog.
2. ***B******rowse*** to the location where you want to save your video and enter a filename for saving. Click the Save button.
3. Wait for the encoding to complete.

[![VirtualDub encoding](/wp-content/uploads/2015/03/VirtualDub-encoding-247x300.png "VirtualDub encoding")](/wp-content/uploads/2015/03/VirtualDub-encoding.png)

### Re-encoding using Handbrake

Handbrake is the best video encoder to use for compressing your video because it supports [constant quality](https://handbrake.fr/docs/en/1.0.0/technical/video-cq-vs-abr.html) encoding parameters. Here are the steps for compressing your video:

1. Click on ***Source*** icon in the toolbar and select ***File***. That will open the ***Open file*** dialog.
2. ***B******rowse*** to the location of the temporary video (\*.avi) you created in the previous step. Click the Open button.
3. Click on the Browse button. That will open the ***Save file*** dialog.
4. ***B******rowse*** to the location where you want to save your final video and enter a filename for saving. Click the Save button.
5. Click on the ***Picture tab***.
6. Select the following values for each fields: 
    1. Anamorphic: Strict
    2. Cropping: Custom
    3. Top, Bottom, Left, Right: 0
7. Click on the ***Video tab***.
8. Select the following values for each fields: 
    1. Video codec: H.264 (x264)
    2. x264 Preset: Slow
    3. x264 Tune: None
    4. Quality, Constant Quality: RF 22
9. Click on the ***Audio tab***.
10. Select ***Auto Passthru*** for Codec.
11. Click on the Start icon in the toolbar.
12. Wait for the encoding to complete.

# Final results

The shots for this time-lapse were taken with my 18-55mm kit lens at 18mm, f/8.0, 1/30th shutter speed, ISO 1600 and 2 seconds between each shots. I accidentally left auto white balance turned on, which is what gives it that flicker. The real-time event lasted for 1 hour and 16 minutes. A total of 2264 photos was required. Here is the final result video visualized at 30 frames per seconds: 

{{< youtube bPIP4BmjDAw >}}
