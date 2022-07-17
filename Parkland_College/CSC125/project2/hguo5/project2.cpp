#include "Account.h"
#include "Person.h"

//declaration of the type of the Person(Account) class for the vector
vector<Person> List;

//displaying the welcome menu
void welcome(string& choice);

//showing the choice menu
void Choice(string& choice);

//checking the inputing of choice
void CheckChoice(string& choice);

//Changing string to int
int StrtoI(string input);

//Changing string to float
float StrtoF(string input);

//Creating the account for choice 1
void Create();

//Checking the num is bigger than 0 or not for choice 1
void CheckNum(float& num,string& str);

//printing out summary for all accounts for choice 2
void PrintSum();

//Printing out details for all accounts for choice 2
void PrintAll();

//Prompting for choice 2
void Rimind2(string& input2);

//Prompting for choice 3
void Remind3(string& input3);

//Select the account for choice 3,4,5
void SelectOne(int selected);

//Deposit the money of the account for choice 4
void Deposit(string input4,int selected);

//Withdraw the money of the account for choice 5
void Withdrawl(string input5,int selected);

//add 3 accounts to the class
void Add3Accounts();

//main program
int main()
{  
  //set the decimal place
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  
  //declaration for variables
  string choice,input1,input2,input3,input4,input5;
  int selected=0;

  //debugging
  //add 3 accounts to the class
  //Add3Accounts();
  
  //welcome menu
  welcome(choice);
  
  //loop for the choice menu
  do
  {  
    //choice 1
     if(choice=="1")
     {
         //print the summary of the accounts
         PrintSum();
         
         //loop for choice 1
         do
         {    
             //prompting
             cout<<"\nInput"<<YEL<<" 'c'"<<RESET<<"To create an account "<<endl;
             cout<<"Input"<<YEL<<" 'b'"<<RESET<<"To back to the main menu"<<YEL<<endl;
             
             //input
             getline(cin,input1);
             cout<<RESET;
             
             //condition to create a account
             if(input1=="c"||input1=="C")
                Create();
                
             //condition for the wrong input string
             else if(input1!="b"&&input1!="B")
             {
                cout<<RED"Invalid input,please re-input."<<RESET;
             }
             
          //condition to end the loop   
         }while(input1!="b"&&input1!="B");
          
          //choice menu
         Choice(choice);
     }
      
      //choice 2
     if(choice=="2")
     {
         //print out the summary for all accounts
        PrintSum();
        
        //loop for choice 2
        do
        {  
            //prompting for choice2
            Rimind2(input2);
            
            //condition to print all details of all account
            if(input2== "a"||input2== "A")
            {
                PrintAll();
            }
            
            //condition for the input string is number
            else if(isdigit(input2[0])||isdigit(input2[1]))
            {
                //transform the input string to integer
                int num=StrtoI(input2);
                
                //condition for wrong input number for exsiting accounts
                if(num<=0||num>List.size())
                {
                    cout<<RED<<"Invalid input, please re-input the number.";
                }
                
                //condition for the right number of potential accounts
                else
                {
                    
                    cout<<"\nYou printed details for the account of "<<YEL<<List[num-1].FullName()<<RESET<<".";
                    
                    //print out details of the selected account
                    List[num-1].perPrint(num-1);
                }
            }
            
            //condition for the wrong input string
            else if(input2!="B"&&input2!="b")
            {
                cout<<RED<<"Invalid input, please re-input.";
            }
            
         //condition to end the loop   
        }while(input2!="b"&&input2!= "B");
        
        //choice menu
       Choice(choice);
     }
    
    //choice 3
    if(choice=="3")
    {  
        //print out the summary for all accounts
        PrintSum();
        
        //loop for choice 3
        do
        {  
            //prompting for choice 3
            Remind3(input3);
            
            //condition for the input string is number
            if(isdigit(input3[0])||isdigit(input3[1]))
            {
                //transform the input string to integer
                int i=StrtoI(input3);
                
                //condition for wrong input number for exsiting accounts
                if(i<=0||i>List.size())
                {
                    cout<<RED<<"Invalid input, please re-input the number ."<<RESET;
                }
                
                //condition for the right number of potential accounts
                else
                {    
                    //set selected to the right number
                    selected=i;
                    
                    //PrintSum();
                    
                    cout<<"\nYou selected the account of ";
                    cout<<YEL<<List[i-1].FullName()<<RESET<<".";
                    
                    //print out the selected account
                    SelectOne(selected);
                    
                    //continue select or end the loop
                    Remind3(input3);
                }
            }
            
            //condition for the wrong input string
            else if(input3!="B"&&input3!="b")
            {
                cout<<RED<<"Invalid input, please re-input ."<<RESET;
            }
            
         //condition to end the loop   
        }while((input3!="B"&&input3!="b"));
        
        //choice menu
        Choice(choice);
    }
    
    //choice 4
    if(choice=="4")
    {  
      //condition for no account was created
      if(selected<=0)
      {  
              cout<<RED<<"\nNo account was created.";
              cout<<" Please create at least one account at first. "<<RESET;      
      }
      
      //condition for the selected account 
      else
      { 
          //prompting for the selected account   
          cout<<"\nYou selected the account of ";
          cout<<YEL<<List[selected-1].FullName()<<RESET<<".";
          SelectOne(selected);
          
        //loop for depositing       
        do
        {  
            //prompting for depositing
            cout<<"\nInput the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"deposit."<<RESET;
            cout<<"\nInput "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
            
            //input for deposting
            getline(cin,input4);
            cout<<RESET;         
           
          //confition for the input string is number  
          if(isdigit(input4[0])||isdigit(input4[1]))
          {  
            Deposit(input4,selected);
          }
          
          //condition for the wrong input string
          else if(input4!="b"&&input4!="B")
          {
            cout<<RED"Invalid input,please re-input."<<RESET<<endl;
          }
          
          //condition to end the loop
        }while(input4!="b"&&input4!="B");
      }
      
      //choice menu
      Choice(choice);
    }
    
    //choice 5
    if(choice=="5")
    {
      ////condition for no account was created
      if(selected<=0)
      {
         cout<<RED<<"\nNo account was created.";
         cout<<" Please create at least one account at first. "<<RESET;  
      }
      
      //condition for the selected account 
      else
      {    
          //prompting for the selected account
          cout<<"\nYou selected the account of ";
          cout<<YEL<<List[selected-1].FullName()<<RESET<<".";
          SelectOne(selected);
          
          //loop for withdrawing
          do
          {
            //prompting for withdrawing
            cout<<"\nInput the "<<YEL<<"amount"<<RESET<<" of money you want to "<<YEL<<"withdrawal."<<RESET<<endl;
            cout<<"Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu."<<RESET<<YEL<<endl;
            
            //input for withdrawing
            getline(cin,input5);
            cout<<RESET;
            
            //confition for the input string is number 
            if(isdigit(input5[0])||isdigit(input5[1]))
            {
              Withdrawl(input5,selected);
            }
            
            //condition for the wrong input string
            else if(input5!="b"&&input5!="B")
            {
                cout<<RED"Invalid input,please re-input."<<RESET<<endl;
            }
            
            //condition to end the loop
          }while(input5!="b"&&input5!="B");
      }
      
      //choice menu
      Choice(choice);
    }

      //choice 6
     else if(choice=="6")
     {       
         //quit the program
         exit (-1);
     }
    
    //condition to end the loop
   }while(choice!="6"||choice!="6");


  return 0;
}

