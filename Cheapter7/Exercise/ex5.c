#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void){
	sigset_t st; //구조체 하나를 만든다.

	sigemptyset(&st); //전부다 초기화하고
	sigaddset(&st,SIGINT); //SIGINT만 넣는다.
	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL); //st에 SIGINT가 있으니 Ctrl_C를 할 때 블록 될 것이다.

	printf("종료 시키려면 ctrl + \\을 눌러라. \n");

	//Habit Books을 1초마다 출력하기위한 소스코드
	while(1){ // Ctrl+\을 하면 종료되기 때문에 예외를 만들지 않았음.
		printf("Hanbit Books\n");
		sleep(1);
	}


	return 0;
}
