%{
#include <stdbool.h>
#include <stdio.h>
#include "instructions.h"
#include "symboltable.h"

void yyerror (char const *s);
extern int yylex (void);

int bytesSoFar;

%}

%union{
  int numval;
  struct argument_t argval;
  enum opcode_t opc;
  int regval;
  char * identval;
}

%token MOV
%token JMP
%token NOP
%token ADDC
%token SUBC
%token AND
%token OR
%token XOR
%token INC
%token DEC
%token CMP
%token BZS
%token BZC
%token BCS
%token BCC
%token ','
%token '['
%token ']'
%token <numval> NUM
/*new line, or line feed*/
%token LF
%token REG_A
%token REG_X
%token REG_Y
%token <identval> IDENT
%token ':'
%token ';'
%token OTHER

%type <opc> opcode
%type <argval> argument
%type <regval> register

%start asmfile

%%

asmfile : lines  { printf("asmfile (start symbol) finished\n");}
        | %empty

lines : line
      | lines line

line : LF
     | opcode LF
        {
          if(printinstruction1($1))
          {
            YYERROR;
          }
        }
     | opcode argument LF
     {
          if(printinstruction2($1, $2))
          {
            YYERROR;
          }
        }
     | opcode argument ',' argument LF
        {
          if(printinstruction3($1, $2, $4))
          {
            YYERROR;
          }
        }
     | label LF
     | label opcode LF
     | label opcode argument LF
     | label opcode argument ',' argument LF

label : IDENT ':' { putsym( $1, bytesSoFar);}

opcode : MOV  { $$ = OP_MOV; }
       | JMP  { $$ = OP_JMP; }
       | NOP  { $$ = OP_NOP; }
       | ADDC { $$ = OP_ADDC; }
       | SUBC { $$ = OP_SUBC; }
       | AND { $$ = OP_AND; }
       | OR { $$ = OP_OR; }
       | XOR { $$ = OP_XOR; }
       | INC { $$ = OP_INC; }
       | DEC { $$ = OP_DEC; }
       | CMP { $$ = OP_CMP; }
       | BZS { $$ = OP_BZS; }
       | BZC { $$ = OP_BZC;}
       | BCS { $$ = OP_BCS;}
       | BCC { $$ = OP_BCC; }

argument : NUM { $$.a_type = AT_NUM; $$.a_value = $1; }
         | register { $$.a_type = AT_REG; $$.a_value = $1; }
         | '[' NUM ']' { $$.a_type = AT_PTR; $$.a_value = $2; }
         | IDENT {$$.a_type = AT_IDE; $$.a_string = $1; }

register : REG_A { $$ = 0; }
          | REG_X { $$ = 1; }
          | REG_Y { $$ = 2; }

%%

int main()
{
    bytesSoFar = 0x8055;
    yyparse();
    return 0;
}

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}
