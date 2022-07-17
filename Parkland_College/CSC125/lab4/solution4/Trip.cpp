// Trip class method definitions

#include "Trip.h"

// Constructor
Trip::Trip()
{
  // Initialize state variables
  distance = 0.0;
  rate = 0.0;
  duration = 0.0;
  origin.clear();
  destination.clear();
}

// Print
void Trip::Print()
{
  cout << "  -------------------------" << endl;
  cout << "  Origin: " << origin << endl;
  cout << "  Destination: " << destination << endl;
  cout << "  Distance (in miles): " << distance << endl;
  cout << "  Rate (mph): " << rate << endl;
  cout << "  Duration (hours): " << duration << endl;
  cout << "  -------------------------" << endl;
}

// Compute duration
void Trip::ComputeDuration()
{
  duration = rate ? distance / rate : 0.0;
}
