#Hu Guo
#clearBlue.py
#10.9
################
def mainFn():  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  clearBlue(mypic)
  writePictureTo(mypic,r"c:\\Users\\B226-04\\Desktop\\re\\cb100%.jpg")
  explore(mypic)
#####################################
def clearBlue(mypic):
  for pixel in getPixels(mypic):
    setBlue(pixel,0)  #decrease the amount of blue by 100%  