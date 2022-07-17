#include "Employee.h"

class Salesperson: public Employee
{
  private:

  public:
    Salesperson();
    virtual ~salesperson(){return;}
    void caltocom();
}

void Salesperson::caltocom
{
  totalcommission=commission+commission*.05;
}
