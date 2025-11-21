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
#line 1 "sintatico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "nodes.h"

int yyerror(const char *s);
int yylex(void);
int errorc = 0;

#line 82 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_IDENT = 5,                      /* IDENT  */
  YYSYMBOL_READ_S = 6,                     /* READ_S  */
  YYSYMBOL_READ_E = 7,                     /* READ_E  */
  YYSYMBOL_SHOW_E = 8,                     /* SHOW_E  */
  YYSYMBOL_SHOW_S = 9,                     /* SHOW_S  */
  YYSYMBOL_DECL_IT = 10,                   /* DECL_IT  */
  YYSYMBOL_DECL_FT = 11,                   /* DECL_FT  */
  YYSYMBOL_ICR = 12,                       /* ICR  */
  YYSYMBOL_CMP_AND = 13,                   /* CMP_AND  */
  YYSYMBOL_CMP_OR = 14,                    /* CMP_OR  */
  YYSYMBOL_CMP_MEI = 15,                   /* CMP_MEI  */
  YYSYMBOL_CMP_MAI = 16,                   /* CMP_MAI  */
  YYSYMBOL_DECL_ST = 17,                   /* DECL_ST  */
  YYSYMBOL_IF_S = 18,                      /* IF_S  */
  YYSYMBOL_IF_E = 19,                      /* IF_E  */
  YYSYMBOL_ELSE_S = 20,                    /* ELSE_S  */
  YYSYMBOL_ELSE_E = 21,                    /* ELSE_E  */
  YYSYMBOL_LOOP_S = 22,                    /* LOOP_S  */
  YYSYMBOL_LOOP_E = 23,                    /* LOOP_E  */
  YYSYMBOL_LOOP_P = 24,                    /* LOOP_P  */
  YYSYMBOL_CMP_MAQ = 25,                   /* CMP_MAQ  */
  YYSYMBOL_CMP_DIF = 26,                   /* CMP_DIF  */
  YYSYMBOL_CMP_MEQ = 27,                   /* CMP_MEQ  */
  YYSYMBOL_CMP_IG = 28,                    /* CMP_IG  */
  YYSYMBOL_DECL_BL = 29,                   /* DECL_BL  */
  YYSYMBOL_BOOL_F = 30,                    /* BOOL_F  */
  YYSYMBOL_BOOL_T = 31,                    /* BOOL_T  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_36_ = 36,                       /* '|'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* '@'  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_44_ = 44,                       /* '\\'  */
  YYSYMBOL_45_ = 45,                       /* '+'  */
  YYSYMBOL_46_ = 46,                       /* '-'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_prog = 50,                      /* prog  */
  YYSYMBOL_stmts = 51,                     /* stmts  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_decl = 53,                      /* decl  */
  YYSYMBOL_atrib = 54,                     /* atrib  */
  YYSYMBOL_loop = 55,                      /* loop  */
  YYSYMBOL_if = 56,                        /* if  */
  YYSYMBOL_cond = 57,                      /* cond  */
  YYSYMBOL_exprlog = 58,                   /* exprlog  */
  YYSYMBOL_termlog = 59,                   /* termlog  */
  YYSYMBOL_faclog = 60,                    /* faclog  */
  YYSYMBOL_comp = 61,                      /* comp  */
  YYSYMBOL_perexpr = 62,                   /* perexpr  */
  YYSYMBOL_cmpl = 63,                      /* cmpl  */
  YYSYMBOL_val = 64,                       /* val  */
  YYSYMBOL_read = 65,                      /* read  */
  YYSYMBOL_rdexpr = 66,                    /* rdexpr  */
  YYSYMBOL_tpvar = 67,                     /* tpvar  */
  YYSYMBOL_show = 68,                      /* show  */
  YYSYMBOL_scont = 69,                     /* scont  */
  YYSYMBOL_termst = 70,                    /* termst  */
  YYSYMBOL_mistl = 71,                     /* mistl  */
  YYSYMBOL_string = 72,                    /* string  */
  YYSYMBOL_varshow = 73,                   /* varshow  */
  YYSYMBOL_atstring = 74,                  /* atstring  */
  YYSYMBOL_arit = 75,                      /* arit  */
  YYSYMBOL_expr = 76,                      /* expr  */
  YYSYMBOL_term = 77,                      /* term  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_comblock = 79                   /* comblock  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
      37,    38,    47,    45,     2,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    39,
       2,    34,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,    44,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    36,    41,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    61,    67,    75,    76,    77,    78,    79,
      80,    81,    85,    86,    87,    88,    89,    90,    91,    92,
      96,    97,   100,   101,   102,   103,   107,   112,   117,   126,
     128,   133,   136,   137,   140,   141,   144,   145,   148,   151,
     152,   156,   157,   158,   159,   160,   161,   165,   166,   171,
     172,   173,   176,   177,   181,   184,   190,   195,   199,   205,
     206,   207,   208,   212,   215,   216,   219,   220,   226,   231,
     236,   240,   246,   250,   256,   257,   260,   261,   265,   266,
     269,   270,   271,   274,   275,   276,   279,   280,   284,   285,
     286,   287,   290,   294
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "IDENT", "READ_S", "READ_E", "SHOW_E", "SHOW_S", "DECL_IT", "DECL_FT",
  "ICR", "CMP_AND", "CMP_OR", "CMP_MEI", "CMP_MAI", "DECL_ST", "IF_S",
  "IF_E", "ELSE_S", "ELSE_E", "LOOP_S", "LOOP_E", "LOOP_P", "CMP_MAQ",
  "CMP_DIF", "CMP_MEQ", "CMP_IG", "DECL_BL", "BOOL_F", "BOOL_T", "']'",
  "'['", "'='", "':'", "'|'", "'('", "')'", "';'", "'{'", "'}'", "'@'",
  "'%'", "'\\\\'", "'+'", "'-'", "'*'", "'/'", "$accept", "prog", "stmts",
  "stmt", "decl", "atrib", "loop", "if", "cond", "exprlog", "termlog",
  "faclog", "comp", "perexpr", "cmpl", "val", "read", "rdexpr", "tpvar",
  "show", "scont", "termst", "mistl", "string", "varshow", "atstring",
  "arit", "expr", "term", "factor", "comblock", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     174,   -34,  -121,    24,     1,     6,    44,    50,    76,    17,
      66,    79,   103,    91,  -121,   174,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,     7,   -15,  -121,    92,    74,    83,    65,
      -1,    67,    68,    69,    59,  -121,    73,  -121,  -121,    17,
      99,   105,   109,  -121,  -121,   189,  -121,   -16,   111,    97,
     114,    -8,  -121,  -121,  -121,   103,   103,   103,   103,  -121,
    -121,  -121,   117,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
     110,   112,   142,   116,  -121,    -1,    -1,  -121,  -121,   152,
     155,   157,   158,    74,    13,   129,    17,    17,  -121,  -121,
    -121,  -121,  -121,  -121,    17,   153,   135,   169,    74,  -121,
     -15,   -15,  -121,  -121,   156,   182,   171,   -18,   187,    -1,
    -121,  -121,  -121,   165,   166,   175,  -121,   179,  -121,   174,
     109,  -121,  -121,   192,   174,   180,   185,   122,  -121,   177,
      74,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   106,
     190,    56,  -121,  -121,  -121,  -121,  -121,    74,  -121,   186,
     200,  -121,   184,   188,  -121,   193,   178,   174,   191,  -121,
      65,  -121,   127,   174,  -121,  -121,   164,  -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    89,    88,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     4,    11,     5,     9,     6,
       8,     7,    10,     0,    82,    85,     0,     0,     0,     0,
       0,    17,    18,    16,    47,    49,    50,    53,    52,     0,
       0,    31,    32,    34,    37,    36,    39,    47,     0,    19,
      90,     0,     1,     3,    79,     0,     0,     0,     0,    87,
      77,    76,     0,    23,    22,    20,    59,    60,    61,    62,
       0,     0,     0,     0,    65,    66,    64,    68,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    44,
      41,    46,    42,    43,     0,     0,     0,     0,     0,    86,
      80,    81,    83,    84,    91,     0,     0,     0,     0,    67,
      70,    69,    73,     0,     0,     0,    48,     0,    40,     0,
      33,    35,    38,     0,     0,     0,     0,     0,    54,    55,
       0,    74,    63,    71,    12,    14,    13,    51,    93,     0,
       0,     0,    15,    91,    25,    24,    21,     0,    56,     0,
      29,    92,     0,     0,    27,     0,     0,     0,     0,    28,
      57,    75,     0,     0,    58,    30,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,   195,     0,  -121,  -121,  -121,  -121,   211,   194,
     137,   138,  -121,   134,  -121,  -121,  -121,  -120,  -121,  -121,
    -121,  -121,  -121,   154,   -41,   -26,   -25,   218,     8,    32,
    -118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,   138,    16,    17,    18,    19,    40,    41,
      42,    43,    44,    45,    94,    46,    20,    70,    71,    21,
      73,    74,    75,    76,    77,    78,    22,    23,    24,    25,
     139
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    62,    60,    65,    61,    26,   141,   -78,    54,   148,
     -78,   -78,   -78,   -78,   130,    15,   -78,   -78,   -78,    95,
      34,    35,    36,    82,   -78,   -78,   131,    86,   -78,   -78,
      99,   -78,    57,    58,   110,   111,   -78,    55,    56,   162,
     164,    29,    72,   -78,   -78,   166,    30,    37,    38,    31,
     112,   118,    55,    56,    39,    32,    27,   117,    28,     1,
       2,     3,     4,   100,   101,     5,     6,     7,   133,    47,
      35,    36,   126,     8,     9,    66,    67,    60,    10,    61,
     153,    33,    68,   112,    49,    11,     1,     2,    50,   102,
     103,    52,   154,    12,    69,    59,    37,    38,    82,    79,
      80,    81,   146,    39,   149,    83,     1,     2,    50,     1,
       2,     3,     4,    63,    64,     5,     6,     7,    85,    86,
      12,   155,    87,     8,     9,     1,     2,    50,    10,    97,
       1,     2,     3,     4,    96,    11,     5,     6,     7,   151,
      12,   151,   150,    12,     8,     9,    98,   107,   165,    10,
     104,   105,   144,   145,   106,   113,    11,   108,   114,    12,
     115,   116,   151,   123,    12,   119,   151,     1,     2,     3,
       4,   124,   125,     5,     6,     7,   129,     1,     2,     3,
       4,     8,     9,     5,     6,     7,    10,    66,    67,   128,
     127,     8,     9,    11,    68,   132,    10,   140,   134,   135,
     167,    12,   152,    11,    88,    89,    69,   158,   136,   147,
      53,    12,   137,   142,    90,    91,    92,    93,   143,   156,
     157,    48,   161,   120,   159,   121,   160,   163,   122,   109,
      51,     0,     0,    84
};

static const yytype_int16 yycheck[] =
{
       0,    27,     3,    28,     5,    39,   124,     0,     1,   129,
       3,     4,     5,     6,    32,    15,     9,    10,    11,    35,
       3,     4,     5,    39,    17,    18,    44,    14,    21,    22,
      38,    24,    47,    48,    75,    76,    29,    45,    46,   157,
     160,    40,    43,    36,    37,   163,    40,    30,    31,     5,
      76,    38,    45,    46,    37,     5,    32,    83,    34,     3,
       4,     5,     6,    55,    56,     9,    10,    11,   109,     3,
       4,     5,    98,    17,    18,    10,    11,     3,    22,     5,
      24,     5,    17,   109,     5,    29,     3,     4,     5,    57,
      58,     0,    36,    37,    29,     3,    30,    31,    39,    32,
      32,    32,   127,    37,   130,    32,     3,     4,     5,     3,
       4,     5,     6,    30,    31,     9,    10,    11,    19,    14,
      37,   147,    13,    17,    18,     3,     4,     5,    22,    32,
       3,     4,     5,     6,    23,    29,     9,    10,    11,   139,
      37,   141,    36,    37,    17,    18,    32,     5,    21,    22,
      33,    41,    30,    31,    42,     3,    29,    41,     3,    37,
       3,     3,   162,    10,    37,    36,   166,     3,     4,     5,
       6,    36,     3,     9,    10,    11,     5,     3,     4,     5,
       6,    17,    18,     9,    10,    11,    22,    10,    11,     7,
      34,    17,    18,    29,    17,     8,    22,     5,    33,    33,
      36,    37,    12,    29,    15,    16,    29,    23,    33,    32,
      15,    37,    33,    33,    25,    26,    27,    28,    33,    33,
      20,    10,    44,    86,    36,    87,    33,    36,    94,    75,
      12,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    11,    17,    18,
      22,    29,    37,    50,    51,    52,    53,    54,    55,    56,
      65,    68,    75,    76,    77,    78,    39,    32,    34,    40,
      40,     5,     5,     5,     3,     4,     5,    30,    31,    37,
      57,    58,    59,    60,    61,    62,    64,     3,    57,     5,
       5,    76,     0,    51,     1,    45,    46,    47,    48,     3,
       3,     5,    74,    30,    31,    75,    10,    11,    17,    29,
      66,    67,    43,    69,    70,    71,    72,    73,    74,    32,
      32,    32,    39,    32,    58,    19,    14,    13,    15,    16,
      25,    26,    27,    28,    63,    35,    23,    32,    32,    38,
      77,    77,    78,    78,    33,    41,    42,     5,    41,    72,
      73,    73,    74,     3,     3,     3,     3,    74,    38,    36,
      59,    60,    62,    10,    36,     3,    74,    34,     7,     5,
      32,    44,     8,    73,    33,    33,    33,    33,    52,    79,
       5,    79,    33,    33,    30,    31,    75,    32,    66,    74,
      36,    52,    12,    24,    36,    74,    33,    20,    23,    36,
      33,    44,    79,    36,    66,    21,    79,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    56,
      56,    57,    58,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     2,     2,     2,     2,
       3,     6,     3,     3,     6,     6,    10,     6,     7,     6,
       9,     1,     1,     3,     1,     3,     1,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     1,     1,     5,     3,     4,     6,     7,     1,
       1,     1,     1,     5,     1,     1,     1,     2,     1,     2,
       2,     3,     1,     2,     3,     6,     1,     1,     1,     2,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     4,     2,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

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
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
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
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: stmts  */
#line 49 "sintatico.y"
     { 
        if (errorc > 0) {
            // Se houver erro, não imprime a árvore
        } else {
            // Cria a raiz e imprime a AST
            Program *p = new Program((yyvsp[0].node));
            p->printAST(); 
        }
     }
