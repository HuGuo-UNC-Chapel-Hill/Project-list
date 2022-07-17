#include "Shape.h"

class Triangle : public Shape
{
  private:
    float area;
  public:
    Triangle(float a=0.0, float b=0.0);

    float getArea() const {return area;}
    friend ostream &operator<<(ostream& os, const Triangle &t);
};

Triangle::Triangle(float a,float b):Shape(a,b)
{
    area=(a>0&&b>0) ? getX()*getY()/2:0;
}

ostream &operator<<(ostream& os, const Triangle &t)
{
    os<<"\n The "<<YEL<<"area"<<RESET<<" of the "<<YEL<<"triangle"<<RESET<<" is : "
            <<GRN<<t.getArea()<<RESET<<endl;
    return os;
}
