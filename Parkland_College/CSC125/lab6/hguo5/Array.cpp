#include "Array.h"


Array ::Array ()
{
   this->init();
}

Array ::Array (int size)
{
   this->size=size;
   array = size ? new float[size]: NULL;
}

Array ::~Array ()
{
    if( array ) delete[] array;
    //cout<<"\nDetor is called";
}

void Array::init()
{
    size=0;
    array=NULL;
}

void Array::setVal(int i,float num)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    this->array[i]=num;
}

Array Array::operator+(Array& a)
{
    Array temp(size);
    for(int i=0;i<size;i++)
        temp.array[i]=this->array[i]+a.array[i];

    return temp;
}

Array Array::operator+(float num)
{
    Array temp(size);
    for(int i=0;i<size;i++)
        temp.array[i]=this->array[i]+num;

    return temp;
}

void Array::operator=(const Array &a)
{
    if( this != &a )
    {    
        size=a.size;
        
        // delete any existing memory

        if( array ) delete[] array;

        // allocate memory for object

        array = size ? new float[size] : NULL;

        // copy dynamic memory

        int i;

        for( i = 0; i < size; ++i )

          array[i] = a.array[i];

    }

}

Array::Array( const Array &a)
{
    this->init();
    *this=a;
}

ostream &operator<<(ostream& os, Array &a)
{
    for(int i=0; i<a.size; i++)
    {
        os<<setw(5)<<a.array[i]<<" ";
    }

    return os;
}
