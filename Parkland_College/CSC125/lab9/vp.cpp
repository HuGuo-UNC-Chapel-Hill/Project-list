
#include <iostream>
using namespace std;

// Parent class
class Parent
{
protected:
  float val;

public:

  // Overloaded output stream operator
  friend ostream &operator<<( ostream &, Parent & );

  // Pure virtual method
  virtual ostream &Print( ostream & ) = 0;

  // Access methods
  void setVal( float f ) { val = f; }
  int getVal() { return val; }
};

ostream &operator<<( ostream &strm, Parent &p )
{
  strm << "Parent information: " << endl;
  strm << "  val: " << p.val << endl;

  // Virtual print
  return p.Print( strm );
}

// Child class
class Child : public Parent
{
protected:
  int ival;

public:

  // Virtual method
  virtual ostream &Print( ostream & );

  // Access methods
  void setIval( int i ) { ival = i; }
  int getIval() { return ival; }
};

ostream &Child::Print( ostream &strm )
{
  strm << "Child information" << endl;
  strm << "  ival: " << ival << endl;
  return strm;
}

main()
{
  Child *c = new Child;
  c->setIval( 44 );

  Parent *p = c;
  p->setVal( 4.5 );
  cout << *p;
}
  
