// PID: 730507803
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//define the size of string
#define SIZE 16


int main(int agrc, char* agrv[]) {
    
    //declaration of fields
    char binaryString[SIZE + 1];
    int quotient = 0, reminder = 0; 
    int num = atoi(agrv[1]);

    //condition for decimal value in 16bits
    if(num <= USHRT_MAX && num >= SHRT_MIN) {

        //condition for negative number
        if (num < 0) {
            num = USHRT_MAX + num + 1;
        }

        //loop for binary calculation
        for (int i = 1; i <= SIZE; i++) {
            quotient = num / 2;
            reminder = num % 2;

                    //conditionto assign value to the bit string
                   if(reminder == 0) {
                       binaryString[SIZE - i] = '0';
                   } else {
                       binaryString[SIZE - i] = '1';
                   }
                    num = quotient;
        }

        //add end sign to the bit string
        binaryString[SIZE] = '\0';
    }
    
    //output the result 
    if (atoi(agrv[1]) <= USHRT_MAX && atoi(agrv[1]) >= SHRT_MIN) {
        printf("The two's complement 16-bit representation of %s is: %s.\n", agrv[1], binaryString);
    } else {
        printf("The two's complement 16-bit representation of %s is: not possible.\n", agrv[1]);
    }
}

