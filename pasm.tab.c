/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* First part of user prologue.  */
#line 1 "pasm.y"


#include <stdio.h>
#include "ast.h"
#include "utils.h"

void yyerror(const char* s);
extern int yylex(void);

extern astroot_t astroot;


#line 84 "pasm.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "pasm.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
	YYSYMBOL_YYEMPTY = -2,
	YYSYMBOL_YYEOF = 0,
	/* "end of file"  */
	YYSYMBOL_YYerror = 1,
	/* error  */
	YYSYMBOL_YYUNDEF = 2,
	/* "invalid token"  */
	YYSYMBOL_NUM = 3,
	/* NUM  */
	YYSYMBOL_IDENT = 4,
	/* IDENT  */
	YYSYMBOL_REG_A = 5,
	/* REG_A  */
	YYSYMBOL_REG_X = 6,
	/* REG_X  */
	YYSYMBOL_REG_Y = 7,
	/* REG_Y  */
	YYSYMBOL_REG_P = 8,
	/* REG_P  */
	YYSYMBOL_REG_S = 9,
	/* REG_S  */
	YYSYMBOL_LF = 10,
	/* LF  */
	YYSYMBOL_SECTION = 11,
	/* SECTION  */
	YYSYMBOL_ORIGIN = 12,
	/* ORIGIN  */
	YYSYMBOL_DB = 13,
	/* DB  */
	YYSYMBOL_DW = 14,
	/* DW  */
	YYSYMBOL_ZP = 15,
	/* ZP  */
	YYSYMBOL_MOV = 16,
	/* MOV  */
	YYSYMBOL_JMP = 17,
	/* JMP  */
	YYSYMBOL_INC = 18,
	/* INC  */
	YYSYMBOL_ADDC = 19,
	/* ADDC  */
	YYSYMBOL_AND = 20,
	/* AND  */
	YYSYMBOL_ASL = 21,
	/* ASL  */
	YYSYMBOL_BIT = 22,
	/* BIT  */
	YYSYMBOL_BR = 23,
	/* BR  */
	YYSYMBOL_BRK = 24,
	/* BRK  */
	YYSYMBOL_CALL = 25,
	/* CALL  */
	YYSYMBOL_CLR = 26,
	/* CLR  */
	YYSYMBOL_CMP = 27,
	/* CMP  */
	YYSYMBOL_DEC = 28,
	/* DEC  */
	YYSYMBOL_OR = 29,
	/* OR  */
	YYSYMBOL_PULL = 30,
	/* PULL  */
	YYSYMBOL_PUSH = 31,
	/* PUSH  */
	YYSYMBOL_RET = 32,
	/* RET  */
	YYSYMBOL_RETI = 33,
	/* RETI  */
	YYSYMBOL_ROL = 34,
	/* ROL  */
	YYSYMBOL_ROR = 35,
	/* ROR  */
	YYSYMBOL_SET = 36,
	/* SET  */
	YYSYMBOL_TRB = 37,
	/* TRB  */
	YYSYMBOL_TSB = 38,
	/* TSB  */
	YYSYMBOL_XOR = 39,
	/* XOR  */
	YYSYMBOL_WAIT = 40,
	/* WAIT  */
	YYSYMBOL_NOP = 41,
	/* NOP  */
	YYSYMBOL_CFLAG = 42,
	/* CFLAG  */
	YYSYMBOL_DFLAG = 43,
	/* DFLAG  */
	YYSYMBOL_IFLAG = 44,
	/* IFLAG  */
	YYSYMBOL_NFLAG = 45,
	/* NFLAG  */
	YYSYMBOL_VFLAG = 46,
	/* VFLAG  */
	YYSYMBOL_ZFLAG = 47,
	/* ZFLAG  */
	YYSYMBOL_48_ = 48,
	/* ','  */
	YYSYMBOL_49_ = 49,
	/* ':'  */
	YYSYMBOL_50_ = 50,
	/* '='  */
	YYSYMBOL_51_ = 51,
	/* '['  */
	YYSYMBOL_52_ = 52,
	/* ']'  */
	YYSYMBOL_53_ = 53,
	/* '+'  */
	YYSYMBOL_54_ = 54,
	/* '('  */
	YYSYMBOL_55_ = 55,
	/* ')'  */
	YYSYMBOL_56_ = 56,
	/* '-'  */
	YYSYMBOL_57_ = 57,
	/* '*'  */
	YYSYMBOL_58_ = 58,
	/* '/'  */
	YYSYMBOL_YYACCEPT = 59,
	/* $accept  */
	YYSYMBOL_asmfile = 60,
	/* asmfile  */
	YYSYMBOL_lines = 61,
	/* lines  */
	YYSYMBOL_line = 62,
	/* line  */
	YYSYMBOL_dbargs = 63,
	/* dbargs  */
	YYSYMBOL_opcode = 64,
	/* opcode  */
	YYSYMBOL_argument = 65,
	/* argument  */
	YYSYMBOL_expr = 66 /* expr  */
};

