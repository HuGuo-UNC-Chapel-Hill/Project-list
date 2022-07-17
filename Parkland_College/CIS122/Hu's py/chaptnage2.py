def nega():
  file=pickAFile()
  mypic=makePicture(file)
  for p in getPixels(mypic):
    red=255-getRed(p)
    green=255-getGreen(p)
    blue=255-getBlue(p)
    negaclor=makeColor(red,green,blue)
    setColor(p,negaclor)
  explore(mypic)  