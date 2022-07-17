#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "Policy.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define MAG   "\x1B[35m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define RESET  "\x1B[0m"



class Employee
{
protected:
  string name;
  float basesalary;
  float commission;
  float totalsalary;
  vector<Policy *> sales;
public:
  Employee(string name="",float b=0.0);
  virtual ~Employee();

  void setName(string name){this->name=name;}
  string getName()const{return name;}

  void setBasesalary(float b){basesalary=b;}
  float getBasesalary()const {return basesalary;}

  virtual void calCommission()=0;
  float getCommission()const {return commission;}

  void setTotalsalary(){totalsalary=basesalary+commission;}
  float getTotalsalary()const{return totalsalary;}

  void setSales(Policy *s){sales.push_back(s);}
  Policy* getSales(int n){return sales[n];}
  int getSalesize(){return sales.size();}

  void printSales();

  friend ostream &operator<<(ostream& os, const  Employee &e)
  {
    return e.print(os);
  }
  virtual ostream& print(ostream &os) const=0;
};
/*
Employee::Employee(string n, float b):
          name(n),basesalary(b)
{
  commission=0;
  totalsalary=0;
}

Employee::~Employee()
{
  //cout<<"Em detor is called"<<endl;
  return;
}

void Employee::printSales()
{
  for(int i=0;i<sales.size();++i)
    cout<<*(sales[i])<<endl;
}*/

#endif
