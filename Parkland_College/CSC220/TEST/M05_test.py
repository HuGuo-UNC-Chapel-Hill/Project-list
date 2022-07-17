#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

import cgi, cgitb

cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')


def find_a_way(alist, current, path):
    # print(path)  # debugging
    # print(current)  # duugging
    # print(len(alist))

    if alist[0] >= len(alist) != 1:  # condition for False
        return str("Sorry. No way to win")

    for step in path:  # condition for False
        if alist[step] == 0 or path.count(step) > 1:
            return str("Sorry. No way to win")

    if current == len(alist) - 1:  # condition for True with single element list
        path.append(current)
        string_win = "Positions visited: "
        for step in path:
            string_win += str(step)
            string_win += "-->"
        string_win += "Win"
        return string_win

    if current + alist[current] < len(alist):
        path.append(current)
        if current + alist[current] in path:
            return find_a_way(alist, path[len(path) - 1] - alist[path[len(path) - 1]], path)
        else:
            return find_a_way(alist, current + alist[current], path)
    if current + alist[current] >= len(alist):
        if path[len(path) - 1] - alist[path[len(path) - 1]] < 0:
            path.append(current)
            return find_a_way(alist, current-alist[current], path)
        else:
            return find_a_way(alist, path[len(path) - 1] - alist[path[len(path) - 1]], path)


pathway = []  # list to record solution
wordlist = []  # list for hold the numbers

if submit == "Find a way":
    for i in bigbox.split():
        wordlist.append(int(i))
    print("<div align = \"center\"><h3>M05_Recursion hguo5</h3>")
    print("For list of <text style=\"background-color"
          ":antiquewhite\">{}</text>.".format(wordlist) + "</br>")
    print(find_a_way(wordlist, 0, pathway))
    print("</div>")