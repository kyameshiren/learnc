#include <stdio.h>

int main() {

        int a;
        int tab;

        while ((a = getchar()) != EOF) {
                if (a != '\t' && a != ' ' )
                        putchar(a);
                        tab = 1;
                if (a == '\t')
                        printf("\\t");
                        tab = 0;
                if (a == ' ' && tab == 0)
                        putchar(a);
        }
}