typedef enum yysymbol_kind_t yysymbol_kind_t;


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
	yy_state_t yyss_alloc;
	YYSTYPE yyvs_alloc;
	YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
	0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	54, 55, 57, 53, 48, 56, 2, 58, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 49, 2,
	2, 50, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 51, 2, 52, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
	35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
	45, 46, 47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    52,    53,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    67,    68,    69,    70,    72,
      73,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     129,   130,   131,   132,   133,   134,   135
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char* yysymbol_name(yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char* const yytname[] =
{
	"\"end of file\"", "error", "\"invalid token\"", "NUM", "IDENT",
	"REG_A", "REG_X", "REG_Y", "REG_P", "REG_S", "LF", "SECTION", "ORIGIN",
	"DB", "DW", "ZP", "MOV", "JMP", "INC", "ADDC", "AND", "ASL", "BIT", "BR",
	"BRK", "CALL", "CLR", "CMP", "DEC", "OR", "PULL", "PUSH", "RET", "RETI",
	"ROL", "ROR", "SET", "TRB", "TSB", "XOR", "WAIT", "NOP", "CFLAG",
	"DFLAG", "IFLAG", "NFLAG", "VFLAG", "ZFLAG", "','", "':'", "'='", "'['",
	"']'", "'+'", "'('", "')'", "'-'", "'*'", "'/'", "$accept", "asmfile",
	"lines", "line", "dbargs", "opcode", "argument", "expr", YY_NULLPTR
};

static const char*
yysymbol_name(yysymbol_kind_t yysymbol)
{
	return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
	-55, 10, 171, -55, -46, -55, 9, 48, 48, -55,
	-55, -55, -55, -55, -55, -55, -55, -55, -55, -55,
	-55, -55, -55, -55, -55, -55, -55, -55, -55, -55,
	-55, -55, -55, -55, 54, 203, 48, 4, -55, -55,
	48, -5, 105, -3, -55, -55, -55, -55, -55, -55,
	-21, -18, -55, -55, -11, 6, 17, 16, -2, 105,
	-55, 48, 48, 74, 37, 71, 99, -55, 48, 48,
	48, 48, 48, -55, 48, 72, 83, 84, 85, 40,
	57, -55, 126, 1, 2, -55, 23, -55, 94, -55,
	105, 105, 105, 105, 105, 86, -55, -55, -55, -55,
	48, -55, 11, 96, -55, -55, -55, 126, -55, -55,
	18, 93, 51, 55, -55, 101, 60, 70, -26, 38,
	-55, -55, -55, -55, -55, -55, 116, 75, 88, 95,
	-55, -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
	4, 0, 2, 1, 0, 12, 0, 0, 0, 21,
	22, 23, 26, 27, 28, 24, 29, 44, 25, 30,
	31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 3, 0, 0, 0, 0, 70, 71,
	0, 0, 19, 0, 55, 56, 57, 59, 58, 7,
	0, 60, 62, 63, 64, 66, 68, 0, 0, 45,
	11, 0, 0, 0, 0, 0, 0, 15, 0, 0,
	0, 0, 0, 16, 0, 0, 0, 0, 0, 0,
	0, 6, 0, 0, 0, 10, 0, 14, 0, 73,
	20, 72, 74, 75, 76, 0, 61, 65, 67, 69,
	0, 46, 0, 0, 17, 18, 9, 0, 13, 49,
	0, 0, 0, 0, 5, 0, 0, 0, 0, 0,
	47, 48, 8, 50, 51, 52, 0, 0, 0, 0,
	54, 53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
	-55, -55, -55, -55, -7, 89, -54, -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
	0, 1, 2, 33, 41, 34, 58, 42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
	59, 43, 64, 35, 36, 67, 66, 73, 81, 86,
	3, 104, 105, 37, 38, 39, 65, 112, 113, 38,
	39, 38, 39, 80, 116, 117, 125, 126, 103, 59,
	74, 79, 75, 106, 90, 91, 92, 93, 94, 76,
	95, 38, 39, 68, 127, 68, 82, 87, 59, 68,
	68, 38, 39, 115, 83, 84, 77, 38, 39, 44,
	45, 46, 47, 48, 49, 40, 111, 78, 91, 50,
	40, 107, 40, 59, 88, 96, 91, 38, 39, 44,
	45, 46, 47, 48, 85, 91, 97, 98, 99, 50,
	69, 100, 40, 70, 71, 72, 51, 52, 53, 54,
	55, 56, 40, 120, 108, 57, 114, 121, 40, 101,
	102, 122, 123, 70, 71, 72, 51, 52, 53, 54,
	55, 56, 124, 128, 63, 57, 0, 129, 40, 38,
	39, 44, 45, 46, 47, 48, 0, 0, 109, 110,
	130, 50, 70, 71, 72, 118, 119, 131, 0, 70,
	71, 72, 69, 0, 89, 70, 71, 72, 69, 0,
	0, 70, 71, 72, 0, 0, 0, 0, 51, 52,
	53, 54, 55, 56, 0, 4, 0, 57, 0, 0,
	40, 5, 6, 0, 7, 8, 0, 9, 10, 11,
	12, 0, 13, 0, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 60, 0, 0, 61, 62, 0, 9,
	10, 11, 12, 0, 13, 0, 14, 15, 16, 17,
	18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
	28, 29, 30, 31, 32
};

static const yytype_int8 yycheck[] =
{
	34, 8, 36, 49, 50, 10, 40, 10, 10, 63,
	0, 10, 10, 4, 3, 4, 12, 6, 7, 3,
	4, 3, 4, 57, 6, 7, 52, 53, 82, 63,
	51, 15, 50, 10, 68, 69, 70, 71, 72, 50,
	74, 3, 4, 48, 6, 48, 48, 10, 82, 48,
	48, 3, 4, 107, 61, 62, 50, 3, 4, 5,
	6, 7, 8, 9, 10, 54, 100, 50, 102, 15,
	54, 48, 54, 107, 3, 3, 110, 3, 4, 5,
	6, 7, 8, 9, 10, 119, 3, 3, 3, 15,
	53, 51, 54, 56, 57, 58, 42, 43, 44, 45,
	46, 47, 54, 52, 10, 51, 10, 52, 54, 52,
	53, 10, 52, 56, 57, 58, 42, 43, 44, 45,
	46, 47, 52, 7, 35, 51, -1, 52, 54, 3,
	4, 5, 6, 7, 8, 9, -1, -1, 52, 53,
	52, 15, 56, 57, 58, 52, 53, 52, -1, 56,
	57, 58, 53, -1, 55, 56, 57, 58, 53, -1,
	-1, 56, 57, 58, -1, -1, -1, -1, 42, 43,
	44, 45, 46, 47, -1, 4, -1, 51, -1, -1,
	54, 10, 11, -1, 13, 14, -1, 16, 17, 18,
	19, -1, 21, -1, 23, 24, 25, 26, 27, 28,
	29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
	39, 40, 41, 10, -1, -1, 13, 14, -1, 16,
	17, 18, 19, -1, 21, -1, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
	37, 38, 39, 40, 41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
	0, 60, 61, 0, 4, 10, 11, 13, 14, 16,
	17, 18, 19, 21, 23, 24, 25, 26, 27, 28,
	29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
	39, 40, 41, 62, 64, 49, 50, 4, 3, 4,
	54, 63, 66, 63, 5, 6, 7, 8, 9, 10,
	15, 42, 43, 44, 45, 46, 47, 51, 65, 66,
	10, 13, 14, 64, 66, 12, 66, 10, 48, 53,
	56, 57, 58, 10, 51, 50, 50, 50, 50, 15,
	66, 10, 48, 63, 63, 10, 65, 10, 3, 55,
	66, 66, 66, 66, 66, 66, 3, 3, 3, 3,
	51, 52, 53, 65, 10, 10, 10, 48, 10, 52,
	53, 66, 6, 7, 10, 65, 6, 7, 52, 53,
	52, 52, 10, 52, 52, 52, 53, 6, 7, 52,
	52, 52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
	0, 59, 60, 61, 61, 62, 62, 62, 62, 62,
	62, 62, 62, 62, 62, 62, 62, 62, 62, 63,
	63, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
	64, 64, 64, 64, 64, 65, 65, 65, 65, 65,
	65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
	65, 65, 65, 65, 65, 65, 65, 65, 65, 65,
	66, 66, 66, 66, 66, 66, 66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
	0, 2, 1, 2, 0, 5, 3, 2, 7, 5,
	4, 3, 1, 5, 4, 3, 3, 5, 5, 1,
	3, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 3, 5, 5, 4,
	6, 6, 6, 8, 8, 1, 1, 1, 1, 1,
	1, 3, 1, 1, 1, 3, 1, 3, 1, 3,
	1, 1, 3, 3, 3, 3, 3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
	yy_state_t* yyssp;
	yysymbol_kind_t yytoken;
	YYLTYPE* yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens(const yypcontext_t* yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
	/* Actual size of YYARG. */
	int yycount = 0;
	int yyn = yypact[+*yyctx->yyssp];
	if (!yypact_value_is_default(yyn))
	{
		/* Start YYX at -YYN if negative to avoid negative indexes in
		   YYCHECK.  In other words, skip the first -YYN actions for
		   this state because they are default actions.  */
		int yyxbegin = yyn < 0 ? -yyn : 0;
		/* Stay within bounds of both yycheck and yytname.  */
		int yychecklim = YYLAST - yyn + 1;
		int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
		int yyx;
		for (yyx = yyxbegin; yyx < yyxend; ++yyx)
			if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
				&& !yytable_value_is_error(yytable[yyx + yyn]))
			{
				if (!yyarg)
					++yycount;
				else if (yycount == yyargn)
					return 0;
				else
					yyarg[yycount++] = YY_CAST(yysymbol_kind_t, yyx);
			}
	}
	if (yyarg && yycount == 0 && 0 < yyargn)
		yyarg[0] = YYSYMBOL_YYEMPTY;
	return yycount;
}


#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen(const char* yystr)
{
	YYPTRDIFF_T yylen;
	for (yylen = 0; yystr[yylen]; yylen++)
		continue;
	return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char*
yystpcpy(char* yydest, const char* yysrc)
{
	char* yyd = yydest;
	const char* yys = yysrc;

	while ((*yyd++ = *yys++) != '\0')
		continue;

	return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr(char* yyres, const char* yystr)
{
	if (*yystr == '"')
	{
		YYPTRDIFF_T yyn = 0;
		const char* yyp = yystr;
		for (;;)
			switch (*++yyp)
			{
			case '\'':
			case ',':
				goto do_not_strip_quotes;

			case '\\':
				{
					if (*++yyp != '\\')
						goto do_not_strip_quotes;
				}

			append:
			default:
				if (yyres)
					yyres[yyn] = *yyp;
				yyn++;
				break;

			case '"':
				if (yyres)
					yyres[yyn] = '\0';
				return yyn;
			}
	do_not_strip_quotes: ;
	}

	if (yyres)
		return yystpcpy(yyres, yystr) - yyres;
	return yystrlen(yystr);
}
#endif


static int
yy_syntax_error_arguments(const yypcontext_t* yyctx,
                          yysymbol_kind_t yyarg[], int yyargn)
{
	/* Actual size of YYARG. */
	int yycount = 0;
	/* There are many possibilities here to consider:
	   - If this state is a consistent state with a default action, then
	     the only way this function was invoked is if the default action
	     is an error action.  In that case, don't check for expected
	     tokens because there are none.
	   - The only way there can be no lookahead present (in yychar) is if
	     this state is a consistent state with a default action.  Thus,
	     detecting the absence of a lookahead is sufficient to determine
	     that there is no unexpected or expected token to report.  In that
	     case, just report a simple "syntax error".
	   - Don't assume there isn't a lookahead just because this state is a
	     consistent state with a default action.  There might have been a
	     previous inconsistent state, consistent state with a non-default
	     action, or user semantic action that manipulated yychar.
	   - Of course, the expected token list depends on states to have
	     correct lookahead information, and it depends on the parser not
	     to perform extra reductions after fetching a lookahead from the
	     scanner and before detecting a syntax error.  Thus, state merging
	     (from LALR or IELR) and default reductions corrupt the expected
	     token list.  However, the list is correct for canonical LR with
	     one exception: it will still contain any token that will not be
	     accepted due to an error action in a later state.
	*/
	if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
	{
		int yyn;
		if (yyarg)
			yyarg[yycount] = yyctx->yytoken;
		++yycount;
		yyn = yypcontext_expected_tokens(yyctx,
		                                 yyarg ? yyarg + 1 : yyarg, yyargn - 1);
		if (yyn == YYENOMEM)
			return YYENOMEM;
		yycount += yyn;
	}
	return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error(YYPTRDIFF_T* yymsg_alloc, char** yymsg,
               const yypcontext_t* yyctx)
{
	enum { YYARGS_MAX = 5 };
	/* Internationalized format string. */
	const char* yyformat = YY_NULLPTR;
	/* Arguments of yyformat: reported tokens (one for the "unexpected",
	   one per "expected"). */
	yysymbol_kind_t yyarg[YYARGS_MAX];
	/* Cumulated lengths of YYARG.  */
	YYPTRDIFF_T yysize = 0;

	/* Actual size of YYARG. */
	int yycount = yy_syntax_error_arguments(yyctx, yyarg, YYARGS_MAX);
	if (yycount == YYENOMEM)
		return YYENOMEM;

	switch (yycount)
	{
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
	default: /* Avoid compiler warnings. */
	YYCASE_(0, YY_("syntax error"));
	YYCASE_(1, YY_("syntax error, unexpected %s"));
	YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
	YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
	YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
	YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
	}

	/* Compute error message size.  Don't count the "%s"s, but reserve
	   room for the terminator.  */
	yysize = yystrlen(yyformat) - 2 * yycount + 1;
	{
		int yyi;
		for (yyi = 0; yyi < yycount; ++yyi)
		{
			YYPTRDIFF_T yysize1
				= yysize + yytnamerr(YY_NULLPTR, yytname[yyarg[yyi]]);
			if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
				yysize = yysize1;
			else
				return YYENOMEM;
		}
	}

	if (*yymsg_alloc < yysize)
	{
		*yymsg_alloc = 2 * yysize;
		if (!(yysize <= *yymsg_alloc
			&& *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
			*yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
		return -1;
	}

	/* Avoid sprintf, as that infringes on the user's name space.
	   Don't have undefined behavior even if the translation
	   produced a string with the wrong number of "%s"s.  */
	{
		char* yyp = *yymsg;
		int yyi = 0;
		while ((*yyp = *yyformat) != '\0')
			if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
			{
				yyp += yytnamerr(yyp, yytname[yyarg[yyi++]]);
				yyformat += 2;
			}
			else
			{
				++yyp;
				++yyformat;
			}
	}
	return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct(const char* yymsg,
           yysymbol_kind_t yykind, YYSTYPE* yyvaluep, YYLTYPE* yylocationp)
{
	YY_USE(yyvaluep);
	YY_USE(yylocationp);
	if (!yymsg)
		yymsg = "Deleting";
	YY_SYMBOL_PRINT(yymsg, yykind, yyvaluep, yylocationp);

	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
	YY_USE(yykind);
	YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
	= {1, 1, 1, 1}
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse(void)
{
	yy_state_fast_t yystate = 0;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus = 0;

	/* Refer to the stacks through separate pointers, to allow yyoverflow
	   to reallocate them elsewhere.  */

	/* Their size.  */
	YYPTRDIFF_T yystacksize = YYINITDEPTH;

	/* The state stack: array, bottom, top.  */
	yy_state_t yyssa[YYINITDEPTH];
	yy_state_t* yyss = yyssa;
	yy_state_t* yyssp = yyss;

	/* The semantic value stack: array, bottom, top.  */
	YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE* yyvs = yyvsa;
	YYSTYPE* yyvsp = yyvs;

	/* The location stack: array, bottom, top.  */
	YYLTYPE yylsa[YYINITDEPTH];
	YYLTYPE* yyls = yylsa;
	YYLTYPE* yylsp = yyls;

	int yyn;
	/* The return value of yyparse.  */
	int yyresult;
	/* Lookahead symbol kind.  */
	yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
	/* The variables used to return semantic value and location from the
	   action routines.  */
	YYSTYPE yyval;
	YYLTYPE yyloc;

	/* The locations where the error started and ended.  */
	YYLTYPE yyerror_range[3];

	/* Buffer for error messages, and its allocated size.  */
	char yymsgbuf[128];
	char* yymsg = yymsgbuf;
	YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

	/* The number of symbols on the RHS of the reduced rule.
	   Keep to zero when no symbol should be popped.  */
	int yylen = 0;

	YYDPRINTF((stderr, "Starting parse\n"));

	yychar = YYEMPTY; /* Cause a token to be read.  */

	yylsp[0] = yylloc;
	goto yysetstate;


	/*------------------------------------------------------------.
	| yynewstate -- push a new state, which is found in yystate.  |
	`------------------------------------------------------------*/
yynewstate:
	/* In all cases, when you get here, the value and location stacks
	   have just been pushed.  So pushing a state here evens the stacks.  */
	yyssp++;


	/*--------------------------------------------------------------------.
	| yysetstate -- set current state (the top of the stack) to yystate.  |
	`--------------------------------------------------------------------*/
yysetstate:
	YYDPRINTF((stderr, "Entering state %d\n", yystate));
	YY_ASSERT(0 <= yystate && yystate < YYNSTATES);
	YY_IGNORE_USELESS_CAST_BEGIN
	*yyssp = YY_CAST(yy_state_t, yystate);
	YY_IGNORE_USELESS_CAST_END
	YY_STACK_PRINT(yyss, yyssp);

	if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
	{
		/* Get the current used size of the three stacks, in elements.  */
		YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
		/* Extend the stack our own way.  */
		if (YYMAXDEPTH <= yystacksize)
			YYNOMEM;
		yystacksize *= 2;
		if (YYMAXDEPTH < yystacksize)
			yystacksize = YYMAXDEPTH;

		{
			yy_state_t* yyss1 = yyss;
			union yyalloc* yyptr =
				YY_CAST(union yyalloc *,
				        YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
			if (!yyptr)
				YYNOMEM;
			YYSTACK_RELOCATE(yyss_alloc, yyss);
			YYSTACK_RELOCATE(yyvs_alloc, yyvs);
			YYSTACK_RELOCATE(yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
			if (yyss1 != yyssa)
				YYSTACK_FREE(yyss1);
		}
# endif

		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;
		yylsp = yyls + yysize - 1;

		YY_IGNORE_USELESS_CAST_BEGIN
		YYDPRINTF((stderr, "Stack size increased to %ld\n",
			YY_CAST (long, yystacksize)));
		YY_IGNORE_USELESS_CAST_END

		if (yyss + yystacksize - 1 <= yyssp)
			YYABORT;
	}
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


	if (yystate == YYFINAL)
		YYACCEPT;


	/*-----------.
| yybackup.  |
`-----------*/
yybackup:
	/* Do appropriate processing given the current state.  Read a
	   lookahead token if we need one and don't already have one.  */

	/* First try to decide what to do without reference to lookahead token.  */
	yyn = yypact[yystate];
	if (yypact_value_is_default(yyn))
		goto yydefault;

	/* Not known => get a lookahead token if don't already have one.  */

	/* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
	if (yychar == YYEMPTY)
	{
		YYDPRINTF((stderr, "Reading a token\n"));
		yychar = yylex();
	}

	if (yychar <= YYEOF)
	{
		yychar = YYEOF;
		yytoken = YYSYMBOL_YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	}
	else if (yychar == YYerror)
	{
		/* The scanner already issued an error message, process directly
		   to error recovery.  But do not keep the error token as
		   lookahead, it is too special and may lead us to an endless
		   loop in error recovery. */
		yychar = YYUNDEF;
		yytoken = YYSYMBOL_YYerror;
		yyerror_range[1] = yylloc;
		goto yyerrlab1;
	}
	else
	{
		yytoken = YYTRANSLATE(yychar);
		YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
	}

	/* If the proper action on seeing token YYTOKEN is to reduce or to
	   detect an error, take that action.  */
	yyn += yytoken;
	if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
		goto yydefault;
	yyn = yytable[yyn];
	if (yyn <= 0)
	{
		if (yytable_value_is_error(yyn))
			goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}

	/* Count tokens shifted since error; after three, turn off error
	   status.  */
	if (yyerrstatus)
		yyerrstatus--;

	/* Shift the lookahead token.  */
	YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);
	yystate = yyn;
	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
	*++yyvsp = yylval;
	YY_IGNORE_MAYBE_UNINITIALIZED_END
	*++yylsp = yylloc;

	/* Discard the shifted token.  */
	yychar = YYEMPTY;
	goto yynewstate;


	/*-----------------------------------------------------------.
	| yydefault -- do the default action for the current state.  |
	`-----------------------------------------------------------*/
yydefault:
	yyn = yydefact[yystate];
	if (yyn == 0)
		goto yyerrlab;


	/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
	/* yyn is the number of a rule to reduce with.  */
	yylen = yyr2[yyn];

	/* If YYLEN is nonzero, implement the default value of the action:
	   '$$ = $1'.
  
	   Otherwise, the following line sets YYVAL to garbage.
	   This behavior is undocumented and Bison
	   users should not rely upon it.  Assigning to YYVAL
	   unconditionally makes the parser a bit smaller, and it avoids a
	   GCC warning that YYVAL may be used uninitialized.  */
	yyval = yyvsp[1 - yylen];

	/* Default location. */
	YYLLOC_DEFAULT(yyloc, (yylsp - yylen), yylen);
	yyerror_range[1] = yyloc;
	YY_REDUCE_PRINT(yyn);
	switch (yyn)
	{
	case 2: /* asmfile: lines  */
#line 50 "pasm.y"
		{
			astroot = (yyvsp[0].linesnode);
			printf("complete file found\n");
			fflush(stdout);
		}
#line 1629 "pasm.tab.c"
		break;

	case 3: /* lines: lines line  */
#line 52 "pasm.y"
		{
			(yyval.linesnode) = addline((yyvsp[-1].linesnode), (yyvsp[0].linenode));
			printf("lines found\n");
			fflush(stdout);
		}
#line 1635 "pasm.tab.c"
		break;

	case 4: /* lines: %empty  */
#line 53 "pasm.y"
		{
			(yyval.linesnode) = newlines();
			printf("found nothing\n");
			fflush(stdout);
		}
#line 1641 "pasm.tab.c"
		break;

	case 5: /* line: opcode argument ',' argument LF  */
#line 55 "pasm.y"
		{
			(yyval.linenode) = newline_instruction2((yyvsp[-4].opcode_value), (yyvsp[-3].arg_value),
			                                        (yyvsp[-1].arg_value), (yyloc));
			printf("line with two arg opcode found\n");
			fflush(stdout);
		}
#line 1647 "pasm.tab.c"
		break;

	case 6: /* line: opcode argument LF  */
#line 56 "pasm.y"
		{
			(yyval.linenode) = newline_instruction1((yyvsp[-2].opcode_value), (yyvsp[-1].arg_value), (yyloc));
			printf("line with one arg opcode found\n");
			fflush(stdout);
		}
#line 1653 "pasm.tab.c"
		break;

	case 7: /* line: opcode LF  */
#line 57 "pasm.y"
		{
			(yyval.linenode) = newline_instruction0((yyvsp[-1].opcode_value), (yyloc));
			printf("line with zero arg opcode found\n");
			fflush(stdout);
		}
#line 1659 "pasm.tab.c"
		break;

	case 8: /* line: IDENT ':' opcode argument ',' argument LF  */
#line 58 "pasm.y"
		{
			(yyval.linenode) = newline_label_instruction2((yyvsp[-6].identval), (yyvsp[-4].opcode_value),
			                                              (yyvsp[-3].arg_value), (yyvsp[-1].arg_value), (yyloc));
			printf("line with label and two arg opcode found\n");
			fflush(stdout);
		}
#line 1665 "pasm.tab.c"
		break;

	case 9: /* line: IDENT ':' opcode argument LF  */
#line 59 "pasm.y"
		{
			(yyval.linenode) = newline_label_instruction1((yyvsp[-4].identval), (yyvsp[-2].opcode_value),
			                                              (yyvsp[-1].arg_value), (yyloc));
			printf("line with label and one arg opcode found\n");
			fflush(stdout);
		}
#line 1671 "pasm.tab.c"
		break;

	case 10: /* line: IDENT ':' opcode LF  */
#line 60 "pasm.y"
		{
			(yyval.linenode) = newline_label_instruction0((yyvsp[-3].identval), (yyvsp[-1].opcode_value), (yyloc));
			printf("line with label and zero arg opcode found\n");
			fflush(stdout);
		}
#line 1677 "pasm.tab.c"
		break;

	case 11: /* line: IDENT ':' LF  */
#line 61 "pasm.y"
		{
			(yyval.linenode) = newline_label((yyvsp[-2].identval), (yyloc));
			printf("line with label found, value=%s\n", (yyvsp[-2].identval));
			fflush(stdout);
		}
#line 1683 "pasm.tab.c"
		break;

	case 12: /* line: LF  */
#line 62 "pasm.y"
		{
			(yyval.linenode) = NULL;
			printf("empty line found\n");
			fflush(stdout);
		}
#line 1689 "pasm.tab.c"
		break;

	case 13: /* line: SECTION IDENT ORIGIN NUM LF  */
#line 63 "pasm.y"
		{
			(yyval.linenode) = newline_section((yyvsp[-3].identval), (yyvsp[-1].numval), (yyloc));
			printf("section found\n");
			fflush(stdout);
		}
#line 1695 "pasm.tab.c"
		break;

	case 14: /* line: IDENT '=' expr LF  */
#line 65 "pasm.y"
		{
			(yyval.linenode) = newline_definition((yyvsp[-3].identval), (yyvsp[-1].expr_value), (yyloc));
			printf("definition found\n");
			fflush(stdout);
		}
#line 1701 "pasm.tab.c"
		break;

	case 15: /* line: DB dbargs LF  */
#line 67 "pasm.y"
		{
			(yyval.linenode) = NULL;
			printf("DB line found\n");
			fflush(stdout);
		}
#line 1707 "pasm.tab.c"
		break;

	case 16: /* line: DW dbargs LF  */
#line 68 "pasm.y"
		{
			(yyval.linenode) = NULL;
			printf("DW line found\n");
			fflush(stdout);
		}
#line 1713 "pasm.tab.c"
		break;

	case 17: /* line: IDENT ':' DB dbargs LF  */
#line 69 "pasm.y"
		{
			(yyval.linenode) = NULL;
			printf("DB with label line found\n");
			fflush(stdout);
		}
#line 1719 "pasm.tab.c"
		break;

	case 18: /* line: IDENT ':' DW dbargs LF  */
#line 70 "pasm.y"
		{
			(yyval.linenode) = NULL;
			printf("DW with label line found\n");
			fflush(stdout);
		}
#line 1725 "pasm.tab.c"
		break;

	case 19: /* dbargs: expr  */
#line 72 "pasm.y"
		{
		}
#line 1731 "pasm.tab.c"
		break;

	case 20: /* dbargs: dbargs ',' expr  */
#line 73 "pasm.y"
		{
		}
#line 1737 "pasm.tab.c"
		break;

	case 21: /* opcode: MOV  */
#line 76 "pasm.y"
		{
			(yyval.opcode_value) = OP_MOV;
			printf("opcode MOV found\n");
			fflush(stdout);
		}
#line 1743 "pasm.tab.c"
		break;

	case 22: /* opcode: JMP  */
#line 77 "pasm.y"
		{
			(yyval.opcode_value) = OP_JMP;
			printf("opcode JMP found\n");
			fflush(stdout);
		}
#line 1749 "pasm.tab.c"
		break;

	case 23: /* opcode: INC  */
#line 78 "pasm.y"
		{
			(yyval.opcode_value) = OP_INC;
			printf("opcode INC found\n");
			fflush(stdout);
		}
#line 1755 "pasm.tab.c"
		break;

	case 24: /* opcode: BRK  */
#line 79 "pasm.y"
		{
			(yyval.opcode_value) = OP_BRK;
			fflush(stdout);
		}
#line 1761 "pasm.tab.c"
		break;

	case 25: /* opcode: CMP  */
#line 80 "pasm.y"
		{
			(yyval.opcode_value) = OP_CMP;
			fflush(stdout);
		}
#line 1767 "pasm.tab.c"
		break;

	case 26: /* opcode: ADDC  */
#line 81 "pasm.y"
		{
			(yyval.opcode_value) = OP_ADDC;
			fflush(stdout);
		}
#line 1773 "pasm.tab.c"
		break;

	case 27: /* opcode: ASL  */
#line 82 "pasm.y"
		{
			(yyval.opcode_value) = OP_ASL;
			fflush(stdout);
		}
#line 1779 "pasm.tab.c"
		break;

	case 28: /* opcode: BR  */
#line 83 "pasm.y"
		{
			(yyval.opcode_value) = OP_BR;
			fflush(stdout);
		}
#line 1785 "pasm.tab.c"
		break;

	case 29: /* opcode: CALL  */
#line 84 "pasm.y"
		{
			(yyval.opcode_value) = OP_CALL;
			fflush(stdout);
		}
#line 1791 "pasm.tab.c"
		break;

	case 30: /* opcode: DEC  */
#line 85 "pasm.y"
		{
			(yyval.opcode_value) = OP_DEC;
			fflush(stdout);
		}
#line 1797 "pasm.tab.c"
		break;

	case 31: /* opcode: OR  */
#line 86 "pasm.y"
		{
			(yyval.opcode_value) = OP_OR;
			fflush(stdout);
		}
#line 1803 "pasm.tab.c"
		break;

	case 32: /* opcode: PULL  */
#line 87 "pasm.y"
		{
			(yyval.opcode_value) = OP_PULL;
			fflush(stdout);
		}
#line 1809 "pasm.tab.c"
		break;

	case 33: /* opcode: PUSH  */
#line 88 "pasm.y"
		{
			(yyval.opcode_value) = OP_PUSH;
			fflush(stdout);
		}
#line 1815 "pasm.tab.c"
		break;

	case 34: /* opcode: RET  */
#line 89 "pasm.y"
		{
			(yyval.opcode_value) = OP_RET;
			fflush(stdout);
		}
#line 1821 "pasm.tab.c"
		break;

	case 35: /* opcode: RETI  */
#line 90 "pasm.y"
		{
			(yyval.opcode_value) = OP_RETI;
			fflush(stdout);
		}
#line 1827 "pasm.tab.c"
		break;

	case 36: /* opcode: ROL  */
#line 91 "pasm.y"
		{
			(yyval.opcode_value) = OP_ROL;
			fflush(stdout);
		}
#line 1833 "pasm.tab.c"
		break;

	case 37: /* opcode: ROR  */
#line 92 "pasm.y"
		{
			(yyval.opcode_value) = OP_ROR;
			fflush(stdout);
		}
#line 1839 "pasm.tab.c"
		break;

	case 38: /* opcode: SET  */
#line 93 "pasm.y"
		{
			(yyval.opcode_value) = OP_SET;
			fflush(stdout);
		}
#line 1845 "pasm.tab.c"
		break;

	case 39: /* opcode: TRB  */
#line 94 "pasm.y"
		{
			(yyval.opcode_value) = OP_TRB;
			fflush(stdout);
		}
#line 1851 "pasm.tab.c"
		break;

	case 40: /* opcode: TSB  */
#line 95 "pasm.y"
		{
			(yyval.opcode_value) = OP_TSB;
			fflush(stdout);
		}
#line 1857 "pasm.tab.c"
		break;

	case 41: /* opcode: XOR  */
#line 96 "pasm.y"
		{
			(yyval.opcode_value) = OP_XOR;
			fflush(stdout);
		}
#line 1863 "pasm.tab.c"
		break;

	case 42: /* opcode: WAIT  */
#line 97 "pasm.y"
		{
			(yyval.opcode_value) = OP_WAIT;
			fflush(stdout);
		}
#line 1869 "pasm.tab.c"
		break;

	case 43: /* opcode: NOP  */
#line 98 "pasm.y"
		{
			(yyval.opcode_value) = OP_NOP;
			fflush(stdout);
		}
#line 1875 "pasm.tab.c"
		break;

	case 44: /* opcode: CLR  */
#line 99 "pasm.y"
		{
			(yyval.opcode_value) = OP_CLR;
			fflush(stdout);
		}
#line 1881 "pasm.tab.c"
		break;

	case 45: /* argument: expr  */
#line 102 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_IMMEDIATE;
			(yyval.arg_value).at_expr = (yyvsp[0].expr_value);
			printf("argument with immediate addressing found\n");
			fflush(stdout);
		}
#line 1887 "pasm.tab.c"
		break;

	case 46: /* argument: '[' expr ']'  */
#line 103 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ABSOLUTE;
			(yyval.arg_value).at_expr = (yyvsp[-1].expr_value);
			printf("argument with absolute addressing found\n");
			fflush(stdout);
		}
#line 1893 "pasm.tab.c"
		break;

	case 47: /* argument: '[' expr '+' REG_X ']'  */
#line 104 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ABSOLUTE_X;
			(yyval.arg_value).at_expr = (yyvsp[-3].expr_value);
			printf("argument with absolute_X addressing found\n");
			fflush(stdout);
		}
#line 1899 "pasm.tab.c"
		break;

	case 48: /* argument: '[' expr '+' REG_Y ']'  */
#line 105 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ABSOLUTE_Y;
			(yyval.arg_value).at_expr = (yyvsp[-3].expr_value);
			printf("argument with absolute_Y addressing found\n");
			fflush(stdout);
		}
#line 1905 "pasm.tab.c"
		break;

	case 49: /* argument: ZP '[' expr ']'  */
#line 106 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ZEROPAGE;
			(yyval.arg_value).at_expr = (yyvsp[-1].expr_value);
			printf("argument with ZEROPAGE addressing found\n");
			fflush(stdout);
		}
#line 1911 "pasm.tab.c"
		break;

	case 50: /* argument: ZP '[' expr '+' REG_X ']'  */
#line 107 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ZEROPAGE_X;
			(yyval.arg_value).at_expr = (yyvsp[-3].expr_value);
			printf("argument with ZEROPAGE_X addressing found\n");
			fflush(stdout);
		}
#line 1917 "pasm.tab.c"
		break;

	case 51: /* argument: ZP '[' expr '+' REG_Y ']'  */
#line 108 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ZEROPAGE_Y;
			(yyval.arg_value).at_expr = (yyvsp[-3].expr_value);
			printf("argument with ZEROPAGE_Y addressing found\n");
			fflush(stdout);
		}
#line 1923 "pasm.tab.c"
		break;

	case 52: /* argument: '[' ZP '[' expr ']' ']'  */
#line 109 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_INDIRECT_ZP;
			(yyval.arg_value).at_expr = (yyvsp[-2].expr_value);
			printf("argument with INDIRECT_ZP addressing found\n");
			fflush(stdout);
		}
#line 1929 "pasm.tab.c"
		break;

	case 53: /* argument: '[' ZP '[' expr '+' REG_X ']' ']'  */
#line 110 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_INDIRECT_ZP_X;
			(yyval.arg_value).at_expr = (yyvsp[-4].expr_value);
			printf("argument with INDIRECT_ZP_X addressing found\n");
			fflush(stdout);
		}
#line 1935 "pasm.tab.c"
		break;

	case 54: /* argument: '[' ZP '[' expr ']' '+' REG_Y ']'  */
#line 111 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_INDIRECT_Y_ZP;
			(yyval.arg_value).at_expr = (yyvsp[-4].expr_value);
			printf("argument with INDIRECT_Y_ZP addressing found\n");
			fflush(stdout);
		}
