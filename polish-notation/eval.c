// #include "polish.h"

int evaluate(stack *stk)
{
	stack  tmp;
	data   d1, d2, d3;

	initialize(&tmp);
	while (!empty(stk)) {
		d1 = pop(stk);
		switch (d1.type) {
		case value:
			push(&tmp, d1);
			break;
		case operator:
			d2 = pop(&tmp);
			d3 = pop(&tmp);
			d1.type = value;
			switch (d1.u.operator) {
				case '+':
					d1.u.value = d3.u.value + d2.u.value;
					printf("%d = %d + %d\n", d1.u.value, d3.u.value, d2.u.value );
					break;
				case '-':
					d1.u.value = d3.u.value - d2.u.value;
					printf("%d = %d - %d\n", d1.u.value, d3.u.value, d2.u.value );
					break;
				case '*':
					d1.u.value = d3.u.value * d2.u.value;
					printf("%d = %d * %d\n", d1.u.value, d3.u.value, d2.u.value );
			}
		}
		push(&tmp, d1);
	}
	d1 = pop(&tmp);
	return d1.u.value;
};