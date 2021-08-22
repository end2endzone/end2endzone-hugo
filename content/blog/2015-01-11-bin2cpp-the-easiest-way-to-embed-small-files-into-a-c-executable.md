---
title: 'bin2cpp: The easiest way to embed small files into a C++ executable'
author: end2end
type: post
date: 2015-01-12T03:56:17+00:00
url: /bin2cpp-the-easiest-way-to-embed-small-files-into-a-c-executable/
featured_image: /wp-content/uploads/2015/01/bin2cpp-featured-image-672x378.png
hits:
  - 211
categories:
  - Development
tags:
  - c++
  - english
  - Freeware

---
# <span id="bin2cpp">bin2cpp</span>

<p class="postedit">
  Please note that bin2cpp source code is now moved to GitHub. Source code can be downloaded from <a href="http://github.com/end2endzone/bin2cpp">the project&#8217;s GitHub page</a>.
</p>

![][1]![][2]![][3]![][4]![][5] 

<span style="line-height: 1.5;">bin2cpp is a command line tool for embedding small files (like images, icons or raw data files) into a C++ executable.</span>

It&#8217;s main features are:

  * <span style="line-height: 1.5;">Easily converts small files as C++ source code for embedding into a C++ executable.</span>
  * <span style="line-height: 1.5;">Content extraction supported by a unique function call for each embedded file.</span>
  * <span style="line-height: 1.5;">Supports a multiple </span>embedded<span style="line-height: 1.5;"> files at once.</span>
  * <span style="line-height: 1.5;">Makes it harder for resource hacker to modify or steal the </span>embedded<span style="line-height: 1.5;"> files.</span>
  * <span style="line-height: 1.5;">No third party libraries required for </span>retrieving<span style="line-height: 1.5;"> the data of the </span>embedded<span style="line-height: 1.5;"> files.</span>

<!--more-->

<span style="line-height: 1.5;">bin2cpp is not implemented using <a href="http://en.wikipedia.org/wiki/Resource_(Windows)">executable resources</a>. Instead, bin2cpp creates multiple function calls for retrieving the data which makes it harder to steal the executable&#8217;s content. It also makes it even harder to replace an existing resource of the executable.</span>

It is designed to be easy to use by developers and to provide easy call functions to get access to the data of the embedded files.

<span style="line-height: 1.5;">The generated functions that reads and extracts the </span>embedded<span style="line-height: 1.5;"> content does not rely on external libraries so you don&#8217;t need to setup your projects to use any third party library to start using bin2cpp. All your embedded data can be accessed right away.</span>

<span style="line-height: 1.5;"><strong>Usage:</strong></span>  
bin2cpp \[inputfile\] \[output folder\] \[header filename\] \[function identifier\] \[chunk size\] \[-override\].

  * **inputfile**: Path to the target file to embed in a C++ source code.
  * **output folder**: Output path to create generated source code. ie: .\generated_files\
  * **header filename**: File name of the C++ Header file. ie: SplashScreen.h
  * **function identifier**: Identifier of the function name that is used to get an instance of the file. ie: SplashScreen
  * **chunk size** (optional): Size of each string segments. Defaults to 200]
  * **override** (optional): Tells bin2cpp to over write the destination files.

# <span id="Screenshots"><span style="line-height: 1.5;">Screenshots</span></span>

<div id="attachment_575" style="width: 847px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done.png"><img aria-describedby="caption-attachment-575" loading="lazy" class="wp-image-575 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done.png" alt="bin2cpp v1.3 Sample" width="837" height="342" srcset="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done.png 837w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done-150x61.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done-300x123.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-done-672x275.png 672w" sizes="(max-width: 837px) 100vw, 837px" /></a>
  
  <p id="caption-attachment-575" class="wp-caption-text">
    bin2cpp v1.3 Sample
  </p>
</div>

