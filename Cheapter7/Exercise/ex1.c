#include <sys/signal.h> //sigset_t ����ü�� ����ϱ� ���ؼ� �ʿ���.
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//void handler(int signo){
//	psignal(signo,"Received signal : ");
//}



int main(void){
	sigset_t st;

	sigemptyset(&st); //�ϴ� ������ ���ϴ�. ���Ŀ� 

	//�ñ׳� ���տ� ��� �ñ׳��� �����ϱ� ���ؼ��� sigfillset()�� �ʿ��մϴ�.
	if(sigfillset(&st) == -1) {//st�� �ñ׳� ���� �ּҸ� �˷��ݴϴ�. �׷� ��� �ñ׳��� ������

		perror("signal");
		exit(1);	
	}
	
	//�ñ׳� ���տ� ������ �ñ׳��� Ȯ���մϴ�.
	if(sigismember(&st, SIGBUS) == 1){ //���ԵǸ� 1 ���� �ȵǸ� 0�� ����
		printf("SIGBUS signal is set\n");
	} else {
		printf("SIGBUS signal is not set.\n");
	}

	return 0;
}

