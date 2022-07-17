#include "Shape.h"

class Triangle : public Shape
{
  private:
    float base;
    float height;
  public:
    Triangle(float a=0.0, float b=0.0);
    virtual ~Triangle(){return;};

    virtual void setArea(){area=base*height/2;};
    virtual ostream &print(ostream& os);
};

Triangle::Triangle(float a,float b):Shape(0)
{
  base=a;
  height=b;
  name="Triangle";
}

ostream &Triangle::print(ostream& os)
{
  os<<YEL<<name<<RESET;
  os<<", base("<<GRN<<base<<RESET<<"), height("<<GRN<<height<<RESET;
  os<<"), area is : "<<GRN<<area<<RESET<<endl;
  return os;
}