#line 1551 "sintatico.tab.c"
    break;

  case 3: /* stmts: stmt stmts  */
#line 62 "sintatico.y"
      { 
          // Insere o stmt no início da lista de filhos do bloco stmts
          (yyvsp[0].node)->getChildren().insert((yyvsp[0].node)->getChildren().begin(), (yyvsp[-1].node)); 
          (yyval.node) = (yyvsp[0].node); 
      }
#line 1561 "sintatico.tab.c"
    break;

  case 4: /* stmts: stmt  */
#line 68 "sintatico.y"
      { 
          // Cria um novo bloco e adiciona o primeiro stmt
          (yyval.node) = new Block(); 
          (yyval.node)->append((yyvsp[0].node)); 
      }
#line 1571 "sintatico.tab.c"
    break;

  case 5: /* stmt: atrib  */
#line 75 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1577 "sintatico.tab.c"
    break;

  case 6: /* stmt: if  */
#line 76 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1583 "sintatico.tab.c"
    break;

  case 7: /* stmt: show  */
#line 77 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1589 "sintatico.tab.c"
    break;

  case 8: /* stmt: read  */
#line 78 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1595 "sintatico.tab.c"
    break;

  case 9: /* stmt: loop  */
#line 79 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1601 "sintatico.tab.c"
    break;

  case 10: /* stmt: arit  */