//displaying the welcome menu
void welcome(string& choice)
{
  cout<<GRN<<"\n----------------------------------------\n";
  cout<<YEL<<"Welcome to the First National Bank\n";
  cout<<"of Parkland - Account transaction system\n";
  cout<<GRN<<"----------------------------------------\n"<<RESET;
  cout<<"Enter any of the following commands:\n";
  cout.setf(ios::left);
  cout<<setw(8)<<" "<<"1) Create account\n";
  cout<<setw(8)<<" "<<"2) Print account\n";
  cout<<setw(8)<<" "<<"3) Select account\n";
  cout<<setw(8)<<" "<<"4) Deposit\n";
  cout<<setw(8)<<" "<<"5) Withdrawal\n";
  cout<<setw(8)<<" "<<"6) Quit\n";
  getline(cin,choice);
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
  getline(cin,choice);
  CheckChoice(choice);
}

//checking the inputing of choice
void CheckChoice(string& choice)
{
  if(isdigit(choice[0]))
  {
    int i=StrtoI(choice);
    if(i>6||i<=0)
    {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
      CheckChoice(choice);
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
      CheckChoice(choice);
  }
}

//Change string to int
int StrtoI(string input)
{
  int i=0;
  stringstream temp;
  temp<<input;
  temp>>i;
  return i;
}

//Change string to float
float StrtoF(string input)
{
  float i=0.0;
  stringstream temp;
  temp<<input;
  temp>>i;
  return i;
}

//Creating the account for choice 1
void Create()
{
  float bal=0.0,rate=0.0;
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

  cout<<"Please set the "<<YEL<<"interest rate "<<RESET<<" : "<<GRN;
  getline(cin,strate,'\n');
  cout<<RESET;
  
  //check the rate string and transfrom the string to the float
  CheckNum(rate,strate);

  cout<<"Please input the"<<YEL<<" balance"<<RESET<<" : "<<GRN;
  getline(cin,strbal,'\n');
  cout<<RESET;
  
  //check the balance string and transfrom the string to the float
  CheckNum(bal,strbal);

  //constructor
  Person temp(bal,rate,firstname,lastname,address,ssn);
  
  //put the account to the vector
  List.push_back(temp);
  
  cout<<"\nYou created the checking account of "<<YEL<<temp.FullName()<<RESET<<".";
  
  //print out the created account
  temp.perPrint(List.size()-1);
}

//Checking the num is bigger than 0 or not for choice 1
void CheckNum(float& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    float i=StrtoF(str);
    if(i<0)
    {
      cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      getline(cin,str);
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
      getline(cin,str);
      cout<<RESET;
      CheckNum(num,str);
  }
}

//printing out summary for all accounts for choice 2
void PrintSum()
{
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
    cout<<" "<<i+1<<"    "<<setw(22)<<List[i].FullName()<<List[i].getToBa()<<endl;
  }
  cout<<GRN<<"-------------------------";
  cout<<"-------------------\n";
  cout<<RESET;
}