#line 1941 "pasm.tab.c"
		break;

	case 55: /* argument: REG_A  */
#line 112 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_REG_A;
			(yyval.arg_value).at_expr = NULL;
			printf("argument REG_A found\n");
			fflush(stdout);
		}
#line 1947 "pasm.tab.c"
		break;

	case 56: /* argument: REG_X  */
#line 113 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_REG_X;
			(yyval.arg_value).at_expr = NULL;
			printf("argument REG_X found\n");
			fflush(stdout);
		}
#line 1953 "pasm.tab.c"
		break;

	case 57: /* argument: REG_Y  */
#line 114 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_REG_Y;
			(yyval.arg_value).at_expr = NULL;
			printf("argument REG_Y found\n");
			fflush(stdout);
		}
#line 1959 "pasm.tab.c"
		break;

	case 58: /* argument: REG_S  */
#line 115 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_REG_S;
			(yyval.arg_value).at_expr = NULL;
			printf("argument REG_S found\n");
			fflush(stdout);
		}
#line 1965 "pasm.tab.c"
		break;

	case 59: /* argument: REG_P  */
#line 116 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_REG_P;
			(yyval.arg_value).at_expr = NULL;
			printf("argument REG_P found\n");
			fflush(stdout);
		}
#line 1971 "pasm.tab.c"
		break;

	case 60: /* argument: CFLAG  */
