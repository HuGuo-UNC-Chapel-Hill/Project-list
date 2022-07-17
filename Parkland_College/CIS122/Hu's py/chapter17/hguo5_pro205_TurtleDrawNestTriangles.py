#Hu Guo
#pro 205
#29.11.2018
#Turtle draws nest triangles
#example: using mainFn(120) to excute
################
from time import sleep
def mainFn(size):
  w=World()
  turtle=makeTurtle(w)
  cornerTri(turtle,size)
  nestedTri(turtle,size)
  triangle(turtle,size)
  
################################  
def triangle(turtle,size):
  turtle.setPenColor(blue)
  for sides in range(3):
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.1)
################################    
def nestedTri(turtle,size):
  turtle.setPenColor(green)
  if size<20:
    return
  for sides in range(3):
    nestedTri(turtle,size/2)
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.1)
#####################################
def cornerTri(turtle,size):
  turtle.setPenColor(red)
  if size<10:
    return
  for sides in range(3):
    forward(turtle,size)
    cornerTri(turtle,size/2)
    turn(turtle,120)
    sleep(0.01)