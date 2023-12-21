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
#include "pasm.tab.h"

YYLTYPE yylloc;
int yyerrstatus = 0;

void yyerror (char const *s);
extern int yylex (void);
extern astroot_t astroot;

expr_node_t* num_expression(int num);
expr_node_t* ident_expression(char* ident);
expr_node_t* binary_expression(expr_type_t et, expr_node_t* left, expr_node_t* right);

argument_node_t* immediate_argument(expr_node_t* expr);
argument_node_t* absolute_argument(expr_node_t* expr);
argument_node_t* register_argument(argument_type_t at);

#line 92 "pasm.tab.c"

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
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '*'  */
  YYSYMBOL_4_ = 4,                         /* '/'  */
  YYSYMBOL_5_ = 5,                         /* '%'  */
  YYSYMBOL_6_ = 6,                         /* '|'  */
  YYSYMBOL_7_ = 7,                         /* '&'  */
  YYSYMBOL_8_ = 8,                         /* '('  */
  YYSYMBOL_9_ = 9,                         /* ')'  */
  YYSYMBOL_10_ = 10,                       /* '+'  */
  YYSYMBOL_11_ = 11,                       /* '-'  */
  YYSYMBOL_NUM = 12,                       /* NUM  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_REG_Y = 14,                     /* REG_Y  */
  YYSYMBOL_REG_S = 15,                     /* REG_S  */
  YYSYMBOL_REG_X = 16,                     /* REG_X  */
  YYSYMBOL_REG_P = 17,                     /* REG_P  */
  YYSYMBOL_REG_A = 18,                     /* REG_A  */
  YYSYMBOL_LF = 19,                        /* LF  */
  YYSYMBOL_CFLAG = 20,                     /* CFLAG  */
  YYSYMBOL_DFLAG = 21,                     /* DFLAG  */
  YYSYMBOL_IFLAG = 22,                     /* IFLAG  */
  YYSYMBOL_NFLAG = 23,                     /* NFLAG  */
  YYSYMBOL_VFLAG = 24,                     /* VFLAG  */
  YYSYMBOL_ZFLAG = 25,                     /* ZFLAG  */
  YYSYMBOL_ZP = 26,                        /* ZP  */
  YYSYMBOL_OTHER = 27,                     /* OTHER  */
  YYSYMBOL_MOV = 28,                       /* MOV  */
  YYSYMBOL_JMP = 29,                       /* JMP  */
  YYSYMBOL_NOP = 30,                       /* NOP  */
  YYSYMBOL_BRK = 31,                       /* BRK  */
  YYSYMBOL_ADDC = 32,                      /* ADDC  */
  YYSYMBOL_ADD = 33,                       /* ADD  */
  YYSYMBOL_ASL = 34,                       /* ASL  */
  YYSYMBOL_BR = 35,                        /* BR  */
  YYSYMBOL_CALL = 36,                      /* CALL  */
  YYSYMBOL_DEC = 37,                       /* DEC  */
  YYSYMBOL_INC = 38,                       /* INC  */
  YYSYMBOL_OR = 39,                        /* OR  */
  YYSYMBOL_PULL = 40,                      /* PULL  */
  YYSYMBOL_PUSH = 41,                      /* PUSH  */
  YYSYMBOL_RET = 42,                       /* RET  */
  YYSYMBOL_RETI = 43,                      /* RETI  */
  YYSYMBOL_ROL = 44,                       /* ROL  */
  YYSYMBOL_ROR = 45,                       /* ROR  */
  YYSYMBOL_SET = 46,                       /* SET  */
  YYSYMBOL_STOP = 47,                      /* STOP  */
  YYSYMBOL_CLR = 48,                       /* CLR  */
  YYSYMBOL_SUBC = 49,                      /* SUBC  */
  YYSYMBOL_TRB = 50,                       /* TRB  */
  YYSYMBOL_TSB = 51,                       /* TSB  */
  YYSYMBOL_XOR = 52,                       /* XOR  */
  YYSYMBOL_WAIT = 53,                      /* WAIT  */
  YYSYMBOL_DB = 54,                        /* DB  */
  YYSYMBOL_DW = 55,                        /* DW  */
  YYSYMBOL_SECTION = 56,                   /* SECTION  */
  YYSYMBOL_ORIGIN = 57,                    /* ORIGIN  */
  YYSYMBOL_AND = 58,                       /* AND  */
  YYSYMBOL_BIT = 59,                       /* BIT  */
  YYSYMBOL_LSR = 60,                       /* LSR  */
  YYSYMBOL_CMP = 61,                       /* CMP  */
  YYSYMBOL_62_ = 62,                       /* ','  */
  YYSYMBOL_63_ = 63,                       /* ':'  */
  YYSYMBOL_64_ = 64,                       /* '='  */
  YYSYMBOL_65_ = 65,                       /* '['  */
  YYSYMBOL_66_ = 66,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_asmfile = 68,                   /* asmfile  */
  YYSYMBOL_lines = 69,                     /* lines  */
  YYSYMBOL_line = 70,                      /* line  */
  YYSYMBOL_dbargs = 71,                    /* dbargs  */
  YYSYMBOL_opcode = 72,                    /* opcode  */
  YYSYMBOL_argument = 73,                  /* argument  */
  YYSYMBOL_expr = 74                       /* expr  */
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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     5,     7,     2,
       8,     9,     3,    10,    62,    11,     2,     4,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
       2,    64,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     6,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    84,
      85,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     117,   124,   130,   136,   143,   149,   155,   161,   167,   173,
     180,   186,   192,   198,   204,   210,   216,   222,   228,   234,
     240,   246,   252,   258,   264,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "'*'", "'/'", "'%'", "'|'",
  "'&'", "'('", "')'", "'+'", "'-'", "NUM", "IDENT", "REG_Y", "REG_S",
  "REG_X", "REG_P", "REG_A", "LF", "CFLAG", "DFLAG", "IFLAG", "NFLAG",
  "VFLAG", "ZFLAG", "ZP", "OTHER", "MOV", "JMP", "NOP", "BRK", "ADDC",
  "ADD", "ASL", "BR", "CALL", "DEC", "INC", "OR", "PULL", "PUSH", "RET",
  "RETI", "ROL", "ROR", "SET", "STOP", "CLR", "SUBC", "TRB", "TSB", "XOR",
  "WAIT", "DB", "DW", "SECTION", "ORIGIN", "AND", "BIT", "LSR", "CMP",
  "','", "':'", "'='", "'['", "']'", "$accept", "asmfile", "lines", "line",
  "dbargs", "opcode", "argument", "expr", YY_NULLPTR
  };
  return yy_sname[yysymbol];
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
     -55,    22,   145,   -55,   -54,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   142,   142,    17,   -55,   -55,   -55,   -55,   -55,    40,
     183,   142,   142,   -55,   -55,   -18,   251,    23,    -7,   -55,
     -55,   -55,   -55,   -55,   -55,     4,   -55,   -55,    11,    13,
      16,    19,    70,    24,   251,   -55,   142,   142,    94,   141,
     242,   -55,   142,   142,   142,   142,   142,   142,   142,   142,
     -55,    79,    82,    83,    88,    91,   142,    39,     1,   -55,
     113,    26,    27,   -55,    30,   -55,   -55,   251,    60,    60,
      60,    60,    60,   -55,   -55,   104,   -55,   -55,   -55,   -55,
      10,   142,    85,   -55,   105,   -55,   -55,   -55,   113,   -55,
     153,   -55,    21,    66,    74,   -55,   122,    76,    77,   252,
       8,   -55,   -55,   -55,   -55,   -55,    87,   135,   -55,    96,
      97,   -55,   -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     9,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    40,    41,    42,    43,
      44,     0,     0,     0,    46,    47,    48,    49,     3,     0,
       0,     0,     0,    75,    76,     0,    19,     0,     0,    62,
      63,    61,    64,    60,     7,    65,    66,    67,    68,    69,
      70,     0,     0,     0,    50,     8,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     0,     0,    15,     0,    12,    84,    20,    80,    79,
      83,    81,    82,    77,    78,     0,    71,    72,    73,    74,
       0,     0,     0,    51,     0,    16,    18,    13,     0,    10,
       0,    54,     0,     0,     0,     6,     0,     0,     0,     0,
       0,    53,    52,    14,    56,    55,     0,     0,    57,     0,
       0,    58,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   -55,    90,   128,   -49,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    38,    45,    39,    63,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    71,    69,    70,    73,    74,    75,    76,    77,    40,
      41,   112,    79,    73,    74,    75,    76,    77,   137,    94,
     120,    79,     3,    88,    73,    74,    75,    76,    77,    64,
      48,   129,    79,    97,    98,    99,   100,   101,   102,   103,
     104,   114,    80,    89,    72,   115,   116,   110,    42,   117,
      81,    64,    43,    44,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,   113,    82,   126,
      78,    79,   122,   103,   138,    83,   121,    84,    42,    64,
      85,   103,    43,    44,    86,    72,    90,   130,    72,    72,
     103,   105,   118,    42,   106,   107,    87,    43,    44,   123,
     108,   124,    42,   109,   111,    62,    43,    44,    49,    50,
      51,    52,    53,    93,    55,    56,    57,    58,    59,    60,
      61,    42,    47,   119,   125,    43,    44,    49,    50,    51,
      52,    53,   131,    55,    56,    57,    58,    59,    60,    61,
     132,   133,   134,   135,    73,    74,    75,    76,    77,   140,
      42,    78,    79,   139,    43,    44,    91,    92,     4,    62,
      95,    42,   141,   142,     5,    43,    44,   127,    68,   128,
       0,     0,     0,     6,     7,     8,     9,    10,    62,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    65,    34,    35,    36,    37,     0,     0,     0,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    66,    67,     0,
       0,    34,    35,    36,    37,    73,    74,    75,    76,    77,
       0,    96,    78,    79,    73,    74,    75,    76,    77,     0,
      42,    78,    79,     0,    43,    44,     0,     0,   136
};