#line 117 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_CFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_CFLAG found\n");
			fflush(stdout);
		}
#line 1977 "pasm.tab.c"
		break;

	case 61: /* argument: CFLAG '=' NUM  */
#line 118 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_CFLAG;
			(yyval.arg_value).at_expr = newexpr_num((yyvsp[0].numval), (yyloc));
			printf("argument AT_CFLAG found\n");
			fflush(stdout);
		}
#line 1983 "pasm.tab.c"
		break;

	case 62: /* argument: DFLAG  */
#line 119 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_DFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_DFLAG found\n");
			fflush(stdout);
		}
#line 1989 "pasm.tab.c"
		break;

	case 63: /* argument: IFLAG  */
#line 120 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_IFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_IFLAG found\n");
			fflush(stdout);
		}
#line 1995 "pasm.tab.c"
		break;

	case 64: /* argument: NFLAG  */
#line 121 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_NFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_NFLAG found\n");
			fflush(stdout);
		}
#line 2001 "pasm.tab.c"
		break;

	case 65: /* argument: NFLAG '=' NUM  */
#line 122 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_NFLAG;
			(yyval.arg_value).at_expr = newexpr_num((yyvsp[0].numval), (yyloc));
			printf("argument AT_NFLAG found\n");
			fflush(stdout);
		}
