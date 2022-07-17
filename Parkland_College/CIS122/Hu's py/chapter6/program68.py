#Hu Guo
#11.01
#Pro68
#Mirror Pixels horizontal bottom to top
#run mainFn() to execute
############################
def mainFn():
  pic=makePicture(pickAFile()) 
  width=getWidth(pic)
  height=getHeight(pic)
  mirrorPoint=height/2  
  for x in range(0,width):
    for y in range(0,mirrorPoint):
      uppx=getPixel(pic,x,y)
      lowpx=getPixel(pic,x,height-y-1)
      color=getColor(lowpx)      
      setColor(uppx,color)
  writePictureTo(pic,r"C:\Users\GUO\Desktop\68out.jpg")
  show(pic)
  
  
  