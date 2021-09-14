---
title: How to make a time-lapse video with free tools and a DSLR camera
author: end2end
type: post
date: 2015-03-15T19:50:02+00:00
url: /how-to-make-a-time-lapse-video-with-free-tools-and-a-dslr-camera/
featured_image: /wp-content/uploads/2015/02/How-to-make-a-time-lapse-video-with-free-tools-and-a-DSLR-camera.jpg
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
# <span id="Introduction">Introduction</span>

[Time-lapse photography][1] is a wonderful effect to make your images alive instead of static because you can make a plain (or almost boring) event and make it so much more dramatic. However, it is something that usually needs a lot of time investment to get something acceptable.

Considering my family was planning to decorate the Christmas tree during the weekend, I decided to take my camera and capture the whole event in a time-lapse video.<!--more-->

To get a nice video, you need to prepare yourself before taking the shots because if you don’t, you can end up with a bad picture set and have a hard time merging all pictures together.

The following article will explains how I managed to make a nice time-lapse video with a DSLR using only free software.

Click here to jump to the [Final Results][2] section and see the video.

# <span id="Prepare_you_gears">Prepare you gears</span>

## <span id="Mandatory_gears_for_time-lapse_videos">Mandatory gears for time-lapse videos</span>

### <span id="Tripod">Tripod</span>

This one is obvious. You need a tripod to make sure that all images are aligned the same directions. The field of view must be identical for all captured images. You do not want to see the background of the event moving during the video but only your subject.

### <span id="Intervalometer">Intervalometer</span>

An intervalometer is a remote trigger with the added capacity to trigger the camera shutter at regular intervals. It is mandatory if you want to do time-lapse image capturing. It is not used to reduce camera shake since the photographer does not take any actions on the camera during the capturing process.

## <span id="Useful_stuff">Useful stuff</span>

### <span id="Calculator">Calculator</span>

A calculator is useful if you go out in the field for your capturing session. For most time-lapse projects related to capturing the nature, it would be wise to bring a camera with you for calculating the perfect interval for your desired effect. See the section [_Calculating the best interval_][3] for details.

## <span id="Tools_you_wont_need">Tools you won’t need</span>

### <span id="Flashes">Flashes</span>

If you think you may need a flash for taking your shots, you might have to reconsider your project.

If your intervals are too short (the elapsed time between each photos), the flash might not have the time to recharge between each shots.

If your intervals are long enough to have your flash recharged, it means that the subject could be positioned differently in the scene resulting in great highlight changes which is really hard to correct in post-production.

Another issue that the flash might cause is flickering. If your scene is not well lighted, there is a high chance that you end up with lots of flickering during the [merging phase][4]. The exposition will vary a lot between each shots and that would not be pleasant to watch. Some plugins can help to reduce flickering but it is always better to think about this in pre-production than dealing with it in post-production.

I am unable to think of a suitable scenario where a flash would be required that also requires long intervals like 5 minutes or more.

# <span id="Check_your_calculations">Check your calculations</span>

Don&#8217;t go out and try to shot anything as quickly as possible. I recommend that you take the time to think and evaluate what is the best interval (time between each photos) for your needs. Is it going to be seconds, minutes or even hours between each shots ? That would greatly change how you need to prepare yourself.

# <span id="Smooth_or_hard_movement_transitions">Smooth or hard movement transitions?</span>

## <span id="Smooth_transitions">Smooth transitions</span>

Smooth transitions between each photos means a short interval between each capture. Is is used when you want your subject to move slowly or show few changes between each frame so the user can understand the subject movement over time.

A high frame rate (at least 24 fps, 30 fps is best) in the final video is required for smooth transitions.

If you make your calculations for a video that is too smooth, the subject will appear frozen which is not something that we want on a time-lapse video.

Usual examples are melting ice, clouds or sunsets/sunrise, or mostly any kind or subject movement.

## <span id="Hard_transitions">Hard transitions</span>

As opposed to smooth transitions, hard transitions between each photos means a longer time interval between each capture. It is used in situation where the user do not have to follow movement like when you want to show the different steps or the increasing progress of a project.

A low frame rate (between 1 fps to 15 fps) in the final video would result to a final video with hard transitions.

If you make your calculations for a video with too hard transitions, the viewer could get confused about what just happened since frames have a tendency to &#8220;jump&#8221; from one to another.

