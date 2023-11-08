
%{

#include "ast.h"
#include "utils.h"
#include "pasm.tab.h"
#include <stdlib.h>

static int linepos=1, columnpos=1;

#define SETLOCATION {yylloc.first_line = linepos; yylloc.first_column=columnpos; yylloc.last_line=linepos; columnpos += yyleng; yylloc.last_column=columnpos;}
%}

%option noyywrap
%%

a|A {  SETLOCATION; return REG_A; }
x|X {  SETLOCATION; return REG_X; }
y|Y {  SETLOCATION; return REG_Y; }
p|P {  SETLOCATION; return REG_P; }
s|S {  SETLOCATION; return REG_S; }
section  { SETLOCATION; return SECTION; }
origin { SETLOCATION; return ORIGIN; }
db  { SETLOCATION; return DB; }
dw { SETLOCATION; return DW; }

mov { SETLOCATION; return MOV; }
jmp { SETLOCATION; return JMP; }
nop { SETLOCATION; return NOP; }
num { SETLOCATION; return NUM; }


[0-9]+ {SETLOCATION; yylval.numval = atoi(yytext); return NUM; }
addc { SETLOCATION; return ADDC; }
and { SETLOCATION; return AND; }
bit { SETLOCATION; return BIT; }
brk { SETLOCATION; return BRK; }
call { SETLOCATION; return CALL; }
clr { SETLOCATION; return CLR; }
cmp { SETLOCATION; return CMP; }
inc { SETLOCATION; return INC; }
dec { SETLOCATION; return DEC; }
or { SETLOCATION; return OR; }
pull { SETLOCATION; return PULL; }
push { SETLOCATION; return PUSH; }
ret { SETLOCATION; return RET; }
reti { SETLOCATION; return RETI; }
rol { SETLOCATION; return ROL; }
ror { SETLOCATION; return ROR; }
set { SETLOCATION; return SET; }
trb { SETLOCATION; return TRB; }
tsb { SETLOCATION; return TSB; }
xor { SETLOCATION; return XOR; }
wait { SETLOCATION; return WAIT; }

":"  { SETLOCATION; return ':';}
"="  { SETLOCATION; return '=';}
"+"  { SETLOCATION; return '+';}
","  { SETLOCATION; return ',';}
"["  { SETLOCATION; return '[';}
"]"  { SETLOCATION; return ']';}
"-"  { SETLOCATION;  return '-';}
"*"  { SETLOCATION;  return '*';}


;.*  { SETLOCATION;  /*ignore comments*/}

\n { SETLOCATION linepos++; columnpos=1;  yylval.numval = 0;  return LF;}
[_a-zA-Z][_a-zA-Z0-9]* { SETLOCATION; yylval.identval = mystrdup(yytext); return IDENT; }



%%
