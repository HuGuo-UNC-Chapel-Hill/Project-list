
#include "Fraction.h"

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
  result = f1 + f2;
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
