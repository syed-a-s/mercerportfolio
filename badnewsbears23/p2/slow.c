// Syed Saadat
// CSC 460
// 2-10-23
// Slow Synch - Fork and Files

#include <stdio.h>

int IsValidInput(int n) {
	if(n > 0 && n <= 26)
		return 1;
	else
		return 0; 
}

void CreateChildren(int num_of_children, int *id, int *other_id) {
	int i, pid;

	for(i = 1; i <= num_of_children; i++) {
		pid = fork();
		if(pid == 0) {
			*id = 'A' + i;

			// making sure last process points back to first
			if(i < num_of_children)  
				*other_id = 'A' + i + 1;
			else
				*other_id = 'A';

			break;
		} 
	}
}

int main(int argc, char** argv) {
	FILE *fopen(), *fp;

	// check user input
	int N = atoi(argv[1]) - 1;

	if(!IsValidInput(N))
		return 0;

	// open file to write a value
	if((fp = fopen("syncfile", "w")) == NULL) {
		printf("Could not open file to write :( \n");
		return 0;
	}

	// write into syncfile ID of whose turn
	fprintf(fp, "%d", 'A');
	fclose(fp);

	// assign parent and child processes their own id
	int my_id = 'A';
	int other_id = 'A' + 1;

	CreateChildren(N, &my_id, &other_id); // child processes' ids

	// loop 5 times
	int i, found;
	
	for(i = 0; i < 5; i++) {
		// repeatedly check file until my_id is found
		found = -1;
		while(found != my_id) {
			//printf("%d %d\n", found, my_id);
			//sleep(1);
			if((fp = fopen("syncfile", "r")) == NULL) {
				printf("Could not open syncfile to read :(\n");
				return 0;
			}

			fscanf(fp, "%d", &found);
			fclose(fp);
		}

		// it must be my turn to do something....
		printf("%c: %d\n", my_id, getpid());

		// update file to allow other_id to go
		if((fp = fopen("syncfile", "w")) == NULL) {
			printf("Could not open file to write :(\n");
			return 0;
		}	

		fprintf(fp, "%d", other_id);
		fclose(fp);
	}

	sleep(1);

	return 0;
}
