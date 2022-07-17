#Hu Guo
#09/20
#Add-Fn and sub functions
#######################
def main_Fn(int1,int2):
 subFn1(int1,int2) #sub
 subFn2(int1,int2) #power
 subFn3(int1,int2) #Divd
########################
def subFn1(int1,int2):
 c=int1+int2 
 print "The addtion is",c
#######################
def subFn2(int1,int2):
 c=int1+int2
 d=c**4
 print "The 4th power of",c,"is",d
################################### 
def subFn3(int1,int2):
 c=int1+int2
 d=c**4
 e=d/4
 print d,"divid by 4 is",e