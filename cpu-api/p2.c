
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p2.c
 * Title      : fork()
 * Description: Example to demonstrate file descriptors are shared among parent and child processes created using fork() 
 *
 * License    : MIT License
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	char *buf = "hello, world!\n";
	int fd = open("p2.output", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
	if(fd == -1) {
		perror("p2.output");
		printf("errno: %d\n", errno);
		exit(1);
	}

	int rc = fork();
	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello, I am the child. (pid:%d)\n", (int) getpid());
		char *pstring = "Child: ";
		write(fd, (void *)pstring, strlen(pstring));
		write(fd, (void *)buf, strlen(buf));

	} else {
		printf("hello, I am the parent. (pid:%d)\n", (int) getpid());
		char *pstring = "Parent: ";
		write(fd, (void *)pstring, strlen(pstring));
		write(fd, (void *)buf, strlen(buf));
	}
}
