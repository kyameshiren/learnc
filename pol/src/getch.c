#include <stdio.h>
#include <string.h>
#include "getch.h"

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
        if (bufp >= BUFSIZE) {
                printf("ungetch: too many characters\n");
        } else {
                buf[bufp++] = c;
        }
}

void ungets(char s[]) {
        int i = strlen(s) - 1;
        while (i >= 0) {
                ungetch(s[i--]);
        }
}

