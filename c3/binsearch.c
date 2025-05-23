#include <stdio.h>

#define BUFFER 20
#define REPEAT 1000000000


int binsearch(int x, int arr[]);

int main(void) {

        int z = 0;
        int arr[BUFFER] = {0};

        while (z < BUFFER) {
                arr[z] = z * 3;
                ++z;
        }

        int x = 15;
        long int i;
        long int sum = 0;
        for (i = 0; i < REPEAT; ++i) {
                sum += binsearch(x, arr);
        }

        printf("%ld\n", sum);

}

int binsearch(int x, int arr[]) {

        int low, mid, high;
        low = 0;
        high = BUFFER - 1;
        while (low != high - 1) {
                mid = (high + low) / 2;
                if (x < arr[mid]) {
                        high = mid - 1;
                } else if (x > arr[mid]){
                        low = mid + 1;
                } else {
                        return mid;
                }
        }
        return -1;
}

