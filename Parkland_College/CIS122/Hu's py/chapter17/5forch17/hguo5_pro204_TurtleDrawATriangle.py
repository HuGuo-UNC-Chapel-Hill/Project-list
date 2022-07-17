#Hu Guo
#pro 205
#29.11.2018
#Turtle draws a Triangle
#example: Using mainClass(120) to execute
################
from time import sleep
def mainClass(size):
  w=World()
  turtle=makeTurtle(w)
  triangle(turtle,size)
########################
def triangle(turtle,size):
  for sides in range(3):
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.3)