#include "Array.h"

void random(Array &a);

void Choice(string& choice);

int StrtoI(string input);

float StrtoF(string input);

void CheckNum(float& num,string& str);

void CheckNum(int& num,string& str);

void CheckChoice(string& choice);

void random(Array &a);

void remind(string& input);

int main()
{
    
    string choice;
    
    cout<<GRN<<"\n--------------------------------------------\n";
    cout<<YEL<<"Welcome to use the shape calculator for lab8\n";
    cout<<GRN<<"--------------------------------------------\n"<<RESET;   
    Choice(choice);

    for(int i=1;i<2;)
    {
        if(choice=="1")
        {

            do
            {  
                float a=0.0,b=0.0;
                string sa="",sb="",input1="";
                cout<<"\n Please input the number of "<<YEL<<"width"<<RESET<<" for the rectangle : ";
                cout<<GRN<<" ";getline(cin,sa);cout<<RESET;
                CheckNum(a,sa);
                
                cout<<"\n Please input the number of "<<YEL<<"length"<<RESET<<" for the rectangle : ";
                cout<<GRN<<" ";getline(cin,sb);cout<<RESET;
                CheckNum(a,sb);
                
                Rectangle r=Rectangle(a,b);
                r.setArea();
                cout<<r;

                cout<<endl<<"\n Try more or quit the program?";
                cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "<<YEL<<"more"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "
                    <<YEL<<"main menu"<<RESET<<"."<<endl;
                cout<<YEL<<" ";getline(cin,input1);cout<<RESET;
                remind(input1);
                if(input1=="b"||input1=="B"){break;}

            }while(input1=="y"||input1=="Y");

           Choice(choice);

        }

        if(choice=="2")
        {

            int size=0;
            float fl=0.0;
            string s,f,input2;

            do
            {

                cout<<"\n Please input the number of "<<YEL<<"size"<<RESET<<" for "<<YEL<<"operand array"<<RESET<<" : ";
                cout<<GRN;getline(cin,s);cout<<RESET;
                CheckNum(size,s);

                Array operand(size);
                random(operand);

                cout<<setw(9)<<" "<<" Please input the "<<YEL<<"float"<<RESET<<" number : ";
                cout<<GRN;getline(cin,f);cout<<RESET;
                CheckNum(fl,f);

                cout<<"\n  The "<<YEL<<"operand array"<<RESET<<" has "<<GRN<<size<<RESET<<" elements : ";
                cout<<GRN<<operand<<RESET;

                Array test(size);

                 test=operand+fl;

                cout<<"\n"<<setw(36)<<" ";
                for(int i=0;i<size;i++)
                    cout<<"------";

                cout<<"\n    The "<<YEL<<"operand array"<<RESET<<" + the "<<YEL<<"float"<<RESET<<"  = ";
                cout<<GRN<<test<<RESET;

                //debug
                //cout<<"\n";test.getMem(0); cout<<" ";operand.getMem(0);

                cout<<endl<<"\n Try more or quit the program?";
                cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "<<YEL<<"more"<<RESET<<".";
                cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<"."<<endl;
                cout<<YEL<<" ";getline(cin,input2);cout<<RESET;
                remind(input2);
                if(input2=="b"||input2=="B"){break;}

            }while(input2=="y"||input2=="Y");

           Choice(choice);

        }

        if(choice=="4")
        {
            exit (-1);
        }


    }


    return 0;
}



//showing the choice menu
void Choice(string& choice)
{
  cout<<" Enter any of the following commands:\n";
  cout<<setw(8)<<" "<<"1) Rectangle calculation\n";
  cout<<setw(8)<<" "<<"2) Triangle calculation\n";
  cout<<setw(8)<<" "<<"3) Circle calculation\n";
  cout<<setw(8)<<" "<<"4) Exit\n";
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

void CheckNum(int& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    float i=StrtoI(str);
    if(i<0)
    {
      cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      getline(cin,str);
      cout<<RESET;
      CheckNum(num,str);
    }
    else
    {
      num=i;
    }
  }
  else
  {
    cout<<RED<<"Invaliad input, please re-input :"<<GRN;
      getline(cin,str);
      cout<<RESET;
      CheckNum(num,str);
  }
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

void random(Array &a)
{
    float num=0.0;
    for(int i=0;i<a.getSize();i++)
    {
        num=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/99.9));
        a.setVal(i,num);
    }
}

//checking for the loop
void remind(string& input)
{
    while(input!="Y"&&input!="y"&&input!="b"&&input!="B")
    {
        cout<<"\n Invalid input, please re-input"<<endl;
        cout<<" Try more or quit the program?";
        cout<<"\n Input "<<YEL<<"'y'"<<RESET<<" to try "<<YEL<<"more"<<RESET<<".";
        cout<<"\n Input "<<YEL<<"'b'"<<RESET<<" to back to the "<<YEL<<"main menu"<<RESET<<"."<<endl;
        cout<<YEL<<" ";getline(cin,input);cout<<RESET;
    }
}

