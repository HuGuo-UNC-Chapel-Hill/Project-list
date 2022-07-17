class SmartTurtle(Turtle):
  def drawSquare(self):
    for i in range(0,4):
      self.turnRight()
      self.forward()