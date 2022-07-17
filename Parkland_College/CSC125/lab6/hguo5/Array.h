#ifndef ARRAY_H
#define ARRAY_H


#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"


using namespace std;


class Array
{
    //private:
    //public:
        int size;
        float *array;

    public:
        Array ();
        Array (int size=0);
        ~Array ();
        void init();
        void setVal(int,float);
        int getSize()const {return size;}
        float getVal(int i)const {return this->array[i];}

        //debug return the memory address of the index in the array
        void getMem(int i){ cout<<&this->array[i];}

        Array operator+(Array &a);
        Array operator+(float);

        void operator=( const Array & );

        Array( const Array & );

        friend ostream &operator<<(ostream& os, Array &a);
};



#endif // ARRAY_H
