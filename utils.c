#include <stdio.h>
#include "utils.h"

void print_binary(unsigned int x) {
    int i;
    int size = sizeof(x) * 8; // Usually 32 bits

    for (i = size - 1; i >= 0; --i) {
        putchar((x & (1u << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' '); // Optional: add space every 8 bits
    }
    putchar('\n');
}
