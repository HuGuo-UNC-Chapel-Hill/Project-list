
#include "Array.h"

// Constructor
Array::Array( int n )
{
  Init();
  nval = n;
  val = nval ? new float[ nval ] : NULL;
}

// Destructor
Array::~Array()
{
  if( nval ) delete[] val;
}

// Initialization 
void Array::Init()
{
  nval = 0;
  val = NULL;
}

// Copy constructor
Array::Array( const Array &a )
{
  Init();
  *this = a;
}

// Overloaded assignment operator
void Array::operator=( const Array &a )
{
  // If not self-copy
  if( this != &a )
    {
      // Member-wise copy
      nval = a.nval;

      // Copy dynamic memory
      if( val ) delete[] val;
      if( nval )
	{
	  val = new float[ nval ];
	  for( int i=0; i < nval; ++i )
	    val[i] = a.val[i];
	}
    }
}

// Overloaded output stream operator
ostream &operator<<(ostream &strm, const Array &a)
{
  strm << "Array:" << endl;
  strm << "  nval: " << a.nval << endl;
  for( int i = 0; i < a.nval; ++i )
    strm << "  val[" << i << "] " << a.val[i] << endl;

  return strm;
}

// Overloaded arithmetic operator functions
Array Array::operator+( const Array &a )
{
  int i;

  Array tmp( a.nval );
  for( i = 0; i < a.nval; ++i )
    tmp.val[i] = val[i] + a.val[i];

  return tmp;
}
Array Array::operator+( const float &t )
{
  int i;

  Array tmp( nval );
  for( i = 0; i < nval; ++i )
    tmp.val[i] = val[i] + t;

  return tmp;
}
Array operator+( const float &a, const Array &b )
{
  int i;

  Array tmp( b.nval );
  for( i = 0; i < b.nval; ++i )
    tmp.val[i] = a + b.val[i];

  return tmp;
}


