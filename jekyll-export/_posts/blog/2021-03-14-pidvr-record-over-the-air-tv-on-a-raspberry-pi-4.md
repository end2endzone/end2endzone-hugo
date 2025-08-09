---
id: 2551
title: 'PiDVR Record over the air TV on a Raspberry Pi 4'
date: '2021-03-14T15:40:03+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=2551'
permalink: '/?p=2551'
hits:
    - '1283'
image: /wp-content/uploads/2021/03/PiDVR-Record-over-the-air-TV-on-a-Raspberry-Pi-4.jpg
categories:
    - Other
tags:
    - english
    - 'Raspberry Pi'
---

# About the project

The following project explains how I used a Raspberry Pi 4 to create a personal digital video recorder to record over-the-air tv.

# Required Hardware

This project requires the following hardware:

- Raspberry Pi 4 (with the required parts) 
    - 4GB of ram
    - A 16GB SD card
    - A micro HDMI cable
    - Monitor with HDMI input
    - A 15.3W USB-C Power Supply (3A @ 5v power supply)
    - Raspberry Pi 4 case. Preferably a passive cooling case for noise consideration.  
        I used the [Argon One](https://www.argon40.com/argon-one-raspberry-pi-4-case.html) case.
- An HDHomeRun Dual tuner from [Silicondust](https://www.silicondust.com/). The oldest model will do. For this build, I used the [*HDHR3-US*](https://www.google.com/search?q=HDHR3-US&amp;source=lnms&amp;tbm=isch&amp;sa=X&amp;ved=2ahUKEwjquKyuvsbuAhWkrFkKHXbmCLMQ_AUoA3oECAEQBQ&amp;biw=1920&amp;bih=927) which dates back to 2012-2013.
- An over-the-air tv antenna for ATSC signals. For this build I use the [Clearstream 4](https://www.google.com/search?q=Antennas+Direct+Clearstream+4+antenna) antenna by Antennas Direct.
- 50ft to 100ft Coaxial Cable, 18AWG, 75 Ohm to connect the antenna to the HDHomeRun.
- External Solid State Drive (SSD) with about 500Gb in size.
- USB 3.0 to SATA Converter Adapter - Look for one that has UASP support.

# Software list

This section defines the list of required software for the project. Follow the instructions in the next section to know when and how to install them.

1. Download  ***Raspberry Pi OS with desktop and recommended software***  from <https://www.raspberrypi.org/software/operating-systems/>
2. Download the  ***Raspberry Pi Imager***  to write the  ***Raspberry Pi OS***  image to an SD card.

# Instructions

## Write Raspberry Pi OS image file to your SD card

1. Launch the  ***Raspberry Pi Imager***  for writing the  ***Raspberry Pi OS***  image file to your SD card. There are plenty of online tutorial for this operation
2. Turn on the Raspberry Pi and follow "first launch" instructions on screen.

## Update the Raspberry Pi firmware

The oldest Raspberry Pi 4 models that originally shipped uses an out of date firmware. Most of all, they do not support booting from an SSD drive connected through USB. Updating the firmware provides better thermals and USB boot support.

Jeff Geerling has written an excellent guide on how to upgrade the Raspberry Pi 4's firmware.  
Follow his instructions available at:  
<https://www.jeffgeerling.com/blog/2019/upgrade-raspberry-pi-4s-firmware-bootloader-better-thermals>.

In summary, run the following commands in a terminal:

```
sudo apt update
sudo apt -y full-upgrade
sudo apt install -y rpi-eeprom
sudo rpi-eeprom-update
sudo reboot
```

## Check that USB 3.0 to SATA adaptor has UASP support

UASP stands for USB Attached SCSI Protocol. In very few words, it is a protocol used in USB storage devices and adapters that performs better that the traditional USB 1.1 protocol.

Jeff Geerling has written an excellent guide on how to verify if your adaptor is UASP compatible.  
Follow his instructions available at:  
<https://www.jeffgeerling.com/blog/2020/uasp-makes-raspberry-pi-4-disk-io-50-faster>.

In summary, connect your ssd drive and run the following commands in a terminal:

```
lsusb -t
```

From Jeff Geerling article:

*This command lists all the USB devices in a tree, and for each of the hard drives, you should see a `Driver` listed. If it's `uas` , then your drive supports UASP and you'll get the best speed. If it's `usb-storage` , then it's using the older BOT protocol and you won't see the full potential.*

## Enable USB boot on the Raspberry Pi

A USB 3.0 Flash Drive or an USB 3.0 SSD is almost always preferable to an SD Card when booting the Raspberry Pi OS. The thing about booting Operating Systems is that 4K Read/Write Speed dictate the experience more than the sequential Read/Write Speed (the usual advertised speed). SD card usually have bad performance regarding 4K Read/Write speed.

On the Raspberry Pi4, you can specify whether to boot from USB or network if the SD card isn't inserted.

The **raspi-config** utility can enable USB Booting on the Raspberry Pi 4:

1. Launch the application in a terminal.
2. Enter **Advanced Options** section.
3. Enter **Boot Order** section.
4. Select **USB Boot** option.

See [raspi-config.md](https://www.raspberrypi.org/documentation/configuration/raspi-config.md) documentation and [bcm2711\_bootloader\_config.md](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711_bootloader_config.md) documentation on <https://www.raspberrypi.org/> for more details.

## Move Raspberry Pi OS from SD card to SSD drive

Running the Raspberry Pi 4 on an SD card has great read and write speed. Opening an application feels good and we do not have to wait forever to get us going. However, an SD card cannot sustain the passage of time. Our build requires to run the raspberry pi 24/7. Sooner or later the SD card will get corrupted during a write operation and then our precious setup we created won't be able to boot from the card anymore.

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

## Shrink the Operating System partition

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
    - 85 mb/s to an external usb 3.0 SSD with an ext4 partition.
    - 26 mb/s to an external usb 3.0 SSD with an NTFS partition.
6. Set the name of the partition to **pidvr**.

## Boot from the SSD drive

At this point, our SSD is now properly configured to be used as our boot device.

Follow these instructions to boot from the SSD:

1. Shutdown the device
2. Disconnect the power cable.
3. Remove the SD card from the SD card slot.
4. Connect the power cable to the Raspberry Pi.

## Uninstall nonessential software

Since we installed the **Raspberry Pi OS with desktop and recommended software** image, there are multiple software that are shipped with the image that we do not intend to use. Most importantly, some of them uses a lot of disk space.

Uninstall the following unneeded software:

1. Open **Recommended Software** manager, which can be found in **Preferences** menu.
2. Uncheck the following software 
    1. In **Education**, uncheck SmartSim
    2. In **Games**, uncheck them all
    3. In **Programming**, Uncheck Mathematica, Scratch, Scratch 3, Sense HAT emulator, Sonic Pi
3. Click **Apply** button to uninstall

## Install additional software

To allow management of the PiDVR, we will need to install other software.

### Argon One fan script

This is specific to our build since we are using the [Argon One](https://www.argon40.com/argon-one-raspberry-pi-4-case.html) case. The instructions from <http://wagnerstechtalk.com/argonone/> properly explains how to install the scripts to support the Argon One power button and fan speed.

In summary, run the following commands in a terminal:

```
curl https://download.argon40.com/argon1.sh | bash
```

### Other

The following list of programs can be installed manually in the terminal:

- [hdparm](https://en.wikipedia.org/wiki/Hdparm), to perform read and write performance tests
- [GNOME Disks](https://en.wikipedia.org/wiki/GNOME_Disks), to get information about disks and partitions
- [GNOME Partition Editor](https://en.wikipedia.org/wiki/GParted) (gparted), to resize and format partions.
- [GSmartControl](https://gsmartcontrol.sourceforge.io/home/), to get SMART information about our disks.
- [QDirStat](https://github.com/shundhammer/qdirstat), to calculate disk usage per directories.
- [7-zip](https://www.7-zip.org/), to add support for \*.7z archives in [Archiver](https://magpi.raspberrypi.org/articles/unzip-and-uncompress-files-on-a-raspberry-pi) software.

The following instructions can install all software mentioned above:

```
sudo apt-get update
sudo apt-get install hdparm gnome-disk-utility gparted gsmartcontrol qdirstat p7zip-full
```

## Create storage directories for our recordings

The instructions in this section explains how to create our base storage directories.

As discussed above, we want tv recordings to be stored on the SSD in the **pidvr** partition which is automatically mounted at **/media/pi/pidvr**.

In directory **/media/pi/pidvr**, create the following directories:

- **backup**, for storing backup images of the raspberry pi os
- **recordings**, for storing our recordings, obviously
- **shared**, for creating a Windows shared directory for easily transferring files from/to the raspberry pi. See next section below.

By default, these directories will only be writable (or accessible) for the **pi** user on the Raspberry Pi. This is a problem for our build since tvheadend run as **hts** user and *hts* user won't have access by default to our **recordings** directory. To allow anyone to have read and write access to these directories, enter the following command in a terminal:

```
sudo chmod -R 7777 /media/pi.
```

***Note**: by default, a partition permissions are inherited from its parent directory where the partition is mounted. In this case, the partition mounted at **/media/pi/pidvr** inherits the permissions from **/media/pi** directory.*

A reboot of the Raspberry Pi may be required for the new partition is show up as writable for everyone.

## Install Samba SMB/CIFS support

By default, Raspberry Pi OS does not include CIFS/Samba support, but this can easily be added. The Raspberry Pi documentation has an article available at <https://www.raspberrypi.org/documentation/remote-access/samba.md> that explains how to proceed.

In summary, run the following commands in a terminal:

```
sudo apt update
sudo apt install -y samba samba-common-bin smbclient cifs-utils
```

*Note: During installation, if you have other samba servers on your network, choose no which is the default option.*

To create shared directories that can be accessed by a Windows computer, edit the configuration file **/etc/samba/smb.conf** with the following command:

```
sudo nano /etc/samba/smb.conf
```

and add the following new sections:

```
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
```

Restart the samba daemon service for the changes to take effect:

```
sudo systemctl restart smbd
```

## Run Raspberry Pi Configuration utility

The default configuration of the pi should be properly set for most users. For our usage, we need to change some of the configuration settings.

For example, the default hostname for the raspberry pi is **raspberrypi** which is a problem if you own multiple raspberry pies because the hostname of a device on a network must be unique for every device in order to be reachable by others. It is also good practice to change the hostname to something that represent the intended usage of the pi.

The **Raspberry Pi Configuration** application, which can be found on the **Preferences** menu of the Raspberry Pi Desktop, will allow you to change the required settings. Please change the following settings accordingly:

1. In **System** tab, change the hostname to **pidvr**.
2. In **Interfaces** tab, enable **SSH** and **VNC**.

## Install Tvheadend

This is the main software for the build. You can find more information about tvheadend at <https://tvheadend.org/>.

There are already great guides that explains how to install and configure tvheadend. For example, [thepihut](https://thepihut.com/blogs/raspberry-pi-tutorials/how-to-stream-digital-tv-with-the-raspberry-pi-tv-hat) and [pimylifeup](https://pimylifeup.com/raspberry-pi-tvheadend/) have great instruction guides.

In summary, run the following commands in a terminal to install tvheadend:

```
sudo apt update
sudo apt install -y tvheadend
```

*Note: During installation, you will need to provide a username and password for the tvheadend aministrator. You can use `pidvr` and `pidvr`.*

## Tvheadend initial configuration setup

After installation, connect to the tvheadend web interface to configure the application and scan for channels. Head over to the following address:  
<http://pidvr:9981/>

### Welcome (1 of 2)

\[caption id="attachment\_2561" align="aligncenter" width="625"\][![tvheadend - welcome page (1 or 2)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot01-1.png) tvheadend - welcome page (1 or 2)\[/caption\]

![](RackMultipart20210314-4-ej0w6x_html_69043a9e7dd44345.png)

This first screen will require you to select a language the web interface and the electronic program guide (EPG):

Enter the following values:

- English
- French

Click **Save &amp; Next** to get to the next page.

*Note: Since we actually changed the language of the web interface, the same page may be displayed when you first click* **Save &amp; Next***. Click it again.*

### Welcome (2 of 2)

![](RackMultipart20210314-4-ej0w6x_html_8ff4b1990405bb00.png)

\[caption id="attachment\_2562" align="aligncenter" width="610"\][![tvheadend - welcome page (2 or 2)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot02-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot02-1.png) tvheadend - welcome page (2 or 2)\[/caption\]

The next page allows you to configure the network access.

We are going to allow all network access by leaving the 'Allowed network' field blank.

We are also going to bypass any logins by entering `*` in each of those fields.

Click **Save &amp; Next** to get to the next page.

### Network settings

\[caption id="attachment\_2563" align="aligncenter" width="610"\][![tvheadend - network settings](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot03-1.png) tvheadend - network settings\[/caption\]

![](RackMultipart20210314-4-ej0w6x_html_40136d095fe9be97.png)

The next screen configures the tuners.

Leave the *IPTV* fields from *Network 1* blank.

At this point, tbheadend should have already discovered both *HDHomeRun ATSC-T Tuner #0 and #1* identified in "**Network 2**" and "**Network 3**" sections. Select **ATSC-T Network** in the *Network type* fields for each network.

Click **Save &amp; Next** to get to the next page.

### Assign predefined muxes to networks

\[caption id="attachment\_2564" align="aligncenter" width="610"\][![tvheadend - muxes](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot04-1.png) tvheadend - muxes\[/caption\]

We now have to set the "muxes". To save you from manually entering muxes, Tvheadend includes predefined mux lists. For best results in Montreal area, select the following muxes: **United States: us-ATSC-center-frequencies-8VSB**

Click **Save &amp; Next** to get to the next page.

### Scan status

\[caption id="attachment\_2565" align="aligncenter" width="610"\][![tvheadend - scan status](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05a-1.png) tvheadend - scan status\[/caption\]

The scan will now commence. It will search for "muxes" and "services" that are distributed via those muxes. Note, a service is a TV channel. When the scan hits 100% you'll be able to see how many muxes and services it's picked up.

\[caption id="attachment\_2566" align="aligncenter" width="610"\][![tvheadend - scan status (100% completed)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot05b-1.png) tvheadend - scan status (100% completed)\[/caption\]

Click **Save &amp; Next** to get to the next page

### Service mapping

\[caption id="attachment\_2567" align="aligncenter" width="608"\][![tvheadend - service mapping](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot06-1.png) tvheadend - service mapping\[/caption\]

Next on the wizard is service mapping. This step maps the services that your scan discovered to channels. If you are interested in adding all channels in your area, do not tick any checkbox. Otherwise, tick the three check boxes.

Click **Save &amp; Next** to get to the next page.

### Finished

\[caption id="attachment\_2568" align="aligncenter" width="608"\][![tvheadend - setup finished](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07-1.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/tvheadend_screenshot07-1.png) tvheadend - setup finished\[/caption\]

The initial setup is finished. Click **Finish** to complete the

At this stage we like to reboot the Raspberry Pi. In the terminal use the following command to restart your Raspberry Pi:

```
sudo reboot now
```

## Tvheadend additional configuration

The following list are specific configuration settings that I like to set for tvheadend:

### Set web interface level to Advanced by default

1. Go to *Configuration*, *General*, *Base* tab.
2. Set *User interface level* to value **Advanced**.
3. Click on **Save** when done.

### Test for tvheadend has access to 'recordings' directory

tvheadend runs as user **hts**. To test read and write access from **hts** user perspective, type the following in a terminal:

```
sudo su hts
cd /media/pi/pidvr/recordings
touch hts_test_file
rm hts_test_file
```

The commands specified above should **not** output any error like the following:

```
touch: cannot touch 'hts_test_file': Permission denied
```

### Setup preferred recordings settings

1. Go to *Configuration*, *Recording*, *Digital Video Recorder Profiles* tab.
2. Click on the *Default profile*.
3. Set *Recording system path* to value **/media/pi/pidvr/recordings**.
4. Set **Pre-recording padding** to 1 min.
5. Set **Post-recording padding** to 3 min.
6. Uncheck **Skip commercials** options.
7. Check **Include date in filename**, **Include time in filename** and **Use Windows-compatible filenames** options.
8. Click on **Save** when done.

### Enable Timeshift

Timeshift is disabled by default and needs to be enabled to get the maximum out of tvheadend.

1. Go to *Configuration*, *Recording*, *Timeshift* tab.
2. Switch to **Expert mode**. This is to work around a bug explained [here](https://tvheadend.org/boards/5/topics/29304) and [here](https://forum.kodi.tv/showthread.php?tid=314837).
3. Check **enabled**.
4. Set *Storage path* to value **/media/pi/pidvr/recordings**.
5. Set *Maximum size (MB)* to value **4096**.
6. Check ***On-demand (no first rewind)*** and ***Fit to RAM (cut rewind)***.
7. Click on **Save** when done.

### Set Network Character set

Montreal channels have the EPG encoding using UTF-8. The network character encoding must be specified manually.

1. Go to *Configuration*, *DVB Inputs*, *Networks* tab.
2. Select the default network created by the first scan (named *ATSC-T Network*).
3. Click **edit** button.
4. Change the name of the network (i.e. *My ATSC Network*)
5. Set *Character set* to value **UTF-8**.
6. Click on **Save**.
7. ---
    
    Switch to *Muxes* tab.
8. Select all available muxes: click on the first mux and press *CTRL+A*.
9. Click **edit** button.
10. Check *Character set* in Advanced Settings.
11. Set *Character set* to value **UTF-8**.
12. Click on **Save**.
13. ---
    
    Switch to *Services* tab.
14. Select all available services: click on the first service and press *CTRL+A*.
15. Click **edit** button.
16. Switch to *Export* view level.
17. Check *Character set* in Advanced Settings.
18. Set *Character set* to value **UTF-8**.
19. Click on **Save**.

### Map desired services as channels

If you did not mapped all services as channels during first configuration, now is the time to do it.

For Montreal area, here is the list of French channels:

- Radio-Canada CBFT-DT
- TVA CFTM-DT
- Noovo CFJP-DT
- Télé-Québec CJNT

1. Go to *Configuration*, *DVB Inputs*, *Services* tab.
2. Select all available services: click on the first service and press *CTRL+A*.
3. Click **edit** button.
4. Check *Enabled* setting in *Basic Settings* and **uncheck** the value.
5. Click on **Save**.
6. Check only the your desired channels that you want to map
7. Click on **Save**.
8. Click on **Map Selected** then **Map selected services**, a new window will open
9. Uncheck **Create type-based tags**.
10. Click on **Map sercices**.
11. Wait for the mapping process to end.

### Change channel identifiers to meaningful names

This is for changing the name of the channels from CBFT (or something) to the actual name of the tv network that owns these channels.

1. Go to *Configuration*, *Channel / EPG*, *Channels* tab.
2. Double click the name of each channel that you need to rename
3. Click on **Save** when done.

For example:

- Radio-Canada - CBFT-DT
- TVA - CFTM-DT
- Noovo - CFJP-DT
- Télé-Québec - CJNT

### UTF-8 characters in Electronic Program Guide (EPG) - bug

![](RackMultipart20210314-4-ej0w6x_html_16af1b06ba9c6ad8.png)

The tv guide seems to be still using non-utf8 characters. This is still an open issue and I have not yet figured out a way to solve the issue:

[![](https://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png)](https://www.end2endzone.com/wp-content/uploads/2021/03/EPG-utf-8-bug.png)

## Configure Kodi to connect to tvheadend

The following instructions defines how to connect Kodi with tvheadend to view recordings:

### Install tvheadend add-on

1. Open *Kodi*.
2. Go to **Settings**.
3. Select **Add-ons**.
4. Select **Install from repository**.
5. Select **PVR Clients** category.
6. Select **Tvheadend HTSP Client**.
7. Select **Install** and wait for the add-on to install.
8. Select **Tvheadend HTSP Client** (again).
9. Select **Configure**.
10. Set *tvheadend hostname* to **pidvr**.
11. Click on **OK** when done.