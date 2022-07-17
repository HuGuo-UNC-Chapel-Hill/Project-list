def edge(precision=5):
  pic=makePicture(pickAFile())  
  width,height=getWidth(pic),getHeight(pic)  
  for y in range(0,height-1):
    for x in range(0,width-1):        
        px=getPixel(pic,x,y)
        right=getPixel(pic,x+1,y)
        below=getPixel(pic,x,y+1)       
        LR=(getRed(right)+getBlue(right)+getGreen(right))/3
        LB=(getRed(below)+getBlue(below)+getGreen(below))/3
        LO=(getRed(px)+getBlue(px)+getGreen(px))/3        
        if abs(LR-LO) > precision and abs(LB-LO) > precision:
          setColor(px,black)
        else:
          setColor(px,white)
 
  explore(pic)