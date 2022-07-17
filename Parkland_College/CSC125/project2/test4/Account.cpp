#include "Account.h"
#include "Person.h"

void Account::accPrint()
{
   cout<<balance<<" ";
   cout<<interate<<" ";
}



Account::Account(float bal, float rate)
{
  this->setBal(bal);
  this->setRate(rate);
}
