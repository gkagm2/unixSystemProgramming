// need super user 
#include <sys/systeminfo.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	char buf[257];

	if(sysinfo(SI_HW_SERIAL, buf, 257) == -1){
		perror("sysinfo");
		exit(1);
	}
	
	printf("HW serial : %s\n", buf);

	if(sysinfo(SI_ISALIST, buf, 2577) == -1){
		perror("sysinfo");
		exit(1);
	}

	printf("ISA List : %s\n", buf);

	
	return 0;
}
