#Hu Guo
#27.11.2018
#p201
##########################
def chase():
  earth=World()
  a1=makeTurtle(earth)
  b2=makeTurtle(earth)
  c3=makeTurtle(earth)
  d4=makeTurtle(earth)
  a1.penUp()
  a1.moveTo(10,10)
  a1.penDown()
  b2.penUp()
  b2.moveTo(10,400)
  b2.penDown()
  c3.penUp()
  c3.moveTo(400,10)
  c3.penDown()
  d4.penUp()
  d4.moveTo(400,400)
  d4.penDown()
  for i in range(0,300):
    chaseTurtle(a1,c3)
    chaseTurtle(c3,d4)
    chaseTurtle(d4,b2)
    chaseTurtle(b2,a1)
#######################
def chaseTurtle(t1,t2):
  t1.turnToFace(t2)
  t1.forward(4)   
