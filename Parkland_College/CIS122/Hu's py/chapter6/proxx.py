#Hu Guo
#11.06
#pro73
#copying a image to canvas
##############
def mainFn():
  pic=makePicture(pickAFile())
  canvas=makeEmptyPicture((530-130)*2,(288-17)*2)
  subFn1(pic,canvas)
  subFn2(pic,canvas)
  explore(pic)
  explore(canvas)
################################
def subFn1(pic,canvas):
  targetX=0
  for sourceX in range(130,530):
    targetY=0
    for sourceY in range(17,288):
      color= getColor(getPixel(pic,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      targetY=targetY+1
    targetX=targetX+1
#####################################
def subFn2(pic,canvas):
  targetX=getWidth(canvas)/2+1
  for sourceX in range(130,530):
    targetY=getHeight(canvas)/2-1
    for sourceY in range(17,288):
      color= getColor(getPixel(pic,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      targetY=targetY+1
    targetX=targetX+1
        