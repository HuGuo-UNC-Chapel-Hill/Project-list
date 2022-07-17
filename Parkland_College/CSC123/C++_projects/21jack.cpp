#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int playerwin(int& money,int wager);
int housewin(int& money,int wager);
int gamestart(int& money,int& wager,int& total,int& houseRoll);

int main(){

    gamestart:
    srand(time(NULL));

    //storage
    bool bust;
    char playerchoice;
    int wager, houseRoll=6,total=0,money=100;
    int card1,card2,card3,card4;

    gamestart(money,wager,total,houseRoll);
    //dice1(card1);

do{

    playerchoice:

    cout<<"\n Player Turn, please choose Hit or Stand";
    cout<<"\n (h to Hit or s to Stand)";
    cin>>playerchoice;
    cout<<endl;
    if (playerchoice=='s'||playerchoice=='S'){
        goto houseturn;
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
        return 0;
    }
    else if(total>21){
        housewin(money,wager);
        return 0;
    }

    houseturn:

            cin.get();

            do{

            cout<<"\n house roll less than 17 and house must Hit one more time";
            int hcard2=0;
            hcard2=rand()%11+1;
            houseRoll=houseRoll+hcard2;
            cout<<"\n house got 1 card of points "<<hcard2<<".";
            cout<<"House's total points are "<<houseRoll<<".";
            if(houseRoll==21){
              housewin(money,wager);
            }
            }while(houseRoll<17&&houseRoll<total);

        if(houseRoll>=17 && houseRoll<21 && total<21){
                if (houseRoll>total){
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
                goto playerchoice;}
        else if (houseRoll==21&&total==21){
                cout<<"\n push"<<endl;
                cout<<houseRoll<<"   "<<total<<endl;
                goto gamestart;}
        else if(houseRoll>21){
            cout<<"\n player win";
             cout<<houseRoll<<"   "<<total<<endl;
                bust=true;
            return 0;
        }

}

int playerwin(int& money,int wager){

     money=money+wager*2;
     cout<<"\n player win.";
     cout<<money;
     return money;}

int housewin(int& money,int wager){

     money=money-wager;
     cout<<"\n player lost.";
     return money;}

int gamestart(int& money,int& wager,int& total,int& houseRoll){
    srand(time(NULL));
    cout<<"\n Game starts.Player has "<<money<<" dollars.";
    cout<<"\n Please input the amount of wager "<<endl;
    cout<<"\n ";
    cin>>wager;
    if(wager>0&&wager<100){
    money=money-wager;
    cout<<"\n ";
    cout<<money;
    cout<<endl;}

    else{
    cout<<"\n Invalid Input.";
    cout<<endl;

    }


    //player got 2 cards at the beginning
    int proll1=rand()%11+1;
    cout<<proll1<<endl;

    srand(time(NULL));
    int proll2=rand()%11+1;
    cout<<proll2<<endl;
    total=proll1+proll2;

    //house got 1 card at the beginning
    srand(time(NULL));
    int hroll1=rand()%11+1;
    houseRoll=hroll1;
    cout<<hroll1<<endl;

    //output
    cout<<"\n Player put "<<wager<<" wager on the table and still has "<<money<<" dollars.";
    cout<<"\n Player got 2 cards and total points are "<<total<<".";
    cout<<"\n House got 1 card and its points are "<<houseRoll<<".";
    cout<<endl;
    cout<<total;
    if(total==21){
        playerwin(money,wager);
    }
    else if(total>21){
        housewin(money,wager);
    }

    return money,wager,total,houseRoll;
    }


