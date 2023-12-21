%{
#include <stdio.h>
#include "ast.h"
#include "pasm.tab.h"

YYLTYPE yylloc;
int yyerrstatus = 0;

void yyerror (char const *s);
extern int yylex (void);
extern astroot_t astroot;

expr_node_t* num_expression(int num);
expr_node_t* ident_expression(char* ident);
expr_node_t* binary_expression(expr_type_t et, expr_node_t* left, expr_node_t* right);

argument_node_t* immediate_argument(expr_node_t* expr);
argument_node_t* absolute_argument(expr_node_t* expr);
argument_node_t* register_argument(argument_type_t at);
%}

%locations
%define parse.error detailed

%union {
  int numval;
  char *identval;
  lines_node_t *linesnode;
  line_node_t *linenode;
  opcode_t opcode_value;
  expr_node_t *expr_value;
  argument_node_t *argument_value;
  expr_list *elist;
}

%left '*' '/'  '%'  '|' '&' '(' ')'
%left '+' '-'  
%token <numval> NUM
%token <identval> IDENT
%token REG_Y
%token REG_S
%token REG_X
%token REG_P
%token REG_A
%token LF
%token CFLAG DFLAG IFLAG NFLAG VFLAG ZFLAG ZP

%token OTHER

/* Define all opcodes */
%token MOV JMP NOP BRK ADDC ADD ASL BR CALL DEC INC OR PULL PUSH RET RETI ROL ROR SET STOP CLR SUBC TRB TSB XOR WAIT DB DW SECTION ORIGIN AND BIT LSR CMP

%type <linesnode> lines
%type <linenode> line
%type <opcode_value> opcode
%type <expr_value> expr
%type <argument_value> argument
%type <elist> dbargs

%start asmfile

%%

asmfile : lines { astroot = $1; printf("complete file found\n"); }

lines: lines line { $$ = addline($1, $2); printf("Lines found\n"); }
    | %empty { $$ = newlines(); printf("Found nothing\n"); }

line: opcode argument LF { $$ = newline_instruction($1, $2->at, AT_NONE, $2->expr, NULL, @$); }
    | opcode argument ',' argument LF { $$ = newline_instruction($1, $2->at, $4->at, $2->expr, $4->expr,@$); printf("Line with instruction found\n"); }
    | opcode LF { $$ = newline_instruction($1, AT_NONE, AT_NONE, NULL, NULL, @$); printf("Line with instruction found\n"); }
    | IDENT ':' LF { $$ = newline_label($1, @$); printf("Line with label found, value = %s\n",$1); }
    | LF { $$ = NULL; printf("Empty line found\n"); }
    | SECTION IDENT ORIGIN NUM LF { $$ = newline_section($2,$4, @$); printf("section found\n"); }
    | DB dbargs LF { $$ = newline_db ($2,@$); printf("DB line found\n"); }
    | IDENT '=' expr LF { $$ = newline_definition($1,$3, @$); printf("Definition found\n"); }
    | IDENT ':' opcode argument LF { $$ = newline_label_instruction($1,$3, $4->at, AT_NONE, $4->expr,NULL, @$); printf("Line with label and instruction with one arg found\n"); }
    | IDENT ':' opcode argument ',' argument LF { $$ = newline_label_instruction($1,$3, $4->at,$6->at, $4->expr,$6->expr, @$); printf("Line with label and instruction with 2 arg found\n"); }
    | IDENT ':' opcode LF { $$ = newline_label_instruction($1,$3, AT_NONE, AT_NONE, NULL,NULL, @$); printf("Line with label and instruction with 0 arg found\n"); }
    | IDENT ':' DB dbargs LF { $$ = newline_label_db($1,$4,@$); printf("DB line with label found\n"); }
    | DW dbargs LF { $$ = newline_dw ($2,@$); printf("DW line found\n"); }
    | IDENT ':' DW dbargs LF { $$ = newline_label_dw($1,$4,@$); printf("Dw line with label found\n"); }

dbargs : expr {$$ = new_dbarg ($1); printf("dbargs found\n"); }
       | dbargs ',' expr {$$ = dbarg_append ($1,$3); printf("dbargs 2 found\n"); }

opcode: MOV { $$ = OP_MOV; }
     | JMP { $$ = OP_JMP; }
     | NOP { $$ = OP_NOP; }
     | BRK { $$ = OP_BRK; }
     | ADDC { $$ = OP_ADDC; }
     | ASL { $$ = OP_ASL; }
     | BR { $$ = OP_BR; }
     | CALL { $$ = OP_CALL; }
     | DEC { $$ = OP_DEC; }
     | INC { $$ = OP_INC; }
     | OR { $$ = OP_OR; }
     | PULL { $$ = OP_PULL; }
     | PUSH { $$ = OP_PUSH; }
     | RET { $$ = OP_RET; }
     | RETI { $$ = OP_RETI; }
     | ROL { $$ = OP_ROL; }
     | ROR { $$ = OP_ROR; }
     | SET { $$ = OP_SET; }
     | STOP { $$ = OP_STOP; }
     | SUBC { $$ = OP_SUBC; }
     | TRB { $$ = OP_TRB; }
     | TSB { $$ = OP_TSB; }
     | XOR { $$ = OP_XOR; }
     | WAIT { $$ = OP_WAIT; }
     | CLR { $$ = OP_CLR; }
     | AND { $$ = OP_AND; }
     | BIT { $$ = OP_BIT; }
     | LSR { $$ = OP_LSR; }
     | CMP { $$ = OP_CMP; }

