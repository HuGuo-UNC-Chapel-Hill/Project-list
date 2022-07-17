#ifndef _Person_h_
#define _Person_h_

#include "Account.h"

class Person:public Account
{
public:
  //Person():Account(){};
  Person():Account()(string firstname,string lastname,string address,string ssn);
  void setFirst(string firstname){this->firstname=firstname;}
  void setLast(string lastname){this->lastname=lastname;}
  void setAdd(string address){this->address=address;}
  void setSsn(string ssn){this->ssn=ssn;}
  string getFirst(){return firstname;}
  string getLast(){return lastname;}
  string getAdd(){return address;}
  string getSSn(){return ssn;}
  void perPrint();
};

#endif
