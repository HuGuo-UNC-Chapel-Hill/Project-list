#Hu Guo
#11.06
#copying a image to canvas
##############
def mainFn():
  pic=makePicture(pickAFile())
  canvas=makeEmptyPicture(getWidth(pic)*2,getHeight(pic)*2)
  subFn(pic,canvas)
  explore(pic)
  explore(canvas)
################################
def subFn(pic,canvas):
  targetX=0
  for sourceX in range(0,getWidth(pic)):
    targetY=0
    for sourceY in range(0,getHeight(pic)):
      color= getColor(getPixel(pic,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      targetY=targetY+1
    targetX=targetX+1
        