#line 2007 "pasm.tab.c"
		break;

	case 66: /* argument: VFLAG  */
#line 123 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_VFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_VFLAG found\n");
			fflush(stdout);
		}
#line 2013 "pasm.tab.c"
		break;

	case 67: /* argument: VFLAG '=' NUM  */
#line 124 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_VFLAG;
			(yyval.arg_value).at_expr = newexpr_num((yyvsp[0].numval), (yyloc));
			printf("argument AT_VFLAG found\n");
			fflush(stdout);
		}
#line 2019 "pasm.tab.c"
		break;

	case 68: /* argument: ZFLAG  */
#line 125 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ZFLAG;
			(yyval.arg_value).at_expr = NULL;
			printf("argument AT_ZFLAG found\n");
			fflush(stdout);
		}
#line 2025 "pasm.tab.c"
		break;

	case 69: /* argument: ZFLAG '=' NUM  */
#line 126 "pasm.y"
		{
			(yyval.arg_value).at_at = AT_ZFLAG;
			(yyval.arg_value).at_expr = newexpr_num((yyvsp[0].numval), (yyloc));
			printf("argument AT_ZFLAG found\n");
			fflush(stdout);
		}
#line 2031 "pasm.tab.c"
		break;

	case 70: /* expr: NUM  */
