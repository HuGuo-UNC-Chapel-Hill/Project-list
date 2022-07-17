#include "Trips.h"

Trips::Trips()
{
  city="";
  distance=0;
}

Trips::Trips(string city,float distance)
{
    this->setCity(city);
    this->setDistance(distance);
}

void Trips::setCity(string city)
{
  this->city=city;
}

void Trips::setDistance(float distance)
{
  this->distance=distance;
}

float Trips::getSpeed()
{
    float speed=0;
    cout<<"Please input your travel speed (miles/hour) :"<<GRN;
    cin>>speed;
    cout<<RESET;
    if(speed<=0)
    {
      cout<<RED<<"Invalid input, please re-input the speed: "<<GRN;
      cin>>speed;
      cout<<RESET;
    }
    return speed;
}

float Trips::getTime(float speed)
{
  float time=0;
  time=this->getDistance()/speed;
  return time;
}

void Trips::Output()
{
  cout<<"\nYou chose "<<GRN<<city<<RESET<<"."<<endl;
  cout<<"There are "<<GRN<<distance<<" miles"<<RESET<<" from Chicago to your destination."<<endl;
}
