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
    NUM = 258,                     /* NUM  */
    IDENT = 259,                   /* IDENT  */
    REG_Y = 260,                   /* REG_Y  */
    REG_S = 261,                   /* REG_S  */
    REG_X = 262,                   /* REG_X  */
    REG_P = 263,                   /* REG_P  */
    REG_A = 264,                   /* REG_A  */
    LF = 265,                      /* LF  */
    CFLAG = 266,                   /* CFLAG  */
    DFLAG = 267,                   /* DFLAG  */
    IFLAG = 268,                   /* IFLAG  */
    NFLAG = 269,                   /* NFLAG  */
    VFLAG = 270,                   /* VFLAG  */
    ZFLAG = 271,                   /* ZFLAG  */
    ZP = 272,                      /* ZP  */
    OTHER = 273,                   /* OTHER  */
    MOV = 274,                     /* MOV  */
    JMP = 275,                     /* JMP  */
    NOP = 276,                     /* NOP  */
    BRK = 277,                     /* BRK  */
    ADDC = 278,                    /* ADDC  */
    ADD = 279,                     /* ADD  */
    ASL = 280,                     /* ASL  */
    BR = 281,                      /* BR  */
    CALL = 282,                    /* CALL  */
    DEC = 283,                     /* DEC  */
    INC = 284,                     /* INC  */
    OR = 285,                      /* OR  */
    PULL = 286,                    /* PULL  */
    PUSH = 287,                    /* PUSH  */
    RET = 288,                     /* RET  */
    RETI = 289,                    /* RETI  */
    ROL = 290,                     /* ROL  */
    ROR = 291,                     /* ROR  */
    SET = 292,                     /* SET  */
    STOP = 293,                    /* STOP  */
    CLR = 294,                     /* CLR  */
    SUBC = 295,                    /* SUBC  */
    TRB = 296,                     /* TRB  */
    TSB = 297,                     /* TSB  */
    XOR = 298,                     /* XOR  */
    WAIT = 299,                    /* WAIT  */
    DB = 300,                      /* DB  */
    DW = 301,                      /* DW  */
    SECTION = 302,                 /* SECTION  */
    ORIGIN = 303,                  /* ORIGIN  */
    AND = 304,                     /* AND  */
    BIT = 305,                     /* BIT  */
    LSR = 306,                     /* LSR  */
    CMP = 307                      /* CMP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "pasm.y"

  int numval;
  char *identval;
  lines_node_t *linesnode;
  line_node_t *linenode;
  opcode_t opcode_value;
  expr_node_t *expr_value;
  argument_node_t *argument_value;
  expr_list *elist;

#line 127 "pasm.tab.h"

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

int yyparse (void);


#endif /* !YY_YY_PASM_TAB_H_INCLUDED  */
