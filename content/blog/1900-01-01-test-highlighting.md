---
title: 'Test highlighting'
author: end2end
date: 1900-01-01
categories:
  - test
tags:
  - test
draft: true
---

# Tables

Tables aren't part of the core Markdown spec, but Hugo supports supports them out-of-the-box.

   Name | Age
--------|------
    Bob | 27
  Alice | 23


## Inline Markdown within tables

| Inline     | Markdown  | In                | Table      |
| ---------- | --------- | ----------------- | ---------- |
| *italics*  | **bold**  | ~~strikethrough~~ | `code`     |


# Code fences

## cpp
```cpp
// Simple C++ program to display "Hello World"
// Header file for input output functions
#include <iostream>
using namespace std;
// main function - where the execution of program begins
int main()
{
    // prints hello world
    cout<<"Hello World";
    return 0;
}
```

## txt
```txt
Roses are red,
Violets are blue,
Sugar is sweet,
And so are you.
```

## html
```html
<html>
 <head>
 </head>
 <body>
   <h1>Hello World<h1>
 </body>
</html>
```

## unspecified
```
The greatest glory in living lies not in never falling, but in rising every time we fall. -Nelson Mandela
The way to get started is to quit talking and begin doing. -Walt Disney
Your time is limited, so don't waste it living someone else's life. Don't be trapped by dogma – which is living with the results of other people's thinking. -Steve Jobs
If life were predictable it would cease to be life, and be without flavor. -Eleanor Roosevelt
If you look at what you have in life, you'll always have more. If you look at what you don't have in life, you'll never have enough. -Oprah Winfrey
If you set your goals ridiculously high and it's a failure, you will fail above everyone else's success. -James Cameron
Life is what happens when you're busy making other plans. -John Lennon
```

## hardcoded HTML pre tags
<pre>
OffsetTravel = (switch default travel (see below)) - Offset
if OffsetTravel &lt; 0
  SwitchMixValue = OffsetTravel / 100 * Low rate
else
  SwitchMixValue = OffsetTravel / 100 * High rate
</pre>


## static file with 'hightlight-static-file' shortcode
{{< hightlight-static-file file="/static/wp-content/hello-world.cpp" lang="cpp" >}}


## highlight shortcode (rendered by Hugo at build-time / compile-time)
{{< highlight go "linenos=table,hl_lines=3 5-7,linenostart=199" >}}
// Simple C++ program to display "Hello World"
// Header file for input output functions
#include <iostream>
using namespace std;
// main function - where the execution of program begins
int main()
{
    // prints hello world
    cout<<"Hello World";
    return 0;
}
{{< /highlight >}}


## with additional custom css classes (ie: 'postedit')
```cpp {.postedit}
// Simple C++ program to display "Hello World"
// Header file for input output functions
#include <iostream>
using namespace std;
// main function - where the execution of program begins
int main()
{
    // prints hello world
    cout<<"Hello World";
    return 0;
}
```


## wrapped in linenumbers shortcode
{{< linenumbers >}}
```cpp
// Simple C++ program to display "Hello World"
// Header file for input output functions
#include <iostream>
using namespace std;
// main function - where the execution of program begins
int main()
{
    // prints hello world
    cout<<"Hello World";
    return 0;
}
```
{{< /linenumbers >}}

{{< linenumbers >}}
```js
console.log("Hello, World!");
```
{{< /linenumbers >}}

{{< linenumbers >}}
```html
<!DOCTYPE html>
<html>
<head>
  <title>Hello World Page</title>
</head>
<body>
  <h1>Hello, World!</h1>
  <p>This is my first HTML page.</p>
</body>
</html>
```
{{< /linenumbers >}}


# Image Galleries (as tables)

{{< image-gallery >}}
| <!-- -->                                                                                                                                                                                  | <!-- -->                                                                                                                                                                                  |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2446_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538053182/in/album-72157686816329321/) | [<br /> ![](/wp-content/uploads/2015/08/IMG_2488_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538049222/in/album-72157686816329321/) |
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2526_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538046922/in/album-72157686816329321/) | [<br /> ![](/wp-content/uploads/2015/08/IMG_2549_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/36900405873/in/album-72157686816329321/) |
| [<br /> ![](/wp-content/uploads/2015/08/IMG_2567_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538045602/in/album-72157686816329321/) |                                                                                                                                                                                           |
{{< /image-gallery >}}


# Image Galleries (images in a div)

{{< image-gallery >}}
[![](/wp-content/uploads/2015/08/IMG_2446_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538053182/in/album-72157686816329321/)
[![](/wp-content/uploads/2015/08/IMG_2488_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538049222/in/album-72157686816329321/)
[![](/wp-content/uploads/2015/08/IMG_2526_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538046922/in/album-72157686816329321/)
[![](/wp-content/uploads/2015/08/IMG_2549_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/36900405873/in/album-72157686816329321/)
[![](/wp-content/uploads/2015/08/IMG_2567_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538045602/in/album-72157686816329321/)
{{< /image-gallery >}}


# Quotes:

According to the [User Manual of the Spektrum DX9 Instruction Manual](http://www.horizonhobby.com/pdf/SPMR9900-Manual_EN.pdf), this is the definition of Mixing:

> Mixing allows control input for a channel to affect more than one channel at a time.

> Mixing functions support:

> - Mixing a channel to another channel.
> - Mixing a channel to itself.
> - Assigning offset to a channel
> - Linking primary to secondary trim.

> These mixes are available for each model memory. Select a channel for master and slave. Inputs for the Master Channel control both the master and Slave Channels. For example, Elevator to Flap makes elevator the Master Channel and flap the Slave Channel. Change the offset value to move the effective center position of the Slave Channel. Positive or negative value determines the direction of the offset. Offset is not available for curve mixes.
