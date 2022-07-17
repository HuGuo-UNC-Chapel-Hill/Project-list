#ifndef _account_h_
#define _account_h_

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Account
{
private:
  float balance,inrate;
public:
  Account():balance(0),inrate(0){};
  void setBala(float bal=0 ){balance=bal;}
  void setRate(float rat=0 ){inrate=rat;}
  float getBala(){return balance;}
  float getRate(){return inrate;}
  void accPrint();
};


#endif
