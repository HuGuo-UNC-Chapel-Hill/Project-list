#include "Trips.h"

typedef Trips *TripsPtr;
const int num=10;
void initia(TripsPtr array);
void List(TripsPtr t);
void Choice(TripsPtr t,string temp);
void remind(string& input);

int main()
{
  float time=0;
  Trips array[num];
  TripsPtr trips=array;
  initia(trips);
  string choice;
  do
  {
      cout<<endl;
      List(trips);
      cout<<YEL<<"Please input the number of the city ("<<GRN<<"0-9"<<YEL<<"): "<<GRN<<endl;
      cin>>choice;
      cout<<RESET;
      Choice(trips,choice);
      cout<<"\nTry more or quit the program?"<<endl;
      cout<<"(press y to try more or press n to quit)"<<GRN<<endl;
      cin>>choice;
      cout<<RESET;
      remind(choice);
  }while(choice=="y"||choice=="Y");

    return 0;

}

void initia(TripsPtr array)
{
     array[0].setCity("Champaign, IL");
     array[0].setDistance(136);
     array[1].setCity("Indianapolis, IN");
     array[1].setDistance(182);
     array[2].setCity("Detroit, MI");
     array[2].setDistance(281);
     array[3].setCity("St Louis, MO");
     array[3].setDistance(297);
     array[4].setCity("Kansas City, MO");
     array[4].setDistance(510);
     array[5].setCity("Washington, D.C.");
     array[5].setDistance(699);
     array[6].setCity("New York, NY");
     array[6].setDistance(791);
     array[7].setCity("Dalls, TX");
     array[7].setDistance(967);
     array[8].setCity("Denver, CO");
     array[8].setDistance(1002);
     array[9].setCity("Los Angeles, CA");
     array[9].setDistance(2060);
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

void Choice(TripsPtr t,string temp)
{
    float time;
    stringstream s;
    s<<temp;
    int i;
    s>>i;
    t[i].Output();
    time=t[i].getTime();
    //cout<<time;
    cout<<endl;
    cout<<YEL<<"Your travel time is : "<<GRN<<(unsigned int)time<<YEL<<" hours ";
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
