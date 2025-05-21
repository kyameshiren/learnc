#include <stdio.h>
#include "utils.h"

// x &= (x - 1) 
// Deletes rightmost bit because subtracting one will always set all bits below the last bit to 1 and the current bit to 0
// When & the two strings together it will always give 1 & 0 == 0 for all bits <= rightmost bit


int fastcount(unsigned x);

int main(void) {

        int x = 0b111111110000;
        int z;

        print_binary(x);
        z = fastcount(x);
        printf("%d\n", z);

}

int fastcount(unsigned x) {

        int n = 0;
        while (x != 0) {
                x &= x - 1;
                ++n;
        }
        return n;


}
