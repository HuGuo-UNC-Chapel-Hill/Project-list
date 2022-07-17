#Hu Guo
#program 15 page 51
#print just the wowels
################################
def justvowels(string):
 for letter in string:
  if letter in "aeiou":
   print letter
################################   
def notvowels(string):
 for letter in string:
  if not (letter in "aeiou"):
   print letter
   