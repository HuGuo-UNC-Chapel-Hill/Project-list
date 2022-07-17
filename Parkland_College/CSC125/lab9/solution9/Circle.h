#ifndef _Circle_h_
#define _Circle_h_

using namespace std;

#include "Shape.h"

class Circle : public Shape
{
protected:
  float radius;

public:
  Circle( float r ) { radius = r; }
  ~Circle() {}

  // Virtual methods
  virtual void Area();
  virtual ostream &Print( ostream &strm );
};

#endif
