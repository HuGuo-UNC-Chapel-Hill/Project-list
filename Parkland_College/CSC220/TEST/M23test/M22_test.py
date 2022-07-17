#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from exceptions import Empty
from graph import Graph
from shortest_paths import *
from svg_weight import SVG_cycle_weight
from construct_path import Mod_construct_path
import cgi, cgitb

cgitb.enable()

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')

g = Graph(directed=True)  # create a Graph object
verts = {}  # map object to store the vertex
start_vertex = ""  # string to store the start vertex
end_vertex = ""    # string to store the end vertex
vertex_list = []   # list to store vertices only

if submit == "Process text":
    print("<div align = 'center'><h3>M21 Graph 3 hguo5</h3>")  # specific html codes for the output webpage

    wordlist = bigbox.replace("\r", "").split("\n")  # process the submission

    # print(wordlist,"</br>")   # debugging

    while wordlist[-1] == "":  # delete empty lines at the end of the input list
        wordlist.pop()

    # process the input list before"#end"
    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        if wordlist[i] == wordlist[i-1]:     # ignore the duplicate vertex
            pass
        elif wordlist[i] == "START":  # set start vertex
            start_vertex = wordlist[i - 1]
        elif wordlist[i] == "END":  # set end vertex
            end_vertex = wordlist[i - 1]
        else:
            vertex_list.append(wordlist[i])  # store vertex to the list

    # initialize vertices in graph
    for v in vertex_list:
        # map from vertex label to Vertex instance
        verts[v] = g.insert_vertex(v)

    # process the edges after "#end"
    for i in range(wordlist.index("#end") + 1, len(wordlist)):
        edges = wordlist[i].replace(",", "").split(" ")

        if edges[0] == "START":  # set start vertex
            start_vertex = edges[1]
        if edges[1] == "END":  # set end vertex
            end_vertex = edges[0]

        # ignore the invalid edges
        elif edges[0] not in vertex_list:
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

    tree_edges = {}
    distanceMap = shortest_path_lengths(g, verts[start_vertex])
    tree_edges = shortest_path_tree(g, verts[start_vertex], distanceMap)


    print("<h3><tr><text>")
    # output the shortest path
    print(Mod_construct_path(verts[start_vertex], verts[end_vertex], tree_edges))

    print("</text></tr></h3>")
    SVG_cycle_weight(verts, g)