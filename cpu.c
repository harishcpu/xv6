#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>

void Spin(int d) {
	sleep(1);
}

int 
main(int argc, char *argv[]) {
		if(argc != 2) {
			fprintf(stderr, "usage: cpu <string>\n");
			exit(1);
		}
		char *str = argv[1];
		while(1) {
			Spin(1);
			printf("%s\n", str);
		}
		return 0;
}
