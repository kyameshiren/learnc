#include <stdio.h>

int main() {

        int a;
        int b = 0;

        while ((a = getchar()) != EOF) {
                if (a == ' ') {
                        ++b; 
                }
                if (a != ' ') {
                        b = 0;
                }
                if (b <= 1) {
                        putchar(a);
                }
        }
}
