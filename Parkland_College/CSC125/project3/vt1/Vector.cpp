#include "Vector.h"



Vec ::Vec (int num)
{
   size=num;
   VC =size ? new vector<float> (size,0.0):NULL;
}

Vec ::~Vec ()
{
    delete VC;
    //cout<<"\nDetor is called";
}

void Vec::init()
{
    size=0;
    VC=NULL;
}

void Vec::setVal(int i,float num)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    VC->at(i)=num;
}

Vec Vec::operator+(Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.VC->at(i)=(VC->at(i)+a.VC->at(i));
    }
    return temp;
}

Vec Vec::operator-(Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.VC->at(i)=(VC->at(i)-a.VC->at(i));
    }
    return temp;
}

Vec Vec::operator*(Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.VC->at(i)=(VC->at(i)*a.VC->at(i));
    }
        //cout<<temp;
    return temp;
}


Vec Vec::operator/(Vec& right)
{
    Vec temp(size);
    temp.VC->at(0)=((VC->at(1)*right.VC->at(2))-(VC->at(2)*right.VC->at(1)));
    temp.VC->at(1)=-((VC->at(0)*right.VC->at(2))-(VC->at(2)*right.VC->at(0)));
    temp.VC->at(2)=((VC->at(0)*right.VC->at(1))-(VC->at(1)*right.VC->at(0)));
    return temp;
}

void Vec::operator=(const Vec &a)
{
    if( this != &a )
    {
        size=a.size;

        // delete any existing memory
       delete VC;
        // allocate memory for object
        VC =size ? new vector<float> (size,0.0):NULL;


        // copy dynamic memory
        for(int i = 0; i < size; ++i )
            VC->at(i)=(a.VC->at(i));
    }
}

Vec::Vec( const Vec &a)
{
    init();
    *this=a;
}

ostream &operator<<(ostream& os, Vec &a)
{
    for(int i=0; i<a.size; i++)
    {
        os<<setw(5)<<a.VC->at(i)<<" ";
    }

    return os;
}
