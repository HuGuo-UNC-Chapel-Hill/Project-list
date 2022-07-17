
#include "Rectangle.h"

// Virtual methods
void Rectangle::Area()
{
  area = width * height;
}
ostream &Rectangle::Print( ostream &strm )
{
  strm << "  Rectangle:" << endl;
  strm << "    Width: " << width << endl;
  strm << "    Height: " << height << endl;
  return strm;
}
