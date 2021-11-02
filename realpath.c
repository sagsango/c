// Directories and Links page : 347
#include <sys/stat.h>
#include <limits.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
//#include "tlpi_hdr.h"
#define EXIT_SUCCESS 0
#define BUF_SIZE PATH_MAX /* For definition of PATH_MAX */

int
main(int argc, char *argv[])
{
	struct stat statbuf;
	char buf[BUF_SIZE];
	ssize_t numBytes;
	if (argc != 2 || strcmp(argv[1], "--help") == 0) 
		printf("%s pathname\n", argv[0]);
	//Directories and Links 369
	if (lstat(argv[1], &statbuf) == -1)
		exit(-1);
	printf("statbuf.stmode:[%d]\n",statbuf.st_mode);
	if (!S_ISLNK(statbuf.st_mode))
		printf("%s is not a symbolic link", argv[1]);
	numBytes = readlink(argv[1], buf, BUF_SIZE - 1); 
	if (numBytes == -1)
		exit(-1);
	buf[numBytes] = '\0'; /* Add terminating null byte */ printf("readlink: %s --> %s\n", argv[1], buf);
	if (realpath(argv[1], buf) == NULL)
		exit(-1);
	printf("realpath: %s --> %s\n", argv[1], buf);
	exit(EXIT_SUCCESS);
}
