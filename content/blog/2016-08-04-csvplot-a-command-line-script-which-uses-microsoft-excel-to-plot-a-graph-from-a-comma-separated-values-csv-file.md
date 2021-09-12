---
title: csvplot – A command line script which uses Microsoft Excel to plot a graph from a Comma-separated values (CSV) file
author: end2end
type: post
date: 2016-08-04T17:30:03+00:00
url: /csvplot-a-command-line-script-which-uses-microsoft-excel-to-plot-a-graph-from-a-comma-separated-values-csv-file/
featured_image: /wp-content/uploads/2016/07/csvplot.CarEngineModel-672x379.png
hits:
  - 3476
categories:
  - Development
tags:
  - english
  - open source
  - scripts

---
<p class="postedit">
  Please note that <strong>csvplot</strong> source code is now moved to GitHub. Source code can be downloaded from the project’s <a href="http://github.com/end2endzone/csvplot">GitHub page</a>.
</p>

# <span id="Purpose">Purpose</span>

I do software prototyping using a wide range of programming language. I often have to generate data that changes over time which is mostly displayed in a grid format. However, that&#8217;s not the best way to understand how the data changes over time compared to plotting the data to a graph.

Most programming language I know does not offer a native library for plotting data to a graph. It is not an easy task. Most programming language often require external libraries for implementing the process and each library does not work the same way.

Excel is a native platform for parsing Comma-separated values (CSV) files and can be scripted to plot the result into an image.

The purpose of this script is to allows any programming language which generates data to plot the data into an image by saving the raw data to a CSV file and then using the power of Excel to plot the result into an image.<!--more-->

Skip to the [download section][1] for quick download.

<p class="pleasenote" data-pleasenote="true">
  Note that <strong><em>csvplot</em></strong> is only available for Windows and has been tested on Windows 7 only.
</p>

# <span id="Features">Features</span>

The following section list the features of **_csvplot_** script:

  * Supports lossless PNG image format.
  * Supports CSV data file format which is a generic text file format supported by any application and programming language.
  * The script supports virtually an unlimited number of time series plots.
  * Automatically detect appropriate boundaries for the graph

# <span id="Limitations">Limitations</span>

The script has some limitations which are explained here.

## <span id="Output_image">Output image</span>

The resolution of the output image may be +- 1 pixels different than what is requested on command line. This is a limitation of how Excel processes image dimensions since it uses &#8220;points&#8221; as base unit and not actual pixels. A conversion from pixels to points must be calculated which may contains small accuracy error.

The only supported image format is PNG. It is still unknown if Excel actually support JPG for exporting graphs but PNG seems to be the perfect candidate since its a lossless compressed format.

## <span id="Column_Titles">Column Titles</span>

It is expected that first row of each column contains the title of the column which will be used as the name of the plotted series within the graph.

# <span id="Usage">Usage</span>

The command for launching the script is as follows. The script must be called with a minimum of 6 command line arguments.

<table class=" generictable" data-generictable="true">
  <tr class="headerrow" data-headerrow="true">
    <td>
      Name
    </td>
    
    <td>
      Description
    </td>
  </tr>
  
  <tr>
    <td>
      InputFile
    </td>
    
    <td>
      Path of the input CSV file
    </td>
  </tr>
  
  <tr>
    <td>
      OutputFile
    </td>
    
    <td>
      Path of the output PNG image
    </td>
  </tr>
  
  <tr>
    <td>
      Width
    </td>
    
    <td>
      Width of the output image in pixels
    </td>
  </tr>
  
  <tr>
    <td>
      Height
    </td>
    
    <td>
      Height of the output image in pixels
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #1, X column
    </td>
    
    <td>
      X column index of first series
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #1, Y column
    </td>
    
    <td>
      Y column index of first series
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #2, X column
    </td>
    
    <td>
      X column index of second series
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #2, Y column
    </td>
    
    <td>
      Y column index of second series
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #n, X column
    </td>
    
    <td>
      &#8230;
    </td>
  </tr>
  
  <tr>
    <td>
      Serie #n, Y column
    </td>
    
    <td>
      &#8230;
    </td>
  </tr>
</table>

<p class="pleasenote" data-pleasenote="true">
  Note that column indice are 1-based and not 0-based. This means that column A is column 1 and not column 0.
</p>

## <span id="Execution_command_line">Execution (command line)</span>

The script is written in [VBScript][2].  Use the following to execute the script from a batch file (*.bat) :

<pre class="lang:batch decode:true" title="Windows Batch file">@echo off
cscript //nologo "%~dp0csvplot.vbs" path\to\demo.csv path\to\demo.png 800 600 1 2
pause
</pre>

## <span id="Output">Output</span>

On execution, the following output is produced by the script:

