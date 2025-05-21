#include <stdio.h>

#define MAX_LENGTH 1000

void rev(char in[], char out[], int end);
int getLine(char s[]);

int main() {

        int len;
        char line[MAX_LENGTH];
        char new[MAX_LENGTH];

        while ((len = getLine(line)) > 0) {
                rev(line, new, len);
                printf("%s", new);
        }
}

int getLine(char s[]) {

        int i = 0;
        int c = getchar();
        while (c != EOF && c != '\n') {
                s[i] = c;
                ++i;
                c = getchar();
        }
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

void rev(char in[], char out[], int end) {
     
        int gap = 0;
        while (in[gap] == ' ') {
                out[gap] = ' ';
                ++gap;
        }

        int len = end - 2;
        int i = len + gap;
        while (len >= 0) {
                out[i - len] = in[len];
                --len;
        }
        out[i + 1] = '\n';
        out[i + 2] = '\0';
}





