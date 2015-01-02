/* 
	Write a program that simulates a conversation with a deaf grandma.
	Grandma can only 'hear' if you use all caps--otherwise she will respond with 'speak up'
	The only way to exit is by shouting 'BYE!'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_caps(char const *s);

int main(void)
{
	char greet, response[] = "NO! NOT SINCE 1925!", bye[] = "BYE!", speak_up[] = "SPEAK UP, SONNY!";

	while (scanf("%s/n", &greet)) {
		if (!all_caps(&greet))
			printf("%s\n", speak_up);
		else
			if (*greet == bye) {
				printf("LATER!\n");
				exit(1);
			} else
				printf("%s\n", response);
	}
	return 0;
};

int all_caps(char const *s)
{
	int n, i;
	char str[strlen(s)];

	n = strlen(s);
	for (i = 0; i < n - 1; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z')
			return 0;
	}
	if (s[i] != '!')
		return 0;
	return 1;
}