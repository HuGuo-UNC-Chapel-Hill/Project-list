// PID: 730507803
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>

//define the const int 
#define CAPINT 32
#define START_RANGE 65
#define END_RANGE 90

int main () {

    //declaration for variable
    int c;

    //loop to check uppercase and output lowercase
    while ((c = getchar()) != EOF) {

        //condition to check the uppercase
        if (c >= START_RANGE && c <= END_RANGE) {

            //output the lowercase
            putchar(c + CAPINT);

        //condition to output the lowercase
        } else {
            putchar(c);
        }
    };

    //return 0; end the program
    return 0;
}

