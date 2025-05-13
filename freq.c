#include <stdio.h>

int main () {

        int a, i; //input character
        int freq[27] = {0};

        // Use ascii value to determine index of character 
        while ((a = getchar()) != EOF) {
                if ( 122 >= a && a >= 97 ) {
                        ++freq[a - 97];
                } else if ( 90 >= a && a >= 65 ) {
                        ++freq[a - 65];
                } else if ( a != '\n' ) {
                        ++freq[26];
                }
        }

        // Print table, * means 'other'
        for ( i = 0; i < 26; ++i) {
                printf("%c : %d\n", i + 65, freq[i]);
        }
        printf("* : %d\n", freq[27]);
}
