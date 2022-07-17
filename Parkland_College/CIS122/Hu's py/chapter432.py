def incblue(mypic):
  for p in getPixels(mypic):
    setBlue(p,0)
  explore(mypic)  