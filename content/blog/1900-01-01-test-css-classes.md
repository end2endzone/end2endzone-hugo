---
title: 'test css classes'
author: end2end
date: 1900-01-01
categories:
  - test
tags:
  - test
draft: true
---

hey this is my text default color

[this is a link to google.com](http://google.com)

this is another line of text

&nbsp;
&nbsp;

**Heading:**

# h1
Text in header 1 [this is a link to google.com](http://google.com)

## h2
Text in header 2 [this is a link to google.com](http://google.com)

### h3
Text in header 3 [this is a link to google.com](http://google.com)

#### h4
Text in header 4 [this is a link to google.com](http://google.com)

##### h5
Text in header 5 [this is a link to google.com](http://google.com)

###### h6
Text in header 6 [this is a link to google.com](http://google.com)

![Flowers](/wp-content/uploads/2015/01/MSBuildReorder-How-to-reorder-a-Visual-Studio-build-log-for-easy-reading.png)

# Custom css classes

### postedit
{{< postedit >}}
  EDIT: Source code is now moved to GitHub. Source code can be downloaded from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder).
{{< /postedit >}}


### pleasenote
{{< pleasenote >}}
  NOTE: Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder/releases).
{{< /pleasenote >}}


### renamep
{{< renamep >}}
  IMG_8823.jpg  Trip to Hawaii with John (2007) 01.jpg</br> IMG_8824.jpg  Trip to Hawaii with John (2007) 02.jpg<br /> IMG_8825.jpg  Trip to Hawaii with John (2007) 03.jpg<br /> ...<br /> IMG_8899.jpg  Trip to Hawaii with John (2007) 77.jpg
{{< /renamep >}}


### buttons
Click on the {{% windows-button3d %}}Play{{% /windows-button3d %}} button then on the {{% windows-button3d %}}Scan{{% /windows-button3d %}} button to activate the process.


### image captions

[![HDHomeRun Tv Dump - Main Window showing channels](https://www.end2endzone.com/wp-content/uploads/2015/02/HDHomeRun-Tv-Dump-Main-Window-showing-channels.png "HDHomeRun Tv Dump - Main Window showing channels")](https://www.end2endzone.com/wp-content/uploads/2015/02/HDHomeRun-Tv-Dump-Main-Window-showing-channels.png)


### image gallery
{{% image-gallery %}}
[![HDHomeRun Tv Dump - Main Window showing channels](https://www.end2endzone.com/wp-content/uploads/2015/02/HDHomeRun-Tv-Dump-Main-Window-showing-channels.png "HDHomeRun Tv Dump - Main Window showing channels")](https://www.end2endzone.com/wp-content/uploads/2015/02/HDHomeRun-Tv-Dump-Main-Window-showing-channels.png)
{{% /image-gallery %}}

# Forms

<form id="comment-form" class="new-comment" method="POST">
  <input required="" name="fields[name]" type="text" placeholder="Your Name">
  <textarea required="" name="fields[body]" placeholder="Your Message" rows="10"></textarea>

  **Thanks for your comment! It will be shown on the site once it has been approved.**
  **Sorry, there was an error with your submission. Please make sure all required fields have been completed and try again.**

  <button type="button" id="comment-form-submit" class="button">Submit</button>
  <button type="button" id="comment-form-submitted" class="hidden button" disabled="">Submitted</button>
  <button type="reset" id="comment-form-reset" class="button">Reset</button>
</form>


# Tables

HTML 5 table:
| Company                      | Contact          | Country  |
|------------------------------|------------------|----------|
| Alfreds Futterkiste          | Maria Anders     | Germany  |
| Centro comercial Moctezuma   | Francisco Chang  | Mexico   |
| Ernst Handel                 | Roland Mendel    | Austria  |
| Island Trading               | Helen Bennett    | UK       |
| Laughing Bacchus Winecellars | Yoshi Tannamuri  | Canada   |
| Magazzini Alimentari Riuniti | Giovanni Rovelli | Italy    |


Table with no header (all first row has empty cells):
|||||
|----------|----------|----------|----------|
| First    | john     | $20,000  | $10,000  |
| Second   | david    | $30,000  | $15,000  |
| Last     | marry    | $40,000  | $15,000  |

RC transmitter channels:

{{< rc-channels >}}
||||
|---|---|---|
| CH 1 | : | Throttle |
| CH 2 | : | Rudder |
| CH 3 | : | Ailerons |
| CH 4 | : | Elevator |
| CH 5 | : | Flight mode |
| CH 6 | : | ??? |
{{< /rc-channels >}}

{{< rc-channels >}}
||||
|---|---|---|
| High | = | 100% |
| Low | = | -100% |
| Offset | = | 0% |
{{< /rc-channels >}}


# Image Galleries (as tables)

{{< image-gallery >}}
| <!-- -->                                                                                                                                                                                  | <!-- -->                                                                                                                                                                                  |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2446_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538053182/in/album-72157686816329321/) | [<br /> ![](/wp-content/uploads/2015/08/IMG_2488_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538049222/in/album-72157686816329321/) |
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2526_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538046922/in/album-72157686816329321/) | [<br /> ![](/wp-content/uploads/2015/08/IMG_2549_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/36900405873/in/album-72157686816329321/) |
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2567_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538045602/in/album-72157686816329321/) |                                                                                                                                                                                           |
{{< /image-gallery >}}


# Other
