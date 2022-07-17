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
template<class T,class E>
void CheckSize(T& num,string& str, vector<E> &all);

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
Policy* addAuto();

//add an home insurace
Policy* addHome();

//add an life insurace
Policy* addLife();

//assign a sale to a employee
template<class T>
void assignSale(vector<T> &all,Policy* temp,string employee);

//claculate all employee's Salary
void calTotalsalary(vector<Manager> &allm, vector<Salesperson> &alls);

//list employee
template<class T,class V>
void listAllE(T& pos,V& all);

//list all sales for the employees in the vector
template<class T, class V>
void listSale(T& pos, V& all);

//list all sales for all employees in the vector
template<class T, class V>
void allSale(T& pos, V& all,string employee);

//print all sales for an individual employee
template<class T>
void salesIndvidual(vector<T> all,string employee);

//print the all sales for a team
void teamSales(vector<Manager>& allm,vector<Salesperson>& alls);

//print out the print menu
void printMenu(string &input);

void remind(string& input);

//debugging
void addInstantiations(vector<Manager> &allm,vector<Salesperson> &alls);

int main()
{
  //set the decimal place
  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  vector<Salesperson> alls; vector<Salesperson>::iterator spos;
  vector<Manager> allm; vector<Manager>::iterator mpos;

  //debugging
  addInstantiations(allm, alls);

  while(1)
  {
    string choice="";
    //main menu
    Choice(choice);

    //add a manager to the system
    if(choice=="1")
    {
      string input="";
      while(1)
      {
        //add an employee
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
        cout<<"Please creat at least one manager."<<RESET;
      }
      else
      {
        string input="";
        while(1)
        {

          //add an employee
          addm(alls);
          //assign this saleperson to a manager
          buildTeam(allm,alls);
          remind(input);
          if(input=="b"||input=="B"){break;}
        }
      }
    }

    //add a insurace sale in the system
    else if (choice=="3")
    {
        //stiuation for no one saleperson in the system
        if(alls.size()==00)
        {
          cout<<RED<<"\nNo salesperson in the system. ";
          cout<<"Please creat at least one salesperson."<<RESET;
        }
        //stiuation for no one manager in the system
        else if(allm.size()==0)
        {
          cout<<RED<<"\nNo manager in the system. ";
          cout<<"Please creat at least one manager."<<RESET;
        }
        //loop to add sale to an employee
        while(alls.size()>0&&allm.size()>0)
        {
          string input="";

          policyMenu(input);
          //add automobile Insurance
          if(input=="1")
          {
              string assign="";
              //pointer for new sale
              Policy* temp=addAuto();

              cout<<"Input "<<YEL<<"'m'"<<RESET<<" to asssign this sale to a manager.\n";
              cout<<"Input "<<YEL<<"'s'"<<RESET<<" to asssign this sale to a Salesperson.\n";
              cout<<GRN;getline(cin,assign);cout<<RESET;
              while(assign!="M"&&assign!="m"&&assign!="s"&&assign!="S")
              {
                  cout<<RED<<"\nInvalid input. Please re-input."<<RESET;
                  cout<<GRN;getline(cin,assign);cout<<RESET;
              }
              if(assign=="m"||assign=="M"){assignSale(allm,temp,"manager");}
              else if(assign=="s"||assign=="S"){assignSale(alls,temp,"salesperson");}
          }

          //add home Insurance
          else if(input=="2")
          {
            string assign="";
            //pointer for new sale
            Policy* temp=addHome();

            cout<<"Input "<<YEL<<"'m'"<<RESET<<" to asssign this sale to a manager.\n";
            cout<<"Input "<<YEL<<"'s'"<<RESET<<" to asssign this sale to a Salesperson.\n";
            cout<<GRN;getline(cin,assign);cout<<RESET;
            while(assign!="M"&&assign!="m"&&assign!="s"&&assign!="S")
            {
                cout<<RED<<"\nInvalid input. Please re-input."<<RESET;
                cout<<GRN;getline(cin,assign);cout<<RESET;
            }
            if(assign=="m"||assign=="M"){assignSale(allm,temp,"manager");}
            else if(assign=="s"||assign=="S"){assignSale(alls,temp,"salesperson");}
          }
          //add life Insurance
          else if(input=="3")
          {
            string assign="";
            //pointer for new sale
            Policy* temp=addLife();

            cout<<"Input "<<YEL<<"'m'"<<RESET<<" to asssign this sale to a manager.\n";
            cout<<"Input "<<YEL<<"'s'"<<RESET<<" to asssign this sale to a Salesperson.\n";
            cout<<GRN;getline(cin,assign);cout<<RESET;
            while(assign!="M"&&assign!="m"&&assign!="s"&&assign!="S")
            {
                cout<<RED<<"\nInvalid input. Please re-input."<<RESET;
                cout<<GRN;getline(cin,assign);cout<<RESET;
            }
            if(assign=="m"||assign=="M"){assignSale(allm,temp,"manager");}
            else if(assign=="s"||assign=="S"){assignSale(alls,temp,"salesperson");}
            }
            //break the loop
            else if(input=="b"||input=="B"){break;}
            //worng input
            else{cout<<RED<<"\nInvalid input. Please re-input.\n"<<RESET;}
          }

    }

    //print options
    else if (choice=="4")
    {
        //claculate all employee's Salary
        calTotalsalary(allm,alls);

        string input="";

        //loop to print sales and employees
        while(1)
        {
          printMenu(input);

          //print out all employees
          if(input=="1")
          {
            cout<<"\nAll managers in the system.\n";
            listAllE(mpos,allm);
            cout<<"\nAll salespersons in the system.\n";
            listAllE(spos,alls);
            cout<<"\nThere are "<<GRN<<allm.size()+alls.size()<<RESET<<" employees in the system.\n";
          }
          //print out all sales
          else  if(input=="2")
          {
            cout<<"\nAll sales records in the system.\n";
            listSale(mpos,allm);
            listSale(spos,alls);
            int temp=0;
            for(int i=0;i<allm.size();++i){temp+=allm[i].getSalesize();}
            for(int i=0;i<alls.size();++i){temp+=alls[i].getSalesize();}
            cout<<"\nThere are "<<GRN<<temp<<RESET<<" sales records in the system.\n";
          }

          //print all sales with employees in Tabular Format
          else if(input=="3")
          {
            //list all sales for all employees in the vector
            allSale(mpos, allm,"manager");
            allSale(spos, alls, "salesperson");
          }

          //print sales with the individual employee
          else if(input=="4")
          {
            string assign="";
            //loop to choose which employee to print
            while(1)
            {
              cout<<"Sales are made by an individual employee.\n";
              cout<<"Input "<<YEL<<"'m'"<<RESET<<" to choose a manager.\n";
              cout<<"Input "<<YEL<<"'s'"<<RESET<<" to chosee a Salesperson.\n";
              cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main main.\n";
              cout<<GRN;getline(cin,assign);cout<<RESET;
              while(assign!="M"&&assign!="m"&&assign!="s"&&assign!="S"&&assign!="b"&&assign!="B")
              {
                  cout<<RED<<"\nInvalid input. Please re-input."<<RESET;
                  cout<<GRN;getline(cin,assign);cout<<RESET;
              }
              if(assign=="m"||assign=="M")
              {
                //print all sales for an individual employee
                salesIndvidual(allm,"manager");
              }
              else if(assign=="s"||assign=="S"){salesIndvidual(alls,"salesperson");}
              //break the loop
              else if(assign=="b"||assign=="B"){break;}
              else{cout<<RED<<"\nInvalid input. Please re-input.\n"<<RESET;}
            }
          }

          //print the sales from a team
          else if(input=="5")
          {
            //print the all sales for a team
            teamSales(allm,alls);
          }

          //break the loop
          else if(input=="b"||input=="B"){break;}

          else{cout<<RED<<"\nInvalid input. Please re-input.\n"<<RESET;}
        }
      }

    //exit
    else if (choice=="5"){exit (-1);}

    else{cout<<RED<<"\nInvalid input. Please re-input."<<RESET;}
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
      cout<<RED<<"Invaliad input. Please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
    }
    else{num=i;}
  }
  else
  {
      cout<<RED<<"Invaliad input. Please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
  }
}

