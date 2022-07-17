#Hu Guo
#10.18
#chapter5 pr51
#convert to sepia tones
#run sepiaTint() to execute
###############################################
def sepiaTint():
  file=pickAFile()
  pic=makePicture(file)
  grayScaleNew(pic)

  for p in getPixels(pic):
    red=getRed(p)
    blue=getBlue(p)
    #tint shadows
    if (red<63):
      red=red*1.1
      blue=blue*0.9
    #tint midtones
    if (red>62 and red <192):
      red =red*1.08
      blue=blue*0.85
    #tint highlights
    if(red>191):
      red=red*1.08
      if(red>255):
        red=255
      blue=blue*0.93
    #set the new color values
    setBlue(p,blue)
    setRed(p,red)
#  writePictureTo(pic,"C:\\Users\\B226-04\\Desktop\\51out.jpg")
  explore(pic)   
#################################################
def grayScaleNew(pic):
  for px in getPixels(pic):
    red=getRed(px)
    green=getGreen(px)
    blue=getBlue(px)
    intensity=(red+green+blue)/3
    nega=makeColor(intensity,intensity,intensity)
    setColor(px,nega)   