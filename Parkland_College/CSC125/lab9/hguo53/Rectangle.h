#include "Shape.h"

class Rectangle : public Shape
{
  private:
    float width;
    float height;
  public:
    Rectangle(float a, float b);
    virtual ~Rectangle(){return;};

    virtual void setArea(){area=width*height;};
    virtual ostream &print(ostream& os);
};

Rectangle::Rectangle(float a, float b):Shape(0)
{
    width=a;height=b;name="Rectangle";
}

ostream &Rectangle::print(ostream& os)
{
  os<<YEL<<name<<RESET;
  os<<", width("<<GRN<<width<<RESET<<"), height("<<GRN<<height<<RESET;
  os<<"), area is : "<<GRN<<area<<RESET<<endl;
  return os;
}
