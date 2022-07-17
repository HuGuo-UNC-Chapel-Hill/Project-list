#Hu Guo
#skel.py
#10.9
################
def mainFn():  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  decreaseRed(mypic)
  writePictureTo(mypic, r"c:\\Users\\B226-04\\Desktop\\re\\rd50%.jpg")
  explore(mypic)
#####################################
def decreaseRed(mypic):
  for pixel in getPixels(mypic):
    value=getRed(pixel)
    setRed(pixel,value*0.5)  #reduce the amount of red by 50%  