#include "Account.h"
#include "Person.h"

void welcome();

int main()
{    
  welcome();
    float bal=0,rate=0;
    string firstname="",lastname="",address="",ssn="";
   vector<Person> List;
   
   Person per(bal,rate,firstname,lastname,address,ssn);
   List.push_back(per); 
   cout<<List.size();
   cout<<endl;
   //List[0].accPrint();
   List[0].perPrint();
   cout<<endl;
}

void welcome()
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
  cout<<setw(8)<<" "<<"6) Quit\n";
  cout<<RESET;

}