#Hu Guo
#10.18
#redeyes
#run mainFn() to execute
##################################
def mainFn():
  file=pickAFile()
  pic=makePicture(file)
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
#red eye reduction algorithm #resource: https://stackoverflow.com/questions/133675/red-eye-reduction-algorithm
    r=getRed(px)
    g=getGreen(px)
    b=getBlue(px)
    average=(float(g)+float(b)+0.0000000001)/2 #+0.00000001 to avoid denominater=0 in "reddect"
    reddect=float(r)/average                                  
##remove right
    for x in range(179,215):   
    #if x>179 and x<215:
      if y>267 and y< 309:
         if float(reddect)>1.4:
          setColor(px,makeColor(average-25,g-25,b-25)) #to make a litter more blacker
##remove left          
    if x>333 and x<372:
      if y>288 and y<323:
        if float(reddect)>1.4:
          setColor(px,makeColor(average-25,g-25,b-25))
  explore(pic)        