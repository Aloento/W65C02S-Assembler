%{

#include <stdio.h>
#include "pasm.tab.h"

%}

%%

mov|MOV { return MOV; }

jmp|JMP { return JMP; }

nop|NOP { return NOP; }

a|A { return REG_A; }

x|X { return REG_X; }

y|Y { return REG_Y; }

"[" { return '['; }

"]" { return ']'; }

"," { return ','; }

":" { return ':'; }

";".* { return ';'; }

\n { return LF; }

^[0-9]*$ { return NUM; }

(?:0[xX])[0-9a-fA-F]+ { return NUM; }

[a-z]([0-9]|[a-z])* { return IDENT; }

" " { /* ignore space */ }

. { return OTHER; }

%%

int yywrap(void)
{
    return 1;
}
