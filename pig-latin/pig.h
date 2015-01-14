#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void pig(char s[])
{
	const char end[] = "ay\0";
	size_t len = strlen(s);
	char res[MAX_LEN];
	char *p;

	p = s;
	
	if (p[0] == 'a' || p[0] == 'e' || p[0] == 'i' || p[0] == 'o' || p[0] == 'u') {
		printf("%s\n", s);
	} else {
	  strcpy(res, p + 1);
	  res[len - 2] = p[0];
	  strcat(res, end);
		printf("%s\n", res);
	}

};