static const yytype_int16 yycheck[] =
{
      39,    19,    41,    42,     3,     4,     5,     6,     7,    63,
      64,    10,    11,     3,     4,     5,     6,     7,    10,    68,
      10,    11,     0,    62,     3,     4,     5,     6,     7,    68,
      13,    10,    11,    72,    73,    74,    75,    76,    77,    78,
      79,    90,    19,    19,    62,    19,    19,    86,     8,    19,
      57,    90,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    66,    64,   118,
      10,    11,   111,   112,    66,    64,    66,    64,     8,   118,
      64,   120,    12,    13,    65,    62,    62,    66,    62,    62,
     129,    12,    62,     8,    12,    12,    26,    12,    13,    14,
      12,    16,     8,    12,    65,    65,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     8,    32,    19,    19,    12,    13,    14,    15,    16,
      17,    18,    66,    20,    21,    22,    23,    24,    25,    26,
      66,    19,    66,    66,     3,     4,     5,     6,     7,    14,
       8,    10,    11,    66,    12,    13,    66,    67,    13,    65,
      19,     8,    66,    66,    19,    12,    13,    14,    40,    16,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    65,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    19,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    59,    60,    61,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,     3,     4,     5,     6,     7,    -1,
       8,    10,    11,    -1,    12,    13,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,    13,    19,    28,    29,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,    70,    72,
      63,    64,     8,    12,    13,    71,    74,    71,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    65,    73,    74,    19,    54,    55,    72,    74,
      74,    19,    62,     3,     4,     5,     6,     7,    10,    11,
      19,    57,    64,    64,    64,    64,    65,    26,    74,    19,
      62,    71,    71,    19,    73,    19,     9,    74,    74,    74,
      74,    74,    74,    74,    74,    12,    12,    12,    12,    12,
      74,    65,    10,    66,    73,    19,    19,    19,    62,    19,
      10,    66,    74,    14,    16,    19,    73,    14,    16,    10,
      66,    66,    66,    19,    66,    66,    16,    10,    66,    66,
      14,    66,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     5,     2,     3,     1,
       5,     3,     4,     5,     7,     4,     5,     3,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     5,     4,     6,     6,     6,     8,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3
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
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
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
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
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
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
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
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
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
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
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
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

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
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
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
  goto yyreduce;


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
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* asmfile: lines  */
#line 64 "pasm.y"
                { astroot = (yyvsp[0].linesnode); printf("complete file found\n"); }
#line 1604 "pasm.tab.c"
    break;

  case 3: /* lines: lines line  */
#line 66 "pasm.y"
                  { (yyval.linesnode) = addline((yyvsp[-1].linesnode), (yyvsp[0].linenode)); printf("Lines found\n"); }
#line 1610 "pasm.tab.c"
    break;

  case 4: /* lines: %empty  */
#line 67 "pasm.y"
             { (yyval.linesnode) = newlines(); printf("Found nothing\n"); }
#line 1616 "pasm.tab.c"
    break;

  case 5: /* line: opcode argument LF  */
#line 69 "pasm.y"
                         { (yyval.linenode) = newline_instruction((yyvsp[-2].opcode_value), (yyvsp[-1].argument_value)->at, AT_NONE, (yyvsp[-1].argument_value)->expr, NULL, (yyloc)); }
#line 1622 "pasm.tab.c"
    break;

  case 6: /* line: opcode argument ',' argument LF  */
#line 70 "pasm.y"
                                      { (yyval.linenode) = newline_instruction((yyvsp[-4].opcode_value), (yyvsp[-3].argument_value)->at, (yyvsp[-1].argument_value)->at, (yyvsp[-3].argument_value)->expr, (yyvsp[-1].argument_value)->expr,(yyloc)); printf("Line with instruction found\n"); }
#line 1628 "pasm.tab.c"
    break;

  case 7: /* line: opcode LF  */
#line 71 "pasm.y"
                { (yyval.linenode) = newline_instruction((yyvsp[-1].opcode_value), AT_NONE, AT_NONE, NULL, NULL, (yyloc)); printf("Line with instruction found\n"); }
#line 1634 "pasm.tab.c"
    break;

  case 8: /* line: IDENT ':' LF  */
#line 72 "pasm.y"
                   { (yyval.linenode) = newline_label((yyvsp[-2].identval), (yyloc)); printf("Line with label found, value = %s\n",(yyvsp[-2].identval)); }
#line 1640 "pasm.tab.c"
    break;

  case 9: /* line: LF  */
#line 73 "pasm.y"
         { (yyval.linenode) = NULL; printf("Empty line found\n"); }
#line 1646 "pasm.tab.c"
    break;

  case 10: /* line: SECTION IDENT ORIGIN NUM LF  */
#line 74 "pasm.y"
                                  { (yyval.linenode) = newline_section((yyvsp[-3].identval),(yyvsp[-1].numval), (yyloc)); printf("section found\n"); }
#line 1652 "pasm.tab.c"
    break;

  case 11: /* line: DB dbargs LF  */
#line 75 "pasm.y"
                   { (yyval.linenode) = newline_db ((yyvsp[-1].elist),(yyloc)); printf("DB line found\n"); }
#line 1658 "pasm.tab.c"
    break;

  case 12: /* line: IDENT '=' expr LF  */
#line 76 "pasm.y"
                        { (yyval.linenode) = newline_definition((yyvsp[-3].identval),(yyvsp[-1].expr_value), (yyloc)); printf("Definition found\n"); }
#line 1664 "pasm.tab.c"
    break;

  case 13: /* line: IDENT ':' opcode argument LF  */
#line 77 "pasm.y"
                                   { (yyval.linenode) = newline_label_instruction((yyvsp[-4].identval),(yyvsp[-2].opcode_value), (yyvsp[-1].argument_value)->at, AT_NONE, (yyvsp[-1].argument_value)->expr,NULL, (yyloc)); printf("Line with label and instruction with one arg found\n"); }
#line 1670 "pasm.tab.c"
    break;

  case 14: /* line: IDENT ':' opcode argument ',' argument LF  */
#line 78 "pasm.y"
                                                { (yyval.linenode) = newline_label_instruction((yyvsp[-6].identval),(yyvsp[-4].opcode_value), (yyvsp[-3].argument_value)->at,(yyvsp[-1].argument_value)->at, (yyvsp[-3].argument_value)->expr,(yyvsp[-1].argument_value)->expr, (yyloc)); printf("Line with label and instruction with 2 arg found\n"); }
#line 1676 "pasm.tab.c"
    break;

  case 15: /* line: IDENT ':' opcode LF  */
#line 79 "pasm.y"
                          { (yyval.linenode) = newline_label_instruction((yyvsp[-3].identval),(yyvsp[-1].opcode_value), AT_NONE, AT_NONE, NULL,NULL, (yyloc)); printf("Line with label and instruction with 0 arg found\n"); }
#line 1682 "pasm.tab.c"
    break;

  case 16: /* line: IDENT ':' DB dbargs LF  */
#line 80 "pasm.y"
                             { (yyval.linenode) = newline_label_db((yyvsp[-4].identval),(yyvsp[-1].elist),(yyloc)); printf("DB line with label found\n"); }
#line 1688 "pasm.tab.c"
    break;

  case 17: /* line: DW dbargs LF  */
#line 81 "pasm.y"
                   { (yyval.linenode) = newline_dw ((yyvsp[-1].elist),(yyloc)); printf("DW line found\n"); }
#line 1694 "pasm.tab.c"
    break;

  case 18: /* line: IDENT ':' DW dbargs LF  */
#line 82 "pasm.y"
                             { (yyval.linenode) = newline_label_dw((yyvsp[-4].identval),(yyvsp[-1].elist),(yyloc)); printf("Dw line with label found\n"); }
#line 1700 "pasm.tab.c"
    break;

  case 19: /* dbargs: expr  */
#line 84 "pasm.y"
              {(yyval.elist) = new_dbarg ((yyvsp[0].expr_value)); printf("dbargs found\n"); }
#line 1706 "pasm.tab.c"
    break;

  case 20: /* dbargs: dbargs ',' expr  */
#line 85 "pasm.y"
                         {(yyval.elist) = dbarg_append ((yyvsp[-2].elist),(yyvsp[0].expr_value)); printf("dbargs 2 found\n"); }
#line 1712 "pasm.tab.c"
    break;

  case 21: /* opcode: MOV  */
#line 87 "pasm.y"
            { (yyval.opcode_value) = OP_MOV; }
#line 1718 "pasm.tab.c"
    break;

  case 22: /* opcode: JMP  */
#line 88 "pasm.y"
           { (yyval.opcode_value) = OP_JMP; }
#line 1724 "pasm.tab.c"
    break;

  case 23: /* opcode: NOP  */
#line 89 "pasm.y"
           { (yyval.opcode_value) = OP_NOP; }
#line 1730 "pasm.tab.c"
    break;

  case 24: /* opcode: BRK  */
#line 90 "pasm.y"
           { (yyval.opcode_value) = OP_BRK; }
#line 1736 "pasm.tab.c"
    break;

  case 25: /* opcode: ADDC  */
#line 91 "pasm.y"
            { (yyval.opcode_value) = OP_ADDC; }
#line 1742 "pasm.tab.c"
    break;

  case 26: /* opcode: ASL  */
#line 92 "pasm.y"
           { (yyval.opcode_value) = OP_ASL; }
#line 1748 "pasm.tab.c"
    break;

  case 27: /* opcode: BR  */
#line 93 "pasm.y"
          { (yyval.opcode_value) = OP_BR; }
#line 1754 "pasm.tab.c"
    break;

  case 28: /* opcode: CALL  */
#line 94 "pasm.y"
            { (yyval.opcode_value) = OP_CALL; }
#line 1760 "pasm.tab.c"
    break;

  case 29: /* opcode: DEC  */
#line 95 "pasm.y"
           { (yyval.opcode_value) = OP_DEC; }
#line 1766 "pasm.tab.c"
    break;

  case 30: /* opcode: INC  */
#line 96 "pasm.y"
           { (yyval.opcode_value) = OP_INC; }
#line 1772 "pasm.tab.c"
    break;

  case 31: /* opcode: OR  */
#line 97 "pasm.y"
          { (yyval.opcode_value) = OP_OR; }
#line 1778 "pasm.tab.c"
    break;

  case 32: /* opcode: PULL  */
#line 98 "pasm.y"
            { (yyval.opcode_value) = OP_PULL; }
#line 1784 "pasm.tab.c"
    break;

  case 33: /* opcode: PUSH  */
#line 99 "pasm.y"
            { (yyval.opcode_value) = OP_PUSH; }
#line 1790 "pasm.tab.c"
    break;

  case 34: /* opcode: RET  */
#line 100 "pasm.y"
           { (yyval.opcode_value) = OP_RET; }
#line 1796 "pasm.tab.c"
    break;

  case 35: /* opcode: RETI  */
#line 101 "pasm.y"
            { (yyval.opcode_value) = OP_RETI; }
#line 1802 "pasm.tab.c"
    break;

  case 36: /* opcode: ROL  */
#line 102 "pasm.y"
           { (yyval.opcode_value) = OP_ROL; }
#line 1808 "pasm.tab.c"
    break;

  case 37: /* opcode: ROR  */
#line 103 "pasm.y"
           { (yyval.opcode_value) = OP_ROR; }
#line 1814 "pasm.tab.c"
    break;

  case 38: /* opcode: SET  */
#line 104 "pasm.y"
           { (yyval.opcode_value) = OP_SET; }
#line 1820 "pasm.tab.c"
    break;

  case 39: /* opcode: STOP  */
#line 105 "pasm.y"
            { (yyval.opcode_value) = OP_STOP; }
#line 1826 "pasm.tab.c"
    break;

  case 40: /* opcode: SUBC  */
#line 106 "pasm.y"
            { (yyval.opcode_value) = OP_SUBC; }
#line 1832 "pasm.tab.c"
    break;

  case 41: /* opcode: TRB  */
#line 107 "pasm.y"
           { (yyval.opcode_value) = OP_TRB; }
#line 1838 "pasm.tab.c"
    break;

  case 42: /* opcode: TSB  */
#line 108 "pasm.y"
           { (yyval.opcode_value) = OP_TSB; }
#line 1844 "pasm.tab.c"
    break;

  case 43: /* opcode: XOR  */
#line 109 "pasm.y"
           { (yyval.opcode_value) = OP_XOR; }
#line 1850 "pasm.tab.c"
    break;

  case 44: /* opcode: WAIT  */
#line 110 "pasm.y"
            { (yyval.opcode_value) = OP_WAIT; }
#line 1856 "pasm.tab.c"
    break;

  case 45: /* opcode: CLR  */
#line 111 "pasm.y"
           { (yyval.opcode_value) = OP_CLR; }
#line 1862 "pasm.tab.c"
    break;

  case 46: /* opcode: AND  */
#line 112 "pasm.y"
           { (yyval.opcode_value) = OP_AND; }
#line 1868 "pasm.tab.c"
    break;

  case 47: /* opcode: BIT  */
#line 113 "pasm.y"
           { (yyval.opcode_value) = OP_BIT; }
#line 1874 "pasm.tab.c"
    break;

  case 48: /* opcode: LSR  */
#line 114 "pasm.y"
           { (yyval.opcode_value) = OP_LSR; }
#line 1880 "pasm.tab.c"
    break;

  case 49: /* opcode: CMP  */
#line 115 "pasm.y"
           { (yyval.opcode_value) = OP_CMP; }
#line 1886 "pasm.tab.c"
    break;

  case 50: /* argument: expr  */
#line 117 "pasm.y"
               {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_IMMEDIATE;
    (yyval.argument_value)->expr = (yyvsp[0].expr_value);
    printf("Argument with immediate addressing found\n");
}
#line 1897 "pasm.tab.c"
    break;

  case 51: /* argument: '[' expr ']'  */
#line 124 "pasm.y"
               {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ABSOLUTE;
    (yyval.argument_value)->expr = (yyvsp[-1].expr_value);
    printf("Argument with absolute addressing found\n");
}
#line 1908 "pasm.tab.c"
    break;

  case 52: /* argument: '[' expr '+' REG_X ']'  */
#line 130 "pasm.y"
                         {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ABSOLUTE_X;
    (yyval.argument_value)->expr = (yyvsp[-3].expr_value);
    printf("Argument with absolute x addressing found\n");
}
#line 1919 "pasm.tab.c"
    break;

  case 53: /* argument: '[' expr '+' REG_Y ']'  */
#line 136 "pasm.y"
                         {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ABSOLUTE_Y;
    (yyval.argument_value)->expr = (yyvsp[-3].expr_value);
    printf("Argument with absolute y addressing found\n");
}
#line 1930 "pasm.tab.c"
    break;

  case 54: /* argument: ZP '[' expr ']'  */
#line 143 "pasm.y"
                  {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ZEROPAGE;
    (yyval.argument_value)->expr = (yyvsp[-1].expr_value);
    printf("Argument with ZEROPAGE found\n");
}
#line 1941 "pasm.tab.c"
    break;

  case 55: /* argument: ZP '[' expr '+' REG_X ']'  */
#line 149 "pasm.y"
                            {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ZEROPAGE_X;
    (yyval.argument_value)->expr = (yyvsp[-3].expr_value);
    printf("Argument with ZEROPAGE_X found\n");
}
#line 1952 "pasm.tab.c"
    break;

  case 56: /* argument: ZP '[' expr '+' REG_Y ']'  */
#line 155 "pasm.y"
                            {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ZEROPAGE_Y;
    (yyval.argument_value)->expr = (yyvsp[-3].expr_value);
    printf("Argument with ZEROPAGE_Y found\n");
}
#line 1963 "pasm.tab.c"
    break;

  case 57: /* argument: '[' ZP '[' expr ']' ']'  */
#line 161 "pasm.y"
                          {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_INDIRECT_ZP;
    (yyval.argument_value)->expr = (yyvsp[-2].expr_value);
    printf("Argument with INDIRECT_ZP found\n");
}
#line 1974 "pasm.tab.c"
    break;

  case 58: /* argument: '[' ZP '[' expr '+' REG_X ']' ']'  */
#line 167 "pasm.y"
                                    {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_INDIRECT_ZP_X;
    (yyval.argument_value)->expr = (yyvsp[-4].expr_value);
    printf("Argument with INDIRECT_ZP_X found\n");
}
#line 1985 "pasm.tab.c"
    break;

  case 59: /* argument: '[' ZP '[' expr ']' '+' REG_Y ']'  */
#line 173 "pasm.y"
                                    {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_INDIRECT_Y_ZP;
    (yyval.argument_value)->expr = (yyvsp[-4].expr_value);
    printf("Argument with INDIRECT_Y_ZP found\n");
}
#line 1996 "pasm.tab.c"
    break;

  case 60: /* argument: REG_A  */
#line 180 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_REG_A;
    (yyval.argument_value)->expr = NULL;
    printf("Argument REG_A found\n");
}
#line 2007 "pasm.tab.c"
    break;

  case 61: /* argument: REG_X  */
