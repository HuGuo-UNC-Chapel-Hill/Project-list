#hu Guo
#10.21.18
#index study
#####################
def mirrorhalf(source):
  pile=""
  for index in range(0,len(source)/2):
    pile=pile+source[index]
  for index in range(len(source)/2-1,-1,-1):
    pile=pile+source[index]
  print pile  
  
######################
def reverse2(source):
  pile=""
  for index in range(len(source)-1,-1,-1):
    pile=pile+source[index]
  print pile
  
def separate(source):
  evens=""
  odds=""
  for index in range(len(source)):
    if index%2==0:
        evens= evens+source[index]
    if not index%2==0:
        odds=odds+source[index]
  print "evens: "+evens
  print "odds: "+odds          
  