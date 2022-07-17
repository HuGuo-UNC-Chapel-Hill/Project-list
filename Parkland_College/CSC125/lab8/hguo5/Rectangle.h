#include "Shape.h"

class Rectangle : public Shape
{
  private:
    float area;
  public:
    Rectangle(float a=0.0, float b=0.0);
    void setArea();
    float getArea() const {return area;}
    friend ostream &operator<<(ostream& os, const Rectangle &r);
};

Rectangle::Rectangle(float a,float b):Shape(a,b)
{}

void Rectangle::setArea() 
{  
    area=getX()*getY();    
}

ostream &operator<<(ostream& os, const Rectangle &r)
{
    os<<"\n The "<<YEL<<"area"<<RESET<<" of the "<<YEL<<"recangle"<<RESET<<" is : "
            <<GRN<<r.area<<RESET<<endl;
    return os;
}