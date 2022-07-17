#ifndef _AutoIns_H_
#define _AutoIns_H_
#include "Policy.h"

class AutoIns :public Policy
{
private:
  string model;
  string vin;
  float liability;
  float collision;
public:
  AutoIns(string name, string m, string v, float l, float c);
   ~AutoIns(){cout<<"Auto detor is called"<<endl;}
  float getComm() const{return commission;}
  ostream &print(ostream& os) const;

  void setModel(string model){this->model=model;}
  void setVin(string vin){this->vin=vin;}
  void setLiability(float l ){liability=l;}
  void setCollision(float c){collision=c;}

  string getModel()const{return model;}
  string getVin()const{return vin;}
  float getLiability()const{return liability;}
  float getCollision()const{return collision;}

};

/*
AutoIns::AutoIns(string name, string m, string v, float l, float c):Policy(name)
{
  model=m;vin=v;liability=l;collision=c;
  setType("Auto Insurance");
  commission=(liability+collision)*0.3;
}

ostream &AutoIns::print(ostream& os) const
{
  cout.setf(ios::left);
  os<<YEL<<getType()<<RESET<<"\n";
  os<<"Name of Insured : "<<GRN<<setw(18)<<getName()<<RESET<<" ";
  os<<"Model of Automobile : "<<GRN<<model<<RESET<<" ";
  os<<setw(9)<<" "<<"VIN Number : "<<GRN<<vin<<RESET<<" \n";
  os<<setw(38)<<" "<<"Liability Coverage : "<<GRN<<liability<<RESET<<" ";
  os<<setw(7)<<" "<<"Collision Coverage : "<<GRN<<collision<<RESET<<" ";
  os<<setw(8)<<" "<<"Commission : "<<GRN<<getCommission()<<RESET<<endl;
  return os;
}
*/


#endif
