#ifndef _Trip_h_
#define _Trip_h_

// Trip class declaration

#include <iostream>
using namespace std;

class Trip
{
private:
  string origin;
  string destination;
  float distance;
  float duration;
  float rate;

public:

  // Constructor
  Trip();
 
  // Print method
  void Print();

  // Compute rate
  void ComputeDuration();       

  // Access methods
  void setDistance( float d ) { distance = d; }
  float getDistance() { return distance; }
  void setRate( float r ) { rate = r; }
  float getRate() { return rate; }
  void setDuration( float d ) { duration = d; }
  float getDuration() { return duration; }
  void setOrigin( string o ) { origin = o; }
  void setDestination( string d ) { destination = d; }
  string getDestination() { return destination; }
  string getOrigin() { return origin; }
};

#endif
