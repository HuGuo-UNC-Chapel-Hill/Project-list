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
 print "addition of two numbers is",s1
#######################
def subFn2(value1,value2):
 s2=value1-value2
 print "subtraction of the two integers is",s2
#########################
def subFn3(value1,value2):
 s3=value1*value2
 print "multiplication of two numbers is",s3
##########################
def subFn4(value1,value2):
 s4=value1/value2
 print "division of the two integers is",s4
#######################
def subFn5(value1,value2):
 s5=value1**value2
 print "Answer of power function is",s5
######################
def subFn6(value1,value2):
 s4=value1/value2
 s6=value1%value2
 print "The answer of integers",value1,"divided by",value2,"is:",s4,"mod",s6