#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *currentDirectory;
	FILE *rfp, *wfp;
	char buf[BUFSIZ];
	int n;
	

	if(argc != 3){
		printf("error\n");
		exit(1);
	}
	if((rfp = fopen(argv[1],"r")) == NULL) {
		perror("fopen : read");
		exit(1);
	}

	chdir(argv[2]);
	

	
	if((wfp = fopen(argv[1],"w")) == NULL) {
		perror("fopen : write");
		exit(1);
	}

	while((n = fread(buf, sizeof(char)*2, 3, rfp)) > 0) {
		fwrite(buf, sizeof(char)*2,n,wfp);
	}

	currentDirectory = getcwd(NULL,BUFSIZ);
	printf("위치 : %s\n",currentDirectory);
	//chdir(strcat(currentDirectory,"/.."));
	chdir(strcat(currentDirectory,"/.."));
	printf("이동 위치 : %s\n",currentDirectory);
	
	remove(argv[1]);


	fclose(rfp);
	fclose(wfp);
	return 0;
}
