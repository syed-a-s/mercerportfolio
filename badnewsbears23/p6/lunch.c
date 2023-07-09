// Syed Saadat
// CSC460
// 3-17-23
// Dining Philosopher

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <time.h>

#define N 5 // # of philosophers
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define MUTEX 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define DEAD 3

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

// sleep from lower to upper # of seconds
void RandomSleep(int lower, int upper) {
	srand(getpid() * time(NULL));
	int rand_time = (rand() % (upper - lower + 1)) + lower;
	sleep(rand_time);
}

// set neigbors to eating if possible
void test(int i, int sems, int *state) {
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[i] = EATING;
		v(i, sems);	
	}	
}

// sleep from 4 to 10 seconds
void think() {
	RandomSleep(4, 10);
}

// sleep from 1 to 3 seconds
void eat() {
	RandomSleep(1, 3);
}

// try to take forks
void take_forks(int i, int sems, int *state) {
	p(MUTEX, sems);
	state[i] = HUNGRY;
	test(i, sems, state);
	v(MUTEX, sems);
	p(i, sems);
}

// put forks away and see if neighbors can eat
void put_forks(int i,int sems, int *state) {
	p(MUTEX, sems);
	state[i] = THINKING;
	test(LEFT, sems, state);
	test(RIGHT, sems, state);
	v(MUTEX, sems);
}

// think, get hungry, eat, repeat
void philosopher(int i, int sems, int *state, int life_span) {
	int iterator;

	for(iterator = 0; iterator < life_span; iterator++) {
		think();			
		take_forks(i, sems, state);
		eat();
		put_forks(i, sems, state);
	}

	state[i] = DEAD;
}

// check if all philosophers are dead
int IsAllDead(int *state) {
	int i;

	for(i = 0; i < N; i++) {
		if(state[i] != DEAD)
			return 0;
	}

	return 1;
}

// convert state to coressponding string
const char* StateToString(int state) {
	switch(state) {
		case(THINKING):
			return "thinking";
		case(HUNGRY):
			return "hungry";
		case(EATING):
			return "eating";
		case(DEAD):
			return "dead";
		default:
			return "unknown";
	}
}

// print the state of each philosopher
void PrintPhilosophers(int *state) {
	int i, j, all_dead;

	for(i = 0; all_dead != 1;i++) {
		printf("%d.", i);
		for(j = 0; j < N; j++)
			printf("%10s", StateToString(state[j]));
		printf("\n");
		all_dead = IsAllDead(state);
		sleep(1);
	}	
}
// create n processes and assign sequential ids 
void CreateChildren(int n, int *id) {
	int i, pid;
	for(i = 0; i < n; i++) {
		pid = fork();		
		if(pid == 0) {
			*id = i;
			break;
		}
	}
}

// super specific intialization function
void InitializeSems(int n, int sems) {
	int i;

	// set sem 0-n to 0 (philosophers)
	for(i = 0; i < n; i++)
		semctl(sems, i, SETVAL);
	
	// set sem n (5 in this case) to 1 (MUTEX)
	semctl(sems, MUTEX, SETVAL, 1); 	
}


int main(int argc, char* argv[]) {
	int local_id, total_seconds;
	int i, shmid, sems, *state;

	local_id = -1; // philospher id (main is -1)
	total_seconds = 6;

	// get shared memory and semaphores
	shmid = shmget(IPC_PRIVATE, sizeof(int) * N, 0770);
	if(shmid == -1) {
		printf("Could not get shared memory\n");
		return -1;
	}

	// attach to the shared memory
	state = (int *) shmat(shmid, NULL, SHM_RND);

	// intialize the state shared memory to thinking
	for(i = 0; i < N; i++) 
		state[i] = THINKING;

	// get semaphores for n philsophers and 1 mutex
	sems = semget(IPC_PRIVATE, N + 1, 0777);

	if(sems == -1) {
		printf("SemGet Failed\n");
		return -1;
	}

	// intialize semaphores
	InitializeSems(N, sems);

	// spawn processes (philosophers)
	CreateChildren(N, &local_id);

	// philosophers
	if(local_id != -1) {
		philosopher(local_id, sems, state, total_seconds);
	// main program
	} else {
		PrintPhilosophers(state);
	}

	sleep(1);

	// detach and cleanup the shared memory
	if(shmdt(state) == -1) printf("shmgm: ERROR in detaching\n");

	// only one process needs to do this
	if(local_id == -1) 
		if((shmctl(shmid, IPC_RMID, NULL)) == -1) // remove shared memory
			printf("ERROR removing shmem\n");

	if(local_id == -1)
		if((semctl(sems, 0, IPC_RMID, 0)) == -1) // remove semaphores
			printf("Parent: ERROR in removing sem\n");

	return 0;
}
