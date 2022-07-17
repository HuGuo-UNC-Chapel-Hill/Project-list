/**********************************
Author:     Hu Guo
Date:       06/19/2019
Name:       Lab1.cpp
Description:   sum of fractions
***********************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

void inputFirst(int& a, int& b);
void firstFra(int& a,int& b);
void inputSecond(int& c, int& d);
void secondFra(int& c,int& d);
int FindGcd(int e, int f);
void result(int a,int b, int c,int d,int e, int f, int gcd);
void zero(int x,int y);

int main()
{
    int a=0,b=0,c=0,d=0,e=0,f=0,gcd=0;
    char input;
    do
    {
	firstFra(a,b);
	secondFra(c,d);
	e=a*d+b*c;
	f=b*d;
	cout<<endl;
	result(a,b,c,d,e,f,gcd);
        cout<<"\nTry more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        cin>>input;
        if(input=='n'||input=='N')
	  exit(-1);
        while(input!='Y'&&input!='y'&&input!='n'&&input!='N')
        {
             cout<<"\nInvalid input, please re-input"<<endl;
             cout<<"Try more or quit the program?"<<endl;
             cout<<"(press y to try more or press n to quit)"<<endl;
             cin>>input;
        }
    }while(input=='y'||input=='Y');
    return 0;
}

void inputFirst(int& a, int& b)
{
    cout<<"\nPlease input the first fraction"<<endl;
    cout<<"Please input the numerator:";
    cin>>a;
    cout<<"Please input the denominator: ";
    cin>>b;
}

void firstFra(int& a, int& b)
{
    inputFirst(a,b);
    if(b==0)
    {
      cout<<"\nInvalid input, the denominator can not be 0.";
      cout<<"Please re-input the number."<<endl;
        inputFirst(a,b);
    }
    cout<<"\nThe first fraction is "<<a<<"/"<<b<<"."<<endl;
    if(a==0)
    {
      cout<<"The first fraction is 0."<<endl;
    }
}

void inputSecond(int& c, int& d)
{
    cout<<"\nPlease input the second fraction"<<endl;
    cout<<"Please input the numerator:";
    cin>>c;
    cout<<"Please input the denominator: ";
    cin>>d;
}

void secondFra(int& c, int& d)
{
    inputSecond(c,d);
    if(d==0)
    {
      cout<<"\nInvalid input, the denominator can not be 0.";
      cout<<"Please re-input the number."<<endl;
        inputSecond(c,d);
    }
    cout<<"\nThe second fraction is "<<c<<"/"<<d<<"."<<endl;
    if(c==0)
    {
      cout<<"The second fraction is 0."<<endl;
    }
}

int FindGcd(int e, int f)
{
   if (e == f)
      return e;
   else if (e > f)
      return FindGcd(e-f, f);
   else return FindGcd(f, f-e);
}

void result(int a, int b,int c,int d,int e,int f,int gcd)
{
    if(a==0)
    {
        zero(c,d);
    }
    else if(c==0)
    {
        zero(a,b);
    }
    else if(e==f)
    {
        cout<<"The sum of two fractions is "<<e<<"/"<<f<<".";
        cout<<"\nThe simplified result is 1"<<".";
    }
    else if(e%f==0)
    {
        cout<<"The sum of two fractions is "<<e<<"/"<<f<<".";
        cout<<"\nThe simplified result is "<<e/f<<".";
    }
    else
    {
        gcd=FindGcd(e,f);
        cout<<"The sum of two fractions is "<<e<<"/"<<f<<".";
        cout<<"\nThe simplified result is "<<e/gcd<<"/"<<f/gcd<<".";
    }
    cout<<endl;
}

void zero(int x, int y)
{
    int gcd=0;
    if(x%y==0)
      {
        cout<<"The sum of two fractions is "<<x<<"/"<<y<<".";
        cout<<"\nThe simplified result is "<<x/y<<".";
      }
      else
      {
        cout<<"The sum of two fractions is "<<x<<"/"<<y<<".";
        gcd=FindGcd(x,y);
        cout<<"\nThe simplified result is "<<x/gcd<<"/"<<y/gcd<<".";
      }
}
