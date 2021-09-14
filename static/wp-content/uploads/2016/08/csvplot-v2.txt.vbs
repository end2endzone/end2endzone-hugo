'
'Read more at: http://www.voiceguide.com/vghelp/source/html/modvbs.htm
'
'MSDN References:
' Range Members (Excel), https://msdn.microsoft.com/en-us/library/office/ff197454.aspx
' 

'Validate command line arguments
dim validArguments
validArguments = true
If WScript.Arguments.Count < 4 Then
  validArguments = false 'missing at least a serie
End If
If WScript.Arguments.Count mod 2 <> 0 Then
  validArguments = false 'a serie is missing a column index
End If
If validArguments = false Then
  Wscript.Echo "CSVPLOT v1.0"
  Wscript.Echo "Usage: csvplot.vbs inputCsvFilePath outputXlsFilePath serie1 serie2 serie3 ..."
  Wscript.Echo "       where a serie is defined by two column index (starting at 1) within the CVS file."
  Wscript.Echo "       ie: csvplot.vbs test.csv test.slx 1 2 1 3"
  Wscript.Echo "Note:  The application assumes that the first row of all columns is the column's title."
  Wscript.Quit
End If

'Extract input and output filenames
dim inputFilePath
dim outputFilePath
inputFilePath   = WScript.Arguments.Item(0)
outputFilePath  = WScript.Arguments.Item(1)

'
'Excel constants definition:
'
'XlDirection enumeration: https://msdn.microsoft.com/en-us/library/office/microsoft.office.interop.excel.xldirection.aspx
const xlDown    = -4121
const xlToLeft  = -4159
const xlToRight = -4161
const xlUp      = -4162

'XlChartType enumeration: https://msdn.microsoft.com/en-us/library/office/microsoft.office.interop.excel.xlcharttype.aspx
const xlXYScatterLines = 74
const xlLineMarkers = 65

'XlChartLocation enumeration: https://msdn.microsoft.com/en-us/library/office/microsoft.office.interop.excel.xlchartlocation.aspx
const xlLocationAsNewSheet = 1
const xlLocationAsObject = 2

const xlCategory = 1
const xlPrimary = 1
const xlValue = 2

'Excel SaveAs file formats
const EXCEL_FILEFORMAT_XLS  = 51
const EXCEL_FILEFORMAT_XLSX = -4143


Dim xlApp, xlBook

Set xlApp = CreateObject("Excel.Application")
Wscript.Echo "Loading input file " & inputFilePath & "..."
set xlBook = xlApp.WorkBooks.Open(inputFilePath)

Wscript.Echo "File load succesful."
Wscript.Echo "File has " & xlApp.ActiveSheet.UsedRange.Columns.Count & " columns."

'Prevent showing popups to the user
xlApp.DisplayAlerts = False

'Plot a graph for ....
CreateNewEmptyChart xlApp 

'loop through all series
dim i
For i = 2 to WScript.Arguments.Count - 1 Step 2
  dim xColumnIndex
  dim yColumnIndex
  xColumnIndex = CInt(WScript.Arguments.Item(i))
  yColumnIndex = CInt(WScript.Arguments.Item(i+1))
  Wscript.Echo "Plotting serie of columns " & xColumnIndex & " and " & yColumnIndex & "..."

  CreateChartSerie xlApp, xColumnIndex, yColumnIndex
Next


'Save as
xlBook.SaveAs outputFilePath, EXCEL_FILEFORMAT_XLS
xlBook.Close true 'SaveChanges=True

xlApp.Quit

'deallocate
set xlSht  = Nothing
Set xlBook = Nothing
Set xlApp = Nothing

Wscript.Echo "File " & outputFilePath & " saved succesfully."



'
'Creates a new empty Chart on the current active sheet
'
Sub CreateNewEmptyChart(xlApp)
    xlApp.ActiveSheet.Shapes.AddChart.Select

    xlApp.ActiveChart.ChartType = xlLineMarkers
    xlApp.ActiveChart.SeriesCollection.NewSeries
    
    'Delete any series that Excel might have automaticaly created for us
    'msgbox "xlApp.ActiveChart.SeriesCollection.Count=" & xlApp.ActiveChart.SeriesCollection.Count
    While xlApp.ActiveChart.SeriesCollection.Count <> 0
        xlApp.ActiveChart.SeriesCollection(1).Delete
    Wend
    'msgbox "xlApp.ActiveChart.SeriesCollection.Count=" & xlApp.ActiveChart.SeriesCollection.Count
End Sub

'
'Gets the title of a given column on the ActiveSheet
'
Function GetColumnTitle(xlApp, columnIndex)
  GetColumnTitle = xlApp.ActiveSheet.Columns(columnIndex).Rows(1).Value
End Function

'
'Gets the range of a column on the ActiveSheet which contains a title as first row
' ie: "=Sheet1!$A$2:$A$37"
'
Function GetColumnRange(xlApp, columnIndex)
    dim str
    str = "=" & xlApp.ActiveSheet.Name & "!"

    'Find the address of the second row of the given column
    str = str & xlApp.ActiveSheet.Columns(columnIndex).Rows(2).Address 'rows 1 is the column's title

    str = str & ":"

    'Find the address of the last row of the given column
    str = str & xlApp.ActiveSheet.Columns(columnIndex).End(xlDown).Address 'rows 1 is the column's title

    'msgbox "str=" & str
    GetColumnRange = str
End Function

'
'Add a new serie in the current ActiveChart in the current ActiveSheet
'Note that function assumes that first row is column's title.
'
Sub CreateChartSerie(xlApp, xColumnIndex, yColumnIndex)
  xlApp.ActiveChart.SeriesCollection.NewSeries

  dim serieIndex
  serieIndex = xlApp.ActiveChart.SeriesCollection.Count

  xlApp.ActiveChart.SeriesCollection(serieIndex).Name = GetColumnTitle(xlApp, yColumnIndex)
  xlApp.ActiveChart.SeriesCollection(serieIndex).Values = GetColumnRange(xlApp, yColumnIndex)
  xlApp.ActiveChart.SeriesCollection(serieIndex).XValues = GetColumnRange(xlApp, xColumnIndex)
End Sub
