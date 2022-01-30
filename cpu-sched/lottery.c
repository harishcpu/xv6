#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// global ticket count
int gtickets = 0;

struct node_t {
	int tickets;
	struct node_t *next;
};

struct node_t *head = NULL;

void insert(int tickets) {
	struct node_t *temp = malloc(sizeof(struct node_t));
	assert(temp != NULL);

	temp->tickets = tickets;
	temp->next = head;
	head = temp;
	gtickets += tickets;
}

void print_list(void) {
	struct node_t *current = head;
	printf("List: ");
	while(current) {
		printf("[%d]", current->tickets);
		current = current->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		fprintf(stderr, "usage: lottery <seed> <loops>\n");
		exit(1);
	}

	int seed = atoi(argv[1]);
	int loops = atoi(argv[2]);
	srandom(seed);
	
	insert(50);
	insert(100);
	insert(25);
	
	print_list();

	for(int i = 0; i < loops; i++) {
		int counter = 0;
		int winner = random() % gtickets;
		struct node_t *current = head;

		while(current) {
			counter = counter + current->tickets;
			if(counter > winner)	break;
			current = current->next;
		}
		// current winner: schedule it...
		print_list();
		printf("winner: %d %d\n\n", winner, current->tickets);
	}
	return 0;
}
