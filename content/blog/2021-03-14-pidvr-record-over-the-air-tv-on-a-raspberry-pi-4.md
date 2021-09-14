---
title: PiDVR Record over the air TV on a Raspberry Pi 4
author: end2end
type: post
date: 2021-03-14T19:40:03+00:00
url: /pidvr-record-over-the-air-tv-on-a-raspberry-pi-4/
featured_image: /wp-content/uploads/2021/03/PiDVR-Record-over-the-air-TV-on-a-Raspberry-Pi-4.jpg
hits:
  - 173
categories:
  - Other
tags:
  - english
  - Raspberry Pi

---
# <span id="About_the_project">About the project</span>

The following project explains how I used a Raspberry Pi 4 to create a personal digital video recorder to record over-the-air tv.

# <span id="Required_Hardware">Required Hardware</span>

This project requires the following hardware:

  * Raspberry Pi 4 (with the required parts) 
      * 4GB of ram
      * A 16GB SD card
      * A micro HDMI cable
      * Monitor with HDMI input
      * A 15.3W USB-C Power Supply (3A @ 5v power supply)
      * Raspberry Pi 4 case. Preferably a passive cooling case for noise consideration.  
        I used the [Argon One][1] case.
  * An HDHomeRun Dual tuner from [Silicondust][2]. The oldest model will do. For this build, I used the [_HDHR3-US_][3] which dates back to 2012-2013.
  * An over-the-air tv antenna for ATSC signals. For this build I use the [Clearstream 4][4] antenna by Antennas Direct.
  * 50ft to 100ft Coaxial Cable, 18AWG, 75 Ohm to connect the antenna to the HDHomeRun.
  * External Solid State Drive (SSD) with about 500Gb in size.
  * USB 3.0 to SATA Converter Adapter &#8211; Look for one that has UASP support.

# <span id="Software_list">Software list</span>

This section defines the list of required software for the project. Follow the instructions in the next section to know when and how to install them.

  1. Download  _**Raspberry Pi OS with desktop and recommended software**_ from <https://www.raspberrypi.org/software/operating-systems/>
  2. Download the  _**Raspberry Pi Imager**_ to write the  _**Raspberry Pi OS**_ image to an SD card.

# <span id="Instructions">Instructions</span>

## <span id="Write_Raspberry_Pi_OS_image_file_to_your_SD_card">Write Raspberry Pi OS image file to your SD card</span>

  1. Launch the  _**Raspberry Pi Imager**_ for writing the  _**Raspberry Pi OS**_ image file to your SD card. There are plenty of online tutorial for this operation
  2. Turn on the Raspberry Pi and follow &#8220;first launch&#8221; instructions on screen.

## <span id="Update_the_Raspberry_Pi_firmware">Update the Raspberry Pi firmware</span>

The oldest Raspberry Pi 4 models that originally shipped uses an out of date firmware. Most of all, they do not support booting from an SSD drive connected through USB. Updating the firmware provides better thermals and USB boot support.

Jeff Geerling has written an excellent guide on how to upgrade the Raspberry Pi 4&#8217;s firmware.  
Follow his instructions available at:  
<https://www.jeffgeerling.com/blog/2019/upgrade-raspberry-pi-4s-firmware-bootloader-better-thermals>.

In summary, run the following commands in a terminal:

    sudo apt update
    sudo apt -y full-upgrade
    sudo apt install -y rpi-eeprom
    sudo rpi-eeprom-update
    sudo reboot

## <span id="Check_that_USB_30_to_SATA_adaptor_has_UASP_support">Check that USB 3.0 to SATA adaptor has UASP support</span>

UASP stands for USB Attached SCSI Protocol. In very few words, it is a protocol used in USB storage devices and adapters that performs better that the traditional USB 1.1 protocol.

Jeff Geerling has written an excellent guide on how to verify if your adaptor is UASP compatible.  
Follow his instructions available at:  
<https://www.jeffgeerling.com/blog/2020/uasp-makes-raspberry-pi-4-disk-io-50-faster>.

In summary, connect your ssd drive and run the following commands in a terminal:

    lsusb -t

From Jeff Geerling article:

