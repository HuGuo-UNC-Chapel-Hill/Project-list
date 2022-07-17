#include <iostream>
using namespace std;

int main()
{   //storage
    int sticks=23,userpickingup,compickingup;

    cout << "Let us play 23 with the computer. You can pick 1 from 3 sticks each turn. ";

    do{
    //user turn
    //condition for user losing
    if(sticks==1)
    cout << "\nThere is the last stick.  You lose.";
    else{
    userinput:
    cout << "\nYour turn.  How many sticks do you wish to take:  ";
    cin >> userpickingup;

        //control the sticks which user picks up in 1 from 3
        if(userpickingup<1 || userpickingup>3){
        cout << "\nYou only can pick 1 from 3 sticks. Please pick again.";
        goto userinput;}
    }

    //processing
    sticks=sticks - userpickingup;
    compickingup = 4-userpickingup;

    //computer turn
    //avoid computer picks up negative number at the last turn
    if(compickingup>sticks)
    {
    cout << "\nThere are now ";
    cout << sticks;
    cout << " sticks left." << endl;

    cout << "\nComputer's turn.  Computer chooses ";
    cout << sticks;
    cout << " sticks." << endl;}

    //computer turn
    //avoid computer picks up negative number at the last turn
    if(compickingup<sticks && sticks>4)
    {
    cout << "\nThere are now ";
    cout << sticks;
    cout << " sticks left." << endl;

    cout << "\nComputer's turn.  Computer chooses ";
    cout << compickingup;
    cout << " sticks." << endl;}

    //computer turn
    //avoid computer picks up negative number at the last turn
    if(compickingup<=sticks && sticks<4)
    {
    cout << "\nThere are now ";
    cout << compickingup;
    cout << " sticks left." << endl;

    cout << "\nComputer's turn.  Computer chooses ";
    cout << sticks;
    cout << " sticks." << endl;}

    sticks= sticks - compickingup;

    //computer's turn
    //the condition computer lose
    if(sticks <= 1)
    cout << "\nThe Computer chooses the last stick.  You Win."<<endl;
    else{
    cout << "\nThere are now ";
    cout << sticks;
    cout << " sticks left." << endl;}
    }while(sticks > 0);

    return 0;

}