argument: expr {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_IMMEDIATE;
    $$->expr = $1;
    printf("Argument with immediate addressing found\n");
}

| '[' expr ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ABSOLUTE;
    $$->expr = $2;
    printf("Argument with absolute addressing found\n");
}
| '[' expr '+' REG_X ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ABSOLUTE_X;
    $$->expr = $2;
    printf("Argument with absolute x addressing found\n");
}
| '[' expr '+' REG_Y ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ABSOLUTE_Y;
    $$->expr = $2;
    printf("Argument with absolute y addressing found\n");
}

| ZP '[' expr ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ZEROPAGE;
    $$->expr = $3;
    printf("Argument with ZEROPAGE found\n");
}
| ZP '[' expr '+' REG_X ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ZEROPAGE_X;
    $$->expr = $3;
    printf("Argument with ZEROPAGE_X found\n");
}
| ZP '[' expr '+' REG_Y ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ZEROPAGE_Y;
    $$->expr = $3;
    printf("Argument with ZEROPAGE_Y found\n");
}
| '[' ZP '[' expr ']' ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_INDIRECT_ZP;
    $$->expr = $4;
    printf("Argument with INDIRECT_ZP found\n");
}
| '[' ZP '[' expr '+' REG_X ']' ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_INDIRECT_ZP_X;
    $$->expr = $4;
    printf("Argument with INDIRECT_ZP_X found\n");
}
| '[' ZP '[' expr ']' '+' REG_Y ']' {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_INDIRECT_Y_ZP;
    $$->expr = $4;
    printf("Argument with INDIRECT_Y_ZP found\n");
}

| REG_A {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_REG_A;
    $$->expr = NULL;
    printf("Argument REG_A found\n");
}
| REG_X {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_REG_X;
    $$->expr = NULL;
    printf("Argument REG_X found\n");
}
| REG_Y {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_REG_Y;
    $$->expr = NULL;
    printf("Argument REG_Y found\n");
}
| REG_S {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_REG_S;
    $$->expr = NULL;
    printf("Argument REG_S found\n");
}
| REG_P {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_REG_P;
    $$->expr = NULL;
    printf("Argument REG_P found\n");
}
| CFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_CFLAG;
    $$->expr = NULL;
    printf("Argument CFLAG found\n");
}
| DFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_DFLAG;
    $$->expr = NULL;
    printf("Argument DFLAG found\n");
}
| IFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_IFLAG;
    $$->expr = NULL;
    printf("Argument IFLAG found\n");
}
| NFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_NFLAG;
    $$->expr = NULL;
    printf("Argument NFLAG found\n");
}
| VFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_VFLAG;
    $$->expr = NULL;
    printf("Argument VFLAG found\n");
}
| ZFLAG {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ZFLAG;
    $$->expr = NULL;
    printf("Argument ZFLAG found\n");
}
| CFLAG '=' NUM {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_CFLAG;
    $$->expr = num_expression($3);
    printf("Argument CFLAG found\n");
}
| NFLAG '=' NUM {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_NFLAG;
    $$->expr = num_expression($3);
    printf("Argument NFLAG found\n");
}
| VFLAG '=' NUM {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_VFLAG;
    $$->expr = num_expression($3);
    printf("Argument VFLAG found\n");
}
| ZFLAG '=' NUM {
    $$ = (argument_node_t*)malloc(sizeof(argument_node_t));
    $$->at = AT_ZFLAG;
    $$->expr = num_expression($3);
    printf("Argument ZFLAG found\n");
}

expr: NUM {$$ = num_expression($1); }
    | IDENT {$$ = ident_expression($1); }
    | expr '+' expr {$$ = binary_expression(ET_PLUS, $1, $3); }
    | expr '-' expr {$$ = binary_expression(ET_MINUS, $1, $3); }
    | expr '/' expr {$$ = binary_expression(ET_DIVISON, $1, $3); }
    | expr '*' expr {$$ = binary_expression(ET_TIMES, $1, $3); }
    | expr '|' expr {$$ = binary_expression(ET_OR, $1, $3); }
    | expr '&' expr {$$ = binary_expression(ET_AND, $1, $3); }
    | expr '%' expr {$$ = binary_expression(ET_MODULO, $1, $3); }
    | '(' expr ')' {$$ = $2; }

%%

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "location: %d.%d-%d.%d\n",
        yylloc.first_line, yylloc.first_column,
        yylloc.last_line, yylloc.last_column);
}
