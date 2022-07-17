
#include <iostream>;
using namespace std;

int main()
{
    int year;

    cout << "Please input the number of year from 1 to 3999."<< endl;
    cin>> year
    while (1<=year<=3999)
        cout << "you input the number of year is: "<<year<<"."<<endl;
    if(year<1) continue;
    if(year>3999) comtinue;
}
