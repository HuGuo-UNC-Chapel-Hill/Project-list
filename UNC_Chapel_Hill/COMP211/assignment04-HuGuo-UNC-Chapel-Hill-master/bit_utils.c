// PID: 730507803
// I pledge the COMP 211 honor code.

#include "bit_utils.h"

int bit_select(int num, int startbit, int endbit) {
    //declaration
    //unsigned int unum = num;

    return (num >> endbit & ~(~0 << (startbit + 1 - endbit)));
}