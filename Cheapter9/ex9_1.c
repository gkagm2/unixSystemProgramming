#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *fp;
	int a;

	fp = popen("wc -l", "w");//�������� �����մϴ�.
	if(fp == NULL){ //fp�� ����Ű���ִ°� NULL�̸� 
		fprintf(stderr, "popen failed\n"); //���� �޽��� ��� �� 
		exit(1);//����
	}

	for( a=0 ;a<100 ; a++){ //0���� 100����
		fprintf(fp, "test line\n");
	}

	pclose(fp);
	return 0;
}
