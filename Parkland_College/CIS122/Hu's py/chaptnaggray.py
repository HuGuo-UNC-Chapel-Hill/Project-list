def negagray():
  file=pickAFile()
  mypic=makePicture(file)
  for p in getPixels(mypic):
    red=getRed(p)
    green=getGreen(p)
    blue=getBlue(p)
    negr=(red+green+blue)/3
    negagray=makeColor(negr,negr,negr)
    setColor(p,negagray)
  explore(mypic)  