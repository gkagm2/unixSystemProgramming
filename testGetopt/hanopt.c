#include <stdio.h>
#define true 1
void Help();
int main(int argc, char *argv[]){ 
	extern char * optarg;
	extern int optind;
	extern int opterr;
	int opt_ok=0;
	int n;

	while((n = getopt(argc, argv, "au:h")) != -1){
		switch(n) {
			case 'a':
				printf("Welcome to Unix System Programming World!!!\n");
				opt_ok =1;
				break;
			case 'u':
					printf("Nice to meet you %s\n",optarg);
					opt_ok = 1;
				break;
			case 'h':
				opt_ok = 0;
				break;
		}
	}
	if(opt_ok != 1) {
		Help();
	}

	return 0;
}

void Help() {
	printf("you can use options '-a', '-u \"words\"', '-h' \n");
}