#line 129 "pasm.y"
		{
			(yyval.expr_value) = newexpr_num((yyvsp[0].numval), (yyloc));
			printf("expression with NUM found, value=%d\n", (yyvsp[0].numval));
			fflush(stdout);
		}
#line 2037 "pasm.tab.c"
		break;

	case 71: /* expr: IDENT  */
#line 130 "pasm.y"
		{
			(yyval.expr_value) = newexpr_ident((yyvsp[0].identval), (yyloc));
			printf("expression with IDENT found, value=%s\n", (yyvsp[0].identval));
			fflush(stdout);
		}
#line 2043 "pasm.tab.c"
		break;

	case 72: /* expr: expr '+' expr  */
#line 131 "pasm.y"
		{
			(yyval.expr_value) = newexpr_binop(ET_PLUS, (yyvsp[-2].expr_value), (yyvsp[0].expr_value), (yyloc));
			printf("expression with PLUS found\n");
			fflush(stdout);
		}
#line 2049 "pasm.tab.c"
		break;

	case 73: /* expr: '(' expr ')'  */
#line 132 "pasm.y"
		{
			(yyval.expr_value) = (yyvsp[-1].expr_value);
			printf("expression in parenthesis found\n");
			fflush(stdout);
		}
#line 2055 "pasm.tab.c"
		break;

	case 74: /* expr: expr '-' expr  */
