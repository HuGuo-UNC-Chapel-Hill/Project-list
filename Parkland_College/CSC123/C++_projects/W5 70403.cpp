#include <iostream>
using namespace std;
const int acc=32;

int main()
{
    int time,ts,ats,dist;
    cout << "Please put the number of time:"<<endl;
    cin >> time;
    ts=time*time;
    ats=acc*ts;
    dist=ats/2;
	cout << "The amount of distance is "<< dist<<" foot."<<endl;
	return 0;
}
