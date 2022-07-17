// PID: 730507803
// I pledge the COMP 211 honor code.

#include <stdio.h>

//define the size of bit string
#define SIZE 32

int main(int agrc, char *agrv[]) {
 
    //declaration for fields
    char twosComplement[SIZE + 1];
    twosComplement[SIZE] = '\0'; 
    char onesComplement[SIZE + 1];
    onesComplement[SIZE] = '\0';

    //give carry the value of 1
    char carry = '1';

    //loop for getting one's complement bit string
    for(int i = 0; i < SIZE; i++) {
        if ( agrv[1][i] == '0'){
            onesComplement[i] = '1';
        } else {
            onesComplement[i] = '0';
        }
    }

    //debugging
    //printf("%s\n", onesComplement);

    //loop for getting two's complement bit string
    for (int i = SIZE - 1; i >= 0; i--) {
        if (onesComplement[i] == '1' && carry == '1') {
            twosComplement[i] = '0';
            carry = '1';
        } else if (onesComplement[i] == '0' && carry == '1') {
            twosComplement[i] = '1';
            carry = '0';
        } else {
            twosComplement[i] = onesComplement[i];
        }
        
        //debugging
        //printf("%c,", twosComplement[i]);
    }

    //output the result
    printf("The negation of the 32-bit two's complement integer %s is: %s.\n", agrv[1], twosComplement);
}
