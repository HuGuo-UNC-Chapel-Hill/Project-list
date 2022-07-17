def smaller():
  pic=makePicture(pickAFile())
  pw,ph=getWidth(pic),getHeight(pic)
  canvas=makeEmptyPicture(pw/2,ph/2)
  sourceX=0
  for targetX in range(0,pw/2):
    sourceY=0
    for targetY in range(0,ph/2):
      color=getColor(getPixel(pic,sourceX,sourceY))
      setColor(getPixel(canvas,targetX,targetY),color)
      sourceY=sourceY+2
    sourceX=sourceX+2 
  show(canvas)   
  