#line 186 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_REG_X;
    (yyval.argument_value)->expr = NULL;
    printf("Argument REG_X found\n");
}
#line 2018 "pasm.tab.c"
    break;

  case 62: /* argument: REG_Y  */
#line 192 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_REG_Y;
    (yyval.argument_value)->expr = NULL;
    printf("Argument REG_Y found\n");
}
#line 2029 "pasm.tab.c"
    break;

  case 63: /* argument: REG_S  */
#line 198 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_REG_S;
    (yyval.argument_value)->expr = NULL;
    printf("Argument REG_S found\n");
}
#line 2040 "pasm.tab.c"
    break;

  case 64: /* argument: REG_P  */
#line 204 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_REG_P;
    (yyval.argument_value)->expr = NULL;
    printf("Argument REG_P found\n");
}
#line 2051 "pasm.tab.c"
    break;

  case 65: /* argument: CFLAG  */
#line 210 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_CFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument CFLAG found\n");
}
#line 2062 "pasm.tab.c"
    break;

  case 66: /* argument: DFLAG  */
#line 216 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_DFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument DFLAG found\n");
}
#line 2073 "pasm.tab.c"
    break;

  case 67: /* argument: IFLAG  */
#line 222 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_IFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument IFLAG found\n");
}
#line 2084 "pasm.tab.c"
    break;

  case 68: /* argument: NFLAG  */
