#include "pig.h"

int main(void) 
{
	char str[MAX_LEN];

	while (strncmp(fgets(str, MAX_LEN, stdin), "\n", MAX_LEN)) {
		size_t len = strlen(str) - 1;
		if (str[len] != '\0') str[len] = '\0';
		pig(str);
	}
	return 0;
};