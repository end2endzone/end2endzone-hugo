---
title: csvplot – A command line script which uses Microsoft Excel to plot a graph from a Comma-separated values (CSV) file
author: end2end
date: 2016-08-04T17:30:03+00:00
url: /csvplot-a-command-line-script-which-uses-microsoft-excel-to-plot-a-graph-from-a-comma-separated-values-csv-file/
images:
  - src: /wp-content/uploads/2016/07/csvplot.CarEngineModel.png
hits:
  - 3476
categories:
  - Development
tags:
  - english
  - open source
  - scripts

---
{{< postedit >}}
  Please note that **csvplot** source code is now moved to GitHub. Source code can be downloaded from the project’s [GitHub page](http://github.com/end2endzone/csvplot).
{{< /postedit >}}


# Purpose

I do software prototyping using a wide range of programming language. I often have to generate data that changes over time which is mostly displayed in a grid format. However, that's not the best way to understand how the data changes over time compared to plotting the data to a graph.

Most programming language I know does not offer a native library for plotting data to a graph. It is not an easy task. Most programming language often require external libraries for implementing the process and each library does not work the same way.

Excel is a native platform for parsing Comma-separated values (CSV) files and can be scripted to plot the result into an image.

The purpose of this script is to allows any programming language which generates data to plot the data into an image by saving the raw data to a CSV file and then using the power of Excel to plot the result into an image.<!--more-->

Skip to the [download section](#Download) for quick download.

{{< pleasenote >}}
  Note that **_csvplot_** is only available for Windows and has been tested on Windows 7 only.
{{< /pleasenote >}}


# Features

The following section list the features of **_csvplot_** script:

  * Supports lossless PNG image format.
  * Supports CSV data file format which is a generic text file format supported by any application and programming language.
  * The script supports virtually an unlimited number of time series plots.
  * Automatically detect appropriate boundaries for the graph

# Limitations

The script has some limitations which are explained here.

## Output image

The resolution of the output image may be +- 1 pixels different than what is requested on command line. This is a limitation of how Excel processes image dimensions since it uses "points" as base unit and not actual pixels. A conversion from pixels to points must be calculated which may contains small accuracy error.

The only supported image format is PNG. It is still unknown if Excel actually support JPG for exporting graphs but PNG seems to be the perfect candidate since its a lossless compressed format.

## Column Titles

It is expected that first row of each column contains the title of the column which will be used as the name of the plotted series within the graph.

# Usage

The command for launching the script is as follows. The script must be called with a minimum of 6 command line arguments.

| Name               | Description                          |
|--------------------|--------------------------------------|
| InputFile          | Path of the input CSV file           |
| OutputFile         | Path of the output PNG image         |
| Width              | Width of the output image in pixels  |
| Height             | Height of the output image in pixels |
| Serie #1, X column | X column index of first series       |
| Serie #1, Y column | Y column index of first series       |
| Serie #2, X column | X column index of second series      |
| Serie #2, Y column | Y column index of second series      |
| Serie #n, X column | ...                                  |
| Serie #n, Y column | ...                                  |


{{< pleasenote >}}
  Note that column indice are 1-based and not 0-based. This means that column A is column 1 and not column 0.
{{< /pleasenote >}}


## Execution (command line)

The script is written in [VBScript](http://en.wikipedia.org/wiki/VBScript).  Use the following to execute the script from a batch file (*.bat) :


```batch
@echo off
cscript //nologo "%~dp0csvplot.vbs" path\to\demo.csv path\to\demo.png 800 600 1 2
pause
```


## Output

On execution, the following output is produced by the script:

[![csvplot Command Line Output](http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output.png)](http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output.png)

csvplot Command Line Output


```sh
Microsoft Windows [Version 6.1.7601]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

C:\&gt;cd /d C:\Temp\csvplotdemo

C:\Temp\csvplotdemo&gt;cscript //Nologo csvplot.vbs %cd%\CarEngineModel.csv %cd%\CarEngineModel.png 853 479 1 3 1 4 1 2 Loading input file C:\Temp\csvplotdemo\CarEngineModel.csv...
File load successful.
File has 4 columns.
Plotting series of columns 1 and 3...
Plotting series of columns 1 and 4...
Plotting series of columns 1 and 2...
File C:\Temp\csvplotdemo\CarEngineModel.png saved successfully.

C:\Temp\csvplotdemo&gt;
```


# Code

The code below can be downloaded by clicking on the following link:

{{< pleasenote >}}
  Please note that download links are now deprecated. Binary version of **csvplot**&nbsp;can be downloaded from the project’s [Release page](http://github.com/end2endzone/csvplot/releases/latest).
{{< /pleasenote >}}


# Samples

The following section shows some example of using cvsplot to plot a series

## Apple Share Prices

The following example show the Apple Share Prices closing value over the year 2015. The data is provided by Nasdaq at the following address:  
<http://www.nasdaq.com/symbol/aapl/historical>.

The CSV data can be downloaded here:  

	[ Apple Share Prices over time (2015).csv](http://www.end2endzone.com/download/2212/ "Version 1.0")

[![Apple Share Prices over time (2015) plot using cvsplot](http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015.png)](http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015.png)

Apple Share Prices over time (2015) plot using cvsplot

## Car Engine Model

The following show a hypothetical car engine model which speed increase of decrease over time based on the feedback of the gas pedal.

The CSV data can be downloaded here: 
	[ Car Engine Model.csv](http://www.end2endzone.com/download/2214/ "Version 1.0")

[![Car Engine Model plot using cvsplot](http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel.png)](http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel.png)

Car Engine Model plot using cvsplot

## Sin(x), Cos(x) and Log(x)

The following show a graph of sin(), cos() and log() function in Excel.

The CSV data can be downloaded here: 
	[ sin(x), cos(x) & log(x) function data.csv](http://www.end2endzone.com/download/2216/ "Version 1.0")

[![sin(x), cos(x) & log(x) plot using cvsplot](http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx.png)](http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx.png)

sin(x), cos(x) & log(x) plot using cvsplot

# License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Download

You can download **_csvplot_**&nbsp;by clicking on the following link:

{{< pleasenote >}}
  Please note that download links are now deprecated. Binary version of **csvplot**&nbsp;can be downloaded from the project’s [Release page](http://github.com/end2endzone/csvplot/releases/latest).
{{< /pleasenote >}}

