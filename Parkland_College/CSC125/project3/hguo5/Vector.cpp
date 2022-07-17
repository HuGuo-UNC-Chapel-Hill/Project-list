#include "Vector.h"

//constrctor
Vec ::Vec (int num)
{
   size=num;
   VC =size ? new vector<float> (size,0.0):NULL;
}

//deconstructor
Vec ::~Vec ()
{
    delete VC;
    //cout<<"\nDetor is called";
}

//initalize the object
void Vec::init()
{
    size=0;
    VC=NULL;
}

//set the val to the dynamic vector
void Vec::setVal(int i,float num)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    VC->at(i)=num;
}

//overloaded operator +
Vec Vec::operator+(const Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.setVal(i,(getVal(i)+a.getVal(i)));
    }
    return temp;
}

//overloaded operator -
Vec Vec::operator-(const Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.setVal(i,(getVal(i)-a.getVal(i)));
    }
    return temp;
}

//overloaded operator *
Vec Vec::operator*(const Vec& a)
{
    Vec temp(size);
    for(int i=0;i<size;i++)
    {
        temp.setVal(i,(getVal(i)*a.getVal(i)));
    }
        //cout<<temp;
    return temp;
}

/*
Vec Vec::operator/(const Vec& right)
{
    Vec temp(size);
    temp.VC->at(0)=((VC->at(1)*right.VC->at(2))-(VC->at(2)*right.VC->at(1)));
    temp.VC->at(1)=-((VC->at(0)*right.VC->at(2))-(VC->at(2)*right.VC->at(0)));
    temp.VC->at(2)=((VC->at(0)*right.VC->at(1))-(VC->at(1)*right.VC->at(0)));
    return temp;
}*/

//overloaded operator /
Vec operator/(const Vec& left, const Vec& right)
{
    Vec temp(left.getSize());

    //result0 = (left1 * right2) - (right1 * left2)
    temp.VC->at(0)=((left.getVal(1)*right.getVal(2))-(right.getVal(1)*left.getVal(2)));

    //result1 = -( (left0 * right2) - (right0 * left2) )
    temp.VC->at(1)=-((left.getVal(0)*right.getVal(2))-(right.getVal(0)*left.getVal(2)));

    //result2 = (left0 * right1) - (right0 * left1)
    temp.VC->at(2)=((left.getVal(0)*right.getVal(1))-(right.getVal(0)*left.getVal(1)));

    return temp;
}

//overloaded operator =
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
            setVal(i,a.getVal(i));
    }
}

//overloaded copy constrcutor
Vec::Vec( const Vec &a)
{
    init();
    *this=a;
}

//overloaded operator <<
ostream &operator<<(ostream& os,const Vec &a)
{
    for(int i=0; i<a.size; i++)
    {
        os<<GRN<<setw(5)<<a.getVal(i)<<" "<<RESET;
    }

    return os;
}
