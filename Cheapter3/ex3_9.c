#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
	symlink("unix.txt","unix.sym");
	return 0;
}
