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
  struct aragument_t argval;
  enum opcode_t opc;
  int regval;
  char * identval;
  expr_ast * exprval;
}

%token MOV
%token JMP
%token NOP
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

%token OTHER

%type <opc> opcode
%type <argval> argument
%type <regval> regiszter
%type <exprval> expr

%start asmfile

%%

asmfile : lines  { printf("asmfile (start symbol) finished\n");}
        | %empty

lines : line
      | lines line

line : LF
     | opcode LF
        {  if($1 == OP_NOP)
           {
             printf( "ea\n" );
             bytesSoFar = bytesSoFar + 1;
           } else {
              printf("ERROR: wrong number of arguments\n");
              YYERROR;
           }
        }
     | opcode argument LF
        {  printf("I am here! 2\n");
           if($1 == OP_JMP && $2.a_type == AT_NUM)
           {
             printf( "4c %02x %02x\n", $2.a_value % 256,  $2.a_value / 256 );
             bytesSoFar = bytesSoFar + 3;
           } else {
           if($1 == OP_JMP && $2.a_type == AT_IDE)
           {
             printf("I am here!\n");
             symrec * val = getsym($2.a_string);
             if (val == 0)
             {
                printf("ERROR: unknown label\n");
                YYERROR;
             }
             printf( "4c %02x %02x\n", val->sval % 256,  val->sval / 256 );
             bytesSoFar = bytesSoFar + 3;
           } else {
              printf("ERROR: wrong number or type of arguments\n");
              YYERROR;
           }
          }
        }
     | opcode argument ',' argument LF
        {  if($1 == OP_MOV)
           {
             bool OK = false;
             if($2.a_type == AT_REG && $2.a_value == 0) //want to load to A
             {
               if($4.a_type == AT_NUM) //immedite load to A
               {
                 printf( "A9 %02x\n", $4.a_value );
                 bytesSoFar = bytesSoFar + 2;
                 OK = true;
               }
               if($4.a_type == AT_PTR) //absolute load to A
               {
                 printf( "AD %02x %02x\n", $4.a_value % 256,  $4.a_value / 256 );
                 bytesSoFar = bytesSoFar + 3;
                 OK = true;
               }

             }
             if (!OK)
             {
             printf("ERROR: some error message\n");
              YYERROR;
             }
           } else {
              printf("ERROR: wrong number or type of arguments\n");
              YYERROR;
           }
        }

     | label LF
     | label opcode LF
     | label opcode argument LF
     | label opcode argument ',' argument LF


label : IDENT ':' { putsym( $1, bytesSoFar);}
opcode : MOV  { $$ = OP_MOV; printf("MOV \n");}
       | JMP  { $$ = OP_JMP; }
       | NOP  { $$ = OP_NOP;}

argument : expr { $$.a_type = AT_NUM; $$.a_value = $1; printf("NUM, it's value is:%d\n", $1 );}
         | regiszter { $$.a_type = AT_REG; $$.a_value = $1; }
         | '[' expr ']' { $$.a_type = AT_PTR; $$.a_value = $2; }
         | IDENT { $$.a_type = AT_IDE; $$.a_string = $1; }

expr :  NUM { $$ = (expr_ast*) malloc(sizeof(expr_ast));
              $$->exp_type = ET_NUM; $$->numval = $1; }
     |  IDENT  { $$ = (expr_ast*) malloc(sizeof(expr_ast));
                 $$->exp_type = ET_IDENT; $$->identval = $1; }
     |  expr '/' expr  { $$ = (expr_ast*) malloc(sizeof(expr_ast));
                 $$->exp_type = ET_DIV;
                  $$->leftchild = $1;
                  $$->rightchild = $3;}
     |  expr '%' expr
     |  '(' expr ')' {  $$ = $2;}

regiszter : REG_A { $$ = 0; }
          | REG_X { $$ = 1; }
          | REG_Y { $$ = 2; }

%%



int main()
{
  bytesSoFar = 0x8055;
  yyparse();
  return 0;
}



void
yyerror (char const *s)
{
fprintf (stderr, "%s\n", s);
}




