class HtmlTable:
    def __init__(self, rows, cols):
        #        self._property = "This is a property"
        self._rows = rows
        self._cols = cols
        self._tbaledata = [["" for i in range(cols)] for j in range(rows)]

    def __str__(self):
        #        return self._property
        return " size = ({} rows, {} cols)".format(self._rows, self._cols)

    def setdata(self, row, col, data):
        # TODO error checking!!!
        self._tbaledata[row][col] = data

    def getdata(self, row, col):
        # TODO error checking!!!
        return self._tbaledata[row][col]

    def printHtml(self, border=0):
        print("<table border='{}'>".format(border))
        for row in range(self._rows):
            print("<tr>")
            for col in range(self._cols):
                print("<td>{}</td>".format(self.getdata(row, col)))
            print("</tr>")
        print("</table>")


# unit testing
if __name__ == "main":
    #    txtt = HtmlTable()  #call __init__
    txxt = HtmlTable(2, 4)
    print(txtt)  # converts to a string using __str__
    # set some data
    txtt.setdata(0, 0, "upper left")
    txtt.setdata(1, 4, "lower right")
    print(txtt.getdata(0, 0))
    print(txtt.getdata(1, 4))
    txtt.printHtml()
