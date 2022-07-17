#Hu Guo
#11.01
#Pro66
#Mirror Pixels
#run mainFn() to execute
#########################################
def mainFn():
  pic=makePicture(pickAFile()) 
  width=getWidth(pic)
  height=getHeight(pic)
  mirrorPoint=width/2  
  for y in range(0,height):
    for x in range(0,mirrorPoint):
      currentPixel=getPixel(pic,x,y)
      color=getColor(currentPixel)      
      targetPixel=getPixel(pic,width-x-1,y)
      setColor(targetPixel,color)
  writePictureTo(pic,r"C:\Users\GUO\Desktop\66out.jpg")    
  show(pic)    