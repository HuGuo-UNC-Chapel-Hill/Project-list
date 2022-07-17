#include <iostream>
using namespace std;

int main()
{
//storage
int age;
double decimal = 0.0123456789;
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
//input
    cout << "Enter your age: "; // Prompt
    cin >> age;
    cout << "\n you entered " << age << " as your age"<< endl; //echo - new line
//processing

    //output
    cout << "Double variable starts at: "<<decimal<<endl;
    cout.precision(4);
    cout << "Double variable starts at: "<<decimal<<endl;
    return 0;
}
