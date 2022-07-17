#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
   srand(time(NULL));
    //storage
    int number=13;
    int result;
    int dicepoints=0;
    int i=1;
    char card;

    //processing
    result=rand()%number+1;

do{
  //switch
    switch(result){
    case (1)://ACE
    dicepoints=11;
    card='Ace';
    break;
    case (2):
    dicepoints=2;
    card='Two';
    break;
    case (3):
    dicepoints=3;
    card='Three';
    break;
    case (4):
    dicepoints=4;
    card='Four';
    break;
    case (5):
    dicepoints=5;
    card='Five';
    break;
    case (6):
    dicepoints=6;
    card='Six';
    break;
    case (7):
    dicepoints=7;
    card='Seven';
    break;
    case (8):
    dicepoints=8;
    card='Eight';
    break;
    case (9):
    dicepoints=9;
    card='Nine';
    break;
    case (10):
    dicepoints=10;
    card='Ten';
    break;
    case (11)://Q
    dicepoints=10;
    card='Q';
    break;
    case (12)://J
    dicepoints=10;
    card='J';
    break;
    case (13)://K
    dicepoints=10;
    card='K';
    break;
    case (14)://ACE
    dicepoints=14;
    card='Ace';
    break;
    }}while(i<0);
    cout<<"/n Player got the card of "<<card<<" for points "<<dicepoints<<". "<<endl;
    return dicepoints;
}
