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
  void printOut();

  //accessor function to get value of fractions
  int setNum(int num=0){this->num=num;}
  int setDem(int den=1){this->den=den;}
  int getNum(){return num;}
  int getDen(){return den;}

  //calculate the sum
  void calculate(Fraction ff,Fraction sf);

  //analysis for each fraction
  void nozero();

  //return the gcd of the fraction
  int GCD();

  //output the simplified result
  void result(Fraction ff,Fraction sf);

};

#endif // FRACTION_H
