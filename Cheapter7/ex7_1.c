#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main(void) { 
	printf("Before SIGCONT Signal to parent.\n");

	kill(getppid(), SIGCONT);

	printf("Before SIGQUIT Signal to me \n");

	kill(getpid(), SIGQUIT);

	printf("After SIGQUIT Signal.\n");

	return 0;

}
