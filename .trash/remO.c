#include <stdio.h>

#define BUFFER 1000

void sqz(char str[], char rem[]);

int main(void) {
        
       
        int c, i;
        char rem[BUFFER];
        char str[BUFFER];

        
        printf("Remove string:\n");
        c = getchar();
        i = 0;
        while (c != '\n' && i < BUFFER - 1) {
                rem[i++] = c;
                c = getchar();
        } 
        rem[i] = '\n';
        rem[++i] = '\0';
        
        printf("Input string:\n");
        c = getchar();
        i = 0;
        while (c != '\n' && i < BUFFER - 1) {
                str[i++] = c;
                c = getchar();
        } 
        str[i] = '\n';
        str[++i] = '\0';
       
        sqz(str, rem);
        printf("%s\n", str);


}

void sqz(char str[], char rem[]) {

        int i;
        int p = 0;
        int map[256] = {0};


        for (i = 0; rem[i] != '\0'; ++i) {
                map[(unsigned char)rem[i]] = 1;
        }

        for (i = 0; str[i] != '\0'; ++i) {
                if (!map[(unsigned char)str[i]]) {
                        str[p++] = str[i];
                }
        }
        str[p] = '\0';
}










