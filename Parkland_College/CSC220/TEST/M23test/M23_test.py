#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo


from graph import Graph
from svg_ud_weight import SVG_cycle_ud_weight
from mst import *

import cgi, cgitb

cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')

g = Graph()  # create a Graph object
verts = {}  # map object to store the vertex
vertex_list = []   # list to store vertices only
Prim_tree = []
Krus_tree = []


if submit == "Process text":

    wordlist = bigbox.replace("\r", "").split("\n")  # process the submission

    # print(wordlist,"</br>")   # debugging

    while wordlist[-1] == "":  # delete empty lines at the end of the input list
        wordlist.pop()

    # process the input list before"#end"
    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        if wordlist[i] == wordlist[i-1]:     # ignore the duplicate vertex
            pass
        else:
            vertex_list.append(wordlist[i])  # store vertex to the list

    # initialize vertices in graph
    for v in vertex_list:
        # map from vertex label to Vertex instance
        verts[v] = g.insert_vertex(v)

    # process the edges after "#end"
    for i in range(wordlist.index("#end") + 1, len(wordlist)):
        edges = wordlist[i].replace(",", "").split(" ")

    #    debugging
    #    print("<text>")
    #    print(vertex_list, "</br>")
    #    print(list(verts.keys()), "</br>")
    #    print(edges, "</br>")
    #    print("</text>")

        if edges[0] not in vertex_list:
            pass
        elif edges[1] not in vertex_list:
            pass
        elif len(edges) != 3:
            pass

        else:
            # initialize edges in graph
            org = edges[0]
            dest = edges[1]
            element = float(edges[2])
            g.insert_edge(verts[org], verts[dest], element)

    print("<div align = 'center'><h3>M21 Graph 3 hguo5</h3>")  # specific html codes for the output webpage
    print("<table><tr><td align = 'center'><text style='font-size:22px'>")

    Prim_tree = MST_PrimJarnik(g)
    Prim_total_weight = float(0.0)
    print("The edges in Prim-Jarnik MST are: </br>")
    for e in Prim_tree:
        Prim_total_weight += e.element()
        print(e, "</br>")
    print("The total weight of Prim-Jarnik MST is {}.</br>".format(round(Prim_total_weight, 1)))
    SVG_cycle_ud_weight(verts, g, Prim_tree)

    print("</text></td><td align = 'center'></td><td align = 'center'><text style='font-size:22px'>")
    Krus_tree = MST_Kruskal(g)
    Krus_total_weight = float(0.0)
    print("The edges in Kruskal MST are: </br>")
    for e in Krus_tree:
        Krus_total_weight += e.element()
        print(e, "</br>")
    print("The total weight of Kruskal MST is {}.</br>".format(round(Krus_total_weight, 1)))
    SVG_cycle_ud_weight(verts, g, Krus_tree)
    print("</text></td></tr></table>")

