#Hu Guo
#10.11
#mirror the front half of a word
###################################
def mirrohalf(string):
  pile=""
  for index in range(0,len(string)/2):
   pile=pile+string[index]
  for index in range(len(string)/2-1,-1,-1):
   pile=pile+string[index]
  print pile  