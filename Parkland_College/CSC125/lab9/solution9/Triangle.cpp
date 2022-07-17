
#include "Triangle.h"

// Virtual methods
void Triangle::Area()
{
  area = float(0.5) * base * height;
}
ostream &Triangle::Print( ostream &strm )
{
  strm << "  Triangle:" << endl;
  strm << "    Base: " << base << endl;
  strm << "    Height: " << height << endl;
  return strm;
}
