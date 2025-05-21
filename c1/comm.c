#include <stdio.h>

// if / is second occurence immediately in line
//
/////// ;lkjasd;fklja sdf// ;lkajsd;fkljasdf	
// If second occurence, and not in literal do not print rest of line

int main(void) {

        int literal = 0;
        int comment = 0;
        int next;
        int c;
        while ((c = getchar()) != EOF) {  
                if (c == '\n') {                     //check
                        literal = 0;
                        comment = 0;
                }
                if (c == '\"' || c == '\'') {        //check
                        ++literal;
                }
                if (c == '/' && (literal % 2 == 0) && comment == 0) {
                        next = getchar();
                        if (next == '/') {
                                comment = 1;
                        } else {
                                putchar(c);
                                c = next;
                        }
                }
                if (comment == 0) {
                        putchar(c);
                }
        }
}
