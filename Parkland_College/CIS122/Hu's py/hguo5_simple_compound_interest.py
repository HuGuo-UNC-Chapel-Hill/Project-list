#Hu Guo
#10 02
#simple compound interest.py 
#formular: A=P*(1+i)^n
#command to run mainFn(pctVar,nVar,principalVar): 
#exmaple: mainFn(7.5,30,10000)
#########################################################  
def mainFn(pctVar,nVar,principalVar):
 subcal(pctVar,nVar,principalVar) #calculate&print
########################################################
def subcal(pctVar,nVar,principalVar):
  a=(1+float(pctVar)*0.01)
  b=float(a)**float(nVar)
  income=float(principalVar)*b
  print "In "+str(nVar)+" years at "+str(pctVar)+" percent, you would have $"+str(int(income))+".00 for a $"+str(principalVar)+" initial investment."