<div id="attachment_2181" style="width: 670px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output.png" rel="attachment wp-att-2181"><img aria-describedby="caption-attachment-2181" loading="lazy" class="size-full wp-image-2181" src="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output.png" alt="csvplot Command Line Output" width="660" height="342" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output.png 660w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output-150x78.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot-command-line-output-300x155.png 300w" sizes="(max-width: 660px) 100vw, 660px" /></a>
  
  <p id="caption-attachment-2181" class="wp-caption-text">
    csvplot Command Line Output
  </p>
</div>

<pre class="lang:sh decode:true" title="Sample execution">Microsoft Windows [Version 6.1.7601]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

C:\&gt;cd /d C:\Temp\csvplotdemo

C:\Temp\csvplotdemo&gt;cscript //Nologo csvplot.vbs %cd%\CarEngineModel.csv %cd%\CarEngineModel.png 853 479 1 3 1 4 1 2 Loading input file C:\Temp\csvplotdemo\CarEngineModel.csv...
File load successful.
File has 4 columns.
Plotting series of columns 1 and 3...
Plotting series of columns 1 and 4...
Plotting series of columns 1 and 2...
File C:\Temp\csvplotdemo\CarEngineModel.png saved successfully.

C:\Temp\csvplotdemo&gt;</pre>

# <span id="Code">Code</span>

The code below can be downloaded by clicking on the following link:

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of <strong>csvplot</strong> can be downloaded from the project’s <a href="http://github.com/end2endzone/csvplot/releases/latest">Release page</a>.
</p>

# <span id="Samples">Samples</span>

The following section shows some example of using cvsplot to plot a series

## <span id="Apple_Share_Prices">Apple Share Prices</span>

The following example show the Apple Share Prices closing value over the year 2015. The data is provided by Nasdaq at the following address:  
<http://www.nasdaq.com/symbol/aapl/historical>.

The CSV data can be downloaded here:  

	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/2212/" rel="nofollow"> Apple Share Prices over time (2015).csv</a>

<div id="attachment_2199" style="width: 812px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015.png" rel="attachment wp-att-2199"><img aria-describedby="caption-attachment-2199" loading="lazy" class="size-full wp-image-2199" src="http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015.png" alt="Apple Share Prices over time (2015) plot using cvsplot" width="802" height="602" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015.png 802w, http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015-150x113.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015-300x225.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015-768x576.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/Apple-Share-Prices-over-time-2015-672x504.png 672w" sizes="(max-width: 802px) 100vw, 802px" /></a>
  
  <p id="caption-attachment-2199" class="wp-caption-text">
    Apple Share Prices over time (2015) plot using cvsplot
  </p>
</div>

## <span id="Car_Engine_Model">Car Engine Model</span>

The following show a hypothetical car engine model which speed increase of decrease over time based on the feedback of the gas pedal.

The CSV data can be downloaded here: 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/2214/" rel="nofollow"> Car Engine Model.csv</a>

<div id="attachment_2182" style="width: 865px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel.png" rel="attachment wp-att-2182"><img aria-describedby="caption-attachment-2182" loading="lazy" class="size-full wp-image-2182" src="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel.png" alt="Car Engine Model plot using cvsplot" width="855" height="482" srcset="http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel.png 855w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel-150x85.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel-300x169.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel-768x433.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/07/csvplot.CarEngineModel-672x379.png 672w" sizes="(max-width: 855px) 100vw, 855px" /></a>
  
  <p id="caption-attachment-2182" class="wp-caption-text">
    Car Engine Model plot using cvsplot
  </p>
</div>

## <span id="Sinx_Cosx_and_Logx">Sin(x), Cos(x) and Log(x)</span>

The following show a graph of sin(), cos() and log() function in Excel.

The CSV data can be downloaded here: 
	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/2216/" rel="nofollow"> sin(x), cos(x) & log(x) function data.csv</a>

<div id="attachment_2205" style="width: 812px" class="wp-caption alignnone">
  <a href="http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx.png" rel="attachment wp-att-2205"><img aria-describedby="caption-attachment-2205" loading="lazy" class="size-full wp-image-2205" src="http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx.png" alt="sin(x), cos(x) & log(x) plot using cvsplot" width="802" height="602" srcset="http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx.png 802w, http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx-150x113.png 150w, http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx-300x225.png 300w, http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx-768x576.png 768w, http://www.end2endzone.com/wp-content/uploads/2016/08/sinxcosxlogx-672x504.png 672w" sizes="(max-width: 802px) 100vw, 802px" /></a>
  
  <p id="caption-attachment-2205" class="wp-caption-text">
    sin(x), cos(x) & log(x) plot using cvsplot
  </p>
</div>

# <span id="License">License</span>

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**DISCLAIMER:**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download **_csvplot_** by clicking on the following link:

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of <strong>csvplot</strong> can be downloaded from the project’s <a href="http://github.com/end2endzone/csvplot/releases/latest">Release page</a>.
</p>

 [1]: #Download
 [2]: http://en.wikipedia.org/wiki/VBScript