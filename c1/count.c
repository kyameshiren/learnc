#include <stdio.h>

int main() {

        int a;
        int n = 0;
        int s = 0;
        int t = 0;
        int c = 0;

        while ((a = getchar()) != EOF) {
                if (a == '\n') {
                        n++;
                }
                if (a == ' ') {
                        s++;
                }
                if (a == '\t') {
                        t++;
                }
                c++;
        }
        printf("\nCharacters: %d\nNewlines: %d\nTabs: %d\nSpace: %d\n", c, n, t, s);
}
