%{

#include <stdio.h>
#include "ast.h"
#include "utils.h"

void yyerror (char const *s);
extern int yylex (void);

extern astroot_t astroot;

%}

%locations
%define parse.error verbose


%union{
  int numval;
  char * identval;
  lines_node_t *linesnode;
  line_node_t *linenode;
  opcode_t opcode_value;
  expr_node_t *expr_value;
  argument_node_t arg_value;
}


%token <numval> NUM
%token <identval> IDENT

%token REG_A REG_X REG_Y REG_P REG_S

%token LF
%token SECTION ORIGIN DB DW

/*opcode tokens*/
%token MOV JMP INC ADDC AND ASL BIT BR BRK CALL CLR CMP DEC OR PULL PUSH RET RETI ROL ROR SET TRB TSB XOR WAIT NOP

%type <linesnode> lines
%type <linenode> line
%type <opcode_value> opcode
%type <arg_value> argument
%type <expr_value> expr
%start asmfile

%%

asmfile : lines     { astroot = $1; printf("complete file found\n"); }

lines : lines line  { $$ = addline($1, $2); printf("lines found\n"); }
      | %empty      { $$ = newlines(); printf("found nothing\n"); }

line  : opcode argument ',' argument LF     { $$ = newline_instruction2($1,$2,$4,@$); printf("line with two arg opcode found\n"); }
      | opcode argument LF          { $$ = newline_instruction1($1,$2,@$); printf("line with one arg opcode found\n"); }
      | opcode LF             { $$ = newline_instruction0($1,@$); printf("line with zero arg opcode found\n"); }
      | IDENT ':' opcode argument ',' argument LF     { $$ = newline_label_instruction2($1,$3,$4,$6,@$); printf("line with label and two arg opcode found\n"); }
      | IDENT ':' opcode argument LF          { $$ = newline_label_instruction1($1,$3,$4,@$); printf("line with label and one arg opcode found\n"); }
      | IDENT ':' opcode LF             { $$ = newline_label_instruction0($1,$3,@$); printf("line with label and zero arg opcode found\n"); }
      | IDENT ':' LF    { $$ = newline_label($1,@$); printf("line with label found, value=%s\n", $1); }
      | LF              { $$ = NULL; printf("empty line found\n"); }
      | SECTION IDENT ORIGIN NUM  LF { $$ = NULL; printf("section found\n"); }

      | IDENT '=' expr LF { $$ = NULL; printf("definition found\n"); }

      | DB dbargs LF { $$ = NULL; printf("DB line found\n"); }
      | DW dbargs LF { $$ = NULL; printf("DW line found\n"); }
      | IDENT ':' DB dbargs LF { $$ = NULL; printf("DB with label line found\n"); }
      | IDENT ':' DW dbargs LF { $$ = NULL; printf("DW with label line found\n"); }

dbargs : expr  {}
       | dbargs ',' expr {}


opcode : MOV { $$ = OP_MOV;  printf("opcode MOV found\n"); }
       | JMP { $$ = OP_JMP; printf("opcode JMP found\n"); }
       | INC { $$ = OP_INC; printf("opcode INC found\n"); }
       | BRK { $$ = OP_BRK; }
       | CMP { $$ = OP_CMP; }
       | ADDC { $$ = OP_ADDC; }
       | ASL { $$ = OP_ASL; }
       | BR { $$ = OP_BR; }
       | CALL { $$ = OP_CALL; }
       | DEC { $$ = OP_DEC; }
       | OR { $$ = OP_OR; }
       | PULL { $$ = OP_PULL; }
       | PUSH { $$ = OP_PUSH; }
       | RET { $$ = OP_RET; }
       | RETI { $$ = OP_RETI; }
       | ROL { $$ = OP_ROL; }
       | ROR { $$ = OP_ROR; }
       | SET { $$ = OP_SET; }
       | TRB { $$ = OP_TRB; }
       | TSB { $$ = OP_TSB; }
       | XOR { $$ = OP_XOR; }
       | WAIT { $$ = OP_WAIT; }
       | NOP { $$ = OP_NOP; }


argument : expr            { $$.at_at = AT_IMMEDIATE; $$.at_expr = $1; printf("argument with immediate addressing found\n"); }
         | '['  expr  ']'  { $$.at_at = AT_ABSOLUTE; $$.at_expr = $2; printf("argument with absolute addressing found\n"); }
         | REG_A           { $$.at_at = AT_REG_A; $$.at_expr = NULL;  printf("argument REG_A found\n"); }
         | REG_X           { $$.at_at = AT_REG_X; $$.at_expr = NULL;  printf("argument REG_X found\n"); }
         | REG_Y           { $$.at_at = AT_REG_Y; $$.at_expr = NULL;  printf("argument REG_Y found\n"); }
         | REG_S           { $$.at_at = AT_REG_S; $$.at_expr = NULL;  printf("argument REG_S found\n"); }
         | REG_P           { $$.at_at = AT_REG_P; $$.at_expr = NULL;  printf("argument REG_P found\n"); }
         

expr : NUM         { $$ = newexpr_num($1,@$);  printf("expression with NUM found, value=%d\n", $1); }
     | IDENT       { $$ = newexpr_ident($1,@$);  printf("expression with IDENT found, value=%s\n", $1); }
     | expr '+' expr   { $$ = newexpr_binop(ET_PLUS,$1,$3,@$);;  printf("expression with PLUS found\n"); }
     | '(' expr ')'   { $$ = $2;  printf("expression in parenthesis found\n"); }
     | expr '-' expr   { $$ = newexpr_binop(ET_MINUS,$1,$3,@$);  printf("expression with SUBTRACTION found\n"); }
     | expr '*' expr   { $$ = newexpr_binop(ET_MULTIPLY,$1,$3,@$);  printf("expression with MULTIPLICATION found\n"); }
     | expr '/' expr   { $$ = newexpr_binop(ET_DIVIDE,$1,$3,@$);  printf("expression with DIVISION found\n"); }
     

%%

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "location: %d.%d-%d.%d\n",
        yylloc.first_line, yylloc.first_column,
        yylloc.last_line, yylloc.last_column);
}
