#include <stdio.h>
extern int addnum(int a, int b);
extern int prodnum(int a, int b);
int main(void) {
	int sum;
	int mul;

	sum = addnum(1,5);
	printf("Sum 1~5 = %d\n", sum);

	mul = prodnum(1,5);
	printf("prodnum 1~5 = %d\n", mul);
	return 0;
}
