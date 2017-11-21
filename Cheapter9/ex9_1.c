#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *fp;
	int a;

	fp = popen("wc -l", "w");//파이프를 생성합니다.
	if(fp == NULL){ //fp가 가리키고있는게 NULL이면 
		fprintf(stderr, "popen failed\n"); //에러 메시지 출력 후 
		exit(1);//종료
	}

	for( a=0 ;a<100 ; a++){ //0부터 100까지
		fprintf(fp, "test line\n");
	}

	pclose(fp);
	return 0;
}
