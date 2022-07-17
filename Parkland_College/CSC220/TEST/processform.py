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

def totle_and_average_length(alist):
    print("<div align = \"center\">") 
    print("<h3>M04_text_processing hguo5</h3>")
    print("<font size =\"+1\">The number of original words are {}.</font><br/>"
          .format(len(alist)))  # output the total number of words

    total_length = 0  # calculate the average length of text
    for i in alist:
        total_length += len(i)
    average_length = total_length / len(alist)
    print("<font size =\"+1\">The average length of original words are {:.4f}.</font><br/>"
          .format(average_length))

def delete_Cap_repeat(alist): 
    for i in range(len(wordlist)):      # to eliminate upper cases 
        wordlist[i] = wordlist[i].lower()
        
    output = []     # to eliminate duplicate words
    [output.append(w) for w in wordlist if w not in output]
    output.sort()
    return output

def word_table(alist): # function to output the 10X40 table
    count = 0  # counter for 10 coloum
    word_number = 400  # counter for 400 words in the table
    print("<table>")
    print("<tr>")
    for word in alist:  # loop to output the 10X40 table
        if count < 10:  # output words to coloum
            print("<td>{}</td>".format(word))
            count += 1
            word_number -= 1
            # print(word_number)
        if count % 10 == 0:  # switch to next row
            print("</tr>")
            print("<tr>")
            count = 0
        if word_number == 0:  # stop the loop after 400 words
            break
    print("</tr>")
    print("</table>")
    print("</div>")


if submit == "Processing Text: output table with original words":          
    wordlist = bigbox.split()
    totle_and_average_length(wordlist)
    wordlist.sort()  # sort the text
    print("<br/><font size =\"+1\">Table with capitalized and repeated words</font>")
    word_table(wordlist)
    
if submit == "Processing Text: table for all lowercase without repeating words":
    wordlist = bigbox.split()
    totle_and_average_length(wordlist)
    wordlist.sort()  # sort the text
    print("<br/><font size =\"+1\">Table without capitalized and repeated words</font>")
    word_table(delete_Cap_repeat(wordlist))