def blend(pic1,pic2):
  width,height=getWidth(pic1),getHeight(pic1)
  blendPic=makeEmptyPicture(getWidth(pic1),getHeight(pic1))
  for y in xrange(height):
    for x in xrange(width):
      
      targetPx=getPixel(blendPic,x,y)
      
      px1=getPixel(pic1,x,y)
      px2=getPixel(pic2,x,y)
      
      r1,g1,b1=getRed(px1),getGreen(px1),getBlue(px1)
      r2,g2,b2=getRed(px2),getGreen(px2),getBlue(px2)
      
      blendColor=makeColor((r1+r2)/2,(g1+g2)/2,(b1+b2)/2)
      
      setColor(targetPx,blendColor)
  show(blendPic)
      