<div id="attachment_576" style="width: 1023px" class="wp-caption aligncenter">
  <a href="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage.png"><img aria-describedby="caption-attachment-576" loading="lazy" class="wp-image-576 size-full" src="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage.png" alt="bin2cpp v1.3 Usage" width="1013" height="359" srcset="http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage.png 1013w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage-150x53.png 150w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage-300x106.png 300w, http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-v1.3-usage-672x238.png 672w" sizes="(max-width: 1013px) 100vw, 1013px" /></a>
  
  <p id="caption-attachment-576" class="wp-caption-text">
    bin2cpp v1.3 Usage
  </p>
</div>

# <span id="Download"><span style="line-height: 1.5;">Download</span></span>

You can download bin2cpp by clicking on the following links:

<p class="pleasenote" data-pleasenote="true">
  Please note that download links are now deprecated. Binary version of bin2cpp can be downloaded directly from <a href="http://github.com/end2endzone/bin2cpp/releases">the project&#8217;s GitHub page</a>.
</p>

# <span id="Code_sample"><span style="line-height: 1.5;">Code sample</span></span>

Here are some C++ code samples for embedding a Visual Studio 2008 project file generated with the following command line:

_<span style="font-family: courier new,courier; font-size: 14pt;">bin2cpp.exe bin2cppTest.vcproj outdir EmbededProjectFile.h Vcproj 250 -override</span>_

<pre title="EmbededProjectFile.h" class="lang:c++ decode:true">/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#pragma once
#include &lt;stddef.h&gt;
namespace bin2cpp
{
  #ifndef BIN2CPP_EMBEDEDFILE_CLASS
  #define BIN2CPP_EMBEDEDFILE_CLASS
  class File
  {
  public:
    virtual size_t getSize() = 0;
    virtual size_t getSegmentSize() = 0;
    virtual size_t getNumSegments() = 0;
    virtual const char * getFilename() = 0;
    virtual const char * getSegment(size_t iIndex, size_t & oLength) = 0;
    virtual const char * getMd5() = 0;
    virtual char * newBuffer() = 0;
    virtual bool save(const char * iFilename) = 0;
  };
  #endif
  File & getVcprojFile();
}; //bin2cpp
</pre>

<pre title="EmbededProjectFile.cpp" class="lang:c++ decode:true">/**
 * This file was generated by
 * bin2cpp v1.3.
 * Copyright (C) 2013-2014 end2endzone.com. All rights reserved.
 * Do not modify this file.
 */
