#include <stdio.h>
#include <signal.h>


int main(void){
	sigset_t st;

	sigemptyset(&st); //시그널 집합 비우기
	
	//시그널 집합에 시그널 추가
	sigaddset(&st, SIGINT); //ctrl + c 누를 때
	sigaddset(&st, SIGQUIT); // 종료신호로 ctrl + \ 누를 
	
	//시그널 집합에 설정된 시그널 확인
	if(sigismember(&st, SIGINT)) {
		printf("SIGINT is setting \n");
	}

	//sigbit는 무엇인가. 
	printf("** Bit pattern : %x\n", st._sigbits[0]);
	return 0;
}
