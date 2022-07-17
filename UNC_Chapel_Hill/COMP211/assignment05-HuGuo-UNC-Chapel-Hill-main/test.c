#include <stdint.h>
#include <stdio.h>

uint32_t bit_select(uint32_t num, uint32_t startbit, uint32_t endbit)
{
    return (num >> endbit & ~(~0 << (startbit + 1 - endbit)));
}

uint32_t bit_select1(uint32_t num, int startbit, int endbit) {
  unsigned int topmask = 0xffffffff;
    return (num >> endbit) & (~(topmask << (startbit-endbit+1)));
}

int main() {
    uint32_t address = 0x7cd27462;
    printf("%d \n", address);
    uint32_t byte_offset = address % (sizeof(uint32_t));
    printf("%d \n", byte_offset);
    printf("%d \n", 8*byte_offset);
    uint8_t v = 12;
    printf("%x \n", v);
    uint32_t a = 0x12345678;
    printf("%x \n", a);
    a = a & 0xFFFF0000;
    printf("%x \n", a);
    a = a|v;
    uint32_t uv = v;
    printf("%x \n", v <<=16);
    printf("%x \n", uv <<=16);
    uint32_t c = bit_select1(a, 2, 1);
    printf("a  %x  c %x \n", a, c);

}
