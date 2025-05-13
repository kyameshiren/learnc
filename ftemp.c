#include <stdio.h>

/* Generates Fahrenheit to Celsius table */

float conv(int fahr);

int main() {

        for (int i = 10; i <= 200; i = i + 10) {
                printf("%3d : %.2f\n", i, conv(i));
        }
}

float conv(int fahr) {
        return (5.0/9.0) * (fahr-32);
}
