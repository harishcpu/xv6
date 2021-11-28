
/* Author     : Harish Kumar(harishec031@gmail.com)
 * Date       : Nov 28 2021
 * File       : p1.c
 * Title      : fork()
 * Description: Almost(not entirely) exact copy of static data, code, etc will be made for 
 * the child process and hence the variable x in child is diff from x in parent.
 *
 * License    : MIT License
 * Copyright (c) 2021 Harish Kumar
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int x = 100;
	int rc = fork();
	if (rc < 0) {
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("The value of variable in child process: (x:%d)\n", x);
		for (int i = 0; i < 3; ++i) {
			x = x+1;
			printf("hello, I am the child. (x:%d)\n", x);
		}
	} else {
		printf("The value of variable in parent process: (x:%d)\n", x);
		for (int i = 0; i < 3; ++i) {
			x = x+2;
			printf("hello, I am the parent. (x:%d)\n", x);
		}
	}
}
