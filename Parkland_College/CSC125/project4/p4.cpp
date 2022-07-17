#include "AutoIns.h"
#include "HomeIns.h"
#include "LifeIns.h"
#include "Manager.h"
#include "Salesperson.h"

#include <cstdlib>
#include <sstream>

//showing the choice menu
void Choice(string& choice);

// transforming string to integer or float
template<class T>
void CheckNum(T& num,string& str);

// check the range of input
template<class T>
void CheckSize(T& num,string& str, vector<T> &all);

//add a manager or salesperson to the system
template<class T>
void addm(vector<T> &all);

//list out employees
template<class T>
void listE(vector<T> all);

//add a salesperson to a manager
void buildTeam(vector<Manager> &allm, vector<Salesperson> &alls);

//print out the policy menu
void policyMenu(string& input);

//add an automobile insurace
Policy* addAuto(vector<Policy *> allp);

//print out the print menu
void printMenu(string &input);

void remind(string& input);

int main()
{
  //set the decimal place
  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  vector<Salesperson> alls; vector<Salesperson>::iterator spos;
  vector<Manager> allm; vector<Manager>::iterator mpos;
  vector<Policy *> allp;

  Manager Zhao("Zhao",2000);
  Manager Li("Li",2000);
  allm.push_back(Zhao);
  allm.push_back(Li);

  while(1)
  {
    string choice="";

    Choice(choice);

    //add a manager to the system
    if(choice=="1")
    {
      string input="";
      while(1)
      {
        addm(allm);
        cout<<"You add "<<YEL<<allm[allm.size()-1].getName()<<RESET;
        cout<<" as a manager.\n";
        remind(input);
        if(input=="b"||input=="B"){break;}
      }
    }

    //add a salesperson to the system
    //asssign this salesperson to a manager
    else if (choice=="2")
    {
      if(allm.size()==0)
      {
        cout<<RED<<"\nNo manager in the system. ";
        cout<<"please creat at least one manager."<<RESET;
      }
      else
      {
        string input="";
        while(1)
        {
          addm(alls);
          buildTeam(allm,alls);
          remind(input);
          if(input=="b"||input=="B"){break;}
        }
      }
    }

    else if (choice=="3")
    {
        if(alls.size()==0&&allm.size()==0)
        {
          cout<<RED<<"\nNo sales people in the system. ";
          cout<<"please creat at least one sales person."<<RESET;
        }
        while(alls.size()>0||allm.size()>0)
        {
          string input="";

          policyMenu(input);

          if(input=="1")
          {
              string assign="";
              while(1)
              {
                  Policy* temp=addAuto(allp);
                  cout<<"Input m to asssign this sale to a manager.\n";
                  cout<<"Input s to asssign this sale to a Salesperson.\n";
                  if(assign=="m"||assign=="M")
                  {
                    float num; string numstring="";
                    cout<<"Please input the number of manager to assign.\n";
                    listE(allm);
                    cout<<"please input the number of the manager.\n";
                    cout<<GRN;getline(cin,numstring);cout<<RESET;
                    CheckSize(num,numstring,allm);
                    allm[num-1].setSales(temp);
                  }

                  remind(input);
                  if(input=="b"||input=="B"){break;}
              }
          }

          else if(input=="b"||input=="B"){break;}
        }
    }

    else if (choice=="4")
    {
        string input="";

        printMenu(input);

        if(input=="1")
        {
          for(int i=0;i<allm.size();++i)
          {
            allm[i].setTeamcom(alls);allm[i].calCommission();allm[i].setTotalsalary();
            cout<<allm[i]<<endl;
          }
          for(int i=0;i<alls.size();++i)
          {
            alls[i].calCommission();alls[i].setTotalsalary();
            cout<<alls[i]<<endl;
          }
        }
        else  if(input=="2")
        {
          for(int i=0;i<alls.size();++i)
          {
            alls[i].calCommission();alls[i].setTotalsalary();
          }
          allm[0].outputTeam(alls);
        }
      }

    else if (choice=="5"){break;}

    else{cout<<RED<<"\nInvalid input, please re-input."<<RESET;}
  }

  return 0;
}

//showing the choice menu
void Choice(string& choice)
{
  cout<<YEL<<"\nWelcome to Parkland Insurance Company:\n"<<RESET;
  cout<<setw(8)<<" "<<"1) Add a manager\n";
  cout<<setw(8)<<" "<<"2) Add a salesperson\n";
  cout<<setw(8)<<" "<<"3) Add an insurace sale\n";
  cout<<setw(8)<<" "<<"4) Print options\n";
  cout<<setw(8)<<" "<<"5) Exit\n";
  getline(cin,choice);
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
    else{num=i;}
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
  }
}

