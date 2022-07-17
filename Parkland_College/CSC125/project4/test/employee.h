#include <iostream>
#include "policy.h"
using namespace std;

class Employee
{
  protect:
    string name;
    float basesalary
    float commission;
    float totalcommission;
    float totalsalary;
    vector<policy> *sales;
  public:
    Employee(string name="",float basesalary);
    virtual ~employee(){return;}
    virtual void caltocom();
    void caltotalsalary(){totalsalary=basesalary+totalcommission;}
}

Employee::Employee(string name,float basesalary)
{
  this->name=name;
  this->basesalary=basesalary;
}
