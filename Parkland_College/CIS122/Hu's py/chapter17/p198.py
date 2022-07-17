#Hu Guo
#27.11.2018
#Pro 198 Page 454
###########################
def mainClass():
  earth=makeWorld()
  smarty=SmartTurtle(earth)
  smarty.drawSquare()
class SmartTurtle(Turtle):
  def drawSquare(self):
    for i in range(0,4):
      self.turnRight()
      self.forward()
   