
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p3.c
 * Title      : fork()
 * Description: Make parent wait for child to complete execution without using wait() system call. 
 *
 * License    : MIT License
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello\n");
	} else {
		sleep(1);
		printf("goodbye\n");	
	}
}
