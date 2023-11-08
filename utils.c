#include "utils.h"


/*strndup implementation from here:

  https://stackoverflow.com/questions/46013382/c-strndup-implicit-declaration

*/

char* mystrndup(const char* s, size_t n)
{
	char* p;
	size_t n1;

	for (n1 = 0; n1 < n && s[n1] != '\0'; n1++)
		continue;
	p = malloc(n1 + 1);
	if (p != NULL)
	{
		memcpy(p, s, n1);
		p[n1] = '\0';
	}
	return p;
}

char* mystrdup(const char* s)
{
	char* p;
	size_t n1;

	for (n1 = 0; s[n1] != '\0'; n1++)
		continue;
	p = malloc(n1 + 1);
	if (p != NULL)
	{
		memcpy(p, s, n1);
		p[n1] = '\0';
	}
	return p;
}
