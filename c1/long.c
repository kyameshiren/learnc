#include <stdio.h>

#define MAX_LENGTH 1000


int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main() {

        int len, max = 0;
        char line[MAX_LENGTH];
        char longest[MAX_LENGTH];
        while ((len = getLine(line, MAX_LENGTH)) > 0) {
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        }
        // Output
        printf("Longest line:\n");
        printf("%s\n", longest);
        printf("Total characters: %d\n", max);
        return 0;
}

// Puts current line into buffer + string format
int getLine(char s[], int lim) {

        int i = 0;
        int j = 0;
        int c = getchar();
        while (c != EOF && c != '\n') {
                if (i < lim - 1) {
                        s[i] = c;
                        ++i;
                }
                ++j;
                c = getchar();
        }
        if (c == '\n') {
                if (i < lim - 1) {
                        s[i] = c;
                        ++i;
                }
                ++j;
        }
        s[i] = '\0';
        return j;
}

// Copy from[] array to[] array
void copy(char to[], char from[]) {

        int i = 0;
        while ((to[i] = from[i]) != '\0') {
                ++i;
        }
}










