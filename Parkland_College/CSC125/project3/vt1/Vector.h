#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"


using namespace std;


class Vec
{
    //private:
    //public:
        int size;
        vector<float> *VC;

    public:
     
        Vec (int size=0);
        ~Vec ();
        void init();
        void setVal(int,float);
        int getSize()const {return size;}
        float getVal(int i)const {return VC->at(i);}

        //debug return the memory address of the index in the Vec
        void getMem(int i){ cout<<&this->VC[i];}

        Vec operator+(Vec &a);

        Vec operator-(Vec &a);

        Vec operator*(Vec &a);

        Vec operator/(Vec &right);


       void operator=( const Vec & );

        Vec( const Vec & );

        friend ostream &operator<<(ostream& os, Vec &a);
};


#endif // Vec_H
