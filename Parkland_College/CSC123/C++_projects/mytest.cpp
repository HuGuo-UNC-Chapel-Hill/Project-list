#include <iostream>
using namespace std;

void pr(int& x);

int main () {

        int a=2;



        pr(a);
        cout<<a;




   return 0;
}

void pr(int& x)
{
    x+=3;

}
