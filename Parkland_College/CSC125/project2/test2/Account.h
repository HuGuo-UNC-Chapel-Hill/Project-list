#ifndef _Account_h_
#define _Account_h_

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

class Account
{
protected:
  float balance,interate;
  string firstname,lastname,address,ssn;
public:
  Account():balance(0),interate(0),firstname(""),lastname(""),address(""),ssn(""){};
  Account(float bal=0,float rate=0);
  void setBal(float bal=0 ){balance=bal;}
  void setRate(float rate=0 ){interate=rate;}
  void Deposit(float money=0){balance+=money;}
  void Withdrawal(float money=0){balance-=money;}
  float getBala(){return balance;}
  float getRate(){return interate;}
  void accPrint();
};


#endif
