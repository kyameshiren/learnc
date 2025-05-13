#include <stdio.h>

/* Generates Fahrenheit to Celsius table */

int main() {
        int fahr;
        float cels;

        printf("  F : C\n");
        for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
                cels = (5.0/9.0) * (fahr-32);
                printf("%3d : %.2f\n", fahr, cels);
        }
}
