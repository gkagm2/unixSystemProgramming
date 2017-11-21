#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


void handler(int signo){
	printf("Signal Handler Signal Number : %d\n", signo);
	psignal(signo , "Received Signal");
}

int main(void){
	
	if(sigset(SIGINT, handler) == SIG_ERR){ //sigset은 시그널 핸들러를 지정한다. 
		perror("signal");
		exit(1);
	}

	printf("Wait 1st Ctrl+C ... : SIGINT\n");
	pause();
	printf("After 1st Signal Handler\n");
	printf("Wait 2nd Ctrl+C ... : SIGINT\n");
	pause();
	printf("After 2nd Signal Handler\n");

	return 0;
}
