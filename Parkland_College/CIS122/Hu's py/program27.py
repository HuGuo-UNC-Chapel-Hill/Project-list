def reverseString(string):
  pile=""
  for index in range(len(string)-1,-1,-1):
    pile=pile+string[index]
  print pile  