#include "Shape.h"

class Circle : public Shape
{
  private:
    float radius;
  public:
    Circle(float r=0.0);
    virtual ~Circle(){return;};

    virtual void setArea(){area=radius*radius*3.14;};
    virtual ostream &print(ostream& os);
};

Circle::Circle(float r):Shape(0)
{
  area=0;
  radius=r;
  name="Circle";
}

ostream &Circle::print(ostream& os)
{
  os<<YEL<<name<<RESET;
  os<<", radius("<<GRN<<radius<<RESET<<"), area is : "<<GRN<<area<<RESET<<endl;
  return os;
}
