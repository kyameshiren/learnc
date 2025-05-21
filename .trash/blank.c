#include <stdio.h>

int main() {

        int a;
        int b = 0;

        while ((a = getchar()) != EOF) {
                if (a == ' ') {
                        if (b != 1) {
                                putchar(a);
                                b = 1; 
                        }
                }
                if (a != ' ') {
                        putchar(a);
                        b = 0;
                }
        }
}