#line 133 "pasm.y"
		{
			(yyval.expr_value) = newexpr_binop(ET_MINUS, (yyvsp[-2].expr_value), (yyvsp[0].expr_value), (yyloc));
			printf("expression with SUBTRACTION found\n");
			fflush(stdout);
		}
#line 2061 "pasm.tab.c"
		break;

	case 75: /* expr: expr '*' expr  */
#line 134 "pasm.y"
		{
			(yyval.expr_value) = newexpr_binop(ET_MULTIPLY, (yyvsp[-2].expr_value), (yyvsp[0].expr_value), (yyloc));
			printf("expression with MULTIPLICATION found\n");
			fflush(stdout);
		}
#line 2067 "pasm.tab.c"
		break;

	case 76: /* expr: expr '/' expr  */
#line 135 "pasm.y"
		{
			(yyval.expr_value) = newexpr_binop(ET_DIVIDE, (yyvsp[-2].expr_value), (yyvsp[0].expr_value), (yyloc));
			printf("expression with DIVISION found\n");
			fflush(stdout);
		}
#line 2073 "pasm.tab.c"
		break;


#line 2077 "pasm.tab.c"

	default: break;
	}
	/* User semantic actions sometimes alter yychar, and that requires
	   that yytoken be updated with the new translation.  We take the
	   approach of translating immediately before every use of yytoken.
	   One alternative is translating here after every semantic action,
	   but that translation would be missed if the semantic action invokes
	   YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
	   if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
	   incorrect destructor might then be invoked immediately.  In the
	   case of YYERROR or YYBACKUP, subsequent parser actions might lead
	   to an incorrect destructor call or verbose syntax error message
	   before the lookahead is translated.  */
	YY_SYMBOL_PRINT("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

	YYPOPSTACK(yylen);
	yylen = 0;

	*++yyvsp = yyval;
	*++yylsp = yyloc;

	/* Now 'shift' the result of the reduction.  Determine what state
	   that goes to, based on the state we popped back to and the rule
	   number reduced by.  */
	{
		const int yylhs = yyr1[yyn] - YYNTOKENS;
		const int yyi = yypgoto[yylhs] + *yyssp;
		yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
			           ? yytable[yyi]
			           : yydefgoto[yylhs]);
	}

	goto yynewstate;


	/*--------------------------------------.
	| yyerrlab -- here on detecting error.  |
	`--------------------------------------*/
