#include "Trips.h"

typedef Trips *TripsPtr;
const int num=10;
void initialization(TripsPtr trips);
void initia(TripsPtr array);
void List(TripsPtr t);
void check(int& x);
void timer(float time,float speed);
void remind(string& input);

int main()
{
  float time=0,speed=0;
  int x;
  Trips array[num];
  TripsPtr trips=array;
  initialization(trips);
  string choice;
  do
  {
      cout<<endl;
      List(trips);
      cout<<YEL<<"Please input the number of the city ("<<GRN<<"0-9"<<YEL<<"): "<<GRN<<endl;
      cin>>x;
      cout<<RESET;      
      check(x);
      array[x].Output();
      speed=array[x].getSpeed();
      time=array[x].getTime(speed);
      timer(time,speed);
      cout<<"\nTry more or quit the program?"<<endl;
      cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
      cin>>choice;
      cout<<RESET;
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
    trips[7]=Trips("Dalls, TX",967);
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
        cout<<" "<<setw(3)<<i<<setw(20)<<t[i].getCity()<<t[i].getDistance()<<endl;
    }
    cout<<"---------------------------------------\n";
    cout<<RESET;
}

void check(int& x)
{ 
  while(x>9||x<0)
  {
    cout<<RED<<"Invalid input, please re-input.\n";
    cout<<YEL<<"Please input the number of the city (";
    cout<<GRN<<"0-9"<<YEL<<"): "<<GRN<<endl;
    cin>>x;
    cout<<RESET;
    check(x);
  }
}

void timer(float time, float speed)
{
    cout<<endl;
    cout<<YEL<<"Your travel speed is : "<<GRN<<speed<<YEL<<" miles/hour.\n";
    cout<<"Your travel time is : "<<GRN<<(unsigned int)time<<YEL<<" hours ";
    cout<<GRN<<int(60*(time-(int)time))<<YEL<<" mins"<<endl;
    cout<<RESET;
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
