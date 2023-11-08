#include <stdio.h>
#include "ast.h"
#include "pasm.tab.h"


astroot_t astroot;


int main(int argc, char** argv)
{
	int retval;
	astroot = NULL;
	retval = yyparse();
	printf("%d\n", retval);
	printast(astroot);
	return 0;
}