_This command lists all the USB devices in a tree, and for each of the hard drives, you should see a `Driver` listed. If it&#8217;s `uas` , then your drive supports UASP and you&#8217;ll get the best speed. If it&#8217;s `usb-storage` , then it&#8217;s using the older BOT protocol and you won&#8217;t see the full potential._

## <span id="Enable_USB_boot_on_the_Raspberry_Pi">Enable USB boot on the Raspberry Pi</span>

A USB 3.0 Flash Drive or an USB 3.0 SSD is almost always preferable to an SD Card when booting the Raspberry Pi OS. The thing about booting Operating Systems is that 4K Read/Write Speed dictate the experience more than the sequential Read/Write Speed (the usual advertised speed). SD card usually have bad performance regarding 4K Read/Write speed.

On the Raspberry Pi4, you can specify whether to boot from USB or network if the SD card isn&#8217;t inserted.

The **raspi-config** utility can enable USB Booting on the Raspberry Pi 4:

  1. Launch the application in a terminal.
  2. Enter **Advanced Options** section.
  3. Enter **Boot Order** section.
  4. Select **USB Boot** option.

See [raspi-config.md][5] documentation and [bcm2711\_bootloader\_config.md][6] documentation on <https://www.raspberrypi.org/> for more details.

## <span id="Move_Raspberry_Pi_OS_from_SD_card_to_SSD_drive">Move Raspberry Pi OS from SD card to SSD drive</span>

Running the Raspberry Pi 4 on an SD card has great read and write speed. Opening an application feels good and we do not have to wait forever to get us going. However, an SD card cannot sustain the passage of time. Our build requires to run the raspberry pi 24/7. Sooner or later the SD card will get corrupted during a write operation and then our precious setup we created won&#8217;t be able to boot from the card anymore.

One solution is to moving the root file system of your Raspberry PI to an external USB drive bypasses this problem. This article presents instructions on moving the root file system from the SD card to an external USB drive, such that you can boot your Raspberry PI with the root file system on the USB drive.

The **SD Card Copier** application, which can be found on the **Accessories** menu of the Raspberry Pi Desktop, will copy Raspberry Pi OS from your SD card to your SSD drive. To use it, you will need to have the USB drive already connected before launching the application.

Follow the following instruction for moving the Raspberry Pi OS from SD card to SSD drive:

  1. Connect the SSD drive to a USB 3.0 port on the Raspberry Pi.
  2. Launch the **SD Card Copier** application, which can be found on the **Accessories** menu of the Raspberry Pi Desktop.
  3. Select your SD card device in the **Copy From Device** dropbown. It should probably be labeled **/dev/mmcblk0**.
  4. Select your SSD device in the **Copy To Device** dropbown. It should probably be labeled **/dev/sda**.
  5. Click on **Start** button.
  6. Wait for the process to complete.
  7. Close the application.

## <span id="Shrink_the_Operating_System_partition">Shrink the Operating System partition</span>

Following the copy of the Raspberry Pi OS from the SD card to the SSD, the **SD Card Copier** application has automatically increased the size of the last partition to the total size of the SSD. This is a problem for the following reasons:

  1. If we have a single huge partition, we are not able to backup the operating system on our disk. This is because a backup destination image cannot be stored on the same partition that it is backuping from. We need at least 2 partitions to backup the operating system to the same disk.
  2. To allow quick backup of the operating system, we need the partition to be reasonably small. On a 16GB card, the operating system partition is 14.58 GB of which about half is in use. This gives us plenty of additional space if we need to install other software.
  3. For our build, we want to store our tv recordings and the operating system on different partitions. TV recordings should be stored in the largest partition of the disk.
  4. In many cases, it is better to store operational data (in our case: recordings, backups, etc) on a separate partition (other than the OS). This configuration allows to restore the OS from a backup or install a fresh new operating system without having to erase the operational data. In other words, we get to keep our recordings in case of an OS corruption or a boot failure.

