
// Lab3 - Re-designed lab2 using C++ classes


#include <iostream>
using namespace std;
#include <stdlib.h>		// contains declaration for abs function

class Fraction
{
private:
  // DATA MODEL
  int numerator;
  int denominator;

public:

  // OPERATIONS ON DATA MODEL
  // Constructor
  Fraction() { numerator=0; denominator=0; }

  // Class-specific methods
  Fraction Add( Fraction * );
  void Simplify();

  // Print method
  void Print();

  // Access methods
  void SetNumerator( int );
  void SetDenominator( int );
  int GetNumerator();
  int GetDenominator();
};

//
// Method Definitions for Fraction class
//
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
Fraction Fraction::Add( Fraction *f2 )
{
  Fraction f3;

  f3.SetNumerator( ( numerator*f2->denominator + 
		     denominator*f2->numerator ) );
  f3.SetDenominator( denominator*f2->denominator );

  return f3;
}  

// Simplify fraction
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

main()
{
  Fraction f1, f2, result;
  int tmpN, tmpD;
  char divideSign;

  // Fraction 1
  cout << "Enter fraction 1: <numerator>/<denominator>" << endl;
  cin >> tmpN >> divideSign >> tmpD;
  f1.SetNumerator( tmpN );
  f1.SetDenominator( tmpD );

  // Fraction 2
  cout << "Enter fraction 2: <numerator>/<denominator>" << endl;
  cin >> tmpN >> divideSign >> tmpD;
  f2.SetNumerator( tmpN );
  f2.SetDenominator( tmpD );

  // Add and simplify
  result = f1.Add( &f2 );
  result.Simplify();

  // Print - method 1
  f1.Print();     cout << " + ";
  f2.Print();     cout << " = ";
  result.Print(); cout << endl;

  // Print - method 2
  cout << f1.GetNumerator()     << "/" << f1.GetDenominator() << " + ";
  cout << f2.GetNumerator()     << "/" << f2.GetDenominator() << " = ";
  cout << result.GetNumerator() << "/" << result.GetDenominator() << endl;
}
