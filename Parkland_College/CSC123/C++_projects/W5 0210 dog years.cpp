#include <iostream>
using namespace std;
/********************************
Author :    Hu Guo
Date :  2/10/2019
Name :  hello.cpp
Description:    Demo for today
*********************************/
const int DOGADJUST = 5;

int main()

{   int age =20;
    // frills show organization
    cout << "How old are you: "; // prompt
    cin >> age;
    cout << "\nYou are "<< age << " years old"<<endl;
    cout << "You are "<< age*DOGADJUST << " in dog years"<<endl;
    return 0;

    return 0;
}
