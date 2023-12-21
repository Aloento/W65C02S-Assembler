%{
#include "ast.h"
#include "pasm.tab.h"
#include <stdlib.h>
#include "utils.h"

static int linepos=1, columnpos=1;

#define SETLOCATION { yylloc.first_line = linepos; yylloc.first_column=columnpos; yylloc.last_line=linepos; columnpos += yyleng; yylloc.last_column=columnpos; }
%}

%option noyywrap

%x HEX
%x BIN

%%

y|Y { SETLOCATION; return REG_Y; }
s|S { SETLOCATION; return REG_S; }
x|X { SETLOCATION; return REG_X; }
p|P { SETLOCATION; return REG_P; }
a|A { SETLOCATION; return REG_A; }
cflag|CFLAG { SETLOCATION; return CFLAG; }
zflag|ZFLAG { SETLOCATION; return ZFLAG; }
iflag|IFLAG { SETLOCATION; return IFLAG; }
dflag|DFLAG { SETLOCATION; return DFLAG; }
nflag|NFLAG { SETLOCATION; return NFLAG; }
vflag|VFLAG { SETLOCATION; return VFLAG; }

and|AND { SETLOCATION; yylval.numval = 0; return AND; }
bit|BIT { SETLOCATION; yylval.numval = 0; return BIT; }
lsr|LSR { SETLOCATION; yylval.numval = 0; return LSR; }
cmp|CMP { SETLOCATION; yylval.numval = 0; return CMP; }
mov|MOV { SETLOCATION; yylval.numval = 0; return MOV; }
jmp|JMP { SETLOCATION; yylval.numval = 0; return JMP; }
nop|NOP { SETLOCATION; yylval.numval = 0; return NOP; }
brk|BRK { SETLOCATION; yylval.numval = 0; return BRK; }
addc|ADDC { SETLOCATION; yylval.numval = 0; return ADDC; }
add|ADD { SETLOCATION; yylval.numval = 0; return ADD; }
asl|ASL { SETLOCATION; yylval.numval = 0; return ASL; }
br|BR { SETLOCATION; yylval.numval = 0; return BR; }
call|CALL { SETLOCATION; yylval.numval = 0; return CALL; }
dec|DEC { SETLOCATION; yylval.numval = 0; return DEC; }
inc|INC { SETLOCATION; yylval.numval = 0; return INC; }
or|OR { SETLOCATION; yylval.numval = 0; return OR; }
pull|PULL { SETLOCATION; yylval.numval = 0; return PULL; }
push|PUSH { SETLOCATION; yylval.numval = 0; return PUSH; }
ret|RET { SETLOCATION; yylval.numval = 0; return RET; }
reti|RETI { SETLOCATION; yylval.numval = 0; return RETI; }
rol|ROL { SETLOCATION; yylval.numval = 0; return ROL; }
ror|ROR { SETLOCATION; yylval.numval = 0; return ROR; }
set|SET { SETLOCATION; yylval.numval = 0; return SET; }
stop|STOP { SETLOCATION; yylval.numval = 0; return STOP; }
subc|SUBC { SETLOCATION; yylval.numval = 0; return SUBC; }
trb|TRB { SETLOCATION; yylval.numval = 0; return TRB; }
tsb|TSB { SETLOCATION; yylval.numval = 0; return TSB; }
xor|XOR { SETLOCATION; yylval.numval = 0; return XOR; }
wait|WAIT { SETLOCATION; yylval.numval = 0; return WAIT; }
clr|CLR { SETLOCATION; yylval.numval = 0; return CLR; }
zp|ZP { SETLOCATION; yylval.numval = 0; return ZP; }

db { SETLOCATION; return DB; }
dw { SETLOCATION; return DW; }

section { SETLOCATION; return SECTION; }
origin { SETLOCATION; return ORIGIN; }

"[" { SETLOCATION; return '['; }
"]" { SETLOCATION; return ']'; }
"=" { SETLOCATION; return '='; }
"+" { SETLOCATION; return '+'; }
"-" { SETLOCATION; return '-'; }
"," { SETLOCATION; return ','; }
":" { SETLOCATION; return ':'; }
"(" { SETLOCATION; return '('; }
")" { SETLOCATION; return ')'; }
"|" { SETLOCATION; return '|'; }
"&" { SETLOCATION; return '&'; }
"^" { SETLOCATION; return '^'; }
"%" { SETLOCATION; return '%'; }
"/" { SETLOCATION; return '/'; }

[0-9]+ { SETLOCATION; yylval.numval = strtol(yytext, NULL, 10); return NUM; }
0x[0-9A-Fa-f]+ { SETLOCATION; yylval.numval = strtol(yytext, NULL, 16); return NUM; }
0b[01]+ { SETLOCATION; yylval.numval = strtol(yytext + 2, NULL, 2); return NUM; }
(_|[a-zA-Z])(_|[a-zA-Z0-9])+ { SETLOCATION; yylval.identval = mystrndup(yytext,yyleng); return IDENT; }

[\t]+ { /* Ignore whitespace */ }
\n|\r { SETLOCATION; linepos++; columnpos = 1; return LF; }
;[^\n]* { /* Ignore comments */ }

. { /* Unknown text */ }
%%
