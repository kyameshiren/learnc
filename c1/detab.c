#include <stdio.h>


int main(void) {

        int stop = 8;
        int len = 0;
        int gap = 0;
        int c;

        while ((c = getchar()) != EOF) {
                ++len;
                if (c == '\n') {
                        len = 0;
                }
                if (c == '\t') {
                        gap = stop - (len % stop);
                        len += gap;
                        while (gap >= 0) {
                                putchar(' ');
                                --gap;
                        }
                } else {
                        putchar(c);
                }
        }
}
