// Syed Saadat
// CSC 460
// 2-22-23
// Favs List

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

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

	// get memory id 
	shmid = GetMemID("/pub/csc460/bb/BBID.txt");

	// get shared memory
	favs = (struct bbStruct *) shmat(shmid, NULL, SHM_RND);

	// print struct info
	for(i = 0; i < 12; i++) 
		printf("%2d: %20s| %8d| %30s\n",(favs + i)->id, (favs + i)->name, (favs + i)->favNum, (favs + i)->favFood);
	
	// detach shared memory	
	if(shmdt(favs) == -1)
		printf("shmgm: ERROR in detaching\n");	
}
