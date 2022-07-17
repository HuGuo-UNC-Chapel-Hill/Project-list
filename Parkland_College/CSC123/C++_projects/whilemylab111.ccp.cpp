// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{int FIRST_YEAR=1990,LAST_YEAR=1995;
    double oil=4343.434;
int counter;
counter=FIRST_YEAR;
while(counter<=LAST_YEAR){
	cout << counter <<": "<<oil<<endl;
	counter++;
	oil*=1.2;
}
	return 0;
}
