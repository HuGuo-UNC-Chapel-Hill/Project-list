def mihalf():
  file=pickAFile()
  mypic=makePicture(file)
  pixels=getPixels(mypic)
  target=len(pixels)-1
  for index in range(0,len(pixels)/2):
    pixel1=pixels[index]
    color1=getColor(pixel1)
    pixel2=pixels[target]
    setColor(pixel2,color1)
    target=target-1
  explore(mypic)  