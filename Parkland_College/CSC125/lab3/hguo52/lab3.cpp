/**********************************
Author:     Hu Guo
Date:       07/01/2019
Name:       Lab3.cpp
Description:   sum of fractions(class method)
***********************************************/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

class Fraction
{
private:
  int num;
  int den;
public:

  Fraction();
  ~Fraction(){};
  //debug
  //~Fraction(){cout<<"Destructor is called.";};

  //munator function to set value to fractions
  void setFrac();

  //check the denominator is zero or not
  void check();

  //print out the factions depends on each situation
  void printOut();

  //accessor function to get value of fractions
  int getNum(){return num;};
  int getDen(){return den;};

  //calculate the sum
  void calculate(Fraction ff,Fraction sf);

  //analysis for each fraction
  void nozero();

  //return the gcd of the fraction
  int GCD();

  //output the simplified result
  void result(Fraction ff,Fraction sf);
};

//checking for the loop
void remind(char& input);

int main()
{
    char choice;
    do
    {
        cout<<endl;
        //instantiating the first fraction
        cout<<YEL<<"Please input the first fraction."<<RESET<<endl;
        Fraction first;
        first.setFrac();
        first.printOut();

        //debug
        //cout<<first.getNum()<<first.getDen();

        //the second fraction
        cout<<YEL<<"Please input the second faction."<<RESET<<endl;
        Fraction second;
        second.setFrac();
        second.printOut();

        //sum of two fractions
        Fraction sum;
        sum.calculate(first,second);
        //debug
        //sum.printOut();

        //output the result
        sum.result(first,second);
        cout<<endl;

        cout<<YEL;
        cout<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
        cin>>choice;
        remind(choice);
        cout<<RESET;

    }while(choice=='y'||choice=='Y');

    return 0;
  }

Fraction::Fraction()
{
    num=0;
    den=1;
}

//munator function to set value to fractions
void Fraction::setFrac()
{
    cout<<"Please in put the numerator: "<<GRN;
    cin>>num;
    cout<<RESET;
    cout<<"please in put the denominator: "<<GRN;
    cin>>den;
    cout<<RESET;
    this->check();
}

//check the denominator is zero or not
void Fraction::check()
{
    while(den==0)
    {
        cout<<RED<<"\nThe denominator can not be zero. Please re-input"<<RESET<<endl;
        this->setFrac();
    }
}

  //print out the factions depends on each situation
void Fraction::printOut()
{

    if(den<0&&num!=0)
    {
        num*=-1;
        den*=-1;
        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<RESET<<".";
        cout<<endl;
    }
    else if(num==0)
    {

        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<"."<<RESET<<endl;
        cout<<"The fraction you inputed is "<<GRN<<"0"<<RESET<<endl;
    }
    else
    {
        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<RESET<<"."<<endl;
	}
	cout<<endl;
}

//calculate the sum
void Fraction::calculate(Fraction ff,Fraction sf)
{
    num=ff.getNum()*sf.getDen()+sf.getNum()*ff.getDen();
    den=ff.getDen()*sf.getDen();
    //debug
    //cout<<num;
    //cout<<den;
}

//return the gcd of the fraction
int Fraction::GCD()
{
    int a,b,c;
    if( den< 0)
    {
        den*=-1;
        num*=-1;
    };
    a = abs(num);
    b = abs(den);
    c = a % b;
    while(c)
    {
      a = b;
      b = c;
      c = a % b;
    }
    return b;
}

//analysis for each fraction
void Fraction::nozero()
{
    int gcd=0;
    if(num%den==0)
    {
        cout<<"\nThe sum of two fractions is "<<GRN<<num<<"/"<<den<<RESET<<".";
        cout<<"\nThe simplified result is "<<GRN<<num/den<<RESET<<".";
    }
    else
    {
        gcd=this->GCD();
        cout<<"\nThe sum of two fractions is "<<GRN<<num<<"/"<<den<<RESET<<".";
        cout<<"\nThe simplified result is "<<GRN<<num/gcd<<"/"<<den/gcd<<RESET<<".";
    }
}

//output the simplified result
void Fraction::result(Fraction ff,Fraction sf)
{
    if(ff.getNum()==0)
    {
        sf.nozero();
    }
    else if(sf.getNum()==0)
    {
        ff.nozero();
    }
    else
    {
        this->nozero();
    }
}

//checking for the loop
void remind(char& input)
{
    if(input=='n'||input=='N')
    {
        cout<<RESET;
        exit(-1);
    }
    while(input!='Y'&&input!='y'&&input!='n'&&input!='N')
    {
        cout<<"\nInvalid input, please re-input"<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        cin>>input;
    }
}
