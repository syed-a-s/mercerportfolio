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

#define MAX_ROWS 20
#define MAX_COLS 50
#define MAX_BUFFERSIZE 26
#define MAX_IDS 30 

const char *shm_sem_ids_filename = "shm_sem_ids";

// process struct
struct process {
	int id, pid, size, seconds;
};

// semaphore p operation
p (int s,int sem_id) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	if((semop(sem_id, &sops, 1)) == -1) 
		printf("%s", "'P' error\n");
}

// semaphore v operation
v(int s, int sem_id) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	if((semop(sem_id, &sops, 1)) == -1)
		printf("%s", "'V' error\n");
}

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

int is_running(const char *filename) {
	// try to read file
	FILE *fp = fopen(filename, "r");

	if(fp == NULL)
		return 0;
	else
		return 1;
}

// used to verify command line arguments and intialize "RAM" and queue
int initialize(int argc, char* argv[], int *num_rows, int *num_cols, int *buffer_size) {
	FILE *fp;
	int temp_id, *shm;
	int i;

	if(is_running(shm_sem_ids_filename)) {
		printf("Consumer is already running\n");
		return 1;
	}

	// validate command line arguments
	if(argc != 4) {
		printf("Invalid arguments. Need 'num_rows num_cols buffer_size'\n");
		return 1;
	} 

	// initialize command line arguments
	*num_rows = atoi(argv[1]);
	*num_cols = atoi(argv[2]);
	*buffer_size = atoi(argv[3]);

	// validate that requested rows, cols, buffer size does not exceed max
	if(*num_rows > MAX_ROWS || *num_cols > MAX_COLS || *buffer_size > MAX_BUFFERSIZE) {
		printf("Invalid Arguments %d %d %d. Max rows, cols, buffer size is %d %d %d\n", 
			*num_rows, 
			*num_cols, 
			*buffer_size, 
			MAX_ROWS, 
			MAX_COLS, 
			MAX_BUFFERSIZE
		);

		return 1;
	}

	// open the file to write ids to
	fp = fopen(shm_sem_ids_filename, "w");	

	// create boolean variable for checking if program is running
	temp_id = shmget(IPC_PRIVATE, sizeof(int), 0777);	
	if(temp_id == -1) {
		printf("Could not get shared memory for is_running boolean\n");
		return 1;
	}
	shm = (int *) shmat(temp_id, NULL, SHM_RND);
	*shm = 1;
	fprintf(fp, "%d,", temp_id);

	// create buffer queue shared memory
	temp_id = shmget(IPC_PRIVATE, sizeof(struct process) * *buffer_size, 0777);	
	if(temp_id == -1) {
		printf("Could not get shared memory for buffer size\n");
		return 1;
	}
	fprintf(fp, "%d,", temp_id);

	// create RAM shared memory
	temp_id = shmget(IPC_PRIVATE, sizeof(int) * (*num_rows * *num_cols), 0777);	
	if(temp_id == -1) {
		printf("Could not get shared memory for buffer size\n");
		return 1;
	}
	fprintf(fp, "%d,", temp_id);

	// get empty semaphore array
	temp_id = semget(IPC_PRIVATE, *buffer_size, 0777);
	if(temp_id == -1) {
		printf("Could not get semaphores for empty\n");
		return 1;
	}
	fprintf(fp, "%d,", temp_id);
	
	// get full semaphore array
	temp_id = semget(IPC_PRIVATE, *buffer_size, 0777);
	if(temp_id == -1) {
		printf("Could not get semaphores for full\n");
		return 1;
	}
	fprintf(fp, "%d,", temp_id);

	// write num_rows and num_cols to file
	fprintf(fp, "%d,%d,%d", *num_rows, *num_cols, *buffer_size);
	fclose(fp);

	return 0;
} 

void display_ram(int num_rows, int num_cols, int buffer_size) {
	int i, j, num_ids;
	int *shm_sem_ids; 

	// get shared memory and semaphore ids
	shm_sem_ids = malloc(MAX_IDS * sizeof(int));
	num_ids = GetIDs(shm_sem_ids_filename, shm_sem_ids);
 	
	// manage memory
	int *ram = (int *) shmat(shm_sem_ids[2], NULL, SHM_RND);
	for(i = 0 ; i < num_rows * num_cols; i++) 
		ram[i] = i;
	
	// display ram
	for(i = 0; i < num_rows * num_cols; i++) {
		if(i % num_cols == 0) printf("\n");
		printf("%d ", ram[i]);
	}
	printf("\n");
	
}

int main(int argc, char *argv[]) {
	int num_rows, num_cols, buffer_size;

	if(initialize(argc, argv, &num_rows, &num_cols, &buffer_size) == 1) {
		return 1;	
	}

	display_ram(num_rows, num_cols, buffer_size);

	return 0;
}




