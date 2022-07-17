/**********************************
Author:     HuGuo
Date:        02/15/2019
Name:      Extra Credit.cpp
Description:        Water Well
***********************************************/

#include <iostream>
#include <conio.h>
using namespace std;
const float PI=3.14,INCHTOFEET=.083333,WATERFOR1DAY=250,_1CFWATER=7.48;

int main()
{
    //storage
    float radius,radiusinfeet,height,uservolume,tankvolumme;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);//could be 0



    //input 3lines for each variable
    cout << "To supply a family of four needs "<< 250 <<" gallons water per day.";
    cout << "\nPlease input the radius and the height of a well to reserve water.";
    cout << "\nEnter the radius of the well in inches: ";// Prompt
    cin >> radius;
    cout << "The radius of the well is " << radius << " inches "<<endl; //echo - new line
    cout << "\nEnter the height of the well in foot, which must blow 50 feet: ";// Prompt
    cin >> height;
    cout << "The height of the well is " << height << " feet."<< endl; //echo - new line

    //processing

    radiusinfeet=radius*INCHTOFEET;
    uservolume = (PI*radiusinfeet*radiusinfeet*height)*_1CFWATER;
    tankvolumme = WATERFOR1DAY-uservolume;

    //loop
    if(height>50)
    {
    cout << "\nYou inputed the height which is bigger than 50 feet. "<<endl; // Prompt
    cout << "\nEnter the height of the well in foot, which must blow 50 feet: "<<endl;// Prompt
    cin >> height;
    cout << "The height of the well is " << height << " feet."<< endl; //echo - new line
    }
    if ( uservolume>= WATERFOR1DAY)
    {
    cout << "\nThe well has " << uservolume << " gallon volume and can reserve enough water."<<endl;
    }

    else
   {
    cout << "\nThe well has " << uservolume << " gallon volume, which can not reserve enough water."<<endl;
    cout << "\nYou will need a holding tank with "<< tankvolumme <<" gallons to satisfy the needs of our family of four from storage."<<endl;
   }
   return 0;
}
