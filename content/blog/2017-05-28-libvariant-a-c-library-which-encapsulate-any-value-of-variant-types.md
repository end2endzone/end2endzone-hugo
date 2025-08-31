---
title: libVariant – A c++ library which encapsulate any value of variant types
author: end2end
date: 2017-05-28T21:06:45+00:00
url: /libvariant-a-c-library-which-encapsulate-any-value-of-variant-types/
images:
  - src: /wp-content/uploads/2016/10/libVariant-cplusplus-library.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Source code:
        * [[download id="2328" template="title"]](/download/2328/)
        
hits:
  - 276
categories:
  - Development
tags:
  - c++
  - english
  - open source

---
# Introduction

The following article is about my new c++ library: libVariant. The library allows one to easily store/encapsulate a value of any c++ type into an instance of type Variant. The library is useful for declaring objects, interfaces, APIs or plugins to be type-independent.

Skip to the [download section](#Download) for quick download.

# Purpose

The libVariant library allows one to create an instance of Variant class. The class is a type safe and value safe union between all known basic c++ types. An instance of a Variant class encapsulates a single value of any c++ type: signed and unsigned integers, floating points & strings.

The class can easily convert between any type of data when required and automatically handles all conversion combinations and minimizes lost of data.

The library is useful for declaring objects, interfaces, plugins or APIs to be type-independent.

The need for a Variant type is mostly required in designs where one does not want to implement conversion of c++ types using templates in every situation. Programmers can use the same procedures and functions to process variables with different internal representations (integers, strings, ...) without converting any data. Without the Variant class, a copy of the same procedures and functions would have to be implemented, each with their different types of data.

# Usage scenarios

Typical usage of the Variant class involves the following:

## Implement a query language

Each column of a "ResultSet" may be of different type. Storing values in a Variant type is a perfect candidate for type abstraction.

## Provide GUI-editable properties in a generic manner

The Variant class can be used to implement a similar fashion of C# properties where property editors ([property sheet](http://www.google.ca/search?q=property+sheet&tbm=isch)) can edit any type of property. An application that display a [property sheet](http://www.google.ca/search?q=property+sheet&tbm=isch) UI, must only implement Variant values editing instead of having to implement each specific type of variable.

## Implementing change-independent plugins

By defining plugin APIs with Variant class, the plugin author or the application can change their data-type requirements without affecting each other. Plugin developers can change how they process variables with different internal representations (integers, strings, ...) and reuse the same API without doing any changes to the application which uses the plugin.

The same applies to users of the plugin which feeds the plugin with data to process.

## Parsing values from text file

Parsing an \*.ini files always used to return string values. Parsing something like `numChild=3` would return a `const char*` with the value `"3"` instead of `int value = 3;`. Text parsers can be designed to always return a Variant when querying for a named variable in a file. In the example above, the method allows the application to read `numChild` value as a string or directly as an integer.

## Implementing [reflection-like](http://en.wikipedia.org/wiki/Reflection_(computer_programming)) APIs on classes

If each classes of a system provides a list of Variant which encapsulates their attributes, one can modify the attributes of a class using the Variant's internal value.

# Functionalities / Features

Possible use are:

* Compatible with the C++ 1998/2003 standard.
* Type-safe, value-safe unions between all c++ basic types, including strings.
* Holds any numeric values up to 64 bits.
* Converts between any type of data as required.
* No data loss on mathematical operations. The class supports automatic internal type promotion to prevent overflows.
* Implements all c++ operators with all known native c++ types to prevent any unwanted implicit conversions to Variant. This make sure that no manipulation errors occurs while handling Variant instances.
* Matches the same behavior as [Visual Basic's Variant type](https://msdn.microsoft.com/en-us/library/office/gg251448.aspx).

# Limitations

## Signed to Unsigned value clamping

The class is designed to prevent erroneous conversion issues which could lead to incorrect memory access or out of bounds issues.

{{< pleasenote >}}
  This method is considered safer on multiple scenarios. It is also different from static casting which would keep all bits identical to the originals resulting in value 65533.
{{< /pleasenote >}}

For instance, if a Variant class with an internal type set to `SINT16` with a value of -3, is then retrieved as an `UINT16` the class will "clamp" the returned value to 0 since -3 cannot be represented as an `UINT16`.

```cpp
Variant var;
var.setSInt16(-3);
var.getUInt16(); // ⇒ clamped to minimum value of uint16 (0)
```

The same is also true for the other way around: if a Variant is set to value 65500 (`UINT16`) and is retrieved as a `SINT16`, then the returned value would be 32767 which is the maximum value of a `SINT16`.

```cpp
Variant var;
var.setUInt16(65500);
var.getSInt16(); // ⇒ clamped to maximum value of sint16 (32767 )
```

To prevent any data loss and conversion clamping, it is suggested to retrieve the internal value of a Variant using the same type as its internal type.

Keep in mind that for most other scenarios, keeping the internal value of a Variant to be restricted to positive signed integers is largely enough for most scenarios allowing values ranging from 0 to +2147483647.

## Out of range value clamping

The Variant class is also build to automatically prevent loss of data when applying mathematical operations.

For instance, if a Variant class with an internal type set to `SINT16` and a value of 32000 is multiplied by 10 (`SINT16`) then the internal type of the class will automatically be promoted to `SINT32` to be able to hold a value of 320000.

However, if the user still requests the internal value as `SINT16`, then the returned value will be clamped to 32767 which is the maximum value of a `SINT16`.

```cpp
Variant var;
var.setSInt16(32000);
var = var * 10; // var ⇒ sint32 with a value of 320000
```

## Unsigned to signed automatic conversions

If the internal value of a Variant is set to any unsigned value and a mathematical operator is applied to the Variant using a signed value then the internal type of the Variant will change from unsigned to signed.

{{< pleasenote >}}
  Note that the expected value from the mathematical operation is always preserved. The only change that may be unnoticed is the internal type changing from unsigned to signed.
{{< /pleasenote >}}

For example, having a Variant set to value 16 `(UINT16)` is multiplied by value 2 `(SINT16)`, then the internal type will automatically change to `SINT16` with a value of 32.

```cpp
Variant var;
var.setUInt16(16);
var = var * 2; // var ⇒ internal type is now sint16
```

## Automatic conversions to floating point

The class can also do automatic conversions of the internal type to floating point in order to minimize the loss of data.

If a Variant class with an internal type set to `SINT16` and a value of 5 is divided by 2 (`SINT16`) then the internal value of the class will automatically convert to `FLOAT64` to be able to hold a value of 2.5. However, if the user still requests the internal value as `SINT16`, then the returned value will be rounded down to 2 which is the same result as if the division would have been processed using the native c++ type `SINT16`.

```cpp
Variant var;
var.setSInt16(5);
var = var / 2;
var.getFloat64(); // ⇒ returns 2.5, var.getSInt16() ⇒ returns 2
```

## Handling value overflows

The class is protected against unintentional overflows. Here is the process of computing intentional overflows:

```cpp
Variant::uint8 value = 250;
Variant::sint8 addition = 10;
Variant var; var.set(value);
var += addition; // promotes to value 260 instead of overflow value 4.
Variant::uint8 overflowValue = var.getUInt64(); // results in value 4
```

# Requirements

The library has some compilation requirements and library dependencies which are:

* Only Visual Studio 2008 projects files are available. Files can be manually moved to other platforms or IDE as required. Supporting other compilers is not currently planned.
* The [Google Test](http://github.com/google/googletest) v1.6 library is required for running test cases.

# License

Copyright (C) 2016 Antoine Beauchamp  

This library is licensed under the MIT License:

A short and simple permissive license with conditions only requiring preservation of copyright and license notices. Licensed works, modifications, and larger works may be distributed under different terms and without source code.

The full license is available [here](https://github.com/end2endzone/bin2cpp/blob/master/LICENSE).

# Download

You can download the libVariant library by clicking on the following link:
{{% download old-id="2328" href="https://github.com/end2endzone/libVariant/archive/refs/tags/3.0.0.zip" %}}libVariant v3.0.0.zip{{% /download %}}
