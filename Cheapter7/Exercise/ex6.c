#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void handler(int signo){
	printf("Wake up\n");
}
int main(void) {
	sigset_t st; //�ñ׳� ������ ���� ����ü ������ ����

	sigemptyset(&st); //�ʱ�ȭ ���ݴϴ�.
	
	if(sigfillset(&st) == -1){//�ñ׳� ���տ� ��� �ñ׳��� 1�� �����մϴ�.
		perror("sigfillset");//���н� �����޽��� ���
		exit(1);
	}
	sigdelset(&st, SIGINT); //SIGINT�ǽñ׳��� ���ܽ�Ų��

	sigprocmask(SIG_BLOCK, &st, (sigset_t *)NULL);//st�� SIGINT�� ������ ��� �ñ׳ε��� ��� BLOCK�ϰԲ� �Ѵ�.
	
	sigset(SIGALRM, handler); //�˶��ñ׳��� �߻��ɽ� handler�Լ� ȣ��

	while(1){ //1�ʸ��� Wake up �޽����� ����ϱ����� �ݺ���.
		alarm(1);
		sleep(1);
	}
	return 0;
}