#include ".\EmbededProjectFile.h"
#include &lt;stdio.h&gt; //for FILE
#include &lt;string&gt; //for memcpy
namespace bin2cpp
{
  class VcprojFile : public virtual bin2cpp::File
  {
  public:
    VcprojFile() {}
    ~VcprojFile() {}
    virtual size_t getSize() { return 10314; }
    virtual size_t getSegmentSize() { return 250; }
    virtual size_t getNumSegments() { return 42; }
    virtual const char * getFilename() { return "bin2cppTest.vcproj"; }
    virtual const char * getSegment(size_t iIndex, size_t & oLength)
    {
      oLength = 0;
      if (iIndex &gt;= getNumSegments())
        return NULL;
      const char * buffer = NULL;
      size_t index = 0;
      oLength = getSegmentSize();
      buffer = "&lt;?xml version=\"1.0\" encoding=\"Windows-1252\"?&gt;\x0d\012&lt;VisualStudioProject\x0d\x0a\tProjectType=\"Visual C++\"\x0d\x0a\tVersion=\"9,00\"\x0d\x0a\tName=\"bin2cppTest\"\x0d\x0a\tProjectGUID=\"{0E82011B-BFB8-45C4-97A9-89B46C2E3704}\"\x0d\x0a\tRootNamespace=\"bin2cppTest\"\x0d\x0a\tKeyword=\"Win32Proj\"\x0d\x0a\tTargetFr"; if (iIndex == index) return buffer; index++;
      buffer = "ameworkVersion=\"196613\"\x0d\x0a\t&gt;\x0d\x0a\t&lt;Platforms&gt;\x0d\x0a\t\t&lt;Platform\x0d\x0a\t\t\tName=\"Win32\"\x0d\x0a\t\t/&gt;\x0d\x0a\t\t&lt;Platform\x0d\x0a\t\t\tName=\"x64\"\x0d\x0a\t\t/&gt;\x0d\x0a\t&lt;/Platforms&gt;\x0d\x0a\t&lt;ToolFiles&gt;\x0d\x0a\t&lt;/ToolFiles&gt;\x0d\x0a\t&lt;Configurations&gt;\x0d\x0a\t\t&lt;Configuration\x0d\x0a\t\t\tName=\"Debug|Win32\"\x0d\x0a\t\t\tOutputDirectory=\"$(SolutionDir"; if (iIndex == index) return buffer; index++;
      buffer = ")$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tIntermediateDirectory=\"$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tConfigurationType=\"1\"\x0d\x0a\t\t\tCharacterSet=\"2\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"call prebuild.bat $(Configuration"; if (iIndex == index) return buffer; index++;
      buffer = "Name) $(PlatformName)\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCustomBuildTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXMLDataGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCWebServiceProxyGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCMIDLTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\""; if (iIndex == index) return buffer; index++;
      buffer = "VCCLCompilerTool\"\x0d\x0a\t\t\t\tOptimization=\"0\"\x0d\x0a\t\t\t\tAdditionalIncludeDirectories=\"&quot;$(SolutionDir)libs\\gtest\\include&quot;;&quot;$(SolutionDir)gtesthelper&quot;\"\x0d\x0a\t\t\t\tPreprocessorDefinitions=\"WIN32;_DEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS\"\x0d\x0a\t\t\t\tMinimalRe"; if (iIndex == index) return buffer; index++;
      buffer = "build=\"true\"\x0d\x0a\t\t\t\tBasicRuntimeChecks=\"3\"\x0d\x0a\t\t\t\tRuntimeLibrary=\"3\"\x0d\x0a\t\t\t\tUsePrecompiledHeader=\"0\"\x0d\x0a\t\t\t\tWarningLevel=\"3\"\x0d\x0a\t\t\t\tDebugInformationFormat=\"4\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManagedResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCResourceComp"; if (iIndex == index) return buffer; index++;
      buffer = "ilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreLinkEventTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCLinkerTool\"\x0d\x0a\t\t\t\tAdditionalDependencies=\"vc90_$(ConfigurationName)_MT_DLL_$(PlatformName)_gtest.lib\"\x0d\x0a\t\t\t\tLinkIncremental=\"2\"\x0d\x0a\t\t\t\tAdditionalLibraryDirectories=\"&"; if (iIndex == index) return buffer; index++;
      buffer = "quot;$(SolutionDir)libs\\gtest\\lib&quot;\"\x0d\x0a\t\t\t\tGenerateDebugInformation=\"true\"\x0d\x0a\t\t\t\tSubSystem=\"1\"\x0d\x0a\t\t\t\tTargetMachine=\"1\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCALinkTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManifestTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXDCMakeTool\"\x0d\x0a\t"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCBscMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCFxCopTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCAppVerifierTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPostBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t&lt;/Configuration&gt;\x0d\x0a\t\t&lt;Configuration\x0d\x0a\t\t\tNa"; if (iIndex == index) return buffer; index++;
      buffer = "me=\"Debug|x64\"\x0d\x0a\t\t\tOutputDirectory=\"$(SolutionDir)$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tIntermediateDirectory=\"$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tConfigurationType=\"1\"\x0d\x0a\t\t\tCharacterSet=\"2\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreBuildEventTool\"\x0d\x0a\t"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t\tCommandLine=\"call prebuild.bat $(ConfigurationName) $(PlatformName)\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCustomBuildTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXMLDataGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCWebServiceProxyGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t\tName=\"VCMIDLTool\"\x0d\x0a\t\t\t\tTargetEnvironment=\"3\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCLCompilerTool\"\x0d\x0a\t\t\t\tOptimization=\"0\"\x0d\x0a\t\t\t\tAdditionalIncludeDirectories=\"&quot;$(SolutionDir)libs\\gtest\\include&quot;;&quot;$(SolutionDir)gtesthelper&quot;\"\x0d\x0a\t\t\t\tPreprocess"; if (iIndex == index) return buffer; index++;
      buffer = "orDefinitions=\"WIN32;_DEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS\"\x0d\x0a\t\t\t\tMinimalRebuild=\"true\"\x0d\x0a\t\t\t\tBasicRuntimeChecks=\"3\"\x0d\x0a\t\t\t\tRuntimeLibrary=\"3\"\x0d\x0a\t\t\t\tUsePrecompiledHeader=\"0\"\x0d\x0a\t\t\t\tWarningLevel=\"3\"\x0d\x0a\t\t\t\tDebugInformationFormat=\"3\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tNam"; if (iIndex == index) return buffer; index++;
      buffer = "e=\"VCManagedResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreLinkEventTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCLinkerTool\"\x0d\x0a\t\t\t\tAdditionalDependencies=\"vc90_$(ConfigurationName)_MT_DLL_$(PlatformNa"; if (iIndex == index) return buffer; index++;
      buffer = "me)_gtest.lib\"\x0d\x0a\t\t\t\tLinkIncremental=\"2\"\x0d\x0a\t\t\t\tAdditionalLibraryDirectories=\"&quot;$(SolutionDir)libs\\gtest\\lib&quot;\"\x0d\x0a\t\t\t\tGenerateDebugInformation=\"true\"\x0d\x0a\t\t\t\tSubSystem=\"1\"\x0d\x0a\t\t\t\tTargetMachine=\"17\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCALinkTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;"; if (iIndex == index) return buffer; index++;
      buffer = "Tool\x0d\x0a\t\t\t\tName=\"VCManifestTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXDCMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCBscMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCFxCopTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCAppVerifierTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPostBuildEvent"; if (iIndex == index) return buffer; index++;
      buffer = "Tool\"\x0d\x0a\t\t\t\tCommandLine=\"\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t&lt;/Configuration&gt;\x0d\x0a\t\t&lt;Configuration\x0d\x0a\t\t\tName=\"Release|Win32\"\x0d\x0a\t\t\tOutputDirectory=\"$(SolutionDir)$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tIntermediateDirectory=\"$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tConfiguratio"; if (iIndex == index) return buffer; index++;
      buffer = "nType=\"1\"\x0d\x0a\t\t\tCharacterSet=\"2\"\x0d\x0a\t\t\tWholeProgramOptimization=\"1\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"call prebuild.bat $(ConfigurationName) $(PlatformName)\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCustomBuildTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d"; if (iIndex == index) return buffer; index++;
      buffer = "\x0a\t\t\t\tName=\"VCXMLDataGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCWebServiceProxyGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCMIDLTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCLCompilerTool\"\x0d\x0a\t\t\t\tOptimization=\"2\"\x0d\x0a\t\t\t\tEnableIntrinsicFunctions=\"true\"\x0d\x0a\t\t\t\tAddit"; if (iIndex == index) return buffer; index++;
      buffer = "ionalIncludeDirectories=\"&quot;$(SolutionDir)libs\\gtest\\include&quot;;&quot;$(SolutionDir)gtesthelper&quot;\"\x0d\x0a\t\t\t\tPreprocessorDefinitions=\"WIN32;NDEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS\"\x0d\x0a\t\t\t\tRuntimeLibrary=\"2\"\x0d\x0a\t\t\t\tEnableFunctionLevelLinking=\"true\"\x0d\x0a"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t\t\tUsePrecompiledHeader=\"0\"\x0d\x0a\t\t\t\tWarningLevel=\"3\"\x0d\x0a\t\t\t\tDebugInformationFormat=\"3\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManagedResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreLinkEventTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCLinkerTool\"\x0d\x0a\t\t\t\tAdditionalDependencies=\"vc90_$(ConfigurationName)_MT_DLL_$(PlatformName)_gtest.lib\"\x0d\x0a\t\t\t\tLinkIncremental=\"1\"\x0d\x0a\t\t\t\tAdditionalLibraryDirectories=\"&quot;$(SolutionDir)libs\\gtest\\lib&quot;\"\x0d\x0a\t\t\t\tGenerateDebugInforma"; if (iIndex == index) return buffer; index++;
      buffer = "tion=\"true\"\x0d\x0a\t\t\t\tSubSystem=\"1\"\x0d\x0a\t\t\t\tOptimizeReferences=\"2\"\x0d\x0a\t\t\t\tEnableCOMDATFolding=\"2\"\x0d\x0a\t\t\t\tTargetMachine=\"1\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCALinkTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManifestTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXDCMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t"; if (iIndex == index) return buffer; index++;
      buffer = "&lt;Tool\x0d\x0a\t\t\t\tName=\"VCBscMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCFxCopTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCAppVerifierTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPostBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t&lt;/Configuration&gt;\x0d\x0a\t\t&lt;Configuration\x0d\x0a\t\t\tName=\"Relea"; if (iIndex == index) return buffer; index++;
      buffer = "se|x64\"\x0d\x0a\t\t\tOutputDirectory=\"$(SolutionDir)$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tIntermediateDirectory=\"$(PlatformName)\\$(ConfigurationName)\"\x0d\x0a\t\t\tConfigurationType=\"1\"\x0d\x0a\t\t\tCharacterSet=\"2\"\x0d\x0a\t\t\tWholeProgramOptimization=\"1\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tNam"; if (iIndex == index) return buffer; index++;
      buffer = "e=\"VCPreBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"call prebuild.bat $(ConfigurationName) $(PlatformName)\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCustomBuildTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXMLDataGeneratorTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCWebServiceProxyGenerato"; if (iIndex == index) return buffer; index++;
      buffer = "rTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCMIDLTool\"\x0d\x0a\t\t\t\tTargetEnvironment=\"3\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCCLCompilerTool\"\x0d\x0a\t\t\t\tOptimization=\"2\"\x0d\x0a\t\t\t\tEnableIntrinsicFunctions=\"true\"\x0d\x0a\t\t\t\tAdditionalIncludeDirectories=\"&quot;$(SolutionDir)libs\\gtest\\inclu"; if (iIndex == index) return buffer; index++;
      buffer = "de&quot;;&quot;$(SolutionDir)gtesthelper&quot;\"\x0d\x0a\t\t\t\tPreprocessorDefinitions=\"WIN32;NDEBUG;_CONSOLE;_CRT_SECURE_NO_WARNINGS\"\x0d\x0a\t\t\t\tRuntimeLibrary=\"2\"\x0d\x0a\t\t\t\tEnableFunctionLevelLinking=\"true\"\x0d\x0a\t\t\t\tUsePrecompiledHeader=\"0\"\x0d\x0a\t\t\t\tWarningLevel=\"3\"\x0d\x0a\t\t\t\tDebug"; if (iIndex == index) return buffer; index++;
      buffer = "InformationFormat=\"3\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManagedResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCResourceCompilerTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPreLinkEventTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCLinkerTool\"\x0d\x0a\t\t\t\tAdditionalDependencies"; if (iIndex == index) return buffer; index++;
      buffer = "=\"vc90_$(ConfigurationName)_MT_DLL_$(PlatformName)_gtest.lib\"\x0d\x0a\t\t\t\tLinkIncremental=\"1\"\x0d\x0a\t\t\t\tAdditionalLibraryDirectories=\"&quot;$(SolutionDir)libs\\gtest\\lib&quot;\"\x0d\x0a\t\t\t\tGenerateDebugInformation=\"true\"\x0d\x0a\t\t\t\tSubSystem=\"1\"\x0d\x0a\t\t\t\tOptimizeReferences=\"2\"\x0d\x0a\t"; if (iIndex == index) return buffer; index++;
      buffer = "\t\t\tEnableCOMDATFolding=\"2\"\x0d\x0a\t\t\t\tTargetMachine=\"17\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCALinkTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCManifestTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCXDCMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCBscMakeTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\""; if (iIndex == index) return buffer; index++;
      buffer = "VCFxCopTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCAppVerifierTool\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t\t&lt;Tool\x0d\x0a\t\t\t\tName=\"VCPostBuildEventTool\"\x0d\x0a\t\t\t\tCommandLine=\"\"\x0d\x0a\t\t\t/&gt;\x0d\x0a\t\t&lt;/Configuration&gt;\x0d\x0a\t&lt;/Configurations&gt;\x0d\x0a\t&lt;References&gt;\x0d\x0a\t\t&lt;ProjectReference\x0d\x0a\t\t\tReferencedProjectIdentifier=\"{B97"; if (iIndex == index) return buffer; index++;
      buffer = "26A09-6C1B-4427-AEB0-AF44C317C333}\"\x0d\x0a\t\t\tRelativePathToProject=\".\\gtesthelper\\gtesthelper.vcproj\"\x0d\x0a\t\t/&gt;\x0d\x0a\t\t&lt;ProjectReference\x0d\x0a\t\t\tReferencedProjectIdentifier=\"{C831C897-220B-4A21-8BDB-FC1B9E9BA2DA}\"\x0d\x0a\t\t\tRelativePathToProject=\".\\bin2cpp\\bin2cpp.vcproj\"\x0d"; if (iIndex == index) return buffer; index++;
      buffer = "\x0a\t\t/&gt;\x0d\x0a\t&lt;/References&gt;\x0d\x0a\t&lt;Files&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Source Files\"\x0d\x0a\t\t\tFilter=\"cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx\"\x0d\x0a\t\t\tUniqueIdentifier=\"{4FC737F1-C7A5-4376-A066-2A32D752A2FF}\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\main.cpp\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d"; if (iIndex == index) return buffer; index++;
      buffer = "\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Header Files\"\x0d\x0a\t\t\tFilter=\"h;hpp;hxx;hm;inl;inc;xsd\"\x0d\x0a\t\t\tUniqueIdentifier=\"{93995380-89BD-4b04-88EB-625FBE52EBFB}\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Resource Files\"\x0d\x0a\t\t\tFilter=\"rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs"; if (iIndex == index) return buffer; index++;
      buffer = ";gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav\"\x0d\x0a\t\t\tUniqueIdentifier=\"{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\prebuild.bat\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Embeded Files\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativ"; if (iIndex == index) return buffer; index++;
      buffer = "ePath=\".\\EmbededProjectFile.cpp\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\EmbededProjectFile.h\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\EmbededSplashScreen.cpp\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\EmbededSplashScreen."; if (iIndex == index) return buffer; index++;
      buffer = "h\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Tests\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\TestExtraction.cpp\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\TestExtraction.h\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Test File"; if (iIndex == index) return buffer; index++;
      buffer = "s\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;File\x0d\x0a\t\t\t\tRelativePath=\".\\splashscreen.png\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t&lt;/File&gt;\x0d\x0a\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;Filter\x0d\x0a\t\t\tName=\"Generated Files\"\x0d\x0a\t\t\t&gt;\x0d\x0a\t\t\t&lt;Filter\x0d\x0a\t\t\t\tName=\"Test Results\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\bin2cppTest.x64.debug.xml\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t"; if (iIndex == index) return buffer; index++;
      buffer = "\t&lt;/File&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\bin2cppTest.x64.release.xml\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\bin2cppTest.x86.debug.xml\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\bin2cppTest.x86.release.xml\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;/"; if (iIndex == index) return buffer; index++;
      buffer = "File&gt;\x0d\x0a\t\t\t&lt;/Filter&gt;\x0d\x0a\t\t\t&lt;Filter\x0d\x0a\t\t\t\tName=\"Test Files\"\x0d\x0a\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\bin2cppTest.vcproj.output.txt\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t\t&lt;File\x0d\x0a\t\t\t\t\tRelativePath=\".\\splashscreen.output.png\"\x0d\x0a\t\t\t\t\t&gt;\x0d\x0a\t\t\t\t&lt;/File&gt;\x0d\x0a\t\t\t&lt;/Filter&gt;\x0d\x0a\t\t&lt;/Filte"; if (iIndex == index) return buffer; index++;
      oLength = 64;
      buffer = "r&gt;\x0d\x0a\t&lt;/Files&gt;\x0d\x0a\t&lt;Globals&gt;\x0d\x0a\t&lt;/Globals&gt;\x0d\012&lt;/VisualStudioProject&gt;\x0d\x0a"; if (iIndex == index) return buffer; index++;
      oLength = 0;
      return NULL;
    }
    virtual const char * getMd5() { return "e9c559c6446954ced242de3c84e09454"; }
    virtual char * newBuffer()
    {
      size_t size = getSize();
      char * buffer = new char[size];
      if (buffer == NULL)
        return NULL;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      size_t index = 0;
      for(size_t i=0; i&lt;numSegments; i++)
      {
        const char * segmentBuffer = getSegment(i, segmentLength);
        memcpy(&buffer[index], segmentBuffer, segmentLength);
        index += segmentLength;
      }
      return buffer;
    }
    virtual bool save(const char * iFilename)
    {
      FILE * f = fopen(iFilename, "wb");
      if (!f) return false;
      size_t numSegments = getNumSegments();
      size_t segmentLength = 0;
      const char * buffer = NULL;
      for(size_t i=0; i&lt;numSegments; i++)
      {
        buffer = getSegment(i, segmentLength);
        fwrite(buffer, 1, segmentLength, f);
      }
      fclose(f);
      return true;
    }
  };
  File & getVcprojFile() { static VcprojFile _instance; return _instance; }
}; //bin2cpp</pre>

# <span id="Compatible_with"><span style="line-height: 1.5;">Compatible with</span></span>

<span style="line-height: 1.5;">bin2cpp is only available for the Windows platform and has been tested with the following version of Windows:</span>

