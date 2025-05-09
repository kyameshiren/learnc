#include <stdio.h>

int main () {
        
        int i, c;
        int array[10] = {0};
        

        while ((c = getchar()) != EOF) {
                if (c >= '0' && c <= '9') {
                        array[c-'0']++;
                }
        }

        for (i=0;i<10;i++) {
                printf("%d : %d\n", i, array[i]);
        }



}
