#Hu Guo
#10.13
#negate.py
#commond mainFn("color") or mainFn("gray")
####################################
def mainFn(key):
  colorFn()
  negrFn()
  grayFn()
#####################################
def mainFn(key):  
  if key == "color":
   colorFn()
  elif key == "negr":
   negrFn() 
  elif key == "gray":
   grayFn()
  else:
   print 'you must enter either "gray" or "color"' 
##################################
def colorFn():
  myfile=pickAFile()
  mypic=makePicture(myfile)
  for pixel in getPixels(mypic):
    red=getRed(pixel)
    green=getGreen(pixel)
    blue=getBlue(pixel)
    negColor=makeColor(255-red, 255-green, 255-blue)
    setColor(pixel,negColor)
  explore(mypic) 
################################
def grayFn():
  myfile=pickAFile()
  mypic=makePicture(myfile)
  for pixel in getPixels(mypic):
   intensity = (getRed(pixel)+getGreen(pixel)+getBlue(pixel))/3
   negra=makeColor(intensity,intensity,intensity)
   setColor(pixel,negra)
  explore(mypic) 
############################
def negrFn():
  myfile=pickAFile()
  mypic=makePicture(myfile)
  for pixel in getPixels(mypic):
   intensity = (getRed(pixel)+getGreen(pixel)+getBlue(pixel))/3
   negra=makeColor(255-intensity,255-intensity,255-intensity)
   setColor(pixel,negra)
  explore(mypic) 
     