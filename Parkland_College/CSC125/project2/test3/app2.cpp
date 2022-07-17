#include "Account.h"
#include "Person.h"

typedef vector<Person>* VPP;

VPP ListPtr;

//displaying the welcome menu
void welcome(char& choice);

//showing the choice menu
void Choice(char& choice);

//Creating the account
void Create();

//Printing out accounts 
void PrintOut(vector<Person> List);

int main()
{ 
  char choice;  
     
  
      
  vector<Person> List;
  
  ListPtr=&List;
  
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
       
       
       if( List.size()==0)
       {
          cout<<RED<<"No account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
       else
       {
         PrintOut(List);
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
  cout<<YEL<<"\n----------------------------------------\n";
  cout<<"Welcome to the First National Bank\n";
  cout<<"of Parkland - Account transaction system\n";
  cout<<"----------------------------------------\n";
  cout<<GRN<<"Enter any of the following commands:\n";
  cout.setf(ios::left);
  cout<<setw(8)<<" "<<"1) Create account\n";
  cout<<setw(8)<<" "<<"2) Print account\n";
  cout<<setw(8)<<" "<<"3) Select account\n";
  cout<<setw(8)<<" "<<"4) Deposit\n";
  cout<<setw(8)<<" "<<"5) Withdrawal\n";
  cout<<setw(8)<<" "<<"6) Quit\n"<<GRN;
  cin>>choice;
  cout<<RESET;
}

//showing the choice menu
void Choice(char& choice)
{  
  cout.setf(ios::left);
  cout<<GRN<<"Enter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Create account\n";
  cout<<setw(8)<<" "<<"2) Print account\n";
  cout<<setw(8)<<" "<<"3) Select account\n";
  cout<<setw(8)<<" "<<"4) Deposit\n";
  cout<<setw(8)<<" "<<"5) Withdrawal\n";
  cout<<setw(8)<<" "<<"6) Quit\n"<<GRN;
  cin>>choice;
  cout<<RESET;
}

//Creating the account
void Create()
{
  float bal=0,rate=0;
  string firstname="",lastname="",address="",ssn="";
  cout<<"Please input the firstname :";
  cin>>firstname;
  cout<<endl;
  cout<<"Please input the lastname :";
  cin>>lastname;
  cout<<endl;
  cout<<"Please input the address :";
  cin>>address;
  cout<<endl;
  cout<<"Please input the ssn :";
  cin>>ssn;
  cout<<endl;
  cout<<"Please input the balance :";
  cin>>bal;
  cout<<endl;
  cout<<"Please input the interest rate :";
  cin>>rate;
  cout<<endl;
  Person temp(bal,rate,firstname,lastname,address,ssn);   
  ListPtr->push_back(temp); 
  cout<<endl;
}

//Printing out accounts 
void PrintOut(vector<Person> List)
{ 
  
  
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<YEL<<"------------------------------------------";
  cout<<"----------------------------------------------\n";
  cout<<" No.\t"<<setw(16)<<"Name"<<setw(15)<<"Address"<<setw(14);
  cout<<"ssn"<<setw(13)<<"Balance"<<"Interest Rate"<<endl;
  cout<<"---------------------------------------------";
  cout<<"-------------------------------------------\n";
  cout<<GRN;
  cout<<List[0].getBala();
  /*for(int i=0;i<vecSize;++i)
    {
        cout<<setw(18)<<ListPtr->getFirst()<<"."<<ListPtr->getLast();
        cout<<setw(18)<<ListPtr->getAdd()<<setw(16);
        cout<<ListPtr->getBala()<<"\t"<<ListPtr->getRate()<<endl;
    }*/
  cout<<RESET;
}



