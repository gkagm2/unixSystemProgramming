#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signo){
	psignal(signo, " received signal : ");
	printf("SIGQUIT signal number : %d\n", signo);
}

int main(void){

	//�ñ׳� �ڵ鷯�� �����ϱ����ؼ��� sigset()�� �ʿ��մϴ�.
	if(sigset(SIGQUIT, handler) == SIG_ERR){ //SIGQUIT signal�� �� handler�Լ��� ����
		perror("sigset error");
		exit(1);
	}
	
	printf("Wait... occur interrupt SIGQUIT -> Ctrl+\\ \n");
	pause();
	printf("Wait2... Ctrl+\\ \n");
	pause();



	return 0;
}
