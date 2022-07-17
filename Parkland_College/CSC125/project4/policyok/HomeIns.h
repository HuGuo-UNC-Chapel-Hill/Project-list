#ifndef _HomeIns_H_
#define _HomeIns_H_
#include "Policy.h"

class HomeIns :public Policy
{
private:
  string square;
  float dwelling;
  float contents;
  float liability;
public:
  HomeIns(string name, string square,float d, float c, float l);
   ~HomeIns(){cout<<"Home detor is called"<<endl;}
  float getComm() const{return commission;}
  void print(ostream& os) const;

  void setSquare(string square){this->square=square;}
  void setDwelling(float dwelling){this->dwelling=dwelling;}
  void setContents(float c){contents=c;}
  void setLiability(float l ){liability=l;}

  string getSquare()const{return square;}
  float getDwelling()const{return dwelling;}
  float getContents()const{return contents;}
  float getLiability()const{return liability;}
};


HomeIns::HomeIns(string name, string square,float d, float c, float l)
        :Policy(name)
{
  this->square=square;dwelling=d;contents=c;liability=l;
  commission=liability*0.3+((dwelling+contents)*0.2);
}

void HomeIns::print(ostream& os) const
{
  cout<<"Home insurance"<<endl;
  cout<<"Name of insured: "<<name<<"\t"<<"Square: "<<square<<"\t"<<"Dwelling: "<<dwelling<<endl;
  cout<<"Contents: "<<contents<<"     "<<"Liability: "<<liability<<"     "<<"Commission: "<<commission<<endl;
}



#endif
