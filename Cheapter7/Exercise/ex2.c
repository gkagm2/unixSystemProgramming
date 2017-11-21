#include <stdio.h>
#include <sys/signal.h> //sigset_t 의 구조체를 사용하기위함.
#include <signal.h>
#include <stdlib.h>
int main(void){
	sigset_t st;

	sigemptyset(&st); //시그널 집합을 초기화 해줍니다.

	//SIGQUIT, SIGILL, SIGTRAP 시그널을 설정하기 위해서 sigaddset()로 시그널을 추가한다.
	if(sigaddset(&st, SIGQUIT) == -1) {
		perror("signal addset error");
		exit(1);
	}
	if(sigaddset(&st, SIGILL) == -1) {
		perror("signal addset error");
		exit(1);
	}
	if(sigaddset(&st, SIGTRAP) == -1){
		perror("signal addset error");
		exit(1);
	} //자 3개의 시그널을 설정해 주었습니다.
	
	if(sigismember(&st,SIGOLL)) {//설정되어있으면 1 되어있지 않으면 0을 리턴한다.
		printf("SIGOLL signal is setting\n");
	} else {
		printf("SIGOLL signal is not setting\n");
	}
	//학교 UNIX server에서는 잘 돌아가는데 왜이러는 걸까요
	//비트 패턴을 확일할 수가 없잖아! 왜 안되는거야! 
	pinrtf(" ** Bit Pattern : %x\n",st.__sigbits[0]);
	pinrtf(" ** Bit Pattern : %x\n",st.__sigbits[1]);
	pinrtf(" ** Bit Pattern : %x\n",st.__sigbits[2]);
	pinrtf(" ** Bit Pattern : %x\n",st.__sigbits[3]);


	return 0;
}

