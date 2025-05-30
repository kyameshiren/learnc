#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "op.h"
#include "getch.h"


int op(char s[]) {

        int i = 0;
        int c, next;

        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';

        if (c == '-') {
                next = getch();
                if (isdigit(next) || next == '.') {
                        s[++i] = c = next;
                } else {
                        ungetch(next);
                        return c;
                }
        } 

        if (c == '=') {
                c = getch();
                if (isalpha(c)) {
                        s[0] = c;
                        s[1] = '\0';
                        return VAR_set;
                } else {
                        ungetch(c);
                        return '=';
                }
        }

        if (c == '@') {
                c = getch();
                if (isalpha(c)) {
                        s[0] = c;
                        s[1] = '\0';
                        return VAR_use;
                } else {
                        ungetch(c);
                        return '@';
                }
        }

        if (c == '$') {
                return LAST_val;
        }

        if (isalpha(c)) {
                i = 0;
                while (isalpha(s[++i] = c = getch()))
                        ;
                s[i] = '\0';
                if (c != EOF) {
                        ungetch(c);
                }
                if (strlen(s) == 1) {
                        return s[0];
                } else {
                        return FUNC;
                }
        }

        if (!isdigit(c) && c != '.') {
                return c;
        }

        if (isdigit(c)) {
                while (isdigit(s[++i] = c = getch()))
                        ;
        }
        if (c == '.') {
                while (isdigit(s[++i] = c = getch()))
                        ;
        }
        s[i] = '\0';
        if (c != EOF) {
                ungetch(c);
        }
        return NUMBER;
}
