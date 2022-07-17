#Hu Guo
#10.16.2018
#program 49 P141
##############################
def mainFn():
  file=pickAFile()
  pic=makePicture(file)
  explore(pic)
  turnRed(pic)
#############################
def turnRed(pic):
  gre=makeColor(106,139,84)
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    if 50<=x<=500:
      if 210<=y<=350:
        color=getColor(px)
        if distance(color,gre)<50.0:
          r=getRed(px)*3
          g=getGreen(px)
          b=getBlue(px)
          setColor(px,makeColor(r,g,b))
  explore(pic)        