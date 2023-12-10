#include "ast.h"
#include "pasm.tab.h"
#include <stdio.h>

YYSTYPE yylval;

YYLTYPE yylloc;

int yylex();

void printtoken(int tok)
{
	switch (tok)
	{
	case REG_A: printf("%d.%d-%d.%d: REG_A \n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column);
		break;
	case REG_X: printf("%d.%d-%d.%d: REG_X \n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column);
		break;
	case REG_Y: printf("%d.%d-%d.%d: REG_Y \n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column);
		break;
	case REG_P: printf("%d.%d-%d.%d: REG_P \n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column);
		break;
	case REG_S: printf("%d.%d-%d.%d: REG_S \n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column);
		break;

	case MOV: printf("%d.%d-%d.%d: MOV \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case JMP: printf("%d.%d-%d.%d: JMP \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case NOP: printf("%d.%d-%d.%d: NOP \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case ADDC: printf("%d.%d-%d.%d: ADDC \n",
	                  yylloc.first_line, yylloc.first_column,
	                  yylloc.last_line, yylloc.last_column);
		break;
	case AND: printf("%d.%d-%d.%d: AND \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case BIT: printf("%d.%d-%d.%d: BIT \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case CLR: printf("%d.%d-%d.%d: CLR \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case CMP: printf("%d.%d-%d.%d: CMP \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case BRK: printf("%d.%d-%d.%d: BRK \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case INC: printf("%d.%d-%d.%d: INC \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case DEC: printf("%d.%d-%d.%d: DEC \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case OR: printf("%d.%d-%d.%d: OR \n",
	                yylloc.first_line, yylloc.first_column,
	                yylloc.last_line, yylloc.last_column);
		break;
	case PULL: printf("%d.%d-%d.%d: PULL \n",
	                  yylloc.first_line, yylloc.first_column,
	                  yylloc.last_line, yylloc.last_column);
		break;
	case PUSH: printf("%d.%d-%d.%d: PUSH \n",
	                  yylloc.first_line, yylloc.first_column,
	                  yylloc.last_line, yylloc.last_column);
		break;
	case RET: printf("%d.%d-%d.%d: RET \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case RETI: printf("%d.%d-%d.%d: RETI \n",
	                  yylloc.first_line, yylloc.first_column,
	                  yylloc.last_line, yylloc.last_column);
		break;
	case ROL: printf("%d.%d-%d.%d: ROL \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case ROR: printf("%d.%d-%d.%d: ROR \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case SET: printf("%d.%d-%d.%d: SET \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case TRB: printf("%d.%d-%d.%d: TRB \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case TSB: printf("%d.%d-%d.%d: TSB \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case XOR: printf("%d.%d-%d.%d: XOR \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case WAIT: printf("%d.%d-%d.%d: WAIT \n",
	                  yylloc.first_line, yylloc.first_column,
	                  yylloc.last_line, yylloc.last_column);
		break;
	case '=': printf("%d.%d-%d.%d: EQUAL \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case '-': printf("%d.%d-%d.%d: SUBTRACTCTION \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case '+': printf("%d.%d-%d.%d: ADDITION \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	case '*': printf("%d.%d-%d.%d: MULTIPLICATION \n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;

	case LF: printf("%d.%d-%d.%d: LF\n",
	                yylloc.first_line, yylloc.first_column,
	                yylloc.last_line, yylloc.last_column);
		break;
	case NUM: printf("%d.%d-%d.%d: NUM, value=%d\n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column, yylval.numval);
		break;
	case IDENT: printf("%d.%d-%d.%d: IDENT, value=%s\n",
	                   yylloc.first_line, yylloc.first_column,
	                   yylloc.last_line, yylloc.last_column, yylval.identval);
		break;
	case ':': printf("%d.%d-%d.%d: COLON\n",
	                 yylloc.first_line, yylloc.first_column,
	                 yylloc.last_line, yylloc.last_column);
		break;
	default: printf("%d: unknown token\n", yylloc.first_line);
		break;
	}
}


int main2(int argc, char** argv)
{
	int retval;
	while (retval = yylex())
	{
		printtoken(retval);
	}
	return 0;
}
