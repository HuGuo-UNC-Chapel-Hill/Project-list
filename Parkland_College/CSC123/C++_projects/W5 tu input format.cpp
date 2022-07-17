#include <iostream>
#include <string>
using namespace std;
const int VQUARTER = 25;//name constants
const int VDIME = 10;
const int VNICKEL = 5;

int main()
{
//storage
int age;
int num = 100.9999;
string text = "C++ Fun";
double decimal = 0.0123456789;
int quarters=2, dimes=2,nickels=2;
int cents;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);//could be 0
//input 3lines for each variable
    cout << "Enter your age: "; // Prompt
    cin >> age;
    cout << "\n you entered " << age << " as your age"<< endl; //echo - new line
//processing
 cents = quarters*VQUARTER + dimes*VDIME + nickels*VNICKEL;
    //output
    cout << "Num variable starts at: "<<num<<endl;
    cout << "Double variable starts at: "<<decimal<<endl;
    cout << "String variable starts at: "<<text<<endl;
    cout.precision(4);
    cout << "Double variable starts at: "<<decimal<<endl;
    return 0;
}
