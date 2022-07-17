#ifndef _Array_h_
#define _Array_h_

using namespace std;
#include <iostream>

class Array
{
private:
  float *val;
  int nval;

public:
  Array( int n=0 );
  ~Array();

  // Copy constructor
  Array( const Array & );

  // Overloaded assignment operator
  void operator=( const Array & );

  // Overloaded member operator functions
  Array operator+( const Array & );
  Array operator+( const float & );

  // Overloaded non-member operater functions
  friend Array operator+( const float &, const Array & );
  friend ostream &operator<<( ostream &, const Array & );

  // Initialization
  void Init();
  
  // Access
  float getValue( int i ) { return val[i]; }
  void setValue( int i, float f ) { val[i] = f; }
};

#endif
