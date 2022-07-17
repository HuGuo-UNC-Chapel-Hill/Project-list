#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

import cgi, cgitb
from sorted_priority_queue import SortedPriorityQueue
cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')


if submit == "Process text":
    wordlist = list(str(bigbox.replace("\r", "")))
    # debugging
    # for i in range(len(wordlist)):
    #     print(wordlist[i])
    # print(" </br>")
    print("<div align = \"center\"><h3>M12_text compression (Huffman) hguo5</h3>")
    freq = {}

    for ch in wordlist:
        #freq[ch] += 1  # KeyError: '5'
        freq[ch] = freq.get(ch, 0) + 1
    
    # debugging
    print("</br>Initial Frequence Dictionary: </br>")
    for char in freq: 
        print("{}: {}".format(char, freq[char]))
    print("</br>")

    key = sorted(freq.keys())
    
    sorted_dict = {}
    sorted_keys = sorted(freq, key=freq.get)  # [1, 3, 2]
    
    # debugging
    # print(sorted_keys)
    for key in sorted_keys:
        sorted_dict[key] = freq[key]
        
    

    print("</br>Sorted Frequence Dictionary: </br>",sorted_dict, "</br>")
    
    codemap = {}
    for key in sorted_dict.keys():
        codemap[key]=""
    print("</br>Initial codemap: </br>", codemap, "</br>")

    headqueue= SortedPriorityQueue()

    for i in sorted_keys:
        headqueue.add(int(sorted_dict[i]), str(i))
    
    while len(headqueue)>1:
        freq1, freq2 = 0, 0
        str1, str2 = "",""
        freq1, str1 = headqueue.remove_min()
        for char in str1:
            codemap[char] = "0" + codemap.get(char, "")

        freq2, str2 = headqueue.remove_min()
        for char in str2:
            codemap[char] = "1" + codemap.get(char, "")

        headqueue.add(freq1+freq2, str1+str2)


    print("</br> Final Codemap: </br>", codemap)
