#include "Person.h"
#include "Account.h"

void Person::perPrint()
{
  cout<<firstname<<" ";
  cout<<lastname<<" ";
  cout<<address<<" ";
  cout<<ssn;
  
}
/*
Person::Person()
{
  this->setFirst("");
  this->setLast("");
  this->setAdd("");
  this->setSsn("");
}
*/
Person::Person(string firstname,string lastname,string address,string ssn)
{
  this->setFirst(firstname);
  this->setLast(lastname);
  this->setAdd(address);
  this->setSsn(ssn);
}
