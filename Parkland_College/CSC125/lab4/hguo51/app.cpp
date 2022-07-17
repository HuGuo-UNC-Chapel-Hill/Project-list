#include "Trips.h"

//define the pointer of the class
typedef Trips *TripsPtr;

//set index of the array
const int num=10;

//initialization the array of the class
void initialization(TripsPtr trips);

//printout the array of the class
void List(TripsPtr t);

//translate the string to int
int StrtoInt(string temp);

//check the string and assign to the index of the array
void CheckNum(int& num,string& str);

//remind for the loop
void remind(string& input);

int main()
{
  //declaration of variables
  float time=0,speed=0;
  int x;
  string choice;

  //instantiate the class
  Trips array[num];

  //assign the instantiation to the pointer
  TripsPtr trips=array;

  ////initialization the array of the class
  initialization(trips);

  do
  {
      //printout the array
      List(trips);

      //input the choice for the index of the array
      cout<<YEL<<"Please input the number of the city ("<<GRN<<"1-10"<<YEL<<"): "<<GRN<<endl;
      cin>>choice;
      cin.ignore();
      cout<<RESET;

      //check the input
      CheckNum(x,choice);

      //input the speed of trips
      speed=array[x].getSpeed();

      //calculate the time and output the it
      array[x].getTime(speed);

      //prompting for the loop
      cout<<"\nTry more or quit the program?"<<endl;
      cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
      cin>>choice;
      cout<<RESET;

      //remind for the loop
      remind(choice);

  }while(choice=="y"||choice=="Y");

    return 0;

}

void initialization(TripsPtr trips)
{
    trips[0]=Trips("Champaign, IL",136);
    trips[1]=Trips("Indianapolis, IN",182);
    trips[2]=Trips("Detroit, MI",281);
    trips[3]=Trips("St Louis, MO",297);
    trips[4]=Trips("Kansas City, KS",529);
    trips[5]=Trips("Washington, D.C.",699);
    trips[6]=Trips("New York, NY",791);
    trips[7]=Trips("Dallas, TX",967);
    trips[8]=Trips("Denver, CO",1002);
    trips[9]=Trips("Los Angeles, CA",2060);
}

void List(TripsPtr t)
{
    cout.setf(ios::left);
    cout<<GRN;
    cout<<"---------------------------------------\n";
    cout<<setw(4)<<"No."<<setw(18)<<"City & State"<<"Distance"<<endl;
    cout<<"---------------------------------------\n";
    for(int i=0;i<num;++i)
    {
        cout<<" "<<setw(3)<<i+1<<setw(20)<<t[i].getCity()<<t[i].getDistance()<<endl;
    }
    cout<<"---------------------------------------\n";
    cout<<RESET;
}

int StrtoInt(string temp)
{
    int i;
    stringstream s;
    s<<temp;
    s>>i;
    return i;
}

void CheckNum(int& num,string& str)
{
  if(isdigit(str[0])||isdigit(str[1]))
  {
    int i=StrtoInt(str);
    if(i<1||i>10)
    {
      cout<<RED<<"Invalid input, please re-input :"<<GRN;
      cin>>str;
      cin.ignore();
      cout<<RESET;
      CheckNum(num,str);
    }
    else
    {
      num=i-1;
    }
  }
  else
  {
    cout<<RED<<"Invalid input, please re-input :"<<GRN;
      cin>>str;
      cin.ignore();
      cout<<RESET;
      CheckNum(num,str);
  }
}

void remind(string& input)
{
    if(input=="n"||input=="N")
    {
        exit(-1);
    }
    while(input!="Y"&&input!="y"&&input!="n"&&input!="N")
    {
        cout<<"\nInvalid input, please re-input"<<endl;
        cout<<"Try more or quit the program?"<<endl;
        cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
        cin>>input;
	cout<<RESET;
    }
}


