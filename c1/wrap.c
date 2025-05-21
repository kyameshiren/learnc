#include <stdio.h>


// get character
// if position > limit
//	print \n


#define LIMIT 20

int main(void) {

	int len = 0;	
	int c;

	while ((c = getchar()) != EOF) {
		++len;
		while (len > LIMIT) {
			printf("\n    / ");
			len = 10;
		}
		if (c == '\n') {
			len = 0;
		} 
		putchar(c);
	}
}
