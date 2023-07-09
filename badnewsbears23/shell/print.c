// prints 1,000 lines

#include <stdio.h>

int main(int argv, char* argc[]) {
	int i;

	for(i = 0; i < 1000; i++)
		printf("I printed %d line(s) :) \n", i + 1);

	return 0;
}
