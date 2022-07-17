#Hu guo
#29.11.2018
#program 202
#Turtle drops a picture and spins it
#using mianFn() to excute
###################
def mainFn():
  file=makePicture(pickAFile())
  apic=duplicatePicture(file)
  spinAPicture(apic)
########################
def spinAPicture(apic):
  canvas=makeEmptyPicture(640,480)
  ted=Turtle(canvas)
  for i in range(0,360):
    ted.drop(apic)
    ted.forward(10)
    ted.turn(20)
  show(canvas)
  