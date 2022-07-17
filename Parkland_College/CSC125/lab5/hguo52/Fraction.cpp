#include "Fraction.h"

Fraction::Fraction()
{
    this->setNum();
    this->setDem();
}

//munator function to set value to fractions
void Fraction::setFrac()
{
     int tmpN, tmpD;
    char divideSign;
    cin >> tmpN >> divideSign >> tmpD;
    cin.ignore();
    this->setNum( tmpN );
    this->setDem( tmpD );
    this->check();
    this->check();
}

//check the denominator is zero or not
void Fraction::check()
{
    if(den==0)
    {
        cout<<RED<<"\nThe denominator can not be zero. Please re-input"<<RESET<<endl;
        this->setFrac();
    }
}

  //print out the factions 
void Fraction:: Print()
{
  cout << num << "/" <<  den;
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

//overloading the operator +
Fraction Fraction::operator+(Fraction sf)
{
    int nums=0,dens=1;
    nums=num*sf.getDen()+sf.getNum()*den;
    dens=den*sf.getDen();
    Fraction temp;
    temp.setNum(nums);
    temp.setDem(dens);
    return temp;
}

//overloading the operator <<
ostream &operator<<(ostream &os, Fraction& f)
{
    if(f.num%f.den==0)
    {
        os<<GRN<<f.num/f.den<<RESET;
    }
    else
    {
        int gcd=0;
        gcd=f.GCD();
        os<<GRN<<f.num/gcd<<"/"<<f.den/gcd<<RESET;
    }
    return os;
}
