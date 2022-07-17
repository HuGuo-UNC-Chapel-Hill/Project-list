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

void Account::accPrint()
{
   cout<<balance;
   cout<<inrate;
}

class Person:public Account
{
private:
  string ssn;
public:
  Person():ssn(""){};
  void setSsn(string ssn){this->ssn=ssn;}
  string getSSn(){return ssn;}
  void perPrint();
};

void Person::perPrint()
{
  cout<<ssn;
}


int main()
{
  Person per[10];
  per[0].setBala(10);
  per[0].setSsn("123456");
  per[0].accPrint();
  cout<<endl;
  per[0].perPrint();
  cout<<endl;
  return 0;
}
