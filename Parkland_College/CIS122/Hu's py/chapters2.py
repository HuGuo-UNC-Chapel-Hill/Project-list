def incblue():
  file=pickAFile()
  mypic=makePicture(file)
  for p in getPixels(mypic):
    setBlue(p,getBlue(p)*0.7)
    setGreen(p,getGreen(p)*0.7)
  explore(mypic)  