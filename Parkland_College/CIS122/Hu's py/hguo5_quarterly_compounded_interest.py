#Hu guo
#11/13
#Quarterly compounding
#exmaple: mainFn(7.5,30,10000)
#########################################################  
def mainFn(pctVar,nVar,principalVar):
  global incomey
  global incomeq
  subcal(pctVar,nVar,principalVar) #calculate&print yearly
  subca2(pctVar,nVar,principalVar) #calculate&print quartely
  subca3(pctVar,nVar,principalVar) #calculate&print compounded
########################################################
def subcal(pctVar,nVar,principalVar):
  global incomey
  a=(1+float(pctVar)*0.01)
  b=float(a)**float(nVar)
  incomey=float(principalVar)*b
  print "In "+str(nVar)+" years at "+str(pctVar)+" percent, you would have $"+str(int(incomey))+".00 for a $"+str(principalVar)+" initial investment."
########################################################
def subca2(pctVar,nVar,principalVar):
  global incomeq
  a=(1+float(pctVar)*0.01*0.25)
  b=float(a)**(float(nVar)*4)
  incomeq=float(principalVar)*b
  print "In "+str(nVar)+" years at "+str(pctVar)+" percent, you would have $"+str(int(incomeq))+".00 for a $"+str(principalVar)+" initial investment, compounded quartely."
############################################################
def subca3(pctVar,nVar,principalVar):
  compounded=int(incomeq)-int(incomey)
  print "In "+str(nVar)+" years at "+str(pctVar)+" percent, you would be $"+str(int(compounded))+".00 ahead if you compounded quartely."