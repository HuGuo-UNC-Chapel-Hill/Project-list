
#include "Fraction.h"

// Set/Get functions
void Fraction::SetNumerator( int n )
{
  numerator = n;
}
void Fraction::SetDenominator( int d )
{
  denominator = d;
}
int Fraction::GetNumerator()
{
  return numerator;
}
int Fraction::GetDenominator()
{
  return denominator;
}

// Add fractions
Fraction Fraction::operator+( const Fraction &f2 )
{
  Fraction f3;

  // Note that because this is a Fraction method
  // we are not required to use access methods
  // to access the numerator and denominator for f2 and f3,
  // we can access them directly even though they are private
  f3.numerator = numerator*f2.denominator + denominator*f2.numerator;
  f3.denominator = denominator*f2.denominator;

  return f3;
}  

/* Simplify fraction */
void Fraction::Simplify()
{
  int a,b,c,gcd;
  if( denominator < 0)
    {
      denominator = -denominator;
      numerator = -numerator;
    };
  a = abs(numerator);
  b = abs(denominator);
  c = a % b;
  while(c)
    {
      a = b;
      b = c;
      c = a % b;
    }
  gcd = b;
  numerator /= gcd;
  denominator /= gcd;
}

// Print fraction
void Fraction:: Print()
{
  cout << numerator << "/" <<  denominator;
}