The following instructions explains how to reduce the size of the OS partition:

  1. Open **GParted.**
  2. Switch to the SSD device (probably **/dev/sda**)
  3. Select the last partition. This is the partition of the Operating System.
  4. Resize the partition to the original size of the SD card.
  5. Create a partition for the remaining space of the SSD.  
    Format the partition as **ext4**. This is to make sure we get the best read and write performance.  
    For reference, the Rraspberry Pi 4 is capable of the following writing speeds: 
     
    
      * 85 mb/s to an external usb 3.0 SSD with an ext4 partition.
      * 26 mb/s to an external usb 3.0 SSD with an NTFS partition.
  6. Set the name of the partition to **pidvr**.

## <span id="Boot_from_the_SSD_drive">Boot from the SSD drive</span>

At this point, our SSD is now properly configured to be used as our boot device.

Follow these instructions to boot from the SSD:

  1. Shutdown the device
  2. Disconnect the power cable.
  3. Remove the SD card from the SD card slot.
  4. Connect the power cable to the Raspberry Pi.

## <span id="Uninstall_nonessential_software">Uninstall nonessential software</span>

Since we installed the **Raspberry Pi OS with desktop and recommended software** image, there are multiple software that are shipped with the image that we do not intend to use. Most importantly, some of them uses a lot of disk space.

Uninstall the following unneeded software:

  1. Open **Recommended Software** manager, which can be found in **Preferences** menu.
  2. Uncheck the following software 
      1. In **Education**, uncheck SmartSim
      2. In **Games**, uncheck them all
      3. In **Programming**, Uncheck Mathematica, Scratch, Scratch 3, Sense HAT emulator, Sonic Pi
  3. Click **Apply** button to uninstall

## <span id="Install_additional_software">Install additional software</span>

To allow management of the PiDVR, we will need to install other software.

### <span id="Argon_One_fan_script">Argon One fan script</span>

This is specific to our build since we are using the [Argon One][1] case. The instructions from <http://wagnerstechtalk.com/argonone/> properly explains how to install the scripts to support the Argon One power button and fan speed.

In summary, run the following commands in a terminal:

    curl https://download.argon40.com/argon1.sh | bash

### <span id="Other">Other</span>

The following list of programs can be installed manually in the terminal:

  * [hdparm][7], to perform read and write performance tests
  * [GNOME Disks][8], to get information about disks and partitions
  * [GNOME Partition Editor][9] (gparted), to resize and format partions.
  * [GSmartControl][10], to get SMART information about our disks.
  * [QDirStat][11], to calculate disk usage per directories.
  * [7-zip][12], to add support for *.7z archives in [Archiver][13] software.

The following instructions can install all software mentioned above:

    sudo apt-get update
    sudo apt-get install hdparm gnome-disk-utility gparted gsmartcontrol qdirstat p7zip-full

## <span id="Create_storage_directories_for_our_recordings">Create storage directories for our recordings</span>

The instructions in this section explains how to create our base storage directories.

As discussed above, we want tv recordings to be stored on the SSD in the **pidvr** partition which is automatically mounted at **/media/pi/pidvr**.

In directory **/media/pi/pidvr**, create the following directories:

  * **backup**, for storing backup images of the raspberry pi os
  * **recordings**, for storing our recordings, obviously
  * **shared**, for creating a Windows shared directory for easily transferring files from/to the raspberry pi. See next section below.

By default, these directories will only be writable (or accessible) for the **pi** user on the Raspberry Pi. This is a problem for our build since tvheadend run as **hts** user and _hts_ user won&#8217;t have access by default to our **recordings** directory. To allow anyone to have read and write access to these directories, enter the following command in a terminal:

    sudo chmod -R 7777 /media/pi.

_**Note**: by default, a partition permissions are inherited from its parent directory where the partition is mounted. In this case, the partition mounted at **/media/pi/pidvr** inherits the permissions from **/media/pi** directory._

A reboot of the Raspberry Pi may be required for the new partition is show up as writable for everyone.

## <span id="Install_Samba_SMBCIFS_support">Install Samba SMB/CIFS support</span>

By default, Raspberry Pi OS does not include CIFS/Samba support, but this can easily be added. The Raspberry Pi documentation has an article available at <https://www.raspberrypi.org/documentation/remote-access/samba.md> that explains how to proceed.

