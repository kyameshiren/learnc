#include <stdio.h>


int main(void) {

        int syn[6] = {0};
        int c;
        int next;
        int escape = 0;
        int comment = 0;
        int quote = 0;
        int track[2] = {0, 1};

        while ((c = getchar()) != EOF) {
                ++track[0];
                if (c == '\n') {
                        escape = 0;
                        comment = 0;
                        quote = 0;
                        track[0] = 0;
                        ++track[1];
                }
                if (c == '/' && (next = getchar()) == '/') {
                        comment = 1;
                } 
                if (c == '\\') { 
                        escape = 1;
:                       c = getchar();
                        escape = 0;
                        c = getchar();
                }
                if (escape == 0) {
                        if (c == '\'' || c == '\"') {
                                quote = 1 - quote; 
                        }
                }
                if (escape == 0 && comment == 0 && quote == 0) {
                        if (c == '(') {
                                ++syn[0];
                        }
                        if (c == ')') {
                                ++syn[1];
                        }
                        if (c == '[') {
                                ++syn[2];
                        }
                        if (c == ']') {
                                ++syn[3];
                        }
                        if (c == '{') {
                                ++syn[4];
                        }
                        if (c == '}') {
                                ++syn[5];
                        }
                }
        }

        if (syn[0] != syn[1]) {
                printf("Parenthesis mismatch!\n");
        } else if (syn[2] != syn[3]) {
                printf("Bracket mismatch!\n");
        } else if (syn[4] != syn[5]) {
                printf("Brace mismatch!\n");
        } else {
                printf("No errors detected!\n");
        }

}






