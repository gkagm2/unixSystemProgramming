#include <stdio.h>
#include <unistd.h>

int main(void){
	printf("PID : %d\n",(int)getpid());
	printf("PGRP : %d\n",(int)getpgrp());
	//printf("PGID(0) : %d\n",(int)getpgid());
	printf("PGID(3615) :%d\n", (int)getpgid(3615));


	return 0;
}
