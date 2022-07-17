#Hu Guo
#10.16.2018
#program 48 P141
##############################
def mainFn():
  file=pickAFile()
  pic=makePicture(file)
  turnRed(pic)
  explore(pic)
#############################
def turnRed(pic):
  gr=makeColor(134,149,64)
  for px in getPixels(pic):
    color=getColor(px)
    if distance(color,gr)<50.0:
      r=getRed(px)*2
      g=getGreen(px)
      b=getBlue(px)
      setColor(px,makeColor(r,g,b))