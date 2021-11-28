
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p1.c
 * Title      : Calling fork() and wait()
 * Description: This file contains the code to create a new process.
 *
 * License    : MIT License
 *
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("hello, world! (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {			// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child: new process
		printf("hello, I am the child (pid:%d)\n", (int) getpid());
	} else {				// parent goes down this path (main)
		int rc_wait = wait(NULL);
		printf("hello, I am the parent of %d (rc_wait:%d) (pid:%d)\n",
					   rc, rc_wait, getpid());
	}
	return 0;
}
