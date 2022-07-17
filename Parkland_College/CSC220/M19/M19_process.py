#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from graph import Graph
from svg import SVG_cycle
import cgi, cgitb

cgitb.enable()


print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')

g = Graph(directed=True)  # create a Graph object

verts = {}  # map object to store the vertex

if submit == "Process text":
    wordlist = bigbox.replace("\r", "").split("\n")  # process the submission

    # print(wordlist,"</br>")   # debugging

    if wordlist[-1] == "":  # for the situation of entering a new line at the end of the input list
        wordlist.pop()

    duplicate_check = []
    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        duplicate_check.append(wordlist[i])

    # print(duplicate_check)    # debugging

    for v in duplicate_check:
        if duplicate_check.count(v) > 1:    # duplicate vertex checking
            raise TypeError('Duplicate Vertex Found [{}]'.format(v))

        else:  # map from vertex label to Vertex instance
            verts[v] = g.insert_vertex(v)

    # print(verts, "</br>") # debugging

    # for v in g.vertices():    #degging
    #    print("The data is {}".format(v), "</br>")

    for i in range(wordlist.index("#end") + 1, len(wordlist)):  # process the edges after "#end"
        edges = wordlist[i].replace(",", "").split(" ")
        for v in edges:
            if v not in duplicate_check:    # raise error for invalid vertex
                raise TypeError('Invalid Edges [{}]'.format(v))

            elif len(edges) != 2:  # raise error for invalid edges
                raise TypeError('Invalid Edges [{}]'.format(v))

        # initialize edges in graph
        org = edges[0]
        dest = edges[1]
        g.insert_edge(verts[org], verts[dest], None)

    print("<div align = 'center'><h3>M19 Graph 1 hguo5</h3>")  # specific html codes for the output webpage
    print("<table bgcolor='' border='1' cellpadding='1' width='700'>")
    print("<tr> <td align = 'center'> VERTEX NAME</td><td align = 'center'> OUTGOING EDGES</td></tr>")

    for v in g.vertices():  # iteration for the vertex
        print("<tr> <td align = 'center'> {} </td><td align = 'center'>".format(v))
        if g.degree(v, outgoing=True) == 0:  # for vertex with outgoing edge as zero
            print("None")
        for e in g.incident_edges(v):  # for vertex with outgoing edges
            str1 = str(e)
            arr = str1.replace(" ", "").split(",")
            print(arr[1], "</br>")
        print("</td></tr>")

    print("</table>")
    print("</div>")

    # for extra points
    # output the graph as a svg cycle
    SVG_cycle(verts, g)

