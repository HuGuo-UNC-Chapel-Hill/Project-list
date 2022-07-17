#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET  "\x1B[0m"

class Shape
{
  private:
    float x;
    float y;
    string name;
  public:
    Shape(float x=0.0, float y=0.0);
    virtual ~Shape(){cout<<"sd is called";};
    virtual float getArea()=0;
    virtual void detail()=0;

    void setX(float i=0.0){x=i;}
    void setY(float i=0.0){y=i;}
    void setName(string n=""){name=n;}
    float getX() const { return x;}
    float getY() const { return y;}
    string getName() const {return name;}

};

Shape::Shape(float a, float b)
{
  setX(a);
  setY(b);
}


class Circle : public Shape
{
  private:
    float area;
  public:
    Circle(float a=0.0, float b=0.0);
    virtual ~Circle();
    float getArea();
    void detail();

};

Circle::Circle(float a,float b):Shape(a,b)
{
    area=getX()*getX()*getY();
    setName("Circle");
}

Circle::~Circle()
{

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

void Choice(string& choice);

template<class T>
void CheckNum(T& num,string& str);



const float PI=3.14;

int main()
{
    vector<Shape *> List;
    vector<Shape *> Bist;
    //cout<<List[0]<<" "<<Bist[0]<<endl;

    float a=0.0;
    string sa="";

    cout<<"\n Please input the "<<YEL<<"radius"<<RESET
                              <<" for the  circle : ";
    cout<<GRN;getline(cin,sa);cout<<RESET;
    CheckNum(a,sa);

    Circle *c= new Circle(a,PI);
    Circle *x= new Circle;
    *x=*c;
    List.push_back(x);
    delete c;
    cout<<List[0]->getArea()<<" "<<c<<endl;
    cout<<c->getArea();


    return 0;
}





//showing the choice menu
void Choice(string& choice)
{
  cout<<"\n Enter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Create shapes\n";
  cout<<setw(8)<<" "<<"2) Output the area of shapes\n";
  cout<<setw(8)<<" "<<"3) Exit\n";
  getline(cin,choice);
}

template<class T>
void CheckNum(T& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    T i=0;
    stringstream temp;
    temp<<str;
    temp>>i;
    if(i<0)
    {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
    }
    else
    {
      num=i;
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
  }
}
