#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <sstream>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

class Account
{
protected:
  float balance,interate;

public:
  Account(float bal=0,float rate=0);
  void setBal(float bal=0 ){balance=bal;}
  void setRate(float rate=0 ){interate=rate;}
  void Deposit(float money=0){balance+=money;}
  void Withdrawal(float money=0){balance-=money;}
  float getBala(){return balance;}
  float getRate(){return interate;}
  void accPrint();
};


#endif // ACCOUNT_H
