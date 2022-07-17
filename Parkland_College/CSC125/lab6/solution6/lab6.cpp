
#include <iostream>
using namespace std;

#include "Array.h"

main()
{
  Array a1( 3 );
  a1.setValue( 0, 1.0 );
  a1.setValue( 1, 22.0 );
  a1.setValue( 2, 12.2 );
 
  Array a2( 3 );
  a2.setValue( 0, 3.3 );
  a2.setValue( 1, 44.5 );
  a2.setValue( 2, 21.7 );
 
  Array tmp;
  tmp = a1 + a2;         
  cout << tmp;

  tmp = a1 + 2.0;
  cout << tmp;

  tmp = 4.0 + tmp;
  cout << tmp;
}
