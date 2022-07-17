# create a server or customer
inputbox = """ken 23
keith 43
karl 14
kevin 66"""

print (inputbox)

#split the inputbox into a list of separate items
items = inputbox.split("\n")

for item in items:
  print ("Item is [{}]".format(item))
  # convert each item to a pair of string
  (name, value) = item.split()  # split on space
  value = int(value)            # turn value into an integer
  # I use value + 1 to show that it's an integer
  print ("  The name is [{}] and the value+1 is [{}] ".format(name, value+1))