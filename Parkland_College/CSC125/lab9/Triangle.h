#include "Shape.h"

class Triangle : public Shape
{
  private:
    float area;
  public:
    Triangle(float a=0.0, float b=0.0);

    float getArea();
     void detail();

};

Triangle::Triangle(float a,float b):Shape(a,b)
{
  area=getX()*getY()/2;
  setName("Triangle");
}


float Triangle::getArea()
{
  return area;
}

void Triangle::detail()
{
    
    cout<<"(base: "<<GRN<<getX()<<RESET<<" height: "<<GRN<<getY()<<RESET<<")";
  
}

