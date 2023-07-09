// Syed Saadat
// CSC460
// 2-27-23
// Super Speedy Synch - Fork and Semaphores

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int IsValidInput(int n) {
	if(n >= 1 && n <= 26)
		return 1;
	else
		return 0;
}

void InitializeSems(int n, int sem_id) {
	int i;

	// parent sem
	semctl(sem_id, 0, SETVAL, 1);

	// children sem
	for(i = 1; i < n; i++) {
		semctl(sem_id, i, SETVAL, 0);
	}
}


void CreateChildren(int n, int *id) {
	int i, pid;
	for(i = 1; i < n; i++) {
		pid = fork();		
		if(pid == 0) {
			*id = i;
			break;
		}
	}
}

p(int s,int sem_id) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	if((semop(sem_id, &sops, 1)) == -1) 
		printf("%s", "'P' error\n");
}


v(int s, int sem_id) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	if((semop(sem_id, &sops, 1)) == -1) 
		printf("%s","'V' error\n");
}

int main(int argc, char* argv[]) {
	int i, n, first_ID, sem_id;
	int loop_count = 5;
	int my_id = 0;

	// need one command line argument
	if(argc != 2) {
		printf("Need one integer argument\n");
		return 1;
	}

	// convert argument to int
	n = atoi(argv[1]);

	// check if between 1-26
	if(!IsValidInput(n)) {
		printf("Need an integer 1-26\n");
		return 1;
	}

	// make a note of parent process
	first_ID = getpid();

	// ask OS for array of semaphores
	sem_id = semget(IPC_PRIVATE, n, 0777);

	// see if you got the request
	if(sem_id == -1) {
		printf("%s", "SemGet Failed.\n");
		return 1;
	}

	// initialize semaphores
	InitializeSems(n, sem_id);

	// fork n times
	CreateChildren(n, &my_id);

	// sync processes 
	for(i = 0; i < loop_count; i++) {
		p(my_id, sem_id);
		printf("%c: %d\n", my_id + 'A', getpid());
		v((my_id + 1) % n, sem_id);
	} 

	sleep(1);

	// cleanup
	if(first_ID == getpid())
		if((semctl(sem_id, 0, IPC_RMID, 0)) == -1)
			printf("%s", "Parent: ERROR in removing sem\n");

	return 0;
}
