#Hu Guo
#pro 205
#29.11.2018
#Turtle draws nest triangles
#example: using mainFn(120) to excute
################
from time import sleep
def mainFn(size):
  w=makeEmptyPicture(600,200)
  turtle=makeTurtle(w)
  nestedTri(turtle,size)
  pic=duplicatePicture(w)
  writePictureTo(w,"C:\Users\GUO\Desktop\11\1.jpg")
def nestedTri(turtle,size):
  if size<20:
    return
  for sides in range(3):
    nestedTri(turtle,size/2)
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.1)