#include <stdio.h>
typedef struct Year{
	int month[12];
	int totalDay;
}Year;
void InitYear(Year *year){
	int i;
	year->month[0] = 31;
	year->month[1] = 28;
	year->month[2] = 31;
	year->month[3] = 30;
	year->month[4] = 31;
	year->month[5] = 30;
	year->month[6] = 31;
	year->month[7] = 31;
	year->month[8] = 30;
	year->month[9] = 31;
	year->month[10] = 30;
	year->month[11] = 31;
	
	for(i=0;i< 12; i++) {
		year->totalDay += year->month[i];
	}

}
int main(void){

	int endOfAge;
	int age;
	int year = 365;
	int currentAge;
	double countWeek;
	int countDay;
	int i;
	printf("현재 나이를 입력하세요 : ");
	scanf("%d",&age);

	printf("삶의 끝의 나이를 입력하세요 : ");
	scanf("%d",&endOfAge);


	currentAge = endOfAge - age;
	
	countDay = currentAge * 365;
	countWeek = countDay / 7;
	
	printf("my day left less %d " , (int)countWeek);

	printf("\n");
	i=0;
	for(i=0;i<countWeek;i++){

		printf("O");
		if(i%30 == 0 ){
			printf("\n");
		}
	}

	return 0;
}
