#Hu Guo
#11.1
#pro63
#lighten with nested loop
#################
def mainFn(): 
  picture=makePicture(pickAFile())
#  explore(picture)
  pic=duplicatePicture(picture)
  lighten2(pic)
  explore(pic)
#################
def lighten2(pic): 
  for x in range(0,getWidth(pic)):
    for y in range(0,getHeight(pic)/2):
      pixel=getPixel(pic,x,y)
      color=getColor(pixel)
      color=makeLighter(color)
      setColor(pixel,color)
 
     
     