#include "Fraction.h"

Fraction::Fraction()
{
    //num=0;
    //den=1;
    this->setNum();
    this->setDem();
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
        cout<<"The sum of two fractions is "<<GRN<<num<<"/"<<den<<RESET<<".";
        cout<<"\nThe simplified result is "<<GRN<<num/den<<RESET<<".";
    }
    else
    {
        gcd=this->GCD();
        cout<<"The sum of two fractions is "<<GRN<<num<<"/"<<den<<RESET<<".";
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


