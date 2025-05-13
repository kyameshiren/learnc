#include <stdio.h>

#define MAX_LENGTH 1000
#define MIN_LENGTH 40


int getLine(char s[], int lim);

int main() {

        int len = 0;
        int min = MIN_LENGTH;
        char line[MAX_LENGTH];
        while ((len = getLine(line, MAX_LENGTH)) > 0) {
                if (len > min) {
                        printf("%s", line);
                        if (line[len -1] != '\n') {
                                printf("\n");
                        }
                        printf("Length: %d\n", len);
                }
        }
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
