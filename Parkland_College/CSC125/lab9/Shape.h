#ifndef SHAPE_H
#define SHAPE_H


#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET  "\x1B[0m"

class Shape
{
  private:
    float x;
    float y;
    string name;
  public:
    Shape(float x=0.0, float y=0.0);
    virtual float getArea()=0;
    virtual void detail()=0;
    
    void setX(float i=0.0){x=i;}
    void setY(float i=0.0){y=i;}
    void setName(string n=""){name=n;}
    float getX() const { return x;}
    float getY() const { return y;}
    string getName() const {return name;}

};

Shape::Shape(float a, float b)
{
  setX(a);
  setY(b);
}



#endif
