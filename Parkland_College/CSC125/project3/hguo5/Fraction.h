#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#include <string>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;


class Fraction
{
private:
  int num;
  int den;
public:

  Fraction();
  ~Fraction(){};
  //debug
  //~Fraction(){cout<<"Destructor is called.";};

  //munator function to set value to fractions
  void setFrac();

  //check the denominator is zero or not
  void check();

  //print out the factions depends on each situation
  void printOut();

  //setter function to set the value to the fraction
  void setNum(int num=0){this->num=num;}
  void setDem(int den=1){this->den=den;}

  //accessor function to get value to the fraction
  int getNum() const {return num;}
  int getDen() const {return den;}

  // Print fraction
  void Print();

  //return the gcd of the fraction
  int GCD();

  //overloading the operator +
  Fraction operator+(const Fraction sf);

  //overloading the operator -
  Fraction operator-(const Fraction sf);

  //overloading the operator *
  Fraction operator*(const Fraction sf);

  //overloading the operator /
  Fraction operator/(const Fraction sf);

  //overloading the operator <<
  friend ostream &operator<<(ostream &os, Fraction& f);

};

#endif // FRACTION_H
