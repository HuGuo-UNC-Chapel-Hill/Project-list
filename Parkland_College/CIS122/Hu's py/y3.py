#Hu Guo
#10.21
#y3.py
#########################
def grayScale(picture):
  pic=duplicatePicture(picture)
#  getPixels()#list
#  getPixle # pixel object
  for px in getPixels(pic): #[px1,px2,px3..] x,y,RGB
    Red=getRed(px)
    Green=getGreen(px)
    Blue=getBlue(px)
    grey=(Red+Green+Blue)/3
    greyColor=makeColor(grey,grey,grey)
    setColor(px,greyColor)
  show(pic) 
  
####################################################
def negative(picture):
  #loops through pixels
  #make a new color
  #set color
  #show
  pic=duplicatePicture(picture)
  for px in getPixels(pic):
    Red=getRed(px)
    Green=getGreen(px)
    Blue=getBlue(px)
    negativeColor=makeColor(255-Red,255-Green,255-Blue)
    setColor(px,negativeColor)
  show(pic)  
  
#####################################################
def bw(picture):
  pic=duplicatePicture(picture)
  for px in getPixels(pic):
    luminance=(getRed(px)+getGreen(px)+getBlue(px))/3
    if luminance<50:
      setColor(px, makeColor(50,50,50))
    elif luminance<100:
      setColor(px,makeColor(100,100,100))
    elif luminance<150:
      setColor(px,makeColor(150,150,150))
    elif luminance<200:
      setColor(px,makeColor(200,200,200)) 
    else:
      setColor(px,white)
  show(pic)          
    
      
      