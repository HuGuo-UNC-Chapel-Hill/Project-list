#Hu Guo
#10.16.2018
#program 48 P141
##############################
def mainFn():
  file=PickAFile()
  pic=makePicture(file)
  turnRed(pic)
  explore(pic)
#############################
def turnRed(pic):
  brown=makeColor(134,149,64)
  for px in getPixels(pic):
    color=getColore(px)
    if distance(color,brown)<50.0:
      r=getRed(px)*2
      g=getGreen(px)
      b=getBlue(px)
      setColor(px,makeColor(r,g,b))