alist = ['a','b','c','d','e']

print ( id(alist) )
print ( id(alist[0]) )
print ( id(alist[1]) )
print ( id(alist[2]) )
print ("done with the list\n")
temp = alist[0]
print ( id(temp) )
print ( id(alist[0]) )
print ("done with the temp\n")

alist[0] += '?'
print ( id(temp) )
print ( id(alist[0]) )
print ("done modifing alist[0]\n")