#ifndef _AutoIns_H_
#define _AutoIns_H_
#include "Policy.h"

class AutoIns :public Policy
{
private:
  string model;
  string vin;
  float liability;
  float coverage;
public:
  AutoIns(string name, string m, string v, float l, float c);
   ~AutoIns(){cout<<"Auto detor is called"<<endl;}
  float getComm() const{return commission;}
  void print(ostream& os) const;

  void setModel(string model){this->model=model;}
  void setVin(string vin){this->vin=vin;}
  void setLiability(float l ){liability=l;}
  void setCoverage(float c){coverage=c;}

  string getModel()const{return model;}
  string getVin()const{return vin;}
  float getLiability()const{return liability;}
  float getCoverage()const{return coverage;}

};


AutoIns::AutoIns(string name, string m, string v, float l, float c):Policy(name)
{
  model=m;vin=v;liability=l;coverage=c;
  commission=(liability+coverage)*0.3;
}

void AutoIns::print(ostream& os) const
{
  cout<<"Auto insurance"<<endl;
  cout<<"Name of insured: "<<name<<"\t"<<"Model: "<<model<<"\t"<<"VIN: "<<vin<<endl;
  cout<<"Liability: "<<liability<<"     "<<"Coverage: "<<coverage<<"     "<<"Commission: "<<commission<<endl;
}



#endif
