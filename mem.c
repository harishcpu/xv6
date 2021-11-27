#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <assert.h>

void
Spin(int d)
{
	sleep(1);
}

int
main(int argc, char *argv[])
{
	int *p = malloc(sizeof(int));
	assert(p != NULL);
	printf("(%d) address pointed to by p: %p\n",
			getpid(), p);
	*p = 0;
	while(1) {
		Spin(1);
		*p = *p + 1;
		printf("(%d) p: %d\n", getpid(), *p);
	}
	return 0;
}
