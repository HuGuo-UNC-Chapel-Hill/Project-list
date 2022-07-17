// PID: 730507803
// I pledge the COMP 211 honor code.

#include "bit_utils.h"

//get the bit string from integer
char* firststr(int num, const int *size);

//get twos complement for negative number
char* twoscom(char *str, const int *size);

char* itob(int num, int size) {
     
    //get the bit string from integer
    char *str = firststr(num, &size);
    
    //get twos complement for negative number
    if (num < 0) {
        str = twoscom(str, &size);   
    } 
    
    //return string
    return str;
}

int mask_bits(int num, int mask) {
    return num & mask;
}

int set_bits(int num, int bits) {
    return num | bits;
}

int inverse_bits(int num, int bits) {
    return num ^ bits;
}

int bit_select(int num, int startbit, int endbit) {
    //declaration
    unsigned int unum = num;

    return (unum >> endbit & ~(~0 << (startbit + 1 - endbit)));
}

char* firststr(int num, const int *size) {
    //declaration and allocate memory for bit string
    char *str = malloc(*size + 1);
    str[*size] = '\0';

    int quotient = 0, reminder = 0;

    //for loop to generate bit string
    for (int i = 1; i <= *size; i++) {
        quotient = num / 2;
        reminder = num % 2;

        //condition to assign 0 or 1 to bit string
        if(reminder == 0) {
            str[*size - i] = '0';
        } else { 
            str[*size - i] = '1';
        }        
        num = quotient;
    }
    return str;
}

char* twoscom(char *str, const int *size) {
    //declaration for ones complement
    char onesComplement[*size + 1];
    onesComplement[*size] = '\0';

    //give carry the value of 1
    char carry = '1';

    //loop for getting one's complement bit string
    for(int i = 0; i < *size; i++) {
        if ( str[i] == '0'){
            onesComplement[i] = '1';
        } else {
            onesComplement[i] = '0';
        }
    }
    
    //loop for getting two's complement bit string
    for (int i = *size - 1; i >= 0; i--) {
        if (onesComplement[i] == '1' && carry == '1') {
            str[i] = '0';
            carry = '1';
        } else if (onesComplement[i] == '0' && carry == '1') {
            str[i] = '1';
            carry = '0';
        } else {
            str[i] = onesComplement[i];
        }
    }    
    return str;
} 