#line 228 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_NFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument NFLAG found\n");
}
#line 2095 "pasm.tab.c"
    break;

  case 69: /* argument: VFLAG  */
#line 234 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_VFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument VFLAG found\n");
}
#line 2106 "pasm.tab.c"
    break;

  case 70: /* argument: ZFLAG  */
#line 240 "pasm.y"
        {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ZFLAG;
    (yyval.argument_value)->expr = NULL;
    printf("Argument ZFLAG found\n");
}
#line 2117 "pasm.tab.c"
    break;

  case 71: /* argument: CFLAG '=' NUM  */
#line 246 "pasm.y"
                {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_CFLAG;
    (yyval.argument_value)->expr = num_expression((yyvsp[0].numval));
    printf("Argument CFLAG found\n");
}
#line 2128 "pasm.tab.c"
    break;

  case 72: /* argument: NFLAG '=' NUM  */
#line 252 "pasm.y"
                {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_NFLAG;
    (yyval.argument_value)->expr = num_expression((yyvsp[0].numval));
    printf("Argument NFLAG found\n");
}
#line 2139 "pasm.tab.c"
    break;

  case 73: /* argument: VFLAG '=' NUM  */
#line 258 "pasm.y"
                {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_VFLAG;
    (yyval.argument_value)->expr = num_expression((yyvsp[0].numval));
    printf("Argument VFLAG found\n");
}
#line 2150 "pasm.tab.c"
    break;

  case 74: /* argument: ZFLAG '=' NUM  */
