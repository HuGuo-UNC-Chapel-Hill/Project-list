#ifndef _MANAGER_H_
#define _MANAGER_H_



#include "Employee.h"
#include "Salesperson.h"

class Manager : public Employee
{
private:
  vector<int> team;
  float teamcommission;

public:
  Manager(string name="",float b=0.0);
  virtual ~Manager();

  void setTeam(int index){team.push_back(index);}
  int getTeam(int n)const{return team[n];}
  int teamSize(){return team.size();}

  void setTeamcom(const vector<Salesperson> &alls);
  float getTeamcom()const{return teamcommission;}

  virtual void calCommission();
  virtual ostream& print(ostream &os)const;
};
/*
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

void Manager::outputTeam(const vector<Salesperson> &alls)
{
  for(int i=0;i<team.size();++i)
    cout<<alls[team[i]];
}


ostream &Manager::print(ostream &os)const
{
  cout.setf(ios::left);
  os<<BLU<<"manager "<<YEL<<left<<setw(15)<<name<<RESET<<".";
  os<<"Base Salary : "<<GRN<<basesalary<<RESET<<" ";
  os<<"Total Commission : "<<GRN<<commission<<RESET<<" ";
  os<<"Total Salary : "<<GRN<<totalsalary<<RESET<<"\n";
  return os;
}
*/
#endif
