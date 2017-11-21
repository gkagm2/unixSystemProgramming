#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd, n;
	char ch;
	off_t l;

	if(argc != 2){
		printf("input file name\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1){
		perror("Read");
		exit(1);
	}

	while((n = read(fd, &ch, 1)) > 0){
		l = lseek(fd, 0, SEEK_CUR);
		if(l%2 != 0) {
			printf("%c",ch);
		}
	}
	if( n == -1 )
		perror("Read");

	close(fd);

	return 0;
}
