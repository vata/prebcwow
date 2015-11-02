# Author:  Cain
# Date:    11 Oct 2005
# Purpose: - Making Win32Com to work in testing environment
#          - Simplify the call of the XLS functions (Like text_file.py)
# Status:  Testing Stage (Not Working)

import pythoncom
import win32com.client


class XLS:

    def __init__(self, filename=None):
        self.filename = filename
        self.dispatch = win32com.client.Dispatch("Excel.Application")
        self.constant = win32com.client.constants
        self.__init__(self.dispatch, filename)

    def Open(self):
      try:
        self.Workbooks.Open(self.filename)
      except pythoncom.com_error, (hr, msg, exc, arg):
        print "The Excel call failed with code %d: %s" % (hr, msg)
        if exc is None:
            print "There is no extended error information"
        else:
            wcode, source, text, helpFile, helpId, scode = exc
            print "The source of the error is", source
            print "The error message is", text
            print "More info can be found in %s (id=%d)" % (helpFile, helpId)

    def Save(self):
        book = self.Workbooks.Add()
        sheet = book.Worksheets(1)
        sheet.Range("A1").Value = "Hello World!"
        sheet.Range("A2").Value = str(Application.SIFilter(None, self.constant.siObjectFilter))
        book.SaveAs(self.filename)
        sheet = None
        book = None
        self.Quit()
        self = None
