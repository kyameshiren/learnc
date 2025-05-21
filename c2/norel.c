#include <stdio.h>

// for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;


#define BUFFER 1000

int main(void) {

        int i; 
        int lim = BUFFER;
        char s[BUFFER];
        char c;

        c = getchar();
        for (i = 0; i < lim - 1; ++i) {
                if (c != '\n') {
                        if (c != EOF) {
                                s[i] = c;
                        }
                }
                c = getchar();
        }
        printf("\n%s\n", s);

}