In summary, run the following commands in a terminal:

    sudo apt update
    sudo apt install -y samba samba-common-bin smbclient cifs-utils

_Note: During installation, if you have other samba servers on your network, choose no which is the default option._

To create shared directories that can be accessed by a Windows computer, edit the configuration file **/etc/samba/smb.conf** with the following command:

    sudo nano /etc/samba/smb.conf

and add the following new sections:

    # Create a read-only shared directory called 'recordings' to
    # easily export recording files outside of the raspberry pi.
    [recordings]
    comment = DVR recordings
    path = /media/pi/pidvr/recordings
    force user = pi
    public = yes
    writable = no
    
    # Create a read ans write shared directory called 'shared' to
    # easily transferring files from/to the raspberry pi.
    [shared]
    path = /media/pi/pidvr/shared
    force user = pi
    public = yes
    writable = yes
    create mask = 0777
    directory mask = 0777

Restart the samba daemon service for the changes to take effect:

    sudo systemctl restart smbd

## <span id="Run_Raspberry_Pi_Configuration_utility">Run Raspberry Pi Configuration utility</span>

The default configuration of the pi should be properly set for most users. For our usage, we need to change some of the configuration settings.

For example, the default hostname for the raspberry pi is **raspberrypi** which is a problem if you own multiple raspberry pies because the hostname of a device on a network must be unique for every device in order to be reachable by others. It is also good practice to change the hostname to something that represent the intended usage of the pi.

The **Raspberry Pi Configuration** application, which can be found on the **Preferences** menu of the Raspberry Pi Desktop, will allow you to change the required settings. Please change the following settings accordingly:

  1. In **System** tab, change the hostname to **pidvr**.
  2. In **Interfaces** tab, enable **SSH** and **VNC**.

## <span id="Install_Tvheadend">Install Tvheadend</span>

This is the main software for the build. You can find more information about tvheadend at <https://tvheadend.org/>.

There are already great guides that explains how to install and configure tvheadend. For example, [thepihut][14] and [pimylifeup][15] have great instruction guides.

In summary, run the following commands in a terminal to install tvheadend:

    sudo apt update
    sudo apt install -y tvheadend

_Note: During installation, you will need to provide a username and password for the tvheadend aministrator. You can use `pidvr` and `pidvr`._

## <span id="Tvheadend_initial_configuration_setup">Tvheadend initial configuration setup</span>

After installation, connect to the tvheadend web interface to configure the application and scan for channels. Head over to the following address:  
<http://pidvr:9981/>

### <span id="Welcome_1_of_2">Welcome (1 of 2)</span>

<div id="attachment_2561" style="width: 635px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01.png"><img aria-describedby="caption-attachment-2561" loading="lazy" class="size-full wp-image-2561" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01.png" alt="tvheadend - welcome page (1 or 2)" width="625" height="528" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01.png 625w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01.png 300w" sizes="(max-width: 625px) 100vw, 625px" /></a>
  
  <p id="caption-attachment-2561" class="wp-caption-text">
    tvheadend &#8211; welcome page (1 or 2)
  </p>
</div>

![][16] This first screen will require you to select a language the web interface and the electronic program guide (EPG):

Enter the following values:

  * English
  * French

Click **Save & Next** to get to the next page.

_Note: Since we actually changed the language of the web interface, the same page may be displayed when you first click_ **Save & Next**_. Click it again._

### <span id="Welcome_2_of_2">Welcome (2 of 2)</span>

![][17] 

<div id="attachment_2562" style="width: 620px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot02.png"><img aria-describedby="caption-attachment-2562" loading="lazy" class="size-full wp-image-2562" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot02.png" alt="tvheadend - welcome page (2 or 2)" width="610" height="617" /></a>
  
  <p id="caption-attachment-2562" class="wp-caption-text">
    tvheadend &#8211; welcome page (2 or 2)
  </p>
</div>

The next page allows you to configure the network access.

We are going to allow all network access by leaving the &#8216;Allowed network&#8217; field blank.

We are also going to bypass any logins by entering `*` in each of those fields.

Click **Save & Next** to get to the next page.

### <span id="Network_settings">Network settings</span>

