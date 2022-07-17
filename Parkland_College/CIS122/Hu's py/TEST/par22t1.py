def subFn2():
  pic2=makePicture(pickAFile())
  spic2= makeEmptyPicture(w2/2,h2/2)
  sourceX = 0
  for targetX in range(0,int(w2/2)):
    sourceY = 0
    for targetY in range(0,int(h2/2)):
      color = getColor(getPixel(pic2,sourceX,sourceY))
      setColor(getPixel(spic2,targetX,targetY), color)
    sourceY = sourceY + 2
  sourceX = sourceX + 2