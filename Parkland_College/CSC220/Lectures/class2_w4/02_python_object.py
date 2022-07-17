#!/usr/local/bin/python3

# htmlTable
# clickme.py

import cgi, cgitb   # system folder at first then local folder
from html_table import HtmlTable
# import html_table
cgitb.enable()

print("Content-type: text/html\n")
w = HtmlTable(2, 4)
w.setdata(0, 0, "Row 1A")
w.setdata(0, 1, "Row 1B")
w.setdata(0, 2, "Row 1C")
w.setdata(0, 3, "Row 1D")
w.printHtml(10)
# w = html_table.HtmlTable()
# print(w)

# print("Hello web")
# pront("Duh!")

