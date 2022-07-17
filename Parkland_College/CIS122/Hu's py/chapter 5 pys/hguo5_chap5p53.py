#Hu Guo
#10.18
#pro53
#posterize to two gray levels
#run grayPosterize() to execute
#######################################
def grayPosterize():
  file=pickAFile()
  pic=makePicture(file)
  for px in getPixels(pic):
    r=getRed(px)
    g=getGreen(px)
    b=getBlue(px)
    luminance=(r+g+b)/3
    if luminance<64:
      setColor(px,black)
    if luminance>=64:
      setColor(px,white)
#  writePictureTo(pic,r"C:\Users\B226-04\Desktop\53out.jpg")
  explore(pic)
 