#include <stdio.h>

int main()
{
        double nc;
        nc = 0;
        while (getchar() != EOF)
                ++nc;
        printf("%d\n", nc - 1);
}
