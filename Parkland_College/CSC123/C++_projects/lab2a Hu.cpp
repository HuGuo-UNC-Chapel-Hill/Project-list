/**********************************
Author:    Hu Guo
Date:      02/19/2019
Name:      Lab2a.cpp
Description:        Roman Numeral Year
***********************************************/
#include <iostream>
#include <string>
using namespace std;
const int M=1000,CM=900,D=500,CD=400,C=100,XC=90,L=50,XL=40,X=10,IX=9,V=5,IV=4,I=1;

int main()
{
    //storage
    int year;
    string Roman="";


    //input
    input:
    cout << "\nEnter a year from 1 to 3999: ";//prompt
    cin >> year;
    cout << endl;

    //processing
    if(year<=0 || year >=4000)
    {
     cout << "\nThe number of year is out of range. Please input again.\n";
     goto input;
    }


    while(year>0 && year<4000)
    {
    if(year>=M)
    {
        year-=M;
        Roman+="M";
    }
    else if (year>=CM)
    {
        year-=CM;
        Roman+="CM";
    }
    else if (year>=D)
    {
        year-=D;
        Roman+="D";
    }
    else if (year>=CD)
    {
        year-=CD;
        Roman+="CD";
    }
    else if (year>=C)
    {
        year-=C;
        Roman+="C";
    }
    else if(year>=XC)
    {
        year-=XC;
        Roman+="XC";
    }
    else if (year>=L)
    {
        year-=L;
        Roman+="L";
    }
    else if (year>=XL)
    {
        year-=XL;
        Roman+="XL";
    }
    else if (year>=X)
      {
        year-=X;
        Roman+="X";
    }
    else if (year>=IX)
    {
        year-=IX;
        Roman+="IX";
    }
    else if (year>=V)
    {
        year-=V;
        Roman+="V";
    }
    else if (year>=IV)
    {
        year-=IV;
        Roman+="IV";
    }
    else if (year>=I)
    {
        year-=I;
        Roman+="I";
    }

}

    //output
    cout<< Roman <<endl;

    return 0;
    }


