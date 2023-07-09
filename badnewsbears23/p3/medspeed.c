// Syed Saadat
// CSC 460
// 2-17-23
// Medium Speed Synch - Fork and Shared Memory

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define TURN shmem[0]

int IsValidInput(int n) {
	if(n >= 1 && n <= 26)
		return 1;
	else
		return 0;
}

main(int argc, char *argv[]) {
	int i, shmid, *shmem;
	int n;                  // Holds the number of procs to generate
	int my_ID = 0;          // used to identify procs in sync
	int loop_count = 5;     // Times each proc will "speak"

	// need one command line argument 
	if(argc < 2) {
		printf("Need 1 command line argument\n");
		return 0;
	}

	n = atoi(argv[1]);

	// check if between 1-26
	if(!IsValidInput(n)) {
		printf("Need a number 1-26\n");
		return 0;
	}

	// Make a note of "who" is the first Process
	int firstID = getpid();

	// Get Shared Memory and ID
	shmid  =  shmget(IPC_PRIVATE, sizeof(int), 0770);
	if (shmid == -1) {
		printf("Could not get shared memory.\n");
		return(0);
	}

	// Attach to the shared memory
	shmem = (int *) shmat(shmid, NULL, SHM_RND);

	// Initialize teh shared memory
	TURN = 0;

	// Spawn all the Processes
	for (i = 1; i < n; i++) {
  		if (fork() > 0) break; // send parent on to Body
  		my_ID++;
	}

	// BODY  OF  PROGRAM 
	for (i = 0; i < loop_count; i++) {
		while(TURN != my_ID);
        	printf("%c: %d\n",my_ID + 'A', getpid());
        	TURN = (TURN + 1) %  + n;
   	}

	// Detach and clean-up the shared memory  ******/
	if (shmdt(shmem) == -1 ) printf("shmgm: ERROR in detaching.\n");

	sleep(1);

	if (firstID == getpid())         // ONLY need one process to do this
		if ((shmctl(shmid, IPC_RMID, NULL)) == -1)
    			printf("ERROR removing shmem.\n");
}

