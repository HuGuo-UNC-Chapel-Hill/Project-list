import math


def SVG_cycle_ud_weight(verts, g, tree):  # output the graph as a svg cycle
    print("<svg height='700' width='500' align = 'center'>")  # svg
    angle = 360 // len(verts.keys())  # get the angle between vertex

    ver1 = list(verts.keys())  # list to help process data

    for i in range(len(ver1)):  # use map to store anlge, circle center, and vertex string
        verts[ver1[i]] = [i * angle, 250, 350, str(ver1[i])]

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
                    x2 = arrDest[1] + (40 * math.cos(degree2))
                    y2 = arrDest[2] + (40 * math.sin(degree2))
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 - 40, y3, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 - 40, y3, weight))
                if x < 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2))
                    y2 = arrDest[2] - (40 * math.sin(degree2))
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 + 15, y3, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 + 15, y3, weight))

                if x < 0 and y < 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] + (40 * math.sin(degree1))
                    y1 = arrOrig[2] + (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] - (40 * math.cos(degree2))
                    y2 = arrDest[2] - (40 * math.sin(degree2))
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 - 40, y3, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 - 40, y3, weight))
                if x > 0 and y > 0:
                    degree1 = math.atan(x / y)
                    x1 = arrOrig[1] - (40 * math.sin(degree1))
                    y1 = arrOrig[2] - (40 * math.cos(degree1))
                    degree2 = math.atan(y / x)
                    x2 = arrDest[1] + (40 * math.cos(degree2))
                    y2 = arrDest[2] + (40 * math.sin(degree2))
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 + 10, y3, weight))
                    else:

                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 + 10, y3, weight))
                if x > 0 and y == 0:
                    x1 = arrOrig[1] - 40
                    y1 = arrOrig[2] + 3
                    x2 = arrDest[1] + 40
                    y2 = arrDest[2] + 3
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3, y3 + 18, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3, y3 + 18, weight))
                if x < 0 and y == 0:
                    x1 = arrOrig[1] + 40
                    y1 = arrOrig[2] - 3
                    x2 = arrDest[1] - 40
                    y2 = arrDest[2] - 3
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3, y3 - 8, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3, y3 - 8, weight))
                if x == 0 and y > 0:
                    x1 = arrOrig[1] + 3
                    y1 = arrOrig[2] - 40
                    x2 = arrDest[1] + 3
                    y2 = arrDest[2] + 40
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 + 8, y3, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 + 8, y3, weight))
                if x == 0 and y < 0:
                    x1 = arrOrig[1] - 3
                    y1 = arrOrig[2] + 40
                    x2 = arrDest[1] - 3
                    y2 = arrDest[2] - 40
                    x3 = (x1 + x2) / 2
                    y3 = (y1 + y2) / 2
                    if e in tree:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='red' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='red'>({}</text>".format(x3 - 45, y3, weight))
                    else:
                        print("<path marker-end='url(#head)'stroke-width='4' fill='none' stroke='blue' "
                              "d='M{},{} {},{}'/> ".format(x1, y1, x2, y2))
                        print("<text x='{}' y='{}' class='small' fill='blue'>({}</text>".format(x3 - 45, y3, weight))

    print("</svg>")
