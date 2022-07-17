#Hu Guo
#11/13/2018
############################
def mainFn(var1,var2):
  global add
  global sub
  subFn1(var1,var2)
  subFn2(var1,var2)
  subFn3()
#############################
def subFn1(var1,var2):
  global add
  add=var1+var2
  print "Addtion is",add  
#############################
def subFn2(var1,var2):
  global sub
  sub=var2-var1
  print "Subtraction is",sub  
###############################
def subFn3():  
  diff=add-sub
  print "difference is",diff
  