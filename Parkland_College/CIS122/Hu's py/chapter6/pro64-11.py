#Hu Guo
#11.1
#pro64
#reduce red eye using nested loops
#################
def removeRedEye2(pic,sX,sY,eX,eY,endColor):
  for x in range(sX,eX):
    for y in range(sY,eY):
      px=getPixel(pic,x,y)
      r=getRed(px)
      g=getGreen(px)
      b=getBlue(px)
      gbaverage=(float(g)+float(b)+0.0001)/2
      reddect=(float(r))/gbaverage
      if float(reddect)>1.4:
          setColor(px,makeColor(gbaverage,g,b))
  explore(pic)      
 
     
     