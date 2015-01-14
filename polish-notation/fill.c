// #include "polish.h"

void fill(stack *stk, const char *str)
{
	const char *p = str;
	char       c1, c2;
	boolean    b1, b2;
	data       d;
	stack      tmp;  

	initialize(stk);    // set the stack to empty
	initialize(&tmp);    // use tmp to process the data from the string

	while (*p != '\0') { // until we reach the end of the string
		while (isspace(*p) || *p == ',')
			++p;
		b1 = (boolean) ((c1 = *p) == '+' || c1 == '-' || c1 == '*'); // b1 is true if the current character is an operator
		b2 = (boolean) ((c2 = *(p + 1)) == ',' || c2 == '\0');       // b2 is true if the next character is a , or the end of the string

		if (b1 && b2) {
			d.type = operator;
			d.u.operator = c1;
		} else {
			d.type = value;
			assert(sscanf(p, "%d", &d.u.value) == 1);   // assign the whole value (i.e., in case it is more than one character) and ensure it worked
		}
		if (!full(&tmp))
			push(&tmp, d);
		while (*p != ',' && *p != '\0')
			++p;                          // advance p until we are past the current element (i.e., a value greater than 1 digit)
	}

	// now, we can pop the values off of tmp and push them onto stk
	while (!empty(&tmp)) {
		d = pop(&tmp);
		if (!full(stk))
			push(stk, d);
	}
}
