#ifndef _Shape_h_
#define _Shape_h_

using namespace std;

#include <iostream>

class Shape
{
protected:
  float area;

public:
  Shape() { area = 0.0; }

  // Overloaded output operator as friend 
  friend ostream &operator<<( ostream &, Shape & );

  // Access methods
  void setArea( float a ) { area = a; }
  float getArea() { return area; }
};

#endif
