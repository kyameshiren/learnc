#include <stdio.h>

int main(void) {
        
        char a;
        short b;
        int c;
        long d;
        float e;
        double f;
        char g[100];
        printf("char   : %d byte\n", sizeof(a));
        printf("short  : %d bytes\n", sizeof(b));
        printf("int    : %d bytes\n", sizeof(c));
        printf("long   : %d bytes\n", sizeof(d));
        printf("float  : %d bytes\n", sizeof(e));
        printf("double : %d bytes\n", sizeof(f));
        printf("array  : %d bytes\n", sizeof(g));

}
