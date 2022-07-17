#Hu Guo
#10.21.18
####################
def duplicate(source):
  pile=""
  for letter in source:
    pile=pile+letter
  print pile
  
##################
def reverse(source):
  pile=""
  for letter in source:
    pile=letter+pile
  print pile

###################
def doubble(source):
  pile=""
  for letter in source:
    pile=pile+letter+letter
  print pile      

############################
def mirror(source):
  pile=""
  for letter in source:
    pile=letter+pile
  print source + pile  