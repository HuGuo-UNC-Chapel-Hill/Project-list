/**********************************
Author:     HuGuo
Date:        02/15/2019
Name:      Extra Credit.cpp
Description:        Water Well
***********************************************/
 #include <iostream>
#include <cstring>
 #include <cmath>

 #include <iomanip>

using namespace std;

 int main () {
int i,k,lo=3,hi=8,result,total,amount,n=8,j;



double quadratic(double a,double b, double c){
if(pow(b,2)-4*a*c<0)
		cout<<"no real solutions";
else if(a==0)
	cout<< "no solution for a=0"<<endl;
	else{
	double d=(-b+sqrt(pow(b,2)-4*a*c))/(a+a);
	double e=(-b-sqrt(pow(b,2)-4*a*c))/(a+a);
	if(e>=d)
		cout<<e<<endl;
	else if(d>=e)
		cout<<d<<endl;
}
return 0;
}


    return 0;
 }
