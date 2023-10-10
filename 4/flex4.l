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

call|CALL { return CALL; }

ret|RET { return RET; }

reti|RETI { return RETI; }

push|PUSH { return PUSH; }

pop|POP { return POP; }

sec|SEC { return SEC; }

clc|CLC { return CLC; }

sei|SEI { return SEI; }

cli|CLI { return CLI; }

clv|CLV { return CLV; }

rotl|ROTL { return ROTL; }

rotr|ROTR { return ROTR; }

db|DB { return DB; }

a|A { return REG_A; }

x|X { return REG_X; }

y|Y { return REG_Y; }

p|P { return REG_P; }

s|S { return REG_S; }

zp|ZP { return REG_ZP; }

[0-9]+ { yylval.numval = strtol(yytext, NULL, 10); return NUM; }

[A-Za-z][A-Za-z0-9_]* { yylval.identval = strdup(yytext); return IDENT; }

0x[0-9A-Fa-f]+ { yylval.numval = strtol(yytext, NULL, 16); return NUM; }

0b[01]+ { yylval.numval = strtol(yytext, NULL, 2); return NUM; }

" " { /*Lets get rid of the spaces*/ }

";".*|"/*"(.*[\n].*)*"*/" { /*Lets get rid of the comments*/ }

"," { return ','; }

"[" { return '['; }

"]" { return ']'; }

":" { return ':'; }

zp\[ { return ZPBRACKET; }

"+" { return '+'; }

\n|\r { return LF; }

. { return OTHER; }

%%

int yywrap(void) { return 1; }