yyerrlab:
	/* Make sure we have latest lookahead translation.  See comments at
	   user semantic actions for why this is necessary.  */
	yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE(yychar);
	/* If not already recovering from an error, report this error.  */
	if (!yyerrstatus)
	{
		++yynerrs;
		{
			yypcontext_t yyctx
				= {yyssp, yytoken, &yylloc};
			const char* yymsgp = YY_("syntax error");
			int yysyntax_error_status;
			yysyntax_error_status = yysyntax_error(&yymsg_alloc, &yymsg, &yyctx);
			if (yysyntax_error_status == 0)
				yymsgp = yymsg;
			else if (yysyntax_error_status == -1)
			{
				if (yymsg != yymsgbuf)
					YYSTACK_FREE(yymsg);
				yymsg = YY_CAST(char *,
				                YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
				if (yymsg)
				{
					yysyntax_error_status
						= yysyntax_error(&yymsg_alloc, &yymsg, &yyctx);
					yymsgp = yymsg;
				}
				else
				{
					yymsg = yymsgbuf;
					yymsg_alloc = sizeof yymsgbuf;
					yysyntax_error_status = YYENOMEM;
				}
			}
			yyerror(yymsgp);
			if (yysyntax_error_status == YYENOMEM)
				YYNOMEM;
		}
	}

	yyerror_range[1] = yylloc;
	if (yyerrstatus == 3)
	{
		/* If just tried and failed to reuse lookahead token after an
		   error, discard it.  */

		if (yychar <= YYEOF)
		{
			/* Return failure if at end of input.  */
			if (yychar == YYEOF)
				YYABORT;
		}
		else
		{
			yydestruct("Error: discarding",
			           yytoken, &yylval, &yylloc);
			yychar = YYEMPTY;
		}
	}

	/* Else will try to reuse lookahead token after shifting the error
	   token.  */
	goto yyerrlab1;


	/*---------------------------------------------------.
	| yyerrorlab -- error raised explicitly by YYERROR.  |
	`---------------------------------------------------*/
yyerrorlab:
	/* Pacify compilers when the user code never invokes YYERROR and the
	   label yyerrorlab therefore never appears in user code.  */
	if (0)
		YYERROR;
	++yynerrs;

	/* Do not reclaim the symbols of the rule whose action triggered
	   this YYERROR.  */
	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);
	yystate = *yyssp;
	goto yyerrlab1;


	/*-------------------------------------------------------------.
	| yyerrlab1 -- common code for both syntax error and YYERROR.  |
	`-------------------------------------------------------------*/
yyerrlab1:
	yyerrstatus = 3; /* Each real token shifted decrements this.  */

	/* Pop stack until we find a state that shifts the error token.  */
	for (;;)
	{
		yyn = yypact[yystate];
		if (!yypact_value_is_default(yyn))
		{
			yyn += YYSYMBOL_YYerror;
			if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
			{
				yyn = yytable[yyn];
				if (0 < yyn)
					break;
			}
		}

		/* Pop the current state because it cannot handle the error token.  */
		if (yyssp == yyss)
			YYABORT;

		yyerror_range[1] = *yylsp;
		yydestruct("Error: popping",
		           YY_ACCESSING_SYMBOL(yystate), yyvsp, yylsp);
		YYPOPSTACK(1);
		yystate = *yyssp;
		YY_STACK_PRINT(yyss, yyssp);
	}

	YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
	*++yyvsp = yylval;
	YY_IGNORE_MAYBE_UNINITIALIZED_END

	yyerror_range[2] = yylloc;
	++yylsp;
	YYLLOC_DEFAULT(*yylsp, yyerror_range, 2);

	/* Shift the error token.  */
	YY_SYMBOL_PRINT("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

	yystate = yyn;
	goto yynewstate;


	/*-------------------------------------.
	| yyacceptlab -- YYACCEPT comes here.  |
	`-------------------------------------*/
yyacceptlab:
	yyresult = 0;
	goto yyreturnlab;


	/*-----------------------------------.
	| yyabortlab -- YYABORT comes here.  |
	`-----------------------------------*/
yyabortlab:
	yyresult = 1;
	goto yyreturnlab;


	/*-----------------------------------------------------------.
	| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
	`-----------------------------------------------------------*/
yyexhaustedlab:
	yyerror(YY_("memory exhausted"));
	yyresult = 2;


	/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
	if (yychar != YYEMPTY)
	{
		/* Make sure we have latest lookahead translation.  See comments at
		   user semantic actions for why this is necessary.  */
		yytoken = YYTRANSLATE(yychar);
		yydestruct("Cleanup: discarding lookahead",
		           yytoken, &yylval, &yylloc);
	}
	/* Do not reclaim the symbols of the rule whose action triggered
	   this YYABORT or YYACCEPT.  */
	YYPOPSTACK(yylen);
	YY_STACK_PRINT(yyss, yyssp);
	while (yyssp != yyss)
	{
		yydestruct("Cleanup: popping",
		           YY_ACCESSING_SYMBOL(+*yyssp), yyvsp, yylsp);
		YYPOPSTACK(1);
	}
#ifndef yyoverflow
	if (yyss != yyssa)
		YYSTACK_FREE(yyss);
#endif
	if (yymsg != yymsgbuf)
		YYSTACK_FREE(yymsg);
	return yyresult;
}

#line 138 "pasm.y"


void yyerror(const char* s)
{
	fprintf(stderr, "%s\n", s);
	fprintf(stderr, "location: %d.%d-%d.%d\n",
	        yylloc.first_line, yylloc.first_column,
	        yylloc.last_line, yylloc.last_column);
	fflush(stderr);
}
