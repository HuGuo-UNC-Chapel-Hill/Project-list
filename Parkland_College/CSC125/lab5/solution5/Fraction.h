#ifndef _Fraction_h_
#define _Fraction_h_

#include <iostream>
using namespace std;
#include <stdlib.h>

class Fraction
{
private:
  int numerator;
  int denominator;

public:

  // Constructor
  Fraction() { numerator=0; denominator=0; }

  // Print method
  void Print();

  // Simplify
  void Simplify();

  // Overloaded addition operator
  Fraction operator+( const Fraction & );

  // Access methods
  void SetNumerator( int );
  void SetDenominator( int );
  int GetNumerator();
  int GetDenominator();
};

#endif
