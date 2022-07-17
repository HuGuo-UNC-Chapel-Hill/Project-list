
#include <iostream>
#include <string>
using namespace std;
const int M=1000,CM=900,DCCC=800,DCC=700,DC=600,D=500,CD=400,CCC=300,CC=200,C=100,XC=90,LXXX=80,LXX=70,LX=60,L=50,XL=40,XXX=30,XX=20,X=10,IX=9,VIII=8,VII=7,VI=6,V=5,IV=4,III=3,II=2,I=1,minimum=-1,maximum=3998;

int main()
{
int year;
string Roman=" ";
cin>>year;
while(year>0)
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
else if (year>=C)
{
    year-=C;
    Roman+="C";
}
}

cout << (string)Roman;
return 0;
}
//Art of one = try to get one pass correct
//Art of many= multiply the art of one


