/**********************************
Author:    Hu Guo
Date:      02/19/2019
Name:      Lab2b.cpp
Description:        Pizza Pieces
***********************************************/
#include <iostream>

using namespace std;
const double PI=3.14;

int main()
{
    //storage
    int pieces,diameter;
    double pizzaarea,smallArea=(0.5)*3*3*PI,radius;

    //processing
        //output
    cout <<"\t"<<"Diameter"<<"\t"<<"Pieces"<<endl;

    for (diameter=6; diameter<10; diameter++)
{
    radius=(0.5)*diameter;
    pizzaarea=radius*radius*PI;
    pieces=pizzaarea/smallArea;

    //output
    cout <<"\t   "<<diameter<<"\t\t   "<<pieces<<endl;
}

    for (diameter=10; diameter<21; diameter++)
{
    radius=(0.5)*diameter;
    pizzaarea=radius*radius*PI;
    pieces=pizzaarea/smallArea;
    //output
    cout <<"\t   "<<diameter<<"\t\t   "<<pieces<<endl;
}

    return 0;
}
