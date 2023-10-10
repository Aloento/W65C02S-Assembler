%{

#include <stdio.h>

#include "instructions.h"

#include "pasm.tab.h"

%}

%%



mov|MOV {  return MOV;  }

jmp|JMP {  return JMP;  }

nop|NOP {  return NOP;  }

a|A  {  return REG_A;  }
x|X  {  return REG_X;  }
(0|1|2|3|4|5|6|7|8|9)+   { yylval.numval=strtol(yytext, NULL, 10);  return NUM;  }

[A-Za-z][A-Za-z0-9]* { yylval.identval = strdup(yytext); return IDENT;}


0x(0|1|2|3|4|5|6|7|8|9)+  { return NUM;  }


" " { /*Lets get rid of the spaces*/  }

","  { return ','; }
"[" { return '['; }
"]" { return ']'; }
\n  { return LF; }
":" { return ':'; }

.  { return OTHER; }

%%

int yywrap(void){return 1;}

/*int main()
{
  yylex();
  return 0;
}
*/