#line 80 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1607 "sintatico.tab.c"
    break;

  case 11: /* stmt: decl  */
#line 81 "sintatico.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1613 "sintatico.tab.c"
    break;

  case 12: /* decl: DECL_IT IDENT ']' INTEGER '['  */
#line 85 "sintatico.y"
                                     { (yyval.node) = new VectorDecl("int", (yyvsp[-3].name), (yyvsp[-1].integer)); }
#line 1619 "sintatico.tab.c"
    break;

  case 13: /* decl: DECL_ST IDENT ']' INTEGER '['  */
#line 86 "sintatico.y"
                                     { (yyval.node) = new VectorDecl("string", (yyvsp[-3].name), (yyvsp[-1].integer)); }
#line 1625 "sintatico.tab.c"
    break;

  case 14: /* decl: DECL_FT IDENT ']' INTEGER '['  */
#line 87 "sintatico.y"
                                     { (yyval.node) = new VectorDecl("float", (yyvsp[-3].name), (yyvsp[-1].integer)); }
#line 1631 "sintatico.tab.c"
    break;

  case 15: /* decl: DECL_BL IDENT ']' INTEGER '['  */
#line 88 "sintatico.y"
                                     { (yyval.node) = new VectorDecl("bool", (yyvsp[-3].name), (yyvsp[-1].integer)); }
