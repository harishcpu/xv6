
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p1.c
 * Title      : Calling fork
 * Description: This file contains the code to create a new process.
 *
 * License    : MIT License
 *
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("hello, world! (pid: %d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child: new process
		printf("hello, I am the child (pid: %d)\n", (int) getpid());
	} else {
		// parent goes down this path (main)
		printf("hello, I am the parent of %d (pid: %d)\n", rc, (int) getpid());
	}
	return 0;
}
