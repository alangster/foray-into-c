#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char pig(char s[])
{
	char res[MAX_LEN], word[MAX_LEN], end = "ay";
	char *ps = s, *pw = word;

	while (*ps != '\0') {

		scanf("%s", word);
		if (*pw == 'a' || *pw == 'e' || *pw == 'i' || *pw == 'o' || *pw == 'u' || *pw == 'y') {
			strcat(res, pw);
		} else {
			strcat(res, pw + 1);
			strcat(res, pw);
			strcat(res, &end);
		}
		strcat(	res, " ");
		do {
			*ps++;		
		} while (!isspace(*ps) || *ps == '\0');
		printf("%s\n", res);
	};
	return res;
};