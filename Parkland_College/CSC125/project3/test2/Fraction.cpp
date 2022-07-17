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

void Fraction:: Print()
{
  cout << num << "/" <<  den;
}

//return the gcd of the fraction
int Fraction::GCD(int num,int den)
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
Fraction Fraction::operator+(const Fraction sf)
{
    int nums=0,dens=1;
    nums=num*sf.getDen()+sf.getNum()*den;
    dens=den*sf.getDen();
    Fraction temp;
    temp.setNum(nums);
    temp.setDem(dens);
    return temp;
}

//overloading the operator -
Fraction Fraction::operator-(const Fraction sf)
{
    int nums=0,dens=1;
    nums=num*sf.getDen()-sf.getNum()*den;
    dens=den*sf.getDen();
    Fraction temp;
    temp.setNum(nums);
    temp.setDem(dens);
    return temp;
}

//overloading the operator *
Fraction Fraction::operator*(const Fraction sf)
{
    int nums=0,dens=1;
    nums=num*sf.getNum();
    dens=den*sf.getDen();
    Fraction temp;
    temp.setNum(nums);
    temp.setDem(dens);
    return temp;
}

//overloading the operator /
Fraction Fraction::operator/(const Fraction sf)
{
    int nums=0,dens=1;
    nums=num*sf.getDen();
    dens=den*sf.getNum();
    Fraction temp;
    temp.setNum(nums);
    temp.setDem(dens);
    return temp;
}
/*
//overloading the operator <<
ostream &operator<<(ostream &os,const Fraction& f)
{
    if(f.num%f.den==0)
    {
        os<<GRN<<f.num/f.den<<RESET;
    }
    else
    {
        int gcd=0;
        gcd=GCD(f.getNum(),f.getDen());
        os<<GRN<<f.num/gcd<<"/"<<f.den/gcd<<RESET;
    }
    return os;
}*/
