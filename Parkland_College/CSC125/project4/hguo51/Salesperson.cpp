

#include "Salesperson.h"


Salesperson::Salesperson(string n,float b)
        :Employee(n,b)
{}

void Salesperson::calCommission()
{
  commission=0.0;
  float salescommission=0.0;
  for(int i=0;i<sales.size();++i)
    salescommission+=sales[i]->getCommission();
  commission=salescommission;
  commission+=(salescommission*0.05);
}


ostream &Salesperson::print(ostream &os)const
{
  os<<MAG<<setw(4)<<" "<<"salesperson"<<RESET<<" : ";
  os<<YEL<<left<<setw(18)<<name<<RESET<<"";
  os<<"Total Commission : "<<GRN<<left<<setw(19)<<commission<<RESET<<" ";
  os<<"Base Salary : "<<GRN<<basesalary<<RESET<<" \n";
  os<<setw(3)<<" "<<"Total Salary : "<<GRN<<totalsalary<<RESET;
  return os;
}
