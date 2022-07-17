#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

import cgi, cgitb
from table_class import Table
cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')


if submit == "Evaluating Statements":
    wordlist = bigbox.replace(" ", "").replace("\r", "").split("\n")
               
    print("<div align = \"center\"><h3>M10_Multiple_Assignment hguo5</h3>")
    print("<table><tr><td>")
    print("<div align = \"center\"> <table>")
    print("<td align='center'>Input </td>")

    print("<tr><td align='center'><textarea rows='20' cols='20' name='input'>")
    for i in range(len(wordlist)):
        print(wordlist[i])
    print("</textarea></br><font size=\"+2\"></font></br></td>")
 
    print("<tr align='center'><td></td><td><td></td></tr>")
    print("</table></div><td>")
    print("<table bgcolor='antiquewhite' border='2' width='220%'\
           align='center'><tr><th>Output</th></tr>")
    variable_table = Table()
    for i in range(len(wordlist)):
        if wordlist[i][0] == "D":
            print("<tr align='center'><td>Printing all variables:</td></tr>")
            variable_table.output()
        elif wordlist[i][0] == "N":
            print("<tr align='center'><td>Hu Guo</td></tr>")
        else:
            (left, right) = wordlist[i].split(":=")
            variable_table.manipulation(left, right)
    print("</td></tr></table>")
    
