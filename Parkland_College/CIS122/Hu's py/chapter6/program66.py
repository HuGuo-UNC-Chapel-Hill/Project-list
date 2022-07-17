#Hu Guo
#11.01
#Pro66
#Mirror Pixels
#run mainFn() to execute
############################
def mainFn():
  pic=makePicture(pickAFile()) 
  width=getWidth(pic)
  height=getHeight(pic)
  mirrorPoint=width/2  
  for y in range(0,height):
    for x in range(0,mirrorPoint):
      leftpx=getPixel(pic,x,y)
      color=getColor(leftpx)      
      rightpx=getPixel(pic,width-x-1,y)
      setColor(rightpx,color)
  writePictureTo(pic,r"C:\Users\GUO\Desktop\66out.jpg")
  show(pic)
  
  
  