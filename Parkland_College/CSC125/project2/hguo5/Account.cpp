#include "Account.h"
#include "Person.h"

Account::Account(float bal, float rate)
{
   rate*=0.01;
   bal=bal+bal*rate;
  this->setBal(bal);
  this->setRate(rate);


}
