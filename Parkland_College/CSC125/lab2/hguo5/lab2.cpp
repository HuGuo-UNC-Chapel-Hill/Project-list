/**********************************
Author:     Hu Guo
Date:       06/24/2019
Name:       Lab2.cpp
Description:   sum of fractions(struct method)
***********************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

struct fraction
{
    int n,d;
}first,second,sum;

void input(fraction *ff);
void calculate(fraction *ff,fraction *sf, fraction *sum);
void result(fraction *ff,fraction *sf, fraction *sum);
void remind(char& input);

int main()
{
    char choice;
    do
    {
        //input the first fraction
        cout<<"Please in put the first fraction"<<endl;
        input(&first);

	//debug
        //cout<<first.n<<"/"<<first.d<<endl;
	
	//input the second fraction
        cout<<"\nPlease in put the second fraction"<<endl;	
	input(&second);

	//debug
        //cout<<second.n<<"/"<<second.d<<endl;

	//calculate the sum
        calculate(&first,&second,&sum);
       
	//debug
	//cout<<sum.n<<"/"<<sum.d<<endl;
       
	//output the simplified result
	result(&first,&second,&sum);
        cout<<endl;
        cout<<"\nTry more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        cin>>choice;
        remind(choice);
    }while(choice=='y'||choice=='Y');
    return 0;
}


void input(fraction *f)
{
    cout<<"Please in put the numerator: ";
    cin>>f->n;
    cout<<"please in put the denominator: ";
    cin>>f->d;
    cout<<endl;
    if(f->d<0&&f->n!=0)
    {
        f->n*=-1;
        f->d*=-1;
        cout<<"The fraction you inputed is "<<f->n<<"/"<<f->d<<".";
        cout<<endl;
    }
    else if(f->n==0)
    {

        cout<<"The fraction you inputed is "<<f->n<<"/"<<f->d<<"."<<endl;
        cout<<"The fraction you inputed is 0"<<endl;
    }
    else if(f->d==0)
    {
        cout<<"Invalid input. The denominator can not be 0. Please re-input."<<endl;
        input(f);
    }
    else
    {
        cout<<"The fraction you inputed is "<<f->n<<"/"<<f->d<<"."<<endl;
    }
}

void calculate(fraction *ff,fraction *sf, fraction *sum)
{
    sum->n=ff->n*sf->d+sf->n*ff->d;
    sum->d=ff->d*sf->d;
}

int FindGcd(int e,int f)
{
    if (e == f)
        return e;
    else if (e > f)
        return FindGcd(e-f, f);
    else return FindGcd(f, f-e);
}

void nozero(fraction *f)
{
    int gcd=0;
    if(f->n%f->d==0)
    {
        cout<<"\nThe sum of two fractions is "<<f->n<<"/"<<f->d<<".";
        cout<<"\nThe simplified result is "<<f->n/f->d<<".";
    }
    else
    {
        gcd=FindGcd(f->n,f->d);
        cout<<"\nThe sum of two fractions is "<<f->n<<"/"<<f->d<<".";
        cout<<"\nThe simplified result is "<<f->n/gcd<<"/"<<f->d/gcd<<".";
    }
}

void result(fraction *ff,fraction *sf, fraction *sum)
{
    if(ff->n==0)
    {
        nozero(sf);
    }
    else if(sf->n==0)
    {
        nozero(ff);
    }
    else
    {
        nozero(sum);
    }
}

void remind(char& input)
{
    if(input=='n'||input=='N')
    {
        exit(-1);
    }
    while(input!='Y'&&input!='y'&&input!='n'&&input!='N')
    {
        cout<<"\nInvalid input, please re-input"<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        cin>>input;
    }
}
