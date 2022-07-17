#Hu Guo
#10 02
#program 23 
########################
def doubledutch(name):
  pile=""
  for letter in name:
   if letter.lower() in "aeiou":
    pile=pile+letter
   if not (letter.lower() in "aeiou"):
    pile=pile+letter+"u"+letter 
  print pile
  