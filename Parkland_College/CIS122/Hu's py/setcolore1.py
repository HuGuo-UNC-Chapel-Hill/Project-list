#HU Guo
#10 04
#P108 chapter 4
################################
def mainFn():
  myfile=pickAFile()
  myfile1=makePicture(myfile)
  black1=makeColor(0,0,255)
  pixels=getPixels(myfile1)
  setColor(pixels[0],black1)
  setColor(pixels[1],black1)
  setColor(pixels[2],black1)
  setColor(pixels[3],black1)
  setColor(pixels[4],black1)
  setColor(pixels[5],black1)
  setColor(pixels[6],black1)
  setColor(pixels[7],black1)
  setColor(pixels[8],black1)
  setColor(pixels[9],black1)
  setColor(pixels[10],black1)
  explore(myfile1) 
  writePictureTo(myfile1,"C:\test1.jpe")