// check the range of input
template<class T,class E>
void CheckSize(T& num,string& str, vector<E> &all)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    T i=0;
    stringstream temp;
    temp<<str;
    temp>>i;
    if(i<=0||i>all.size())
    {
      cout<<RED<<"Invaliad input. Please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckSize(num,str,all);
    }
    else{num=i;}
  }
  else
  {
      cout<<RED<<"Invaliad input. Please re-input :";
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
    cout<<"No."<<GRN<<i+1<<" "<<YEL<<all[i].getName()<<RESET<<endl;
}


//add a salesperson to a manager
void buildTeam(vector<Manager> &allm, vector<Salesperson> &alls)
{
  float num; string numstring="";
  cout<<"Please asssign this salesperson to a manager.\n";
  listE(allm);
  cout<<"Please input the "<<YEL<<"number"<<RESET<<" of the manager.\n";
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
  cout<<"Input the "<<YEL<<"number"<<RESET<<" to add sales.\n";
  cout<<"1) Auto Insurance Policy\n";
  cout<<"2) Home Insurance Policy\n";
  cout<<"3) Life Insurance Policy\n";
  cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu\n";
  cout<<GRN;getline(cin,input);cout<<RESET;
}

//add an automobile insurace
Policy* addAuto()
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
  cout<<"\nYou added an automobile insurace sale to the system."<<endl;
  return temp;
}

