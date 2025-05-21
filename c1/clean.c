#include <stdio.h>

#define MAX_LENGTH 1000


int getLine(char s[]);
void filter(char in[], int end);

int main() {

        int len = 0;
        char line[MAX_LENGTH];
        while ((len = getLine(line)) > 0) {
                if (line[0] != '\n') {
                        filter(line, len);
                        printf("%s", line);
                }
        }
        return 0;
}

// Puts current line into buffer + string format
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

void filter(char in[], int end) {

        int len = end - 2;
        while (in[len] == ' ') {
                in[len] = 'x';
                --len;
        }

}
