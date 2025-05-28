#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Constants for tokens
#define MAXOP 100
#define NUMBER '0'
#define FUNC 200 
#define VAR_set 300 
#define VAR_use 301 
#define LAST_val 302 

// Functions declarations
int getop(char[]);
void push(double);
double pop(void);

// Stack implementation
#define MAXVAL 100
int sp = 0;     // stack pointer
double stack[MAXVAL];   // value stack

// Variable storage
double vars[26];        // variable array
double last_val;

int main(void) {

        int type;
        int i;
        double op2;
        char s[MAXOP];

        while ((type = getop(s)) != EOF ) {

                        switch (type) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case '+':
                                push(pop() + pop());
                                break;
                        case '*':
                                push(pop() * pop());
                                break;
                        case '-':
                                op2 = pop();
                                push(pop() - op2);
                                break;
                        case '/':
                                op2 = pop();
                                if (op2 != 0.0) {
                                        push(pop() / op2);
                                } else {
                                        printf("error: zero divisor\n");
                                }
                                break;
                        case '%':                              
                                op2 = pop();
                                push((int)pop() % (int)op2);    // CAST TO INT, HANDLE MOD
                                break;
                        case 'p':
                                printf("\n");
                                if (last_val) {
                                        printf("Stored: %g\n", last_val);
                                } 
                                if (sp > 0) {
                                        for (i = sp - 1; i >= 0; i--) {
                                                printf("Stack(%d): %.8g\n", i + 1, stack[i]);
                                        }
                                }
                                break;
                        case 'c':
                                sp = 0;
                                break;
                        case 'd':
                                if (sp > 0 && sp < MAXVAL) {
                                        stack[sp] = stack[sp - 1];
                                        sp++;
                                } else {
                                        printf("error: no value to duplicate");
                                }
                                break;
                        case 's':
                                if (sp > 1 && sp < MAXVAL) {
                                        double temp = stack[sp - 1];
                                        stack[sp - 1] = stack[sp - 2];
                                        stack[sp - 2] = temp;
                                } else {
                                        printf("error: not enough values to swap");
                                }
                                break;
                        case FUNC:
                                if (strcmp(s, "sin") == 0) {
                                        push(sin(pop()));
                                } else if (strcmp(s, "cos") == 0) {
                                        push(cos(pop()));
                                } else if (strcmp(s, "tan") == 0) {
                                        push(tan(pop()));
                                } else if (strcmp(s, "exp") == 0) {
                                        push(exp(pop()));
                                } else if (strcmp(s, "log") == 0) {
                                        push(log(pop()));
                                } else if (strcmp(s, "pow") == 0) {
                                        op2 = pop();
                                        push(pow(pop(), op2));
                                } else {
                                        printf("error: invalid command");
                                }
                                break;
                        case VAR_set:
                                int set = toupper(s[0]) - 'A';
                                if (set >= 0 && set < 26) {
                                        vars[set] = pop();
                                } else {
                                        printf("error: invalid variable name");
                                }
                                break;
                        case VAR_use:
                                int use = toupper(s[0]) - 'A';
                                if (use >= 0 && use < 26) {
                                        push(vars[use]);
                                } else {
                                        printf("error: invalid variable name");
                                }
                                break;
                        case LAST_val:
                                push(last_val);
                                break;
                        case '\n':
                                last_val = pop();
                                printf("\tResult: %.8g\n", last_val);
                                break;
                        default:
                                printf("error: unkown command %s\n", s);
                                break;
                }
        }
        return 0; 
}



void push(double f) {
        if (sp < MAXVAL) {
                stack[sp++] = f;
        } else {
                printf("error: stack full, can't push %g\n", f);
        }
}

double pop(void) {
        if (sp > 0) {
                return stack[--sp];
        } else {
                printf("error: stack empty\n");
                return 0.0;
        }
}


int getch(void);
void ungetch(int);

int getop(char s[]) {

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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
        if (bufp >= BUFSIZE) {
                printf("ungetch: too many characters\n");
        } else {
                buf[bufp++] = c;
        }
}
