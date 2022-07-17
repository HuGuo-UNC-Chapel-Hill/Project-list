def mixem2(astring):
 mix=""
 for index in range(0,len(astring)/2):
  mix = mix + astring[index]+" ."
 for index in range(len(astring)/2,len(astring)):
  mix = mix + astring[index]
 return mix