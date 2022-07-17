/* 
   Redesign of lab1 using data modeling methods. We write a data model
   definition of what a fraction "knows" then write functions to
   perform what a fraction "does". Note how we pass pointers to our
   data model functions in order to operate on the data object. 

   Note how each one of our data model operations are as atomic or
   singular focused as possible. In other words we want each of our 
   functions to do one thing very well. Our goal is reusability. 
   If we combine two many tasks into a data model function, then it we 
   couldn't reuse the function if we wanted to perform only one of those tasks! 
   This is why we have simple functions like SetNumerator and GetNumerator
   below. This will be how we build member functions for C++ classes!

   Note most importantly how we keep code that is specific to the
   application (i.e. user I/O with cout/cin or printf/scanf) separate 
   from the data model operations and instead put these tasks in our main
   program. This is because we want our data model (and operations) 
   to be completely INDEPENDENT of any application so we can reuse the 
   data model code. This way if I were to ask you to write another program 
   using fractions, you could reuse the model and functions. If we had, for
   example, the user I/O inside our functions to set the numerator and denominator, 
   we wouldn't be able to reuse these functions for all applications. Imagine if 
   you were writing another application that set the numerator/denominator from 
   within a program (rather than from a user). We would have to modify the
   functions to set the numerator/denominator... this is NOT reusability.
*/

#include <iostream>
using namespace std;
#include <stdlib.h>		// declares the abs function

// DATA MODEL
struct Fraction
{
  int numerator;
  int denominator;
};

// OPERATIONS ON DATA MODEL
void SetNumerator( Fraction *, int );
void SetDenominator( Fraction *, int );
int GetNumerator( Fraction * );
int GetDenominator( Fraction * );
Fraction AddFraction( Fraction *, Fraction *);
void SimplifyFraction( Fraction * );
void PrintFraction( Fraction * );

main()
{
  Fraction f1, f2, result;
  int tmpN, tmpD;
  char divideSign;

  // Fraction 1
  cout << "Enter fraction 1: <numerator>/<denominator>" << endl;
  cin >> tmpN >> divideSign >> tmpD;
  SetNumerator( &f1, tmpN );
  SetDenominator( &f1, tmpD );

  // Fraction 2
  cout << "Enter fraction 2: <numerator>/<denominator>" << endl;
  cin >> tmpN >> divideSign >> tmpD;
  SetNumerator( &f2, tmpN );
  SetDenominator( &f2, tmpD );

  // Add and simplify
  result = AddFraction( &f1, &f2 );
  SimplifyFraction( &result );

  // Print - method 1
  PrintFraction( &f1 );     cout << " + ";
  PrintFraction( &f2 );     cout << " = ";
  PrintFraction( &result ); cout << endl;

  // Print - method 2
  cout << GetNumerator( &f1 )     << "/" << GetDenominator( &f1 ) << " + ";
  cout << GetNumerator( &f2 )     << "/" << GetDenominator( &f2 ) << " = ";
  cout << GetNumerator( &result ) << "/" << GetDenominator( &result ) << endl;
}

// Set/Get functions
void SetNumerator( Fraction *f, int n )
{
  f->numerator = n;
}
void SetDenominator( Fraction *f, int d )
{
  f->denominator = d;
}
int GetNumerator( Fraction *f )
{
  return f->numerator;
}
int GetDenominator( Fraction *f )
{
  return f->denominator;
}

// Add fractions
Fraction AddFraction( Fraction *f1, Fraction *f2 )
{
  Fraction f3;

  SetNumerator( &f3, ( f1->numerator*f2->denominator + 
		       f1->denominator*f2->numerator ) );
  SetDenominator( &f3, f1->denominator*f2->denominator );

  return f3;
}  

// Simplify fraction
void SimplifyFraction( Fraction *f )
{
  int a,b,c,gcd;
  if( f->denominator < 0)
    {
      f->denominator = -f->denominator;
      f->numerator = -f->numerator;
    };
  a = abs(f->numerator);
  b = abs(f->denominator);
  c = a % b;
  while(c)
    {
      a = b;
      b = c;
      c = a % b;
    }
  gcd = b;
  f->numerator /= gcd;
  f->denominator /= gcd;
}

// Print fraction
void PrintFraction( Fraction *f )
{
  cout << f->numerator << "/" <<  f->denominator;
}















