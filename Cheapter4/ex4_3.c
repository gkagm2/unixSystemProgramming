#include <unistd.h>
#include <stdio.h>

int main(void){
	printf("Clock Tick : %ld\n", sysconf(_SC_CLK_TCK));
	printf("Max Open File : %ld\n", sysconf(_SC_OPEN_MAX));
//	printf("Max Login Name Length : %ld\n", sysconf(_SC_LOGNAME_MAX)); //can't compile
	return 0;
}