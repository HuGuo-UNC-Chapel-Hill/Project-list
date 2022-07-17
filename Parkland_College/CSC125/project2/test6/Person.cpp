#include "Person.h"
#include "Account.h"




Person::Person():Account(0,0)
{
  this->setFirst("");
  this->setLast("");
  this->setAdd("");
  this->setSsn("");
}

Person::Person(float bal,float rate,string firstname,string lastname,string address,string ssn):Account(bal,rate)
{
  this->setFirst(firstname);
  this->setLast(lastname);
  this->setAdd(address);
  this->setSsn(ssn);
}

void Person::perPrint()
{
  cout<<totalbalance<<" ";
  cout<<interate<<" ";
  cout<<firstname<<" ";
  cout<<lastname<<" ";
  cout<<address<<" ";
  cout<<ssn;
}
