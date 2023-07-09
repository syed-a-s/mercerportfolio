// Name: Syed Saadat
// Class: CSC460
// Date: 3-24-23
// Title: Bob's Deadly Diner 

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + N) % N
#define MIN 0
#define MAX 10000

// semaphore p operation
p(int s, int sems) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	if((semop(sems, &sops, 1)) == -1)
		printf("%s", "'P' error \n");
}

// semaphore v operation
v(int s, int sems) {
	struct sembuf sops;
	sops.sem_num = s;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	if((semop(sems, &sops, 1)) == -1)
		printf("%s", "'V' error\n");
}

// print n tabs
void PrintTabs(int num_tabs) {
	int i;
	for(i = 0; i < num_tabs; i++)
		printf("\t");
}

// run loop from lower bound to upper bound
int SimulateBusy(int lower, int upper) {
	srand(getpid() * time(NULL));

	int i;
	int rand_int = (rand() % (upper - lower + 1)) + lower;

	for(i = 0; i <= rand_int; i++);
}

// p on left and right chopsticks (semaphores)
void take_chopsticks(int i, int sems) {
	p(LEFT, sems);
	SimulateBusy(MIN, MAX); // simulate time between left and right chopstick
	p(RIGHT, sems);
}

// v on left and right chopsticks (semaphores)
void put_chopsticks(int i, int sems) {
	v(LEFT, sems);
	SimulateBusy(MIN, MAX); // simluate time between left and right chopstick
	v(RIGHT, sems); 
}

// print think state
void think(int local_id) {
	printf("%d: ", local_id);
	PrintTabs(local_id);
	printf("%5s", "THINKING\n");
	SimulateBusy(MIN, MAX);
}

// print hungry state
void hungry(int local_id, int sems) {
	printf("%d: ", local_id);
	PrintTabs(local_id);
	take_chopsticks(local_id, sems);
}

// print eat state
void eat(int local_id, int sems) {
	printf("%d: ", local_id);
	PrintTabs(local_id);
	printf("%5s", "EATING\n");	
	put_chopsticks(local_id, sems);	
}

// create n processes with id 0 to n - 1
void CreateChildren(int n, int *id) {
	int i, pid;
	for(i = 0; i < n; i++) {
		pid = fork();
		if(pid == 0) {
			*id = i + 1;
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	int i, local_id, sems;

	local_id = 0; // main process local id

	// get semaphores
	sems = semget(IPC_PRIVATE, N, 0777);

	if(sems == -1) {
		printf("semget failed\n");
		return -1;
	}

	// initialize semaphores to 1
	for(i = 0 ; i < N; i++) 
		semctl(sems, 1, SETVAL);

	// create four more processes
	CreateChildren(4, &local_id);
	
	// 5 processes enter here
	while(1) {
		think(local_id);		
		hungry(local_id, sems);
		eat(local_id, sems);
	}

	sleep(1);

	// cleanup
	if(local_id == 0)
		if((semctl(sems, 0, IPC_RMID, NULL)) == -1)
			printf("Parent: ERROR in removing sem\n");
	
	return 0;
}
