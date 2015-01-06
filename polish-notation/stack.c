// #include "polish.h"

boolean empty(const stack *stk)
{
	return (stk -> count == EMPTY);
};

boolean full(const stack *stk)
{
	return (stk -> count == FULL);
};

void initialize(stack *stk)
{
	stk -> count = 0;
	stk -> top = NULL;
};

void push(stack *stk, data d)
{
	elem *e;

	if (!full(stk)){
		stk -> count++;
		e = malloc(sizeof(elem));
		e -> d = d;
		e -> next = stk -> top;
		stk -> top = e;
		// stk -> count++;
	}
};

data pop(stack *stk)
{
	elem *e;
	data d;

	if (!empty(stk)) {
		d = stk -> top -> d;
		e = stk -> top;
		stk -> top = stk -> top -> next;
		stk -> count--;
		free(e);
	}
	return d;
};

data top(stack *stk)
{
	return (stk -> top -> d);
};
