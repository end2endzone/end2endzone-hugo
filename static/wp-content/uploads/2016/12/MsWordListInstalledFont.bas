Attribute VB_Name = "ListInstalledFont"
Option Explicit

Public Sub SetupColumnsPerPage(numColumns As Integer)
    'Define numColumns columns per page
    With Selection.PageSetup.TextColumns
        .SetCount numColumns:=numColumns
        .EvenlySpaced = True
        .LineBetween = False
    End With
End Sub

Public Sub ClearDocumentContent()
    'Clear the current document
    Selection.WholeStory
    Selection.Delete Unit:=wdCharacter, Count:=1
End Sub

Public Sub SetupThinMargin()
    With Selection.PageSetup
        .LineNumbering.Active = False
        .Orientation = wdOrientPortrait
        .TopMargin = CentimetersToPoints(1.27)
        .BottomMargin = CentimetersToPoints(1.27)
        .LeftMargin = CentimetersToPoints(1.27)
        .RightMargin = CentimetersToPoints(1.27)
        .Gutter = CentimetersToPoints(0)
        .HeaderDistance = CentimetersToPoints(1.25)
        .FooterDistance = CentimetersToPoints(1.25)
        .PageWidth = CentimetersToPoints(21.59)
        .PageHeight = CentimetersToPoints(27.94)
        .FirstPageTray = wdPrinterDefaultBin
        .OtherPagesTray = wdPrinterDefaultBin
        .SectionStart = wdSectionNewPage
        .OddAndEvenPagesHeaderFooter = False
        .DifferentFirstPageHeaderFooter = False
        .VerticalAlignment = wdAlignVerticalTop
        .SuppressEndnotes = False
        .MirrorMargins = False
        .TwoPagesOnOne = False
        .BookFoldPrinting = False
        .BookFoldRevPrinting = False
        .BookFoldPrintingSheets = 1
        .GutterPos = wdGutterPosLeft
    End With
End Sub

Public Sub AddFontSample(fontIndex As Integer, fontName As String, text As String, boldFlag As Boolean, italicFlag As Boolean)
    With Selection
     'Show test string with selected font
     .Font.Name = fontName
     .Font.Size = 16
     .Font.bold = boldFlag
     .Font.italic = italicFlag
     .Font.Underline = wdUnderlineNone
     .TypeText text & Chr(11)
     
     Dim boldFontName As String
     Dim italicFontName As String
     If (boldFlag = True) Then
        boldFontName = ", Bold"
     End If
     If (italicFlag = True) Then
        italicFontName = ", Italic"
     End If
     
     'Show actual font name in document
     .Font.Name = "Times New Roman"
     .Font.Size = 9
     .Font.bold = False
     .Font.italic = False
     .Font.Underline = wdUnderlineSingle
     .TypeText "(" & fontName & boldFontName & italicFontName & ")"
     
     .InsertParagraphAfter
     .MoveDown Unit:=wdParagraph
    End With

End Sub

Public Sub ListInstalledFont()
    ClearDocumentContent
    SetupThinMargin
    SetupColumnsPerPage 2

    Application.ScreenUpdating = False

    Dim sampleText As String
    sampleText = InputBox("Enter some sample text")
    If sampleText = "" Then sampleText = "The quick brown fox jumps over the lazy dog"

    'For each installed font
    Dim fontIndex As Integer
    For fontIndex = 1 To FontNames.Count
     Dim currentFontName As String
     currentFontName = FontNames(fontIndex)
     
     'Create sample text
     AddFontSample fontIndex, currentFontName, sampleText, False, False
     AddFontSample fontIndex, currentFontName, sampleText, True, False
     AddFontSample fontIndex, currentFontName, sampleText, True, True
     AddFontSample fontIndex, currentFontName, sampleText, False, True
    Next
    
    Application.ScreenUpdating = True
End Sub
