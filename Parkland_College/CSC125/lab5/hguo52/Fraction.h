#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>
#include <stdio.h>
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
  void Print();

  //setter function to set the value to the fraction
  int setNum(int num=0){this->num=num;}
  int setDem(int den=1){this->den=den;}

  //accessor function to get value to the fraction
  int getNum(){return num;}
  int getDen(){return den;}

  //return the gcd of the fraction
  int GCD();

  //overloading the operator +
  Fraction operator+(Fraction sf) ;

  //overloading the operator <<
  friend ostream &operator<<(ostream &os, Fraction& f);

};

#endif // FRACTION_H
