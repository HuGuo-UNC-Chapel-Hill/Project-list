#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

void Choice(string& choice);

template<class T>
void CheckNum(T& num,string& str);

void counter(int shape, int i, int t, int r, int c);

int main()
{
    vector<Shape *> List;

    cout<<GRN<<"\n--------------------------------------------\n";
    cout<<YEL<<"Welcome to use the shape creator for lab9\n";
    cout<<GRN<<"--------------------------------------------\n"<<RESET;

    while(1)
    {
        string choice="",sshape="";

        int shape=0;

        Choice(choice);

        if(choice=="1")
        {
            cout<<" Please input the number of shapes : ";
            cout<<GRN;getline(cin,sshape);cout<<RESET;
            CheckNum(shape,sshape);

            string input="";

            int i=0,tn=0,rn=0,cn=0;

            while(i<shape)
            {
                cout<<"\n Input "<<YEL<<"'t'"<<RESET<<" to creat "
                                   <<YEL<<"Triangle"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'r'"<<RESET<<" to creat "
                                   <<YEL<<"Retangle"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'c'"<<RESET<<" to creat "
                                   <<YEL<<"Circle"<<RESET<<"."<<endl;
                cout<<YEL;getline(cin,input);cout<<RESET;

                if(input=="t"||input=="T")
                {
                    i++;tn++;

                    float a=0.0,b=0.0;
                    string sa="",sb="";

                    cout<<"\n Please input the "<<YEL<<"base"<<RESET
                                    <<" for the triangle : ";
                    cout<<GRN;getline(cin,sa);cout<<RESET;
                    CheckNum(a,sa);

                    cout<<" Please input the "<<YEL<<"height"<<RESET
                                    <<" for the triangle : ";
                    cout<<GRN;getline(cin,sb);cout<<RESET;
                    CheckNum(b,sb);

                    Triangle *t=new Triangle(a,b);
                    List.push_back(t);

                    counter(shape,i,tn,rn,cn);
                }

                else if(input=="r"||input=="R")
                {
                    i++;rn++;

                    float a=0.0,b=0.0;
                    string sa="",sb="";

                    cout<<"\n Please input the "<<YEL<<"width"<<RESET
                              <<" for the rectangle : ";
                    cout<<GRN;getline(cin,sa);cout<<RESET;
                    CheckNum(a,sa);

                    cout<<" Please input the "<<YEL<<"length"<<RESET
                              <<" for the rectangle : ";
                    cout<<GRN;getline(cin,sb);cout<<RESET;
                    CheckNum(b,sb);

                    Rectangle *r=new Rectangle(a,b);
                    List.push_back(r);

                    counter(shape,i,tn,rn,cn);

                }

                else if(input=="c"||input=="C")
                {
                    i++;cn++;

                    float a=0.0;
                    string sa="";

                    cout<<"\n Please input the "<<YEL<<"radius"<<RESET
                              <<" for the  circle : ";
                    cout<<GRN;getline(cin,sa);cout<<RESET;
                    CheckNum(a,sa);

                    Circle *c=new Circle(a);
                    List.push_back(c);

                    counter(shape,i,tn,rn,cn);

                }

                else{cout<<RED<<"\n Invalid input, please re-input."<<RESET;}
            }

        }

        else if(choice=="2")
        {
            for(int i=0;i<List.size();++i)
            {
                List[i]->setArea();
                cout<<"\n The "<<GRN<<"No."<<i+1<<RESET<<" shape is ";
                cout<<*(List[i]);
            }
        }

        else if(choice=="3")
        {
            break;
        }

        else{cout<<RED<<"\n Invalid input, please re-input."<<RESET;}
    }

    while(!List.empty())
    {
        delete List.back();
        List.pop_back();
    }

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

void counter(int shape, int i, int t, int r, int c)
{
  cout<<"\n Total created shapes : "<<GRN<<i<<RESET;
  cout<<" (Triangle: "<<GRN<<t<<RESET<<"), ";
  cout<<"(Recangle: "<<GRN<<r<<RESET<<"), ";
  cout<<"(Circle: "<<GRN<<c<<RESET<<").";
  cout<<"\n Number of shapes aviliable : "<<GRN<<shape-i
        <<RESET<<"."<<endl;
}
