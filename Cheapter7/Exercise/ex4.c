#include <stdio.h>
#include <signal.h>// sigaction()을 사용하기위해서 필요합니다.
#include <stdlib.h>
void handler(int signo){
	struct sigaction act;
	psignal(signo,"received signal");

	//한번 핸들러가 실행이 되었으면 기본 처리 방법으로 설정을 바꿔주자.
	//기본 처리 방법이 어떤 방법이지??
}

int main(void){

	struct sigaction act; //sigaction구조체가  필요합니다.

	sigemptyset(&act.sa_mask); //시그널 집합을 초기화하기위한것인데 act구조체의 as_mask가 sigset_t로 되어있으니 이걸로 하면 됨.

	//SIGQUIT의 시그널을 설정해줍니다.
	sigaddset(&act.sa_mask, SIGQUIT);

	act.sa_flags =0; //설정이 되어있지 않으면 sa_handler가 사용됨.따라서 0 설정함

	//SIGQUIT의 신호가 왔을 때 handler함수로 처리를 해주기 위하여
	act.sa_handler = handler; 

	if(sigaction(SIGQUIT, &act, (struct sigaction *)NULL) == -1) { //수행을 성공시 0 실패시 -1을 리턴.
		perror("sigaction ");
		exit(1);
	}
	pause();

	pause();
	return 0;
}
