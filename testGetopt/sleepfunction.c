#include <stdio.h>

int main(void){
	
	int i;

	for(i=0;i<100;i++){
		printf("%d\n",i);
		//usleep(1000000) 이랑 sleep(1)이 1초를 나타냄.
	//	usleep(1000000);
		sleep(1);
	}



	return 0;
}
