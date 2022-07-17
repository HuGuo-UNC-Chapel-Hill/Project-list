#!/usr/local/bin/python3

import cgi, cgitb

cgitb.enable()


def binSearch(alist, lo, hi, lookingFor):
    """ alist is a sorted list we are searching
    lo is the lowest index it might be at
    hi is the highest index it might be at
    lookingFor is what we're looking for. """

    print(lookingFor)
    if lo > hi:
        return "not found"
    mid = (lo + hi) // 2
    if lookingFor < alist[mid]:
        return binSearch(alist, lo, mid - 1, lookingFor)
    elif lookingFor > alist[mid]:
        return binSearch(alist, mid + 1, hi, lookingFor)
    else:  # lookingFor == alist[mid]
        return "found"



print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')
lookingfor = aform.getvalue('lookingfor')

print("<p>You typed {} in the message area then hit {}</p>".format(bigbox, submit))

if submit == "Lines":
    linelist = bigbox.split("\n")
    for line in linelist:
        print("line: [{}]<br>".format(line))
elif submit == "Words":
    wordlist = bigbox.split()
    for word in wordlist:
        print("word: [{}]<br>".format(word))
elif submit == "Search":
    wordlist = bigbox.split()
    wordlist.sort()
    # for word in wordlist:
    #    print ("word: [{}]<br>".format(word))
    print(binSearch(wordlist, 0, len(wordlist) - 1, lookingfor))