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
%token SECTION ORIGIN DB DW ZP

/*opcode tokens*/
%token MOV JMP INC ADDC AND ASL BIT BR BRK CALL CLR CMP DEC OR PULL PUSH RET RETI ROL ROR SET TRB TSB XOR WAIT NOP
%token CFLAG DFLAG IFLAG NFLAG VFLAG ZFLAG

%type <linesnode> lines
%type <linenode> line
%type <opcode_value> opcode
%type <arg_value> argument
%type <expr_value> expr
%start asmfile

%%

asmfile : lines     { astroot = $1; printf("complete file found\n"); fflush(stdout); }

lines : lines line  { $$ = addline($1, $2); printf("lines found\n"); fflush(stdout); }
      | %empty      { $$ = newlines(); printf("found nothing\n"); fflush(stdout); }

line  : opcode argument ',' argument LF     { $$ = newline_instruction2($1,$2,$4,@$); printf("line with two arg opcode found\n"); fflush(stdout); }
      | opcode argument LF          { $$ = newline_instruction1($1,$2,@$); printf("line with one arg opcode found\n"); fflush(stdout); }
      | opcode LF             { $$ = newline_instruction0($1,@$); printf("line with zero arg opcode found\n"); fflush(stdout); }
      | IDENT ':' opcode argument ',' argument LF     { $$ = newline_label_instruction2($1,$3,$4,$6,@$); printf("line with label and two arg opcode found\n"); fflush(stdout); }
      | IDENT ':' opcode argument LF          { $$ = newline_label_instruction1($1,$3,$4,@$); printf("line with label and one arg opcode found\n"); fflush(stdout); }
      | IDENT ':' opcode LF             { $$ = newline_label_instruction0($1,$3,@$); printf("line with label and zero arg opcode found\n"); fflush(stdout); }
      | IDENT ':' LF    { $$ = newline_label($1,@$); printf("line with label found, value=%s\n", $1); fflush(stdout); }
      | LF              { $$ = NULL; printf("empty line found\n"); fflush(stdout); }
      | SECTION IDENT ORIGIN NUM  LF { $$ = newline_section($2,$4,@$); printf("section found\n"); fflush(stdout); }

      | IDENT '=' expr LF { $$ = newline_definition($1,$3,@$); printf("definition found\n"); fflush(stdout); }

      | DB dbargs LF { $$ = NULL; printf("DB line found\n"); fflush(stdout); }
      | DW dbargs LF { $$ = NULL; printf("DW line found\n"); fflush(stdout); }
      | IDENT ':' DB dbargs LF { $$ = NULL; printf("DB with label line found\n"); fflush(stdout); }
      | IDENT ':' DW dbargs LF { $$ = NULL; printf("DW with label line found\n"); fflush(stdout); }

dbargs : expr  {}
       | dbargs ',' expr {}


opcode : MOV { $$ = OP_MOV;  printf("opcode MOV found\n"); fflush(stdout); }
       | JMP { $$ = OP_JMP; printf("opcode JMP found\n"); fflush(stdout); }
       | INC { $$ = OP_INC; printf("opcode INC found\n"); fflush(stdout); }
       | BRK { $$ = OP_BRK; fflush(stdout); }
       | CMP { $$ = OP_CMP;fflush(stdout); }
       | ADDC { $$ = OP_ADDC; fflush(stdout); }
       | ASL { $$ = OP_ASL; fflush(stdout); }
       | BR { $$ = OP_BR; fflush(stdout); }
       | CALL { $$ = OP_CALL; fflush(stdout); }
       | DEC { $$ = OP_DEC; fflush(stdout); }
       | OR { $$ = OP_OR; fflush(stdout); }
       | PULL { $$ = OP_PULL; fflush(stdout); }
       | PUSH { $$ = OP_PUSH; fflush(stdout); }
       | RET { $$ = OP_RET; fflush(stdout); }
       | RETI { $$ = OP_RETI; fflush(stdout); }
       | ROL { $$ = OP_ROL; fflush(stdout); }
       | ROR { $$ = OP_ROR; fflush(stdout); }
       | SET { $$ = OP_SET; fflush(stdout); }
       | TRB { $$ = OP_TRB; fflush(stdout); }
       | TSB { $$ = OP_TSB; fflush(stdout); }
       | XOR { $$ = OP_XOR; fflush(stdout); }
       | WAIT { $$ = OP_WAIT; fflush(stdout); }
       | NOP { $$ = OP_NOP; fflush(stdout); }
       | CLR { $$ = OP_CLR; fflush(stdout); }