  * Windows XP
  * <span style="text-align: justify; line-height: 1.5;">Windows Vista</span>
  * <span style="text-align: justify; line-height: 1.5;">Windows 7</span>

# <span id="Minimum_system_requirements">Minimum system requirements</span>

  * 100% PC compatible
  * <span style="text-align: justify; line-height: 1.5;">Pentium II, 300 mhz</span>
  * <span style="text-align: justify; line-height: 1.5;">256 Mb RAM</span>
  * <span style="text-align: justify; line-height: 1.5;">1 Mb free disk space</span>
  * <span style="text-align: justify; line-height: 1.5;">Administrator rights (for installation)</span>

# <span id="License">License</span>

<span lang="EN-US">bin2cpp is being distributed as Freeware for personal, commercial use, non-profit organization, and educational purpose. It may be included with CD-ROM/DVD-ROM distributions. You are NOT allowed to make a charge for distributing this Software (either for profit or merely to recover your media and distribution costs) whether as a stand-alone product, or as part of a compilation or anthology, nor to use it for supporting your business or customers. It may be distributed freely on any website or through any other distribution mechanism, as long as no part of it is changed in any way.</span>

The full license is available [here][6].

# <span id="History_of_changes">History of changes</span>

Version 1.3 &#8211; First public release

 [1]: https://img.shields.io/badge/License-MIT-yellow.svg
 [2]: https://img.shields.io/github/release/end2endzone/bin2cpp.svg
 [3]: https://ci.appveyor.com/api/projects/status/q9k0ebb971o475qi/branch/master?svg=true
 [4]: https://img.shields.io/appveyor/tests/end2endzone/bin2cpp/master.svg
 [5]: https://img.shields.io/github/downloads/end2endzone/bin2cpp/total.svg
 [6]: http://www.end2endzone.com/wp-content/uploads/2015/01/bin2cpp-EULA.htm