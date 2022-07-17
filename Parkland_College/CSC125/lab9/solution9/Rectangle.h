#ifndef _Rectangle_h_
#define _Rectangle_h_

using namespace std;

#include "Shape.h"

class Rectangle : public Shape
{
protected:
  float width, height;

public:
  Rectangle( float w, float h ) { width = w; height = h; }
  ~Rectangle() {}

  // Virtual methods
  virtual void Area();
  virtual ostream &Print( ostream &strm );
};

#endif
