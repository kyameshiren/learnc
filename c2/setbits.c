#include <stdio.h>
#include "utils.h"

unsigned int setbits(unsigned x, unsigned y, int p, int n);

int main(void) {

        int x = 0b11110000;
        int y = 0b00000101;
        int p = 7;
        int n = 4;
    
        print_binary(x);
        print_binary(y);
        unsigned int z = setbits(x, y, p, n);
        print_binary(z);

}

unsigned int setbits(unsigned x, unsigned y, int p, int n) {

        unsigned int mask;
        unsigned int offset;
        offset = p - n + 1;
        mask = ~(~0u << n);
        y = (y & mask) << offset;
        x = x & (~mask << offset);
        return x | y;

}
