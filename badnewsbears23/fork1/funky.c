// Syed Saadat
// CSC 460
// 2-1-23
// Funky Forks - C program

#include <stdio.h>

int main(int argc, char** argv) {
	int N;
	int children;

	if(argc != 2) {
		printf("Invalid number of arguments\n");
		return 0;
	}

	N = atoi(argv[1]);

	if(N > 5) {
		printf("Number must be less than 5\n");
		return 0;
	}

	if (N < 0) {
		printf("Number must be positive\n");
		return 0;
	}

	printf("GEN\tPID\tPPID\n");

	int i, j;
	for(i = 0; i < N + children; i++) {
		if(fork() == 0) {
			children++;
			break;
		}

	}

	printf("%d\t%d\t%d\n", children, getpid(),getppid());
	sleep(1);

	return 0;
}

