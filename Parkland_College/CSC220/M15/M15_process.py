#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from avl_tree import AVLTreeMap
import cgi, cgitb
cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')

tree = AVLTreeMap()

filename = "/home/staff/kurban/public/lists/web2.txt"
dictionaryFile = open(filename, "r")
i = 0
for word in dictionaryFile:
    tree[word.lower().replace("\r", "").replace("\n","")]=i
    i += 1

# for word in tree:
#    print(word)

if submit == "Process text":
    wordlist = bigbox.replace("\r", "").replace("\n","").split(" ")
    for i in range(len(wordlist)):
        wordlist[i] = wordlist[i].lower()
    # print(wordlist)
    
    blacklist = []
       
    for word in wordlist:
        if tree.get(str(word)) is None:
            blacklist.append(word)
    print("<div align = \"center\"><h3>M15_text Paragraph Analysis 4 hguo5</h3>")
    if len(blacklist) > 0:
        words = ""
        print("<table bgcolor='antiquewhite' border='2' width='700'\
           align='center'><tr><th>{} words are not in the dictionary:</th></tr><td align='center'>"
           .format(len(blacklist)))
        
        for i in range(len(blacklist)):
            words += blacklist[i] + " "
        #    if i % 8 == 7:
        #        words += "</br>"
        print("<textarea rows='12' cols='50'>")
        print(words)
        print("</textarea>")
        print("</td></tr></table>")
        
    else:
        print("<table bgcolor='antiquewhite' border='2' width='700'\
           align='center'><tr><th>All of words are included in the dictionary.</th></tr>")
            