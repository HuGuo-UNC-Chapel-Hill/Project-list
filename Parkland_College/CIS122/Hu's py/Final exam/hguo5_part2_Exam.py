#Hu Guo
#Final exam - part 2
#11.12.2018
#use mainFn(path) to excute
#example: mainFn("C:\\Users\\GUO\\Desktop\\F2OUT.jpg")
###########################
def mainFn(path):
  global f1
  global widthf1,heightf1  
  global canvas2
  global widthc,heightc  
  f1=makePicture(pickAFile())
  widthf1,heightf1=getWidth(f1),getHeight(f1)
  cc=pickAColor()
  widthc,heightc=3*widthf1,3*heightf1 
  canvas2=makeEmptyPicture(widthc,heightc,cc)
  subFn1()                                        #subFn1 draw a rectangular border 
  subFn2()                                        #subFn2 copy the F1OUT.jpg image to four locations   
  subFn3()                                        #draw randomly on canvas
  subFn4()                                        #copy same file (F1OUT.jpg) to the center of the canvas                    
  pic=duplicatePicture(canvas2)
  writePictureTo(pic,path)
  explore(pic)
#########################################
def subFn1():                                     #subFn1 draw a rectangular border 
  t=draw(canvas2)                                 #introduce a mainClass for turtle 
  t.penUp()                                        
  t.moveTo(100,100)                               #move turtle to start point 
  t.setPenColor(blue)
  t.setPenWidth(40)
  t.penDown()
  t.drawhor()                                     #use the subclass draw a horizontal line 
  t.drawver()                                     #use the subclass draw a vertical line 
  t.drawhor()                                     #use the subclass draw a horizontal line 
  t.drawver()                                     #use the subclass draw a vertical line 
class draw(Turtle):                               #define the mainClass   
  def drawhor(self):                              #define the subclass to draw a horzontal line
    for i in range(1):
      self.turn(90)
      self.forward(widthc-200)
  def drawver(self):                              #define the subcalss to draw a vertical line
    for i in range(1):
      self.turn(90)
      self.forward(heightc-200)  
####################################
def subFn2():                                        #copy picture to canvas2
    #copy f1out to the left corner           
    targetX=0                                        #set start point on the canvas      
    for picX in range(0,widthf1):                    #loop the X value
      targetY=0                                      #set start ponit on the canvas 
      for picY in range(0,heightf1):                 #loop the Y value 
        colorC=getColor(getPixel(f1,picX,picY))      #copy pixels from the picture 
        setColor(getPixel(canvas2,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value  
      
    #copy f1out to the top right corner           
    targetX=widthc-widthf1                           #set start point on the canvas      
    for picX in range(0,widthf1):                    #loop the X value
      targetY=0                                      #set start ponit on the canvas 
      for picY in range(0,heightf1):                 #loop the Y value 
        colorC=getColor(getPixel(f1,picX,picY))      #copy pixels from the picture 
        setColor(getPixel(canvas2,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value    
      
    #copy f1out to the bottom left corner           
    targetX=0                                        #set start point on the canvas      
    for picX in range(0,widthf1):                    #loop the X value
      targetY=heightc-heightf1                       #set start ponit on the canvas 
      for picY in range(0,heightf1):                 #loop the Y value 
        colorC=getColor(getPixel(f1,picX,picY))      #copy pixels from the picture 
        setColor(getPixel(canvas2,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value  
      
    #copy f1out to the bottom right corner           
    targetX=widthc-widthf1                           #set start point on the canvas      
    for picX in range(0,widthf1):                    #loop the X value
      targetY=heightc-heightf1                       #set start ponit on the canvas 
      for picY in range(0,heightf1):                 #loop the Y value 
        colorC=getColor(getPixel(f1,picX,picY))      #copy pixels from the picture 
        setColor(getPixel(canvas2,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value   
      
##############################################################
import random
def subFn3():                                        #draw randomly on canvas
  tr=Turtle(canvas2)
  tr.setPenWidth(3)
  for i in range(6000):
    tr.setPenColor(makeColor(random.randint(1,255),random.randint(1,255),random.randint(1,255)))
    tr.forward(int(100*random.random()))
    tr.turn(int(90*random.random()))
    
################################################################
def subFn4():
   #copy f1out to the bottom right corner           
    targetX=widthc-widthf1*2                         #set start point on the canvas      
    for picX in range(0,widthf1):                    #loop the X value
      targetY=heightc-heightf1*2                     #set start ponit on the canvas 
      for picY in range(0,heightf1):                 #loop the Y value 
        colorC=getColor(getPixel(f1,picX,picY))      #copy pixels from the picture 
        setColor(getPixel(canvas2,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value         

                                  
                