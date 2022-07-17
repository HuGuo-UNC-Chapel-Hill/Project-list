#Hu Guo
#makeSunset.py
#10.9
################
def mainFn():  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  sunset(mypic)
  writePictureTo(mypic,r"c:\\Users\\B226-04\\Desktop\\re\\Sunset.jpg")
  explore(mypic)
#####################################
def sunset(mypic):
  for pixel in getPixels(mypic):
    value=getBlue(pixel)
    setBlue(pixel,value*0.7)  #decrease the amount of blue by 70%
    value=getGreen(pixel)
    setGreen(pixel,value*0.7) #decrease the amount of green by 70% 