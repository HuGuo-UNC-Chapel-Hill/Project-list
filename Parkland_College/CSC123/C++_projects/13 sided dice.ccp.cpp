#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(NULL));

    int number=13;
    int result;
    int diceside=0;
    result=rand()%number+1;


    switch(result){
    case (1):
    diceside=11;
    break;
    case (2):
    diceside=2;
    break;
    case (3):
    diceside=3;
    break;
    case (4):
    diceside=4;
    break;
    case (5):
    diceside=5;
    break;
    case (6):
    diceside=6;
    break;
    case (7):
    diceside=7;
    break;
    case (8):
    diceside=8;
    break;
    case (9):
    diceside=9;
    break;
    case (10):
    diceside=10;
    break;
    case (11):
    diceside=10;
    break;
    case (12):
    diceside=10;
    break;
    case (13):
    diceside=10;
    break;
    case (14):
    diceside=14;
    break;
    }
    cout<<diceside;


}
