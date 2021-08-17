---
title: libVariant – A c++ library which encapsulate any value of variant types
author: end2end
type: post
date: 2017-05-28T21:06:45+00:00
url: /libvariant-a-c-library-which-encapsulate-any-value-of-variant-types/
featured_image: /wp-content/uploads/2016/10/libVariant-cplusplus-library-672x378.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Source code:</p>
        <ul class="fa-ul">
        <li><a href="/download/2328/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2328" template="title"]</a></li>
        </ul>
        </div>
        
hits:
  - 267
categories:
  - Development
tags:
  - c++
  - english
  - open source

---
# <span id="Introduction">Introduction</span>

The following article is about my new c++ library: libVariant. The library allows one to easily store/encapsulate a value of any c++ type into an instance of type Variant. The library is useful for declaring objects, interfaces, APIs or plugins to be type-independent.

<!--more-->

Skip to the [download section][1] for quick download.

# <span id="Purpose">Purpose</span>

The libVariant library allows one to create an instance of Variant class. The class is a type safe and value safe union between all known basic c++ types. An instance of a Variant class encapsulates a single value of any c++ type: signed and unsigned integers, floating points & strings.

The class can easily convert between any type of data when required and automatically handles all conversion combinations and minimizes lost of data.

The library is useful for declaring objects, interfaces, plugins or APIs to be type-independent.

