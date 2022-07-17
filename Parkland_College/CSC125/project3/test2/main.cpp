#include "Fraction.h"
#include "Vector.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

void Choice(string& choice);

int StrtoI(string input);

float StrtoF(string input);

void CheckChoice(string& choice);

void CheckNum(float& num,string& str);

void remind1(float& lf, float& rf,string &input1);

void initVec(Vec& lvc, string side);

void remind2(Vec& lf, Vec& rf,string &input2);

void remind3(Fraction& lf, Fraction& rf,string& input3);

int main()
{
    string choice;

    float lf=0.0,rf=0.0;

    Fraction leftf,rightf;

    Vec lvc,rvc;

    //lvc.getMem(0);

    cout<<YEL<<"\n-------------------------------------------\n";
    cout<<GRN<<"Welcome to use the multi-purpose calculator\n";
    cout<<YEL<<"-------------------------------------------"<<RESET;
    Choice(choice);

    do
    {
        if(choice=="1")
        {

            string input1;
            cout<<GRN<<"\nFloat point calculator"<<RESET;
            if(lf!=0.0&&rf!=0.0)
            {
                cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;
            }

            do
            {
                remind1(lf,rf,input1);

                if(input1=="n")
                {
                    string left="",right="";
                    cout<< "\nPlease input the left float number : ";
                    cout<<GRN;getline(cin,left);cout<<RESET;
                    CheckNum(lf,left);
                    cout<< "Please input the right float number : ";
                    cout<<GRN;getline(cin,left);cout<<RESET;
                    CheckNum(rf,left);

                }
                else if(input1=="a")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float sum=lf+rf;
                    cout<<endl<<GRN<<lf<<RESET<<" + "<<GRN<<rf<<RESET<<" = "<<GRN<<sum<<RESET<<endl;
                }
                else if(input1=="s")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float dif=lf-rf;
                    cout<<endl<<GRN<<lf<<RESET<<" - "<<GRN<<rf<<RESET<<" = "<<GRN<<dif<<RESET<<endl;
                }
                else if(input1=="m")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float pro=lf*rf;
                    cout<<endl<<GRN<<lf<<RESET<<" * "<<GRN<<rf<<RESET<<" = "<<GRN<<pro<<RESET<<endl;
                }
                else if(input1=="d")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float quo=lf/rf;
                    cout<<endl<<GRN<<lf<<RESET<<" / "<<GRN<<rf<<RESET<<" = "<<GRN<<quo<<RESET<<endl;
                }
                else if(input1=="b"||input1=="B"){break;}
                //condition for the wrong input string
                else
                {
                    cout<<RED<<"Invalid input, please re-input.";
                }


            }while(input1!="b"&&input1!="B");

            Choice(choice);

        }

        if(choice=="2")
        {

            string input2;
            cout<<GRN<<"\nVector calculation calculator\n"<<RESET;
            if(lvc.getSize()!=0&&rvc.getSize()!=0)
            {
                cout<< "\nThe left vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                cout<< "The right vector numbers are : "<<GRN<<rvc<<RESET<<endl;
            }
            do
            {
                remind2(lvc,rvc,input2);

                if(input2=="n")
                {
                     initVec(lvc,"left vector");
                     initVec(rvc,"right vector");
                }
                else if(input2=="a")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float sum=lf+rf;
                    cout<<endl<<GRN<<lf<<RESET<<" + "<<GRN<<rf<<RESET<<" = "<<GRN<<sum<<RESET<<endl;
                }
                else if(input2=="s")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float dif=lf-rf;
                    cout<<endl<<GRN<<lf<<RESET<<" - "<<GRN<<rf<<RESET<<" = "<<GRN<<dif<<RESET<<endl;
                }
                else if(input2=="m")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float pro=lf*rf;
                    cout<<endl<<GRN<<lf<<RESET<<" * "<<GRN<<rf<<RESET<<" = "<<GRN<<pro<<RESET<<endl;
                }
                else if(input2=="d")
                {
                    cout<< "\nThe left float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The right float number is "<<GRN<<rf<<RESET<<endl;

                    float quo=lf/rf;
                    cout<<endl<<GRN<<lf<<RESET<<" / "<<GRN<<rf<<RESET<<" = "<<GRN<<quo<<RESET<<endl;
                }
                else if(input2=="b"||input2=="B"){break;}
                //condition for the wrong input string
                else
                {
                    cout<<RED<<"Invalid input, please re-input.";
                }


            }while(input2!="b"&&input2!="B");

            Choice(choice);

        }


        if(choice=="3")
        {
            string input3;
            cout<<GRN<<"\nFractions calculator"<<RESET;
            if(leftf.getNum()!=0&&rightf.getNum()!=0)
            {
                cout<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;
            }

            do
            {
                remind3(leftf,rightf,input3);

                if(input3=="n")
                {
                    cout<< "\nPlease input the left fraction : <numerator>/<denominator> \n";
                    cout<<GRN;leftf.setFrac();cout<<RESET;
                    cout<< "\nPlease input the right fraction : <numerator>/<denominator> \n";
                    cout<<GRN;rightf.setFrac();cout<<RESET;

                }
                else if(input3=="a")
                {
                    cout<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    Fraction sum=leftf+rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " + ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";
                    //overload the operator <<
                    cout<<sum<<endl;
                }
                else if(input3=="s")
                {
                    cout<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    Fraction dif=leftf-rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " - ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";
                    //overload the operator <<
                    cout<<dif<<endl;
                }
                else if(input3=="m")
                {
                    cout<<"\n"<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    Fraction pro=leftf*rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " * ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";
                    //overload the operator <<
                    cout<<pro<<endl;
                }
                else if(input3=="d")
                {
                    cout<< "\nThe left fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The right fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    Fraction quo=leftf/rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " / ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";
                    //overload the operator <<
                    cout<<quo<<endl;
                }

                else if(input3=="b"||input3=="B"){break;}
                //condition for the wrong input string
                else
                {
                    cout<<RED<<"Invalid input, please re-input.";
                }


            }while(input3!="b"&&input3!="B");

            Choice(choice);

        }

        else if(choice=="4")
        {
         exit (-1);
        }

    }while(choice!="4");

    return 0;
}


