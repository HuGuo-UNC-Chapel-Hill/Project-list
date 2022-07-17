#include "Fraction.h"
#include "Vector.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

//choice menu
void Choice(string& choice);

// transforming string to integer or float
void CheckNum(float& num,string& str);

//prompting for choice 1
void remind1(float& lf, float& rf,string &input1);

//prompting for choice 2
void remind2(Vec& lf, Vec& rf,string &input2);

//initial the object for vector class
void initVec(Vec& lvc, string side);

//prompting for choice 3
void remind3(Fraction& lf, Fraction& rf,string& input3);

//the size of the vector
const int size=3;

int main()
{
    //set the decimal place
    std::cout << std::fixed;
    std::cout << std::setprecision(1);

    //declarations
    float lf=0.0,rf=0.0;
    Fraction leftf,rightf;
    Vec lvc,rvc;

    //debug
    //lvc.getMem(0);

    cout<<YEL<<"\n-------------------------------------------\n";
    cout<<GRN<<"Welcome to use the multi-purpose calculator\n";
    cout<<YEL<<"-------------------------------------------"<<RESET;

    //loop for the choice menu
    while(1)
    {    
        string choice;  
        
        //choice menu
        Choice(choice);
      
        //choice 1
        if(choice=="1")
        {

            string input1;

            //prompting
            cout<<GRN<<"\nFloat point calculator"<<RESET;
            if(lf!=0.0&&rf!=0.0)
            {
                cout<< "\nThe "<<YEL<<"left"<<RESET<<" float number is "<<GRN<<lf<<RESET<<endl;
                cout<< "The "<<YEL<<"right"<<RESET<<" float number is "<<GRN<<rf<<RESET<<endl;
            }

            //loop for choice 1
            while(1)
            {
                //prompting for choice 1
                remind1(lf,rf,input1);

                //choice to input new float numbers
                if(input1=="n")
                {
                    string left="",right="";
                    cout<< "\nPlease input the "<<YEL<<"left"<<RESET<<" float number : ";
                    cout<<GRN;getline(cin,left);cout<<RESET;
                    CheckNum(lf,left);
                    cout<< "Please input the "<<YEL<<"right"<<RESET<<" float number : ";
                    cout<<GRN;getline(cin,left);cout<<RESET;
                    CheckNum(rf,left);

                }

                //choice to do addition
                else if(input1=="a")
                {
                    cout<<GRN<<"\nFloat point addtion :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" float number is "<<GRN<<rf<<RESET<<endl;
                    float sum=lf+rf;
                    cout<<endl<<GRN<<lf<<RESET<<" + "<<GRN<<rf<<RESET<<" = "<<GRN<<sum<<RESET<<endl;
                }

                //choice to do subtraction
                else if(input1=="s")
                {
                    cout<<GRN<<"\nFloat point subtraction :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" float number is "<<GRN<<rf<<RESET<<endl;
                    float dif=lf-rf;
                    cout<<endl<<GRN<<lf<<RESET<<" - "<<GRN<<rf<<RESET<<" = "<<GRN<<dif<<RESET<<endl;
                }

                //choice to do multiplication
                else if(input1=="m")
                {
                    cout<<GRN<<"\nFloat point multiplication :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" float number is "<<GRN<<rf<<RESET<<endl;
                    float pro=lf*rf;
                    cout<<endl<<GRN<<lf<<RESET<<" * "<<GRN<<rf<<RESET<<" = "<<GRN<<pro<<RESET<<endl;
                }

                //choice to do division
                else if(input1=="d")
                {
                    cout<<GRN<<"\nFloat point division :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" float number is "<<GRN<<lf<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" float number is "<<GRN<<rf<<RESET<<endl;
                    float quo=lf/rf;
                    cout<<endl<<GRN<<lf<<RESET<<" / "<<GRN<<rf<<RESET<<" = "<<GRN<<quo<<RESET<<endl;
                }

                //choice to break the loop
                else if(input1=="b"||input1=="B"){break;}

                //condition for the wrong inputing strings
                else
                {
                    cout<<RED<<"Invalid input, please re-input."<<RESET;
                }
            }
        }

        else if(choice=="2")
        {

            string input2;

            //prompting
            cout<<GRN<<"\nVector calculation calculator"<<RESET;
            if(lvc.getSize()!=0&&rvc.getSize()!=0)
            {
                cout<< "\nThe "<<YEL<<"left"<<RESET<<" vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                cout<< "The "<<YEL<<"right"<<RESET<<" vector numbers are : "<<GRN<<rvc<<RESET<<endl;
            }

            //loop for choice 2
            while(1)
            {
                //prompting for choice 2
                remind2(lvc,rvc,input2);

                //choice to make new objects for vector class
                if(input2=="n")
                {
                     initVec(lvc,"left");
                     initVec(rvc,"right");
                }

                //choice to do addition
                else if(input2=="a")
                {
                    cout<<GRN<<"\nVector addtion :"<<RESET;
                    cout<<"\n"<<setw(7)<<" "<< "The "<<YEL<<"left"<<RESET<<" vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                    cout<<setw(6)<<" "<<"The "<<YEL<<"right"<<RESET<<" vector numbers are : "<<GRN<<rvc<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator + =
                    Vec sum=lvc+rvc;

                    cout<<setw(35)<<" ";
                    for(int i=0;i<size;i++)
                        cout<<"-------";
                    cout<<"\nThe "<<YEL<<"left"<<RESET<<" vector + the "<<YEL<<"right"<<RESET<<" vector = ";

                    //overloaded operator <<
                    cout<<sum<<endl;
                }

                //choice to do subtraction
                else if(input2=="s")
                {
                    cout<<GRN<<"\nVector subtraction :"<<RESET;
                    cout<<"\n"<<setw(7)<<" "<< "The "<<YEL<<"left"<<RESET<<" vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                    cout<<setw(6)<<" "<<"The "<<YEL<<"right"<<RESET<<" vector numbers are : "<<GRN<<rvc<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator - =
                    Vec dif=lvc-rvc;

                    cout<<setw(35)<<" ";
                    for(int i=0;i<size;i++)
                        cout<<"-------";
                    cout<<"\nThe "<<YEL<<"left"<<RESET<<" vector - the "<<YEL<<"right"<<RESET<<" vector = ";

                    //overloaded operator <<
                    cout<<dif<<endl;
                }

                //choice to do multiplication
                else if(input2=="m")
                {
                    cout<<GRN<<"\nVector multiplication :"<<RESET;
                    cout<<"\n"<<setw(7)<<" "<< "The "<<YEL<<"left"<<RESET<<" vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                    cout<<setw(6)<<" "<<"The "<<YEL<<"right"<<RESET<<" vector numbers are : "<<GRN<<rvc<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator * =
                    Vec pro=lvc*rvc;

                    cout<<setw(35)<<" ";
                    for(int i=0;i<size;i++)
                        cout<<"-------";
                    cout<<"\nThe "<<YEL<<"left"<<RESET<<" vector * the "<<YEL<<"right"<<RESET<<" vector = ";

                    //overloaded operator <<
                    cout<<pro<<endl;
                }

                //choice to do division
                else if(input2=="d")
                {
                    cout<<GRN<<"\nVector division :"<<RESET;
                    cout<<"\n"<<setw(7)<<" "<< "The "<<YEL<<"left"<<RESET<<" vector numbers are : "<<GRN<<lvc<<RESET<<endl;
                    cout<<setw(6)<<" "<<"The "<<YEL<<"right"<<RESET<<" vector numbers are : "<<GRN<<rvc<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator / =
                    Vec quo=lvc/rvc;

                    cout<<setw(35)<<" ";
                    for(int i=0;i<size;i++)
                        cout<<"-------";
                    cout<<"\nThe "<<YEL<<"left"<<RESET<<" vector / the "<<YEL<<"right"<<RESET<<" vector = ";

                    //overloaded operator <<
                    cout<<quo<<endl;

                }

                //choice to break the loop
                else if(input2=="b"||input2=="B"){break;}

                //condition for the wrong input string
                else
                {
                    cout<<RED<<"Invalid input, please re-input."<<RESET;
                }
            }
        }


        else if(choice=="3")
        {
            string input3;

            //prompting
            cout<<GRN<<"\nFractions calculator"<<RESET;
            if(leftf.getNum()!=0&&rightf.getNum()!=0)
            {
                cout<< "\nThe "<<YEL<<"left"<<RESET<<" fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                cout<< "The "<<YEL<<"right"<<RESET<<" fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;
            }

            while(1)
            {
                //prompting for choice3
                remind3(leftf,rightf,input3);

                //choice to make new objects for Fraction class
                if(input3=="n")
                {
                    cout<< "\nPlease input the "<<YEL<<"left"<<RESET<<" fraction : <numerator>/<denominator> \n";
                    cout<<GRN;leftf.setFrac();cout<<RESET;
                    cout<< "\nPlease input the "<<YEL<<"right"<<RESET<<" fraction : <numerator>/<denominator> \n";
                    cout<<GRN;rightf.setFrac();cout<<RESET;
                }

                //choice to do addition
                else if(input3=="a")
                {
                    cout<<GRN<<"\nFraction addition :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator + 
                    Fraction sum=leftf+rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " + ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";

                    //overload the operator <<
                    cout<<sum<<endl;
                }

                //choice to do subtraction
                else if(input3=="s")
                {
                    cout<<GRN<<"\nFraction subtraction :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator - 
                    Fraction dif=leftf-rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " - ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";

                    //overload the operator <<
                    cout<<dif<<endl;
                }

                //choice to do multiplication
                else if(input3=="m")
                {
                    cout<<GRN<<"\nFraction multiplication :"<<RESET;
                    cout<<"\n"<< "\nThe "<<YEL<<"left"<<RESET<<" fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    //overloaded copy constructor and overloaded operator * 
                    Fraction pro=leftf*rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " * ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";

                    //overload the operator <<
                    cout<<pro<<endl;
                }

                //choice to do division
                else if(input3=="d")
                {
                    cout<<GRN<<"\nFraction division :"<<RESET;
                    cout<< "\nThe "<<YEL<<"left"<<RESET<<" fraction is "<<GRN;leftf.Print();cout<<RESET<<endl;
                    cout<< "The "<<YEL<<"right"<<RESET<<" fraction is "<<GRN;rightf.Print();cout<<RESET<<endl;

                    ////overloaded copy constructor and overloaded operator / 
                    Fraction quo=leftf/rightf;

                    cout<<"\n"<<GRN;leftf.Print(); cout<<RESET; cout << " / ";
                    cout<<GRN;rightf.Print(); cout<<RESET; cout << " = ";

                    //overload the operator <<
                    cout<<quo<<endl;
                }

                //choice to break the loop
                else if(input3=="b"||input3=="B"){break;}

                //condition for the wrong input string
                else
                {
                    cout<<RED<<"Invalid input, please re-input."<<RESET;
                }
            }
        }
        
        //exit the program
        else if(choice=="4")
        {
         exit (-1);
        }
        
        //condition for the worng input string
        else
        {
            cout<<RED<<"Invalid input, please re-input."<<RESET;
        }
        
    }

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
}

// transforming string to integer or float
void CheckNum(float& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
      float i=0.0;
      stringstream temp;
      temp<<str;
      temp>>i;
      num=i;
  }
  else
  {
      cout<<RED<<"Invaliad input, please re-input :";
      cout<<GRN;getline(cin,str);cout<<RESET;
      CheckNum(num,str);
  }
}

//initial the object for vector class
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

//prompting for choice 1
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

//prompting for choice 2
void remind2(Vec& lvc, Vec& rvc,string& input2)
{  
    //condition for empty dynamic vector
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

//prompting for choice 3
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

