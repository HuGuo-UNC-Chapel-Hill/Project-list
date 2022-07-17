#ifndef ARRAY_H
#define ARRAY_H



using namespace std;
#include <iostream>
#include <stdlib.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET  "\x1B[0m"


template<class T>
class Array
{
private:
  T *val;
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
  //Array operator+( const float & );

  // Overloaded non-member operator functions
  friend Array<T> operator+( const float & a, const Array<T> & b)
  {
    int i;
    Array tmp( b.nval );
    for( i = 0; i < b.nval; ++i )
        tmp.val[i] = a + b.val[i];
    return tmp;
  }

  friend ostream &operator<<( ostream & strm, const Array<T> & a )
  {
    strm <<YEL<< "Array:" << RESET << endl;
    strm << "  size: " << RED << a.nval << RESET << endl;
    strm << "  contents :";
    for( int i = 0; i < a.nval; ++i )
        strm <<GRN<< " " << a.val[i] <<" "<<RESET;
    strm << endl;
    return strm;
  }


  // Initialization
  void Init();

  // Access
  T getValue( int i ) { return val[i]; }
  void setValue( int i, T f ) { val[i] = f; }
};


// Constructor
template<class T>
Array<T>::Array( int n )
{
  Init();
  nval = n;
  val = nval ? new T[ nval ] : NULL;
}

// Destructor
template<class T>
Array<T>::~Array()
{
  if( nval ) delete[] val;
}

// Initialization
template<class T>
void Array<T>::Init()
{
  nval = 0;
  val = NULL;
}

// Copy constructor
template<class T>
Array<T>::Array( const Array &a )
{
  Init();
  *this = a;
}

// Overloaded assignment operator
template<class T>
void Array<T>::operator=( const Array &a )
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
	  val = new T[ nval ];
	  for( int i=0; i < nval; ++i )
	    val[i] = a.val[i];
	}
    }
}


// Overloaded arithmetic operator functions
template<class T>
Array<T> Array<T>::operator+( const Array<T> &a )
{
  int i;

  Array tmp( a.nval );
  for( i = 0; i < a.nval; ++i )
    tmp.val[i] = val[i] + a.val[i];

  return tmp;
}





#endif // ARRAY_H
