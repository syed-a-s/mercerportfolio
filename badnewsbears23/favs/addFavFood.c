// Syed Saadat
// CSC 460
// 2-22-23
// Favs List

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
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
	char fav_food[20];

	if(argc != 2) {
		printf("Error: one argument needed\n");
		return 0;
	}

	// truncate to 20 characters at most
	strncpy(fav_food, argv[1], 19);
	fav_food[19] = '\0';

	// get memory id 
	shmid = GetMemID("/pub/csc460/bb/BBID.txt");

	// get shared memory
	favs = (struct bbStruct *) shmat(shmid, NULL, SHM_RND);

	// update fav num
	strcpy((favs + (SYED_ID - 1))->favFood, fav_food);

	// detach shared memory	
	if(shmdt(favs) == -1)
		printf("shmgm: ERROR in detaching\n");	
}

