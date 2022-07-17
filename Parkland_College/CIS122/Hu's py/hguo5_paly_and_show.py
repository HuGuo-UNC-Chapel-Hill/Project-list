#Hu Guo
#09 20
#Play_and_show functions
#######################
def mainFn(path1,path2):
 subFn1(path1) #show pic
 subFn2(path2) #play sound
##########################
def subFn1(path1):
 make_pic=makePicture(path1)
 show(make_pic)
############################ 
def subFn2(path2):
 make_wav=makeSound(path2)
 play(make_wav)