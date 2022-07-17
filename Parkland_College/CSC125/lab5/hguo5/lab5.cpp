#include "Fraction.h"


void remind(char& input);

Fraction operator+( Fraction ff,  Fraction sf) ;


int main()
{
    char choice;
    do
    {
        cout<<endl;
        //instantiating the first fraction
        cout<<YEL<<"Please input the first fraction."<<RESET<<endl;
        Fraction first;
        cout<<first.getNum()<<first.getDen();
        first.setFrac();
        first.printOut();

        //debug
        //cout<<first.getNum()<<first.getDen();

        //the second fraction
        cout<<YEL<<"Please input the second faction."<<RESET<<endl;
        Fraction second;
        second.setFrac();
        second.printOut();

        //sum of two fractions
        Fraction sum;
        sum=first+second;
        // sum.calculate(first,second);
        //debug
        //sum.printOut();

        //output the result
        sum.result(first,second);
        cout<<endl;

        cout<<YEL;
        cout<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
        cin>>choice;
        remind(choice);
        cout<<RESET;

    }while(choice=='y'||choice=='Y');

    return 0;
  }

Fraction operator+( Fraction ff,  Fraction sf)
{   int num=0,den=1;
    num=ff.getNum()*sf.getDen()+sf.getNum()*ff.getDen();
    den=ff.getDen()*sf.getDen();
    Fraction temp;
    temp.setNum(num);
    temp.setDem(den);
    return temp;
}

//checking for the loop
void remind(char& input)
{
    if(input=='n'||input=='N')
    {
        cout<<RESET;
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
