#include <stdio.h>

int main()
{
        int fahr; 
        float celc;
        int start = 0, end = 300;
        int step = 10;
        fahr = start;

        printf("Fahr |  Celc\n");
        printf("-------------\n");

        while (fahr <= end)
        {
                celc = (5.0 / 9.0) * (fahr - 32);
                printf("%4d : %6.2f\n", fahr, celc);
                fahr += step;
         }
}
                
        
