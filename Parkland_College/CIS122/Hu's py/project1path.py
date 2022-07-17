# Hu Guo
#10.20
#project 1
#run mainFn(path) to execute
#########################################
def mainFn(path):   #1.  The main function will take one argument which is a text string indicating where the user wishes to write the file.
  pic=makePicture(pickAFile())   #2.  It has the user pickAFile() to edit
  subFn3(pic)  #3.	It changes the light purple stars to a green color 
  subFn4(pic)  #4.	It changes the pinkish stars to a deep red color 
  subFn5(pic)  #5.	It changes the red circle to black 
  subFn6(pic)  #6.	It changes the orange ellipse to blue 
  subFn7(pic)  #7.	It changes the light blue rectangle to gray 
  subFn8(pic)  #8.	It changes the brown body and head of the ukulele to dark blue 
  subFn9(pic)  #9.	It changes blackish fretboard of the ukulele to red
  subFn10(pic) #10.	It lightens the top left quarter of the image.
  explore(pic) #11.	It then displays the image to the user 
  writePictureTo(pic,path)   #12.	It then writes the image to disk as the user indicated in the call to the main function  
################################################################### 
def subFn3(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    if x>179 and x<211:  #the first star
      if y>30 and y<68:
        c=getColor(px)
        if distance(c,white)>30:
            setColor(px,green)
    if x>442 and x<473:  #the sencond star
      if y>33 and y<73:
        c=getColor(px)
        if distance(c,white)>30:
            setColor(px,green)  
    if x>45 and x<83:  #the third star
      if y>81 and y<181:
        c=getColor(px)
        if distance(c,white)>30:
            setColor(px,green)   
            
##############################################
def subFn4(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    if x>108 and x<153:  #the first star
      if y>46 and y<87:
        c=getColor(px)
        dr=makeColor(200,0,0)
        if distance(c,white)>30:
            setColor(px,dr)
    if x>335 and x<395:  #the sencond star
      if y>93 and y<143:
        c=getColor(px)
        dr=makeColor(200,0,0)
        if distance(c,white)>30:
            setColor(px,dr)   
            
#####################################################
def subFn5(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    c=getColor(px)
    if distance(c,white)>30:
      if x>94 and x<231: 
        if y>123 and y<216:        
          if distance(c,red)<100:
            setColor(px,black)    
      
################# 
def subFn6(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    nr=255-getRed(px)          #using negative color to separate orange color
    ng=255-getGreen(px)
    nb=255-getBlue(px)
    c=getColor(px)
    if distance(c,white)>30:
      if x>178 and x<419: 
        if y>178 and y<316:        
          if float((nr+ng+nb)/3)>50:
            if nr<50 and nb>100:
              setColor(px,blue)  
              
######################################
def subFn7(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)              
    nb=255-getBlue(px)     #using negative color to separate light blue color       
    c=getColor(px)
    if distance(c,white)>30:
      if x>2 and x<301: 
        if y>216 and y<354:        
          if nb<170:
            setColor(px,gray)  
            
################################################
def subFn8(pic): 
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    c=getColor(px)
    intensity=(getRed(px)+getGreen(px)+getBlue(px))/3  
    ng=255-intensity                  #using negative gray color to separate brown
    ngcolor=makeColor(ng,ng,ng)
    if x>486 and x<520:
      if y>154 and y<178: 
        if distance(c,white)>30:
          if distance(c,black)>30: 
            if distance(ngcolor,white)<130:
              setColor(px,makeColor(0,0,139))
    
    if x>484 and x<486:
      if y>160 and y<167: 
        if distance(c,white)>30:
          if distance(c,black)>30: 
            if distance(ngcolor,white)<130:
              setColor(px,makeColor(0,0,139))
              
    if x>312 and x<422:
      if y>169 and y<264: 
        if distance(c,white)>30:
          if distance(c,black)>100: 
            if distance(ngcolor,white)<130:
              setColor(px,makeColor(0,0,139)) 
            if ng>90 and ng<155:          
              setColor(px,makeColor(50,50,189))


###########################################################
def subFn9(pic):
  for px in getPixels(pic):
    x=getX(px)
    y=getY(px)
    c=getColor(px)
    nr=255-getRed(px)          #using negative color to separate black color
    ng=255-getGreen(px)
    nb=255-getBlue(px)
    nc=makeColor(nr,ng,nb)
    if x<487 and x>400:
      if y>162 and y<207:
        if distance(c,white)>50:
          if distance(nc,white)<100:
            setColor(px,red) 
    if x>396 and x<400: 
      if y>188 and y<194:  
        if distance(c,white)>50:
          if distance(nc,white)<100:
            setColor(px,red)                       

#######################################################
def subFn10(pic):        
    for px in getPixels(pic):
      x=getX(px)
      y=getY(px)    
      height=getHeight(pic)
      width=getWidth(pic)
      c=getColor(px)
      if x>=0 and x<=(width/2):
        if y>=0 and y<=(height/2):
           lc=makeLighter(c)
           setColor(px,lc)
        
      
    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          