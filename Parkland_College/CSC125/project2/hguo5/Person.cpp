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

void Person::perPrint(int selected)
{
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  cout<<" No."<<selected+1<<"\n";
  cout<<" Name : "<<setw(18)<<this->FullName()<<"Checking Account : "<<this->getToBa()<<endl;
  cout<<setw(29)<<" "<<"Interest Rate : "<<this->getRate()<<endl;
  cout<<setw(37)<<" "<<"S.S.N : "<<this->getSsn()<<endl;
  cout<<setw(35)<<" "<<"Address : "<<this->getAdd()<<endl;
  cout<<"------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}


