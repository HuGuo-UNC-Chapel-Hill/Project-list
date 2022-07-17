#!/usr/local/bin/python3
# I honor Parkland's core values by affirming that I have
# followed all academic integrity guidelines for this work.
# Hu Guo

from graph import Graph
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
    
    while wordlist[-1] == "":  # for the situation of entering empty lines at the end of the input list
        wordlist.pop()

    ver_list=[]

    for i in range(wordlist.index("#end")):  # process the vertex before "#end"
        if " " in wordlist[i]:  # raise error for invalid vertex
            raise TypeError('EMBEDDED SPACES---Invalid Vertex')
        else:  # map from vertex label to Vertex instance
            verts[wordlist[i]] = g.insert_vertex(wordlist[i])
            ver_list.append(wordlist[i])

    for i in range(wordlist.index("#end") + 1, len(wordlist)):  # process the edges after "#end"
        edges = wordlist[i].replace(",", "").split(" ")
        for v in edges:
            if v not in ver_list:
      #  if len(edges) != 2:  # raise error for invalid edges
                raise TypeError('EMBEDDED SPACES---Invalid edge')
        else:  # insert edges to graph object
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

    print("<table><tr><td><div align = 'center'><h3>")
    if cycle:
        del cycle[0] # delete the first vertex
        print("Cycle found in the graph.</br>")
        print(cycle,"</h3></td><td>")
    else:
        print("There is no cycle in the graph.</h3></td><td>")

    ###########################
    # Output the Graph as SVG #
    ###########################
    print("<svg height='800' width='1000' align = 'center'>")  # svg
    angle = 360 // len(verts.keys())  # get the angle between vertex

    ver1 = list(verts.keys())  # list to help process data

    for i in range(len(ver1)):  # use map to store anlge, circle center, and vertex string
        verts[ver1[i]] = [i * angle, 500, 350, str(ver1[i])]

    for v in verts.values():  # process data to each vertex and set the new center of each vertex
        x = int(200 * math.cos((math.radians(v[0]))))
        y = int(200 * math.sin((math.radians(v[0]))))
        v[1] += x
        v[2] += y

    for v in verts.values():  # draw vertex around a cricle
        print("<circle cx='{}' cy='{}' r='40' stroke='black' stroke-width='3' fill='gray' />".format(v[1], v[2]))
        print("<text x='{}' y='{}' fill='vlack'>{}</text>".format(int(v[1]) - 28, int(v[2]) + 3, v[3]))

    for v in g.vertices():  # iteration for the vertex
        if g.degree(v, outgoing=True) != 0:  # for vertex with outgoing edge as zero
            arrOrig = list(verts[str(v)])
            for e in g.incident_edges(v):  # for vertex with outgoing edges
                str1 = str(e)
                arr = str1.replace(" ", "").split(",")
                arrDest = list(verts[arr[1]])
                x = arrOrig[1] - arrDest[1]  # data to calculate the path
                y = arrOrig[2] - arrDest[2]  # data to calculate the path
                #   diffectent condition to draw the path and triangle at the end of each path
                if x > 0 and y < 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] + (40 * math.sin(degree1))
                    y1 = arrOrig[2] + (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] + (40 * math.cos(degree2)) - 3
                    y2 = arrDest[2] + (40 * math.sin(degree2)) - 10
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x < 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2)) + 3
                    y2 = arrDest[2] - (40 * math.sin(degree2)) + 10
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x < 0 and y < 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] + (40 * math.sin(degree1))
                    y1 = arrOrig[2] + (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2)) - 10
                    y2 = arrDest[2] - (40 * math.sin(degree2)) + 4
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x > 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] + (40 * math.cos(degree2)) + 10
                    y2 = arrDest[2] + (40 * math.sin(degree2)) - 4
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x > 0 and y == 0:
                    x1 = arrOrig[1] - 40
                    y1 = arrOrig[2] + 3
                    x2 = arrDest[1] + 50
                    y2 = arrDest[2] + 3
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x < 0 and y == 0:
                    x1 = arrOrig[1] + 40
                    y1 = arrOrig[2] - 3
                    x2 = arrDest[1] - 50
                    y2 = arrDest[2] - 3
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x == 0 and y > 0:
                    x1 = arrOrig[1] + 3
                    y1 = arrOrig[2] - 40
                    x2 = arrDest[1] + 3
                    y2 = arrDest[2] + 50
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                if x == 0 and y < 0:
                    x1 = arrOrig[1] - 3
                    y1 = arrOrig[2] + 40
                    x2 = arrDest[1] - 3
                    y2 = arrDest[2] - 50
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
    print("</svg></td></tr></table>")


