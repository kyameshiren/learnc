#include <stdio.h>


int main() {

        char string[7] = {'h', 'e', 'l', 'l', 'o', '\n', '\0'};

        int i = 7;

        while (i >= 0) {
                putchar(string[i]);
                --i;
        }
}
