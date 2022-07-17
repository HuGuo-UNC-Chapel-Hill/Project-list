#Hu Guo
#10.25
#Mid term exam
#run mainFn(path) to execute
#########################################
def mainFn(path):    #It also gets one argument at the command line which is a file name that the user wants to write the resulting image to
  pic=makePicture(pickAFile())    #to choose image file using the mouse
  subFn1(pic)    #Make first upper left quadrant of the image color lighter
  subFn2(pic)    #Make upper right quadrant of the image to color negative image
  subFn3(pic)    #Make bottom (lower) left quadrant of the image to grayscale image.
  subFn4(pic)    #Make bottom (lower) right quadrant of the image to black and white image.
  explore(pic)   #show the image 
  writePictureTo(pic,path)    #writes the file to disk
   
##########################################
def subFn1(pic):               #Make first upper left quadrant of the image color lighter
  width=getWidth(pic)          #get the width of image 
  height=getHeight(pic)        #get the height of image
  for px in getPixels(pic):    #loop each pixel
    x=getX(px)                 #set x as pixel horzantal coordinate      
    y=getY(px)                 #set y as pixel vertical coordinate
    c=getColor(px)             #get color from each pixel
    if x>=0 and x<=(width/2):     #choose x range 
      if y>=0 and y<=(height/2):  #choose y range
        lc=makeLighter(c)         #make lighter color for pixels
        setColor(px,lc)           #set lighter color  
        
######################################################################################## 
def subFn2(pic):               #Make upper right quadrant of the image to color negative image       
  width=getWidth(pic)          #get the width of image 
  height=getHeight(pic)        #get the height of image
  for px in getPixels(pic):    #loop each pixel
    x=getX(px)                 #set x as pixel horzantal coordinate      
    y=getY(px)                 #set y as pixel vertical coordinate
    red=getRed(px)             #get red color value
    green=getGreen(px)         #get grenn color value
    blue=getBlue(px)           #get blue color value
    negColor=makeColor(255-red, 255-green, 255-blue)    #set a newcolor as negetive color
    if x<width and x>(width/2):      #choose x range 
      if y>0 and y<=(height/2):      #choose y range
        setColor(px,negColor)        #set color
        
#####################################################################################        
def subFn3(pic):    #Make bottom (lower) left quadrant of the image to grayscale image
  width=getWidth(pic)          #get the width of image 
  height=getHeight(pic)        #get the height of image
  for px in getPixels(pic):    #loop each pixel
    x=getX(px)                 #set x as pixel horzantal coordinate      
    y=getY(px)                 #set y as pixel vertical coordinate
    red=getRed(px)             #get red color value
    green=getGreen(px)         #get grenn color value
    blue=getBlue(px)           #get blue color value 
    newred=red*.299
    newgreen=green*0.587
    newblue=blue*0.114       
    grayscale=newred+newgreen+newblue   #set grayscale color value 
    if x>0 and x<(width/2):             #choose x range 
      if y<height and y>(height/2):      #choose y range
        setColor(px,makeColor(grayscale,grayscale,grayscale))            #set color
        
####################################################################################
def subFn4(pic):               #Make bottom (lower) right quadrant of the image to black and white image.
  width=getWidth(pic)          #get the width of image 
  height=getHeight(pic)        #get the height of image
  for px in getPixels(pic):    #loop each pixel
    x=getX(px)                 #set x as pixel horzantal coordinate      
    y=getY(px)                 #set y as pixel vertical coordinate
    red=getRed(px)             #get red color value
    green=getGreen(px)         #get grenn color value
    blue=getBlue(px)           #get blue color value 
    newred=red*.299
    newgreen=green*0.587
    newblue=blue*0.114       
    luminance=newred+newgreen+newblue   #set luminance color value 
    if x<width and x>(width/2):         #choose x range 
      if y<height and y>(height/2):     #choose y range
        if luminance>=64:               #detect px which has bigger luminance
          setColor(px,white)            #set color to white
        if luminance<64:                #detect px which has smaller luminance
          setColor(px,black)            #set color to black
     