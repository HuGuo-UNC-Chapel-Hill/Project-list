#include "AutoIns.h"

AutoIns::AutoIns(string name, string m, string v, float l, float c):Policy(name)
{
  model=m;vin=v;liability=l;coverage=c;
  commission=(liability+coverage)*0.3;
}

void AutoIns::print(ostream& os) const
{
  cout<<"Auto insurance"<<endl;
  cout<<"Name of insured: "<<name<<"\t"<<"Model: "<<model<<"\t"<<"VIN: "<<vin<<endl;
  cout<<"Liability: "<<liability<<"     "<<"Coverage: "<<coverage<<"     "<<"Commission: "<<commission<<endl;
}
