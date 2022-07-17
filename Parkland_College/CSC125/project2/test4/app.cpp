#include "Account.h"
#include "Person.h"



typedef vector<Person>* VPP;

VPP ListPtr;

vector<Person> List;

//displaying the welcome menu
void welcome(string& choice);

//showing the choice menu
void Choice(string& choice);

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

//Decide printing of accounts
void PrintF(string& input2);

//check the correct input
void remind(string& input);

void CheckNum(float& num);

//add 3 instances to the class
void AddAccounts();

int main()
{
  string choice,input1,input2;

  ListPtr=&List;

  AddAccounts();

  welcome(choice);
  cin.ignore();

  do
  {
     if(choice=="1")
     {
         do
         {
            if(input1=="c"||input1=="C")
                Create();
            PrintSum();
            cout<<"Input"<<YEL<<" 'c'"<<RESET<<"To create an account "<<endl;
            cout<<"Input"<<YEL<<" 'b'"<<RESET<<"To back to the main menu"<<GRN<<endl;
            cin>>input1;
            cin.ignore();
            cout<<RESET;
            remind(input1);
         }while(input1!="b"&&input1!="B");

         Choice(choice);
         cin.ignore();
     }

     if(choice=="2")
     {
       if( List.size()==0)
       {
          cout<<RED<<"\nNo account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
       else
       {
          PrintSum();
          do{
                if(ListPtr->size()==1)
                {
                    cout<<"\nInput "<<YEL<<"1"<<RESET<<" to print out details of that account."<<endl;
                }
                else if(ListPtr->size()>1)
                {
                    cout<<"\nInput "<<YEL<<" 1-"<<ListPtr->size()<<RESET;
                    cout<<" to print out details of "<<YEL<<"one account."<<RESET<<endl;
                }
                cout<<"Input "<<YEL<<"'a'"<<RESET<<" to print out details of "<<YEL<<"all account."<<RESET<<endl;
                cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<GRN<<endl;
                cin>>input2;
                cin.ignore();
                cout<<RESET;
                PrintF(input2);
            }while(input2!="b"&&input2!= "B");
        }

       Choice(choice);
       cin.ignore();
     }


     else if(choice=="6")
     {
         exit (-1);

     }

   }while(choice!="6"||choice!="6");


  return 0;
}

//displaying the welcome menu
void welcome(string& choice)
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
void Choice(string& choice)
{
  cout.setf(ios::left);
  cout<<"\nEnter any of the following commands:\n";
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
  Person temp(1000,1.1,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview","224-46-0407");
  ListPtr->push_back(temp);
  Person temp1(2200,1.2,"Marvin", "Jerod","197 Chyna Radial Suite 370 East Sadieland","306-42-6992");
  ListPtr->push_back(temp1);
  Person temp2(3400,3.2,"Rogahn", "Georgette","9480 Juliana Village Suite 152 Wehnerbury","649-05-1129");
  ListPtr->push_back(temp2);
}

void CheckNum(float& num)
{
  while(num<0)
  {
    cout<<RED<<"Invalid input, please re-input the rate : ";
    cin>>num;
    cin.ignore();
    RESET;
    CheckNum(num);
  }
}


//Creating the account
void Create()
{
  float bal=0,rate=0;
  string firstname="",lastname="",address="",ssn="";
  
  cout<<"Please input the"<<YEL<<" firstname"<<RESET<<" : "<<GRN;
  getline(cin,firstname,'\n');
  cout<<RESET;

  cout<<"Please input the"<<YEL<<" lastname"<<RESET<<" : "<<GRN;
  getline(cin,lastname,'\n');
  cout<<RESET;

  cout<<"Please input the"<<YEL<<" address"<<RESET<<" : "<<GRN;
  getline(cin,address,'\n');
  cout<<RESET;

  cout<<"Please input the"<<YEL<<" S.S.N."<<RESET<<" : "<<GRN;
  getline(cin,ssn,'\n');
  cout<<RESET;

  cout<<"Please set the "<<YEL<<"interest rate"<<RESET<< " in" ;
  cout<<" Correct format"<<YEL<<"(e.g. 1.5, 2.7, 5.3)"<<RESET<<" : "<<GRN;
  cin>>rate;
  cin.ignore();
  cout<<RESET;
  CheckNum(rate);

  cout<<"Please input the"<<YEL<<" balance"<<RESET<<" : "<<GRN;
  cin>>bal;
  cin.ignore();
  cout<<RESET;
  CheckNum(bal);
 
  Person temp(bal,rate,firstname,lastname,address,ssn);
  ListPtr->push_back(temp);

}

void PrintSum()
{ 
  cout<<"\nThere are "<<GRN<<ListPtr->size()<<RESET<<" accounts in the system."<<endl;
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"---------------------------------\n";
  cout<<" No.  "<<setw(20)<<"Name"<<endl;
  cout<<"---------------------------------\n";
  //cout<<List[0].getBala();
  for(int i=0;i<vecSize;++i)
  {
        name=List[i].getFirst()+"."+List[i].getLast();
        cout<<" "<<i+1<<"    "<<setw(20)<<name<<endl;
  }
  cout<<"---------------------------------\n";
  cout<<RESET;
}

//Printing out accounts
void PrintAll()
{
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"\n-----------------------------------------------";
  cout<<"-------------------------------------------------\n";
  cout<<" No.  "<<setw(18)<<"Name"<<setw(15)<<"Interest Rate";
  cout<<setw(18)<<"Checking Account"<<setw(14)<<"S.S.N."<<"Address"<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------\n";
  //cout<<List[0].getBala();
  for(int i=0;i<vecSize;++i)
  {
        name=List[i].getFirst()+"."+List[i].getLast();
        cout<<" "<<i+1<<"    "<<setw(22)<<name<<setw(13);
        cout<<List[i].getRate()<<setw(16)<<List[i].getToBa();
        cout<<setw(14)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  }
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------";
  cout<<RESET;
}

//Change string to int
int StrtoI(string input2)
{
  int i=0;
  stringstream s;
  s<<input2;
  s>>i;
  return i;
}

//Print one account out
void PrintOne(string input2)
{
    int i=0;
    i=StrtoI(input2)-1;
  string name;
  cout.setf(ios::left);
  cout<<GRN<<"\n-----------------------------------------------";
  cout<<"-------------------------------------------------\n";
  cout<<" No.  "<<setw(18)<<"Name"<<setw(15)<<"Interest Rate";
  cout<<setw(18)<<"Checking Account"<<setw(14)<<"S.S.N"<<"Address"<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------\n";
  name=List[i].getFirst()+"."+List[i].getLast();
  cout<<" "<<i+1<<"    "<<setw(22)<<name<<setw(13);
  cout<<List[i].getRate()<<setw(16)<<List[i].getToBa();
  cout<<setw(14)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------";
  cout<<RESET;
}

void PrintF(string& input2)
{
    if(input2== "a"||input2== "A")
    {
        PrintAll();
    }
    else if(isdigit(input2[0]))
    {
        if(StrtoI(input2)<=0||StrtoI(input2)>(ListPtr->size()+1))
        {
            cout<<RED<<"Invalid input, please re-input the number : "<<GRN;
            cin>>input2;
            cout<<RESET;
            PrintF(input2);
        }
        else
            PrintOne(input2);
    }
    while(input2!="a"&&input2!="A"&&input2!="B"&&input2!="b"&&!isdigit(input2[0]))
    {
        cout<<RED<<"Invalid input, please re-input : "<<GRN;
        cin>>input2;
        cout<<RESET;
        PrintF(input2);
    }
}


void remind(string& input1)
{
    while(input1!="c"&&input1!="C"&&input1!="b"&&input1!="B")
    {
        cout<<RED"\nInvalid input,please re-input."<<RESET;
        cout<<"\nThere are "<<GRN<<ListPtr->size()<<RESET<<" accounts in the system."<<endl;
        cout<<"Input"<<YEL<<" 'c'"<<RESET<<"To create an account "<<endl;
        cout<<"Input"<<YEL<<" 'b'"<<RESET<<"To back to the main menu"<<GRN<<endl;
        cout<<GRN;
        cin>>input1;
        cin.ignore();
        cout<<RESET;
        remind(input1);
    }
}
