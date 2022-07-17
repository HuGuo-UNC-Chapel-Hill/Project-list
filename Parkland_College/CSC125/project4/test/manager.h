#include "Employee.h"
#include "Salesperson.h"

class Manager :public Employee
{
  private:
    vector<salesperson> *team;
    float teamcommission;
  public:
    manager(string name="",float basesalary=0.0);
    virtual ~Manager(){return;}
    void caltocom();
}

Manager::Manager(string name,float basesalary):Employee(name,basesalary)
{
  
}

void Manager::caltocom
{
  totalcommission=commission+commission*0.3+teamcommission*0.05;
}
