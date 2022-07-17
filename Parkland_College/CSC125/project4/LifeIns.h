#ifndef _LifeIns_h_
#define _LifeIns_h_

#include "Policy.h"

class LifeIns:public Policy
{
private:
  int age;
  string dependent;
  float coverage;
public:
  LifeIns(string name, int a,string dependent,float coverage);
  ~LifeIns(){cout<<"Life detor is called"<<endl;};
  float getComm() const {return commission;}
  ostream &print(ostream& os)const;

  void setAge(int a){age=a;}
  void setDependent(string d){dependent=d;}
  void setCoverage(float c){coverage=c;}

  int getAge()const{return age;}
  string getDependent()const{return dependent;}
  float getCoverage()const{return coverage;}

};

/*
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
  cout.setf(ios::left);
  os<<YEL<<getType()<<RESET<<"\n";
  os<<"Name of Insured : "<<GRN<<setw(23)<<getName()<<RESET<<" ";
  os<<"Age of Insured : "<<GRN<<age<<RESET<<" ";
  os<<setw(10)<<" "<<"Name of Dependent : "<<GRN<<dependent<<RESET<<" \n";
  os<<setw(38)<<" "<<"Term Life Coverage : "<<GRN<<coverage<<RESET<<" ";
  os<<setw(40)<<" "<<"Commission : "<<GRN<<getCommission()<<RESET<<endl;
  return os;
}
*/

#endif
