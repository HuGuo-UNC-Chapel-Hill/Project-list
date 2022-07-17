#ifndef _Circle_h_
#define _Circle_h_

#include "Shape.h"

class Circle : public Shape
{
protected:
  float radius;

public:
  Circle( float r=0.0 ) { radius = r; }
  ~Circle() {}

  // Compute area
  void Area();
};

#endif
