#include <stdio.h>
#include "utils.h"

int invert(unsigned int x, int p, int n);

int main(void){

        int x = 0b1010101010101010;
        int z;
        int p = 5;
        int n = 3;

        z = invert(x, p, n);
        print_binary(z);
}

int invert(unsigned int x, int p, int n) {

        unsigned int mask;
        unsigned int offset;
        offset = p - n + 1;
        mask = ~(~0u << n);
        x = x ^ (mask << offset);

        return x;
}
