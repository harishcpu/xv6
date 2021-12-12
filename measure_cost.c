#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

double system_call_cost(int samples) {
		char buf[10];
		int fd;
		suseconds_t diff;
		unsigned long msec_total;
		struct timeval t0, t1;

		for(int i = 0; i < samples; i++) {
			fd = open("README.md", O_RDONLY);
			if(fd < 0) {
					perror("README.md");
					exit(1);
			}

			gettimeofday(&t0, NULL);

			read(fd, buf, 0);

			gettimeofday(&t1, NULL);

			if(close(fd) < 0) {
					perror("README.md");
					exit(1);
			}

			diff = t1.tv_usec - t0.tv_usec;
			msec_total += (int) diff;
		}
		return (double) msec_total / (double) samples;	
		
}

#if defined(__x86_64__)

static __inline__ unsigned long long rdtsc(void) {
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo) | ( ((unsigned long long)hi) << 32);
}

#endif

unsigned long long syscall_cost_rdtsc(int samples) {
		char buf[10];
		int fd;
		unsigned long long t0, t1, msec_total;

		for(int i = 0; i < samples; i++) {
			fd = open("README.md", O_RDONLY);
			if(fd < 0) {
					perror("README.md");
					exit(1);
			}

			t0 = rdtsc();
			
			read(fd, buf, 0);
			
			t1 = rdtsc() - t0;

			if(close(fd) < 0) {
					perror("README.md");
					exit(1);
			}

			msec_total += t1;
		}
		return (long double) msec_total / (long double) samples;
}

int main(int argc, char *argv[]) {
	int user_input;
	printf("Do you want to measure cost of a system call using \n"
					"\t1. gettimeofday\n"
					"\t2. rdtsc\n");
	scanf("%d", &user_input);
	switch(user_input) {
			case 1: printf("The average time taken for a system call (0 byte read) is %.3fms\n", 
									system_call_cost(10));
				break;
			case 2: printf("The average time taken for a system call (0 byte read) is %llu\n", 
									syscall_cost_rdtsc(10));
				break;
		default:
				printf("Invalid input. Please enter the correct value.\n");
	}
	return 0;
}
