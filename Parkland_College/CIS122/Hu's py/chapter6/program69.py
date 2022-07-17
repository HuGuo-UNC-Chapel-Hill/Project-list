#Hu Guo
#11.01
#pro69
#Mirror the temple of Hephaestus
#run mainFn() to execute
###################################################
def mainFn():
  pic=makePicture(pickAFile())
  height=getHeight(pic)
  width=getWidth(pic)
  mirrorPoint=395
  for y in range (52,135):
    for x in range (44,mirrorPoint):
      leftpx=getPixel(pic,x,y)
      color=getColor(leftpx)
      rightpx=getPixel(pic,mirrorPoint*2-x-1,y)
      setColor(rightpx,color)
  writePictureTo(pic,r"C:\Users\GUO\Desktop\69out.jpg")
  explore(pic)
  