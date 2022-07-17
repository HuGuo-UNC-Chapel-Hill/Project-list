#include "Account.h"
#include "Person.h"

void Account::accPrint()
{
   cout<<totalbalance<<" ";
   cout<<interate<<" ";
}



Account::Account(float bal, float rate)
{
   rate*=0.01;
   bal=bal+bal*rate;
  this->setBal(bal);
  this->setRate(rate);


}
