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

if submit == "Words":
    wordlist = bigbox.split()
    print("<text>The number of words are {}.</text><br/>".format(len(wordlist)))

    total_length = 0
    for i in wordlist:
        total_length += len(i)
    average_length = total_length / len(wordlist)
    print("<text>The average length of words are {:.4f}.</text><br/>"
          .format(average_length))
    wordlist.sort()

    word_count = 0
    if len(wordlist) < 400:
        print("<text>The first {} words in the table.</text><br/>"
              .format(len(wordlist)))
    else:
        print("<text>The first 400 words in the 10 x 40 table.</text><br/>")
    
def pt(alist):
    count = 0
    word_number = 400
    str=""
    str+="<table>"
    str+="<tr>"
    for word in alist:
        if count < 10:
            str+= "<td>{}</td>".format(word)
            count += 1
            word_number -= 1
        if count % 10 == 0:
            str+="</tr>"
            str+="<tr>"
            count = 0
        if word_number == 0:
            break
    str+="</tr>"
    str+="</table>"
    return str
    

    
    
