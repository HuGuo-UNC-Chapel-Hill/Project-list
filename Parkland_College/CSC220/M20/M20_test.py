#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from graph import Graph
from svg import SVG_cycle
import cgi, cgitb

cgitb.enable()
import math

print("Content-type: text/html\n")
aform = cgi.FieldStorage()
bigbox = aform.getvalue('bigbox')
submit = aform.getvalue('submit')

g = Graph(directed=True)  # create a Graph object

verts = {}  # map object to store the vertex

if submit == "Process text":
    wordlist = bigbox.replace("\r", "").split("\n")  # process the submission

    # print(wordlist,"</br>")   # debugging

    while wordlist[-1] == "":  # delete empty lines at the end of the input list
        wordlist.pop()

    duplicate_check = []
    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        duplicate_check.append(wordlist[i])

    # print(duplicate_check)    # debugging

    for i in range(len(duplicate_check)):
        if duplicate_check[i] == duplicate_check[i-1]:  # duplicate vertex checking
            pass

        else:  # map from vertex label to Vertex instance
            verts[duplicate_check[i]] = g.insert_vertex(duplicate_check[i])

    for i in range(wordlist.index("#end") + 1, len(wordlist)):  # process the edges after "#end"
        edges = wordlist[i].replace(",", "").split(" ")
        for v in edges:
            if v not in duplicate_check:  # raise error for invalid vertex
                raise TypeError('Invalid Edges [{}]'.format(v))

            elif len(edges) != 2:  # raise error for invalid edges
                raise TypeError('Invalid Edges')

        # initialize edges in graph
        org = edges[0]
        dest = edges[1]
        g.insert_edge(verts[org], verts[dest], None)

    worked_on = {}  # dictionary to record worked on vertices
    visited = {}    # dictionary to record visited vertices
    cycle = []


    def DFS_cycle(g, u):
        global cycle
        visited[u] = ""     # add vertex to dictionary
        worked_on[u] = ""   # add vertex to dictionary
    #    dict_out(worked_on) # debugging

        for e in g.incident_edges(u):
            v = e.opposite(u)
            if v in worked_on:  # condition for finding a cycle
                for k in worked_on:
                    cycle.append(str(k)) # record the circle
            if v not in visited:    # keep going through the graph
                visited[v] = ""
                DFS_cycle(g, v)

        del worked_on[u]    # delete the vertex as marking finished
    #    dict_out(worked_on) # debugging

    # print(verts.values(), "</br>")    #debugging
    print("<div align = 'center'><h3>M20 Graph 2 hguo5</h3>")  # specific html codes for the output webpage

    DFS_cycle(g, verts["vertex1"])

    print("<table ><tr><div align = 'center'></br></br></br><h3>")
    if cycle:
        if not g.get_edge(verts[cycle[-1]], verts[cycle[0]]):
            del cycle[0]    # delete the unrelated first vertex
        else:
            pass
        print("Cycle found in the graph.</br>")
        print(cycle, "</h3></tr>")
    else:
        print("There is no cycle in the graph.</h3></tr><tr>")

    # output graph as a svg cycle
    SVG_cycle(verts, g)

    print("</tr></table>")


