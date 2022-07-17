#include "LifeIns.h"

LifeIns::LifeIns(string name, int a,string dependent,
                float coverage)
        :Policy(name)
{
  age=a;this->dependent=dependent;this->coverage=coverage;
  setType("Life Insurance");
  commission=coverage*0.2;
}

ostream &LifeIns::print(ostream& os) const
{
  os<<endl<<CYN<<type<<RESET<<"\n";
  os<<"Name of insured : ";
  os<<YEL<<left<<setw(21)<<name<<RESET<<setw(3)<<" ";
  os<<"Commission : ";
  os<<GRN<<commission<<RESET<<" "<<endl;
  os<<setw(38)<<" "<<"Age of Insured : "<<GRN<<left<<setw(14)<<age<<RESET;
  os<<"Name of Dependent : "<<GRN<<dependent<<RESET<<" \n";
  os<<setw(34)<<" "<<"Term Life Coverage : "<<GRN<<left<<setw(12)<<coverage<<RESET<<" ";
  return os;
}
