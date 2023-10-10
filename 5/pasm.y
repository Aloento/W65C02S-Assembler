%{
#include <stdbool.h>
#include <stdio.h>
#include "instructions.h"
#include "symboltable.h"

void yyerror (char const *s);
extern int yylex (void);

int bytesSoFar;
file_ast *globalLines;

%}

%union{
  int numval;
  struct argument_t argval;
  enum opcode_t opc;
  int regval;
  char * identval;
  struct llist_t * numbersval;
  expr_ast * exprval;
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
%token CALL
%token RET
%token RETI
%token PUSH
%token POP
%token SEC
%token CLC
%token SEI
%token CLI
%token CLV
%token ROTL
%token ROTR
%token DB

%token ZPBRACKET
%token REG_A
%token REG_X
%token REG_Y
%token REG_P
%token REG_S
%token REG_ZP

%token <numval> NUM
%token <identval> IDENT

%token ','
%token '['
%token ']'
%token ':'
%token '+'

%token LF
%token OTHER

%type <opc> opcode
%type <argval> argument
%type <regval> register
%type <numbersval> numbers
%type <numbersval> db
%type <exprval> expr

%start asmfile

%%

asmfile : lines { evallines(globalLines); }
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
     | db LF {
          printDB($1);
        }
     | label LF
     | label db LF
     | label opcode LF
     | label opcode argument LF
     | label opcode argument ',' argument LF

label : IDENT ':' { putsym( $1, bytesSoFar); }

opcode : MOV { $$ = OP_MOV; }
       | JMP { $$ = OP_JMP; }
       | NOP { $$ = OP_NOP; }
       | ADDC { $$ = OP_ADDC; }
       | SUBC { $$ = OP_SUBC; }
       | AND { $$ = OP_AND; }
       | OR { $$ = OP_OR; }
       | XOR { $$ = OP_XOR; }
       | INC { $$ = OP_INC; }
       | DEC { $$ = OP_DEC; }
       | CMP { $$ = OP_CMP; }
       | BZS { $$ = OP_BZS; }
       | BZC { $$ = OP_BZC; }
       | BCS { $$ = OP_BCS; }
       | BCC { $$ = OP_BCC; }
       | CALL { $$ = OP_CALL; }
       | RET { $$ = OP_RET; }
       | RETI { $$ = OP_RETI; }
       | PUSH { $$ = OP_PUSH; }
       | POP { $$ = OP_POP; }
       | SEC { $$ = OP_SEC; }
       | CLC { $$ = OP_CLC; }
       | SEI { $$ = OP_SEI; }
       | CLI { $$ = OP_CLI; }
       | CLV { $$ = OP_CLV; }
       | ROTL { $$ = OP_ROTL; }
       | ROTR { $$ = OP_ROTR; }

argument : expr { $$.a_type = AT_NUM; $$.a_expr = $1; }
         | register { $$.a_type = AT_REG; $$.a_reg = $1; }
         | '[' expr ']' { $$.a_type = AT_PTR; $$.a_expr = $2; }
         | '[' ZPBRACKET expr ']' ']' { $$.a_type = AT_ZP; $$.a_expr = $3; }
         | '[' ZPBRACKET expr ']' '+' register ']' { $$.a_type = AT_ZPY; $$.a_expr = $3; }

expr :  NUM { $$ = (expr_ast*) malloc(sizeof(expr_ast));
              $$->exp_type = ET_NUM; $$->numval = $1; }
     |  IDENT  { $$ = (expr_ast*) malloc(sizeof(expr_ast));
                 $$->exp_type = ET_IDENT; $$->identval = strdup($1); }
     |  expr '/' expr { 
                $$ = (expr_ast*) malloc(sizeof(expr_ast));
                $$->exp_type = ET_DIV;
                $$->leftchild = $1;
                $$->rightchild = $3;
              }
     |  expr '%' expr { 
                $$ = (expr_ast*) malloc(sizeof(expr_ast));
                $$->exp_type = ET_REM;
                $$->leftchild = $1;
                $$->rightchild = $3;
              }
     |  '(' expr ')' { $$ = $2; }

register : REG_A { $$ = 0; }
         | REG_X { $$ = 1; }
         | REG_Y { $$ = 2; }
         | REG_P { $$ = 3; }
         | REG_S { $$ = 4; }

numbers: NUM { $$ = llist_new($1); }
       | numbers ',' NUM { $$ = llist_add($1, $3); }

db: DB numbers { $$ = $2; }

%%

int main()
{
    globalLines = ast_new(IT_DUMMY, 0, NULL);
    bytesSoFar = 0x8055;
    yyparse();
    return 0;
}

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}