//Printing out details for all accounts for choice 2
void PrintAll()
{
    cout<<"\nYou printed details for "<<YEL<<"all accounts"<<RESET<<".";
  unsigned int vecSize = List.size();
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  for(int i=0;i<vecSize;++i)
  {

    cout<<" No."<<i+1<<"\n";
    cout<<" Name : "<<setw(18)<<List[i].FullName()<<"Checking Account : ";
    cout<<List[i].getToBa()<<endl;
    cout<<setw(29)<<" "<<"Interest Rate : "<<List[i].getRate()<<endl;
    cout<<setw(37)<<" "<<"S.S.N : "<<List[i].getSsn()<<endl;
    cout<<setw(35)<<" "<<"Address : "<<List[i].getAdd()<<endl;
  }
  cout<<"------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}

//Prompting for choice 2
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
        getline(cin,input2);
        cout<<RESET;
}

//Prompting for choice 3
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
    getline(cin,input3);
    cout<<RESET;
}

//Select the account for choice 3,4,5
void SelectOne(int selected)
{
  int i=0;
  i=selected-1;
  cout.setf(ios::left);
  cout<<GRN<<"\n----------------------------";
  cout<<"----------------------------------\n";
  cout<<" No."<<i+1<<"\n";
  cout<<" Name : "<<setw(18)<<List[i].FullName()<<"Checking Account : "<<List[i].getToBa();
  cout<<"\n------------------------------";
  cout<<"--------------------------------";
  cout<<RESET;
}

//Deposit the money of the account for choice 4
void Deposit(string input4,int selected)
{
  //declaration for the float variable
  float x=0.0;
  
  //transfrom the input string to the float
  x=StrtoF(input4);
  
  //condition for negative numbers
  if(x<0)
  {
    cout<<RED<<"Invalid input, please re-input.\n"<<RESET;
  }
  
  //condition for pasitive numbers
  else
  {
    //deposit the number to the totalbalance of the selected account
    List[selected-1].Deposit(x);
    
    //prompting for the deposited account
    cout<<"\nYou deposited "<<GRN<<x<<RESET<<" to the account of ";
    cout<<YEL<<List[selected-1].FullName()<<RESET<<".";
    SelectOne(selected);
  }
}

//Withdraw the money of the account for choice 5
void Withdrawl(string input5,int selected)
{    
    //declaration for the float variable
    float x=0;
    
    //transfrom the input string to the float
    x=StrtoF(input5);
    
    //condition for negative numbers or out of the rage of the totalbalance
    if(x<0||x>List[selected-1].getToBa())
    {
      cout<<RED<<"Invalid input, please re-input.\n"<<RESET;
    }
    
    //condition for pasitive numbers
    else
    {
      //withdrw the number to the totalbalance of the selected account
      List[selected-1].Withdrawal(x);
      
      //prompting for the deposited account
      cout<<"\nYou withdrew "<<GRN<<x<<RESET<<" from the account of ";
      cout<<YEL<<List[selected-1].FullName()<<RESET<<".";
      SelectOne(selected);
    }
}

//add 3 accounts to the class
void Add3Accounts()
{  
  //constructor
  Person temp(1000.00,1,"Bergnaum" ,"Dorris","229 Candace Burg Port Aliyahview","224-46-0407");
  
  //put the account in the vector
  List.push_back(temp);
  
  Person temp1(2000.00,2,"Marvin", "Jerod","197 Chyna Radial Suite 370","306-42-6992");
  List.push_back(temp1);
  
  Person temp2(3000.00,3,"Rogahn", "Georgette","9480 Juliana Village Suite 152","649-05-1129");
  List.push_back(temp2);
}