#include <stdio.h>

#define BUFFER 1000

int brk(char check[], char index[]);

int main(void) {
        
       
        int c, i;
        char check[BUFFER];
        char index[BUFFER];

        
        printf("Check string:\n");
        c = getchar();
        i = 0;
        while (c != '\n' && i < BUFFER - 1) {
                check[i] = c;
                ++i;
                c = getchar();
        } 
        check[i] = '\0';
        
        printf("Index string:\n");
        c = getchar();
        i = 0;
        while (c != '\n' && i < BUFFER - 1) {
                index[i] = c;
                ++i;
                c = getchar();
        } 
        index[i] = '\0';
       
        printf("%d\n", brk(check, index));


}


int brk(char check[], char index[]) {
        
        int i; 
        int map[256] = {0};
        for (i = 0; check[i] != '\0'; ++i) {
                map[(unsigned char)check[i]] = 1;
        }

        for (i = 0; index[i] != '\0'; ++i) {
                if (map[(unsigned char)index[i]] == 1) {
                        return i;
                }
        } 
        return -1;

}
