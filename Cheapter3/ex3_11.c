#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	char buf[BUFSIZ];
	int n;

	n = readlink("unix.sym", buf, BUFSIZ);
	if(n == -1){
		perror("readlink");
		exit(1);
	}

	buf[n] = '\0';
	printf("unix.sym : READLINK = %s\n",buf);

	return 0;
}
