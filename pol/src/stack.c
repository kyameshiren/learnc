#include <stdio.h>
#include "stack.h"

// Stack implementation
int sp = 0;     // stack pointer
double stack[MAXVAL];   // value stack

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

int get_sp(void) {
        return sp;
}

int print_stack(void) {
        if (sp > 0) {
                for (int i = sp - 1; i >= 0; i--) {
                        printf("Stack(%d): %.8g\n", i + 1, stack[i]);
                }
                return 0;
        }
        return 1;
}

void clear_sp(void) {
        sp = 0;
}

int dup_stack(void) {
        if (sp > 0 && sp < MAXVAL) {
                stack[sp] = stack[sp - 1];
                sp++;
                return 1;
        }
        return 0;
}

int swap_stack(void) {
        if (sp > 1 && sp < MAXVAL) {
                double temp = stack[sp - 1];
                stack[sp - 1] = stack[sp - 2];
                stack[sp - 2] = temp;
                return 1;
        }
        return 0;
}