The need for a Variant type is mostly required in designs where one does not want to implement conversion of c++ types using templates in every situation. Programmers can use the same procedures and functions to process variables with different internal representations (integers, strings, &#8230;) without converting any data. Without the Variant class, a copy of the same procedures and functions would have to be implemented, each with their different types of data.

# <span id="Usage_scenarios">Usage scenarios</span>

Typical usage of the Variant class involves the following:

## <span id="Implement_a_query_language">Implement a query language</span>

Each column of a &#8220;ResultSet&#8221; may be of different type. Storing values in a Variant type is a perfect candidate for type abstraction.

## <span id="Provide_GUI-editable_properties_in_a_generic_manner">Provide GUI-editable properties in a generic manner</span>

The Variant class can be used to implement a similar fashion of C# properties where property editors (<a href="http://www.google.ca/search?q=property+sheet&tbm=isch" target="_blank" rel="noopener">property sheet</a>) can edit any type of property. An application that display a <a href="http://www.google.ca/search?q=property+sheet&tbm=isch" target="_blank" rel="noopener">property sheet</a> UI, must only implement Variant values editing instead of having to implement each specific type of variable.

## <span id="Implementing_change-independent_plugins">Implementing change-independent plugins</span>

By defining plugin APIs with Variant class, the plugin author or the application can change their data-type requirements without affecting each other. Plugin developers can change how they process variables with different internal representations (integers, strings, &#8230;) and reuse the same API without doing any changes to the application which uses the plugin.

The same applies to users of the plugin which feeds the plugin with data to process.

## <span id="Parsing_values_from_text_file">Parsing values from text file</span>

Parsing an *.ini files always used to return string values. Parsing something like <code class="prettycode">numChild=3</code> would return a <code class="prettycode">const char*</code> with the value <code class="prettycode">"3"</code> instead of <code class="prettycode">int value = 3;</code>. Text parsers can be designed to always return a Variant when querying for a named variable in a file. In the example above, the method allows the application to read <code class="prettycode">numChild</code> value as a string or directly as an integer.

## <span id="Implementing_reflection-like_APIs_on_classes">Implementing <a href="http://en.wikipedia.org/wiki/Reflection_(computer_programming)" target="_blank" rel="noopener">reflection-like</a> APIs on classes</span>

If each classes of a system provides a list of Variant which encapsulates their attributes, one can modify the attributes of a class using the Variant&#8217;s internal value.

# <span id="Functionalities_Features">Functionalities / Features</span>

Possible use are:

<li style="text-align: justify;">
  Compatible with the C++ 1998/2003 standard.
</li>
<li style="text-align: justify;">
  Type-safe, value-safe unions between all c++ basic types, including strings.
</li>
<li style="text-align: justify;">
  Holds any numeric values up to 64 bits.
</li>
<li style="text-align: justify;">
  Converts between any type of data as required.
</li>
<li style="text-align: justify;">
  No data loss on mathematical operations. The class supports automatic internal type promotion to prevent overflows.
</li>
<li style="text-align: justify;">
  Implements all c++ operators with all known native c++ types to prevent any unwanted implicit conversions to Variant. This make sure that no manipulation errors occurs while handling Variant instances.
</li>
<li style="text-align: justify;">
  Matches the same behavior as <a href="https://msdn.microsoft.com/en-us/library/office/gg251448.aspx">Visual Basic&#8217;s Variant type</a>.
</li>

# <span id="Limitations">Limitations</span>

## <span id="SignedtoUnsigned_value_clamping">Signed to Unsigned value clamping</span>

The class is designed to prevent erroneous conversion issues which could lead to incorrect memory access or out of bounds issues.

<p class="pleasenote" data-pleasenote="true">
  This method is considered safer on multiple scenarios. It is also different from static casting which would keep all bits identical to the originals resulting in value 65533.
</p>

For instance, if a Variant class with an internal type set to <code class="prettycode">SINT16</code> with a value of -3, is then retrieved as an <code class="prettycode">UINT16</code> the class will &#8220;clamp&#8221; the returned value to 0 since -3 cannot be represented as an <code class="prettycode">UINT16</code>.

<p class="prettycode" data-prettycode="true">
  Variant var;<br /> var.setSInt16(-3);<br /> var.getUInt16() ⇒ clamped to minimum value of uint16 (0)
</p>

The same is also true for the other way around: if a Variant is set to value 65500 (<code class="prettycode">UINT16</code>) and is retrieved as a <code class="prettycode">SINT16</code>, then the returned value would be 32767 which is the maximum value of a <code class="prettycode">SINT16</code>.

<p class="prettycode" data-prettycode="true">
  Variant var;<br /> var.setUInt16(65500);<br /> var.getSInt16() ⇒ clamped to maximum value of sint16 (32767 )
</p>

To prevent any data loss and conversion clamping, it is suggested to retrieve the internal value of a Variant using the same type as its internal type.

Keep in mind that for most other scenarios, keeping the internal value of a Variant to be restricted to positive signed integers is largely enough for most scenarios allowing values ranging from 0 to +2147483647.

## <span id="Out_of_range_value_clamping">Out of range value clamping</span>

The Variant class is also build to automatically prevent loss of data when applying mathematical operations.

For instance, if a Variant class with an internal type set to <code class="prettycode">SINT16</code> and a value of 32000 is multiplied by 10 (<code class="prettycode">SINT16</code>) then the internal type of the class will automatically be promoted to <code class="prettycode">SINT32</code> to be able to hold a value of 320000.

However, if the user still requests the internal value as <code class="prettycode">SINT16</code>, then the returned value will be clamped to 32767 which is the maximum value of a <code class="prettycode">SINT16</code>.

<p class="prettycode" data-prettycode="true">
  Variant var;<br /> var.setSInt16(32000);<br /> var = var * 10;<br /> var ⇒ sint32 with a value of 320000
</p>

## <span id="Unsigned_to_signed_automatic_conversions">Unsigned to signed automatic conversions</span>

If the internal value of a Variant is set to any unsigned value and a mathematical operator is applied to the Variant using a signed value then the internal type of the Variant will change from unsigned to signed.

<p class="pleasenote" data-pleasenote="true">
  Note that the expected value from the mathematical operation is always preserved. The only change that may be unnoticed is the internal type changing from unsigned to signed.
</p>

For example, having a Variant set to value 16 <code class="prettycode">(UINT16)</code> is multiplied by value 2 <code class="prettycode">(SINT16)</code>, then the internal type will automatically change to <code class="prettycode">SINT16</code> with a value of 32.

<p class="prettycode" data-prettycode="true">
  Variant var;<br /> var.setUInt16(16);<br /> var = var * 2;<br /> var ⇒ internal type is now sint16
</p>

## <span id="Automatic_conversions_to_floating_point">Automatic conversions to floating point</span>

The class can also do automatic conversions of the internal type to floating point in order to minimize the loss of data.

If a Variant class with an internal type set to <code class="prettycode">SINT16</code> and a value of 5 is divided by 2 (<code class="prettycode">SINT16</code>) then the internal value of the class will automatically convert to <code class="prettycode">FLOAT64</code> to be able to hold a value of 2.5. However, if the user still requests the internal value as <code class="prettycode">SINT16</code>, then the returned value will be rounded down to 2 which is the same result as if the division would have been processed using the native c++ type <code class="prettycode">SINT16</code>.

<p class="prettycode" data-prettycode="true">
  Variant var;<br /> var.setSInt16(5);<br /> var = var / 2;<br /> var.getFloat64() ⇒ returns 2.5<br /> var.getSInt16() ⇒ returns 2
</p>

## <span id="Handling_value_overflows">Handling value overflows</span>

The class is protected against unintentional overflows. Here is the process of computing intentional overflows:

<p class="prettycode" data-prettycode="true">
  Variant::uint8 value = 250;<br /> Variant::sint8 addition = 10;<br /> Variant var;<br /> var.set(value);<br /> var += addition; // promotes to value 260 instead of overflow value 4.<br /> Variant::uint8 overflowValue = var.getUInt64(); // results in value 4
</p>

# <span id="Requirements">Requirements</span>

The library has some compilation requirements and library dependencies which are:

<li style="text-align: justify;">
  Only Visual Studio 2008 projects files are available. Files can be manually moved to other platforms or IDE as required. Supporting other compilers is not currently planned.
</li>
<li style="text-align: justify;">
  The <a href="http://github.com/google/googletest">Google Test</a> v1.6 library is required for running test cases.
</li>

# <span id="License">License</span>

libVariant  
Copyright (C) 2016 Antoine Beauchamp  
The code & updates for the library can be found on http://end2endzone.com

<span style="color: #aaaaaa;"><strong>AUTHOR/LICENSE:</strong></span>  
This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of  
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  Lesser General Public License (LGPL-3.0) for more details.

You should have received a copy of the GNU Lesser General Public  
License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

**<span style="color: #aaaaaa;">DISCLAIMER:</span>**  
This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# <span id="Download">Download</span>

You can download the libVariant library by clicking on the following link:


		<a class="aligncenter download-button" href="http://www.end2endzone.com/download/2328/" rel="nofollow"> Download &ldquo;libVariant-v2.0.114.zip&rdquo; <small>libVariant-v2.0.114.zip &ndash; Downloaded 515 times &ndash; 99 KB</small> </a>

 [1]: #Download