
#include "Circle.h"

// Virtual methods
void Circle::Area()
{
  area = float(3.14) * radius * radius;
}
ostream &Circle::Print( ostream &strm )
{
  strm << "  Circle:" << endl;
  strm << "    Radius: " << radius << endl;
  return strm;
}
