#include "Trips.h"

//default constructor
Trips::Trips()
{
  city="";
  distance=0;
}

//overloaded constructor
Trips::Trips(string city,float distance)
{
    this->setCity(city);
    this->setDistance(distance);
}

//setter function
void Trips::setCity(string city)
{
  this->city=city;
}

//setter function
void Trips::setDistance(float distance)
{
  this->distance=distance;
}

//prompting for the choice
void Trips::Output()
{
  cout<<"\nYou chose "<<GRN<<city<<RESET<<"."<<endl;
  cout<<"There are "<<GRN<<distance<<" miles"<<RESET<<" from Chicago to your destination.\n"<<endl;
}

//input the speed of trips
float Trips::getSpeed()
{
    float speed=0;

    this->Output();

    cout<<"Please input your travel speed :"<<GRN;
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

//calculate the time and output the it
void Trips::getTime(float speed)
{
  float time=0;
  time=this->getDistance()/speed;

  cout<<YEL<<"\nYour travel time is : "<<GRN<<(unsigned int)time<<YEL<<" hours ";
  cout<<GRN<<int(60*(time-(int)time))<<YEL<<" mins"<<endl;
  cout<<RESET;
}


