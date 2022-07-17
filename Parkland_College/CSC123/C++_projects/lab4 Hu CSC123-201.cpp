//black jack


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll);
int diceside();
void messageplayerturn(int money,int& wager,bool& bust,int& total,int& houseRoll);
void houseTurn(int& houseRoll,bool &bust,int& total);

int main(){
    gamestart:

    //storage
    bool bust;
    char playerchoice;
    int wager, houseRoll=6,total=17,dice=diceside(),money=100;
    cout<<"\n "<<houseRoll<<" "<<total<<" "<<diceside();

    //player input the wager
    cout<<"\n Game starts. Please input the amount of wager "<<endl;
    cout<<"\n ";
    cin>>wager;
    cout<<endl;


    money=money-wager;
    cout<<"\n ";
    cout<<money;
    cout<<endl;

    //playerTurn(money,wager,bust,total,houseRoll);
    messageplayerturn(money,wager,bust,total,houseRoll);




   cout<<"\n Player Turn, please choose Hit or Stand";
   cout<<"\n (h to Hit or s to Stand)";
   cin>>playerchoice;
   cout<<endl;

   if(playerchoice=='h' || playerchoice=='H'){
    playerturn:

    total=total+dice;
    //check buts
    if(total<=21)
        goto houseturn;
        bust=false;
    if(total>21){
    cout<< "\n player lose"<<endl;
        bust=true;
    return 0;}

    }

    cout<<cout<< "\n player"<<total<<endl;

    if(playerchoice=='s' || playerchoice=='S'){
            houseturn:
            houseRoll=houseRoll+dice;
        while(houseRoll<17){
            houseRoll=houseRoll+dice;
            cout<<"\n house roll less than 17 and house must Hit one more time"; }

        if(houseRoll>=17 && houseRoll<21 && total<21){
                if (houseRoll>total){
                cout<< "\n player lose house turn"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;
                bust=true;
                }
                else if (houseRoll=total){
                cout<<"\n push"<<endl;
                goto gamestart;}
                else if (houseRoll<total)
                goto playerturn;}
        else if (houseRoll=total=21){
                cout<<"\n push"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;
                goto gamestart;}
        else if(houseRoll>21){
            cout<<"\n player win";
                bust=true;
            return 0;
        }



}
}

int diceside(){
    srand(time(NULL));

    int number=13;
    int result;
    int diceside=0;
    result=rand()%number+1;


    switch(result){
    case (1)://ACE
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
    case (11)://Q
    diceside=10;
    break;
    case (12)://J
    diceside=10;
    break;
    case (13)://K
    diceside=10;
    break;
    case (14)://ACE
    diceside=14;
    break;
    }
    return diceside;
}


void messageplayerturn(int money,int& wager,bool& bust,int& total,int& houseRoll){
switch (bust){
case false:
cout<<"\n This player has "<<money<<" dollars, and "<< wager<< " wager.";
cout<<"\n The points of the player is "<<total<<".";
cout<<"\n The points of the house is "<<houseRoll<<".";
cout<<endl;
break;
case true:
cout<<"\n The points of player is "<<total<<".";
cout<<"\n The points of the house is "<<houseRoll<<".";
cout<<"\n This player lost "<<wager<< "wager, and still has "<<money;
cout<<endl;
break;
}
}

void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll);


