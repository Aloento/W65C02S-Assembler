#include <stdio.h>
#include "ast.h"
#include "pasm.tab.h"
#include <stdbool.h>

astroot_t astroot;


/* The first transformation finds the byte position
  for every instruction, and puts the labels
  with their bytepositions into the symbol table. */
bool transform1()
{
	printf("Error: transformation 1 is not yet implemented\n");
	return false;
}

/* The second transformation evaluates every definition
   and puts the defined variables
  with their values into the symbol table. */
bool transform2()
{
	printf("Error: transformation 2 is not yet implemented\n");
	return false;
}


int main(int argc, char** argv)
{
	int retval;
	astroot = NULL;
	retval = yyparse();
	printf("%d\n", retval);
	printast(astroot);
	if (transform1())
	{
		printf("Transformation 1 successful\n");
		printast(astroot);
		if (transform2())
		{
			printf("Transformation 2 successful\n");
			printast(astroot);
		}
	}
	return 0;
}
