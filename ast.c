#include "ast.h"
#include <stdio.h>

expr_node_t *newexpr_num(int num, YYLTYPE loc)
{
	expr_node_t *retval = malloc(sizeof(expr_node_t));
	retval->et = ET_NUM;
	retval->num = num;
	return retval;
}

expr_node_t *newexpr_ident(char *ident, YYLTYPE loc)
{
	expr_node_t *retval = malloc(sizeof(expr_node_t));
	retval->et = ET_IDENT;
	retval->ident = ident;
	return retval;
}

expr_node_t *newexpr_binop(expr_type_t etype, expr_node_t *left, expr_node_t *right, YYLTYPE loc)
{
	expr_node_t *retval = malloc(sizeof(expr_node_t));
	retval->et = etype;
	retval->left = left;
	retval->right = right;
	return retval;
}

lines_node_t *addline(lines_node_t *oldlines, line_node_t *newline)
{
	if (oldlines && newline)
	{
		if (oldlines->lastlines)
		{
			lines_node_t *newnode = newlines();
			newnode->currentline = newline;
			oldlines->lastlines->nextlines = newnode;
			oldlines->lastlines = newnode;
		}
		else
		{
			oldlines->currentline = newline;
			oldlines->lastlines = oldlines;
			oldlines->nextlines = NULL;
		}
	}
	return oldlines;
}

lines_node_t *newlines()
{
	lines_node_t *retval = malloc(sizeof(lines_node_t));
	retval->currentline = NULL;
	retval->nextlines = NULL;
	retval->lastlines = NULL;
	return retval;
}

line_node_t *newline_label(char *ident, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL;
	retval->location = loc;
	retval->ident = ident;
	return retval;
}

line_node_t *newline_instruction0(opcode_t opcode, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = retval->arg2 = AT_NONE;
	return retval;
}

line_node_t *newline_label_instruction0(char *ident, opcode_t opcode, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL_PLUS_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = retval->arg2 = AT_NONE;
	retval->ident = ident;
	return retval;
}

line_node_t *newline_instruction1(opcode_t opcode, argument_node_t argn1, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = argn1.at_at;
	retval->expr1 = argn1.at_expr;
	retval->arg2 = AT_NONE;
	return retval;
}

line_node_t *newline_label_instruction1(char *ident, opcode_t opcode, argument_node_t argn1, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL_PLUS_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = argn1.at_at;
	retval->expr1 = argn1.at_expr;
	retval->arg2 = AT_NONE;
	retval->ident = ident;
	return retval;
}

line_node_t *newline_instruction2(opcode_t opcode, argument_node_t argn1, argument_node_t argn2, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = argn1.at_at;
	retval->expr1 = argn1.at_expr;
	retval->arg2 = argn2.at_at;
	retval->expr2 = argn2.at_expr;
	return retval;
}

line_node_t *newline_label_instruction2(char *ident, opcode_t opcode, argument_node_t argn1, argument_node_t argn2, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL_PLUS_INSTRUCTION;
	retval->location = loc;
	retval->opcode = opcode;
	retval->arg1 = argn1.at_at;
	retval->expr1 = argn1.at_expr;
	retval->arg2 = argn2.at_at;
	retval->expr2 = argn2.at_expr;
	retval->ident = ident;
	return retval;
}

line_node_t *newline_section(char *section_name, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_SECTION; // Assuming LT_SECTION is a valid line type
	retval->location = loc;
	retval->ident = section_name;
	return retval;
}

line_node_t *newline_definition(char *def_name, expr_node_t *def_value, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_DEFINITION;
	retval->location = loc;
	retval->ident = def_name;
	retval->expr1 = def_value;
	return retval;
}

line_node_t *newline_label_db(char *ident, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL_DB;
	retval->location = loc;
	retval->ident = ident;
	return retval;
}

line_node_t *newline_label_dw(char *label_name, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_LABEL_DW;
	retval->location = loc;
	retval->ident = label_name;
	return retval;
}

line_node_t *newline_db(expr_node_t *data, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_DATA;
	retval->location = loc;
	retval->expr1 = data;
	return retval;
}

line_node_t *newline_dw(expr_node_t *data, YYLTYPE loc)
{
	line_node_t *retval = malloc(sizeof(line_node_t));
	retval->lt = LT_DW;
	retval->location = loc;
	retval->expr1 = data;
	return retval;
}

void printexprnode(expr_node_t *node)
{
	if (node)
	{
		switch (node->et)
		{
		case ET_NUM:
			printf("NUM expr value=%d\n", node->num);
			break;
		case ET_PLUS:
			printf("PLUS expr\n");
			printexprnode(node->left);
			printexprnode(node->right);
			break;
		case ET_MINUS:
			printf("MINUS expr\n");
			printexprnode(node->left);
			printexprnode(node->right);
			break;
		case ET_MULTIPLY:
			printf("MULTIPLY expr\n");
			printexprnode(node->left);
			printexprnode(node->right);
			break;
		case ET_DIVIDE:
			printf("DIVIDE expr\n");
			printexprnode(node->left);
			printexprnode(node->right);
			break;
		}
	}
	else
	{
		printf("EMPTY expr node\n");
	}
}

void printlinenode(line_node_t *node)
{
	if (node)
	{
		switch (node->lt)
		{
		case LT_LABEL:
			printf("LINE: label, bytepos=%d, ident=%s\n", node->bytepos, node->ident);
			break;
		case LT_INSTRUCTION:
			printf("LINE: instruction, bytepos=%d, opcode=%d, arg1=%d, arg2=%d\n", node->bytepos, node->opcode,
				   node->arg1, node->arg2);
			printexprnode(node->expr1);
			printexprnode(node->expr2);
			break;

		default:
			printf("Line type not yet implemented\n");
			break;
		}
	}
	else
	{
		printf("Empty LINE node\n");
	}
}

void printlinesnode(lines_node_t *node)
{
	lines_node_t *currnode = node;
	while (currnode)
	{
		printlinenode(currnode->currentline);
		currnode = currnode->nextlines;
	}
}

void printast(astroot_t root)
{
	printf("Abstract syntax tree\n");
	if (root)
	{
		printlinesnode(root);
	}
	else
	{
		printf("Empty AST\n");
	}
}
