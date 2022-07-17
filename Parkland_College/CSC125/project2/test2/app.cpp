#include "Account.h"
#include "Person.h"

void welcome();

int main()
{

  Person per[20];
  per[0]=Account(10,0.5)
  per[0]=Person("Abc","Greenstret","2312");
  per[0].accPrint();
  cout<<endl;
  per[0].perPrint();
  welcome();
  cout<<endl;
  return 0;
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