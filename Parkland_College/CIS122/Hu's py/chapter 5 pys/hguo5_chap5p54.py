#Hu Guo
#10.18
#pro54
#simple line drwing
#run edge() to execute
###########################
def edge():
  file=pickAFile()
  pic=makePicture(file)
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    if y< getHeight(pic)-1 and x<getWidth(pic)-1:
      sum=getRed(px)+getGreen(px)+getBlue(px)
      botrt=getPixel(pic,x+1,y+1)
      sum2=getRed(botrt)+getGreen(botrt)+getBlue(botrt)
      diff=abs(sum2-sum)
      newcolor=makeColor(diff,diff,diff)
      setColor(px,newcolor)
#  writePictureTo(pic,r"C:\Users\B226-04\Desktop\Hu's py\chapter 5 pys\54out")
  explore(pic)