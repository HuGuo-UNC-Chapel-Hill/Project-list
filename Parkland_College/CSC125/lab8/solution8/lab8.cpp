
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

#include <stdlib.h>

main()
{
  Circle c;
  Triangle t;
  Rectangle r;
  int choice;
  float tmp1, tmp2;

  cout << "Create a shape" << endl;
  cout << "\t1) Circle" << endl;
  cout << "\t2) Triangle" << endl;
  cout << "\t3) Rectangle" << endl;
  cout << "\t4) Done" << endl;
  cin >> choice;
  switch( choice )
    {
    case 1:
      cout << "Enter <radius>" << endl;
      cin >> tmp1;
      c = Circle( tmp1 );
      c.Area();
      cout << c;
      break;
    case 2:
      cout << "Enter <base> <height>" << endl;
      cin >> tmp1 >> tmp2;
      t = Triangle( tmp1, tmp2 );
      t.Area();
      cout << t;
      break;
    case 3:
      cout << "Enter <width> <height>" << endl;
      cin >> tmp1 >> tmp2;
      r = Rectangle( tmp1, tmp2 );
      r.Area();
      cout << r;
      break;
    case 4:
      exit(0);
      break;
    }
}
