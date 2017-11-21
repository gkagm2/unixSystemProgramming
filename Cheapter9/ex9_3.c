#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int fd[2];
	pid_t pid;
	char buf[257];
	int len, status;
	
	if(pipe(fd) == -1){ //pipe 함수를 사용해 파이프를 생성한다.
		perror("pipe");//pipe 함수의 인자로는 파일 기술자를 저장할 배열을 지정한다.
		exit(1);
	}
	
	switch(pid = fork()) {//fork함수를 사용해 자식 프로세스를 생성한다.
		case -1:
			perror("fork");
			exit(1);
		case 0: //child.  자식프로세스의 동작 부분이다.
			close(fd[1]); //fd[1]을 닫는다. 이는 자식 프로세스에서 파이프를 읽기용으로 사용하겠다는 의미이다. 
			write(1, "Child Process:", 15);
			len = read(fd[0], buf, 256);//파이프의 입력 부분인 fd[0]에서 문자열을 읽어들인다.
			write(1, buf, len);
			close(fd[0]);
		default: //parent. 부모프레스스의 동작부분이다.
			close(fd[0]);//fd[0]을 닫는다. 이는 파이프를 출력용으로 사용하겠다는 의미이다.
			buf[0] = '\0';
			write(fd[1], "Test Message\n", 14); //fd[1]로 문자열을 출력한다.
			close(fd[1]);
			waitpid(pid, &status, 0);
			break;
	}
	return 0;
}