Usual examples are building constructions or rotting fruits.

## <span id="Calculating_the_bestinterval">Calculating the best interval</span>

Once you have defined what kind of transitions you want, and the &#8220;amount&#8221; of movement you want to show in your final video, here&#8217;s how to perfectly define the right interval time to get very smooth or hard transitions.

You first need to define the following:

  * How long does the real event last ?
  * How long the final video would be ?
  * What is the final video frame rate ? That is 15 or less for hard and 24 and over for smooth.

Now open [Photography time-lapse calculator][5] (that&#8217;s an Excel sheet) and take a look at the &#8220;interval calculator&#8221;. Use the same number in the appropriate fields and the sheet will do the math to give you the perfect interval time for the desired smooth/hard transition effect.

# <span id="Gear_setup">Gear setup</span>

## <span id="Use_manual_focus">Use manual focus</span>

Set your camera in manual focus. This is also mandatory if your intervals are really close (less than 10 seconds).

If you set your camera in auto focus, lets say to capture the movement of your subject when it moves closer and away from the camera, you will end up with some pictures with a blurry background and some with a clear background and that would not be interesting to watch.

Also, the auto-focus of your camera can take as much as 1-2 seconds and that delay would be added to the intervals between each shots. You are much better to use a narrower aperture to increase the dept of field instead of using auto-focus.

It also saves battery power 🙂

## <span id="Set_camera_in_manual_mode">Set camera in manual mode</span>

You need to set your camera in manual mode.

The objective is to have an identical exposure over all your frames (pictures) during the whole capturing period. The only way to expect this is to use the manual mode in your DSLR. All other modes will make assumptions or estimation of what is the best value for ISO/Aperture/Shutter speed and you may not always get the same value which would create slight variations in the final image exposure.

The same applies for any priority modes.

### <span id="Shutter_speeds">Shutter speeds</span>

almost any shutter speed is good for doing time-lapse videos. However, make sure you select a shutter speed that is appropriate for the situation. If your shutter speed that is too fast/quick, all your images will appear frozen which would result in a consecutive list of frozen action images.

If your final video have a medium to low frame rate, you could make use of this by selecting a slow shutter speed (read 1/60th to 1/30th). That shutter speed range would create motion blur in your image and ease the transition between 2 video frames.

### <span id="Aperture">Aperture</span>

Set your aperture as wide as possible (that means the lowest f number as possible) to allows a maximum amount of light to enter the camera. Take consideration for allowing a proper [depth of field][6] for your video.

If your subject is close to the camera, a wider depth of field is required (to have both the background and the subject at focus) so a narrow aperture (high f number) would be better.

If you are capturing a background or a nature scene, the widest aperture would allow more light to come in without sacrificing anything at focus.

### <span id="ISO">ISO</span>

As usual, set your ISO to the lowest possible value that is reasonable for giving the right exposure.

## <span id="Shoot_in_JPG">Shoot in JPG</span>

Set your camera to shoot in JPG not RAW. RAW is really nice for stills but it is way too heavy for multiple captures and considerably reduces your recording time. Besides, you don&#8217;t really need RAW for time-lapse videos.

An average RAW file takes about 26.75 MiB and considering you may be capturing stills at 15 seconds intervals, you will only be able to record 570 frames. In other words, you will only be able to record an event of 2 hours and 22 minutes before fulling the memory card. If you are capturing at 10 seconds interval, that&#8217;s only 1 hour and 35 minutes of real-time recording before fulling the memory card!

Here&#8217;s the calculations:

16 GB = 16000000000 bytes = 15258 MiB  
15258 MiB / 26.75 MiB per photo = 570 frames  
570 photos @ 1 frame per 15 seconds = 142.5 minutes = 02:22:30 of real-time recording.  
570 photos @ 1 frame per 10 seconds = 95 minutes = 01:35:30 of real-time recording.

During this shooting, I use RAW captures without thinking much about this. I had to invest too much time converting and resizing images to JPG. I also had to change the 16 GB memory card for another one at the end of the video which explains why the view angle changes at the end. Save yourself the trouble and use the JPG captures.

## <span id="Set_reduced_image_capture_size">Set reduced image capture size</span>

This step is optional but doing so could reduce the amount of time in post-processing. If you already know the resolution of the final video (480p, 720p, 1080p, 4K), you can set the camera to automatically resize images to the appropriate resolution that matches the final video resolution.

You can also decide to skip this step and reduce images size during post-processing with your [favorite image editor][7] with the help of a [batch plugin][8] or use a live [resize filter][9] when importing images into the video software.

## <span id="Turn_off_Image_stabilization_IS">Turn off Image stabilization (IS)</span>

As usual, since you are using a tripod, set Image Stabilization to off.

## <span id="Configure_appropriate_white_balance">Configure appropriate white balance</span>

Turn off auto white balance. This is required to reduce flickering to a minimum. It is better to have flickering because the amount of light in the room was varying over time than having your camera trying to detect the best white balance on every capture. Try on auto once, look at the value and use the same for all other captures.

In other words, it is best to set all auto features of your camera to off for the same reasons.

## <span id="Connect_your_intervalometer">Connect your intervalometer</span>

Connect your intervalometer and configure the appropriate interval time calculated previously for capturing frames.

# <span id="Capture_your_scene">Capture your scene</span>

Now is the time to take as much shoot as needed for properly capturing your subject&#8217;s movement or change over time. In the meantime, get yourself a coffee, start downloading required softwares or watch a movie and come back in a hour or so 🙂

# <span id="Prepare_your_image_files">Prepare your image files</span>

After the capturing session is completed and you have transferred all your images to your PC, it is time to make sure your files are prepared for the final product.

## <span id="Verify_the_image_sequence_order">Verify the image sequence order</span>

In order to import the images to a video application, all images must have the same pattern: a common prefix with a sequential increasing number. All images have to be named in a continuous image sequence. However, in some scenarios, this list could be broken or require modifications.

Here&#8217;s some situation that might happened which would require special attention.

### <span id="Reordering_fixing_image_counter_wrap_around">Reordering, fixing image counter wrap around</span>

In the low probability that you started shooting pictures when your camera&#8217;s file name counter was close to wrapping around (say IMG\_9xxx.jpg), you might end up with a broken sequence. That means you will have your first block which is IMG\_9000.jpg to IMG\_9999.jpg and your second block which is IMG\_0000.jpg to IMG_2345.jpg. Most (if not all) video software will try to import each block as independent blocks. To prevent this, you need to reorder your images to a single continuous image sequence.

In other words, you basically need to reorder each block to the following:

  * IMG\_0000.jpg [&#8230;] IMG\_2345.jpg renamed to IMG\_1000.jpg [&#8230;] IMG\_3345.jpg
  * IMG\_9000.jpg [&#8230;] IMG\_9999.jpg renamed to IMG\_0000.jpg [&#8230;] IMG\_0999.jpg

to get the target range IMG\_0000.jpg [&#8230;] IMG\_3345.jpg.

The easiest way to do this is to use the following script. Copy and paste the content of the following window and create a file located next to the images called &#8220;rename.vbs&#8221;.

<p class="pleasenote">
  Take note that the .vbs file extension is mandatory for Windows to recognize the file as a runnable script.
</p>

<pre class="lang:vb decode:true" title="Reorder photography blocks (vbscript)" data-url="/wp-content/uploads/2015/02/Reorder-photography-blocks.vbs"></pre>

The script will ask for the required parameters and take care of the issue and all the renaming. Once executed, you will have a single block of continuous images: IMG\_0000.jpg [&#8230;] IMG\_3345.jpg.

<p class="pleasenote">
  Note: This script is only available for the Windows platform.
</p>

### <span id="Deleting_erroneous_images">Deleting erroneous images</span>

If you see an erroneous image or an image that would break the flow of movement, you may have to delete an image from the sequence. Let say that during the capturing session, you had to check your camera and accidentally moved your hand in front of the lens. IMG_3400.jpg is now a nice black picture of your hand&#8230;

If you ever have to delete an image, you need to restore the natural sequence order for the video software to recognize the whole sequence. For every image deleted, you need to copy & paste the previous image and rename it using the name of the deleted image.

In the previous example, if you want to delete IMG\_3400.jpg, you first delete IMG\_3400.jpg, then copy IMG\_3399.jpg and name it IMG\_3400.jpg.

If you want to delete multiple frames, lets say IMG\_3050.jpg to IMG\_3069.jpg (20 frames), it is best to restore the sequence using both IMG\_3049.jpg and IMG\_3070.jpg to create a smaller hole/gap. That is deleting IMG\_3050.jpg through IMG\_3059.jpg and using IMG\_3049.jpg for restoration of the first half and deleting IMG\_3060.jpg through IMG\_3069.jpg and using IMG\_3070.jpg for restoration of the second half.

<p class="pleasenote">
  Please take note that deleting pictures actually creates an artificial hole/gap in the final video timeline and may result to a hard transition.
</p>

### <span id="Resize_your_images">Resize your images</span>

This step is optional but it is suggested to resize your images to help Windows Movie Maker or VirtualDub to load all images into your project. It is a good idea to resize all your images to match the final resolution of your movie (that is 720p or 1080p pixels high).

The best way to resize your images is to use [David&#8217;s Batch Processor 1.1.8][8] plugin for [Gimp][7] and follow theses steps:

<li style="text-align: justify;">
  Open Gimp.
</li>
<li style="text-align: justify;">
  Click on <em><strong>Filters\Batch Process&#8230;</strong></em> menu to launch David&#8217;s Batch Processor.
</li>
<li style="text-align: justify;">
  Import your images into David&#8217;s Batch Processor: <ol>
    <li style="text-align: justify;">
      In the <em><strong>Input tab</strong></em>, click the Add Files button and browse to your images location.<br /> ie <em>G:\Temp\timelapse\noel2014</em>
    </li>
    <li style="text-align: justify;">
      Select all your images and press the Add button. That will import all your images. This process may take some time. Please be patient.
    </li>
    <li style="text-align: justify;">
      Once completed, press the Close button to close the file dialog.
    </li>
  </ol>
</li>

<li style="text-align: justify;">
  Enable Resizing for all your images <ol>
    <li style="text-align: justify;">
      Click on the <em><strong>Resize tab</strong></em>.
    </li>
    <li style="text-align: justify;">
      Check the <em><strong>Enable</strong></em> check box.
    </li>
    <li style="text-align: justify;">
      Select the <em><strong>Absolute</strong></em> option. That will enable the second section.
    </li>
    <li style="text-align: justify;">
      Enter the final resolution of your movie. <ol>
        <li style="text-align: justify;">
          Use a <em>Width</em> of 1280 and a <em>Height</em> of 720 for a 720p resolution or
        </li>
        <li style="text-align: justify;">
          Use a <em>Width</em> of 1920 and a <em>Height</em> of 1080 for a 1080p resolution.
        </li>
      </ol>
    </li>
    
    <li style="text-align: justify;">
      Select <strong><em>Inside</em></strong> for the <em>Fit</em> property.
    </li>
  </ol>
  
  <ol>
    <li style="text-align: justify;">
      Define where your resized images will be saved <ol>
        <li style="text-align: justify;">
          Click on the <em><strong>Rename tab</strong></em>.
        </li>
        <li style="text-align: justify;">
          Click on Select Dir button and select a new output folder.<br /> ie: <em>G:\Temp\timelapse\noel2014Resize</em>
        </li>
        <li style="text-align: justify;">
          Once completed, press the Open button to close the folder dialog.
        </li>
        <li style="text-align: justify;">
          You should see your target folder listed next to the field <strong><em>To Directory</em></strong>.
        </li>
      </ol>
    </li>
    
    <li style="text-align: justify;">
      Define the image format of the resized images <ol>
        <li style="text-align: justify;">
          Click on the <em><strong>Output tab</strong></em>.
        </li>
        <li style="text-align: justify;">
          Select the following values for each fields: <ol>
            <li style="text-align: justify;">
              Format: JPG
            </li>
            <li style="text-align: justify;">
              Quality: 0.85
            </li>
            <li style="text-align: justify;">
              Smoothing: 0.00
            </li>
            <li style="text-align: justify;">
              Optimize: checked.
            </li>
            <li style="text-align: justify;">
              Progressive: unchecked.
            </li>
            <li style="text-align: justify;">
              Sampling: 2&#215;2
            </li>
            <li style="text-align: justify;">
              Baseline: checked.
            </li>
            <li style="text-align: justify;">
              Restarts: 0
            </li>
            <li style="text-align: justify;">
              Algorithm: Integer
            </li>
          </ol>
        </li>
      </ol>
    </li>
    
    <li style="text-align: justify;">
      Press the Start button to start resizing your images.
    </li>
    <li style="text-align: justify;">
      Wait for the process to complete.
    </li>
  </ol>
</li>

<div id="attachment_776" style="width: 244px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/02/David-Batch-Processor-Done.png"><img aria-describedby="caption-attachment-776" loading="lazy" class="size-medium wp-image-776" src="http://www.end2endzone.com/wp-content/uploads/2015/02/David-Batch-Processor-Done.png" alt="David Batch Processor Done" width="234" height="300" srcset="http://www.end2endzone.com/wp-content/uploads/2015/02/David-Batch-Processor-Done.png 234w, http://www.end2endzone.com/wp-content/uploads/2015/02/David-Batch-Processor-Done.png 117w, http://www.end2endzone.com/wp-content/uploads/2015/02/David-Batch-Processor-Done.png 400w" sizes="(max-width: 234px) 100vw, 234px" /></a>
  
  <p id="caption-attachment-776" class="wp-caption-text">
    David Batch Processor Done
  </p>
</div>

# <span id="Combining_photos_into_a_movie">Combining photos into a movie</span>

In the next sections, I will explain 2 methods that you can use to combine photos into a movie. Each methods has their own required list of software and has their pros and cons.

## <span id="Windows_Movie_Maker">Windows Movie Maker</span>

This sections explains how to process your captured images into a video using Windows Movie Maker.

<div id="attachment_788" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg"><img aria-describedby="caption-attachment-788" loading="lazy" class="size-medium wp-image-788" src="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg" alt="Windows Movie Maker screenshot" width="300" height="163" srcset="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg 672w, http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker.jpg 965w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-788" class="wp-caption-text">
    Windows Movie Maker screenshot
  </p>
</div>

### <span id="Download_required_files">Download required files</span>

<li style="text-align: justify;">
  Windows Movie Maker <a href="http://windows.microsoft.com/en-ca/windows-live/download-windows-essentials">online installer</a> / <a href="http://windows.microsoft.com/en-ca/windows-live/essentials-install-offline-faq">offline installer</a> download.
</li>
  * or the older version [Windows Movie Maker 2.6][10].

Download and install each software before processing to the next steps.

### <span id="Add_photos_to_movie_timeline">Add photos to movie timeline</span>

All your images are ready. Now is the time to import them in Windows Movie Maker by following theses steps:

<li style="text-align: justify;">
  Open <strong><em>Windows Movie Maker</em></strong>.
</li>
<li style="text-align: justify;">
  Importing all images <ol>
    <li style="text-align: justify;">
      Press the <em><strong>Add videos and photos</strong></em> button.
    </li>
    <li style="text-align: justify;">
      Select all your images and press the Open button.
    </li>
  </ol>
</li>

<li style="text-align: justify;">
  Set the appropriate frame rate <ol>
    <li style="text-align: justify;">
      Right-click on the <em><strong>timeline</strong> </em>and select the option <em><strong>Select All</strong></em>.
    </li>
    <li style="text-align: justify;">
      Press <em><strong>Ctrl+A</strong></em> key to select all.
    </li>
    <li style="text-align: justify;">
      Click on the <em><strong>Edit tab</strong></em>.
    </li>
    <li style="text-align: justify;">
      Locate the <em><strong>Duration</strong></em> field. That is the time in seconds where the frame will remain visible.
    </li>
    <li style="text-align: justify;">
      Based on the calculation you made in section <a href="#Calculating_the_bestinterval">Calculating the best interval</a>, set the appropriate duration to match your desired frame rate with the following formula:<br /> Duration = 1 / fps.</p> <ol>
        <li style="text-align: justify;">
          Here are quick calculations:1 fps = 1 second<br /> 2 fps = 0,5 second<br /> 10 fps = 0,1 second<br /> 15 fps = 0,066666667 second<br /> 16 fps = 0,0625 second<br /> 20 fps = 0,05 second<br /> 24 fps = 0,041666667 second<br /> 30 fps = 0,033333333 second
        </li>
      </ol>
    </li>
  </ol>
</li>

### <span id="Adding_an_audio_track">Adding an audio track</span>

Windows Movie Maker supports adding an audio track to the video. You can use an audio file or the audio of another video as an audio track. To add an audio track, follow theses steps:

  1. Left-click on the _**timeline**_ and move the cursor to the beginning of the timeline.
<li style="text-align: justify;">
  Click on <strong><em>Add Music</em></strong> button in the ribbon toolbar.
</li>
<li style="text-align: justify;">
  Browse the audio or video file and click on Open button.
</li>
<li style="text-align: justify;">
  You should see a new track with a green background on the timeline view.
</li>

If you do not have an audio file on your computer, you can try to find some on the [Creative Commons Search (Music)][11] site.

### <span id="Saving_to_MP4_file">Saving to MP4 file</span>

Now that your composition is complete, save your project into an MP4 video by following theses steps:

<li style="text-align: justify;">
  Click on <strong><em>Save Movie</em></strong> button in the ribbon toolbar.
</li>
<li style="text-align: justify;">
  Select the export settings that matches your needs and file size. For maximum quality, save your movie using the <em><strong>For high-definition display</strong></em> setting.
</li>

<div id="attachment_789" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png"><img aria-describedby="caption-attachment-789" loading="lazy" class="size-medium wp-image-789" src="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png" alt="Windows Movie Maker Export Completed" width="300" height="120" srcset="http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/02/Windows-Movie-Maker-Export-Completed.png 541w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-789" class="wp-caption-text">
    Windows Movie Maker Export Completed
  </p>
</div>

## <span id="VirtualDub">VirtualDub</span>

This sections explains how to process your captured images into a video using VirtualDub.

### <span id="Download_required_files-2">Download required files</span>

  * [VirtualDub][12] (latest version).
<li style="text-align: justify;">
  <a href="http://lags.leetcode.net/codec.html">Lagarith Lossless Video Codec</a>
</li>
<li style="text-align: justify;">
  <a href="http://www.compression.ru/video/deflicker/index_en.html">VirtualDub MSU Deflicker filter </a>or <a href="http://neuron2.net/deflick/flick.html">Deflicker Filter for VirtualDub</a>
</li>
<li style="text-align: justify;">
  <a href="https://handbrake.fr/downloads.php">HandBrake</a>
</li>
<li style="text-align: justify;">
  <a href="http://home.earthlink.net/~tacosalad/video/fadefx.htm">FadeFX 1.2</a> &#8211; Fade Effects for VirtualDub
</li>

Download and install each software before processing to the next steps.

### <span id="Importing">Importing</span>

Importing your images as a video in VirtualDub is also really easy: simply follow theses steps:

  1. Start VirtualDub.
  2. Click on **_File/Open video file_** menu.
  3. In the Open file dialog, make sure that _**Automatically load linked segments**_ is checked.
  4. Select the first image of the sequence and click the Open button. VirtualDub will automatically detect the next images and will update the timeline accordingly.
  5. Verify that the timeline length (in video frames) matches the total number of captured images in your project.

<div id="attachment_802" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png"><img aria-describedby="caption-attachment-802" loading="lazy" class="size-medium wp-image-802" src="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png" alt="VirtualDub editing" width="300" height="135" srcset="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png 1024w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png 672w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-editing.png 1209w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-802" class="wp-caption-text">
    VirtualDub editing
  </p>
</div>

### <span id="Configure_Frame_Rate">Configure Frame Rate</span>

  1. Click on **_Video/Frame Rate_** menu. That will open the Video frame rate control dialog.
  2. Select _**Change frame rate to (fps)**_ and enter the value you calculated in section [Calculating the best interval][3].

### <span id="Lossless_video_codec">Lossless video codec</span>

VirtualDub output uncompressed AVI files by default which is not an option considering the resolution of the video. It needs to be configured to use a [video codec][13] for compressing the video.

Since this guide will handle re-encoding using Handbrake, it is suggested to use a lossless video codec to prevent loosing any quality while exporting your video from VirtualDub to Handbrake. The best lossless video codec available is [Lagarith Lossless Video Codec][14].

Here are the steps for configuring the codec:

<li style="text-align: justify;">
  Click on <strong><em>Video/Compression </em></strong>menu. That will open the <em><strong>Select video compression</strong></em> dialog.
</li>
<li style="text-align: justify;">
  Select <em><strong>Lagarith Lossless Codec</strong></em> and press the Configure button.
</li>
<li style="text-align: justify;">
  Check <em><strong>Use Multithreading</strong></em> and <em><strong>Prevent Upsampling When Decoding</strong></em>.
</li>

### <span id="Reducing_flickering">Reducing flickering</span>

Flickering occurs when the exposition between each video frame is not identical which gives the fading effect that you may see. That is why your should shoot in manual: to reduce flickering to a minimum.

If you see flickering in your video, a filter can be applied to the video to reduce it. Here are the steps for configuring the filter:

<li style="text-align: justify;">
  Click on <strong><em>Video/Filters </em></strong>menu. That will open the <em><strong>Filter</strong></em> dialog.
</li>
<li style="text-align: justify;">
  Click on the Add button. That will open the <em><strong>Add Filter</strong></em> dialog.
</li>
<li style="text-align: justify;">
  Click on the Load button and <em><strong>browse</strong> </em>to the location where you extracted one of the <em><strong>deflicker filter (*.vdf)</strong></em>
</li>
<li style="text-align: justify;">
  Press the OK Button.
</li>
<li style="text-align: justify;">
  Configure the filter parameters and press the OK button.
</li>

<div id="attachment_804" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png"><img aria-describedby="caption-attachment-804" loading="lazy" class="size-medium wp-image-804" src="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png" alt="VirtualDub Deflicker filter" width="300" height="208" srcset="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Deflicker-filter.png 529w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-804" class="wp-caption-text">
    VirtualDub Deflicker filter
  </p>
</div>

### <span id="Applying_additional_filters_optional">Applying additional filters (optional)</span>

If you want to add fade-in or fade-off effects you can use the FadeFX filter with the following:

<li style="text-align: justify;">
  Click on <strong><em>Video/Filters </em></strong>menu. That will open the <em><strong>Filter</strong></em> dialog.
</li>
<li style="text-align: justify;">
  Click on the Add button. That will open the <em><strong>Add Filter</strong></em> dialog.
</li>
<li style="text-align: justify;">
  Click on the Load button and <em><strong>browse</strong> </em>to the location where you extracted one of the <em><strong>fadefx filter (*.vdf)</strong></em>
</li>
<li style="text-align: justify;">
  Press the OK Button.
</li>
<li style="text-align: justify;">
  Configure the filter parameters and press the OK button.
</li>

<div id="attachment_801" style="width: 310px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png"><img aria-describedby="caption-attachment-801" loading="lazy" class="size-medium wp-image-801" src="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png" alt="VirtualDub Fade In Fade Out filter" width="300" height="208" srcset="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-Fade-In-Fade-Out-filter.png 529w" sizes="(max-width: 300px) 100vw, 300px" /></a>
  
  <p id="caption-attachment-801" class="wp-caption-text">
    VirtualDub Fade In Fade Out filter
  </p>
</div>

### <span id="Adding_an_audio_track-2">Adding an audio track</span>

VirtualDub also support adding an audio track from an external audio file. VirtualDub works best with _**WAV**_ of _**MP3**_ audio file. Here are the steps for adding an audio file to your video:

<li style="text-align: justify;">
  Click on <strong><em>Audio/Audio from other file </em></strong>menu. That will open the <em><strong>Open an audio file</strong></em> dialog.
</li>
<li style="text-align: justify;">
  <strong><em>B</em></strong><em><strong>rowse</strong> </em>to the location of the audio file add<em> and click the Open button.</em>
</li>
<li style="text-align: justify;">
  If you are importing an MP3 file, <em><strong>select</strong></em> the type of bitrate of the file. That is CBR or VBR. In case you do not know, select <em><strong>Autodetect</strong></em>.
</li>
<li style="text-align: justify;">
  Press the OK Button.
</li>

For free creative commons licensed music, visit the following link: [Creative Commons Search (Music)][11].

### <span id="Saving_to_temporary_avi_file">Saving to temporary *.avi file</span>

As explained in the [Lossless video codec][15] section, VirtualDub is not the best software for encoding your video (compressing). It is better to use Handbrake for this task. To save your video without loosing any detail or data, a temporary AVI file must be created.

<li style="text-align: justify;">
  Click on <strong><em>File/Save as AVI </em></strong>menu. That will open the <em><strong>Save file</strong></em> dialog.
</li>
<li style="text-align: justify;">
  <strong><em>B</em></strong><em><strong>rowse</strong> </em>to the location where you want to save your video and enter a filename for saving. Click the Save button.
</li>
<li style="text-align: justify;">
  Wait for the encoding to complete.
</li>

<div id="attachment_803" style="width: 257px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-encoding.png"><img aria-describedby="caption-attachment-803" loading="lazy" class="size-medium wp-image-803" src="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-encoding.png" alt="VirtualDub encoding" width="247" height="300" srcset="http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-encoding.png 247w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-encoding.png 124w, http://www.end2endzone.com/wp-content/uploads/2015/03/VirtualDub-encoding.png 303w" sizes="(max-width: 247px) 100vw, 247px" /></a>
  
  <p id="caption-attachment-803" class="wp-caption-text">
    VirtualDub encoding
  </p>
</div>

### <span id="Re-encoding_using_Handbrake">Re-encoding using Handbrake</span>

Handbrake is the best video encoder to use for compressing your video because it supports [constant quality][16] encoding parameters. Here are the steps for compressing your video:

<li style="text-align: justify;">
  Click on <em><strong>Source</strong> </em>icon in the toolbar and select <em><strong>File</strong></em>. That will open the <em><strong>Open file</strong></em> dialog.
</li>
<li style="text-align: justify;">
  <strong><em>B</em></strong><em><strong>rowse</strong> </em>to the location of the temporary video (*.avi) you created in the previous step. Click the Open button.
</li>
<li style="text-align: justify;">
  Click on the Browse button. That will open the <em><strong>Save file</strong></em> dialog.
</li>
<li style="text-align: justify;">
  <strong><em>B</em></strong><em><strong>rowse</strong> </em>to the location where you want to save your final video and enter a filename for saving. Click the Save button.
</li>
<li style="text-align: justify;">
  Click on the <em><strong>Picture tab</strong></em>.
</li>
<li style="text-align: justify;">
  Select the following values for each fields: <ol>
    <li style="text-align: justify;">
      Anamorphic: Strict
    </li>
    <li style="text-align: justify;">
      Cropping: Custom
    </li>
    <li style="text-align: justify;">
      Top, Bottom, Left, Right: 0
    </li>
  </ol>
</li>

<li style="text-align: justify;">
  Click on the <em><strong>Video tab</strong></em>.
</li>
<li style="text-align: justify;">
  Select the following values for each fields: <ol>
    <li style="text-align: justify;">
      Video codec: H.264 (x264)
    </li>
    <li style="text-align: justify;">
      x264 Preset: Slow
    </li>
    <li style="text-align: justify;">
      x264 Tune: None
    </li>
    <li style="text-align: justify;">
      Quality, Constant Quality: RF 22
    </li>
  </ol>
</li>

<li style="text-align: justify;">
  Click on the <em><strong>Audio tab</strong></em>.
</li>
<li style="text-align: justify;">
  Select <em><strong>Auto Passthru</strong></em> for Codec.
</li>
<li style="text-align: justify;">
  Click on the Start icon in the toolbar.
</li>
<li style="text-align: justify;">
  Wait for the encoding to complete.
</li>

# <span id="Final_results">Final results</span>

The shots for this time-lapse were taken with my 18-55mm kit lens at 18mm, f/8.0, 1/30th shutter speed, ISO 1600 and 2 seconds between each shots. I accidentally left auto white balance turned on, which is what gives it that flicker.

The real-time event lasted for 1 hour and 16 minutes. A total of 2264 photos was required.

Here is the final result video visualized at 30 frames per seconds:

 [1]: http://en.wikipedia.org/wiki/time-lapse_photography
 [2]: #Final_results
 [3]: #Calculating_the_bestinterval
 [4]: #Combining_photos_into_a_movie
 [5]: http://www.end2endzone.com/wp-content/uploads/2015/02/Photography-time-lapse-calculator.xls
 [6]: http://www.google.com/?q=aperture+depth+of+field
 [7]: http://www.gimp.org/downloads/
 [8]: http://members.ozemail.com.au/~hodsond/dbp.html
 [9]: #Applying_additional_filters_optional
 [10]: http://www.microsoft.com/en-us/download/details.aspx?id=34
 [11]: http://search.creativecommons.org/
 [12]: http://virtualdub.sourceforge.net/
 [13]: http://en.wikipedia.org/wiki/Video_codec
 [14]: http://lags.leetcode.net/codec.html
 [15]: #Lossless_video_codec
 [16]: https://handbrake.fr/docs/en/1.0.0/technical/video-cq-vs-abr.html