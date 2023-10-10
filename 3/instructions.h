#include <stdlib.h>

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
   OP_BCC
};

enum a_type_t
{
   AT_NUM,
   AT_REG,
   AT_PTR,
   AT_IDE
};

struct argument_t
{
   enum a_type_t a_type;
   int a_value;
   char *a_string;
};

// Functions declarations
int printinstruction1(enum opcode_t opc);
int printinstruction2(enum opcode_t opc, struct argument_t argval);
int printinstruction3(enum opcode_t opc, struct argument_t argval, struct argument_t);