// check the range of input
template<class T>
void CheckSize(T& num,string& str, vector<T> &all)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    T i=0;
    stringstream temp;
    temp<<str;
    temp>>i;
    if(i<=0||i>all.size())
    {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckSize(num,str,all);
    }
    else{num=i;}
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckSize(num,str,all);
  }
}

//add a manager or salesperson to the system
template<class T>
void addm(vector<T> &all)
{
  string name="",basestring="";
  float basesalary=0.0;
  cout<<"Please input information of this employee.\n";
  cout<<"Input the name : ";
  cout<<YEL;getline(cin,name);cout<<RESET;
  cout<<"Input the basesalary : ";
  cout<<GRN;getline(cin,basestring);cout<<RESET;
  CheckNum(basesalary,basestring);
  T temp(name,basesalary);
  all.push_back(temp);
}

//list out employees
template<class T>
void listE(vector<T> all)
{
  for(int i=0;i<all.size();++i)
    cout<<GRN<<i+1<<" "<<YEL<<all[i].getName()<<RESET<<endl;
}


//add a salesperson to a manager
void buildTeam(vector<Manager> &allm, vector<Salesperson> &alls)
{
  float num; string numstring="";
  cout<<"Please asssign this salesperson to a manager.\n";
  for(int i=0;i<allm.size();++i)
    cout<<GRN<<i+1<<" "<<YEL<<allm[i].getName()<<RESET<<endl;
  cout<<"please input the number of the manager.\n";
  cout<<GRN;getline(cin,numstring);cout<<RESET;
  CheckSize(num,numstring,allm);
  allm[num-1].setTeam(alls.size()-1);
  cout<<"You add "<<YEL<<alls[alls.size()-1].getName()<<RESET;
  cout<<" as a salesperson,";
  cout<<" and asssign to the team of manager ";
  cout<<YEL<<allm[num-1].getName()<<RESET<<". \n";
}

//print out the policy menu
void policyMenu(string& input)
{
  cout<<"Input the number to add sales.\n";
  cout<<"1) Auto Insurance Policy\n";
  cout<<"2) Home Insurance Policy\n";
  cout<<"3) Life Insurance Policy\n";
  cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu\n";
  cout<<GRN;getline(cin,input);cout<<RESET;
}

//add an automobile insurace
Policy* addAuto(vector<Policy *> allp)
{
  string name="", model="",vin="",liabilitys="",collisions="";
  float liability=0.0,collision=0.0;
  cout<<"\nPlease input detials of this Auto Insurance policy.";
  cout<<"\nPlease input the name of insured : ";
  cout<<GRN;getline(cin,name);cout<<RESET;
  cout<<"\nPlease input the modle of the automobile : ";
  cout<<GRN;getline(cin,model);cout<<RESET;
  cout<<"\nPlease input the VIN number the automobile : ";
  cout<<GRN;getline(cin,vin);cout<<RESET;
  cout<<"\nPlease input the amount of liability coverage : ";
  cout<<GRN;getline(cin,liabilitys);cout<<RESET;
  CheckNum(liability,liabilitys);
  cout<<"\nPlease input the amount of collision coverage : ";
  cout<<GRN;getline(cin,collisions);cout<<RESET;
  CheckNum(collision,collisions);
  AutoIns *temp=new AutoIns(name,model,vin,liability,collision);
  allp.push_back(temp);
  cout<<"You added an automobile insurace sale to the system."<<endl<<endl;
  cout<<*(allp[allp.size()-1]);
  return temp;
}

//print out the print menu
void printMenu(string &input)
{
  cout<<"1) Print All Employees\n";
  cout<<"2) Print All Sales\n";
  cout<<"3) Print All Sales Made by All Employee In Tabular Format\n";
  cout<<"4) Print of All Sales Made by An Individual Employee\n";
  cout<<"5) Print All Sales Made by A Team Reporting to Individual Manager\n";
  cout<<"6) Back to Main Menu\n";
  cout<<GRN;getline(cin,input);cout<<RESET;
}

void remind(string& input)
{
    cout<<"Input "<<YEL<<"'y'"<<RESET<<" to add more.\n";
    cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu.\n";
    cout<<YEL;getline(cin,input);cout<<RESET;
    while(input!="Y"&&input!="y"&&input!="b"&&input!="B")
    {
      cout<<RED<<"\nInvalid input, please re-input.\n"<<RESET;
      cout<<"Input "<<YEL<<"'y'"<<RESET<<" to add more.\n";
      cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu.\n";
      cout<<YEL;getline(cin,input);cout<<RESET;
    }
}
