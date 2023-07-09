// Name: Syed Saadat
// Class: CSC460
// Date: 4/14/23
// Title: Memory Management 1
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

const char *shm_sem_ids_filename = "shm_sem_ids"; 

// process struct
struct process {
	int id, pid, size, seconds;
};

int GetIDs(const char *filename, int *ids) {
	FILE *fp = fopen(filename, "r");
	int num_ids = 0;

	// read numbers frome file and store in array
    	while (fscanf(fp, "%d,", &ids[num_ids]) == 1) {
		num_ids++;
        }
	fclose(fp);	

	return num_ids;
}

int validate_input(int requested_ram, int requested_time, int *shm_sem_ids) {
	FILE *fp = fopen(shm_sem_ids_filename, "r");
	int *ram, num_rows, num_cols;

	int i;

	ram = (int*) shmat(shm_sem_ids[2], NULL, SHM_RND); // get RAM shared memory
	num_rows = shm_sem_ids[5];
	num_cols = shm_sem_ids[6];

	printf("num of rows: %d\n", num_rows);
	printf("num_cols: %d\n", num_cols);

	// display ram
	for(i = 0; i < num_rows * num_cols; i++) {
		if(i % num_cols == 0) printf("\n");
		printf("%d ", ram[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int *shm_sem_ids = malloc(10 * sizeof(int));
	int num_ids = GetIDs(shm_sem_ids_filename, shm_sem_ids);

	// validate that consumer process is up and running
	int *is_running = (int*) shmat(shm_sem_ids[0], NULL, SHM_RND);	
	if(*is_running != 1) {
		printf("Consumer has not yet started\n");
		return -1;
	} else {
		printf("Producing\n");
	}

	validate_input(30, 25, shm_sem_ids);

	// create jobs for consumer
	return 0;
}

