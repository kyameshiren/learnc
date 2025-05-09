#include <stdio.h>

/* 
 * Implement feature that gets largest word in file and then sets RANGE to largest word
 */

#define IN  1        /* Inside word */
#define OUT 0        /* Outside word */
#define RANGE 20     /* Maximum word size in file */

int main () {
        
        int a;                  /* Input character */
        int i, j;               /* Loop variables  */
        int state = OUT;        /* Word state */
        int count = 0;          /* Char in word count */
        int hist[RANGE] = {0};  /* Histogram array */
        int maxValue = 0;       /* Maximum value in hist */
        int maxIndex = 0;       /* Index of maximum value */
        int level;              /* Used for inverting the table */

/*
 * Loop over all characters
 * If multiple characters in word, increment index of histogram
 */

        while ((a = getchar()) != EOF) {

                if ( a == ' ' || a == '\n' || a == '\t' ) {
                        ++hist[count - 1];
                        state = OUT;
                        count = 0;
                }
                if ( a != ' ' ) {
                        count++;
                        state = IN;
                }
        }

/*
 * Get maximum value and index of histogram
 */

        for (i=0;i<RANGE;i++) {
                if ( hist[i] > maxValue ) {
                        maxValue = hist[i];
                        maxIndex = i;
                }
        }

/* 
 * Initialize highest level of table to largest value in array
 * Starting at highest level, loop through entire array and print 'x' if value is higher than level
 * Decrement level and retest
 */

        printf("\n");
        level = maxValue;
        for (j=0;j<maxValue;j++) {
                for (i=0;i<RANGE;i++) {
                        
                        if ( hist[i] >= level ) {
                                printf("x ");
                        }
                        else {
                                printf("  ");
                        }

                        if ( i == 10 ) {
                                printf(" ");
                        }
                }
                --level;
                printf("\n");
        }
/*
 * If at base of table, print index and final output string
 */

        for (i=0;i<RANGE;i++) {
                printf("%d ", i + 1);
        }
        printf("\n%d words had %d character(s)\n", maxValue, maxIndex + 1);
}











