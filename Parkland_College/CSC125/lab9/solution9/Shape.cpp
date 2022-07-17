
#include "Shape.h"

// Overloaded output operator as friend 
ostream &operator<<( ostream &strm, Shape &s )
{
  // Call virtual print method
  s.Print( strm );

  // Print base information
  strm << "    Area: " << s.area << endl;

  // Return stream
  return strm;
}
