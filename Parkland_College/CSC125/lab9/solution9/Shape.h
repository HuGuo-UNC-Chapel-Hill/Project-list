#ifndef _Shape_h_
#define _Shape_h_

using namespace std;

#include <iostream>

class Shape
{
  // Overloaded output operator as friend 
  friend ostream &operator<<( ostream &, Shape & );

protected:
  float area;

public:
  Shape() : area( 0.0 ) {}

  // Virtual destructor
  virtual ~Shape() {}

  // Pure virtual methods
  virtual ostream &Print( ostream & ) = 0;
  virtual void Area() = 0;
};

#endif
