// Name : Syed Saadat
// Class : CSC 460
// Date : 3-31-23
// TItle : Bob's Bank
// NOTE : compile with -lm

#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define INIT_BALANCE 1000
#define MUTEX 0

// semaphore p operation
p(int s,int sem_id) {
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
		printf("%s","'V' error\n");
}

// get shared memory and semaphore id from file
void GetID(int *shm_id, int *sem_id, const char *file_name) {
	FILE *fopen(), *fp;
	fp = fopen(file_name, "r");

	if(fp == NULL) {
		printf("File does not exist\n");
	} else {
		// read first number and then second number
		fscanf(fp, "%d\n%d", shm_id, sem_id);
		fclose(fp);
	}
}

// check if program has started by checking if file exists
int IsRunning(const char *file_name) {
	FILE *fopen(), *fp;

	// try to read file
	fp = fopen(file_name, "r");

	if(fp == NULL)
		return 0;
	else
		return 1;
}

// get shared memory, semaphores, and write ids into file. set balance to 1000
void InitializeProgram(int shm_id, int sem_id, int *balance, const char *file_name) {
	FILE *fopen(), *fp;

	if(!IsRunning(file_name)) {
		printf("Creating shared memory, semaphores, and file with IDs\n");

		// create file
		fp = fopen(file_name, "w");

		// get shared memory
		shm_id = shmget(IPC_PRIVATE, sizeof(int), 0777);
		if(shm_id == -1) {
			printf("Could not get shared memory\n");
			return;
		}
		
		// get semaphores
		sem_id = semget(IPC_PRIVATE, 1, 0777);

		if(sem_id == -1) {
			printf("SemGet failed\n");
			return;
		}

		// intialize shared memory (balance)
		balance = (int *) shmat(shm_id, NULL, SHM_RND);
		*balance = INIT_BALANCE;

		// write shm_id and sem_id to file
		fprintf(fp, "%d\n", shm_id);
		fprintf(fp, "%d\n", sem_id);

		fclose(fp);
	} else {
		printf("Program has already been started\n");
	} 
}

// bob's bank parent/child simulation
void BobBank(int shm_id, int sem_id, int num_of_trials, int *balance) {
	int i, local_id;
	int num_parents;

	local_id = 0;
	num_parents = 16;

	// attach to shared memory
	balance = (int *) shmat(shm_id, NULL, SHM_RND);

	// initialize semaphore
	semctl(sem_id, MUTEX, SETVAL, 1);

	// fork and initialize parents' ids
	for(i = 1; i < num_parents; i++) {
		if(fork() == 0) {
			local_id = i;
			break;
		}
	}

	// all parent processes
	if(fork() != 0) {
		for(i = 0; i < num_of_trials; i++) {
			p(MUTEX, sem_id);
			int deposit_amount = (int) pow(2, local_id);
			printf("%d + %d = %d\n", *balance, deposit_amount, *balance + deposit_amount);
			*balance += deposit_amount;
			v(MUTEX, sem_id);
		}
	// all child processes
	} else {
		for(i = 0; i < num_of_trials; i++) {
			p(MUTEX, sem_id);
			int withdrawal_amount = (int) pow(2, local_id);
			printf("\t\t\t%d - %d = %d\n", *balance, withdrawal_amount, *balance - withdrawal_amount);
			*balance -= withdrawal_amount;
			v(MUTEX, sem_id);
		}
	}

	sleep(1);
}

// print shared memory value
void PrintBalance(int shm_id, int *balance) {
	balance = (int *) shmat(shm_id, NULL, SHM_RND);
	printf("Balance: %d\n", *balance);
}

// clean shared memory, semaphores, and file
void Die(int shm_id, int sem_id, const char *file_name) {
	// remove shared memory
	if((shmctl(shm_id, IPC_RMID, NULL)) == -1)
		printf("Error removing shared memory\n");
	else
		printf("Shared memory removed\n");

	// remove semaphores
	if((semctl(sem_id, 0, IPC_RMID, NULL)) == -1)
		printf("Error removing semaphores\n");
	else
		printf("Semaphores removed\n");

	// delete file
	if(remove(file_name) == 0)
		printf("File removed\n");
	else
		printf("Error removing file\n");
}

int main(int argc, char* argv[]) {
	int shm_id, sem_id;
	int local_id, *balance;
	const char file_name[5] = "ids";

	switch(argc) {
		case 1:
			// no argument
			InitializeProgram(shm_id, sem_id, balance, file_name);
			break;
		case 2: {
			// if file doesn't exist, kill program
			if(!IsRunning(file_name)) { 
				printf("Can't do that - Program has not yet started\n");
				break;
			}

			int num = atoi(argv[1]); // get num from argument
			GetID(&shm_id, &sem_id, file_name); // get shm and sem id from file

			// int 1-100 arg - run simulation n times
			if(num >= 1 && num <= 100) {
				BobBank(shm_id, sem_id, num, balance);
			// balance argument - print argument
			} else if(strcmp(argv[1], "balance") == 0) {
				PrintBalance(shm_id, balance);
			// die argument - kill shm, sems, and file
			} else if(strcmp(argv[1], "die") == 0) {
				Die(shm_id, sem_id, file_name);
			// otherwise invalid
			} else {
				printf("Invalid argument: '%s'\n", argv[1]);
			}

			break;
		}
		default:
			printf("Invalid number of arguments\n");
			break;
	}

	return 0;
}
