#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void){
	DIR *dp;
	struct dirent *dent;

	if((dp = opendir("hanbit")) == NULL){
		perror("opendir");
		exit(1);
	}

	printf("** Directory content \n");
	printf("Start Offset : %ld\n", telldir(dp));
	while((dent = readdir(dp))){
		printf("Read : %s ", dent->d_name);
		printf("Cur Offset : %ld\n", telldir(dp));
	}

	printf("** Directory Pointer Rewind **\n");
	rewinddir(dp);
	printf("Cur Offset : %ld\n", telldir(dp));

	printf("** Move Directory Pointer **\n");
	seekdir(dp,24);
	printf("Cur Offset : %ld\n", telldir(dp));

	dent = readdir(dp);
	printf("Read : %s\n", dent->d_name);
	printf("Next Offset : %ld\n", telldir(dp));

	return 0;
}
