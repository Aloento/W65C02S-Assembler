%{

#include <stdio.h>

%}

%%



mov|MOV {  printf("Opcode ");  }

a  {  printf("register ");  }

(0|1|2|3|4|5|6|7|8|9)+   {  printf("arbitrary number ");  }

" " { /*Lets get rid of the spaces*/  }

"+"  { printf("plussz ");}



              
%%            
              
int yywrap(void){return 1;}
              
int main()
{
  yylex();
  return 0;
}

