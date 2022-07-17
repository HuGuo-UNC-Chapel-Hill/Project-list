#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from graph import Graph
from svg import SVG_cycle
from bfs import *
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

    # set start vertex and end vertex if in the input list before"#end"
    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        if wordlist[i] == wordlist[i-1]:     # ignore the duplicate vertex
            pass
        if wordlist[i] == "START":  # set start vertex
            start_vertex = wordlist[i - 1]
        elif wordlist[i] == "END":  # set end vertex
            end_vertex = wordlist[i - 1]
        else:
            vertex_list.append(wordlist[i])     # store vertex to the list

    # print("<text>{}, {}, {}</text></br>".format(start_vertex, end_vertex, vertex_list))  # debugging

    # duplicate checking
    for v in vertex_list:
        # map from vertex label to Vertex instance
        verts[v] = g.insert_vertex(v)

    # process the edges after "#end"
    # set start vertex and end vertex if in the input list after "#end"
    for i in range(wordlist.index("#end") + 1, len(wordlist)):
        edges = wordlist[i].replace(",", "").split(" ")
        if edges[1] == "START":  # set start vertex
            start_vertex = edges[0]
        elif edges[1] == "END":  # set end vertex
            end_vertex = edges[0]
        else:
            for v in edges:
                if v not in vertex_list:  # raise error for invalid vertex
                    raise TypeError('Invalid Edges [{}]'.format(v))

                elif len(edges) != 2:  # raise error for invalid edges
                    raise TypeError('Invalid Edges [{}]'.format(v))

            # initialize edges in graph
            org = edges[0]
            dest = edges[1]
            g.insert_edge(verts[org], verts[dest], None)

    # condition for start vertex existing
    print("<table><tr><text>")
    if start_vertex:
        print("The start vertex is \"{},\" and the end vertex is \"{}.\"</text></tr></br></br><tr>"
              .format(start_vertex, end_vertex))

        bfsTree = {}
        BFS(g, verts[start_vertex], bfsTree)
        path = []  # list to store the path

        # modified codes from the professor's example
        starting = verts[start_vertex]
        ending = verts[end_vertex]
        currentSpot = ending;
        path.append(currentSpot.element())
        while currentSpot != starting:
            edgeToCurrentSpot = bfsTree[currentSpot]
            currentSpot = edgeToCurrentSpot.opposite(currentSpot)
            path.append(currentSpot.element())

        # reverse the sequence
        path.reverse()

        # output the path
        path[0] = str("Start point: ") + path[0]
        path[-1] = str("End point: ") + path[-1]
        for i in range(len(path)-1):
            print(path[i], "-->")
        print(path[-1], "</tr></br><tr>")

    # condition for no start vertex existing
    else:
        print("There is no a start point.</text></tr></br><tr>")

    # output the graph as a svg cycle
    SVG_cycle(verts, g)

    print("</tr></table>")













