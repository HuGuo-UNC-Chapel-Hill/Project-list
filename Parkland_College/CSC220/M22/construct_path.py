# modified function from the textbook to return the results
def Mod_construct_path(u, v, discovered):
    string = ""
    string += str("The shortest path form {} to {} is: </br>".format(str(u), str(v)))
    path = []  # empty path by default
    edges = []  # empty path to store edges
    if v in discovered:
        # we build list from v to u and then reverse it at the end

        path.append(v)
        walk = v
        while walk is not u:
            e = discovered[walk]  # find edge leading to walk
            edges.append(e)
            parent = e.opposite(walk)
            path.append(parent)
            walk = parent
        path.reverse()  # reorient path from u to v
        edges.reverse()

    string += str(path[0])

    # calculate the total weight
    total_weight = 0
    for i in edges:
        total_weight += i.element()

    # output the results
    for i in range(0, len(edges)):
        (ori, des) = edges[i].endpoints()
        string += str("--({})-->{}".format(edges[i].element(), des))
    string += "</br>"
    string += str("The shortest path's total weight is {}.".format(round(total_weight, 1)))

    return string