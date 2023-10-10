#include <stdio.h>
#include <stdlib.h>
#include "symboltable.h"
#include "ast.h"

/*Evaluates an AST for an expression. Returns 0 if there is no error.*/
int evalexpr(expr_ast inast, int *result)
{
  symrec * symval;
  int leftval, rightval;
  switch(inast.exp_type)
  {
    case ET_NUM:
      *result = inast.numval;
      return 0;
    case ET_IDENT:
      symval = getsym(inast.identval);
      if (symval == 0)
      {
        printf("ERROR: unknown label\n");
        return 1;
      }
      *result = symval->sval;
      return 0;
    case ET_DIV:
      if( evalexpr(*(inast.leftchild), &leftval) ||
          evalexpr(*(inast.rightchild), &rightval) )
      { return 1; }
      *result = leftval / rightval;
      return 0;
    case ET_REM:
      if( evalexpr(*(inast.leftchild), &leftval) ||
          evalexpr(*(inast.rightchild), &rightval) )
      { return 1; }
      *result = leftval % rightval;
      return 0;
  }
}

int evallines(file_ast inast)
{
  int exprval;
  switch(inast.it)
  {
    case IT_DUMMY:
      break;
    case IT_ONEBYTE:
      printf("%02x\n", inast.opcode);
      break;
    case IT_TWOBYTE:
      if (evalexpr(*(inast.expr), &exprval)) { return 1; }
      printf("%02x %02x\n", inast.opcode, exprval);
      break;
    case IT_THREEBYTE:
      if( evalexpr(*(inast.expr), &exprval)) { return 1; }
      printf("%02x %02x %02x\n", inast.opcode,
           exprval%256, exprval/256);
      break;
    case IT_BRANCH:
      /* Computing the byte offset of a conditional jump
         one must compute the difference between the current position
         and the position of the label. The difference must be converted
         to two's complement reprezentation. It is an error if the result
         does not fit into a singel byte.
         More precisely, the jump is relative from the next instruction.
         So
           bzs  0
         is a nop, because it jumps to the next instruction anyway
           bzs 0xfe
         is an infinite loop if the zero flag is set, because
         fe = -2 in two's complement, and bzs is a two byte long instruction.

           call somefunction
           bzs 0xfb
         will call somefunction again and again if the zero flag is set.
         (the flag can be changed inside the function) because 0xfb = -5

           bzs 1
           mov a,x
           addc a, 10

         In this code the mov a,x instruction is skipped if the z flag is set.
         But normally we want to use labels:

          bzs label1
          mov a,x
  label1: addc a, 10

 */
      break;
  }
  if (inast.nextline)
  {
    /*recursive call to the next line*/
    return evallines(*(inast.nextline));
  }
}
