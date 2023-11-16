#include "ast.h"
#include "pasm.tab.h"
#include "symboltable.h"
#include <stdbool.h>
#include <stdio.h>

astroot_t astroot;


/* The first transformation finds the byte position
  for every instruction, and puts the labels
  with their bytepositions into the symbol table. */
bool transform1()
{
	int currpos;
	int nbytes;
	unsigned char res[3];
	lines_node_t* currlines = astroot;
	while (currlines)
	{
		//zuo shen me
		line_node_t* cl = currlines->currentline;
		switch (cl->lt)
		{
		case LT_LABEL:
			if (checksym(cl->ident))
			{
				printf("Error: label already defined %s line=%d\n", cl->ident, cl->location.first_line);
				return false;
			}
			putsym(cl->ident, currpos);
			break;
		case LT_INSTRUCTION:
			nbytes = getmachinebytes(0, cl->opcode, cl->arg1, 0, cl->arg2, 0, res);
			if (nbytes < 1)
			{
				printf("Error: instruction error %d line=%d\n", nbytes, cl->location.first_line);
				return false;
			}
			cl->bytepos = currpos;
			currpos += nbytes;
			break;
		case LT_DEFINITION:
			break;
		case LT_SECTION:
			currpos = cl->bytepos;
			break;
		case LT_DATA:
			break;
		case LT_LABEL_PLUS_INSTRUCTION:
			break;
		case LT_LABEL_PLUS_DATA:
			break;
		}
		currlines->nextlines;
	}
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
		printsymboltable();
		if (transform2())
		{
			printf("Transformation 2 successful\n");
			printast(astroot);
		}
	}
	return 0;
}
