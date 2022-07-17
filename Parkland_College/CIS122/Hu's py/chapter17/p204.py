#Hu Guo
#pro 205
#29.11.2018
#Turtle draw a Triangle
#example: Using mainFn(120) to execute
################
from time import sleep
def mainFn(size):
  w=World()
  turtle=makeTurtle(w)
  triangle(turtle,size)
########################
def triangle(turtle,size):
  for sides in range(3):
    forward(turtle,size)
    turn(turtle,120)
    sleep(0.3)