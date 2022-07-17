#include "Fraction.h"


void remind(string& input);



int main()
{
    string choice;
    do
    {
        Fraction leftf,rightf;
        //instantiating the first fraction
        cout<< "\nPlease input the left fraction : <numerator>/<denominator> \n";
        cout<<GRN;leftf.setFrac();cout<<RESET;
        cout<< "\nPlease input the right fraction : <numerator>/<denominator> \n";
        cout<<GRN;rightf.setFrac();cout<<RESET;

        //sum of two fractions
        Fraction sum;

        //overloading the operator <<
        cout<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
        cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

        sum=leftf+rightf;

        cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " + ";
        cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";
        //overload the operator <<
        cout<<sum<<endl;
               
        cout<<YEL;
        cout<<"\nTry more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
        getline(cin,choice);cout<<RESET;
        remind(choice);
        cout<<RESET;

    }while(choice=="y"||choice=="Y");

    return 0;
  }


//checking for the loop
void remind(string& input)
{
    if(input=="n"||input=="N")
    {
        cout<<RESET;
        exit(-1);
    }
    while(input!="Y"&&input!="y"&&input!="n"&&input!="N")
    {
        cout<<"\nInvalid input, please re-input"<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<endl;
        getline(cin,input);
    }
}
