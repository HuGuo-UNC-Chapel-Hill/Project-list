#ifndef _Triangle_h_
#define _Triangle_h_

using namespace std;

#include "Shape.h"

class Triangle : public Shape
{
protected:
  float base, height;

public:
  Triangle( float b, float h ) { base = b; height = h; }
  ~Triangle() {}

  // Virtual methods
  virtual void Area();
  virtual ostream &Print( ostream &strm );
};

#endif
