#ifndef AST_H
#define AST_H

#include "machinecodes.h"
#include <stddef.h>
#include <stdlib.h>

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;

struct YYLTYPE
{
	int first_line;
	int first_column;
	int last_line;
	int last_column;
};

#define YYLTYPE_IS_DECLARED 1
#define YYLTYPE_IS_TRIVIAL 1
#endif

typedef enum
{
	ET_NUM,
	ET_IDENT,
	ET_PLUS,
	ET_MINUS,
	ET_TIMES,
	ET_MODULO,
	ET_DIVISON,
	ET_EQUALS,
	ET_NOT_EQUAL,
	ET_AND,
	ET_OR
} expr_type_t;

typedef struct expr_node_t
{
	expr_type_t et;
	int num;
	char* ident;
	struct expr_node_t *left, *right; /*subexpressions*/
} expr_node_t;

typedef struct expr_list
{
	expr_node_t* expr;
	struct expr_list* next;
} expr_list;

typedef enum
{
	LT_LABEL,
	/* line with a label*/
	LT_INSTRUCTION,
	/* instruction */
	LT_DEFINITION,
	LT_SECTION,
	LT_DB,
	LT_DW,
	LT_LABEL_PLUS_INSTRUCTION,
	LT_LABEL_PLUS_DB,
	LT_LABEL_PLUS_DW
} line_type_t;

typedef struct line_node_t
{
	line_type_t lt;
	YYLTYPE location;
	int bytepos;

	char* ident; /*for labels and definitions*/
	opcode_t opcode; /*for instructions*/
	argument_type_t arg1, arg2;
	expr_node_t *expr1, *expr2; /*for definitions and instructions*/
	expr_list* elist; /*for db and dw*/
} line_node_t;

typedef struct argument_node_t
{
	argument_type_t at;
	expr_node_t* expr;
} argument_node_t;

typedef struct lines_node_t
{
	line_node_t* currentline;
	struct lines_node_t* nextlines;
	struct lines_node_t* lastlines;
} lines_node_t;

typedef lines_node_t* astroot_t;

lines_node_t* addline(lines_node_t* oldlines, line_node_t* newline);
lines_node_t* newlines();

line_node_t* newline_label(char* ident, YYLTYPE loc);
line_node_t* newline_instruction(opcode_t opcode, argument_type_t arg1, argument_type_t arg2, expr_node_t* expr1,
                                 expr_node_t* expr2, YYLTYPE loc);
line_node_t* newline_section(char* ident, int num, YYLTYPE loc);
line_node_t* newline_definition(char* ident, expr_node_t* expr, YYLTYPE loc);
line_node_t* newline_label_instruction(char* ident, opcode_t opcode, argument_type_t arg1, argument_type_t arg2,
                                       expr_node_t* expr1, expr_node_t* expr2, YYLTYPE loc);
line_node_t* newline_label_db(char* ident, expr_list* elist, YYLTYPE loc);
line_node_t* newline_label_dw(char* ident, expr_list* elist, YYLTYPE loc);
line_node_t* newline_db(expr_list* elist, YYLTYPE loc);
line_node_t* newline_dw(expr_list* elist, YYLTYPE loc);
expr_list* dbarg_append(expr_list* elist, expr_node_t* expr);
expr_list* new_dbarg(expr_node_t* expr);

void printast(astroot_t root);

#endif // AST_H
