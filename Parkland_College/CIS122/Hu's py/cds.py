def deceRed():
  file=pickAFile()
  mypic=makePicture(file)
  pixels=getPixels(mypic)
  for index in range(0,len(pixels)/2):
    pixel=pixels[index]
    value=getRed(pixel)
    setRed(pixel,value*0.5)
  explore(mypic)  