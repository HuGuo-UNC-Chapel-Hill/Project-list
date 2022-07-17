#Hu Guo
#project 2
#11/07
#run mainFn(path) to execute
#####################################
def mainFn(path):  
  file=makePicture(pickAFile())                      #select and make the picture     
  height,width=getHeight(file),getWidth(file)        #get height and width of pic
  canvas=makeEmptyPicture(width*2+20,height*2+20,blue)     #create the canvas 
  explore(file)                                      #explore original picture 
  subFn1(file,canvas)                                #horizantal mirror the pic and copy to canvas  
  subFn2(file,canvas)                                #vertical mirror and copy to canvas
  subFn3(file,canvas)                                #balck and white and copy to canvas  with upside down     
  subFn4(file,canvas)                                #change to color negative mode and copy to canvas 
  subFn5(file,canvas)                                #paste selected region to the canvas
  explore(canvas)
  writePictureTo(canvas,path)
########################################################################
def subFn1(file,canvas):
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    mirrorpoint=height/2                             #set mirrorpoint 
    for x in range(0,width):                         #choose original x range 
      for y in range(0,mirrorpoint):                 #choose original y range
        topPX=getPixel(pic,x,y)                      #set the start point of the copied pixels  
        bottomPX=getPixel(pic,x,height-y-1)          #set the destination of the copied pixels
        colorP=getColor(topPX)                       #copy color from original pixels 
        setColor(bottomPX,colorP)                    #set color to the destination
        
 #copy picture to canvas       
    targetX=0+5                                      #set start point on the canvas      
    for picX in range(0,width):                      #loop the X value
      targetY=0+5                                    #set start ponit on the canvas 
      for picY in range(0,height):                   #loop the Y value 
        colorC=getColor(getPixel(pic,picX,picY))     #copy pixels from the picture 
        setColor(getPixel(canvas,targetX,targetY),colorC)  #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value  
      targetX=targetX+1                              #move to next X value
##################################################################
def subFn2(file,canvas):
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    mirrorpoint=width/2                              #set mirrorpoint
    for x in range(0,mirrorpoint):                   #choose original x range 
      for y in range(0,height):                      #choose original y range
        topPX=getPixel(pic,x,y)                      #set the start point of the copied pixels 
        bottomPX=getPixel(pic,width-x-1,y)           #set the destination of the copied pixels 
        colorP=getColor(topPX)                       #copy color from original pixels
        setColor(bottomPX,colorP)                    #set color to the destination
        
#copy picture to canvas            
    targetX=width+15                                 #set start point on the canvas 
    for picX in range(0,width):                      #loop the X value
      targetY=0+5                                    #set start ponit on the canvas
      for picY in range(0,height):                   #loop the Y value 
        colorC=getColor(getPixel(pic,picX,picY))     #copy pixels from the picture 
        setColor(getPixel(canvas,targetX,targetY),colorC)    #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value 
      targetX=targetX+1                              #move to next X value
      
################################################################################################
def subFn3(file,canvas):
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    for px in getPixels(pic):                        #loop the pixels 
      luminance=(getRed(px)+getGreen(px)+getBlue(px))/3    #get the luminance from pixels
      if luminance<50:                                     #detect luminance   
        setColor(px, makeColor(50,50,50))                  #set color to black&white
      elif luminance<100:                                  #detect luminance 
        setColor(px,makeColor(100,100,100))                #set color to black&white
      elif luminance<150:                                  #detect luminance   
        setColor(px,makeColor(150,150,150))                #set color to black&white
      elif luminance<200:                                  #detect luminance   
        setColor(px,makeColor(200,200,200))                #set color to black&white 
      else:
        setColor(px,white)                                 #set color to black&white 
      
#copy picture to canvas            
    targetX=width-1+5                                #set start point on the canvas 
    for picX in range(0,width):                      #loop the X value
      targetY=height*2-1+15                          #set start ponit on the canvas
      for picY in range(0,height):                   #loop the Y value 
        colorC=getColor(getPixel(pic,picX,picY))     #copy pixels from the picture 
        setColor(getPixel(canvas,targetX,targetY),colorC)    #write pixels to the canvas
        targetY=targetY-1                            #move to next Y value 
      targetX=targetX-1                              #move to next X value
      
######################################################################################################      
def subFn4(file,canvas):
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    for px in getPixels(pic):                        #loop the pixels 
      r,g,b=255-getRed(px),255-getGreen(px),255-getBlue(px)      #get the new color                      
      setColor(px,makeColor(r,g,b))
          
#copy picture to canvas            
    targetX=width+15                                 #set start point on the canvas 
    for picX in range(0,width):                      #loop the X value
      targetY=height+15                              #set start ponit on the canvas
      for picY in range(0,height):                   #loop the Y value 
        colorC=getColor(getPixel(pic,picX,picY))     #copy pixels from the picture 
        setColor(getPixel(canvas,targetX,targetY),colorC)    #write pixels to the canvas
        targetY=targetY+1                            #move to next Y value 
      targetX=targetX+1                              #move to next X value  
######################################################################################
def subFn5(file,canvas):
#copy selected region to up left quarter
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    targetX=88                                       #set the start X point at the canvas 
    for sourceX in range(78,218):                    #loop;choose the x value of the original picture
      targetY=190                                    #set the start Y point at the canvas 
      for sourceY in range(51,108):                  #loop;choose the Y value of the original picture    
        color=getColor(getPixel(pic,sourceX,sourceY))#get color from the original picture
        setColor(getPixel(canvas,targetX,targetY),color)#set color to the canvas
        targetY=targetY+1                            #move Y value to the next pixel    
      targetX=targetX+1                              #move x value to the next pixel 
##copy selected region to up right quarter      
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    targetX=425                                      #set the start X point at the canvas 
    for sourceX in range(78,218):                    #loop;choose the x value of the original picture
      targetY=323                                    #set the start Y point at the canvas 
      for sourceY in range(51,108):                  #loop;choose the Y value of the original picture    
        color=getColor(getPixel(pic,sourceX,sourceY))#get color from the original picture
        setColor(getPixel(canvas,targetX,targetY),color)#set color to the canvas
        targetY=targetY+1                            #move Y value to the next pixel    
      targetX=targetX+1                              #move x value to the next pixel
#copy selected region to bottom left quarter      
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    targetX=246                                      #set the start X point at the canvas 
    for sourceX in range(78,218):                    #loop;choose the x value of the original picture
      targetY=541                                    #set the start Y point at the canvas 
      for sourceY in range(51,108):                  #loop;choose the Y value of the original picture    
        color=getColor(getPixel(pic,sourceX,sourceY))#get color from the original picture
        setColor(getPixel(canvas,targetX,targetY),color)#set color to the canvas
        targetY=targetY-1                            #move Y value to the next pixel    
      targetX=targetX-1                              #move x value to the next pixel 
#copy selected region to bottom right quarter      
    pic=duplicatePicture(file)                       #make a copy of picture 
    height,width=getHeight(pic),getWidth(pic)        #get height and width
    targetX=425                                      #set the start X point at the canvas 
    for sourceX in range(78,218):                    #loop;choose the x value of the original picture
      targetY=323+height+10                          #set the start Y point at the canvas 
      for sourceY in range(51,108):                  #loop;choose the Y value of the original picture    
        color=getColor(getPixel(pic,sourceX,sourceY))#get color from the original picture
        setColor(getPixel(canvas,targetX,targetY),color)#set color to the canvas
        targetY=targetY+1                            #move Y value to the next pixel    
      targetX=targetX+1                              #move x value to the next pixel                                                                                                                                                                                             