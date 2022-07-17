#include <iostream>
//Libraries are used in C++ to add feature to the language
//there are 72 keywords in C++
//iostream is a library about input and output
using namespace std; // semicolons end a complete thought
/*****************************************************
 Author : Hu Guo
 Date : 2/7/2019
 Name : Demo.cpp
 Description : Demo for today
*****************************************************/
const int DOGADJUST = 5;

int main()
// this is our startup function
// this also our end function

{

    int age ;
    // frills show organization
    cout << "How old are you: "; // prompt
    cin >> age;
    cout << "\nYou are "<< age << " years old"<<endl;
    cout << "You are "<< age*DOGADJUST << " in dog years"<<endl;
    return 0;
}
