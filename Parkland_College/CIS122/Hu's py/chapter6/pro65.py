#Hu Guo
#11.1
#pro65
#yellow box
#################
from time import clock
def mainFn():
  pic=makePicture(pickAFile())
  yellowbox1(pic)
  yellowbox2(pic)
  explore(pic)
###############################
def yellowbox1(pic):
  start=clock()
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    if 100<=x<200 and 100<=y<200:
      setColor(px,yellow)
  print"Time:", clock()-start
  
################################
def yellowbox2(pic):
  start=clock()
  for x in range(250,350):
    for y in range(250,350):
      setColor(getPixel(pic,x,y),yellow)
  print"Time:",clock()-start      
     
 
     
     