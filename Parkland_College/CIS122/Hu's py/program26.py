#Hu Guo
#10 02
#program 26 
########################
def mirrorHalfString2(string): 
  pile=""
  for index in range(0,len(string)/2):
    pile=pile+string[index]
  for index in range((len(string)/2)-1,-1,-1):
    pile=pile+string[index]
  print pile