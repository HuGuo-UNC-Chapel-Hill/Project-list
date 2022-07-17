def blend():
  pic1=makePicture(pickAFile())
  pic2=makePicture(pickAFile())
  w1,h1,w2,h2=getWidth(pic1),getHeight(pic1),getWidth(pic2),getHeight(pic2)
  middlepic2=makeEmptyPicture(w1,h1)
  blendpic=makeEmptyPicture(w1,h1)
  targetX=0                            #set start point on the canvas
  for picX in range(w2/2-w1/2-50,w2/2+w1/2-50):      #loop the X value
    targetY=0                          #set start ponit on the canvas
    for picY in range(0,h1):           #loop the Y value  
      Color1=getColor(getPixel(pic2,picX,picY))    #copy pixels from the picture 
      setColor(getPixel(middlepic2,targetX,targetY),Color1)    #write pixels to the canvas
      targetY=targetY+1                 #move to next Y value           
    targetX=targetX+1                   #move to next X value
  
  for x in range(0,w1):
    for y in range(0,h1):
      targetPx=getPixel(blendpic,x,y)      
      px1=getPixel(pic1,x,y)
      px2=getPixel(middlepic2,x,y)      
      r1,g1,b1=getRed(px1),getGreen(px1),getBlue(px1)
      r2,g2,b2=getRed(px2),getGreen(px2),getBlue(px2)      
      blendColor=makeColor((r1+r2)/2,(g1+g2)/2,(b1+b2)/2)      
      setColor(targetPx,blendColor)
  show(blendpic) 
     
  sourceX=0
  for targetX in range(w2/2-w1/2-50,w2/2+w1/2-50):
    sourceY=0
    for targetY in range(0,h1):
      Color2=getColor(getPixel(blendpic,sourceX,sourceY))    #copy pixels from the picture 
      setColor(getPixel(pic2,targetX,targetY),Color2)    #write pixels to the canvas
      sourceY=sourceY+1                 #move to next Y value           
    sourceX=sourceX+1      
  show(pic2) 