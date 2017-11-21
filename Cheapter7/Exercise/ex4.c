#include <stdio.h>
#include <signal.h>// sigaction()�� ����ϱ����ؼ� �ʿ��մϴ�.
#include <stdlib.h>
void handler(int signo){
	struct sigaction act;
	psignal(signo,"received signal");

	//�ѹ� �ڵ鷯�� ������ �Ǿ����� �⺻ ó�� ������� ������ �ٲ�����.
	//�⺻ ó�� ����� � �������??
}

int main(void){

	struct sigaction act; //sigaction����ü��  �ʿ��մϴ�.

	sigemptyset(&act.sa_mask); //�ñ׳� ������ �ʱ�ȭ�ϱ����Ѱ��ε� act����ü�� as_mask�� sigset_t�� �Ǿ������� �̰ɷ� �ϸ� ��.

	//SIGQUIT�� �ñ׳��� �������ݴϴ�.
	sigaddset(&act.sa_mask, SIGQUIT);

	act.sa_flags =0; //������ �Ǿ����� ������ sa_handler�� ����.���� 0 ������

	//SIGQUIT�� ��ȣ�� ���� �� handler�Լ��� ó���� ���ֱ� ���Ͽ�
	act.sa_handler = handler; 

	if(sigaction(SIGQUIT, &act, (struct sigaction *)NULL) == -1) { //������ ������ 0 ���н� -1�� ����.
		perror("sigaction ");
		exit(1);
	}
	pause();

	pause();
	return 0;
}
