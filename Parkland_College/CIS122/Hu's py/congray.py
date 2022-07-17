#Hu Guo
#10.11
#program 42 convert to Grayscale
#####################################
def grayScale():
  myfile=pickAFile()
  mypic=makePicture(myfile)
  for pixel in getPixels(mypic):
   intensity=(getRed(pixel)+getGreen(pixel)+getBlue(pixel))/3
   grays=makeColor(intensity,intensity,intensity)
   setColor(pixel,grays)
  writePictureTo(mypic,r"C:\Users\B226-04\Desktop\Hu's py\New folder\42out.jpg")
  explore(mypic)
  