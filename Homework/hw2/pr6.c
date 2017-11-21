#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#define MAX 2
struct Student{
	int id;
	int unix_grade;
	int c_grade;
	int network_grade;
};

int main(int argc, char *argv[]){
	struct Student student[MAX];
	int rfd;
	int n;
	int buf_index = 0;
	int word_count = 0;
	int turn = 0;
	int st_i=0;
	int i;

	char ch;
	char buf[BUFSIZ];

	if(argc != 2){
		printf("write file name \n");
		exit(1);
	}
	rfd = open(argv[1], O_RDONLY);
	if(rfd == -1) {
		perror("Read");
		exit(1);
	}
	
	while(( n= read(rfd, &ch, 1)) > 0) {
		if (ch == ' ' || ch == '\n'){ 
			buf[buf_index] = '\0';

			switch(turn) {
				case 0:
					student[st_i].id = atoi(buf);
					break;
				case 1:
					student[st_i].unix_grade = atoi(buf);
					break;
				case 2: 
					student[st_i].c_grade = atoi(buf);
					break;
				case 3:
					student[st_i].network_grade = atoi(buf);
					break;
			}
			turn++;
			buf_index=0;
			if(turn == 4){
				turn =0;
				st_i++;
			}
				
		}
		else {
			buf[buf_index++] = ch;
		}
	}
	if( n == -1) {
		perror("Read");
		exit(1);
	}

	//Print
	printf("hakbun  average \n");
	for(i=0;i<sizeof(student) / sizeof(student[0]); i++){
		printf("%d %lf\n", student[i].id, (student[i].unix_grade + student[i].c_grade + student[i].network_grade) / (double)3);
	}
	close(rfd);
	return 0;
}
