#include <stdio.h>
#include <signal.h>


int main(void){
	sigset_t st;

	sigemptyset(&st); //�ñ׳� ���� ����
	
	//�ñ׳� ���տ� �ñ׳� �߰�
	sigaddset(&st, SIGINT); //ctrl + c ���� ��
	sigaddset(&st, SIGQUIT); // �����ȣ�� ctrl + \ ���� 
	
	//�ñ׳� ���տ� ������ �ñ׳� Ȯ��
	if(sigismember(&st, SIGINT)) {
		printf("SIGINT is setting \n");
	}

	//sigbit�� �����ΰ�. 
	printf("** Bit pattern : %x\n", st._sigbits[0]);
	return 0;
}
