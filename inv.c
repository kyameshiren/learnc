#include <stdio.h>

#define RANGE 20     /* Maximum word size in file */

int main () {
        
        int a;                  /* Input character */
        int i, j;               /* Loop variables  */
        int count = 0;          /* Char in word count */
        int hist[RANGE] = {0};  /* Histogram array */
        int maxValue = 0;       /* Maximum value in hist */
        int maxIndex = 0;       /* Index of maximum value */

        // Count word length
        while ((a = getchar()) != EOF) {
                if ( a == ' ' || a == '\n' || a == '\t' ) {
                        if ( RANGE > count > 0 ) {
                                ++hist[count - 1];
                                count = 0;
                        } else {
                                ++hist[RANGE - 1];
                        }
                } else {
                        count++;
                }
        }

        // Max value, index
        for (i = 0; i < RANGE; i++) {
                if ( hist[i] > maxValue ) {
                        maxValue = hist[i];
                        maxIndex = i;
                }
        }

        // Print histogram starting from the top
        for (j = maxValue; j > 0; j--) {
                for (i=0;i<RANGE;i++) {
                        if ( hist[i] >= j ) {
                                printf(" x ");
                        } else {
                                printf("   ");
                        }
                }
                printf("\n");
        }

        // Final outputs
        for (i = 1; i <= RANGE; i++) {
                if (i == RANGE) {
                        printf("%2d+", i);
                } else {
                        printf("%2d ", i);
                }
        }
        printf("\n%d words had %d character(s)\n", maxValue, maxIndex + 1);
}











