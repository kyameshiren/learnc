#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "stack.h"
#include "getch.h"

// Constants for tokens
#define MAXOP 100

// Variable storage
double vars[26];        // variable array
double last_val;

int main(void) {

        int type;
        double op2;
        char s[MAXOP];
        int error = 0;
        int hold = 0;

        while ((type = op(s)) != EOF ) {

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
                                        error++;
                                }
                                break;
                        case '%':                              
                                op2 = pop();
                                push((int)pop() % (int)op2);    // CAST TO INT, HANDLE MOD
                                break;
                        case 'p':
                                printf("\n");
                                if (last_val) {
                                        printf("stored: %g\n", last_val);
                                } 
                                if (print_stack()) {
                                        printf("error: unable to print\n");
                                        error++;
                                }
                                break;
                        case 'c':
                                clear_sp();
                                printf("stack cleared\n");
                                hold++;
                                break;
                        case 'd':
                                if (!dup_stack()) {
                                        printf("error: unable to duplicate\n");
                                        error++;
                                }
                                break;
                        case 's':
                                if (!swap_stack()) {                                
                                        printf("error: unable to swap\n");
                                        error++;
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
                                        error++;
                                }
                                break;
                        case VAR_set:
                                int set = toupper(s[0]) - 'A';
                                if (set >= 0 && set < 26) {
                                        vars[set] = pop();
                                        hold++;
                                } else {
                                        printf("error: invalid variable name");
                                        error++;
                                }
                                break;
                        case VAR_use:
                                int use = toupper(s[0]) - 'A';
                                if (use >= 0 && use < 26) {
                                        push(vars[use]);
                                } else {
                                        printf("error: invalid variable name");
                                        error++;
                                }
                                break;
                        case LAST_val:
                                push(last_val);
                                hold++;
                                break;
                        case '\n':
                                if (!error && !hold && get_sp() > 0) {
                                        last_val = pop();
                                        printf("\tResult: %.8g\n", last_val);
                                }
                                error = 0;
                                hold = 0;
                                break;
                        default:
                                printf("error: unkown command %s\n", s);
                                error++;
                                break;
                } 
        }
        return 0; 
}

