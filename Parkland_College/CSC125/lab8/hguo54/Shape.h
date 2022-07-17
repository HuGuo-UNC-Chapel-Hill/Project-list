#ifndef SHAPE_H
#define SHAPE_H


#include <iostream>
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
  public:
    Shape(float x=0.0, float y=0.0);
    void setX(float i=0.0){x=i;}
    void setY(float i=0.0){y=i;}
    float getX() const { return x;}
    float getY() const { return y;}
};

Shape::Shape(float x, float y)
{
  setX(x);
  setY(y);
}

#endif