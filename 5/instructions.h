#include <stdlib.h>
#include "ast.h"

enum opcode_t
{
   OP_MOV,
   OP_JMP,
   OP_NOP,
   OP_ADDC,
   OP_SUBC,
   OP_AND,
   OP_OR,
   OP_XOR,
   OP_INC,
   OP_DEC,
   OP_CMP,
   OP_BZS,
   OP_BZC,
   OP_BCS,
   OP_BCC,
   OP_CALL,
   OP_RET,
   OP_RETI,
   OP_PUSH,
   OP_POP,
   OP_SEC,
   OP_CLC,
   OP_SEI,
   OP_CLI,
   OP_CLV,
   OP_ROTL,
   OP_ROTR,
};

enum a_type_t
{
	AT_NUM,
	AT_REG,
	AT_PTR,
	AT_ZP,
	AT_ZPY,
};

struct argument_t
{
   enum a_type_t a_type;
   int a_reg;
   expr_ast *a_expr;
};

struct numbers_t
{
   int n_value;
   struct numbers_t *n_next;
};

struct llist_t
{
   int value;
   struct llist_t *next;
};

struct llist_t *llist_new(int value);
struct llist_t *llist_add(struct llist_t *list, int value);

void printDB(struct llist_t *list);

// Functions declarations
int printinstruction1(enum opcode_t opc);
int printinstruction2(enum opcode_t opc, struct argument_t argval);
int printinstruction3(enum opcode_t opc, struct argument_t argval, struct argument_t);
