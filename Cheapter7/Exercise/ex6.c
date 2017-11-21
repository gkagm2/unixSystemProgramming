#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void handler(int signo){
	printf("Wake up\n");
}
int main(void) {
	sigset_t st; //시그널 집합을 담을 구조체 변수한 선언

	sigemptyset(&st); //초기화 해줍니다.
	
	if(sigfillset(&st) == -1){//시그널 집합에 모든 시그널을 1로 설정합니다.
		perror("sigfillset");//실패시 오류메시지 출력
		exit(1);
	}
	sigdelset(&st, SIGINT); //SIGINT의시그널은 제외시킨다

	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);//st에 SIGINT를 제외한 모든 시그널들일 경우 BLOCK하게끔 한다.
	
	sigset(SIGALRM, handler); //알람시그널이 발생될시 handler함수 호출

	while(1){ //1초마다 Wake up 메시지를 출력하기위한 반복문.
		alarm(1);
		sleep(1);
	}
	return 0;
}
