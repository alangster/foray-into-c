#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#define EMPTY 0
#define FULL  100

struct data
{
	enum {operator, value} type;       // the data can be either a mathematical operator or a number
	union {
		char  operator;
		int   value;
	}                      u;          // use 'u' to reference the actual value associated with the data (i.e., the symbol or number)
};

typedef struct data  data;

struct elem
{
	data         d;
	struct elem  *next;                // using a linked-list to implement the stack
};

typedef struct elem  elem;

typedef enum {false, true}  boolean;

struct stack
{
	int   count;                       // stack keeps track of how many elements are on it
	elem  *top;                        // use 'top' as a pointer to the element on the top of the stack
};

typedef struct stack  stack;

boolean empty(const stack *);
boolean full(const stack *);
void initialize(stack *);
void push(stack *, data);
data pop(stack *);
data top(stack *);

void fill(stack *, const char *);
void print_data(data *);
void print_stack(stack *);
int evaluate(stack *);

#include "fill.c"
#include "eval.c"
#include "print.c"
#include "stack.c"