//add an home insurace
Policy* addHome()
{
  string name="", squares="",dwellings="",contentss="",liabilitys="";
  float square=0.0,dwelling=0.0,contents=0.0, liability=0.0;
  cout<<"\nPlease input detials of this Home Insurance policy.";
  cout<<"\nPlease input the name of insured : ";
  cout<<GRN;getline(cin,name);cout<<RESET;
  cout<<"\nPlease input house square footage : ";
  cout<<GRN;getline(cin,squares);cout<<RESET;
  CheckNum(square,squares);
  cout<<"\nPlease input the amount of dwelling coverage : ";
  cout<<GRN;getline(cin,dwellings);cout<<RESET;
  CheckNum(dwelling,dwellings);
  cout<<"\nPlease input the amount of contents coverage : ";
  cout<<GRN;getline(cin,contentss);cout<<RESET;
  CheckNum(contents,contentss);
  cout<<"\nPlease input the amount of liability coverage : ";
  cout<<GRN;getline(cin,liabilitys);cout<<RESET;
  CheckNum(liability,liabilitys);
  HomeIns *temp=new HomeIns(name,square,dwelling,contents,liability);
  cout<<"\nYou added an automobile insurace sale to the system."<<endl;
  return temp;
}

//add an home insurace
Policy* addLife()
{
  string name="", dependent="",ages="",coverages="";
  int age=0;
  float coverage=0.0;
  cout<<"\nPlease input detials of this Home Insurance policy.";
  cout<<"\nPlease input the name of insured : ";
  cout<<GRN;getline(cin,name);cout<<RESET;
  cout<<"\nPlease input age of insured : ";
  cout<<GRN;getline(cin,ages);cout<<RESET;
  CheckNum(age,ages);
  cout<<"\nPlease input the name of dependent : ";
  cout<<GRN;getline(cin,dependent);cout<<RESET;
  cout<<"\nPlease input the amount of term life coverage : ";
  cout<<GRN;getline(cin,coverages);cout<<RESET;
  CheckNum(coverage,coverages);
  LifeIns *temp=new LifeIns(name,age,dependent,coverage);
  cout<<"\nYou added an automobile insurace sale to the system."<<endl;
  return temp;
}

//assign a sale to a employee
template<class T>
void assignSale(vector<T> &all,Policy* temp,string employee)
{
  float num; string numstring="";
  listE(all);
  cout<<"Please input the "<<YEL<<"number"<<RESET<<" of the "<<employee<<" to assign.\n";
  cout<<GRN;getline(cin,numstring);cout<<RESET;
  CheckSize(num,numstring,all);
  all[num-1].setSales(temp);
  cout<<*(all[num-1].getSales(all[num-1].getSalesize()-1))<<endl;
  cout<<"You assigned this sale to the "<<employee<<" ";
  cout<<YEL<<all[num-1].getName()<<RESET<<". "<<endl;
}

//claculate all employee's Salary
void calTotalsalary(vector<Manager> &allm, vector<Salesperson> &alls)
{
  for(int i=0;i<alls.size();++i)
  {
    alls[i].calCommission();
    alls[i].setTotalsalary();
  }
  for(int i=0;i<allm.size();++i)
  {
    allm[i].setTeamcom(alls);
    allm[i].calCommission();
    allm[i].setTotalsalary();
  }
}

//list all sales for the employees in the vector
template<class T,class V>
void listAllE(T& pos,V& all)
{
  for(pos=all.begin();pos!=all.end();++pos)
  {
    cout<<*pos<<endl;
  }
}


//list all sales for the employees in the vector
template<class T, class V>
void listSale(T& pos, V& all)
{
  for(pos=all.begin();pos!=all.end();++pos)
  {
      pos->printSales();
  }
  cout<<endl;
}

//list all sales for all employees in the vector
template<class T, class V>
void allSale(T& pos, V& all,string employee)
{
  for(pos=all.begin();pos!=all.end();++pos)
  {
    cout<<"\nCheck sales are made by \n";
    cout<<*pos;
    pos->printSales();
  }
}


