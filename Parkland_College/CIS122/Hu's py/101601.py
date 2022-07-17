def miha():
  file=pickAFile()
  mypic=makePicture(file)
  pixel=getPixels(mypic)
  target=len(pixel)-1
  for index in range(0,len(pixel)/2):
    pixel1=pixel[index]
    color1=getColor(pixel1)
    pixel2=pixel[target]
    setColor(pixel2,color1)
    target=target-1
  explore(mypic)