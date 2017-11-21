#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int rfd;
	int wfd;
	int n;
	char buf[10];
	if(argc != 3) {
		printf("input two files name");
		exit(1);
	}
	rfd = open(argv[1], O_RDONLY);
	if(rfd == -1){
		perror("Read");
		exit(1);
	}
	wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if(wfd == -1){
		perror("Write");
		exit(1);
	}

	while(( n = read(rfd, buf, 10)) > 0) {
		if(write(wfd, buf, n) != n)
			perror("Write");
	}

	close(rfd);
	close(wfd);




	return 0;
}
