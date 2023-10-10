%{

#include <stdio.h>

%}

%%

mov|MOV { printf("input mov"); }

jmp|JMP { printf("input jum"); }

nop|NOP { printf("No Operation or do nothing"); }

a|A { printf("register A"); }

x|X { printf("register X"); }

y|Y { printf("register Y"); }

num|NUM { printf("input num"); }

"[" { printf("open bracket"); printf("%s", yytext); }

"]" { printf("close bracket"); printf("%s", yytext); }

"," { printf("comma"); printf("%s", yytext); }

\n { printf("new line\n"); }

(-[0-9]|[0-9])+ { printf("NUM (decimal ) %s",yytext); }

(0x|0X)([0-9]|[a-f]|[A-F])+ {
    int val;
    printf("NUM(hex)");
    val = strtol(yytext + 2, NULL, 16);
    printf(" val: %d ", val);
}

" " { /* ignore space */ }

.  { printf("syntax error"); }

%%

int yywrap(void)
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}
