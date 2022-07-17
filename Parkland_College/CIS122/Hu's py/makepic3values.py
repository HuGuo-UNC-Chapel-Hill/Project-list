#Hu Guo
#makeSunset2.py
#10.9
################
def mainFn(dr,db,dg):  
  myfile=pickAFile()
  mypic=makePicture(myfile)
  cRed(mypic,dr)
  cBlue(mypic,db)
  cGreen(mypic,dg)
  writePictureTo(mypic,r"C:\Users\B226-04\Desktop\Hu's py\New folder\3values.jpg")
  explore(mypic)
##########################################   
def cRed(mypic,dr):
  for pixel in getPixels(mypic):
    value=getRed(pixel)
    setRed(pixel,value*dr)  #changge the amount of red by dr
#############################################
def cBlue(mypic,db):
  for pixel in getPixels(mypic):
    value=getBlue(pixel)
    setBlue(pixel,value*db)  #change the amount of blue by db
#############################################
def cGreen(mypic,dg):
  for pixel in getPixels(mypic):  
    value=getGreen(pixel)
    setGreen(pixel,value*dg) #change the amount of green by dg 