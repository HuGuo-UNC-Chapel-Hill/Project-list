#include "Account.h"
#include "Person.h"


vector<Person> List;

//displaying the welcome menu
void welcome(string& choice);

//showing the choice menu
void Choice(string& choice);

//check the string of choice
void CheckChoice(string& choice);

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

//check the correct input
void remindF1(string& input);

//Decide printing of accounts
void remindF2(string& input2);

//Decide printing of accounts
void remindF3(string& input3,string& choice,int& selected);

void PrintF4(int selected);

void CheckNum(float& num);

//add 3 instances to the class
void AddAccounts();

int main()
{
  string choice,input1,input2,input3,input4;
  int selected=0;

  AddAccounts();

  welcome(choice);
  

  do
  {
     if(choice=="1")
     {  
         cin.ignore();
         do
         {
            if(input1=="c"||input1=="C")
                Create();
            PrintSum();
            cout<<"\nInput"<<YEL<<" 'c'"<<RESET<<"To create an account "<<endl;
            cout<<"Input"<<YEL<<" 'b'"<<RESET<<"To back to the main menu"<<GRN<<endl;
            cin>>input1;
            cin.ignore();
            cout<<RESET;
            remindF1(input1);
         }while(input1!="b"&&input1!="B");

         Choice(choice);
         //cin.ignore();
     }

     if(choice=="2")
     {
       cin.ignore();
       if( List.size()==0)
       {
          cout<<RED<<"\nNo account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
       else
       {
          PrintSum();
          do{
                if(List.size()==1)
                {
                    cout<<"\nInput "<<YEL<<"1"<<RESET<<" to print out details of that account."<<endl;
                }
                else if(List.size()>1)
                {
                    cout<<"\nInput "<<YEL<<"1-"<<List.size()<<RESET;
                    cout<<" to print out details of "<<YEL<<"one account."<<RESET<<endl;
                }
                cout<<"Input "<<YEL<<"'a'"<<RESET<<" to print out details of "<<YEL<<"all account."<<RESET<<endl;
                cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<GRN<<endl;
                cin>>input2;
                cin.ignore();
                cout<<RESET;
                remindF2(input2);
            }while(input2!="b"&&input2!= "B");
        }

       Choice(choice);
     }

    if(choice=="3")
    {  
        cin.ignore();
        if( List.size()==0)
       {
          cout<<RED<<"\nNo account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
       else
       {
          PrintSum();
          if(List.size()==1)
          {
              cout<<"\nInput "<<YEL<<"1"<<RESET<<" to choose the account."<<endl;
          }
          else if(List.size()>1)
          {
              cout<<"\nInput "<<YEL<<"1-"<<List.size()<<RESET;
              cout<<" to  choose the account ."<<endl;
          }
          cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<GRN<<endl;
          cin>>input3;
          cin.ignore();
          cout<<RESET;
          remindF3(input3,choice,selected);
       }
    }
    
    if(choice=="4")
    {
      cin.ignore();
      
      float deposit=0;
      
      if(selected<=0||selected>List.size())
      {
        cout<<RED<<"\nPlease select one account at first."<<RESET;
        Choice(choice);
      }
      else
      { 
        do
        { 
          if(input4=="p"||input4=="P")
          {
            cout<<"Please input the amount of money to deposit : "<<GRN;
            cin>>deposit;
            cin.ignore();
            cout<<RESET;
            CheckNum(deposit);
            List[selected-1].Deposit(deposit);
            //PrintF4(selected);
          }      
          cout<<"\nYou chose the account of ";
          cout<<GRN<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".";
          PrintF4(selected);
          cout<<"Input "<<YEL<<"'p'"<<RESET<<" to "<<YEL<<"deposit "<<RESET<<"money to the account."<<endl;
          cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<GRN<<endl;
          cin>>input4;
          cin.ignore();
          cout<<RESET;
        }while(input4!="b"||input4!="b");
      } 
      Choice(choice);
    }
    

     else if(choice=="6")
     {  
         cin.ignore();
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
  CheckChoice(choice);
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
  CheckChoice(choice);
}

void CheckChoice(string& choice)
{  
  int i=StrtoI(choice);
  if(isdigit(choice[0]))
  {
    if(i>6||i<=0)
    {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
  }
}

void AddAccounts()
{
  Person temp(1000,1.1,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview","224-46-0407");
  List.push_back(temp);
  Person temp1(2200,1.2,"Marvin", "Jerod","197 Chyna Radial Suite 370 East Sadieland","306-42-6992");
  List.push_back(temp1);
  Person temp2(3400,3.2,"Rogahn", "Georgette","9480 Juliana Village Suite 152 Wehnerbury","649-05-1129");
  List.push_back(temp2);
}

void CheckNum(float& num)
{
  while(num<0)
  {
    cout<<RED<<"Invalid input, please re-input : ";
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
  List.push_back(temp);

}

void PrintSum()
{
  cout<<"\nThere are "<<GRN<<List.size()<<RESET<<" accounts in the system."<<endl;
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"---------------------------------\n";
  cout<<" No.  "<<setw(20)<<"Name"<<"Balance"<<endl;
  cout<<"---------------------------------\n";
  //cout<<List[0].getBala();
  for(int i=0;i<vecSize;++i)
  {
        name=List[i].getFirst()+"."+List[i].getLast();
        cout<<" "<<i+1<<"    "<<setw(20)<<name<<List[i].getBala()<<endl;
  }
  cout<<"---------------------------------";
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
        cout<<" "<<i+1<<"    "<<setw(22)<<name<<setw(15);
        cout<<List[i].getRate()<<setw(14)<<List[i].getToBa();
        cout<<setw(14)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  }
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------";
  cout<<RESET;
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
  cout<<" "<<i+1<<"    "<<setw(22)<<name<<setw(15);
  cout<<List[i].getRate()<<setw(14)<<List[i].getToBa();
  cout<<setw(14)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  cout<<"--------------------------------------------------";
  cout<<"----------------------------------------------";
  cout<<RESET;
}

//Print one account out
void PrintF4(int selected)
{
    int i=0;
    i=selected-1;
  string name;
  cout.setf(ios::left);
  cout<<GRN<<"\n-------------------------------------------------\n";
  
  cout<<" No.  "<<setw(18)<<"Name"<<setw(18)<<"Interest Rate"<<"Balance";
  cout<<GRN<<"\n-------------------------------------------------\n";
  name=List[i].getFirst()+"."+List[i].getLast();
  cout<<" "<<i+1<<"    "<<setw(22)<<name<<setw(15);
  cout<<List[i].getRate()<<List[i].getBala();
  //cout<<setw(14)<<List[i].getSsn()<<List[i].getAdd()<<endl;
  cout<<GRN<<"\n-------------------------------------------------\n";
  cout<<RESET;
}

void remindF1(string& input1)
{
    while(input1!="c"&&input1!="C"&&input1!="b"&&input1!="B")
    {
        cout<<RED"Invalid input,please re-input : "<<RESET;
        cout<<GRN;
        cin>>input1;
        cin.ignore();
        cout<<RESET;
        remindF1(input1);
    }
}

void remindF2(string& input2)
{
    if(input2== "a"||input2== "A")
    {
        PrintAll();
    }
    else if(isdigit(input2[0]))
    {
        if(StrtoI(input2)<=0||StrtoI(input2)>List.size())
        {
            cout<<RED<<"Invalid input, please re-input the number : "<<GRN;
            cin>>input2;
            cin.ignore();
            cout<<RESET;
            remindF2(input2);
        }
        else
            PrintOne(input2);
    }
    while(input2!="a"&&input2!="A"&&input2!="B"&&input2!="b"&&!isdigit(input2[0]))
    {
        cout<<RED<<"Invalid input, please re-input : "<<GRN;
        cin>>input2;
        cin.ignore();
        cout<<RESET;
        remindF2(input2);
    }
}

void remindF3(string& input3,string& choice,int& selected)
{
    if(input3=="b"||input3=="B")
    {
      Choice(choice);
    }
    if(isdigit(input3[0]))
    {
        int i=StrtoI(input3);
        if(i<=0||i>List.size())
        {
            cout<<RED<<"Invalid input, please re-input the number : "<<GRN;
            cin>>input3;
            cin.ignore();
            cout<<RESET;
            remindF3(input3,choice,selected);
        }
        else
        {  
            selected=i;
            cout<<"\nYou chose the account of ";
            cout<<GRN<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".";
            PrintOne(input3);
            Choice(choice);
        }
    }
    while(input3!="B"&&input3!="b"&&!isdigit(input3[0]))
    {
        cout<<RED<<"Invalid input, please re-input : "<<GRN;
        cin>>input3;
        cin.ignore();
        cout<<RESET;
        remindF3(input3,choice,selected);
    }
}

