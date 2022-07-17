def subFn2():
    pic2=makePicture(pickAFile())
    w,h=getWidth(pic2),getHeight(pic2)
    pic2r=makeEmptyPicture(h,w)
    targetX=0                                #set start point on the canvas      
    for picX in range(0,w):                      #loop the X value
      targetY=0                            #set start ponit on the canvas 
      for picY in range(0,h):                    #loop the Y value 
        colorC=getColor(getPixel(pic2,picX,picY)) #copy pixels from the picture 
        setColor(getPixel(pic2r,targetY,targetX),colorC)  #write pixels to the canvas
        targetY=targetY+1                         #move to next Y value  
      targetX=targetX+1 
    show(pic2r)                          #move to next X value          