#Hu Guo
#increasered.py
#10.9
################
def mainFn():  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  increasered(mypic)
  writePictureTo(mypic,r"c:\\Users\\B226-04\\Desktop\\re\\ird20%.jpg")
  explore(mypic)
#####################################
def incresaered(mypic):
  for pixel in getPixels(mypic):
    value=getRed(pixel)
    setRed(pixel,value*1.2)  #increase the amount of red by 20%  