#include "HomeIns.h"

HomeIns::HomeIns(string name, string square,float d, float c, float l)
        :Policy(name)
{
  this->square=square;dwelling=d;contents=c;liability=l;
  commission=liability*0.3+((dwelling+contents)*0.2);
}

void HomeIns::print(ostream& os) const
{
  cout<<"Home insurance"<<endl;
  cout<<"Name of insured: "<<name<<"\t"<<"Square: "<<square<<"\t"<<"Dwelling: "<<dwelling<<endl;
  cout<<"Contents: "<<contents<<"     "<<"Liability: "<<liability<<"     "<<"Commission: "<<commission<<endl;
}
