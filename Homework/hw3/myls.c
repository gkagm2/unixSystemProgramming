#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	DIR *dp;
	struct dirent *dent;
	char *currentDirectory;
	
	currentDirectory = getcwd(NULL,BUFSIZ);

	if((dp = opendir(currentDirectory)) == NULL) {
		perror("opendir");
		exit(1);
	}

	while((dent = readdir(dp))){
		if(dent->d_name[0] == '.')
			continue;
		printf("%s ",dent->d_name);
	}
	printf("\n");

	closedir(dp);

	return 0;
}



