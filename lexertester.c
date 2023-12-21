#include <stdio.h>
#include "ast.h"
#include "pasm.tab.h"

YYSTYPE yylval;

YYLTYPE yylloc;

int yylex();

void printtoken(int tok)
{
	switch (tok)
	{
	case MOV: printf("%d.%d-%d.%d: MOV\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case REG_X: printf("%d.%d-%d.%d: REG_X\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                   yylloc.last_column);
		break;
	case REG_A: printf("%d.%d-%d.%d: REG_A\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                   yylloc.last_column);
		break;
	case JMP: printf("%d.%d-%d.%d: JMP\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case NOP: printf("%d.%d-%d.%d: NOP\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case BRK: printf("%d.%d-%d.%d: BRK\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case ADDC: printf("%d.%d-%d.%d: ADDC\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case ADD: printf("%d.%d-%d.%d: ADD\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case ASL: printf("%d.%d-%d.%d: ASL\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case BR: printf("%d.%d-%d.%d: BR\n", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
		break;
	case CALL: printf("%d.%d-%d.%d: CALL\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case DEC: printf("%d.%d-%d.%d: DEC\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case INC: printf("%d.%d-%d.%d: INC\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case OR: printf("%d.%d-%d.%d: OR\n", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
		break;
	case PULL: printf("%d.%d-%d.%d: PULL\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case PUSH: printf("%d.%d-%d.%d: PUSH\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case RET: printf("%d.%d-%d.%d: RET\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case RETI: printf("%d.%d-%d.%d: RETI\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case ROL: printf("%d.%d-%d.%d: ROL\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case ROR: printf("%d.%d-%d.%d: ROR\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case SET: printf("%d.%d-%d.%d: SET\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case STOP: printf("%d.%d-%d.%d: STOP\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case SUBC: printf("%d.%d-%d.%d: SUBC\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case TRB: printf("%d.%d-%d.%d: TRB\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case TSB: printf("%d.%d-%d.%d: TSB\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case XOR: printf("%d.%d-%d.%d: XOR\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column);
		break;
	case WAIT: printf("%d.%d-%d.%d: WAIT\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                  yylloc.last_column);
		break;
	case IDENT: printf("%d.%d-%d.%d: IDENT %s\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                   yylloc.last_column, yylval.identval);
		break;
	case NUM: printf("%d.%d-%d.%d: NUM Value=%d\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                 yylloc.last_column, yylval.numval);
		break;
	case LF: printf("%d.%d-%d.%d: LF\n", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
		break;
	case DB: printf("%d.%d-%d.%d: DB\n", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
		break;
	case DW: printf("%d.%d-%d.%d: DW\n", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
		break;
	case SECTION: printf("%d.%d-%d.%d: SECTION\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                     yylloc.last_column);
		break;
	case ORIGIN: printf("%d.%d-%d.%d: ORIGIN\n", yylloc.first_line, yylloc.first_column, yylloc.last_line,
	                    yylloc.last_column);
		break;
	default: printf("%d: unknown token\n", yylloc.first_line);
		break;
	}
}


int main3(int argc, char** argv)
{
	int retval;
	while (retval = yylex())
	{
		printtoken(retval);
	}
	return 0;
}
