#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){
	struct stat buf;

	stat("unix.txt",&buf);

	printf("Mode = %o (16Áø¼ö : %x)\n",(unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	if(S_ISFIFO(buf.st_mode))
		printf("unix.txt : FIFO\n");
	
	return 0;
}
