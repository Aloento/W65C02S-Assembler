enum expr_type
{
  ET_NUM,
  ET_IDENT,
  ET_DIV,
  ET_REM
};

/** Abstract syntax tree for expressions */
typedef struct expr_ast
{
  enum expr_type exp_type;
  int numval;
  char *identval;
  struct expr_ast *leftchild, *rightchild;
} expr_ast;

enum intruction_type
{
  IT_DUMMY,     /* for lines where ther is no instruction, just label, or
                   constant definition or comment */
  IT_ONEBYTE,   /* like nop; inc a */
  IT_TWOBYTE,   /* like mov a, 0x12 */
  IT_THREEBYTE, /* like jmp label; mov [04001], a*/
  IT_BRANCH     /* like bzs label; bzc label */
};

typedef struct file_ast
{
  enum intruction_type it;
  int opcode;
  int currentpos;
  expr_ast *expr;
  struct file_ast *nextline;
} file_ast;

void ast_append(file_ast *newast);

file_ast *ast_new(enum intruction_type it, int opcode, expr_ast *expr);

int evallines(file_ast* actLine);
