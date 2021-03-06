#include "Account.h"
#include "Person.h"


vector<Person> List;

//displaying the welcome menu
void welcome(string& choice);

//showing the choice menu
void Choice(string& choice);

//check the inputing of choice
void CheckChoice(string& choice);

//Creating the account
void Create();

//Change string to int
int StrtoI(string input);

//printing out summary for all accounts
void PrintSum();

//Printing out details for all accounts
void PrintAll();

//Print details of one account out 
void PrintOne(int selected);

//Decide printing of accounts
void Print(string input2);

//Select accounts
void remindF3(string& input3,string& choice,int& selected);

void deposit(string input4,int selected);

void withdrawl(string input5,int selected);

void CheckNum(float& num);

//add 3 instances to the class
void AddAccounts();

int main()
{  
  std::cout << std::fixed;
  std::cout << std::setprecision(2); 
  
  string choice,input1,input2,input3,input4,input5;
  int num2=0,selected=0;

  AddAccounts();

  welcome(choice);
  
  do
  {
     if(choice=="1")
     {  
         cin.ignore();
         PrintSum();
         do
         {
            cout<<"\nInput"<<YEL<<" 'c'"<<RESET<<"To create an account "<<endl;
            cout<<"Input"<<YEL<<" 'b'"<<RESET<<"To back to the main menu"<<YEL<<endl;
            cin>>input1;
            cin.ignore();
            cout<<RESET;
            if(input1=="c"||input1=="C")
                Create();
            else if(input1!="b"&&input1!="B")
            {
                cout<<RED"Invalid input,please re-input."<<RESET;
            }    

         }while(input1!="b"&&input1!="B");

         Choice(choice);
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
                cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<YEL<<endl;
                cin>>input2;
                cin.ignore();
                cout<<RESET;
                Print(input2);
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
       }
          cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<YEL<<endl;
          cin>>input3;
          cin.ignore();
          cout<<RESET;
          if(input3=="b"||input3=="B")
          {
            Choice(choice);
          }
          remindF3(input3,choice,selected);
       
    }
    
    if(choice=="4")
    {
      cin.ignore();
      
      if(selected<=0)
      {
        cout<<RED<<"\nPlease select one account at first."<<RESET;
      }
      else
      { 
          cout<<"\nYou chose the account of ";
          cout<<YEL<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".\n";
          PrintOne(selected);
        do
        { 
          cout<<"Input the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"deposit."<<RESET<<endl;
          cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
          cin>>input4;
          cin.ignore();
          cout<<RESET;         
          if(isdigit(input4[0]))
          {  
            deposit(input4,selected);
          }
          else if(input4!="b"&&input4!="B")
          {
            cout<<RED"Invalid input,please re-input."<<RESET<<endl;
          }      
        }while(input4!="b"&&input4!="B");
      } 
      Choice(choice);
    }
    
    if(choice=="5")
    {
      cin.ignore();
      
      if(selected<=0)
      {
        cout<<RED<<"\nPlease select one account at first."<<RESET;
      }
      else
      { 
          cout<<"\nYou chose the account of ";
          cout<<YEL<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".\n";
          PrintOne(selected);
          do
          {      
            cout<<"Input the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"withdrawal."<<RESET<<endl;
            cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
            cin>>input5;
            cin.ignore();
            cout<<RESET;
            if(isdigit(input5[0]))
            {  
              withdrawl(input5,selected);
            }
            else if(input5!="b"&&input5!="B")
            {
                cout<<RED"Invalid input,please re-input."<<RESET<<endl;
            }
          }while(input5!="b"&&input5!="B");
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
  Person temp(1000,0.01,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview","224-46-0407");
  List.push_back(temp);
  Person temp1(2200,0.02,"Marvin", "Jerod","197 Chyna Radial Suite 370 East Sadieland","306-42-6992");
  List.push_back(temp1);
  Person temp2(3400,0.03,"Rogahn", "Georgette","9480 Juliana Village Suite 152 Wehnerbury","649-05-1129");
  List.push_back(temp2);
}

void CheckNum(float& num)
{
  while(num<0)
  {
    cout<<RED<<"Invalid input, please re-input : ";
    cin>>num;
    cin.ignore();
    cout<<RESET;
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
  cout<<" Correct format"<<YEL<<"(e.g. 5, 2.7, 3)"<<RESET<<" : "<<GRN;
  cin>>rate;
  cin.ignore();
  cout<<RESET;
  CheckNum(rate);
  rate*=0.01;

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
  string name;
  cout<<"\nThere are "<<GRN<<List.size()<<RESET<<" accounts in the system.";
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"\n-------------------------";
  cout<<"-------------------\n";  
  cout<<" No.  "<<setw(19)<<"Name"<<"Checking Account";
  cout<<GRN<<"\n-------------------------";
  cout<<"-------------------\n";  
  for(int i=0;i<vecSize;++i)
  {  
    name=List[i].getFirst()+"."+List[i].getLast();      
    cout<<" "<<i+1<<"    "<<setw(22)<<name<<List[i].getToBa()<<endl;
  }
  cout<<GRN<<"-------------------------";
  cout<<"-------------------\n";  
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
  cout<<GRN<<"\n----------------------------------";
  cout<<"----------------------------------\n";  
  cout<<" No.  "<<setw(19)<<"Name"<<setw(10)<<"Balance"<<setw(16);
  cout<<"Interest Rate"<<"Checking Account";
  cout<<"\n----------------------------------";
  cout<<"----------------------------------\n";  
  
  for(int i=0;i<vecSize;++i)
  {
    name=List[i].getFirst()+"."+List[i].getLast();
    cout<<" "<<i+1<<"    "<<setw(19)<<name<<setw(10)<<List[i].getBala();
    cout<<setw(16)<<List[i].getRate()<<setw(20)<<List[i].getToBa();
    cout<<"S.S.N : "<<List[i].getSsn()<<endl;
    cout<<setw(69)<<" "<<"Address : "<<List[i].getAdd()<<endl;
  }
  cout<<"----------------------------------";
  cout<<"----------------------------------\n";
  cout<<RESET;
}

void PrintOne(int selected)
{
  int i=0;
  i=selected-1;
  string name;
  name=List[i].getFirst()+"."+List[i].getLast();
  cout.setf(ios::left);
  cout<<GRN<<"----------------------------------";
  cout<<"----------------------------------\n";  
  cout<<" No.  "<<setw(19)<<"Name"<<setw(10)<<"Balance"<<setw(16);
  cout<<"Interest Rate"<<"Checking Account";
  cout<<"\n----------------------------------";
  cout<<"----------------------------------\n";  
  cout<<" "<<i+1<<"    "<<setw(19)<<name<<setw(10)<<List[i].getBala();
  cout<<setw(16)<<List[i].getRate()<<setw(20)<<List[i].getToBa();
  cout<<"S.S.N : "<<List[i].getSsn()<<endl;  
  cout<<setw(69)<<" "<<"Address : "<<List[i].getAdd()<<endl;
  cout<<"----------------------------------";
  cout<<"----------------------------------\n";
  cout<<RESET;
}

void Print(string input2)
{
    if(input2== "a"||input2== "A")
    {
        PrintAll();
    }
    else if(isdigit(input2[0]))
    {    
        int num=StrtoI(input2);
        if(num<=0||num>List.size())
        {
            cout<<RED<<"Invalid input, please re-input the number.";
        }
        else{PrintOne(num);}
    }
    else if(input2!="B"&&input2!="b")
    {
      cout<<RED<<"Invalid input, please re-input.";
    }
}

void remindF3(string& input3,string& choice,int& selected)
{
    if(isdigit(input3[0]))
    {
        int i=StrtoI(input3);
        if(i<=0||i>List.size())
        {
            cout<<RED<<"Invalid input, please re-input the number : "<<YEL;
            cin>>input3;
            cin.ignore();
            cout<<RESET;
            remindF3(input3,choice,selected);
        }
        else
        {  
             selected=i;
            cout<<"\nYou chose the account of ";
            cout<<YEL<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".\n";
            PrintOne(selected);
            Choice(choice);
        }
    }
    else(input3!="B"&&input3!="b")
    {
        cout<<RED<<"Invalid input, please re-input : "<<YEL;
        cin>>input3;
        cin.ignore();
        cout<<RESET;
        remindF3(input3,choice,selected);
    }
}

void deposit(string input4,int selected)
{  
  float x=0;
  x=x=StrtoI(input4);
  if(x<0)
  {
    cout<<RED<<"Invalid input, please re-input.\n"<<RESET;
  }
  else  
  {
    List[selected-1].Deposit(x);
    cout<<"\nYou deposited "<<GRN<<x<<RESET<<" to the account of ";
    cout<<YEL<<List[selected-1].getFirst()<<"."<<List[selected-1].getLast()<<RESET<<".\n";
    PrintOne(selected);
  }
}


void withdrawl(string input5,int selected)
{  
    float x=0;
    x=StrtoI(input5);
    if(x<0||x>List[selected-1].getToBa())
    {
      cout<<RED<<"Invalid input, please re-input.\n"<<RESET;
    }
    else  
    {
      List[selected-1].Withdrawal(x);
      cout<<"\nYou withdrawaled "<<GRN<<x<<RESET<<" from the account of ";
      cout<<YEL<<List[selected-1].getFirst()<<"."<<List[selected-1].getLast()<<RESET<<".\n";
      PrintOne(selected);
    }
}