#line 264 "pasm.y"
                {
    (yyval.argument_value) = (argument_node_t*)malloc(sizeof(argument_node_t));
    (yyval.argument_value)->at = AT_ZFLAG;
    (yyval.argument_value)->expr = num_expression((yyvsp[0].numval));
    printf("Argument ZFLAG found\n");
}
#line 2161 "pasm.tab.c"
    break;

  case 75: /* expr: NUM  */
#line 271 "pasm.y"
          {(yyval.expr_value) = num_expression((yyvsp[0].numval)); }
#line 2167 "pasm.tab.c"
    break;

  case 76: /* expr: IDENT  */
#line 272 "pasm.y"
            {(yyval.expr_value) = ident_expression((yyvsp[0].identval)); }
#line 2173 "pasm.tab.c"
    break;

  case 77: /* expr: expr '+' expr  */
#line 273 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_PLUS, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2179 "pasm.tab.c"
    break;

  case 78: /* expr: expr '-' expr  */
#line 274 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_MINUS, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2185 "pasm.tab.c"
    break;

  case 79: /* expr: expr '/' expr  */
#line 275 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_DIVISON, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2191 "pasm.tab.c"
    break;

  case 80: /* expr: expr '*' expr  */
#line 276 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_TIMES, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2197 "pasm.tab.c"
    break;

  case 81: /* expr: expr '|' expr  */
#line 277 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_OR, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2203 "pasm.tab.c"
    break;

  case 82: /* expr: expr '&' expr  */
#line 278 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_AND, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2209 "pasm.tab.c"
    break;

  case 83: /* expr: expr '%' expr  */
#line 279 "pasm.y"
                    {(yyval.expr_value) = binary_expression(ET_MODULO, (yyvsp[-2].expr_value), (yyvsp[0].expr_value)); }
#line 2215 "pasm.tab.c"
    break;

  case 84: /* expr: '(' expr ')'  */
#line 280 "pasm.y"
                   {(yyval.expr_value) = (yyvsp[-1].expr_value); }
#line 2221 "pasm.tab.c"
    break;


#line 2225 "pasm.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
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
          yydestruct ("Error: discarding",
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
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 282 "pasm.y"


void yyerror(char const *s)
{
    fprintf(stderr, "%s\n", s);
    fprintf(stderr, "location: %d.%d-%d.%d\n",
        yylloc.first_line, yylloc.first_column,
        yylloc.last_line, yylloc.last_column);
}
