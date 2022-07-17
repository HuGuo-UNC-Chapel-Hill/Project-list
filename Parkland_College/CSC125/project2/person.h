#ifndef _person_h_
#define _person_h_

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class Person
{
private:
  string ssn;
public:
  Person():ssn(""){};
  void setSsn(string ssn){this->ssn=ssn;}
  string getSSn(){return ssn;}
  void perPrint();
};

#endif
