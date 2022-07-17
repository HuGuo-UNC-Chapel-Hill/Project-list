#include "Shape.h"

class Rectangle : public Shape
{
  private:
    float area;
  public:
    Rectangle(float a=0.0, float b=0.0);

    float getArea() const {return area;}
    friend ostream &operator<<(ostream& os, const Rectangle &r);
};

Rectangle::Rectangle(float a,float b):Shape(a,b)
{

    area=(a>0&&b>0) ? getX()*getY():0;
}

ostream &operator<<(ostream& os, const Rectangle &r)
{
    os<<"\n The "<<YEL<<"area"<<RESET<<" of the "<<YEL<<"recangle"<<RESET<<" is : "
            <<GRN<<r.getArea()<<RESET<<endl;
            //os<<r.getX();
    return os;
}
