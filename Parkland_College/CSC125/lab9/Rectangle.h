#include "Shape.h"

class Rectangle : public Shape
{
  private:
    float area;

  public:
    Rectangle(float a, float b);
  
    float getArea();
    void detail();
};

Rectangle::Rectangle(float a, float b):Shape(a,b)
{
    area=getX()*getY();
    setName("Recangle");
  
}

float Rectangle::getArea()
{
    return area;
}

void Rectangle::detail()
{
    cout<<"(width: "<<GRN<<getX()<<RESET<<" length: "
       <<GRN<<getY()<<RESET<<")";
}