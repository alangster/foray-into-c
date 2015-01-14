// #include "polish.h"

void print_data(data *d)
{
	switch (d -> type) {
		case operator:
			printf("%3c\n", d -> u.operator);
			break;
		case value:
			printf("%3d\n", d -> u.value);
			break;
	}
};

void print_stack(stack *stk)
{ 
	data d;

	printf("Count: %d  ", stk -> count);
	if (!empty(stk)) {
		d = pop(stk);
		print_data(&d);
		print_stack(stk);
		push(stk, d);
	}
};
