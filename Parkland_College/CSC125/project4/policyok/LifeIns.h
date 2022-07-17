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
  void print(ostream& os) const;

  void setAge(int a){age=a;}
  void setDependent(string d){dependent=d;}
  void setCoverage(float c){coverage=c;}

  int getAge()const{return age;}
  string getDependent()const{return dependent;}
  float getCoverage()const{return coverage;}

};


LifeIns::LifeIns(string name, int a,string dependent,
                float coverage)
        :Policy(name)
{
  age=a;this->dependent=dependent;this->coverage=coverage;
  commission=coverage*0.2;
}

void LifeIns::print(ostream& os) const
{
  cout<<"Life insurance"<<endl;
  cout<<"Name of insured:"<<name<<"\t"<<"Age of insured:"<<age<<"\t"<<"Dependent:"<<dependent<<endl;
  cout<<"Coverage:"<<coverage<<"     "<<"Commission:"<<commission<<endl;
}


#endif
