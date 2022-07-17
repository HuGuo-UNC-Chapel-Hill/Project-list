#Hu Guo
#11.01
#Pro67
#Mirror Pixels horizontal
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
      color=getColor(uppx)      
      lowpx=getPixel(pic,x,height-y-1)
      setColor(lowpx,color)
  writePictureTo(pic,r"C:\Users\GUO\Desktop\67out.jpg")
  show(pic)
  
  
  