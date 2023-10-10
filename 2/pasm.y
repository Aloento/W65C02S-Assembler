%{

#include <stdio.h>

%}

%token MOV
%token JMP
%token NOP

%token ','
%token '['
%token ']'
%token ':'
%token ';'

%token NUM
%token LF
%token REG_A
%token REG_X
%token REG_Y
%token OTH0ER
%token IDENT

%start asmfile

%%

asmfile : lines { printf("asmfile (start symbol) finished \n"); }
        |  { printf("empty file"); }

lines : line
      | lines line

line : LF
     | LF IDENT LF
     | opcode LF
     | opcode argument LF
     | opcode argument comment
     | opcode argument ',' argument LF
     | opcode IDENT LF
     | IDENT ':' LF
     | IDENT ':' opcode
     | argument LF
     | LF ';'
     | LF comment LF

opcode : MOV { printf("MOV \n"); }
       | JMP { printf("JMP \n"); }
       | NOP { printf("NOP \n"); }

argument : NUM
         | register
         | '[' NUM ']'
         | IDENT

register : REG_A
         | REG_X
         | REG_Y

comment : ';' LF

%%

int main()
{
    yyparse();
    return 0;
}

void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
}