//showing the choice menu
void Choice(string& choice)
{
  cout.setf(ios::left);
  cout<<"\nEnter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Float calculation\n";
  cout<<setw(8)<<" "<<"2) Vector calculation\n";
  cout<<setw(8)<<" "<<"3) Fraction calculation\n";
  cout<<setw(8)<<" "<<"4) Quit\n";
  getline(cin,choice);
  CheckChoice(choice);
}

//Change string to int
int StrtoI(string input)
{
  int i=0;
  stringstream temp;
  temp<<input;
  temp>>i;
  return i;
}

//Change string to float
float StrtoF(string input)
{
  float i=0.0;
  stringstream temp;
  temp<<input;
  temp>>i;
  return i;
}

//checking the string of choice
void CheckChoice(string& choice)
{

  if(isdigit(choice[0]))
  {
    int i=StrtoI(choice);
    if(i>4||i<=0)
    {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
    }
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input."<<RESET;
      Choice(choice);
  }
}

void CheckNum(float& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
      float i=StrtoF(str);
      num=i;
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      getline(cin,str);
      cout<<RESET;
      CheckNum(num,str);
  }
}

void initVec(Vec& lvc,string side)
{
    float l0=0.0,l1=0.0,l2=0.0;
    string ls0="",ls1="",ls2="";
    Vec temp(3);
    lvc=temp;
    cout<<"\nPlease input the "<<YEL<<"first"<<RESET<<" float of the "<<YEL<<side<<RESET<<" vector : ";
    cout<<GRN;getline(cin,ls0);cout<<RESET;
    CheckNum(l0,ls0);
    lvc.setVal(0,l0);
    cout<<"Please input the "<<YEL<<"second"<<RESET<<" float of the "<<YEL<<side<<RESET<<" vector : ";
    cout<<GRN;getline(cin,ls1);cout<<RESET;
    CheckNum(l1,ls1);
    lvc.setVal(1,l1);
    cout<<"Please input the "<<YEL<<"third"<<RESET<<" float of the "<<YEL<<side<<RESET<<" vector : ";
    cout<<GRN;getline(cin,ls2);cout<<RESET;
    CheckNum(l2,ls2);
    lvc.setVal(2,l2);
    cout<<"The "<<YEL<<side+" vector's"<<RESET<<" numbers are : ";cout<<lvc;cout<<endl;
}

void remind1(float& lf, float& rf,string& input1)
{

    if(lf==0.0&&rf==0.0)
    {
        string left="",right="";
        cout<< "\nPlease input the left float number : ";
        cout<<GRN;getline(cin,left);cout<<RESET;
        CheckNum(lf,left);
        cout<< "Please input the right float number : ";
        cout<<GRN;getline(cin,left);cout<<RESET;
        CheckNum(rf,left);
    }
        cout<<"\nInput "<<YEL<<"'n'"<<RESET<<" to make "<<YEL<<"new floats"<<RESET<<".";
        cout<<"\nInput "<<YEL<<"'a'"<<RESET<<" to do "<<YEL<<"addition"<<RESET<<".";
        cout<<"\nInput "<<YEL<<"'s'"<<RESET<<" to do "<<YEL<<"subtraction"<<RESET<<".";
        cout<<"\nInput "<<YEL<<"'m'"<<RESET<<" to do "<<YEL<<"multiplication"<<RESET<<".";
        cout<<"\nInput "<<YEL<<"'d'"<<RESET<<" to do "<<YEL<<"division"<<RESET<<".";
        cout<<"\nInput "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<".\n";
        cout<<YEL;getline(cin,input1);cout<<RESET;

}

void remind2(Vec& lvc, Vec& rvc,string& input2)
{

    if(lvc.getSize()==0&&rvc.getSize()==0)
    {
        initVec(lvc,"left");
        initVec(rvc,"right");
    }
    cout<<"\nInput "<<YEL<<"'n'"<<RESET<<" to make "<<YEL<<"new vectors"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'a'"<<RESET<<" to do "<<YEL<<"addition"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'s'"<<RESET<<" to do "<<YEL<<"subtraction"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'m'"<<RESET<<" to do "<<YEL<<"multiplication"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'d'"<<RESET<<" to do "<<YEL<<"division"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<".\n";
    cout<<YEL;getline(cin,input2);cout<<RESET;
}

void remind3(Fraction& lf, Fraction& rf,string& input3)
{

    if(lf.getNum()==0&&rf.getNum()==0)
    {
        cout<< "\nPlease input the left fraction : <numerator>/<denominator> \n";
        cout<<GRN;lf.setFrac();cout<<RESET;
        cout<< "\nPlease input the right fraction : <numerator>/<denominator> \n";
        cout<<GRN;rf.setFrac();cout<<RESET;
    }
    cout<<"\nInput "<<YEL<<"'n'"<<RESET<<" to make "<<YEL<<"new fractions"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'a'"<<RESET<<" to do "<<YEL<<"addition"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'s'"<<RESET<<" to do "<<YEL<<"subtraction"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'m'"<<RESET<<" to do "<<YEL<<"multiplication"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'d'"<<RESET<<" to do "<<YEL<<"division"<<RESET<<".";
    cout<<"\nInput "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<".\n";
    cout<<YEL;getline(cin,input3);cout<<RESET;
}

