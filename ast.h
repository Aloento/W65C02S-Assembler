#include "machinecodes.h"
#include <stddef.h>
#include <stdlib.h>

/* Location type.  */
#if !defined YYLTYPE && !defined YYLTYPE_IS_DECLARED
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
	ET_MULTIPLY,
	ET_DIVIDE,
	ET_TIMES,
	ET_MODULO,
	ET_EQUAL,
	ET_NOT_EQUAL,
	ET_AND,
	ET_OR,
} expr_type_t;

typedef struct expr_node_t
{
	expr_type_t et;
	int num;
	char* ident;
	struct expr_node_t* left, * right; /*subexpressions*/
} expr_node_t;

typedef struct expr_linked_list
{
	expr_node_t* expr;
	struct expr_linked_list* next;
} expr_linked_list;

typedef enum
{
	LT_LABEL,
	LT_LABEL_DB,
	LT_LABEL_DW,
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

typedef struct
{
	argument_type_t at_at;
	expr_node_t* at_expr;
} argument_node_t;

typedef struct line_node_t
{
	line_type_t lt;
	YYLTYPE location;
	int bytepos;

	char* ident; /*for labels and definitions*/
	opcode_t opcode; /*for instructions*/
	argument_type_t arg1, arg2;
	expr_node_t* expr1, * expr2; /*for definitions and instructions*/
	/*for data, you need a linked list of expressions, write it yourself*/
	expr_linked_list* linked_list;
} line_node_t;

typedef struct lines_node_t
{
	line_node_t* currentline;
	struct lines_node_t* nextlines;
	struct lines_node_t* lastlines;
} lines_node_t;

typedef lines_node_t* astroot_t;

lines_node_t* addline(lines_node_t* oldlines, line_node_t* newline);
lines_node_t* newlines();
expr_node_t* newexpr_num(int num, YYLTYPE loc);
expr_node_t* newexpr_binop(expr_type_t etype, expr_node_t* left, expr_node_t* right, YYLTYPE loc);
line_node_t* newline_label(char* ident, YYLTYPE loc);
line_node_t* newline_instruction0(opcode_t opcode, YYLTYPE loc);
line_node_t* newline_label_instruction0(char* ident, opcode_t opcode, YYLTYPE loc);
line_node_t* newline_instruction1(opcode_t opcode, argument_node_t argn1, YYLTYPE loc);
line_node_t* newline_label_instruction1(char* ident, opcode_t opcode, argument_node_t argn1, YYLTYPE loc);
line_node_t* newline_instruction2(opcode_t opcode, argument_node_t argn1, argument_node_t argn2, YYLTYPE loc);
line_node_t* newline_label_instruction2(char* ident, opcode_t opcode, argument_node_t argn1, argument_node_t argn2,
	YYLTYPE loc);

void printast(astroot_t root);
