#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int winning,goata,goatb,door;
    char action,choicedoor,choice1;

    srand(1);
    srand(time(0));

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


    cout << " Debugging-----"<<"winning:"<<winning<<"  goata:"<<goata<<" goatb:"<<goatb;
    cout << endl;

    cout << "\n You see 3 doors before you.One has a prize package worth $30,000 dollars.";
    cout << "\n The other two have a sick goat because everyone's a winner on Skidoo.";
    cout << "\n Please choose a door (Please in put 1 or 2 or 3):";
    cin >> door;
    cout << endl;
    if(door==1||2==door||3==door){
    cout << "\n You chose the door "<<door<<".";
    cout << endl;}
    else
    cout << "Invalid Input.";
    cout <<endl;


    //winningdoor:
    if(door==winning){
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        cout << "\n\"Here is a tip for this game: behind Door "<< goata <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<winning<<" or the Door "<< goatb << ".";
        cout << "\n Now you stand before the Door "<<winning<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide stay or not, you can do something to get clues.\"";
        cout <<endl;
        action:{
        cout << "\n You can push the door or check the ground before the door.\"";
        cout << "\n (P for Pushing or C for checking):";
        cin >> action;
        cout << endl;}
        switch (action){
        case 'P':
        case 'p':
        cout << "\n You pushed the door, which is sealed. Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        cout << "\n You check the ground before the door, which is very clean.";
        cout << endl;
        break;
        default:
        cout << "Invalid input.";
        cout <<endl;
        }

        cout << "\n Now you need decide to change the door or do a little more thing.";
        cout << "\n (D for choosing the door or A for finding more clues):";
        cin >> choice1;
        cout << endl;
        switch(choice1){
        case 'D':
        case 'd':
        goto choicedoor;
        break;
        case 'a':
        case 'A':
        goto action;
        break;
        default:
        cout << "Invalid Input.";
        }

        choicedoor:
        cout << "\n\"Staying with your current door or switching to other door.\"";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoor;


        switch (choicedoor){
        case '1':
        cout << "You chose to stay with current door";
        cout << "Open door "<< winning <<". Aaaah, you got the $30,000 dollars!!!";
        cout <<endl;
        break;
        case '2':
        cout << "You chose to switch to Door "<< goatb <<".";
        cout << "Open door "<< goatb << ". Aaaah, another sick goat. Caught the flu from "<< goatb <<".";
        cout << "The prize package was behind door "<< winning<<".";
        break;
        }

    }

     //goatadoor:
    if(door==goata){
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        cout << "\n\"Here is a tip for this game: behind Door "<< goatb <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<goata<<" or the Door "<< winning << ".";
        cout << "\n Now you stand before the Door "<<goata<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide stay or not, you can do something to get clues.\"";
        cout <<endl;
        actiona:{
        cout << "\n You can push the door or check the ground before the door.\"";
        cout << "\n (P for Pushing or C for checking):";
        cin >> action;
        cout << endl;}
        switch (action){
        case 'P':
        case 'p':
        cout << "\n You pushed the door, which is sealed. Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        cout << "\n You found the ground in front of the door dirty, and some animal footprints.";
        cout << endl;
        break;
        default:
        cout << "Invalid input.";
        cout <<endl;
        }

        cout << "\n Now you need decide to change the door or do a little more thing.";
        cout << "\n (D for choosing the door or A for finding more clues):";
        cin >> choice1;
        cout << endl;
        switch(choice1){
        case 'D':
        case 'd':
        goto choicedoora;
        break;
        case 'a':
        case 'A':
        goto actiona;
        break;
        default:
        cout << "Invalid Input.";
        }

        choicedoora:
        cout << "\n\"Staying with your current door or switching to other door.\"";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoor;


       switch (choicedoor){
        case '1':
        cout << "\n You chose to stay with current door";
        cout << "\n Open door "<< goata << ". Aaaah, another sick goat. Caught the flu from goat"<< goatb <<".";
        cout << "\n The prize package was behind door "<< winning<<".";
        break;
        case '2':
        cout << "\n You chose to switch to Door "<< winning <<".";
        cout << "\n Open door "<< winning <<". Aaaah, you got the $30,000 dollars!!!";
        cout <<endl;
        break;
        default:
        cout << "Invalid input.";
        cout <<endl;
        }

    }

       //goatbdoor:
        if(door==goatb){
        cout << "\n You heard the computer's voice before the vest:";
        cout <<endl;
        cout << "\n\"Here is a tip for this game: behind Door "<< goata <<" is a sick goat.";
        cout << "\n The prize package must behind the Door "<<goatb<<" or the Door "<< winning << ".";
        cout << "\n Now you stand before the Door "<<goatb<<".";
        cout << "\n we are very fair here on Skidoo.I am going to give you a choice.";
        cout << "\n You can stay with the current door or switch to other door.";
        cout << "\n Before you decide stay or not, you can do something to get clues.\"";
        cout <<endl;
        actionb:{
        cout << "\n You can push the door or check the ground before the door.\"";
        cout << "\n (P for Pushing or C for checking):";
        cin >> action;
        cout << endl;}
        switch (action){
        case 'P':
        case 'p':
        cout << "\n You pushed the door, which is sealed. Nothing happened.";
        cout << endl;
        break;
        case 'C':
        case 'c':
        cout << "\n You found the ground in front of the door dirty, and some animal footprints.";
        cout << endl;
        break;
        default:
        cout << "Invalid input.";
        cout <<endl;
        }

        cout << "\n Now you need decide to change the door or do a little more thing.";
        cout << "\n (D for choosing the door or A for finding more clues):";
        cin >> choice1;
        cout << endl;

        switch(choice1){
        case 'D':
        case 'd':
        goto choicedoorb;
        break;
        case 'a':
        case 'A':
        goto actionb;
        break;
        default:
        cout << "Invalid Input.";
        }

        choicedoorb:
        cout << "\n\"Staying with your current door or switching to other door.\"";
        cout << "\n (1 for staying or 2 for switching):";
        cin >> choicedoor;


       switch (choicedoor){
        case '1':
        cout << "\n You chose to stay with current door";
        cout << "\n Open door "<< goatb << ". Aaaah, another sick goat. Caught the flu from goat "<< goatb <<".";
        cout << "\n The prize package was behind door "<< winning<<".";
        break;
        case '2':
        cout << "\n You chose to switch to Door "<< winning <<".";
        cout << "\n Open door "<< winning <<". Aaaah, you got the $30,000 dollars!!!";
        cout <<endl;
        break;
        default:
        cout << "Invalid input.";
        cout <<endl;
        }

    }
}
