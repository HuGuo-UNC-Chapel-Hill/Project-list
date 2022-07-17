#Hu guo
#p203
#29.11.2018
#Dancing Turtles
#using dance() to excute
######################
from time import sleep

def dance():
  makesquare()
#################  
def makesquare():
  w=makeWorld()
  evenlist=[]
  oddlist=[]
  for turtles in range(10):
    t= makeTurtle(w)
    t.turn(turtles*36)
    if turtles%2==0:
      evenlist=evenlist+[t]
    else:
      oddlist=oddlist+[t]
  for times in range(20):
    for sides in range(5):
      if times % 2==0:
        for t in evenlist:
          t.forward(100)
          t.turn(90)
      else:
        for t in oddlist:
          t.forward(100)
          t.turn(72)
      sleep(0.2)    