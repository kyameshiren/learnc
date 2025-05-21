#include <stdio.h>
#include <string.h>

#define BUFFER 1000

int main(void) {

        int i;
        char a[BUFFER]; 
        char c;

        int k = 0;
        while ((c = getchar()) != EOF && k < BUFFER - 1) {
                if (c != '\n') {
                        a[k++] = c;
                }
        }
        a[k] = '\0';

        int n = strlen(a);
        for (i = 0; i < n; i++) {
                printf("%c%c", a[i], (i%32==31 || i==n-1) ? '\n' : ' ');
        }
}
