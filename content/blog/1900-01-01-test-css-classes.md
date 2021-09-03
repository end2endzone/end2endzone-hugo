---
title: 'test css classes'
author: end2end
date: 1900-01-01
categories:
  - test
tags:
  - test
---

hey this is my text default color

[this is a link to google.com](http://google.com)

this is another line of text{#id .pleasenote}


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

![Flowers](/wp-content/uploads/2015/01/MSBuildReorder-How-to-reorder-a-Visual-Studio-build-log-for-easy-reading-150x84.png){.callout}

## heading ## {#id .className attrName=attrValue class="class1 class2"}

# Custom css classes

{{< postedit >}}
  EDIT: Source code is now moved to GitHub. Source code can be downloaded from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder).
{{< /postedit >}}

{{< pleasenote >}}
  NOTE: Please note that download links are now deprecated. Binary version of msbuildreorder can be downloaded directly from [the project's GitHub page](http://github.com/end2endzone/msbuildreorder/releases).
{{< /pleasenote >}}

# Forms

<form id="comment-form" class="new-comment" method="POST">
  <input required="" name="fields[name]" type="text" placeholder="Your Name">
  <textarea required="" name="fields[body]" placeholder="Your Message" rows="10"></textarea>

  <div class="submit-notice">
    <strong class="submit-notice-text submit-success hidden">Thanks for your comment! It will be shown on the site once it has been approved.</strong>
    <strong class="submit-notice-text submit-failed hidden">Sorry, there was an error with your submission. Please make sure all required fields have been completed and try again.</strong>
  </div>

  <button type="button" id="comment-form-submit" class="button">Submit</button>
  <button type="button" id="comment-form-submitted" class="hidden button" disabled="">Submitted</button>
  <button type="reset" id="comment-form-reset" class="button">Reset</button>
</form>


# Tables

HTML 5 table:
<table>
  <thead>
  <tr>
    <th>Company</th>
    <th>Contact</th>
    <th>Country</th>
  </tr>
  </thead>
  <tbody>
  <tr>
    <td>Alfreds Futterkiste</td>
    <td>Maria Anders</td>
    <td>Germany</td>
  </tr>
  <tr>
    <td>Centro comercial Moctezuma</td>
    <td>Francisco Chang</td>
    <td>Mexico</td>
  </tr>
  <tr>
    <td>Ernst Handel</td>
    <td>Roland Mendel</td>
    <td>Austria</td>
  </tr>
  <tr>
    <td>Island Trading</td>
    <td>Helen Bennett</td>
    <td>UK</td>
  </tr>
  <tr>
    <td>Laughing Bacchus Winecellars</td>
    <td>Yoshi Tannamuri</td>
    <td>Canada</td>
  </tr>
  <tr>
    <td>Magazzini Alimentari Riuniti</td>
    <td>Giovanni Rovelli</td>
    <td>Italy</td>
  </tr>
  </tbody>
</table>

Plain html table:
<table>
 <tr>
  <th>Name</th>
  <th>Salary</th>
  <th>Expenses</th>
 <tr>
  <td>john</td>
  <td>$20,000</td>
  <td>$10,000</td>
 </tr>
 <tr>
  <td>david</td>
  <td>$30,000</td>
  <td>$15,000</td>
 </tr>
 <tr>
  <td>marry</td>
  <td>$40,000</td>
  <td>$15,000</td>
 </tr>
</table>

# Other
