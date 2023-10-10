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
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MOV = 258,                     /* MOV  */
    JMP = 259,                     /* JMP  */
    NOP = 260,                     /* NOP  */
    ADDC = 261,                    /* ADDC  */
    SUBC = 262,                    /* SUBC  */
    AND = 263,                     /* AND  */
    OR = 264,                      /* OR  */
    XOR = 265,                     /* XOR  */
    INC = 266,                     /* INC  */
    DEC = 267,                     /* DEC  */
    CMP = 268,                     /* CMP  */
    BZS = 269,                     /* BZS  */
    BZC = 270,                     /* BZC  */
    BCS = 271,                     /* BCS  */
    BCC = 272,                     /* BCC  */
    CALL = 273,                    /* CALL  */
    RET = 274,                     /* RET  */
    RETI = 275,                    /* RETI  */
    PUSH = 276,                    /* PUSH  */
    POP = 277,                     /* POP  */
    SEC = 278,                     /* SEC  */
    CLC = 279,                     /* CLC  */
    SEI = 280,                     /* SEI  */
    CLI = 281,                     /* CLI  */
    CLV = 282,                     /* CLV  */
    ROTL = 283,                    /* ROTL  */
    ROTR = 284,                    /* ROTR  */
    DB = 285,                      /* DB  */
    REG_A = 286,                   /* REG_A  */
    REG_X = 287,                   /* REG_X  */
    REG_Y = 288,                   /* REG_Y  */
    REG_P = 289,                   /* REG_P  */
    REG_S = 290,                   /* REG_S  */
    REG_ZP = 291,                  /* REG_ZP  */
    NUM = 292,                     /* NUM  */
    IDENT = 293,                   /* IDENT  */
    LF = 294,                      /* LF  */
    OTHER = 295                    /* OTHER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "pasm.y"

  int numval;
  struct argument_t argval;
  enum opcode_t opc;
  int regval;
  char * identval;
  struct llist_t * numbersval;

#line 113 "pasm.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PASM_TAB_H_INCLUDED  */
