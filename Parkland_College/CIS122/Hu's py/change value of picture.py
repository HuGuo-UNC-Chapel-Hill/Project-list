#Hu Guo
#change value of picture.py
#10.9
################
def mainFn(dr):  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  changeValue(dr)
  
  writePictureTo(mypic,r"c:\\Users\\B226-04\\Desktop\\re\\changevaluepicture.jpg")
  explore(mypic)
#####################################
def changeValue(dr):
  for pixel in getPixels(mypic):
    value=getRed(pixel)
    setRed(pixel,value*float(dr))  #change the amount of red by dr  