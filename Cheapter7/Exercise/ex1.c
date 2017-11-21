#include <sys/signal.h> //sigset_t 구조체를 사용하기 위해서 필요함.
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//void handler(int signo){
//	psignal(signo,"Received signal : ");
//}



int main(void){
	sigset_t st;

	sigemptyset(&st); //일단 집합을 비웁니다. 그후에 

	//시그널 집합에 모든 시그널을 설정하기 위해서는 sigfillset()이 필요합니다.
	if(sigfillset(&st) == -1) {//st의 시그널 집합 주소를 알려줍니다. 그럼 모든 시그널이 설정됨

		perror("signal");
		exit(1);	
	}
	
	//시그널 집합에 설정된 시그널을 확인합니다.
	if(sigismember(&st, SIGBUS) == 1){ //포함되면 1 포함 안되면 0을 리턴
		printf("SIGBUS signal is set\n");
	} else {
		printf("SIGBUS signal is not set.\n");
	}

	return 0;
}

