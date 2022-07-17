#Hu Guo
#10.18
#pro 55
#clearer edge edtection
#run edgedetect() to execute
###########################
def edgedetect():
  pic=makePicture(pickAFile())
  cal(pic)	
  explore(pic)
##############################   
def cal(pic):
   for px in getPixels(pic):
      x=getX(px)
      y=getY(px)
      if y<getHeight(pic)-1 and x<getWidth(pic)-1:
        botrt = getPixel(pic,x+1,y+1)     
        thislum=(getRed(px)+getGreen(px)+getBlue(px))/3
        brlum=(getRed(botrt)+getGreen(botrt)+getBlue(botrt))/3
        if abs(brlum-thislum)>10:
           setColor(px,black)
        if abs(brlum-thislum)<=10:
           setColor(px,white)