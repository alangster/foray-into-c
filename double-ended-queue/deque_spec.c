#include <stdio.h>
#include "deque.h"

void info(deque *);

int main(void)
{
	deque dq1;

	printf("Initializing deque\n");
	reset(&dq1);
	info(&dq1);
	
	printf("Adding 'a' to front\n");
	add_to_front(&dq1, 'a');
	info(&dq1);

	printf("Adding 'z' to rear\n");
	add_to_rear(&dq1, 'z');
	info(&dq1);

	printf("Adding 'y' to rear\n");
	add_to_rear(&dq1, 'y');
	info(&dq1);	

	printf("Adding 'b' to front\n");
	add_to_front(&dq1, 'b');
	info(&dq1);

	printf("Adding 'c' to front\n");
	add_to_front(&dq1, 'c');
	info(&dq1);

	printf("Adding 'x' to rear\n");
	add_to_rear(&dq1, 'x');
	info(&dq1);		

	printf("Adding 'd' to front\n");
	add_to_front(&dq1, 'd');
	info(&dq1);	

	printf("Adding 'e' to front\n");
	add_to_front(&dq1, 'e');
	info(&dq1);

	printf("Adding 'w' to rear\n");
	add_to_rear(&dq1, 'w');
	info(&dq1);	

	printf("Attempting to add 'v' to rear\n");
	add_to_rear(&dq1, 'v');
	info(&dq1);

	return 0;
};

void info(deque *q)
{
	printf("%s%d, %s%d\n", "FRONT: ", q -> front, "REAR: ", q -> rear);
	printf("%s%c, %s%c\n", "FVAL: ", q -> s[q -> front], "RVAL: ", q -> s[q -> rear]);

	printf("%s%d\n", "Full? ", full(q));
	printf("%s%d\n", "Empty? ", empty(q));
};