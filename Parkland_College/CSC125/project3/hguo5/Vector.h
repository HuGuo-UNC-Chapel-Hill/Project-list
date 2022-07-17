#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

using namespace std;

class Vec
{
    private:
        //size of the dynamic vector
        int size;

        //vector pointer
        vector<float> *VC;

    public:

        //constructor
        Vec (int size=0);

        //destructor
        ~Vec ();

        //initialize the object
        void init();

        //get the size of the dynamic vector
        int getSize()const {return size;}

        //set the value for the dynamic vector
        void setVal(int,float);

        //return the vlaue of any poistion of the dynamic vector
        float getVal(int i)const {return VC->at(i);}

        //debug return the memory address of the index in the Vec
        void getMem(int i){ cout<<&this->VC[i];}

        //overloaded operator +
        Vec operator+(const Vec &a);

        //overloaded operator -
        Vec operator-(const Vec &a);

        //overloaded operator *
        Vec operator*(const Vec &a);

       // Vec operator/(const Vec &right);

        //overloaded operator /
        friend Vec operator/(const Vec& left, const Vec &right);

        ////overloaded operator =
        void operator=( const Vec & );

        //overloaded  copy constructor
        Vec( const Vec & );

        //overloaded operaotr <<
        friend ostream &operator<<(ostream& os,const Vec &a);
};


#endif // VECTOR_H
