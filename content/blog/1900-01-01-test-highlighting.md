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

## Tables

Tables aren't part of the core Markdown spec, but Hugo supports supports them out-of-the-box.

   Name | Age
--------|------
    Bob | 27
  Alice | 23


#### Inline Markdown within tables

| Inline&nbsp;&nbsp;&nbsp;     | Markdown&nbsp;&nbsp;&nbsp;  | In&nbsp;&nbsp;&nbsp;                | Table      |
| ---------- | --------- | ----------------- | ---------- |
| *italics*  | **bold**  | ~~strikethrough~~&nbsp;&nbsp;&nbsp; | `code`     |


# cpp - code fences
```cpp
// Simple C++ program to display "Hello World"
// Header file for input output functions
#include<iostream>
using namespace std;
// main function - where the execution of program begins
int main()
{
    // prints hello world
    cout<<"Hello World";
    return 0;
}
```

# txt - code fences
```txt
Roses are red,
Violets are blue,
Sugar is sweet,
And so are you.
```

# html - code fences
```html
<html>
 <head>
 </head>
 <body>
   <h1>Hello World<h1>
 </body>
</html>
```

# unspecified - code fences
```
The greatest glory in living lies not in never falling, but in rising every time we fall. -Nelson Mandela
The way to get started is to quit talking and begin doing. -Walt Disney
Your time is limited, so don't waste it living someone else's life. Don't be trapped by dogma – which is living with the results of other people's thinking. -Steve Jobs
If life were predictable it would cease to be life, and be without flavor. -Eleanor Roosevelt
If you look at what you have in life, you'll always have more. If you look at what you don't have in life, you'll never have enough. -Oprah Winfrey
If you set your goals ridiculously high and it's a failure, you will fail above everyone else's success. -James Cameron
Life is what happens when you're busy making other plans. -John Lennon
```


# Image Galleries (as tables)

{{< image-gallery >}}
| <!-- -->                                                                                                                                                                                  | <!-- -->                                                                                                                                                                                  |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [<br /> ![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2446_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538053182/in/album-72157686816329321/) | [<br /> ![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2488_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538049222/in/album-72157686816329321/) |
| [<br /> ![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2526_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538046922/in/album-72157686816329321/) | [<br /> ![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2549_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/36900405873/in/album-72157686816329321/) |
| [<br /> ![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2567_e2ez-672x448.jpg)<br /> ](https://www.flickr.com/photos/154618444@N05/37538045602/in/album-72157686816329321/) |                                                                                                                                                                                           |
{{< /image-gallery >}}


# Image Galleries (images in a div)

{{< image-gallery >}}
[![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2446_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538053182/in/album-72157686816329321/)
[![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2488_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538049222/in/album-72157686816329321/)
[![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2526_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538046922/in/album-72157686816329321/)
[![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2549_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/36900405873/in/album-72157686816329321/)
[![](http://www.end2endzone.com/wp-content/uploads/2015/08/IMG_2567_e2ez-672x448.jpg)](https://www.flickr.com/photos/154618444@N05/37538045602/in/album-72157686816329321/)
{{< /image-gallery >}}
