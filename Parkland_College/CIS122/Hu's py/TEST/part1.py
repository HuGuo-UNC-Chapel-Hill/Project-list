#Hu Guo
#Final exam - part 1
#11.12.2018
#use mainFn(path) to excute
#example: mainFn("C:\\Users\\GUO\\Desktop\\F1OUT.jpg")
###########################
def mainFn(path):
  global p1,p2
  global w1,h1,w2,h2
  global canvas1
  global wc1,hc1
  p1=makePicture(pickAFile())
  w1,h1=getWidth(p1),getHeight(p1)
  p2=makePicture(pickAFile())
  w2,h2=getWidth(p2),getHeight(p2)
  canvas1=makeEmptyPicture(w1+w2+5,h1+h2+5,green)
  wc1,hc1=getWidth(canvas1),getHeight(canvas1)
  subFn1()
  subFn2()
  subFn3()
  subFn4()
  subFn5()
  F1OUT=duplicatePicture(F1)
  writePictureTo(F1OUT,path)
  explore(F1OUT)
##################################
def subFn1():
    pic1=duplicatePicture(p1)
    mirrorpoint=h1/2                              #set mirrorpoint 
    for x in range(0,w1):                         #choose original x range 
      for y in range(0,mirrorpoint):              #choose original y range
        topPX=getPixel(pic1,x,y)                  #set the start point of the copied pixels  
        bottomPX=getPixel(pic1,x,h1-y-1)          #set the destination of the copied pixels
        colorP=getColor(topPX)                    #copy color from original pixels 
        setColor(bottomPX,colorP)                 #set color to the destination
                          
    targetX=0                                     #set start point on the canvas      
    for picX in range(0,w1):                      #loop the X value
      targetY=0                                   #set start ponit on the canvas 
      for picY in range(0,h1):                    #loop the Y value 
        colorC=getColor(getPixel(pic1,picX,picY)) #copy pixels from the picture 
        setColor(getPixel(canvas1,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                         #move to next Y value  
      targetX=targetX+1                           #move to next X value  
#####################################
def subFn2():
  pic1=duplicatePicture(p1)
  pic2=duplicatePicture(p2)
#rotate img2.jpg 
  pic2r=makeEmptyPicture(h2,w2)
  targetX=0                                #set start point on the canvas      
  for picX in range(0,w2):                 #loop the X value
    targetY=0                              #set start ponit on the canvas 
    for picY in range(0,h2):                    #loop the Y value 
      colorC=getColor(getPixel(pic2,picX,picY)) #copy pixels from the picture        
      setColor(getPixel(pic2r,targetY,targetX),colorC)  #write pixels to the canvas
      targetY=targetY+1                         #move to next Y value  
    targetX=targetX+1                      #move to next X value  
     
#copy rotated image2 to canvas1
  targetX=wc1-h2
  for picX in range(0,h2):
    targetY=0
    for picY in range(0,h1):
      colorC=getColor(getPixel(pic2r,picX,picY)) #copy pixels from the picture               
      setColor(getPixel(canvas1,targetX,targetY),colorC)  #write pixels to the canvas
      targetY=targetY+1                         #move to next Y value  
    targetX=targetX+1                      #move to next X value
    
######################################
def subFn3():
#detect red color on the flag then change it to yellow
  pic3=duplicatePicture(p1)
  for px in getPixels(pic3):
    picX=getX(px)
    picY=getY(px)
    r=getRed(px)
    g=getGreen(px)
    b=getBlue(px)
#red eye reduction algorithm #resource: https://stackoverflow.com/questions/133675/red-eye-reduction-algorithm     
    gbaverage=(float(g)+float(b))/2
    reddect=(float(r))/gbaverage
   
    if picX>44 and picX<200:                    #choose x range  
      if picY>63 and picY<200:                  #choose Y range
        if float(reddect)>1.4:                  #detect red color
          setColor(px,green)                   #change color to yellow 
#copy picture to bottom left corner  
  targetX=0                                     #set start point on the canvas      
  for picX in range(0,w1):                      #loop the X value
      targetY=h1+2                                   #set start ponit on the canvas 
      for picY in range(0,h1):                    #loop the Y value 
        colorC=getColor(getPixel(pic3,picX,picY)) #copy pixels from the picture 
        setColor(getPixel(canvas1,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                         #move to next Y value  
      targetX=targetX+1                           #move to next X value 
#################################################      
def subFn4():
  pic1=duplicatePicture(p1)
  pic2=duplicatePicture(p2)  
  middlepic2=makeEmptyPicture(w1,h1)
  blendpic=makeEmptyPicture(w1,h1)
  #copy middle part of pic2
  targetX=0                            #set start point on the canvas
  for picX in range(w2/2-w1/2-50,w2/2+w1/2-50):      #loop the X value
    targetY=0                          #set start ponit on the canvas
    for picY in range(0,h1):           #loop the Y value  
      Color1=getColor(getPixel(pic2,picX,picY))    #copy pixels from the picture 
      setColor(getPixel(middlepic2,targetX,targetY),Color1)    #write pixels to the canvas
      targetY=targetY+1                 #move to next Y value           
    targetX=targetX+1                   #move to next X value
  #blend middle part pic2 with pic1
  for x in range(0,w1):
    for y in range(0,h1):
      targetPx=getPixel(blendpic,x,y)      
      px1=getPixel(pic1,x,y)
      px2=getPixel(middlepic2,x,y)      
      r1,g1,b1=getRed(px1),getGreen(px1),getBlue(px1)
      r2,g2,b2=getRed(px2),getGreen(px2),getBlue(px2)      
      blendColor=makeColor(int(r1*0.5+r2*0.5),int(g1*0.5+g2*0.5),int(b1*0.5+b2*0.5))      
      setColor(targetPx,blendColor)
   
  #copy blendpic to pic2 in the same location   
  sourceX=0
  for targetX in range(w2/2-w1/2-50,w2/2+w1/2-50):
    sourceY=0
    for targetY in range(0,h1):
      Color2=getColor(getPixel(blendpic,sourceX,sourceY))    #copy pixels from the picture 
      setColor(getPixel(pic2,targetX,targetY),Color2)    #write pixels to the canvas
      sourceY=sourceY+1                 #move to next Y value           
    sourceX=sourceX+1      
  
  #copy blended pic2 to canvas1
  targetX=w1+5
  for sourceX in range(0,w2):
    targetY=h1+2
    for sourceY in range(0,h2):
      Color3=getColor(getPixel(pic2,sourceX,sourceY))       
      setColor(getPixel(canvas1,targetX,targetY),Color3)
      targetY=targetY+1
    targetX=targetX+1
    
###############################
def subFn5():
  global F1
  pic1=canvas1  
  F1=makeEmptyPicture(wc1/2,hc1/2)
  sourceX=0
  for targetX in range(0,wc1/2):
    sourceY=0
    for targetY in range(0,hc1/2):
      color=getColor(getPixel(canvas1,sourceX,sourceY))
      setColor(getPixel(F1,targetX,targetY),color)
      sourceY=sourceY+2
    sourceX=sourceX+2     
             