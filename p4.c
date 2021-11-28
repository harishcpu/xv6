
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p4.c
 * Title      : Calling fork(), wait(), exec() with redirection
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
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0) {			// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {	// child: new process
		close(STDOUT_FILENO);
		open("p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

		char *myargs[3];
		myargs[0] = strdup("wc");	// program: "wc" (word count) 
		myargs[1] = strdup("p4.c"); // argument: file to count
		myargs[2] = NULL;			// marks end of array

		execvp(myargs[0], myargs);	// runs word count
		printf("this shouldn't print out");
	} else {				// parent goes down this path (main)
		int rc_wait = wait(NULL);
	}
	return 0;
}
