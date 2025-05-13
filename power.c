#include <stdio.h>

int power(int base, int exp); 

int main() {

        int a; 
        int b = 1;
        while (b <= 16) {
                printf("%2d : %d \n", b, power(2, b));
                ++b;
        }
        return 0;
}


int power(int base, int exp) {
      
        int out = 1; 
        while (exp > 0) {
                out = out * base;
                --exp;
        }
        return out; 
}


