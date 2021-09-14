defaultCaption = "Enter a value"

prefix = askString(defaultCaption, "What is the prefix filename for your images?", "IMG_")
postfix = ".jpg"

block1Start = askNumber(defaultCaption, "What is the starting number for the first block?", 9000)
block1End   = askNumber(defaultCaption, "What is the ending number for the first block?", 9999)
block2Start = askNumber(defaultCaption, "What is the starting number for the second block?", 0)
block2End   = askNumber(defaultCaption, "What is the ending number for the second block?", 2345)

indexLength = Max(Len(block1Start), Max(Len(block1End), Max(Len(block2Start), Len(block2End) ) ) )
block1Size = block1End-block1Start+1
block2Size = block2End-block2Start+1

block1ImageStart = prefix & padNumber(block1Start, indexLength) & postfix
block1ImageEnd = prefix & padNumber(block1End, indexLength) & postfix
block2ImageStart = prefix & padNumber(block2Start, indexLength) & postfix
block2ImageEnd = prefix & padNumber(block2End, indexLength) & postfix

'0 to 3345
newBlock1IndexStart = 0
newBlock1IndexEnd = block1Size
newBlock2IndexStart = block1Size+1
newBlock2IndexEnd = block1Size+block2Size

newBlock1ImageStart = prefix & padNumber(newBlock1IndexStart, indexLength) & postfix
newBlock1ImageEnd = prefix & padNumber(newBlock1IndexEnd, indexLength) & postfix
newBlock2ImageStart = prefix & padNumber(newBlock2IndexStart, indexLength) & postfix
newBlock2ImageEnd = prefix & padNumber(newBlock2IndexEnd, indexLength) & postfix

confirmationMessage = "The following script will rename block " & vbCrLf & _
  block1ImageStart & "-->" & block1ImageEnd & _
  " into " & _
  newBlock1ImageStart & "-->" & newBlock1ImageEnd & vbCrLf & _
  "and block " & vbCrLf & _
  block2ImageStart & "-->" & block2ImageEnd & _
  " into " & _
  newBlock2ImageStart & "-->" & newBlock2ImageEnd & vbCrLf & _
  vbCrLf & _
  "Is this what you want?"

defaultCaption = "Confirm renaming"
askYesOrDie defaultCaption, confirmationMessage
askYesOrDie defaultCaption, "The process is permanent and can not be undone." & vbCrLf & "Are you really sure?"

'start with file renaming

'Renaming all files with a "tmp_" prefix to prevent conflicts
for i = block1Start to block1End
  oldFilename = prefix & padNumber(i, indexLength) & postfix
  newFilename = "tmp_" & oldFilename
  renameFile oldFilename, newFilename
next
for i = block2Start to block2End
  oldFilename = prefix & padNumber(i, indexLength) & postfix
  newFilename = "tmp_" & oldFilename
  renameFile oldFilename, newFilename
next

'Rename tmp_block1
loopCount = 0
for i = block1Start to block1End
  oldFilename = "tmp_" & prefix & padNumber(i, indexLength) & postfix
  newFilename = prefix & padNumber(loopCount+newBlock1IndexStart, indexLength) & postfix
  renameFile oldFilename, newFilename
  loopCount = loopCount + 1
next

'Rename tmp_block2
loopCount = 0
for i = block2Start to block2End
  oldFilename = "tmp_" & prefix & padNumber(i, indexLength) & postfix
  newFilename = prefix & padNumber(loopCount+newBlock2IndexStart, indexLength) & postfix
  renameFile oldFilename, newFilename
  loopCount = loopCount + 1
next




sub renameFile(oldFilename, newFilename)
  Dim fso
  Set fso = WScript.CreateObject("Scripting.FileSystemObject")
  fso.MoveFile oldFilename, newFilename
  Set fso = nothing
end sub


sub askYesOrDie(caption, prompt)
  response = Msgbox(prompt, vbYesNo+vbExclamation, caption)
  if (response = vbNo) Then WScript.Quit  'Detect No
end sub

function askNumber(caption, prompt, defaultValue)
  Dim response
  Do
    response = InputBox(prompt, caption, defaultValue)
    If response = "" Then WScript.Quit  'Detect Cancel
    If IsNumeric(response) Then Exit Do 'Detect value response.
    MsgBox "You must enter a numeric value.", 48, "Invalid Entry"
  Loop
  askNumber = response
end function 

function askString(caption, prompt, defaultValue)
  Dim response
  Do
    response = InputBox(prompt, caption, defaultValue)
    If response = "" Then WScript.Quit  'Detect Cancel
    Exit Do 'Detect value response.
  Loop
  askString = response
end function 

function Max(a,b) 
  Max = a 
  If b > a then Max = b 
end function 

function Min(a,b) 
  Min = a 
  If b < a then Min = b 
end function 

function padNumber(value, numDigits)
  value2 = value
  do while(len(value2) < numDigits)
    value2 = "0" & value2
  loop
  padNumber = value2
end function
