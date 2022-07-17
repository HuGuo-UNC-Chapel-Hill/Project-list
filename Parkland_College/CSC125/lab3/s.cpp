#include <iostream>

using namespace std;

 

// Knows

class Solution

{

private:

  float vol;

  float per;

 

  // Does (declarations)

public:

  void Init(float v, float p);

  void Mix(Solution *, Solution *);

  void Print();

  Solution() 

  {

    vol = 0.0;

    per = 0.0;

  }

  void setVol( float v ) { vol = v; }

  void setPer( float p ) { per = p; }

  float getVol() { return vol; }

  float getPer() { return per; }

};

 

// Application

main()

{

  // Declare 3 solutions

  Solution x;

  Solution y;

  Solution f;

 

  // Initialize solutions

  x.Init( 0.0, 0.20 );

  y.Init( 0.0, 0.45 );

  f.Init( 60.0, 0.30 );

 

  // Mix solutions

  f.Mix( &x, &y );

 

  // Print solutions

  x.Print();

  y.Print();

  f.Print();

}

 

 

// Does (definitions)

void Solution::Init(float v, float p)

{

  vol = v;

  per = p;

}

void Solution::Mix(Solution *x, Solution *y)

{

  y->vol = ( per*vol - x->per*vol ) /

    ( y->per - x->per );

  x->vol = vol - y->vol;

}

void Solution::Print()

{

  cout << “Solution:” << endl;

  cout << “  volume: ” << vol << endl;

  cout << “  percentage: ” << per << endl;

}
