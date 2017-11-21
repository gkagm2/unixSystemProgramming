#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#define BEL 0x07

int count;
void sigcatch(int sig){
	if(sig == SIGQUIT){
		printf("bell was rung %d times\n",count);
		exit(1);
	}
}


int main(void){
	void sigcatch();

	printf("\n<pRESS cTRL+c KEY Bell)  Quit -> Ctrl+\\ \n");


	return 0;
}
