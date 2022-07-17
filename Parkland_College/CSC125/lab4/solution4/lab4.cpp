// Lab 4

#include "Trip.h"

#define NUM_TRIPS	10

// Stores city name and miles
struct City
{
  string name;
  float miles;
};

City cities[NUM_TRIPS] = 
{
  "Kansas City, MO", 530.0,
  "Nashville, TN", 474.0,
  "Minneapolis, MN", 409,
  "Dallas, TX", 928,
  "Denver, CO", 1011,
  "Fargo, ND", 646,
  "Los Angeles, CA", 2034,
  "Indianapolis, IN", 185,
  "Miami, FL", 1377,
  "Phoenix, AZ", 1800
};

main()
{
  Trip trips[NUM_TRIPS];

  // Set predefined trips
  int i;
  for( i = 0; i < NUM_TRIPS; ++i )
    {
      trips[i].setOrigin( "Chicago" );
      trips[i].setDestination( cities[i].name );
      trips[i].setDistance( cities[i].miles );
    }

  // Welcome screen
  cout << "-----------------------------" << endl;
  cout << "| Welcome to Travel Planner |" << endl;
  cout << "-----------------------------" << endl;

  // User interface
  int choice;
  bool done = false;
  while( !done )
    {
      // Input destination
      cout << "Select destination: " << endl;
      for( i = 0; i < NUM_TRIPS; ++i )
	{
	  cout << "  " << i+1 << ") " << trips[i].getDestination();
	  cout << " - " << trips[i].getDistance() << " miles" << endl;
	}
      cout << "  " << i+1 << ") Quit" << endl;
      cin >> choice;

      // If quit
      done = ( choice == NUM_TRIPS+1 ) ? 1 : 0;

      // If not done
      if( !done )
	{
	  // Input rate of travel
	  float rate;
	  cout << endl;
	  cout << "Enter driving speed (in mph): ";
	  cin >> rate;
	  trips[ choice-1 ].setRate( rate );

	  // Compute and print duration
	  trips[ choice-1 ].ComputeDuration();
	  cout << "Trip Information:" << endl;
	  trips[ choice-1 ].Print();
	}
    }
}