<div id="attachment_2563" style="width: 620px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png"><img aria-describedby="caption-attachment-2563" loading="lazy" class="size-full wp-image-2563" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png" alt="tvheadend - network settings" width="610" height="691" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png 610w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png 132w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png 265w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03.png 593w" sizes="(max-width: 610px) 100vw, 610px" /></a>
  
  <p id="caption-attachment-2563" class="wp-caption-text">
    tvheadend &#8211; network settings
  </p>
</div>

![][18] The next screen configures the tuners.

Leave the _IPTV_ fields from _Network 1_ blank.

At this point, tbheadend should have already discovered both _HDHomeRun ATSC-T Tuner #0 and #1_ identified in &#8220;**Network 2**&#8221; and &#8220;**Network 3**&#8221; sections. Select **ATSC-T Network** in the _Network type_ fields for each network.

Click **Save & Next** to get to the next page.

### <span id="Assign_predefined_muxes_to_networks">Assign predefined muxes to networks</span>

<div id="attachment_2564" style="width: 620px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04.png"><img aria-describedby="caption-attachment-2564" loading="lazy" class="size-full wp-image-2564" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04.png" alt="tvheadend - muxes" width="610" height="399" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04.png 610w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04.png 300w" sizes="(max-width: 610px) 100vw, 610px" /></a>
  
  <p id="caption-attachment-2564" class="wp-caption-text">
    tvheadend &#8211; muxes
  </p>
</div>

We now have to set the &#8220;muxes&#8221;. To save you from manually entering muxes, Tvheadend includes predefined mux lists. For best results in Montreal area, select the following muxes: **United States: us-ATSC-center-frequencies-8VSB**

Click **Save & Next** to get to the next page.

### <span id="Scan_status">Scan status</span>

<div id="attachment_2565" style="width: 620px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a.png"><img aria-describedby="caption-attachment-2565" loading="lazy" class="size-full wp-image-2565" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a.png" alt="tvheadend - scan status" width="610" height="406" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a.png 610w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a.png 300w" sizes="(max-width: 610px) 100vw, 610px" /></a>
  
  <p id="caption-attachment-2565" class="wp-caption-text">
    tvheadend &#8211; scan status
  </p>
</div>

The scan will now commence. It will search for &#8220;muxes&#8221; and &#8220;services&#8221; that are distributed via those muxes. Note, a service is a TV channel. When the scan hits 100% you&#8217;ll be able to see how many muxes and services it&#8217;s picked up.

<div id="attachment_2566" style="width: 620px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b.png"><img aria-describedby="caption-attachment-2566" loading="lazy" class="size-full wp-image-2566" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b.png" alt="tvheadend - scan status (100% completed)" width="610" height="406" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b.png 610w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b.png 300w" sizes="(max-width: 610px) 100vw, 610px" /></a>
  
  <p id="caption-attachment-2566" class="wp-caption-text">
    tvheadend &#8211; scan status (100% completed)
  </p>
</div>

Click **Save & Next** to get to the next page

### <span id="Service_mapping">Service mapping</span>

<div id="attachment_2567" style="width: 618px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06.png"><img aria-describedby="caption-attachment-2567" loading="lazy" class="size-full wp-image-2567" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06.png" alt="tvheadend - service mapping" width="608" height="409" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06.png 608w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06.png 300w" sizes="(max-width: 608px) 100vw, 608px" /></a>
  
  <p id="caption-attachment-2567" class="wp-caption-text">
    tvheadend &#8211; service mapping
  </p>
</div>

Next on the wizard is service mapping. This step maps the services that your scan discovered to channels. If you are interested in adding all channels in your area, do not tick any checkbox. Otherwise, tick the three check boxes.

Click **Save & Next** to get to the next page.

### <span id="Finished">Finished</span>

<div id="attachment_2568" style="width: 618px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07.png"><img aria-describedby="caption-attachment-2568" loading="lazy" class="size-full wp-image-2568" src="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07.png" alt="tvheadend - setup finished" width="608" height="263" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07.png 608w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07.png 150w, http://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07.png 300w" sizes="(max-width: 608px) 100vw, 608px" /></a>
  
  <p id="caption-attachment-2568" class="wp-caption-text">
    tvheadend &#8211; setup finished
  </p>
