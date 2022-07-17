#include "Account.h"
#include "Person.h"


vector<Person> List;

//displaying the welcome menu
void welcome(string& choice);

//showing the choice menu
void Choice(string& choice);

//checking the inputing of choice
void CheckChoice(string& choice);

//logic chain for choice1
void Remind1(string& input1);

//Creating the account
void Create();

//Changing string to int
int StrtoI(string input);

//Changing string to float
float StrtoF(string input);

//Checking the num is bigger than 0 or not
void CheckNum(float& num,string& str);

//printing out summary for all accounts
void PrintSum();

//Printing out details for all accounts
void PrintAll();

//Printing details of one account out
void PrintOne(int selected);

//prompting for choice2
void Rimind2(string& input2);

//Decide to print which accounts
void Print2(string input2);

//prompting for choice3
void Remind3(string& input3);

//Selecting accounts
void Select3(string& input3,string& choice,int& selected);

void SelectOne(int selected);

void Deposit(string input4,int selected);

void Withdrawl(string input5,int selected);

//add 3 instances to the class
void AddAccounts();

int main()
{
  std::cout << std::fixed;
  std::cout << std::setprecision(2);

  string choice,input1,input2,input3,input4,input5;
  int selected=0;
  
  //debug
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
            Remind1(input1);
         }while(input1!="b"&&input1!="B");

         Choice(choice);
     }

     if(choice=="2")
     {
       cin.ignore();
       PrintSum();
        do
        {
            Rimind2(input2);
            Print2(input2);
        }while(input2!="b"&&input2!= "B");

       Choice(choice);
     }

    if(choice=="3")
    {
        cin.ignore();
        PrintSum();
        Remind3(input3);
        Select3(input3,choice,selected);
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
          cout<<"\nYou selected the account of ";
          cout<<YEL<<List[selected-1].getFirst()<<"."<<List[selected-1].getLast()<<RESET<<".";
          SelectOne(selected);
        do
        {
          cout<<"\nInput the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"deposit."<<RESET;
          cout<<"\nInput "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
          cin>>input4;
          cin.ignore();
          cout<<RESET;
          if(isdigit(input4[0]))
          {
            Deposit(input4,selected);
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
          cout<<"\nYou selected the account of ";
          cout<<YEL<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".";
          SelectOne(selected);
          do
          {
            cout<<"\nInput the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"withdrawal."<<RESET<<endl;
            cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
            cin>>input5;
            cin.ignore();
            cout<<RESET;
            if(isdigit(input5[0]))
            {
              Withdrawl(input5,selected);
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
  
  if(isdigit(choice[0]))
  {
    int i=StrtoI(choice);
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
  Person temp(1230.20,0.01,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview","224-46-0407");
  List.push_back(temp);
  Person temp1(2900.12,0.02,"Marvin", "Jerod","197 Chyna Radial Suite 370","306-42-6992");
  List.push_back(temp1);
  Person temp2(3590.01,0.03,"Rogahn", "Georgette","9480 Juliana Village Suite 152","649-05-1129");
  List.push_back(temp2);
}

void CheckNum(float& num,string& str)
{  
  if(isdigit(str[0])||isdigit(str[1]))
  {
    float i=StrtoF(str);
    if(i<0)
    {
      cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      cin>>str;
      cin.ignore();
      cout<<RESET;
      CheckNum(num,str);
    }
    else
    {
      num=i;
    }
  }
  else
  {
    cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      cin>>str;
      cin.ignore();
      cout<<RESET;
      CheckNum(num,str);
  }
}


//Creating the account
void Create()
{
  float bal=0,rate=0;
  string firstname="",lastname="",address="",ssn="",strbal="", strate="";

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
  getline(cin,strate,'\n');
  cout<<RESET;
  CheckNum(rate,strate);
  //set the rate to correct demcimal place
  rate*=0.01;

  cout<<"Please input the"<<YEL<<" balance"<<RESET<<" : "<<GRN;
  getline(cin,strbal,'\n');
  cout<<RESET;
  CheckNum(bal,strbal);
  //set the total balance
  bal=bal+bal*rate;

  Person temp(bal,rate,firstname,lastname,address,ssn);
  List.push_back(temp);
  cout<<"\nYou created the checking account of "<<YEL<<firstname<<"."<<lastname<<" ."<<RESET;
  PrintOne(List.size());
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
int StrtoI(string input)
{
  int i=0;
  stringstream s;
  s<<input;
  s>>i;
  return i;
}

float StrtoF(string input)
{
  float i=0;
  stringstream s;
  s<<input;
  s>>i;
  return i;
}


//Printing out accounts
void PrintAll()
{  
  string name;
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  for(int i=0;i<vecSize;++i)
  {
    name=List[i].getFirst()+"."+List[i].getLast();
    cout<<" No."<<i+1<<"\n";
    cout<<" Name : "<<setw(18)<<name<<"Checking Account : "<<List[i].getToBa()<<endl;
    cout<<setw(29)<<" "<<"Interest Rate : "<<List[i].getRate()<<endl;
    cout<<setw(37)<<" "<<"S.S.N : "<<List[i].getSsn()<<endl;
    cout<<setw(35)<<" "<<"Address : "<<List[i].getAdd()<<endl;
  }
  cout<<"------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}

void PrintOne(int selected)
{
  int i=0;
  i=selected-1;
  string name;
  name=List[i].getFirst()+"."+List[i].getLast();
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  cout<<" No."<<i+1<<"\n";
  cout<<" Name : "<<setw(18)<<name<<"Checking Account : "<<List[i].getToBa()<<endl;
  cout<<setw(29)<<" "<<"Interest Rate : "<<List[i].getRate()<<endl;
  cout<<setw(37)<<" "<<"S.S.N : "<<List[i].getSsn()<<endl;
  cout<<setw(35)<<" "<<"Address : "<<List[i].getAdd()<<endl;
  cout<<"------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}


void Rimind2(string& input2)
{
        if( List.size()==0)
       {
          cout<<RED<<"\nNo account was created. Please create at least one account at first.\n";
          cout<<RESET;
       }
    
        else if(List.size()==1)
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
    
}

void Print2(string input2)
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

void Remind3(string& input3)
{
    if( List.size()==0)
    {
        cout<<RED<<"\nNo account was created. Please create at least one account at first.\n";
        cout<<RESET;
    }
    else if(List.size()==1)
    {
        cout<<"\nInput "<<YEL<<"1"<<RESET<<" to choose the account."<<endl;
    }
    else if(List.size()>1)
    {
        cout<<"\nInput "<<YEL<<"1-"<<List.size()<<RESET;
        cout<<" to  choose the account ."<<endl;
    }
    cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the main menu."<<YEL<<endl;
    cin>>input3;
    cin.ignore();
    cout<<RESET;
}

void SelectOne(int selected)
{
  int i=0;
  i=selected-1;
  string name;
  name=List[i].getFirst()+"."+List[i].getLast();
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  cout<<" No."<<i+1<<"\n";
  cout<<" Name : "<<setw(18)<<name<<"Checking Account : "<<List[i].getToBa();;
  cout<<"\n------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}

void Select3(string& input3,string& choice,int& selected)
{
    if(isdigit(input3[0]))
    {
        int i=StrtoI(input3);
        if(i<=0||i>List.size())
        {
            cout<<RED<<"Invalid input, please re-input the number ."<<YEL;
            Remind3(input3);
            Select3(input3,choice,selected);
        }
        else
        {
            selected=i;
            cout<<"\nYou selected the account of ";
            cout<<YEL<<List[selected-1].getFirst()+"."+List[selected-1].getLast()<<RESET<<".";
            SelectOne(selected);
            Choice(choice);
        }
    }
    else if(input3=="b"||input3=="B")
    {
        Choice(choice);
    }
    else if(input3!="B"&&input3!="b")
    {
        cout<<RED<<"Invalid input, please re-input : "<<YEL;
        Remind3(input3);
        Select3(input3,choice,selected);
    }
}

void Deposit(string input4,int selected)
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
    cout<<YEL<<List[selected-1].getFirst()<<"."<<List[selected-1].getLast()<<RESET<<".";
    SelectOne(selected);
  }
}


void Withdrawl(string input5,int selected)
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
      cout<<YEL<<List[selected-1].getFirst()<<"."<<List[selected-1].getLast()<<RESET<<".";
      SelectOne(selected);
    }
}

void Remind1(string& input1)
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
}