//print all sales for an individual employee
template<class T>
void salesIndvidual(vector<T> all,string employee)
{
  float num; string numstring="";
  for(int i=0;i<all.size();++i)
  {
    cout<<"No."<<GRN<<i+1<<" "<<YEL<<left<<setw(16)<<all[i].getName()<<RESET;
    cout<<"Sales made : "<<GRN<<all[i].getSalesize()<<RESET<<".\n";
  }

  cout<<"Please input the "<<YEL<<"number"<<RESET<<" of the "<<employee<<" you want to check sales.\n";
  cout<<GRN;getline(cin,numstring);cout<<RESET;
  CheckSize(num,numstring,all);
  cout<<"\nSales are made by "<<MAG<<employee<<" "<<YEL<<all[num-1].getName()<<RESET<<".";
  all[num-1].printSales();
}


//print the all sales for a team
void teamSales(vector<Manager>& allm,vector<Salesperson>& alls)
{
  float num; string numstring="";
  for(int i=0;i<allm.size();++i)
  {
    cout<<"No."<<GRN<<i+1<<" "<<YEL<<left<<setw(25)<<allm[i].getName()<<RESET;
    cout<<"     Team member : "<<GRN<<allm[i].teamSize()<<RESET".\n";
  }
  cout<<"\nInput the "<<YEL<<"number"<<RESET<<" of the team leader to check sales.\n";
  cout<<GRN;getline(cin,numstring);cout<<RESET;
  CheckSize(num,numstring,allm);
  cout<<"\nSales are made by the team leaded by "<<MAG<<"manager "<<YEL<<allm[num-1].getName()<<RESET<<".\n";
  cout<<"\nSales are made by the leader as "<<MAG<<"manager "<<YEL<<allm[num-1].getName()<<RESET<<".";
  allm[num-1].printSales();
  if(allm[num-1].teamSize()>0)
  {
      for(int i=0;i<allm[num-1].teamSize();++i)
      {
        int temp=0;
        temp=allm[num-1].getTeam(i);
        cout<<"\nSales are made by the team member as "<<MAG<<"salesperson "<<YEL<<alls[temp].getName()<<RESET<<".";
        alls[temp].printSales();
      }
  }
}

//print out the print menu
void printMenu(string &input)
{
  cout<<"1) Print All Employees\n";
  cout<<"2) Print All Sales\n";
  cout<<"3) Print All Sales Made by All Employee In Tabular Format\n";
  cout<<"4) Print of All Sales Made by An Individual Employee\n";
  cout<<"5) Print All Sales Made by A Team Reporting to Individual Manager\n";
  cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to Main Menu\n";
  cout<<GRN;getline(cin,input);cout<<RESET;
}

void remind(string& input)
{
    cout<<"Input "<<YEL<<"'y'"<<RESET<<" to add more.\n";
    cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu.\n";
    cout<<YEL;getline(cin,input);cout<<RESET;
    while(input!="Y"&&input!="y"&&input!="b"&&input!="B")
    {
      cout<<RED<<"\nInvalid input, Please re-input.\n"<<RESET;
      cout<<"Input "<<YEL<<"'y'"<<RESET<<" to add more.\n";
      cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to main menu.\n";
      cout<<YEL;getline(cin,input);cout<<RESET;
    }
}

void addInstantiations(vector<Manager> &allm,vector<Salesperson> &alls)
{
  Manager Iron("Iron man",2000);
  Manager Captain("Captain America",2000);
  allm.push_back(Iron);
  allm.push_back(Captain);
  Salesperson Ant("Ant man",1000);
  Salesperson Hawkeye("Hawkeye",1000);
  Salesperson Thor("Thor",1000);
  alls.push_back(Ant);
  alls.push_back(Hawkeye);
  alls.push_back(Thor);
  allm[1].setTeam(0);
  allm[1].setTeam(1);
  allm[0].setTeam(2);
  AutoIns *s=new AutoIns("Rocket","Galaxy mark3","CIA2463",1000.00,1000.00);
  AutoIns *v=new AutoIns("War Machine","Suit mark3","766563",1000.00,1000.00);
  HomeIns *d=new HomeIns("Black Widow",456,1000,1000,1000);
  HomeIns *e=new HomeIns("Thanos",8000,1000,1000,1000);
  LifeIns *l=new LifeIns("Captain Marvel", 20,"Nebula",1000);
  LifeIns *z=new LifeIns("Hulk", 30,"Bruce Banner",1000);
  allm[0].setSales(s);
  allm[0].setSales(d);
  allm[1].setSales(l);
  alls[0].setSales(v);
  alls[1].setSales(z);
  alls[2].setSales(e);
}
