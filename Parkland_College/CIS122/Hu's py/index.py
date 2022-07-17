def xxx(n):
  word="abdxudy"
  pile=''
  for index in range(0,len(word)):
   pile=pile+word[index%n]
  return pile
  