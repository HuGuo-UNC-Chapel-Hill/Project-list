def separate(string):
   odds=''
   evers=''
   print len(string)
   for index in range(len(string)):
      if index%2==0:
        evers=evers+string[index]
   for index in range(len(string)):
     if not (index%2==0):
        odds=odds+string[index]
   print "Evers :",evers
   print "Odds :",odds      