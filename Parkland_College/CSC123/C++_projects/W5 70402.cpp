#include <iostream>
using namespace std;

int main()
{
    int q,d,n,money;
    cout << "Please put the number of quarters:"<<endl;
    cin >> q;
    cout << "Please put the number of dimes:"<<endl;
    cin >> d;
    cout << "Please put the number of nickels:"<<endl;
    cin >> n;
    money=25*q+10*d+5*n;
	cout << "The amount of money is "<< money <<" cents."<<endl;
	return 0;
}
