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
  //munator function to set value to fractions
  void setFrac();

  //print out the factions depends on each situation
  void printOut();

  //accessor function to get value of fractions
  int getNum(){return num;};
  int getDen(){return den;};

  //calculate the sum
  void calculate(Fraction ff,Fraction sf);

  //analysis for each fraction
  void nozero();
};

//instantiate the fractions
void Instantiation(Fraction& f);

//function to find the greatest common divisor
int FindGcd(int num, int den);

//out put the final simlified result
void result(Fraction ff,Fraction sf, Fraction sum);

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
        Instantiation(first);

	//debug
	//cout<<first.getNum()<<first.getDen();


	//the second fraction
        cout<<YEL<<"Please input the second faction."<<RESET<<endl;
        Fraction second;
        Instantiation(second);


	//sum of two fractions
        Fraction sum;
        sum.calculate(first,second);
        result(first,second,sum);
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
  f.setFrac();
}

void Instantiation(Fraction& f)
{
    while(f.getDen()==0)
    {
        cout<<RED<<"\nThe denominator can not be zero. Please re-input"<<RESET<<endl;
        f.setFrac();
    }
    f.printOut();
    cout<<endl;
}

void Fraction::setFrac()
{
  cout<<YEL<<"Please in put the numerator: "<<GRN;
  cin>>num;
  cout<<YEL;
    cout<<"please in put the denominator: "<<GRN;
  cin>>den;
  cout<<RESET;
  cout<<endl;
}

void Fraction::printOut()
{
    cout<<YEL;
    if(den<0&&num!=0)
    {
        num*=-1;
        den*=-1;
        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<".";
        cout<<endl;
    }
    else if(num==0)
    {

        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<"."<<YEL<<endl;
        cout<<"The fraction you inputed is "<<GRN<<"0"<<YEL<<endl;
    }
    else
    {
        cout<<"The fraction you inputed is "<<GRN<<num<<"/"<<den<<"."<<endl;
	}
	cout<<RESET;
}

void Fraction::calculate(Fraction ff,Fraction sf)
{
  num=ff.getNum()*sf.getDen()+sf.getNum()*ff.getDen();
  den=ff.getDen()*sf.getDen();
  //debug
  //cout<<num;
  //cout<<den;
}

int FindGcd(int num, int den)
{
    if (num == den)
        return num;
    else if (num > den)
        return FindGcd(num-den, den);
    else return FindGcd(den, den-num);
}

void Fraction::nozero()
{
    int gcd=0;
    if(num%den==0)
    {
        cout<<YEL<<"\nThe sum of two fractions is "<<GRN<<num<<"/"<<den<<".";
        cout<<YEL<<"\nThe simplified result is "<<GRN<<num/den<<".";
    }
    else
    {
        gcd=FindGcd(num,den);
        cout<<YEL<<"\nThe sum of two fractions is "<<GRN<<num<<"/"<<den<<".";
        cout<<YEL<<"\nThe simplified result is "<<GRN<<num/gcd<<"/"<<den/gcd<<".";
    }
    cout<<RESET;
}

void result(Fraction ff,Fraction sf, Fraction sum)
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
        sum.nozero();
    }
}

void remind(char& input)
{
    if(input=='n'||input=='N')
    {
        cout<<RESET;
        exit(-1);
    }
    while(input!='Y'&&input!='y'&&input!='n'&&input!='N')
    {
        cout<<YEL<<"\nInvalid input, please re-input"<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        cin>>input;
        cout<<RESET;
    }
}
