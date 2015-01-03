/* 
	Write a program that simulates a conversation with a deaf grandma.
	Grandma can only 'hear' if you use all caps--otherwise she will respond with 'speak up'
	The only way to exit is by shouting 'BYE!'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_caps(char s[]);
int is_bye(char s[]);
void format(char *s[]);

int main(void)
{
	char c, greet[100], response[] = "NO! NOT SINCE 1925!", speak_up[] = "SPEAK UP, SONNY!";
	int i;

	for (i = 0; ;) {
		scanf("%99s", greet);
		if (!all_caps(greet))
			printf("%s\n", speak_up);
		else
			if (is_bye(greet)) {
				printf("LATER!\n");
				exit(1);
			} else
				printf("%s\n", response);
	}

	return 0;
};

void format(char *s[]) 
{
	int n = sizeof(*s);

	for (; n >= 0; --n) {
		if (*s[n] == '\n')
			s[n] = '\0';
	}
};

int is_bye(char s[])
{
	char bye[100] = "BYE!";
	
	return (strcmp(s, bye) == 0 ? 1 : 0);
};

int all_caps(char s[])
{
	int i = 0;

	if (s[i] == '\n')
		return 0;
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] >= 'a' && s[i] <= 'z')
			return 0;
	}
	return 1;
}