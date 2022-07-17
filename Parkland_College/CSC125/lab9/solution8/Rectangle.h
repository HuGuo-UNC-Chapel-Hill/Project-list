#ifndef _Rectangle_h_
#define _Rectangle_h_

#include "Shape.h"

class Rectangle : public Shape
{
protected:
  float width, height;

public:
  Rectangle() { width = height = 0.0; }
  Rectangle( float w, float h ) { width = w; height = h; }
  ~Rectangle() {}

  // Compute area
  void Area();
};

#endif
