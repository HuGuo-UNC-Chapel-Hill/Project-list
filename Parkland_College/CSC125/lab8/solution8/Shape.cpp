
#include "Shape.h"

// Overloaded output operator
ostream &operator<<( ostream &strm, Shape &s )
{
  strm << "area: " << s.area << endl;
  return strm;
}
