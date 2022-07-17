
#include "Employee.h"


Employee::Employee(string n, float b):
          name(n),basesalary(b)
{
  commission=0;
  totalsalary=0;
}

Employee::~Employee()
{
  //cout<<"Em detor is called"<<endl;
  return;
}

void Employee::printSales()
{
  for(int i=0;i<sales.size();++i)
    cout<<*(sales[i])<<endl;
}
