#ifndef _SALESPERSON_H_
#define _SALESPERSON_H_

#include "Employee.h"

class Salesperson : public Employee
{
private:
public:
  Salesperson(string name="",float b=0.0);
  virtual ~Salesperson(){return;};
  virtual void calCommission();
  virtual ostream& print(ostream &os)const;

};
/*
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
  cout.setf(ios::left);
  os<<"Name : "<<YEL<<setw(15)<<name<<RESET<<" ";
  os<<"("<<GRN<<"Salesperson"<<RESET<<"), ";
  os<<"Base Salary("<<GRN<<basesalary<<RESET<<"), ";
  os<<"Sales Commission("<<GRN<<commission<<RESET<<"), ";
  os<<"Total Salary("<<GRN<<totalsalary<<RESET<<").\n";
  return os;
}*/

#endif
