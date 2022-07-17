#ifndef _Triangle_h_
#define _Triangle_h_

#include "Shape.h"

class Triangle : public Shape
{
protected:
  float base, height;

public:
  Triangle() { base = height = 0.0; }
  Triangle( float b, float h ) { base = b; height = h; }
  ~Triangle() {}

  // Compute area
  void Area();
};

#endif
