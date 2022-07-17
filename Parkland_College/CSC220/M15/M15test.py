#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from avl_tree import AVLTreeMap
from binary_search_tree import TreeMap
from linked_queue import LinkedQueue
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
    print(wordlist)
    
    blacklist = []
    
    
    for word in wordlist:
        if tree.get(str(word), d = True):
            blacklist.append(word)
            
         
    
    print(blacklist) 