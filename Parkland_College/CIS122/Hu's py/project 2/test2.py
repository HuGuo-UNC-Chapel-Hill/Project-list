#Hu Guo
#project 2
#11/07
#run mainFn(path) to execute
#####################################
def mainFn():  
  file=makePicture(pickAFile())                    #select and make the picture 
  pic=duplicatePicture(file)                       #make a copy of picture
  height,width=getHeight(pic),getWidth(pic)        #get height and width of pic
  canvas=makeEmptyPicture(width*2,height*2,blue)   #create the canvas 
  explore(pic)                                     #explore original picture 
#  subFn1(pic,canvas)                               #horizantal mirror the pic and copy to canvas  
  subFn2(pic,canvas)                               #vertical mirror and copy to canvas
#  subFn3(pic)                                     #balck and white       
#  subFn4(pic)                                     #line drawing 
#  subFn5(pic)                                     #paste selected region to the canvas
  explore(canvas)
########################################################################

##################################################################
def subFn2(pic,canvas):
    height,width=getHeight(pic),getWidth(pic)
    mirrorpoint=width/2
    for x in range(0,mirrorpoint):
      for y in range(0,height):
        topPX=getPixel(pic,x,y)
        bottomPX=getPixel(pic,width-x-1,y)
        colorP=getColor(topPX)
        setColor(bottomPX,colorP)
    targetX=width
    for picX in range(0,width):
      targetY=0
      for picY in range(0,height):
        colorC=getColor(getPixel(pic,picX,picY))
        setColor(getPixel(canvas,targetX,targetY),colorC)
        targetY=targetY+1
      targetX=targetX+1  