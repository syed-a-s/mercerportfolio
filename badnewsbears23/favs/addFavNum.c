// Syed Saadat
// CSC 460
// 2-22-23
// Favs List

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SYED_ID 10

struct bbStruct {
	int id;
	char name[20];
	int favNum;
	char favFood[30];
};

int GetMemID(char *path) {
	FILE *fopen(), *fp;
	int ID;

	if((fp = fopen(path, "r")) == NULL) {
		printf("Could not open file to read :(\n");
		return -1;
	}

	fscanf(fp, "%d", &ID);
	fclose(fp);

	return ID;
}

main(int argc, char* argv[]) {
	int i, shmid;
	struct bbStruct *favs; 

	if(argc != 2) {
		printf("Error: one integer argument needed\n");
		return 0;
	}

	int fav_num = atoi(argv[1]);

	if(fav_num == 0 && *argv[1] != '0') {
		printf("Error: '%s' is not an integer\n", argv[1]);
		return(0);
	} 

	// get memory id 
	shmid = GetMemID("/pub/csc460/bb/BBID.txt");

	// get shared memory
	favs = (struct bbStruct *) shmat(shmid, NULL, SHM_RND);

	// update fav num
	(favs + (SYED_ID - 1))->favNum = fav_num;

	// detach shared memory	
	if(shmdt(favs) == -1)
		printf("shmgm: ERROR in detaching\n");	
}