#line 1637 "sintatico.tab.c"
    break;

  case 16: /* decl: DECL_ST IDENT  */
#line 89 "sintatico.y"
                                     { (yyval.node) = new VarDecl("string", (yyvsp[0].name)); }
#line 1643 "sintatico.tab.c"
    break;

  case 17: /* decl: DECL_IT IDENT  */
#line 90 "sintatico.y"
                                     { (yyval.node) = new VarDecl("int", (yyvsp[0].name)); }
#line 1649 "sintatico.tab.c"
    break;

  case 18: /* decl: DECL_FT IDENT  */
#line 91 "sintatico.y"
                                     { (yyval.node) = new VarDecl("float", (yyvsp[0].name)); }
#line 1655 "sintatico.tab.c"
    break;

  case 19: /* decl: DECL_BL IDENT  */
#line 92 "sintatico.y"
                                     { (yyval.node) = new VarDecl("bool", (yyvsp[0].name)); }
#line 1661 "sintatico.tab.c"
    break;

  case 20: /* atrib: IDENT '=' arit  */
#line 96 "sintatico.y"
                                        { (yyval.node) = new Store((yyvsp[-2].name), (yyvsp[0].node)); }
#line 1667 "sintatico.tab.c"
    break;

  case 21: /* atrib: IDENT ']' atstring '[' '=' arit  */