</div>

The initial setup is finished. Click **Finish** to complete the

At this stage we like to reboot the Raspberry Pi. In the terminal use the following command to restart your Raspberry Pi:

    sudo reboot now

## <span id="Tvheadend_additional_configuration">Tvheadend additional configuration</span>

The following list are specific configuration settings that I like to set for tvheadend:

### <span id="Set_web_interface_level_to_Advanced_by_default">Set web interface level to Advanced by default</span>

  1. Go to _Configuration_, _General_, _Base_ tab.
  2. Set _User interface level_ to value **Advanced**.
  3. Click on **Save** when done.

### <span id="Test_for_tvheadend_has_access_to_8216recordings8217_directory">Test for tvheadend has access to &#8216;recordings&#8217; directory</span>

tvheadend runs as user **hts**. To test read and write access from **hts** user perspective, type the following in a terminal:

    sudo su hts
    cd /media/pi/pidvr/recordings
    touch hts_test_file
    rm hts_test_file

The commands specified above should **not** output any error like the following:

    touch: cannot touch 'hts_test_file': Permission denied

### <span id="Setup_preferred_recordings_settings">Setup preferred recordings settings</span>

  1. Go to _Configuration_, _Recording_, _Digital Video Recorder Profiles_ tab.
  2. Click on the _Default profile_.
  3. Set _Recording system path_ to value **/media/pi/pidvr/recordings**.
  4. Set **Pre-recording padding** to 1 min.
  5. Set **Post-recording padding** to 3 min.
  6. Uncheck **Skip commercials** options.
  7. Check **Include date in filename**, **Include time in filename** and **Use Windows-compatible filenames** options.
  8. Click on **Save** when done.

### <span id="Enable_Timeshift">Enable Timeshift</span>

Timeshift is disabled by default and needs to be enabled to get the maximum out of tvheadend.

  1. Go to _Configuration_, _Recording_, _Timeshift_ tab.
  2. Switch to **Expert mode**. This is to work around a bug explained [here][19] and [here][20].
  3. Check **enabled**.
  4. Set _Storage path_ to value **/media/pi/pidvr/recordings**.
  5. Set _Maximum size (MB)_ to value **4096**.
  6. Check _**On-demand (no first rewind)**_ and _**Fit to RAM (cut rewind)**_.
  7. Click on **Save** when done.

### <span id="Set_Network_Character_set">Set Network Character set</span>

Montreal channels have the EPG encoding using UTF-8. The network character encoding must be specified manually.

  1. Go to _Configuration_, _DVB Inputs_, _Networks_ tab.
  2. Select the default network created by the first scan (named _ATSC-T Network_).
  3. Click **edit** button.
  4. Change the name of the network (i.e. _My ATSC Network_)
  5. Set _Character set_ to value **UTF-8**.
  6. Click on **Save**.
  7. * * *Switch to 
    
    _Muxes_ tab.
  8. Select all available muxes: click on the first mux and press _CTRL+A_.
  9. Click **edit** button.
 10. Check _Character set_ in Advanced Settings.
 11. Set _Character set_ to value **UTF-8**.
 12. Click on **Save**.
 13. * * *Switch to 
    
    _Services_ tab.
 14. Select all available services: click on the first service and press _CTRL+A_.
 15. Click **edit** button.
 16. Switch to _Export_ view level.
 17. Check _Character set_ in Advanced Settings.
 18. Set _Character set_ to value **UTF-8**.
 19. Click on **Save**.

### <span id="Map_desired_services_as_channels">Map desired services as channels</span>

If you did not mapped all services as channels during first configuration, now is the time to do it.

For Montreal area, here is the list of French channels:

  * Radio-Canada CBFT-DT
  * TVA CFTM-DT
  * Noovo CFJP-DT
  * Télé-Québec CJNT

  1. Go to _Configuration_, _DVB Inputs_, _Services_ tab.
  2. Select all available services: click on the first service and press _CTRL+A_.
  3. Click **edit** button.
  4. Check _Enabled_ setting in _Basic Settings_ and **uncheck** the value.
  5. Click on **Save**.
  6. Check only the your desired channels that you want to map
  7. Click on **Save**.
  8. Click on **Map Selected** then **Map selected services**, a new window will open
  9. Uncheck **Create type-based tags**.
 10. Click on **Map sercices**.
 11. Wait for the mapping process to end.

