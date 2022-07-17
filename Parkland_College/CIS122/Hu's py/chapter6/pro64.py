#Hu Guo
#11.1
#pro64
#reduce red eye using nested loops
#################
def removeRedEye2(pic,sX,sY,eX,eY,endColor):
  for x in range(sX,eX):
    for y in range(sY,eY):
      px=getPixel(pic,x,y)
      if(distance(red,getColor(px))<165):
        setColor(px,endColor)
  explore(pic)      
 
     
     