#line 97 "sintatico.y"
                                        { (yyval.node) = new VectorStore((yyvsp[-5].name), (yyvsp[-3].node), (yyvsp[0].node)); }
#line 1673 "sintatico.tab.c"
    break;

  case 22: /* atrib: IDENT '=' BOOL_T  */
#line 100 "sintatico.y"
                                        { (yyval.node) = new Store((yyvsp[-2].name), new ConstBool(true)); }
#line 1679 "sintatico.tab.c"
    break;

  case 23: /* atrib: IDENT '=' BOOL_F  */
#line 101 "sintatico.y"
                                        { (yyval.node) = new Store((yyvsp[-2].name), new ConstBool(false)); }
#line 1685 "sintatico.tab.c"
    break;

  case 24: /* atrib: IDENT ']' atstring '[' '=' BOOL_T  */
#line 102 "sintatico.y"
                                        { (yyval.node) = new VectorStore((yyvsp[-5].name), (yyvsp[-3].node), new ConstBool(true)); }
#line 1691 "sintatico.tab.c"
    break;

  case 25: /* atrib: IDENT ']' atstring '[' '=' BOOL_F  */
#line 103 "sintatico.y"
                                        { (yyval.node) = new VectorStore((yyvsp[-5].name), (yyvsp[-3].node), new ConstBool(false)); }
#line 1697 "sintatico.tab.c"
    break;

  case 26: /* loop: LOOP_S INTEGER ':' DECL_IT IDENT ICR LOOP_E '|' comblock '|'  */
#line 108 "sintatico.y"
     { 
        // Loop definido (FOR): LO 10 : it a++ OP
        (yyval.node) = new ForLoop((yyvsp[-8].integer), (yyvsp[-5].name), (yyvsp[-1].node));
     }
#line 1706 "sintatico.tab.c"
    break;

  case 27: /* loop: LOOP_S cond LOOP_E '|' comblock '|'  */
#line 113 "sintatico.y"
     { 
        // Loop condicional (WHILE)
        (yyval.node) = new WhileLoop((yyvsp[-4].node), (yyvsp[-1].node));
     }
#line 1715 "sintatico.tab.c"
    break;

  case 28: /* loop: LOOP_S cond LOOP_E '|' comblock LOOP_P '|'  */
#line 118 "sintatico.y"
     { 
        // Loop condicional com Break (PARE)
        (yyvsp[-2].node)->append(new BreakNode());
        (yyval.node) = new WhileLoop((yyvsp[-5].node), (yyvsp[-2].node));
     }
#line 1725 "sintatico.tab.c"
    break;

  case 29: /* if: IF_S cond IF_E '|' comblock '|'  */
