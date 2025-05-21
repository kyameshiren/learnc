#include <stdio.h>
#include "utils.h"

int rot(unsigned int x, int n);

int main(void){

        unsigned int x = 65535;
        int z;
        int n = 13;

        print_binary(x);
        z = rot(x, n);
        print_binary(z);
}

int rot(unsigned int x, int n) {

        int len = sizeof(x) * 8;
        n = n % len;
        return (x >> n) | (x << (len - n));

}
