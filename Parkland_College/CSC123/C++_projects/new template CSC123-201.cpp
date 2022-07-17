/**********************************
Author:     HuGuo
Date:        02/10/2019
Name:      Lab1.cpp
Description:        cents calculator
***********************************************/

#include <iostream>
using namespace std;
const int VQUARTER = 25, VDIME = 10, VNICKEL = 5;//name constants

int main()
{
    //storage
    int quarters,dimes,nickels,cents;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //input 3lines for each variable
    cout << "Enter the number of quarters: "; // Prompt
    cin >> quarters;
    cout << "\n You have " << quarters << " quarters."<< endl; //echo - new line
    cout << "\nEnter the number of dimes: "; // Prompt
    cin >> dimes;
    cout << "\n You have " << dimes << " dimes."<< endl; //echo - new line
    cout << "\nEnter the number of nickels: "; // Prompt
    cin >> nickels;
    cout << "\n You have " << nickels << " nickels."<< endl; //echo - new line

    //processing
    cents = quarters*VQUARTER + dimes*VDIME + nickels*VNICKEL;

    //output
    cout << "\nThe total number of cents are "<<cents<<" cents."<<endl;
    return 0;
}
