#ifndef _Policy_h_
#define _Policy_h_


#include <iostream>
#include <string>
using namespace std;

class Policy
{
protected:
  string name;
  float commission;
public:
  Policy(string name="")
  {
      this->name=name;
      commission=0.0;
  }
  virtual ~Policy(){};
  void setName(string name=""){this->name=name;}
  string getName()const{return name;}
  float getCommission()const{return commission;}
  virtual float getComm() const=0;
  virtual void print(ostream& os) const=0;
  friend ostream &operator<<(ostream& os,const Policy &i)
  {
      i.print(os);
      return os;
  }
};


#endif
