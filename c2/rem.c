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
                rem[i] = c;
                ++i;
                c = getchar();
        } 
        rem[i] = '\n';
        rem[++i] = '\0';
        
        printf("Input string:\n");
        c = getchar();
        i = 0;
        while (c != '\n' && i < BUFFER - 1) {
                str[i] = c;
                ++i;
                c = getchar();
        } 
        str[i] = '\n';
        str[++i] = '\0';
       
        sqz(str, rem);
        printf("%s\n", str);


}

void sqz(char str[], char rem[]) {

        int i, k;
        int p = 0;
        int check = 0;
        for (i = 0; str[i] != '\0'; ++i) {
                for (k = 0; rem[k] != '\0'; ++k) {
                        if (str[i] == rem[k]) {
                                ++check;
                        }
                }
                if (check == 0) {
                        str[p++] = str[i];
                }
                check = 0;
        }
        str[p] = '\0';
}











