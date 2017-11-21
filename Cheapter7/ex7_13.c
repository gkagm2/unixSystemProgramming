#include <unistd.h>
#include <signal.h>
#include <stdio.h>
//#include <siginfo.h>

void handler(int signo){
	psignal(signo, "Received Signal:");
}

int main(void){
	sigset_t set;
	q
	p
	p
	q
	
	sigset(SIGALRM, handler);

	sigfillset(&set);
	sigdelset(&set, SIGALRM);

	alarm(3);

	printf("Wait...\n");

	sigsuspend(&set);
	return 0;
}
