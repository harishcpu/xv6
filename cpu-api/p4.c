
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p4.c
 * Title      : fork() and wait()
 * Description: use wait() system call in child process and let parent complete its execution first. 
 *
 * License    : MIT License
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		wait(NULL);
		printf("Child Printing: hello\n");
	} else {
		printf("Parent printing: goodbye\n");	
	}
}
