

#include "Manager.h"

Manager::Manager(string n,float b)
        :Employee(n,b)
{}

Manager::~Manager()
{
  //cout<<"Ma detor is called"<<endl;
  return;
}

void Manager::setTeamcom( const vector<Salesperson> &alls )
{
  teamcommission=0.0;
  for(int i=0;i<team.size();++i)
    teamcommission+=alls[team[i]].getCommission();
  teamcommission*=0.05;
}

void Manager::calCommission()
{
  commission=0.0;
  float salescommission=0.0;
  for(int i=0;i<sales.size();++i)
    salescommission+=sales[i]->getCommission();
  commission=salescommission;
  commission+=(salescommission*0.3);
  commission+=teamcommission;
}

ostream &Manager::print(ostream &os)const
{
  os<<MAG<<setw(8)<<" "<<"manager"<<RESET<<" : ";
  os<<YEL<<left<<setw(18)<<name<<RESET<<"";
  os<<"Total Commission : "<<GRN<<left<<setw(19)<<commission<<RESET<<" ";
  os<<"Base Salary : "<<GRN<<basesalary<<RESET<<" \n";
  os<<setw(3)<<" "<<"Total Salary : "<<GRN<<totalsalary<<RESET;
  return os;
}
