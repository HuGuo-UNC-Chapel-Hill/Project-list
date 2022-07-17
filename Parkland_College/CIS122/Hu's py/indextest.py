def test10(path):
    
    pic=makePicture(pickAFile())
    for px in getPixels(pic):
      x=getX(px)
      y=getY(px)    
      height=getHeight(pic)
      width=getWidth(pic)
      c=getColor(px)
      if x>=0 and x<(width/2):
        if y>=0 and y<(height/2):
           lc=makeLighter(c)
           setColor(px,lc)
    explore(pic)     
    writePictureTo(pic,"path")