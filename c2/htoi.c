#include <stdio.h>
#include <ctype.h>

#define BUFFER 1000

int htoi(char in[]);


int main(void) {

        char s[BUFFER];
        char c;
        int i = 0;

        while ((c = getchar()) != '\n') {
                s[i] = c;
                ++i;
        }
        if (c == '\n') {
                s[i] = c;
                ++i;
                s[i] = '\0';
        }

        printf("%d\n", htoi(s));

}

int htoi(char in[]) {

        int i, n;

        i = 0;
        n = 0;

        if (in[0] == '0' && tolower(in[1]) == 'x') {
                i = 2;
        }

        while (in[i] != '\0') {
                if (isdigit(in[i])) {
                        n = 16 * n + (in[i] - '0');
                } else if (isalpha(in[i])) {
                        n = 16 * n + (tolower(in[i]) - 87);
                }
                ++i;
        }
        return n;

}
