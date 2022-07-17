//black jack


#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll);

int gamestart(int& money,int& wager,int& total,int& houseRoll,int& dicepoints);
bool playerbust(int total,bool& bust);
int playerturnchoice(int& total,bool& bust);
int dice(int& dicepoints);
//void messageplayerturn(int money,int& wager,bool& bust,int& total,int& houseRoll);
//void houseTurn(int& houseRoll,bool &bust,int& total);


int main(){


    gamestart:
    srand(time(NULL));
    //storage
    bool bust;
    char playerchoice;
    int wager, houseRoll=6,total=17,money=100,dicepoints=0;

    gamestart(money,wager,total,houseRoll,dicepoints);
    playerbustcheck:
    playerbust(total,bust);

    if(total=21){
        cout<<"Player win.";
    }



    if(total<21){
    char playerchoice;

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;

    if (playerchoice=='h'||playerchoice=='H'){
    int proll3=rand()%13+1;
    total=total+proll3;
    cout<<"\n Player chose Hit and got 1 card of points "<<proll3<<".";
    cout<<"\n Player's total points are "<<total<<".";

    cout<<endl;



    }


    if (playerchoice=='s'||playerchoice=='S'){
    cout<<"\n House's turn.";}


   }

    if(total>21)
    {
        cout<<"player lost";
    }
   // playerturnchoice(total,bust);



    //messageplayerturn(money,wager,bust,total,houseRoll);
    cout<<"\n "<<houseRoll<<" "<<total<<" "<<dicepoints<<" "<<endl;



    //playerTurn(money,wager,bust,total,houseRoll);







    cout<<cout<< "\n player"<<total<<endl;

}




void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll){
switch (bust){
case true:

money=money-wager;

cout<<"\n Player bust!!!";
cout<<"\n The points of player is "<<total<<".";
cout<<"\n The points of the house is "<<houseRoll<<".";
cout<<"\n This player lost "<<wager<< "wager, and still has "<<money;
cout<<endl;

break;
default:
cout<<"Nothing happened.";
}
}



int gamestart(int& money,int& wager,int& total,int& houseRoll,int& dicepoints){

    cout<<"\n Game starts.Player has "<<money<<" dollars.";
    cout<<"\n Please input the amount of wager "<<endl;
    cout<<"\n ";
    cin>>wager;

    if (wager>0 && wager<money){
    money=money-wager;
    cout<<"\n ";
    cout<<money;
    cout<<endl;}

    else{
    cout<<"\n Invalid Input.";
    cout<<endl;
    gamestart(money,wager,total,houseRoll,dicepoints);
    }
    //cout<<endl;

    //money=money-wager;
    //cout<<"\n ";
    //cout<<money;
    //cout<<endl;

    //player got 2 cards at the beginning
    int proll1;
    dice(proll1);
    cout<<proll1<<endl;
    int proll2;
    dice(proll2);
    cout<<proll2<<endl;
    total=proll1+proll2;

    //house got 1 card at the beginning
    int hroll1=rand()%13+1;
    cout<<hroll1<<endl;

    //output
    cout<<"\n Player put "<<wager<<" on the table and still has "<<money<<" dollars.";
    cout<<"\n Player got 2 cards and total points are "<<total<<".";
    cout<<"\n House got 1 card and its points are "<<houseRoll<<".";
    cout<<endl;

    return money,wager,total,houseRoll;}



bool playerbust(int total,bool& bust){

    //check buts
    if(total<21)

        return false;
    if(total=21){
        cout<<"player win."
        return false;}

    if(total>21){

        return true;
        cout<<"player lost";
}}


int playerturnchoice(int& total,bool& bust){

    char playerchoice;

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;

    if (playerchoice=='h'||playerchoice=='H'){
    int proll3=rand()%13+1;
    total=total+proll3;
    cout<<"\n Player chose Hit and got 1 card of points "<<proll3<<".";
    cout<<"\n Player's total points are "<<total<<".";

    cout<<endl;



    }


    if (playerchoice=='s'||playerchoice=='S'){
    cout<<"\n House's turn.";}


   }

int dice(int& dicepoints){
  srand(time(NULL));
    //storage
    int number=13;
    int result;

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
    //cout<<"/n Player got the card of "<<card<<" for points "<<dicepoints<<". "<<endl;
    return dicepoints;
}

