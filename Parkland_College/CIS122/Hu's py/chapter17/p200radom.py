#Hu Guo
#program 200
#29.11.2018
########################
from time import sleep
import random
def mainClass():
  myColor=makeColor(255,255,200)
  earth=makeEmptyPicture(640,400,myColor)
  t1=Turtle(earth)
  t1.setPenWidth(20)        #width of the line
  #t1.setPenWidth(random.randint(1,10))      #will choose random penwidth
  for times in range(1):
   for i in range(500):
    #t1.setPenColor(makeColor(random.randint(200,255),random.randint(200,150),random.randint(1,255))
    t1.setPenColor(makeColor(random.randint(1,255),random.randint(1,150),random.randint(1,255)))
    #t1.setPenWidrh(random.randint(25,75)) #take penwidth more and cover
    t1.forward(int(100*random.random()))
    t1.turn(int(90*random.random()))
    sleep(0.001)    #time between two linew drawing
    #writePictureTo(earth,"c:\\users\\)
  show(earth)  