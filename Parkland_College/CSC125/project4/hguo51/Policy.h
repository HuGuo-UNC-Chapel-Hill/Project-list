#ifndef _POLICY_H_
#define _POLICY_H_


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define MAG   "\x1B[35m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define RESET  "\x1B[0m"

class Policy
{
protected:
  string type;
  float commission;
  string name;
public:
  Policy(string name="");

  virtual ~Policy(){};

  void setName(string name=""){this->name=name;}
  string getName()const{return name;}

  void setType(string t){type=t;}
  string getType()const{return type;}

  float getCommission()const{return commission;}

  virtual ostream &print(ostream& os) const=0;
  friend ostream &operator<<(ostream& os, const Policy &i)
  {
      return i.print(os);
  }
};


#endif
