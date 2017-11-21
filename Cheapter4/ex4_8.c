#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
int main(void){
	struct passwd *pw;

	pw = getpwnam("jmaster");
	if(pw == NULL){
		perror("can't find user name");
		exit(1);
	}
	printf("UID : %d\n", (int)pw->pw_uid);
	printf("Home Directory : %s\n", pw->pw_dir);
	return 0;
}
