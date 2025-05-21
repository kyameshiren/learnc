#include <stdio.h>

#define BUFFER 1000

void sqz(char in[], int c);

int main(void) {
        
       
        int c, i;
        int z = 'z';
        char str[BUFFER];

        c = getchar();
        i = 0;
        while (c != '\n') {
                str[i] = c;
                ++i;
                c = getchar();
        } 
        if (c == '\n') {
                str[i] = '\n';
                str[++i] = '\0';
        }
       
        printf("%s\n", str);
        sqz(str, z); 
        printf("%s\n", str);


}

void sqz(char in[], int c) {

        int i = 0;
        int k = 0;
        while (in[i] != '\0') {
                if (in[i] != c) {
                        in[k] = in[i];
                        ++k;
                } 
                ++i;
        }
        in[k] = '\0';
}










