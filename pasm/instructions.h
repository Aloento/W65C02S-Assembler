#include <stdlib.h>
enum opcode_t
{
   OP_MOV,
   OP_JMP,
   OP_NOP
} ;

enum a_type_t
{
   AT_NUM,
   AT_REG,
   AT_PTR,
   AT_IDE
};

struct aragument_t
{
  enum a_type_t a_type;
  int a_value;
  char * a_string;
};

