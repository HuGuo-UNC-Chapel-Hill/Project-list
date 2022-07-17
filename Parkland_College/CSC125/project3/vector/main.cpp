#include "Vector.h"

void random(Vec &a);


int main()
{
     //time
    srand (time(0));
     //set the decimal place
    std::cout << std::fixed;
    std::cout << std::setprecision(1);

    Vec left(3);
    random(left);
    cout<<left<<endl;
    Vec right(3);
    random(right);
    cout<<right<<endl;

    Vec test(3);
    cout<<test<<endl;
    //left+right;
    //test=left+right;
    //test=left-right;
    //test=left*right;
    test=left/right;
    cout<<test<<endl;
    cout<<test.getSize();

    return 0;
}

void random(Vec &a)
{
    float num=0.0;
    for(int i=0;i<a.getSize();i++)
    {
        num=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/99.9));
        a.setVal(i,num);
    }
}
