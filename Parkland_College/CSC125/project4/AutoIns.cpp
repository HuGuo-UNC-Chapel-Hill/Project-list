#include "AutoIns.h"


AutoIns::AutoIns(string name, string m, string v, float l, float c):Policy(name)
{
  model=m;vin=v;liability=l;collision=c;
  setType("Auto Insurance");
  commission=(liability+collision)*0.3;
}

ostream &AutoIns::print(ostream& os) const
{
  os<<endl<<CYN<<type<<RESET<<"\n";
  os<<"Name of insured : ";
  os<<YEL<<left<<setw(21)<<name<<RESET<<setw(3)<<" ";
  os<<"Commission : ";
  os<<GRN<<commission<<RESET<<" \n";
  os<<setw(33)<<" "<<"Model of Automobile : "<<GRN<<left<<setw(21)<<model<<RESET;
  os<<"VIN Number : "<<GRN<<vin<<RESET<<" \n";
  os<<setw(34)<<" "<<"Liability Coverage : "<<GRN<<left<<setw(12)<<liability<<RESET<<" ";
  os<<"Collision Coverage : "<<GRN<<collision<<RESET<<" ";
  return os;
}
