#include "HomeIns.h"

HomeIns::HomeIns(string name, float s,float d, float c, float l)
        :Policy(name)
{
  square=s;dwelling=d;contents=c;liability=l;
  setType("Home Insurance");
  commission=liability*0.3+((dwelling+contents)*0.2);
}

ostream &HomeIns::print(ostream& os) const
{
  os<<endl<<CYN<<type<<RESET<<"\n";
  os<<"Name of insured : ";
  os<<YEL<<left<<setw(21)<<name<<RESET<<setw(3)<<" ";
  os<<"Commission : ";
  os<<GRN<<commission<<RESET<<" "<<endl;
  os<<setw(38)<<" "<<"Square Footage : "<<GRN<<left<<setw(14)<<square<<RESET;
  os<<"Dwelling Coverage : "<<GRN<<dwelling<<RESET<<" \n";
  os<<setw(35)<<" "<<"Contents Coverage : "<<GRN<<left<<setw(12)<<contents<<RESET<<" ";
  os<<"Liability Coverage : "<<GRN<<liability<<RESET<<" ";
  return os;
}
