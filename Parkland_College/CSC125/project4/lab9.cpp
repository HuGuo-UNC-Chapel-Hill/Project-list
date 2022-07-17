#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void Choice(string& choice);

template<class T>
void CheckNum(T& num,string& str);

const float PI=3.14;

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
            
            int i=0;
 
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
                    i++;
                                       
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
                    
                    cout<<"\n Total created shapes : "<<GRN<<i<<RESET;
                    cout<<"\n Number of shapes aviliable : "<<GRN<<shape-i
                          <<RESET<<endl;    
                }
                
                else if(input=="r"||input=="R")
                {    
                    i++;
                    
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
                    
                    cout<<"\n Total created shapes : "<<GRN<<i<<RESET;
                    cout<<"\n Number of shapes aviliable : "<<GRN<<shape-i
                          <<RESET<<endl; 
                    
                }
                
                else if(input=="c"||input=="C")
                {    
                    i++;
                    
                    float a=0.0;
                    string sa="";

                    cout<<"\n Please input the "<<YEL<<"radius"<<RESET
                              <<" for the  circle : ";
                    cout<<GRN;getline(cin,sa);cout<<RESET;
                    CheckNum(a,sa);

                    Circle *c=new Circle(a,PI);
                    List.push_back(c);
                    
                    cout<<"\n Total created shapes : "<<GRN<<i<<RESET;
                    cout<<"\n Number of shapes aviliable : "<<GRN<<shape-i
                          <<RESET<<endl; 
                    
                }
                   
                else{cout<<RED<<"\n Invalid input, please re-input."<<RESET;}                                    
            }
            
        }
        
        else if(choice=="2")
        {
            for(int i=0;i<List.size();++i)
            {
                cout<<"\n The "<<GRN<<"No."<<i+1<<RESET<<" shape is "<<
                        YEL<<List[i]->getName()<<" "<<RESET;
                List[i]->detail();
                cout<<", and the area is : "
                        <<GRN<<List[i]->getArea()<<RESET<<"."<<endl;
            }
        }
        
        else if(choice=="3")
        {
            exit (-1);
        }
        
        else{cout<<RED<<"\n Invalid input, please re-input."<<RESET;}               
    } 
    
    while(!List.empty()) 
    {
        delete List.back();
        List.pop_back();
    }
    
    List.clear();
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


