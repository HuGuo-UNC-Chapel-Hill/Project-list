def decreaseRed(mypic):
  for pixel in getPixels(mypic):
    setRed(pixel,getRed(pixel)*0.5)
  explore(mypic)  