#line 127 "sintatico.y"
     { (yyval.node) = new IfNode((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1731 "sintatico.tab.c"
    break;

  case 30: /* if: IF_S cond IF_E '|' comblock '|' ELSE_S comblock ELSE_E  */
#line 129 "sintatico.y"
     { (yyval.node) = new IfNode((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1737 "sintatico.tab.c"
    break;

  case 31: /* cond: exprlog  */
#line 133 "sintatico.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1743 "sintatico.tab.c"
    break;

  case 32: /* exprlog: termlog  */
#line 136 "sintatico.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1749 "sintatico.tab.c"
    break;

  case 33: /* exprlog: exprlog CMP_OR termlog  */
#line 137 "sintatico.y"
                                 { (yyval.node) = new BinaryOp((yyvsp[-2].node), "OR", (yyvsp[0].node)); }
#line 1755 "sintatico.tab.c"
    break;

  case 34: /* termlog: faclog  */
#line 140 "sintatico.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1761 "sintatico.tab.c"
    break;

  case 35: /* termlog: termlog CMP_AND faclog  */
#line 141 "sintatico.y"
                                 { (yyval.node) = new BinaryOp((yyvsp[-2].node), "AND", (yyvsp[0].node)); }
#line 1767 "sintatico.tab.c"
    break;

  case 36: /* faclog: perexpr  */
#line 144 "sintatico.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1773 "sintatico.tab.c"
    break;

  case 37: /* faclog: comp  */
#line 145 "sintatico.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1779 "sintatico.tab.c"
    break;

  case 38: /* comp: perexpr cmpl perexpr  */
#line 148 "sintatico.y"
                            { (yyval.node) = new BinaryOp((yyvsp[-2].node), (yyvsp[-1].node)->astLabel(), (yyvsp[0].node)); }
#line 1785 "sintatico.tab.c"
    break;

  case 39: /* perexpr: val  */
#line 151 "sintatico.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1791 "sintatico.tab.c"
    break;

  case 40: /* perexpr: '(' exprlog ')'  */
#line 152 "sintatico.y"
                          { (yyval.node) = (yyvsp[-1].node); }
#line 1797 "sintatico.tab.c"
    break;

  case 41: /* cmpl: CMP_MAQ  */
#line 156 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, ">", NULL); }
#line 1803 "sintatico.tab.c"
    break;

  case 42: /* cmpl: CMP_MEQ  */
#line 157 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, "<", NULL); }
#line 1809 "sintatico.tab.c"
    break;

  case 43: /* cmpl: CMP_IG  */
#line 158 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, "==", NULL); }
#line 1815 "sintatico.tab.c"
    break;

  case 44: /* cmpl: CMP_MAI  */
#line 159 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, ">=", NULL); }
#line 1821 "sintatico.tab.c"
    break;

  case 45: /* cmpl: CMP_MEI  */
#line 160 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, "<=", NULL); }
#line 1827 "sintatico.tab.c"
    break;

  case 46: /* cmpl: CMP_DIF  */
#line 161 "sintatico.y"
               { (yyval.node) = new BinaryOp(NULL, "!=", NULL); }
#line 1833 "sintatico.tab.c"
    break;

  case 47: /* val: INTEGER  */
#line 165 "sintatico.y"
              { (yyval.node) = new ConstInt((yyvsp[0].integer)); }
#line 1839 "sintatico.tab.c"
    break;

  case 48: /* val: INTEGER ';' INTEGER  */
#line 166 "sintatico.y"
                          { 
        // Suporte a float com sintaxe LIMPO (ex: 2;50)
        float f = (float)(yyvsp[-2].integer) + ((float)(yyvsp[0].integer) / 100.0);
        (yyval.node) = new ConstFloat(f); 
      }
#line 1849 "sintatico.tab.c"
    break;

  case 49: /* val: FLOAT  */
#line 171 "sintatico.y"
              { (yyval.node) = new ConstFloat((yyvsp[0].flt)); }
#line 1855 "sintatico.tab.c"
    break;

  case 50: /* val: IDENT  */
#line 172 "sintatico.y"
              { (yyval.node) = new Load((yyvsp[0].name)); }
#line 1861 "sintatico.tab.c"
    break;

  case 51: /* val: IDENT ']' atstring '['  */
#line 173 "sintatico.y"
                           { (yyval.node) = new VectorLoad((yyvsp[-3].name), (yyvsp[-1].node)); }
#line 1867 "sintatico.tab.c"
    break;

  case 52: /* val: BOOL_T  */
#line 176 "sintatico.y"
              { (yyval.node) = new ConstBool(true); }
#line 1873 "sintatico.tab.c"
    break;

  case 53: /* val: BOOL_F  */
#line 177 "sintatico.y"
              { (yyval.node) = new ConstBool(false); }
#line 1879 "sintatico.tab.c"
    break;

  case 54: /* read: READ_S '{' rdexpr '}' READ_E  */
#line 181 "sintatico.y"
                                    { (yyval.node) = new ReadNode((yyvsp[-2].node)); }
#line 1885 "sintatico.tab.c"
    break;

  case 55: /* rdexpr: tpvar '@' IDENT  */
#line 184 "sintatico.y"
                         { 
           // Cria um bloco para a leitura
           (yyval.node) = new Block();
           // Cria uma declaração implícita/uso para a leitura
           (yyval.node)->append(new VarDecl("input", (yyvsp[0].name))); 
       }
#line 1896 "sintatico.tab.c"
    break;

  case 56: /* rdexpr: tpvar '@' IDENT rdexpr  */
#line 190 "sintatico.y"
                                { 
           // Adiciona ao bloco existente de leitura
           (yyvsp[0].node)->getChildren().insert((yyvsp[0].node)->getChildren().begin(), new VarDecl("input", (yyvsp[-1].name)));
           (yyval.node) = (yyvsp[0].node);
       }
#line 1906 "sintatico.tab.c"
    break;

  case 57: /* rdexpr: tpvar '@' IDENT ']' atstring '['  */
#line 195 "sintatico.y"
                                          { 
           (yyval.node) = new Block();
           (yyval.node)->append(new VectorLoad((yyvsp[-3].name), (yyvsp[-1].node)));
       }
#line 1915 "sintatico.tab.c"
    break;

  case 58: /* rdexpr: tpvar '@' IDENT ']' atstring '[' rdexpr  */
#line 199 "sintatico.y"
                                                 {
           (yyvsp[0].node)->getChildren().insert((yyvsp[0].node)->getChildren().begin(), new VectorLoad((yyvsp[-4].name), (yyvsp[-2].node)));
           (yyval.node) = (yyvsp[0].node);
       }
#line 1924 "sintatico.tab.c"
    break;

  case 59: /* tpvar: DECL_IT  */
#line 205 "sintatico.y"
                { (yyval.node) = NULL; }
#line 1930 "sintatico.tab.c"
    break;

  case 60: /* tpvar: DECL_FT  */
#line 206 "sintatico.y"
                { (yyval.node) = NULL; }
#line 1936 "sintatico.tab.c"
    break;

  case 61: /* tpvar: DECL_ST  */
#line 207 "sintatico.y"
                { (yyval.node) = NULL; }
#line 1942 "sintatico.tab.c"
    break;

  case 62: /* tpvar: DECL_BL  */
#line 208 "sintatico.y"
                { (yyval.node) = NULL; }
#line 1948 "sintatico.tab.c"
    break;

  case 63: /* show: SHOW_S '{' scont '}' SHOW_E  */
#line 212 "sintatico.y"
                                   { (yyval.node) = new PrintNode((yyvsp[-2].node)); }
#line 1954 "sintatico.tab.c"
    break;

  case 64: /* scont: string  */
#line 215 "sintatico.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1960 "sintatico.tab.c"
    break;

  case 65: /* scont: termst  */
#line 216 "sintatico.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1966 "sintatico.tab.c"
    break;

  case 66: /* termst: mistl  */
#line 219 "sintatico.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1972 "sintatico.tab.c"
    break;

  case 67: /* termst: mistl string  */
#line 220 "sintatico.y"
                      { 
           (yyvsp[-1].node)->append((yyvsp[0].node));
           (yyval.node) = (yyvsp[-1].node);
       }
#line 1981 "sintatico.tab.c"
    break;

  case 68: /* mistl: varshow  */
#line 226 "sintatico.y"
                { 
           Block* b = new Block(); 
           b->append((yyvsp[0].node)); 
           (yyval.node) = b; 
      }
#line 1991 "sintatico.tab.c"
    break;

  case 69: /* mistl: string varshow  */
#line 231 "sintatico.y"
                       { 
           Block* b = new Block();
           b->append((yyvsp[-1].node)); b->append((yyvsp[0].node));
           (yyval.node) = b;
      }
#line 2001 "sintatico.tab.c"
    break;

  case 70: /* mistl: mistl varshow  */
#line 236 "sintatico.y"
                      {
           (yyvsp[-1].node)->append((yyvsp[0].node)); 
           (yyval.node) = (yyvsp[-1].node);
      }
#line 2010 "sintatico.tab.c"
    break;

  case 71: /* mistl: mistl string varshow  */
#line 240 "sintatico.y"
                             {
           (yyvsp[-2].node)->append((yyvsp[-1].node)); (yyvsp[-2].node)->append((yyvsp[0].node)); 
           (yyval.node) = (yyvsp[-2].node);
      }
#line 2019 "sintatico.tab.c"
    break;

  case 72: /* string: atstring  */
#line 246 "sintatico.y"
                  { 
           // Converte identificador ou número em nó de string literal para impressão
           (yyval.node) = new ConstString((yyvsp[0].node)->astLabel()); 
       }
#line 2028 "sintatico.tab.c"
    break;

  case 73: /* string: string atstring  */
#line 250 "sintatico.y"
                         { 
           // Concatenação simplificada para a árvore
           (yyval.node) = (yyvsp[-1].node);
       }
#line 2037 "sintatico.tab.c"
    break;

  case 74: /* varshow: '%' IDENT '\\'  */
#line 256 "sintatico.y"
                         { (yyval.node) = new Load((yyvsp[-1].name)); }
#line 2043 "sintatico.tab.c"
    break;

  case 75: /* varshow: '%' IDENT ']' atstring '[' '\\'  */
#line 257 "sintatico.y"
                                          { (yyval.node) = new VectorLoad((yyvsp[-4].name), (yyvsp[-2].node)); }
#line 2049 "sintatico.tab.c"
    break;

  case 76: /* atstring: IDENT  */
#line 260 "sintatico.y"
                  { (yyval.node) = new Load((yyvsp[0].name)); }
#line 2055 "sintatico.tab.c"
    break;

  case 77: /* atstring: INTEGER  */
#line 261 "sintatico.y"
                   { (yyval.node) = new ConstInt((yyvsp[0].integer)); }
#line 2061 "sintatico.tab.c"
    break;

  case 78: /* arit: expr  */
#line 265 "sintatico.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2067 "sintatico.tab.c"
    break;

  case 79: /* arit: expr error  */
#line 266 "sintatico.y"
                  { (yyval.node) = (yyvsp[-1].node); yyerrok; }
#line 2073 "sintatico.tab.c"
    break;

  case 80: /* expr: expr '+' term  */
#line 269 "sintatico.y"
                     { (yyval.node) = new BinaryOp((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 2079 "sintatico.tab.c"
    break;

  case 81: /* expr: expr '-' term  */
#line 270 "sintatico.y"
                     { (yyval.node) = new BinaryOp((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 2085 "sintatico.tab.c"
    break;

  case 82: /* expr: term  */
#line 271 "sintatico.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2091 "sintatico.tab.c"
    break;

  case 83: /* term: term '*' factor  */
#line 274 "sintatico.y"
                       { (yyval.node) = new BinaryOp((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 2097 "sintatico.tab.c"
    break;

  case 84: /* term: term '/' factor  */
#line 275 "sintatico.y"
                       { (yyval.node) = new BinaryOp((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 2103 "sintatico.tab.c"
    break;

  case 85: /* term: factor  */
#line 276 "sintatico.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2109 "sintatico.tab.c"
    break;

  case 86: /* factor: '(' expr ')'  */
#line 279 "sintatico.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2115 "sintatico.tab.c"
    break;

  case 87: /* factor: INTEGER ';' INTEGER  */
#line 280 "sintatico.y"
                               { 
           float f = (float)(yyvsp[-2].integer) + ((float)(yyvsp[0].integer) / 100.0);
           (yyval.node) = new ConstFloat(f); 
       }
#line 2124 "sintatico.tab.c"
    break;

  case 88: /* factor: FLOAT  */
#line 284 "sintatico.y"
                               { (yyval.node) = new ConstFloat((yyvsp[0].flt)); }
#line 2130 "sintatico.tab.c"
    break;

  case 89: /* factor: INTEGER  */
#line 285 "sintatico.y"
                               { (yyval.node) = new ConstInt((yyvsp[0].integer)); }
#line 2136 "sintatico.tab.c"
    break;

  case 90: /* factor: IDENT  */
#line 286 "sintatico.y"
                               { (yyval.node) = new Load((yyvsp[0].name)); }
#line 2142 "sintatico.tab.c"
    break;

  case 91: /* factor: IDENT ']' atstring '['  */
#line 287 "sintatico.y"
                               { (yyval.node) = new VectorLoad((yyvsp[-3].name), (yyvsp[-1].node)); }
#line 2148 "sintatico.tab.c"
    break;

  case 92: /* comblock: comblock stmt  */
#line 290 "sintatico.y"
                         { 
             (yyvsp[-1].node)->append((yyvsp[0].node)); 
             (yyval.node) = (yyvsp[-1].node); 
         }
#line 2157 "sintatico.tab.c"
    break;

  case 93: /* comblock: stmt  */
#line 294 "sintatico.y"
                { 
             (yyval.node) = new Block(); 
             (yyval.node)->append((yyvsp[0].node)); 
         }
#line 2166 "sintatico.tab.c"
    break;


#line 2170 "sintatico.tab.c"

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
          = {yyssp, yytoken};
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 300 "sintatico.y"

/* Main no lexico.l */
