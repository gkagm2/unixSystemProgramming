#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signo){
	psignal(signo, "Received Signal:");
	sleep(5);
	printf("In Signal Handler, After Sleep\n");
}

int main(void){
	struct sigaction act;
	
	sigemptyset(&act.sa_mask); //시그널 집합 비우기
	sigaddset(&act.sa_mask, SIGQUIT); //시그널 집합에 시그널 설정 추가
	act.sa_flags = 0; //sa_flags에는 아무 플래그도 지정하지 않는다.
	act.sa_handler = handler;
	if(sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {
		perror("sigaction");
		exit(1);
	}

	fprintf(stderr,"Input SIGINT : ");
	pause();
	fprintf(stderr,"After Signal Handler\n");

	return 0;

}
