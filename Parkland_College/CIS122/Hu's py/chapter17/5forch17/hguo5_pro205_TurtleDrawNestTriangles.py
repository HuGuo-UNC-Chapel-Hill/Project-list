#Hu Guo
#pro 205
#29.11.2018
#Turtle draws nest triangles
#example: using mainClass(120) to excute
################
from time import sleep
def mainClass(size):
  w=World()
  turtle=makeTurtle(w)
  triangle(turtle,size)
  nestedTri(turtle,size)
################################  
def triangle(turtle,size):
  for sides in range(3):
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.1)
################################    
def nestedTri(turtle,size):
  if size<20:
    return
  for sides in range(3):
    nestedTri(turtle,size/2)
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.1)