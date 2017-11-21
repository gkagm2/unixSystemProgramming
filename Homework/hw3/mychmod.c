#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	struct stat buf;
	int permissionNum;



	if(argc != 3) {
		printf("mychmod \"permission\" \"file name\"\n");
		exit(1);
	}

	stat(argv[2], &buf);

	printf("바뀌기 전 Mode = %o (16진수: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

	if((buf.st_mode & S_IREAD) != 0)
		printf("%s : user has a read permission\n",argv[2]);
	if((buf.st_mode & (S_IREAD >> 3)) != 0)
		printf("%s : group has a read permission\n",argv[2]);
	if((buf.st_mode & S_IROTH) != 0)
		printf("%s : other have a read permission\n",argv[2]);

	
	permissionNum = atoi(argv[1]) ;
	printf("permissionNum : %d\n",permissionNum);
	buf.st_mode = permissionNum;
	printf("buf.st_mode : %d , %x, %o\n",(unsigned int)buf.st_mode,(unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	stat(argv[2], &buf);
	chmod(argv[2], permissionNum);

	printf("user id : %d , group id : %d \n",buf.st_uid, buf.st_gid);
	printf("바뀐 Mode = %o \n", (unsigned int)buf.st_mode);

	return 0;
}
