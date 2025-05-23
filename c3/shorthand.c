#include <stdio.h>
#include <ctype.h>

#define BUFFER 1000

void shorthand(char in[], char out[]);

int main(void) {

        char string[] = "testa-dcheckl-z";
        char out[BUFFER];
        shorthand(string, out);
        printf("%s\n", out);


}

void shorthand(char in[], char out[]) {

        int i, k = 0;

        for (i = 0; in[i] != '\0'; ++i) {

                if (isalpha(in[i - 1]) && in[i] == '-' && isalpha(in[i + 1])) {
                        char start = in[i - 1];
                        char end = in[i + 1];
                        while (start < end) {
                                out[k++] = ++start;
                        }
                        ++i;
                } else {
                        out[k++] = in[i];
                }

        }
        out[k] = '\0';
}
