#include "Trips.h"

Trips::Trips()
{
  city="";
  distance=0;
}

void Trips::setCity(string city)
{
  this->city=city;
}

void Trips::setDistance(float distance)
{
  this->distance=distance;
}

float Trips::getTime()
{
  float time=0, speed=0;
  cout<<"Please input the travel speed (miles/hour):";
  cin>>speed;
  time=this->getDistance()/speed;
  return time;
}

void Trips::Output()
{
  cout<<"\nYou chose "<<GRN<<city<<RESET<<" as your destination."<<endl;
  cout<<"There are "<<GRN<<distance<<RESET<<" miles from Chicago to "<<city<<"."<<endl;
}
