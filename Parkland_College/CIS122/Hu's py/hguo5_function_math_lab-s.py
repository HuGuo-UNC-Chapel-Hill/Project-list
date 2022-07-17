#Hu Guo
#09 20
#fun_math_lab functions
#######################
def mainFn(value1,value2):
 subFn1(value1,value2) #add
 subFn2(value1,value2) #sub
 subFn3(value1,value2) #mul
 subFn4(value1,value2) #div
 subFn5(value1,value2) #Pow
 subFn6(value1,value2) #mod
########################
def subFn1(value1,value2):
 s1=value1+value2
 print "The result of",value1,"add",value2,"is",s1
#######################
def subFn2(value1,value2):
 s2=value1-value2
 print "The result of",value1,"subtract",value2,"is",s2
#########################
def subFn3(value1,value2):
 s3=value1*value2
 print "The result of",value1,"multiplate",value2,"is",s3
##########################
def subFn4(value1,value2):
 s4=value1/value2
 print "The result of",value1,"divided by",value2,"is",s4
#######################
def subFn5(value1,value2):
 s5=value1**value2
 print "The result of",value2,"power of",value1,"is",s5
######################
def subFn6(value1,value2):
 s6=value1%value2
 print "The remainder of",value1,"divided by",value2,"is",s6