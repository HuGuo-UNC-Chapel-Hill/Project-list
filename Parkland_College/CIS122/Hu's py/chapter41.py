def decreaseRed(mypic):
  for pixel in getPixels(mypic):
    value=getRed(pixel)
    setRed(pixel,value*0.5)
  explore(mypic)  