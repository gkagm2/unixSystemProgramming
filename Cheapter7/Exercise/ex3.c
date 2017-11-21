#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo){
	psignal(signo, " received signal : ");
	printf("SIGQUIT signal number : %d\n", signo);
}

int main(void){

	//시그널 핸들러를 지정하기위해서는 sigset()이 필요합니다.
	if(sigset(SIGQUIT, handler) == SIG_ERR){ //SIGQUIT signal일 때 handler함수로 가슈
		perror("sigset error");
		exit(1);
	}
	
	printf("Wait... occur interrupt SIGQUIT -> Ctrl+\\ \n");
	pause();
	printf("Wait2... Ctrl+\\ \n");
	pause();



	return 0;
}
