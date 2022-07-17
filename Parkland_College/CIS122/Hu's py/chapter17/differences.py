#Hu Guo  
#test difference between making turtle inside the world() and inside the canvas
########################
def MainFn():
  earth=makeWorld(600,600)
  t1=makeTurtle(earth)
  canvas=makeEmptyPicture(600,600,green)
  t2=makeTurtle(canvas)
  t1.setPenColor(red)
  t1.setPenWidth(6)
  t1.forward()
  t1.turn(-45)
  t1.forward()
  mycolor=makeColor(100,50,30)
  t2.setPenColor(mycolor)
  t2.setPenWidth(6)
  t2.forward()
  t2.turn(-45)
  t2.forward()
  show(canvas)