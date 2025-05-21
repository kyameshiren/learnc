#include <stdio.h>
#include <string.h>


#define BUFFER 1000

void lower(char array[], int len);


int main(void) {

        int i;
        int c;
        char array[BUFFER];
                
        i = 0;
        while ((c = getchar()) != EOF && i < BUFFER - 1) {
                array[i++] = c;
        }
        array[i] = '\0';
             
        int len = i - 1; 
        printf("%s\n", array);
        lower(array, len);
        printf("%s\n", array);

}

void lower(char array[], int len) {

        int i;

        i = 0;
        while (i < len) {
                        array[i] = (array[i] >= 65 && array[i] <= 90) ? array[i] + 32 : array[i];
                        ++i;
        }


}
