/**********************************
Author:     Hu Guo
Date:       02/26/2019
Name:       Lab3 A.cpp
Description:   goat and money game
***********************************************/
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main()
{
    //storage
    int winning,goata,goatb,door;
    char action,actiona,actionb,choicedoor,choicedoora,choicedoorb,choice1,choicea,choiceb;

    //text color
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );

    //get random number for each door
    winning=rand( )%3+1;
    if (winning%1==0){
        goata=2;
        goatb=3;
    }
    if (winning%2==0){
        goata=1;
        goatb=3;
    }
    if (winning%3==0){
        goata=1;
        goatb=2;
    }


    //cout << " Debugging-----"<<"winning:"<<winning<<"    goata:"<<goata<<"      goatb:"<<goatb;
    //cout << endl;

    //introduction for this game
    door:
    cout << "\n You see 3 doors before you.One has a prize package worth $30,000 dollars.";
    cout << "\n The other two have a sick goat because everyone is a winner on Skidoo.";
    cout << "\n Please choose a door (Please input 1 or 2 or 3):";
    cin >> door;
    cout << endl;
    if(door==1||2==door||3==door){
    cout << "\n You chose the door "<<door<<".";
    cout << endl;}
    else{
    cout << " Invalid Input.";
    goto door;
    cout <<endl;}


    //winningdoor:
    if(door==winning){
        //game starts
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
        cout << "\n\"Here is a tip for this game: behind Door "<< goata <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<winning<<" or the Door "<< goatb << ".";
        cout << "\n Now you stand before the Door "<<winning<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide to stay or not, you can do some actions to get clues.\"";
        cout <<endl;

        //actions to get clues
        action:{
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        actioninput:
        cout << "\n You can push the door or check the ground before the door.";
        cout << "\n (P for Pushing or C for checking):";
        cin >> action;
        cout << endl;}
        switch (action){
        case 'P':
        case 'p':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You pushed the door which is sealed.";
        cout << "\n You are not strong enough to open the door.";
        cout << "\n Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You check the ground before the door, which is very clean.";
        cout << "\n You are not able to find any trace on the ground.";
        cout << endl;
        break;
        default:
        cout << " Invalid input.";
        goto actioninput;
        cout <<endl;
        }

        //decide to change door or keep finding clues
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        decide:
        cout << "\n Now you need to decide to change the door or do a little more thing.";
        cout << "\n (D for deciding which door or F for finding more clues):";
        cin >> choice1;
        cout << endl;
        switch(choice1){
        case 'd':
        case 'D':
        goto choicedoor;
        break;
        case 'f':
        case 'F':
        goto action;
        break;
        default:
        cout << " Invalid Input.";
        goto decide;
        cout <<endl;
        }

        //choice for staying or switching
        choicedoor:
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout << "\n Staying with your current door or switching to other door. ";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoor;
        cout <<endl;

        //the final result
        switch (choicedoor){
        case '1':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to stay with current door";
        cout << "\n Open door "<< winning <<".";
        cout << "\n Aaaah, you got the $30,000 dollars!!!";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout <<endl;
        break;
        case '2':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to switch to Door "<< goatb <<".";
        cout << "\n Open door "<< goatb << ". Aaaah, another sick goat. Caught the flu from "<< goatb <<".";
        cout << "\n The prize package was behind door "<< winning<<".";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout << endl;
        break;
        default:
        cout << "Invalid Input.";
        goto choicedoor;
        cout <<endl;
        }

    }

        //goatadoor:
        if(door==goata){

        //game starts
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
        cout << "\n\"Here is a tip for this game: behind Door "<< goatb <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<goata<<" or the Door "<< winning << ".";
        cout << "\n Now you stand before the Door "<<goata<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide to stay or not, you can do some actions to get clues.\"";
        cout <<endl;

        //actions to get clues
        actiona:{
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        actioninputa:
        cout << "\n You can push the door or check the ground before the door.";
        cout << "\n (P for Pushing or C for checking):";
        cin >> actiona;
        cout << endl;}
        switch (actiona){
        case 'P':
        case 'p':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You pushed the door which is sealed.";
        cout << "\n You are not strong enough to open the door.";
        cout << "\n Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You examined the ground very carefully.";
        cout << "\n You found some small animal footprints.";
        cout << endl;
        break;
        default:
        cout << " Invalid input.";
        goto actioninputa;
        cout <<endl;
        }

        //choice for staying or switching
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        decidea:
        cout << "\n Now you need to decide to change the door or do a little more thing.";
        cout << "\n (D for deciding which door or F for finding more clues):";
        cin >> choicea;
        cout << endl;
        switch(choicea){
        case 'd':
        case 'D':
        goto choicedoora;
        break;
        case 'f':
        case 'F':
        goto actiona;
        break;
        default:
        cout << " Invalid Input.";
        goto decidea;
        cout <<endl;
        }

        //choice for staying or switching
        choicedoora:
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout << "\n Staying with your current door or switching to other door. ";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoora;
        cout <<endl;

        //the final result
        switch (choicedoora){
        case '1':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to stay with current door.";
        cout << "\n Open door "<< goata;
        cout << "\n Aaaah, another sick goat. Caught the flu from goat"<< goata <<".";
        cout << "\n The prize package was behind door "<< winning<<".";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout <<endl;
        break;
        case '2':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to switch to door "<< winning <<".";
        cout << "\n Open door "<< winning ;
        cout << "\n Aaaah, you got the $30,000 dollars!!!";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout <<endl;
        break;
        default:
        cout << " Invalid Input.";
        goto choicedoora;
        cout <<endl;
        }

    }


       //goatbdoor:
        if(door==goatb){

        //game starts
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        SetConsoleTextAttribute(hStdOut, FOREGROUND_RED );
        cout << "\n\"Here is a tip for this game: behind Door "<< goata <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<goatb<<" or the Door "<< winning << ".";
        cout << "\n Now you stand before the Door "<<goatb<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide to stay or not, you can do some actions to get clues.\"";
        cout <<endl;

        //actions to get clues
        actionb:{
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        actioninputb:
        cout << "\n You can push the door or check the ground before the door.";
        cout << "\n (P for Pushing or C for checking):";
        cin >> actionb;
        cout << endl;}
        switch (actionb){
        case 'P':
        case 'p':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You pushed the door which is sealed.";
        cout << "\n You are not strong enough to open the door.";
        cout << "\n Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You examined the ground very carefully.";
        cout << "\n You found some small animal footprints.";
        cout << endl;
        break;
        default:
        cout << " Invalid input.";
        goto actioninputb;
        cout <<endl;
        }

        //decide to change door or keep finding clues
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        decideb:
        cout << "\n Now you need to decide to change the door or do a little more thing.";
        cout << "\n (D for deciding which door or F for finding more clues):";
        cin >> choiceb;
        cout << endl;
        switch(choiceb){
        case 'd':
        case 'D':
        goto choicedoorb;
        break;
        case 'f':
        case 'F':
        goto actionb;
        break;
        default:
        cout << " Invalid Input.";
        goto decideb;
        cout <<endl;
        }

        //choice for staying or switching
        choicedoorb:
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout << "\n Staying with your current door or switching to other door. ";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoorb;
        cout <<endl;

        //the final result
        switch (choicedoorb){
        case '1':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to stay with the current Door.";
        cout << "\n Open door "<< goatb;
        cout << "\n Aaaah, another sick goat. Caught the flu from goat"<< goatb <<".";
        cout << "\n The prize package was behind door "<< winning<<".";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout <<endl;
        break;
        case '2':
        SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN );
        cout << "\n You chose to switch to door"<<winning<< ".";
        cout << "\n Open door "<< winning ;
        cout << "\n Aaaah, you got the $30,000 dollars!!!";
        SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
        cout << endl;
        break;
        default:
        cout << " Invalid Input.";
        goto choicedoorb;
        cout <<endl;
        }

    }
    return 0;
}
