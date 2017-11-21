#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

	int fd;
	int n = 1;
	int i = 0; 
	int b = 0;
	char buf[256];
	int grade[4];
	char ch;

	fd = open("uiv", O_RDONLY);
	while (1) {
		n = read(fd, &ch, 1);
		if (n <= 0)
			break;
		if (ch == ' ' || ch == '\n') {
			buf[b] = '\0';
			grade[i++] = atoi(buf);
			b = 0;
			if (ch == '\n') {
				printf("%d %d %d %d %d\n", grade[0], grade[1], grade[2], grade[3], (grade[1] + grade[2] + grade[3]) / 3);
				i = 0;
			}
		}
		else
			buf[b++] = ch;
																				}
		return 0;

}



