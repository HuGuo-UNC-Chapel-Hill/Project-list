def incblue(mypic):
  for p in getPixels(mypic):
    setBlue(p,getBlue(p)*1.2)
  explore(mypic)  