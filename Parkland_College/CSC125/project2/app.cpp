#include "account.h"
#include "person.h"


int main()
{
  Account acc[10];
  Person per[10];
  acc[0].setBala(10);
  per[0].setSsn("123456");
  acc[0].accPrint();
  cout<<endl;
  per[0].perPrint();
  cout<<endl;
  return 0;
}
