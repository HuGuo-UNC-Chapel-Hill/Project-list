#include "Vector.h"

void random(Vec &a);


int main()
{
     //time
    srand (time(0));
    Vec lvc ,rvc;
    random(lvc);
    cout<<lvc;

    return 0;
}

void random(Vec &a)
{
    float num=0.0;
    Vec temp(3);
    a=tmep;
    for(int i=0;i<a.getSize();i++)
    {
        num=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/99.9));
        a.setVal(i,num);
    }
}
