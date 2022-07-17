#include "Shape.h"

class Circle : public Shape
{
  private:
    float area;
  public:
    Circle(float a=0.0, float b=0.0);

    float getArea() const {return area;}
    friend ostream &operator<<(ostream& os, const Circle &c);
};

Circle::Circle(float a,float b):Shape(a,b)
{
    area=(a>0&&b>0) ? a*a*b:0;
}


ostream &operator<<(ostream& os, const Circle &c)
{
    os<<"\n The "<<YEL<<"area"<<RESET<<" of the "<<YEL<<"cirle"<<RESET<<" is : "
            <<GRN<<c.getArea()<<RESET<<endl;
    return os;
}
