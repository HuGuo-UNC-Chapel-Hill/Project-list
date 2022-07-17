#Hu Guo
#10.11
#Program 47 mirro half of picture
########################################
def mirroHalf():
  myfile=pickAFile()
  mypic=makePicture(myfile)
  pixels=getPixels(mypic)
  target=len(pixels)-1
  for index in range(0,len(pixels)/2):
    pixel1=pixels[index]
    color1=getColor(pixel1)
    pixel2=pixels[target]
    setColor(pixel2,color1)
    target=target-1
  writePictureTo(mypic,r"C:\Users\B226-04\Desktop\Hu's py\New folder\mirroHalf.jpg")
  explore(mypic)  
   