### <span id="Change_channel_identifiers_to_meaningful_names">Change channel identifiers to meaningful names</span>

This is for changing the name of the channels from CBFT (or something) to the actual name of the tv network that owns these channels.

  1. Go to _Configuration_, _Channel / EPG_, _Channels_ tab.
  2. Double click the name of each channel that you need to rename
  3. Click on **Save** when done.

For example:

  * Radio-Canada &#8211; CBFT-DT
  * TVA &#8211; CFTM-DT
  * Noovo &#8211; CFJP-DT
  * Télé-Québec &#8211; CJNT

### <span id="UTF-8_characters_in_Electronic_Program_Guide_EPG_8211_bug">UTF-8 characters in Electronic Program Guide (EPG) &#8211; bug</span>

![][21] The tv guide seems to be still using non-utf8 characters. This is still an open issue and I have not yet figured out a way to solve the issue:

[<img loading="lazy" class="size-full wp-image-2569 aligncenter" src="http://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png" alt="" width="193" height="293" srcset="http://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png 193w, http://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png 99w" sizes="(max-width: 193px) 100vw, 193px" />][22] 

## <span id="Configure_Kodi_to_connect_to_tvheadend">Configure Kodi to connect to tvheadend</span>

The following instructions defines how to connect Kodi with tvheadend to view recordings:

### <span id="Install_tvheadend_add-on">Install tvheadend add-on</span>

  1. Open _Kodi_.
  2. Go to **Settings**.
  3. Select **Add-ons**.
  4. Select **Install from repository**.
  5. Select **PVR Clients** category.
  6. Select **Tvheadend HTSP Client**.
  7. Select **Install** and wait for the add-on to install.
  8. Select **Tvheadend HTSP Client** (again).
  9. Select **Configure**.
 10. Set _tvheadend hostname_ to **pidvr**.
 11. Click on **OK** when done.

 [1]: https://www.argon40.com/argon-one-raspberry-pi-4-case.html
 [2]: https://www.silicondust.com/
 [3]: https://www.google.com/search?q=HDHR3-US&amp;source=lnms&amp;tbm=isch&amp;sa=X&amp;ved=2ahUKEwjquKyuvsbuAhWkrFkKHXbmCLMQ_AUoA3oECAEQBQ&amp;biw=1920&amp;bih=927
 [4]: https://www.google.com/search?q=Antennas+Direct+Clearstream+4+antenna
 [5]: https://www.raspberrypi.org/documentation/configuration/raspi-config.md
 [6]: https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711_bootloader_config.md
 [7]: https://en.wikipedia.org/wiki/Hdparm
 [8]: https://en.wikipedia.org/wiki/GNOME_Disks
 [9]: https://en.wikipedia.org/wiki/GParted
 [10]: https://gsmartcontrol.sourceforge.io/home/
 [11]: https://github.com/shundhammer/qdirstat
 [12]: https://www.7-zip.org/
 [13]: https://magpi.raspberrypi.org/articles/unzip-and-uncompress-files-on-a-raspberry-pi
 [14]: https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-stream-digital-tv-with-the-raspberry-pi-tv-hat
 [15]: https://pimylifeup.com/raspberry-pi-tvheadend/
 [16]: RackMultipart20210314-4-ej0w6x_html_69043a9e7dd44345.png
 [17]: RackMultipart20210314-4-ej0w6x_html_8ff4b1990405bb00.png
 [18]: RackMultipart20210314-4-ej0w6x_html_40136d095fe9be97.png
 [19]: https://tvheadend.org/boards/5/topics/29304
 [20]: https://forum.kodi.tv/showthread.php?tid=314837
 [21]: RackMultipart20210314-4-ej0w6x_html_16af1b06ba9c6ad8.png
 [22]: http://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png