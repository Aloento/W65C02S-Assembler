%{

#include <stdio.h>
#include "instructions.h"
#include "pasm.tab.h"

%}

%%

mov|MOV { return MOV; }

jmp|JMP { return JMP; }

nop|NOP { return NOP; }

addc|ADDC { return ADDC; }

subc|SUBC { return SUBC; }

and|AND { return AND; }

or|OR { return OR; }

xor|XOR { return XOR; }

inc|INC { return INC; }

dec|DEC { return DEC; }

cmp|CMP { return CMP; }

bzs|BZS { return BZS; }

bzc|BZC { return BZC; }

bcs|BCS { return BCS; }

bcc|BCC { return BCC; }

a|A { return REG_A; }

x|X { return REG_X; }

y|Y { return REG_Y; }

(0|1|2|3|4|5|6|7|8|9)+ { yylval.numval = strtol(yytext, NULL, 10); return NUM; }

[A-Za-z][A-Za-z0-9]* { yylval.identval = strdup(yytext); return IDENT;}

0x(0|1|2|3|4|5|6|7|8|9|a|b|c|d|e|f)+ { yylval.numval = strtol(yytext, NULL, 16); return NUM; }

" " { /*Lets get rid of the spaces*/ }

";".*|"/*"(.*[\n].*)*"*/" { /*Lets get rid of the comments*/ }

"," { return ','; }

"[" { return '['; }

"]" { return ']'; }

\n { return LF; }

":" { return ':'; }

. { return OTHER; }

%%

int yywrap(void) { return 1; }
