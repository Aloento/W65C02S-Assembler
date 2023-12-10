/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PASM_TAB_H_INCLUDED
# define YY_YY_PASM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE

enum yytokentype
{
	YYEMPTY = -2,
	YYEOF = 0,
	/* "end of file"  */
	YYerror = 256,
	/* error  */
	YYUNDEF = 257,
	/* "invalid token"  */
	NUM = 258,
	/* NUM  */
	IDENT = 259,
	/* IDENT  */
	REG_A = 260,
	/* REG_A  */
	REG_X = 261,
	/* REG_X  */
	REG_Y = 262,
	/* REG_Y  */
	REG_P = 263,
	/* REG_P  */
	REG_S = 264,
	/* REG_S  */
	LF = 265,
	/* LF  */
	SECTION = 266,
	/* SECTION  */
	ORIGIN = 267,
	/* ORIGIN  */
	DB = 268,
	/* DB  */
	DW = 269,
	/* DW  */
	ZP = 270,
	/* ZP  */
	MOV = 271,
	/* MOV  */
	JMP = 272,
	/* JMP  */
	INC = 273,
	/* INC  */
	ADDC = 274,
	/* ADDC  */
	AND = 275,
	/* AND  */
	ASL = 276,
	/* ASL  */
	BIT = 277,
	/* BIT  */
	BR = 278,
	/* BR  */
	BRK = 279,
	/* BRK  */
	CALL = 280,
	/* CALL  */
	CLR = 281,
	/* CLR  */
	CMP = 282,
	/* CMP  */
	DEC = 283,
	/* DEC  */
	OR = 284,
	/* OR  */
	PULL = 285,
	/* PULL  */
	PUSH = 286,
	/* PUSH  */
	RET = 287,
	/* RET  */
	RETI = 288,
	/* RETI  */
	ROL = 289,
	/* ROL  */
	ROR = 290,
	/* ROR  */
	SET = 291,
	/* SET  */
	TRB = 292,
	/* TRB  */
	TSB = 293,
	/* TSB  */
	XOR = 294,
	/* XOR  */
	WAIT = 295,
	/* WAIT  */
	NOP = 296,
	/* NOP  */
	CFLAG = 297,
	/* CFLAG  */
	DFLAG = 298,
	/* DFLAG  */
	IFLAG = 299,
	/* IFLAG  */
	NFLAG = 300,
	/* NFLAG  */
	VFLAG = 301,
	/* VFLAG  */
	ZFLAG = 302 /* ZFLAG  */
};

typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "pasm.y"

	int numval;
	char* identval;
	lines_node_t* linesnode;
	line_node_t* linenode;
	opcode_t opcode_value;
	expr_node_t* expr_value;
	argument_node_t arg_value;

#line 121 "pasm.tab.h"
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
	int first_line;
	int first_column;
	int last_line;
	int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse(void);


#endif /* !YY_YY_PASM_TAB_H_INCLUDED  */
