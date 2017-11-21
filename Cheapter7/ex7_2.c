#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signo){

	printf("Signal Handler Signal Number : %d\n", signo);
	psignal(signo, "Received Signal");
}
int main(void){
	void (*hand)(int);

	hand = signal(SIGINT, handler); //SIGINT 는 Ctrl + C를 입력 시 . 신호
	if(hand == SIG_ERR){
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
