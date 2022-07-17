#include "Account.h"
#include "Person.h"



typedef vector<Person>* VPP;

VPP ListPtr;

vector<Person> List;

//displaying the welcome menu
void welcome(char& choice);

//showing the choice menu
void Choice(char& choice);

//Creating the account
void Create();

//printing out summary for all accounts
void PrintSum();

//Printing out details for all accounts
void PrintAll();

//Change string to int
int StrtoI(string input);

//Print one account out
void PrintOne(string input);

void AddAccounts();

int main()
{
  char choice;



  //vector<Person> List;

  ListPtr=&List;

  AddAccounts();

  welcome(choice);

  cout<<endl;


  do
  {
     if(choice=='1')
     {

         choice=0;

         Create();


         //List[0].perPrint();
         cout<<endl;

         Choice(choice);
     }

     if(choice=='2')
     {
       choice=0;
       string input;

       if( List.size()==0)
       {
          cout<<RED<<"No account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
       else
       {
          PrintSum();
          cout<<"There are "<<ListPtr->size()<<" accounts in the system."<<endl;
          cout<<"Please input 0-"<<ListPtr->size()<<" to print the detail of that account out,"<<endl;
          cout<<"or input 'a' to print details of all accounts out."<<endl;
          cin>>input;

          if(input== "a"||input== "A")
          {
             PrintAll();
             cout<<endl;
          }
          else if(StrtoI(input)<=ListPtr->size()&&StrtoI(input)>=0)
          {
              PrintOne(input);
              cout<<endl;
          }
          else
          {
              cout<<"Invalid input, please re-input:";
              cin>>input;
              cout<<endl;
          }

          cout<<endl;
       }

       Choice(choice);
     }


     else if(choice=='6')
     {
         exit (-1);

     }

   }while(choice!='n'||choice!='N');


  return 0;
}

//displaying the welcome menu
void welcome(char& choice)
{
  cout<<"\n----------------------------------------\n";
  cout<<"Welcome to the First National Bank\n";
  cout<<"of Parkland - Account transaction system\n";
  cout<<"----------------------------------------\n";
  cout<<"Enter any of the following commands:\n";
  cout.setf(ios::left);
  cout<<setw(8)<<" "<<"1) Create account\n";
  cout<<setw(8)<<" "<<"2) Print account\n";
  cout<<setw(8)<<" "<<"3) Select account\n";
  cout<<setw(8)<<" "<<"4) Deposit\n";
  cout<<setw(8)<<" "<<"5) Withdrawal\n";
  cout<<setw(8)<<" "<<"6) Quit\n";
  cin>>choice;

}

//showing the choice menu
void Choice(char& choice)
{
  cout.setf(ios::left);
  cout<<"Enter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Create account\n";
  cout<<setw(8)<<" "<<"2) Print account\n";
  cout<<setw(8)<<" "<<"3) Select account\n";
  cout<<setw(8)<<" "<<"4) Deposit\n";
  cout<<setw(8)<<" "<<"5) Withdrawal\n";
  cout<<setw(8)<<" "<<"6) Quit\n";
  cin>>choice;

}

void AddAccounts()
{
  Person temp(1000,1.1,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview, VA 97820","224-46-0407");
  ListPtr->push_back(temp);
  Person temp1(2200,1.2,"Marvin", "Jerod","197 Chyna Radial Suite 370 East Sadieland, ID 48579","306-42-6992");
  ListPtr->push_back(temp1);
  Person temp2(3400,3.2,"Rogahn", "Georgette","9480 Juliana Village Suite 152 Wehnerbury, MT 36099","649-05-1129");
  ListPtr->push_back(temp2);
}


//Creating the account
void Create()
{
  float bal=0,rate=0;
  string firstname="",lastname="",address="",ssn="";
  cout<<"Please input the firstname :";
  cin>>firstname;
  //cout<<endl;
  cout<<"Please input the lastname :";
  cin>>lastname;
  //cout<<endl;
  cout<<"Please input the address :";
  cin>>address;
  //cout<<endl;
  cout<<"Please input the ssn :";
  cin>>ssn;
  //cout<<endl;
  cout<<"Please set the interest rate :";
  cin>>rate;
  //cout<<endl;
  cout<<"Please input the balance :";
  cin>>bal;
  //cout<<endl;

  Person temp(bal,rate,firstname,lastname,address,ssn);
  ListPtr->push_back(temp);
  cout<<endl;
}

void PrintSum()
{
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);

  cout<<"----------------------------------------------\n";
  cout<<" No.  "<<setw(20)<<"Name"<<setw(16)<<"Balance"<<endl;
  cout<<"----------------------------------------------\n";
  //cout<<List[0].getBala();
  for(int i=0;i<vecSize;++i)
  {
        name=List[i].getFirst()+"."+List[i].getLast();
        cout<<" "<<i<<"    "<<setw(20)<<name<<setw(11)<<List[i].getBala()<<endl;
  }
  cout<<"----------------------------------------------\n";
}

//Printing out accounts
void PrintAll()
{
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<"-----------------------------------------------";
  cout<<"-------------------------------------------------\n";
  cout<<" No.  "<<setw(20)<<"Name"<<setw(16)<<"Interest Rate";
  cout<<setw(10)<<"Balance"<<setw(13)<<"Ssn Number"<<"Address"<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------\n";
  //cout<<List[0].getBala();
  for(int i=0;i<vecSize;++i)
  {
        name=List[i].getFirst()+"."+List[i].getLast();
        cout<<" "<<i<<"    "<<setw(25)<<name<<setw(11);
        cout<<List[i].getRate()<<setw(10)<<List[i].getBala();
        cout<<setw(13)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  }
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------\n";
}

//Change string to int
int StrtoI(string input)
{
  int i=0;
  stringstream s;
  s<<input;
  s>>i;
  return i;
}

//Print one account out
void PrintOne(string input)
{
  int i=0;
  i=StrtoI(input);
  string name;
  cout.setf(ios::left);
  cout<<"-----------------------------------------------";
  cout<<"-------------------------------------------------\n";
  cout<<" No.  "<<setw(20)<<"Name"<<setw(16)<<"Interest Rate";
  cout<<setw(10)<<"Balance"<<setw(13)<<"Ssn Number"<<"Address"<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------\n";
  name=List[i].getFirst()+"."+List[i].getLast();
  cout<<" "<<i<<"    "<<setw(25)<<name<<setw(11);
  cout<<List[i].getRate()<<setw(10)<<List[i].getBala();
  cout<<setw(13)<<List[i].getSsn()<<List[i].getAdd()<<endl;
   cout<<"-----------------------------------------------";
  cout<<"-------------------------------------------------\n";
}
