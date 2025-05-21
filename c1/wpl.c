#include <stdio.h>

int main () {

        int a;
        int in = 0;
        int wc = 0;

        while ((a = getchar()) != EOF) {

                if ( a == ' ' || a == '\n' || a == '\t' ) {
                        in = 0;
                }
                else if ( in == 0 ) {
                        in = 1;
                        wc++;
                        putchar('\n');
                }
                if ( a != '\n' ) {
                        putchar(a);
                }
        }
        printf("\nWord count: %d\n", wc);
}

