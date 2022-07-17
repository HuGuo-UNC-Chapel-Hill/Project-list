#include "LifeIns.h"

LifeIns::LifeIns(string name, int a,string dependent,
                float coverage)
        :Policy(name)
{
  age=a;this->dependent=dependent;this->coverage=coverage;
  commission=coverage*0.2;
}

void LifeIns::print(ostream& os) const
{
  cout<<"Life insurance"<<endl;
  cout<<"Name of insured:"<<name<<"\t"<<"Age of insured:"<<age<<"\t"<<"Dependent:"<<dependent<<endl;
  cout<<"Coverage:"<<coverage<<"     "<<"Commission:"<<commission<<endl;
}
