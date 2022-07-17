#include "Shape.h"

class Circle : public Shape
{
  private:
    float area;
  public:
    Circle(float a=0.0, float b=0.0);

    float getArea();
    void detail();

};

Circle::Circle(float a,float b):Shape(a,b)
{
    area=getX()*getX()*getY();
    setName("Circle");   
}

float Circle::getArea()
{
    return area;
}

void Circle::detail()
{
    cout<<"(Radius: "<<GRN<<getX()<<RESET<<" PI: "
       <<GRN<<getY()<<RESET<<")";
}