#include "ast.h"
#include "pasm.tab.h"
#include "symboltable.h"
#include <stdbool.h>
#include <stdio.h>

astroot_t astroot;

bool label_handler(line_node_t* currentline, int current_bytepos)
{
	if (checksym(currentline->ident))
	{
		printf("Error: label is already defined.  %d line=%d'\n", currentline->location.first_line, current_bytepos);
		return true;
	}
	putsym(currentline->ident, current_bytepos);
	return false;
}

/* The first transformation finds the byte position
  for every instruction, and puts the labels
  with their bytepositions into the symbol table. */
bool transform1()
{
	int current_bytepos = 0;
	int instruction_len;
	unsigned char result[3];
	int numexprs;
	expr_list* curexpr;
	lines_node_t* currentlines = astroot;

	while (currentlines != NULL)
	{
		line_node_t* currentline = currentlines->currentline;
		switch (currentline->lt)
		{
		case LT_SECTION:
			current_bytepos = currentline->bytepos;
			break;
		case LT_LABEL:
			if (label_handler(currentline, current_bytepos))
			{
				return false;
			}
			break;
		case LT_LABEL_PLUS_INSTRUCTION:
			if (label_handler(currentline, current_bytepos))
			{
				return false;
			}
			result[3];

			instruction_len = getmachinebytes(0, currentline->opcode, currentline->arg1, 0, currentline->arg2, 0,
				result);
			if (instruction_len < 1)
			{
				printf("Error: invalid opcode.  %d line=%d'\n", currentline->location.first_line, current_bytepos);
				return false;
			}
			currentline->bytepos = current_bytepos;
			current_bytepos += instruction_len;
			break;
		case LT_INSTRUCTION:
			instruction_len = 0;
			result[3];

			instruction_len = getmachinebytes(0, currentline->opcode, currentline->arg1, 0, currentline->arg2, 0,
				result);
			if (instruction_len < 1)
			{
				printf("Error: invalid opcode.  %d line=%d'\n", currentline->location.first_line, current_bytepos);
				return false;
			}
			currentline->bytepos = current_bytepos;
			current_bytepos += instruction_len;
			break;
		case LT_LABEL_PLUS_DB:
			if (label_handler(currentline, current_bytepos))
			{
				return false;
			}
			numexprs = 0;
			curexpr = currentline->elist;
			while (curexpr != NULL)
			{
				numexprs++;
				curexpr = curexpr->next;
			}
			currentline->bytepos = current_bytepos;
			current_bytepos += numexprs;
			break;
		case LT_DB:
			numexprs = 0;
			curexpr = currentline->elist;
			while (curexpr != NULL)
			{
				numexprs++;
				curexpr = curexpr->next;
			}
			currentline->bytepos = current_bytepos;
			current_bytepos += numexprs;
			break;
		default:
			break;
		}
		currentlines = currentlines->nextlines;
	}

	return true;
}

/* This function evaluates an expression and puts the result into val.
   Return value: 0: success
				 1: nul pointer
				 2: unknown variable
				 3: division by zero
*/
int evaluate_expression(expr_node_t* expr, int* val)
{
	if (expr == NULL)
	{
		return 1;
	}
	switch (expr->et)
	{
	case ET_NUM:
		*val = expr->num;
		return 0;
	case ET_IDENT:
	{
		if (checksym(expr->ident))
		{
			*val = getsym(expr->ident);
			return 0;
		}
		return 2;
	}
	case ET_PLUS:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = val1 + val2;
		return 0;
	}
	case ET_MINUS:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = val1 - val2;
		return 0;
	}
	case ET_TIMES:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = val1 * val2;
		return 0;
	}
	case ET_MODULO:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		if (val2 == 0)
		{
			return 3;
		}
		*val = val1 % val2;
		return 0;
	}
	case ET_DIVISON:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		if (val2 == 0)
		{
			return 3;
		}
		*val = val1 / val2;
		return 0;
	}
	case ET_EQUALS:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = (val1 == val2);
		return 0;
	}
	case ET_NOT_EQUAL:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = (val1 != val2);
		return 0;
	}
	case ET_AND:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = (val1 && val2);
		return 0;
	}
	case ET_OR:
	{
		int val1, val2;
		int ret1 = evaluate_expression(expr->left, &val1);
		int ret2 = evaluate_expression(expr->right, &val2);
		if (ret1 || ret2)
		{
			return 1;
		}
		*val = (val1 || val2);
		return 0;
	}
	default:
		break;
	}

	return 4;
}

/* The second transformation evaluates every definition
   and puts the defined variables
  with their values into the symbol table. */

bool transform2()
{
	lines_node_t* currentlines = astroot;
	while (currentlines != NULL)
	{
		line_node_t* currentline = currentlines->currentline;
		switch (currentline->lt)
		{
		case LT_DEFINITION:
			if (checksym(currentline->ident))
			{
				printf("Error: variable is already defined.  %s line=%d'\n", currentline->ident,
					currentline->location.first_line);
				return false;
			}
			int val;
			int ret = evaluate_expression(currentline->expr1, &val);
			if (ret)
			{
				printf("Error: evaluating expression.  %d line=%d'\n", ret, currentline->location.first_line);
				return false;
			}
			putsym(currentline->ident, val);
			break;
		default:
			break;
		}
		currentlines = currentlines->nextlines;
	}

	return true;
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
			printsymboltable();
		}
	}
	return 0;
}
