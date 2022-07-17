#include<iostream>
#include<ctime>
#include<time.h>
#include <cstdlib>

using namespace std;

int gamestart(int money,int& wager,int& total,int& houseRoll,bool& bust);
void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll);
int playerwin(int& money,int wager);
int housewin(int& money,int wager);
int playerwinmoney(int&money, int& wager);
void houseturn();
void newround();
int playerturnchoice(int& total);


//void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll);

int main(){

    gamestart:
    srand(time(NULL));

    //storage
    bool bust;
    char playerchoice;
    int wager, houseRoll=0,total=0,money=100;


    gamestart(money,wager,total,houseRoll,bust);



    playerTurn(money,wager,bust,total,houseRoll);

    if(bust=false){houseturn();


            do{
            cout<<"\n House's total points are "<<houseRoll<<".";
            cout<<"\n house roll less than 17 and house keep getting one card.";
            int hcard2=0;
            hcard2=rand()%11+1;
            houseRoll=houseRoll+hcard2;
            cout<<"\n house got 1 card of points "<<hcard2<<".";

            cout<<endl;
            if(houseRoll==21){
              housewin(money,wager);
            }
            }while(houseRoll<17&&houseRoll<total);

        if(houseRoll>=17 && houseRoll<21 && total<21){
                if (houseRoll>total){
                cout<<"\n House's total points are "<<houseRoll<<".";
                cout<<" Player has points of "<<total<<".";
                cout<< "\n player lose"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;
                bust=true;
                }
                else if (houseRoll=total){
                cout<<"\n Player and house have the same points";
                cout<<"\n Push"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;
                goto gamestart;}
                else if (houseRoll<total)
                playerwin(money,wager);}
        else if (houseRoll==21&&total==21){
                cout<<"\n push"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;

                goto gamestart;}
        else if(houseRoll>21){
            cout<<"\n House's total points are "<<houseRoll<<".";
            cout<<"\n player win";
             cout<<houseRoll<<"   "<<total<<endl;
                bust=true;
            return 0;
        }}

}
    //playerwin(money,wager);
    //cout<<money;
    //housewin(money,wager);
    //cout<<money;







int gamestart(int money,int& wager,int& total,int& houseRoll,bool& bust){
    srand(time(NULL));
    start:
    cin.get();
    bust=false;
    total=0;
    houseRoll=0;
    cout<<"\n Game starts.Player has "<<money<<" dollars.";
    cout<<"\n Please input the amount of wager "<<endl;
    cout<<"\n ";
    cin>>wager;
    if(wager>0&&wager<100){
    money=money-wager;
    cout<<"\n ";
    cout<<money;
    cout<<endl;
   }

    else{
    cout<<"\n Invalid Input.";
    cout<<endl;
    goto start;
    }


    //player got 2 cards at the beginning
    int proll1=rand()%11+1;
    cout<<proll1<<endl;


    int proll2=rand()%11+1;
    cout<<proll2<<endl;
    total=proll1+proll2;

    //house got 1 card at the beginning

    int hroll1=rand()%11+1;
    houseRoll=hroll1;
    cout<<hroll1<<endl;

    //output
    cout<<"\n Player put "<<wager<<" wager on the table and still has "<<money<<" dollars.";
    cout<<"\n Player got 2 cards and total points are "<<total<<".";
    cout<<"\n House got 1 card and its points are "<<houseRoll<<".";
    cout<<endl;
    cout<<total;
     playerTurn(money,wager,bust,total,houseRoll);
    if(total==21){
        playerwinmoney(money,wager);
        gamestart(money,wager,total,houseRoll,bust);
        bust=false;
    }
    else if(total>21){
        housewin(money,wager);
    }

    return money,wager,total,houseRoll;
    playerTurn(money,wager,bust,total,houseRoll);
    }

void playerTurn(int money,int& wager,bool& bust,int& total,int& houseRoll){


    playerchoice:
    char playerchoice;

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;
    if (playerchoice=='s'||playerchoice=='S'){

        bust=false;
        houseturn();
        }

    if (playerchoice=='h'||playerchoice=='H'){

    int proll3=rand()%11+1;
    total=total+proll3;
    //debugging
    //total=21;
    cout<<"\n Player chose Hit and got 1 card of points "<<proll3<<".";
    cout<<"\n Player's total points are "<<total<<".";
    cout<<endl;
    if(total<21){
    goto playerchoice;
    }
    if(total==21){
        playerwinmoney(money,wager);
        cout<<"player turn player win 21";
        gamestart(money,wager,total,houseRoll,bust);
        bust=false;}
    else if(total>21){
        bust=true;}
    if(bust){
        cout<<"\n player lose";
        cout<<endl;
        newround();
        gamestart(money,wager,total,houseRoll,bust);}



    }
}

int playerturnchoice(int& total){
    srand(time(NULL));
    char playerchoice;

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;

    if (playerchoice=='h'||playerchoice=='H'){
    int proll3=rand()%11+1;
    total=total+proll3;
    cout<<"\n Player chose Hit and got 1 card of points "<<proll3<<".";
    cout<<"\n Player's total points are "<<total<<".";

    cout<<endl;
    return total;
    }}

int playerwin(int& money,int wager){

     money=money+wager*2;
     cout<<"\n player win.";
     cout<<money;
     return money;}

int housewin(int& money,int wager){

     money=money-wager;
     cout<<"\n player lost.";
     return money;}


int dice1(int& card1){
    srand(time(NULL));

    //storage
    int number=13;
    int result,dicepoints;
    char card;

    //processing
    result=rand()%number+1;


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
    }
    card1=dicepoints;
    //cout<<"/n Player got the card of "<<card<<" for points "<<dicepoints<<". "<<endl;
    return card1;
}

int dice2(int& card2){
    srand(time(NULL));

    //storage
    int number=13;
    int result,dicepoints;
    char card;

    //processing
    result=rand()%number+1;


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
    }
    card2=dicepoints;
    //cout<<"/n Player got the card of "<<card<<" for points "<<dicepoints<<". "<<endl;
    return card2;
}

int dice3(int& card3){
    srand(time(NULL));

    //storage
    int number=13;
    int result,dicepoints;
    char card;

    //processing
    result=rand()%number+1;


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
    }
    card3=dicepoints;
    //cout<<"/n Player got the card of "<<card<<" for points "<<dicepoints<<". "<<endl;
    return card3;
}

void newround(){cout<<"this is a new round.";}

int playerwinmoney(int&money, int& wager){
money=money+wager*2;
wager=0;
return money,wager;}

void houseturn(){
cout<<"\n this is house's turn";
cout<<endl;}

void testpart1(int money,int& wager,bool& bust,int& total,int& houseRoll){

    do{

    char playerchoice;

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;
    if (playerchoice=='s'||playerchoice=='S'){
        houseturn();
        bust=false;
    }
    if (playerchoice=='h'||playerchoice=='H'){
    int proll3=rand()%11+1;
    total=total+proll3;
    cout<<"\n Player chose Hit and got 1 card of points "<<proll3<<".";
    cout<<"\n Player's total points are "<<total<<".";
    cout<<endl;
    }}while(total<21);

    if(total==21){
        playerwin(money,wager);
        cout<<"This is a new round,";
        bust=false;
    gamestart(money, wager,total, houseRoll,bust);
    }
    else if(total>21){
        housewin(money,wager);
        bust=true;
}
    if(bust){
        cout<<"player lose";}
    else{
        houseturn();
    }}
