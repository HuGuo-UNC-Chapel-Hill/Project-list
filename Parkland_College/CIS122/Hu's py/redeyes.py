#Hu Guo
#10.18
#redeyes
#run mainFn()
##################################
def mainFn():
  file=pickAFile()
  pic=makePicture(file)
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
##calculate the range of red color
    r=getRed(px)
    g=getGreen(px)
    b=getBlue(px)
    gbaverage=(float(g)+float(b))/2
    reddect=(float(r))/gbaverage
##remove right   
    if x>179 and x<215:
      if y>267 and y< 309:
         if float(reddect)>1.4:
          setColor(px,makeColor(gbaverage,g,b))
##remove left          
    if x>333 and x<372:
      if y>288 and y<323:
        if float(reddect)>1.4:
          setColor(px,makeColor(gbaverage,g,b))
  explore(pic)        