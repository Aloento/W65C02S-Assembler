#include "ast.h"
#include "pasm.tab.h"
#include <stdio.h>


astroot_t astroot;


int main1(int argc, char** argv)
{
	int retval;
	astroot = NULL;
	retval = yyparse();
	printf("%d\n", retval);
	printast(astroot);
	return 0;
}
