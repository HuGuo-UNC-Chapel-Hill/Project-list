def mirror(p):
  pic=duplicatePicture(p) 
  width,height=getWidth(pic),getHeight(pic)
  mirrorPoint=width/2
  
  for y in xrange(height):
    for x in xrange(0,mirrorPoint):
      currentPixel=getPixel(pic,x,y)
      color=getColor(currentPixel)
      
      targetPixel=getPixel(pic,width-x-1,y)
      setColor(targetPixel,color)
  show(pic)    
  
def mirrorvertical(p):
  pic=duplicatePicture(p) 
  width,height=getWidth(pic),getHeight(pic)
  mirrorPoint=height/2
  
  for y in xrange(mirrorPoint):
    for x in xrange(width):
      currentPixel=getPixel(pic,x,y)
      color=getColor(currentPixel)
      
      targetPixel=getPixel(pic,x,height-y-1)
      setColor(targetPixel,color)
  show(pic)     