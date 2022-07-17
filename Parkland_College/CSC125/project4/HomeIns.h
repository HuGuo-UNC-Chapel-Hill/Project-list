#ifndef _HomeIns_H_
#define _HomeIns_H_
#include "Policy.h"

class HomeIns :public Policy
{
private:
  float square;
  float dwelling;
  float contents;
  float liability;
public:
  HomeIns(string name, float s,float d, float c, float l);
   ~HomeIns(){cout<<"Home detor is called"<<endl;}
  float getComm() const{return commission;}
  ostream &print(ostream& os)const;


  void setSquare(float s){square=s;}
  void setDwelling(float d){dwelling=d;}
  void setContents(float c){contents=c;}
  void setLiability(float l ){liability=l;}

  float getSquare()const{return square;}
  float getDwelling()const{return dwelling;}
  float getContents()const{return contents;}
  float getLiability()const{return liability;}
};

/*
HomeIns::HomeIns(string name, float s,float d, float c, float l)
        :Policy(name)
{
  square=s;dwelling=d;contents=c;liability=l;
  setType("Home Insurance");
  commission=liability*0.3+((dwelling+contents)*0.2);
}

ostream &HomeIns::print(ostream& os) const
{
  cout.setf(ios::left);
  os<<YEL<<getType()<<RESET<<"\n";
  os<<"Name of Insured : "<<GRN<<setw(23)<<getName()<<RESET<<" ";
  os<<"Square Footage : "<<GRN<<square<<RESET<<" ";
  os<<setw(9)<<" "<<"Dwelling Coverage : "<<GRN<<dwelling<<RESET<<" \n";
  os<<setw(39)<<" "<<"Contents Coverage : "<<GRN<<contents<<RESET<<" ";
  os<<setw(6)<<" "<<"Liability Coverage : "<<GRN<<liability<<RESET<<" ";
  os<<setw(7)<<" "<<"Commission : "<<GRN<<getCommission()<<RESET<<endl;
  return os;
}
*/


#endif
