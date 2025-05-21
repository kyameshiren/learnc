#include <stdio.h>

#define MAX_WORD_LENGTH 20

int main() {
    int c, i, len = 0;
    int word_lengths[MAX_WORD_LENGTH] = {0};
    int max_count = 0;

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (len > 0) {
                if (len < MAX_WORD_LENGTH)
                    word_lengths[len]++;
                else
                    word_lengths[MAX_WORD_LENGTH - 1]++;
                len = 0;
            }
        } else {
            len++;
        }
    }

    // Find the highest count for scaling
    for (i = 1; i < MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > max_count) {
            max_count = word_lengths[i];
        }
    }

    // Print vertical histogram
    printf("\nVertical Histogram of Word Lengths:\n");

    for (int row = max_count; row > 0; row--) {
        for (i = 1; i < MAX_WORD_LENGTH; i++) {
            if (word_lengths[i] >= row)
                printf(" # ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // Print the x-axis labels
    for (i = 1; i < MAX_WORD_LENGTH; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    return 0;
}




