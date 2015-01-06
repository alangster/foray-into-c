#include "polish.h"


int main(void)
{
	char str[] = "13, 4, -, 2, 3, *, +";
	stack polish;

	printf("Polish Expression: %s\n", str);
	fill(&polish, str);
	print_stack(&polish);
	printf("Evaluated: %d\n", evaluate(&polish));
	return 0;
};