import math


def SVG_cycle_weight(verts, g):  # output the graph as a svg cycle
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
                weight = arr[2]
                #   diffectent condition to draw the path and triangle at the end of each path
                if x > 0 and y < 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] + (40 * math.sin(degree1))
                    y1 = arrOrig[2] + (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] + (40 * math.cos(degree2)) - 3
                    y2 = arrDest[2] + (40 * math.sin(degree2)) - 10
                    x3 = (x1 + x2)/2
                    y3 = (y1 + y2)/2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3-40, y3, weight))
                if x < 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2)) + 3
                    y2 = arrDest[2] - (40 * math.sin(degree2)) + 10
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3 + 20, y3, weight))
                if x < 0 and y < 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] + (40 * math.sin(degree1))
                    y1 = arrOrig[2] + (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2)) - 10
                    y2 = arrDest[2] - (40 * math.sin(degree2)) + 4
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3 - 40, y3, weight))
                if x > 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] + (40 * math.cos(degree2)) + 10
                    y2 = arrDest[2] + (40 * math.sin(degree2)) - 4
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3 + 10, y3, weight))
                if x > 0 and y == 0:
                    x1 = arrOrig[1] - 40
                    y1 = arrOrig[2] + 3
                    x2 = arrDest[1] + 50
                    y2 = arrDest[2] + 3
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3, y3 + 15, weight))
                if x < 0 and y == 0:
                    x1 = arrOrig[1] + 40
                    y1 = arrOrig[2] - 3
                    x2 = arrDest[1] - 50
                    y2 = arrDest[2] - 3
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3, y3 - 5, weight))
                if x == 0 and y > 0:
                    x1 = arrOrig[1] + 3
                    y1 = arrOrig[2] - 40
                    x2 = arrDest[1] + 3
                    y2 = arrDest[2] + 50
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3 + 8, y3, weight))
                if x == 0 and y < 0:
                    x1 = arrOrig[1] - 3
                    y1 = arrOrig[2] + 40
                    x2 = arrDest[1] - 3
                    y2 = arrDest[2] - 50
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    print("<defs> <marker id='head' orient='auto' markerWidth='2' markerHeight='4' refX='0.1' refY='2'>"
                          "<path d='M0,0 V4 L2,2 Z' fill='blue' /></marker></defs>")
                    print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                          "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                    print("<text x='{}' y='{}' class='small' fill='green'>({}</text>".format(x3 - 45, y3, weight))
    print("</svg></td></tr></table>")
