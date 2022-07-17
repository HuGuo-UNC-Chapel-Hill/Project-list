#Hu Guo
#27.11.2018
#p200
##########################
def mainClass():
  earth=World()
  t1=makeTurtle(earth)
  t1.forward(100)
  t1.turn(90)
  bob=ConfusedTurtle(earth)
  bob.forward(100)
  bob.turn(90)
import random  
class ConfusedTurtle(Turtle):
  def forward(self,num):
    Turtle.forward(self,int(num*random.random()))
  def turn(self,num):
    Turtle.turn(self,int(num*random.random()))  