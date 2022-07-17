#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;


void Choice(string& choice);

template<class T>
void CheckNum(T& num,string& str);

void CheckChoice(string& choice);

void remind(string& input);

const float PI=3.14;

int main()
{
    string choice;

    cout<<GRN<<"\n--------------------------------------------\n";
    cout<<YEL<<"Welcome to use the shape calculator for lab8\n";
    cout<<GRN<<"--------------------------------------------\n"<<RESET;
    Choice(choice);

    for(int i=1;i<2;)
    {
        if(choice=="1")
        {
            string input1="";
            while(1)
            {
                float a=0.0,b=0.0;
                string sa="",sb="";

                cout<<GRN<<"\n Tritangle shape calculation"<<RESET;
                cout<<"\n Please input the number of "<<YEL<<"base"<<RESET<<" for the triangle : ";
                cout<<GRN<<" ";getline(cin,sa);cout<<RESET;
                CheckNum(a,sa);

                cout<<"\n Please input the number of "<<YEL<<"height"<<RESET
                    <<" for the Tritangle : ";
                cout<<GRN<<" ";getline(cin,sb);cout<<RESET;
                CheckNum(b,sb);

                Triangle t=Triangle(a,b);
                //t.setArea();
                cout<<t;

                cout<<endl<<" Try more or quit the program?";
                cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "
                    <<YEL<<"more"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "
                    <<YEL<<"main menu"<<RESET<<"."<<endl;
                cout<<YEL<<" ";getline(cin,input1);cout<<RESET;
                remind(input1);

                if(input1=="b"||input1=="B"){break;}
            }
           Choice(choice);
        }

        if(choice=="2")
        {
            string input2="";
            while(1)
            {
                float a=0.0,b=0.0;
                string sa="",sb="";

                cout<<GRN<<"\n Rectangle shape calculation"<<RESET;
                cout<<"\n Please input the number of "<<YEL<<"width"<<RESET<<" for the rectangle : ";
                cout<<GRN<<" ";getline(cin,sa);cout<<RESET;
                CheckNum(a,sa);

                cout<<"\n Please input the number of "<<YEL<<"length"<<RESET
                    <<" for the rectangle : ";
                cout<<GRN<<" ";getline(cin,sb);cout<<RESET;
                CheckNum(b,sb);

                Rectangle r=Rectangle(a,b);
                //r.setArea();
                cout<<r;

                cout<<endl<<" Try more or quit the program?";
                cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "
                    <<YEL<<"more"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "
                    <<YEL<<"main menu"<<RESET<<"."<<endl;
                cout<<YEL<<" ";getline(cin,input2);cout<<RESET;
                remind(input2);

                if(input2=="b"||input2=="B"){break;}
            }
           Choice(choice);
        }

        if(choice=="3")
        {
            string input2="";
            while(1)
            {
                 float a=0.0;
                string sa="";

                cout<<GRN<<"\n Circle shape calculation (PI=3.14) "<<RESET;
                cout<<"\n Please input the number of "<<YEL<<"radius"<<RESET<<" for the circle : ";
                cout<<GRN<<" ";getline(cin,sa);cout<<RESET;
                CheckNum(a,sa);

                Circle c=Circle(a,PI);
                //c.setArea();
                cout<<c;

                cout<<endl<<" Try more or quit the program?";
                cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "
                    <<YEL<<"more"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "
                    <<YEL<<"main menu"<<RESET<<"."<<endl;
                cout<<YEL<<" ";getline(cin,input2);cout<<RESET;
                remind(input2);
                if(input2=="b"||input2=="B"){break;}
            }
           Choice(choice);
        }

        if(choice=="4")
        {
            exit (-1);
        }
    }

    return 0;
}



//showing the choice menu
void Choice(string& choice)
{
  cout<<" Enter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Triangle shape calculation\n";
  cout<<setw(8)<<" "<<"2) Recangle shape calculation\n";
  cout<<setw(8)<<" "<<"3) Circle shape calculation\n";
  cout<<setw(8)<<" "<<"4) Exit\n";
  getline(cin,choice);
  CheckChoice(choice);
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

//checking the string of choice
void CheckChoice(string& choice)
{
  if(isdigit(choice[0]))
  {
    int i=0;
    CheckNum(i,choice);
    if(i>4||i<=0)
    {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
  }
}


//checking for the loop
void remind(string& input)
{
    while(input!="Y"&&input!="y"&&input!="b"&&input!="B")
    {
        cout<<"\n Invalid input, please re-input"<<endl;
        cout<<" Try more or quit the program?";
        cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "<<YEL<<"more"<<RESET<<".";
        cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<"."<<endl;
        cout<<YEL<<" ";getline(cin,input);cout<<RESET;
    }
}