argument : expr            { $$.at_at = AT_IMMEDIATE; $$.at_expr = $1; printf("argument with immediate addressing found\n"); fflush(stdout); }
         | '['  expr  ']'  { $$.at_at = AT_ABSOLUTE; $$.at_expr = $2; printf("argument with absolute addressing found\n"); fflush(stdout); }
         | '['  expr '+' REG_X ']'  { $$.at_at = AT_ABSOLUTE_X; $$.at_expr = $2; printf("argument with absolute_X addressing found\n"); fflush(stdout); }
         | '['  expr '+' REG_Y ']'  { $$.at_at = AT_ABSOLUTE_Y; $$.at_expr = $2; printf("argument with absolute_Y addressing found\n"); fflush(stdout); }
         | ZP '['  expr  ']'  { $$.at_at = AT_ZEROPAGE; $$.at_expr = $3; printf("argument with ZEROPAGE addressing found\n"); fflush(stdout); }
         | ZP '['  expr '+' REG_X ']'  { $$.at_at = AT_ZEROPAGE_X; $$.at_expr = $3; printf("argument with ZEROPAGE_X addressing found\n"); fflush(stdout); }
         | ZP '['  expr '+' REG_Y ']'  { $$.at_at = AT_ZEROPAGE_Y; $$.at_expr = $3; printf("argument with ZEROPAGE_Y addressing found\n"); fflush(stdout); } 
         | '[' ZP '[' expr ']' ']'  { $$.at_at = AT_INDIRECT_ZP; $$.at_expr = $4; printf("argument with INDIRECT_ZP addressing found\n"); fflush(stdout); }
         | '[' ZP '[' expr '+' REG_X ']' ']'  { $$.at_at = AT_INDIRECT_ZP_X; $$.at_expr = $4; printf("argument with INDIRECT_ZP_X addressing found\n"); fflush(stdout); }
         | '[' ZP '[' expr ']' '+' REG_Y  ']'  { $$.at_at = AT_INDIRECT_Y_ZP; $$.at_expr = $4; printf("argument with INDIRECT_Y_ZP addressing found\n"); fflush(stdout); }
         | REG_A           { $$.at_at = AT_REG_A; $$.at_expr = NULL;  printf("argument REG_A found\n"); fflush(stdout);}
         | REG_X           { $$.at_at = AT_REG_X; $$.at_expr = NULL;  printf("argument REG_X found\n"); fflush(stdout);}
         | REG_Y           { $$.at_at = AT_REG_Y; $$.at_expr = NULL;  printf("argument REG_Y found\n"); fflush(stdout);}
         | REG_S           { $$.at_at = AT_REG_S; $$.at_expr = NULL;  printf("argument REG_S found\n"); fflush(stdout);}
         | REG_P           { $$.at_at = AT_REG_P; $$.at_expr = NULL;  printf("argument REG_P found\n"); fflush(stdout);}
         | CFLAG           { $$.at_at = AT_CFLAG; $$.at_expr = NULL;  printf("argument AT_CFLAG found\n"); fflush(stdout);}
         | CFLAG  '=' NUM         { $$.at_at = AT_CFLAG; $$.at_expr = newexpr_num($3,@$);  printf("argument AT_CFLAG found\n"); fflush(stdout);}
         | DFLAG           { $$.at_at = AT_DFLAG; $$.at_expr = NULL;  printf("argument AT_DFLAG found\n"); fflush(stdout);}     
         | IFLAG           { $$.at_at = AT_IFLAG; $$.at_expr = NULL;  printf("argument AT_IFLAG found\n"); fflush(stdout);}
         | NFLAG           { $$.at_at = AT_NFLAG; $$.at_expr = NULL;  printf("argument AT_NFLAG found\n"); fflush(stdout);}
         | NFLAG  '=' NUM         { $$.at_at = AT_NFLAG; $$.at_expr = newexpr_num($3,@$);  printf("argument AT_NFLAG found\n"); fflush(stdout);}
         | VFLAG           { $$.at_at = AT_VFLAG; $$.at_expr = NULL;  printf("argument AT_VFLAG found\n"); fflush(stdout);}
         | VFLAG  '=' NUM         { $$.at_at = AT_VFLAG; $$.at_expr = newexpr_num($3,@$);  printf("argument AT_VFLAG found\n"); fflush(stdout);}
         | ZFLAG           { $$.at_at = AT_ZFLAG; $$.at_expr = NULL;  printf("argument AT_ZFLAG found\n"); fflush(stdout);}
         | ZFLAG  '=' NUM         { $$.at_at = AT_ZFLAG; $$.at_expr = newexpr_num($3,@$);  printf("argument AT_ZFLAG found\n"); fflush(stdout);}
         

expr : NUM         { $$ = newexpr_num($1,@$);  printf("expression with NUM found, value=%d\n", $1); fflush(stdout);}
     | IDENT       { $$ = newexpr_ident($1,@$);  printf("expression with IDENT found, value=%s\n", $1); fflush(stdout);}
     | expr '+' expr   { $$ = newexpr_binop(ET_PLUS,$1,$3,@$);;  printf("expression with PLUS found\n"); fflush(stdout);}
     | '(' expr ')'   { $$ = $2;  printf("expression in parenthesis found\n"); fflush(stdout);}
     | expr '-' expr   { $$ = newexpr_binop(ET_MINUS,$1,$3,@$);  printf("expression with SUBTRACTION found\n");fflush(stdout); }
     | expr '*' expr   { $$ = newexpr_binop(ET_MULTIPLY,$1,$3,@$);  printf("expression with MULTIPLICATION found\n"); fflush(stdout);}
     | expr '/' expr   { $$ = newexpr_binop(ET_DIVIDE,$1,$3,@$);  printf("expression with DIVISION found\n"); fflush(stdout);}
     

%%

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "location: %d.%d-%d.%d\n",
        yylloc.first_line, yylloc.first_column,
        yylloc.last_line, yylloc.last_column);
        fflush(stderr);
}
