#Hu Guo
#04.12.2018
#Turtle Drawing (a windMill under the sun)
#using mianFn(path) to excute
#example  mainFn("C:\\Users\\GUO\\Desktop\\wm.jpg")
##################################
def mainFn(path):
  canvas=makeEmptyPicture(640,480)
  t1=windmilldraw(canvas)
  t1.penUp()
  t1.turn(-90)
  t1.moveTo(220,220)
  t1.penDown()
  t1.setPenWidth(8)
  t1.setPenColor(red)
  t1.turn(90)  
  t1.drawRoof()      #subclass 1
  t1.turnToFace(220,220)
  t1.setPenColor(black)
  t1.setPenWidth(7)
  t1.drawHouse()     #subclass 2
  t1.turnToFace(220,220)  
  t1.forward(93)
  t1.turn(90)
  t1.penUp()
  t1.forward(30)
  t1.penDown()  
  t1.setPenColor(blue)
  t1.setPenWidth(5)
  t1.drawFan()       #subclass 3
  t1.penUp()
  t1.moveTo(100,40)
  t1.penDown()
  t1.setPenColor(yellow)
  t1.setPenWidth(4)
  t1.drawSun()       #subclass 4
  pic=duplicatePicture(canvas)
  show(pic)  
  writePictureTo(pic,path)
####################################  
class windmilldraw(Turtle):   
  def drawRoof(self):
    for i in range(11):
      self.turn(15)
      self.forward(25)
      
  def drawHouse(self):
    for i in range(0,4):
      self.forward(188)
      self.turnLeft()                 

  def drawFan(self):   
    self.forward(160)
    self.turn(150)
    self.forward(80)
    self.turn(60)
    self.forward(80)
    self.turn(-30)
    self.forward(160)
    self.turn(150)
    self.forward(80)
    self.turn(60)
    self.forward(80)
    self.turn(-30)
    self.forward(10)
    self.turn(90)
    self.forward(150)
    self.turn(150)
    self.forward(80)
    self.turn(60)
    self.forward(80)
    self.turn(-30)
    self.forward(150)
    self.turn(150)
    self.forward(80)
    self.turn(60)
    self.forward(80)
    
  def drawSun(self):
    for i in range(70):
      self.forward(90)
      self.turn(85)    
      
  

 
