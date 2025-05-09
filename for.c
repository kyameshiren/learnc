#include <stdio.h>

/* for loop syntax check (init, condition, action) */

int main() {
        int a;
        for (a = 0; getchar() != 'f'; a++)
                ;
        printf("%d\n", a);
}
