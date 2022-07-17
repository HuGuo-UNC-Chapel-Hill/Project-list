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
protected:
    float area;
    string name;
public:
    Shape(float a=0.0);
    virtual ~Shape(){return;}

    friend ostream &operator<<(ostream &os, Shape& s)
    {
      return s.print(os);
    }
    virtual ostream &print(ostream &osd)=0;

    virtual void setArea()=0;
};

Shape::Shape(float a):area(a)
{
  name="";
}

#endif
