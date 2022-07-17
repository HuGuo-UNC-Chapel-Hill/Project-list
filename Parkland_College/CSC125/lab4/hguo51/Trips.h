#ifndef TRIPS_H
#define TRIPS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <sstream>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

class Trips
{
 private:
  string city;
  float distance;

 public:
  Trips();
  Trips(string city,float distance);
  void setCity(string city);
  void setDistance(float distance);
  string getCity(){ return city;}
  float getDistance(){ return distance;}
  float getSpeed();
  void getTime(float speed);
  void Output();
};


#endif // TRIPS_H_H

