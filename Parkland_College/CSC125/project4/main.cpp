#include "AutoIns.h"
#include "HomeIns.h"
#include "LifeIns.h"
#include "Manager.h"
#include "Salesperson.h"
#include "Employee.h"
#include <sstream>

template<class T>
void CheckNum(T& num,string& str);

template<class T>
void addm(vector<T> &allm);

int main()
{

  vector<Salesperson> alls;
  vector<Manager> allm;
  Manager Zhao("Zhao",2000);
  Manager Li("Li",2000);
  allm.push_back(Zhao);
  allm.push_back(Li);
  Salesperson Ziu("Ziu",2000);
  Salesperson Liu("Liu",2000);
  alls.push_back(Ziu);
  AutoIns *s=new AutoIns("K","ford mark3","cai463",1000.00,1000.00);
  AutoIns *v=new AutoIns("V","Toto mark3","766563",1000.00,1000.00);
  HomeIns *d=new HomeIns("S",456,1000,1000,1000);
  LifeIns *l=new LifeIns("He", 20,"Li xiao ming",1000);
  LifeIns *z=new LifeIns("Yhu", 10,"Zhang jun",1000);
  Zhao.setSales(s);
  Zhao.setSales(v);
  Li.setSales(d);
  Liu.setSales(l);
  Ziu.setSales(z);
  Salesperson temp=Ziu;
  allm[0].sett(temp);
  allm[0].sett(Ziu);
  cout<<*(allm[0].rt(0).getSales(0));
  allm[0].rt(0).printSales();
}


//add a manager to the system
template<class T>
void addm(vector<T> &all)
{
  string name="",basestring="";
  float basesalary=0.0;
  cout<<"Please input information of this manager.\n";
  cout<<"Input the name : ";
  cout<<YEL;getline(cin,name);cout<<RESET;
  cout<<"Input the basesalary : ";
  cout<<GRN;getline(cin,basestring);cout<<RESET;
  CheckNum(basesalary,basestring);
  T temp(name,basesalary);
  all.push_back(temp);
}

void adds(vector<Salesperson>& alls)
{
  string name="",basestring="";
  float basesalary=0.0;
  cout<<"Please input information of this manager.\n";
  cout<<"Input the name : ";
  cout<<YEL;getline(cin,name);cout<<RESET;
  cout<<"Input the basesalary : ";
  cout<<GRN;getline(cin,basestring);cout<<RESET;
  CheckNum(basesalary,basestring);
  Salesperson temp(name,basesalary);
  alls.push_back(temp);
}

// transforming string to integer or float
template<class T>
void CheckNum(T& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    T i=0;
    stringstream temp;
    temp<<str;
    temp>>i;
    if(i<=0)
    {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
    }
    else
    {
      num=i;
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
  }
}
