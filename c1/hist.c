#include <stdio.h>


#define IN  1
#define OUT 0
#define RANGE 20


int main () {
        
        int a;
        int i, j;
        int state = OUT; 
        int count = 0;
        int hist[RANGE] = {0};
        int max = 0;

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
 
        for (i=0;i<RANGE;i++) {
                if ( hist[i] > max ) {
                        max = hist[i];
                }
                printf("%d ", i + 1);
        }

        printf("\n");

        for (j=0;j<max;j++) {
                for (i=0;i<RANGE;i++) {
                        if ( hist[i] > 0 ) {
                                printf("x ");
                                --hist[i];
                        }
                        else {
                                printf("  ");
                        }
                }
                printf("\n");
        }


        printf("Max: %d\n", max);



}











