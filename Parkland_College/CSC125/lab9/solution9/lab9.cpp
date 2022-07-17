
#include <vector>
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

Shape *CreateShape();

main()
{
  vector <Shape *> shapes;
  Shape *tmp;

  // Create shapes
  while( tmp = CreateShape() )
    shapes.push_back( tmp );

  // For each shape created
  cout << "Your computed shape areas..." << endl;
  for( int i=0; i < shapes.size(); ++i )
    {
      // Dynamic binding (using the virtual function "Area")
      // to compute areas of the shape
      shapes[i]->Area();

      // Print the shape (overloaded output stream operator)
      cout << *shapes[i];

      // Delete the shape
      delete shapes[i];
    }
}

Shape *CreateShape()
{
  float tmp1, tmp2;
  int choice;
  Shape *tmp;

  // Create new shape on heap
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
      tmp = new Circle( tmp1 );
      break;
    case 2:
      cout << "Enter <base> <height>" << endl;
      cin >> tmp1 >> tmp2;
      tmp = new Triangle( tmp1, tmp2 );
      break;
    case 3:
      cout << "Enter <width> <height>" << endl;
      cin >> tmp1 >> tmp2;
      tmp = new Rectangle( tmp1, tmp2 );
      break;
    case 4:
      tmp = NULL;
      break;
    }

  // Return pointer to shape
  return tmp;
}
