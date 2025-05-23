#include <stdio.h>

#define BUFFER 20 

int fsearch(int x, int arr[]);

int main(void) {

        int z = 0;
        int arr[BUFFER] = {0};

        while (z < BUFFER) {
                arr[z] = z * 3;
                ++z;
        }

        int x = 54;
        int n = fsearch(x, arr);
        printf("%d\n", n);


}

int fsearch(int x, int arr[]) {

        int low, mid, high;
        low = 0;
        high = BUFFER - 1;
        while (low <= high) {
                mid = (high + low) / 2;
                if (x <= arr[mid]) {
                        high = mid - 1;
                } else {
                        low = mid + 1;
                }
        }
        if (x == arr[mid]) {
                return mid;
        } else {
                return -1;
        }
}

