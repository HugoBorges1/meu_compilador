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

#include "nodes.h"
#include <map>
#include <string>
#include <set>

int yyerror(const char *s);
int yylex(void);

std::map<std::string, int> memory_int;
std::map<std::string, std::map<int, int>> memory_vector_int;

std::map<std::string, std::string> memory_string;
std::map<std::string, std::map<int, std::string>> memory_vector_string;

std::map<std::string, double> memory_float;
std::map<std::string, std::map<int, double>> memory_vector_float;

std::map<std::string, bool> memory_bool;
std::map<std::string, std::map<int, bool>> memory_vector_bool;

std::map<std::string, std::map<int, int>> vec_read_counts;
std::map<std::string, std::map<int, int>> vec_loop_counts;
std::map<std::string, std::map<int, int>> vec_if_counts;

std::map<std::string, int> read_counts;
std::map<std::string, int> loop_change_counts;
std::map<std::string, int> if_change_counts;

std::set<std::string> declared_vars;
std::set<std::string> declared_floats; 
std::set<std::string> declared_strings;

int inside_loop = 0;
int inside_if = 0;


#line 109 "sintatico.tab.c"

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
  YYSYMBOL_READ_S = 3,                     /* READ_S  */
  YYSYMBOL_READ_E = 4,                     /* READ_E  */
  YYSYMBOL_SHOW_E = 5,                     /* SHOW_E  */
  YYSYMBOL_SHOW_S = 6,                     /* SHOW_S  */
  YYSYMBOL_DECL_IT = 7,                    /* DECL_IT  */
  YYSYMBOL_DECL_FT = 8,                    /* DECL_FT  */
  YYSYMBOL_ICR = 9,                        /* ICR  */
  YYSYMBOL_CMP_AND = 10,                   /* CMP_AND  */
  YYSYMBOL_CMP_OR = 11,                    /* CMP_OR  */
  YYSYMBOL_CMP_MEI = 12,                   /* CMP_MEI  */
  YYSYMBOL_CMP_MAI = 13,                   /* CMP_MAI  */
  YYSYMBOL_DECL_ST = 14,                   /* DECL_ST  */
  YYSYMBOL_IF_S = 15,                      /* IF_S  */
  YYSYMBOL_IF_E = 16,                      /* IF_E  */
  YYSYMBOL_ELSE_S = 17,                    /* ELSE_S  */
  YYSYMBOL_ELSE_E = 18,                    /* ELSE_E  */
  YYSYMBOL_LOOP_S = 19,                    /* LOOP_S  */
  YYSYMBOL_LOOP_E = 20,                    /* LOOP_E  */
  YYSYMBOL_LOOP_P = 21,                    /* LOOP_P  */
  YYSYMBOL_CMP_MAQ = 22,                   /* CMP_MAQ  */
  YYSYMBOL_CMP_DIF = 23,                   /* CMP_DIF  */
  YYSYMBOL_CMP_MEQ = 24,                   /* CMP_MEQ  */
  YYSYMBOL_CMP_IG = 25,                    /* CMP_IG  */
  YYSYMBOL_DECL_BL = 26,                   /* DECL_BL  */
  YYSYMBOL_BOOL_F = 27,                    /* BOOL_F  */
  YYSYMBOL_BOOL_T = 28,                    /* BOOL_T  */
  YYSYMBOL_INTEGER = 29,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 30,                     /* FLOAT  */
  YYSYMBOL_IDENT = 31,                     /* IDENT  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_36_ = 36,                       /* '|'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '@'  */
  YYSYMBOL_42_ = 42,                       /* '%'  */
  YYSYMBOL_43_ = 43,                       /* '\\'  */
  YYSYMBOL_44_ = 44,                       /* ';'  */
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
  YYSYMBOL_safeblock = 55,                 /* safeblock  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_loop = 57,                      /* loop  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_ifblock = 59,                   /* ifblock  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_if = 61,                        /* if  */
  YYSYMBOL_comblock = 62,                  /* comblock  */
  YYSYMBOL_exprlog = 63,                   /* exprlog  */
  YYSYMBOL_termlog = 64,                   /* termlog  */
  YYSYMBOL_faclog = 65,                    /* faclog  */
  YYSYMBOL_comp = 66,                      /* comp  */
  YYSYMBOL_perexpr = 67,                   /* perexpr  */
  YYSYMBOL_cmpl = 68,                      /* cmpl  */
  YYSYMBOL_val = 69,                       /* val  */
  YYSYMBOL_read = 70,                      /* read  */
  YYSYMBOL_rdexpr = 71,                    /* rdexpr  */
  YYSYMBOL_rditem = 72,                    /* rditem  */
  YYSYMBOL_tpvar = 73,                     /* tpvar  */
  YYSYMBOL_show = 74,                      /* show  */
  YYSYMBOL_showLST = 75,                   /* showLST  */
  YYSYMBOL_showITM = 76,                   /* showITM  */
  YYSYMBOL_varshow = 77,                   /* varshow  */
  YYSYMBOL_atstring = 78,                  /* atstring  */
  YYSYMBOL_indice = 79,                    /* indice  */
  YYSYMBOL_arit = 80,                      /* arit  */
  YYSYMBOL_expr = 81,                      /* expr  */
  YYSYMBOL_term = 82,                      /* term  */
  YYSYMBOL_factor = 83                     /* factor  */
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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

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
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      37,    38,    47,    45,     2,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    44,
       2,    34,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,    43,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    36,    40,     2,     2,     2,     2,
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
       0,    62,    62,    71,    76,    80,    81,    82,    83,    84,
      85,    86,    89,    94,   100,   106,   111,   116,   122,   127,
     133,   157,   168,   179,   213,   232,   249,   249,   251,   251,
     257,   261,   265,   265,   267,   271,   275,   280,   284,   288,
     292,   296,   300,   304,   308,   312,   316,   320,   324,   328,
     332,   336,   340,   344,   348,   352,   381,   407,   411,   415,
     420,   425,   431,   435,   439,   443,   447,   451,   456,   460,
     464,   488,   515,   519,   523,   527,   531,   535,   540,   544,
     548,   552,   556,   560,   564,   568,   572,   576,   580,   584,
     588,   592,   596,   600,   604,   608,   612,   616,   620,   624,
     628,   653
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
  "\"end of file\"", "error", "\"invalid token\"", "READ_S", "READ_E",
  "SHOW_E", "SHOW_S", "DECL_IT", "DECL_FT", "ICR", "CMP_AND", "CMP_OR",
  "CMP_MEI", "CMP_MAI", "DECL_ST", "IF_S", "IF_E", "ELSE_S", "ELSE_E",
  "LOOP_S", "LOOP_E", "LOOP_P", "CMP_MAQ", "CMP_DIF", "CMP_MEQ", "CMP_IG",
  "DECL_BL", "BOOL_F", "BOOL_T", "INTEGER", "FLOAT", "IDENT", "']'", "'['",
  "'='", "':'", "'|'", "'('", "')'", "'{'", "'}'", "'@'", "'%'", "'\\\\'",
  "';'", "'+'", "'-'", "'*'", "'/'", "$accept", "prog", "stmts", "stmt",
  "decl", "atrib", "safeblock", "$@1", "loop", "$@2", "ifblock", "$@3",
  "if", "comblock", "exprlog", "termlog", "faclog", "comp", "perexpr",
  "cmpl", "val", "read", "rdexpr", "rditem", "tpvar", "show", "showLST",
  "showITM", "varshow", "atstring", "indice", "arit", "expr", "term",
  "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -34,   -20,    31,    41,    48,    90,    95,    55,   -83,
     -83,    53,    99,    28,     1,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,    93,    94,   -83,   126,    13,     9,    17,
      57,   -83,   -83,    63,    90,    10,   112,   -83,   -83,    12,
     -83,    66,     2,   113,   106,    81,   116,    18,   -83,   -83,
      99,    99,    99,    99,   -83,   -83,   -83,     3,   -83,   108,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   100,   -83,   -83,   -83,   -83,   -83,    36,   -83,   -83,
     -83,   121,   122,   124,   106,    -5,    90,   118,    90,   -83,
     -83,   -83,   -83,   -83,   -83,    90,   148,   123,   128,   -83,
     -83,   125,   -83,   -83,   -83,   106,   -83,    94,    94,   -83,
     -83,   156,   -83,   130,    -3,   157,   -83,   131,   132,   133,
     134,   -83,   112,   -83,   -83,   -83,   137,   -83,   136,   129,
     138,   -83,   140,    59,   -83,   -83,   -83,   -83,   -83,   -83,
     139,     1,   161,   -18,     1,   -83,    86,   -83,   106,   141,
     159,   -83,     1,   153,   142,   -83,     1,   -83,   -83,   -83,
     144,   143,   -83,   -83,   145,   -83,   -83,   -83,   162,   -83,
     -83,   -83,   146,   -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
      98,   100,     0,     0,     2,     4,    11,     5,     9,     6,
       8,     7,    10,    90,    93,    96,     0,     0,    16,    17,
      19,    53,    54,    55,     0,     0,    38,    40,    43,    42,
      45,    53,     0,    18,     0,     0,   100,     0,     1,     3,
       0,     0,     0,     0,    62,    63,    64,     0,    58,     0,
      73,    72,    83,    82,    74,    77,    78,    79,    80,    81,
      75,     0,    76,    84,    85,    86,    87,     0,    66,    69,
      68,     0,     0,     0,     0,     0,     0,     0,     0,    51,
      50,    47,    52,    48,    49,     0,     0,     0,     0,    89,
      88,     0,    22,    21,    20,     0,    97,    91,    92,    94,
      95,     0,    59,     0,     0,    81,    67,     0,     0,     0,
       0,    46,    39,    32,    41,    44,     0,    26,     0,   101,
       0,    57,    60,     0,    70,    65,    12,    14,    13,    56,
       0,     0,     0,     0,     0,    15,     0,   101,     0,     0,
      34,    37,    33,     0,     0,    30,    27,    25,    24,    23,
       0,     0,    32,    36,     0,    31,    61,    71,     0,    28,
      35,    26,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,     0,   -83,   -83,     8,   -83,   -83,   -83,
      21,   -83,   -83,    40,     5,   101,    97,   -83,    98,   -83,
     -83,   -83,   -83,   135,   -83,   -83,   -83,   111,   -83,    56,
     -82,   -44,   178,    96,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,   151,    16,    17,   143,   144,    18,   171,
     140,   141,    19,   152,    35,    36,    37,    38,    39,    95,
      40,    20,    57,    58,    59,    21,    77,    78,    79,    80,
     101,    22,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,   104,   120,   154,     1,    26,    86,     2,     3,     4,
      54,    55,    42,    86,    49,     5,     6,    56,   155,    27,
       7,    86,    97,   130,    89,    90,    87,     8,    48,   133,
       9,    10,    11,   121,    91,    92,    93,    94,    12,    85,
     134,    81,    60,   111,    61,    62,    63,    64,    65,    82,
      66,    67,    68,    69,    70,    71,   106,    72,    73,    74,
      75,    76,    28,    50,    51,    60,   160,    61,    62,    63,
      64,    65,    29,    66,    67,    68,   115,    70,    71,    30,
      72,    73,    74,    75,    76,    44,    43,    45,    60,    83,
      61,    62,    63,    64,    65,    84,    66,    67,    68,    69,
      70,    96,   159,    72,    73,    74,    75,    76,   102,   103,
       9,    10,    46,   157,   158,     9,    10,    46,    12,    31,
      32,    33,    88,    12,    41,    32,    33,    34,     9,    10,
      46,   114,    34,    54,    55,    99,    12,   100,    50,    51,
      56,    52,    53,   109,   110,    98,   107,   108,   105,   113,
     117,   118,   163,   119,   123,   126,   163,   128,   129,   127,
     131,   132,   135,   146,   136,   137,   138,   139,   142,   145,
     153,   147,   148,   164,   161,   150,   162,   166,   165,   172,
     170,   169,   173,   168,   156,   124,   167,   122,   116,   149,
      47,     0,   112,   125
};

static const yytype_int16 yycheck[] =
{
       0,    45,    84,    21,     3,    39,    11,     6,     7,     8,
       7,     8,     7,    11,    14,    14,    15,    14,    36,    39,
      19,    11,    20,   105,    12,    13,    16,    26,     0,    32,
      29,    30,    31,    38,    22,    23,    24,    25,    37,    34,
      43,    32,    29,    40,    31,    32,    33,    34,    35,    32,
      37,    38,    39,    40,    41,    42,    38,    44,    45,    46,
      47,    48,    31,    45,    46,    29,   148,    31,    32,    33,
      34,    35,    31,    37,    38,    39,    40,    41,    42,    31,
      44,    45,    46,    47,    48,    32,    31,    34,    29,    32,
      31,    32,    33,    34,    35,    32,    37,    38,    39,    40,
      41,    35,   146,    44,    45,    46,    47,    48,    27,    28,
      29,    30,    31,    27,    28,    29,    30,    31,    37,    29,
      30,    31,    10,    37,    29,    30,    31,    37,    29,    30,
      31,    31,    37,     7,     8,    29,    37,    31,    45,    46,
      14,    47,    48,    52,    53,    32,    50,    51,    32,    41,
      29,    29,   152,    29,    36,     7,   156,    29,    33,    36,
       4,    31,     5,    34,    33,    33,    33,    33,    31,    33,
       9,    33,    32,    20,    33,    36,    17,    33,    36,   171,
      18,    36,    36,   162,   144,    88,    43,    86,    77,   133,
      12,    -1,    57,    95
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     8,    14,    15,    19,    26,    29,
      30,    31,    37,    50,    51,    52,    53,    54,    57,    61,
      70,    74,    80,    81,    82,    83,    39,    39,    31,    31,
      31,    29,    30,    31,    37,    63,    64,    65,    66,    67,
      69,    29,    63,    31,    32,    34,    31,    81,     0,    52,
      45,    46,    47,    48,     7,     8,    14,    71,    72,    73,
      29,    31,    32,    33,    34,    35,    37,    38,    39,    40,
      41,    42,    44,    45,    46,    47,    48,    75,    76,    77,
      78,    32,    32,    32,    32,    63,    11,    16,    10,    12,
      13,    22,    23,    24,    25,    68,    35,    20,    32,    29,
      31,    79,    27,    28,    80,    32,    38,    82,    82,    83,
      83,    40,    72,    41,    31,    40,    76,    29,    29,    29,
      79,    38,    64,    36,    65,    67,     7,    36,    29,    33,
      79,     4,    31,    32,    43,     5,    33,    33,    33,    33,
      59,    60,    31,    55,    56,    33,    34,    33,    32,    78,
      36,    52,    62,     9,    21,    36,    62,    27,    28,    80,
      79,    33,    17,    52,    20,    36,    33,    43,    59,    36,
      18,    58,    55,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    56,    55,    58,    57,
      57,    57,    60,    59,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     2,     2,     2,     2,
       3,     3,     3,     6,     6,     6,     0,     2,     0,    11,
       6,     7,     0,     2,     6,     9,     2,     1,     1,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     2,
       3,     6,     1,     1,     1,     5,     1,     2,     1,     1,
       3,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     4
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
#line 62 "sintatico.y"
             {    
     Program pg((yyvsp[0].node));
     pg.printAST();

     SemanticVarDecl vd;
     vd.check(&pg);
     vd.printFoundVars();
}
#line 1580 "sintatico.tab.c"
    break;

  case 3: /* stmts: stmts stmt  */
#line 71 "sintatico.y"
                       {
     (yyvsp[-1].node)->append((yyvsp[0].node));
     (yyval.node) = (yyvsp[-1].node);
}
#line 1589 "sintatico.tab.c"
    break;

  case 4: /* stmts: stmt  */
#line 76 "sintatico.y"
             {
     (yyval.node) = new Stmts((yyvsp[0].node));
}
#line 1597 "sintatico.tab.c"
    break;

  case 12: /* decl: DECL_IT IDENT ']' INTEGER '['  */
#line 89 "sintatico.y"
                                                 {
     declared_vars.insert((yyvsp[-3].name));
     (yyval.node) = new VectorDecl((yyvsp[-3].name), (yyvsp[-1].integer), "int");
}
#line 1606 "sintatico.tab.c"
    break;

  case 13: /* decl: DECL_ST IDENT ']' INTEGER '['  */
#line 94 "sintatico.y"
                                                 {
     declared_vars.insert((yyvsp[-3].name));
     declared_strings.insert((yyvsp[-3].name));
     (yyval.node) = new VectorDecl((yyvsp[-3].name), (yyvsp[-1].integer), "string");
}
#line 1616 "sintatico.tab.c"
    break;

  case 14: /* decl: DECL_FT IDENT ']' INTEGER '['  */
#line 100 "sintatico.y"
                                                 {
     declared_floats.insert((yyvsp[-3].name));
     declared_vars.insert((yyvsp[-3].name));
     (yyval.node) = new VectorDecl((yyvsp[-3].name), (yyvsp[-1].integer), "float");
}
#line 1626 "sintatico.tab.c"
    break;

  case 15: /* decl: DECL_BL IDENT ']' INTEGER '['  */
#line 106 "sintatico.y"
                                                 {
     declared_vars.insert((yyvsp[-3].name));
     (yyval.node) = new VectorDecl((yyvsp[-3].name), (yyvsp[-1].integer), "boolean");
}
#line 1635 "sintatico.tab.c"
    break;

  case 16: /* decl: DECL_IT IDENT  */
#line 111 "sintatico.y"
                           {
     declared_vars.insert((yyvsp[0].name));
     (yyval.node) = new VarDecl((yyvsp[0].name), "int");
}
#line 1644 "sintatico.tab.c"
    break;

  case 17: /* decl: DECL_FT IDENT  */
#line 116 "sintatico.y"
                           {
     declared_floats.insert((yyvsp[0].name));
     declared_vars.insert((yyvsp[0].name));
     (yyval.node) = new VarDecl((yyvsp[0].name), "float");
}
#line 1654 "sintatico.tab.c"
    break;

  case 18: /* decl: DECL_BL IDENT  */
#line 122 "sintatico.y"
                           {
     declared_vars.insert((yyvsp[0].name));
     (yyval.node) = new VarDecl((yyvsp[0].name), "bool");
}
#line 1663 "sintatico.tab.c"
    break;

  case 19: /* decl: DECL_ST IDENT  */
#line 127 "sintatico.y"
                           {
     declared_vars.insert((yyvsp[0].name));
     declared_strings.insert((yyvsp[0].name));
     (yyval.node) = new VarDecl((yyvsp[0].name), "string");
}
#line 1673 "sintatico.tab.c"
    break;

  case 20: /* atrib: IDENT '=' arit  */
#line 133 "sintatico.y"
                               {

     if (inside_loop == 0 && inside_if == 0) {
          if (declared_strings.count((yyvsp[-2].name))) {
               memory_string[(yyvsp[-2].name)] = (yyvsp[0].node)->getStringValue();
          } 
          else if (declared_floats.count((yyvsp[-2].name))) {
               memory_float[(yyvsp[-2].name)] = (yyvsp[0].node)->getDoubleValue();
          }
          else {
               memory_int[(yyvsp[-2].name)] = (int)(yyvsp[0].node)->getDoubleValue(); 
          }
     }

     (yyval.node) = new Store((yyvsp[-2].name), (yyvsp[0].node));
     
     if (inside_loop > 0) {
          loop_change_counts[(yyvsp[-2].name)]++;
     }
     if (inside_if > 0) {
          if_change_counts[(yyvsp[-2].name)]++;
     }
}
#line 1701 "sintatico.tab.c"
    break;

  case 21: /* atrib: IDENT '=' BOOL_T  */
#line 157 "sintatico.y"
                             {
     if (inside_loop == 0 && inside_if == 0) {
          memory_bool[(yyvsp[-2].name)] = true; 
     }

     (yyval.node) = new Store((yyvsp[-2].name), new ConstBoolean(true));

     if (inside_loop > 0) loop_change_counts[(yyvsp[-2].name)]++;
     if (inside_if > 0) if_change_counts[(yyvsp[-2].name)]++;
}
#line 1716 "sintatico.tab.c"
    break;

  case 22: /* atrib: IDENT '=' BOOL_F  */
#line 168 "sintatico.y"
                             {
     if (inside_loop == 0 && inside_if == 0) {
          memory_bool[(yyvsp[-2].name)] = false; 
     }

     (yyval.node) = new Store((yyvsp[-2].name), new ConstBoolean(false));

     if (inside_loop > 0) loop_change_counts[(yyvsp[-2].name)]++;
     if (inside_if > 0) if_change_counts[(yyvsp[-2].name)]++;
}
#line 1731 "sintatico.tab.c"
    break;

  case 23: /* atrib: IDENT ']' indice '[' '=' arit  */
#line 179 "sintatico.y"
                                                 {
     int indexVal = (yyvsp[-3].node)->getIntValue();

     int r = vec_read_counts[(yyvsp[-5].name)][indexVal];
     int l = vec_loop_counts[(yyvsp[-5].name)][indexVal];
     int i = vec_if_counts[(yyvsp[-5].name)][indexVal];

     string strVal = (yyvsp[0].node)->getStringValue();

     if (strVal == "" && memory_vector_string.count((yyvsp[-5].name))) { 
          if (declared_floats.count((yyvsp[-5].name))) strVal = to_string((yyvsp[0].node)->getDoubleValue());
          else strVal = to_string((yyvsp[0].node)->getIntValue());
     }

     if (inside_loop == 0 && inside_if == 0) {
          if (strVal != "") {
               memory_vector_string[(yyvsp[-5].name)][indexVal] = strVal;
          } 
          else if (declared_floats.count((yyvsp[-5].name))) {
               double val = (yyvsp[0].node)->getDoubleValue();
               memory_vector_float[(yyvsp[-5].name)][indexVal] = val;
          }
          else {
               int intVal = (yyvsp[0].node)->getIntValue();
               memory_vector_int[(yyvsp[-5].name)][indexVal] = intVal;
          }
     }

     (yyval.node) = new StoreVector((yyvsp[-5].name), (yyvsp[-3].node), (yyvsp[0].node), indexVal, true, r, l, i);

     if (inside_loop > 0) vec_loop_counts[(yyvsp[-5].name)][indexVal]++;
     if (inside_if > 0) vec_if_counts[(yyvsp[-5].name)][indexVal]++;
}
#line 1769 "sintatico.tab.c"
    break;

  case 24: /* atrib: IDENT ']' indice '[' '=' BOOL_T  */
#line 213 "sintatico.y"
                                               {
     int indexVal = (yyvsp[-3].node)->getIntValue();

     int r = vec_read_counts[(yyvsp[-5].name)][indexVal];
     int l = vec_loop_counts[(yyvsp[-5].name)][indexVal];
     int i = vec_if_counts[(yyvsp[-5].name)][indexVal];

     
     if (inside_loop == 0 && inside_if == 0) {
          memory_vector_bool[(yyvsp[-5].name)][indexVal] = true;
     }

     if (inside_loop > 0) loop_change_counts[(yyvsp[-5].name)]++;
     if (inside_if > 0) if_change_counts[(yyvsp[-5].name)]++;

     (yyval.node) = new StoreVector((yyvsp[-5].name), (yyvsp[-3].node), new ConstBoolean(true), indexVal, true, r, l, i);

}
#line 1792 "sintatico.tab.c"
    break;

  case 25: /* atrib: IDENT ']' indice '[' '=' BOOL_F  */
#line 232 "sintatico.y"
                                               {
     int indexVal = (yyvsp[-3].node)->getIntValue();

     int r = vec_read_counts[(yyvsp[-5].name)][indexVal];
     int l = vec_loop_counts[(yyvsp[-5].name)][indexVal];
     int i = vec_if_counts[(yyvsp[-5].name)][indexVal];
     
     if (inside_loop == 0 && inside_if == 0) {
          memory_vector_bool[(yyvsp[-5].name)][indexVal] = false;
     }

     if (inside_loop > 0) loop_change_counts[(yyvsp[-5].name)]++;
     if (inside_if > 0) if_change_counts[(yyvsp[-5].name)]++;
     
     (yyval.node) = new StoreVector((yyvsp[-5].name), (yyvsp[-3].node), new ConstBoolean(false), indexVal, true, r, l, i);
}
#line 1813 "sintatico.tab.c"
    break;

  case 26: /* $@1: %empty  */
#line 249 "sintatico.y"
            { inside_loop++; }
#line 1819 "sintatico.tab.c"
    break;

  case 27: /* safeblock: $@1 comblock  */
#line 249 "sintatico.y"
                                            { inside_loop--; (yyval.node) = (yyvsp[0].node); }
#line 1825 "sintatico.tab.c"
    break;

  case 28: /* $@2: %empty  */
#line 251 "sintatico.y"
                                                                { 
        declared_vars.insert((yyvsp[-3].name)); 
}
#line 1833 "sintatico.tab.c"
    break;

  case 29: /* loop: LOOP_S INTEGER ':' DECL_IT IDENT ICR LOOP_E '|' $@2 safeblock '|'  */
#line 253 "sintatico.y"
                    {
          (yyval.node) = new ForStmt((yyvsp[-9].integer), (yyvsp[-6].name), (yyvsp[-1].node));
 }
#line 1841 "sintatico.tab.c"
    break;

  case 30: /* loop: LOOP_S exprlog LOOP_E '|' safeblock '|'  */
#line 257 "sintatico.y"
                                                        {
     (yyval.node) = new LoopStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 1849 "sintatico.tab.c"
    break;

  case 31: /* loop: LOOP_S exprlog LOOP_E '|' safeblock LOOP_P '|'  */
#line 261 "sintatico.y"
                                                                {
     (yyval.node) = new LoopStmt((yyvsp[-5].node), (yyvsp[-2].node));
}
#line 1857 "sintatico.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 265 "sintatico.y"
          { inside_if++; }
#line 1863 "sintatico.tab.c"
    break;

  case 33: /* ifblock: $@3 comblock  */
#line 265 "sintatico.y"
                                        { inside_if--; (yyval.node) = (yyvsp[0].node); }
#line 1869 "sintatico.tab.c"
    break;

  case 34: /* if: IF_S exprlog IF_E '|' ifblock '|'  */
#line 267 "sintatico.y"
                                                 {
   (yyval.node) = new IfStmt((yyvsp[-4].node), (yyvsp[-1].node));
}
#line 1877 "sintatico.tab.c"
    break;

  case 35: /* if: IF_S exprlog IF_E '|' ifblock '|' ELSE_S ifblock ELSE_E  */
#line 271 "sintatico.y"
                                                                           {
   (yyval.node) = new IfStmt((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node));
}
#line 1885 "sintatico.tab.c"
    break;

  case 36: /* comblock: comblock stmt  */
#line 275 "sintatico.y"
                              {
     (yyvsp[-1].node)->append((yyvsp[0].node));
     (yyval.node) = (yyvsp[-1].node);
}
#line 1894 "sintatico.tab.c"
    break;

  case 37: /* comblock: stmt  */
#line 280 "sintatico.y"
                {
     (yyval.node) = new Stmts((yyvsp[0].node));
}
#line 1902 "sintatico.tab.c"
    break;

  case 38: /* exprlog: termlog  */
#line 284 "sintatico.y"
                       { 
     (yyval.node) = (yyvsp[0].node);
}
#line 1910 "sintatico.tab.c"
    break;

  case 39: /* exprlog: exprlog CMP_OR termlog  */
#line 288 "sintatico.y"
                                         {
     (yyval.node) = new CompOp((yyvsp[-2].node), "OU", (yyvsp[0].node));
}
#line 1918 "sintatico.tab.c"
    break;

  case 40: /* termlog: faclog  */
#line 292 "sintatico.y"
                      { 
     (yyval.node) = (yyvsp[0].node); 
}
#line 1926 "sintatico.tab.c"
    break;

  case 41: /* termlog: termlog CMP_AND faclog  */
#line 296 "sintatico.y"
                                         {
     (yyval.node) = new CompOp((yyvsp[-2].node), "E", (yyvsp[0].node));
}
#line 1934 "sintatico.tab.c"
    break;

  case 42: /* faclog: perexpr  */
#line 300 "sintatico.y"
                      { 
     (yyval.node) = (yyvsp[0].node); 
}
#line 1942 "sintatico.tab.c"
    break;

  case 43: /* faclog: comp  */
#line 304 "sintatico.y"
                   { 
     (yyval.node) = (yyvsp[0].node);
}
#line 1950 "sintatico.tab.c"
    break;

  case 44: /* comp: perexpr cmpl perexpr  */
#line 308 "sintatico.y"
                                        {
     (yyval.node) = new CompOp((yyvsp[-2].node), (yyvsp[-1].name), (yyvsp[0].node));
}
#line 1958 "sintatico.tab.c"
    break;

  case 45: /* perexpr: val  */
#line 312 "sintatico.y"
                  { 
     (yyval.node) = (yyvsp[0].node); 
}
#line 1966 "sintatico.tab.c"
    break;

  case 46: /* perexpr: '(' exprlog ')'  */
#line 316 "sintatico.y"
                               { 
     (yyval.node) = (yyvsp[-1].node); 
}
#line 1974 "sintatico.tab.c"
    break;

  case 47: /* cmpl: CMP_MAQ  */
#line 320 "sintatico.y"
               { 
     (yyval.name) = (char*)"MAIOR_QUE"; 
}
#line 1982 "sintatico.tab.c"
    break;

  case 48: /* cmpl: CMP_MEQ  */
#line 324 "sintatico.y"
               { 
     (yyval.name) = (char*)"MENOR_QUE"; 
}
#line 1990 "sintatico.tab.c"
    break;

  case 49: /* cmpl: CMP_IG  */
#line 328 "sintatico.y"
               { 
     (yyval.name) = (char*)"IGUAL_A"; 
}
#line 1998 "sintatico.tab.c"
    break;

  case 50: /* cmpl: CMP_MAI  */
#line 332 "sintatico.y"
               { 
     (yyval.name) = (char*)"MAIOR_OU_IGUAL_A"; 
}
#line 2006 "sintatico.tab.c"
    break;

  case 51: /* cmpl: CMP_MEI  */
#line 336 "sintatico.y"
               { 
     (yyval.name) = (char*)"MENOR_OU_IGUAL_A"; 
}
#line 2014 "sintatico.tab.c"
    break;

  case 52: /* cmpl: CMP_DIF  */
#line 340 "sintatico.y"
               { 
     (yyval.name) = (char*)"DIFERENTE_DE"; 
}
#line 2022 "sintatico.tab.c"
    break;

  case 53: /* val: INTEGER  */
#line 344 "sintatico.y"
                 { 
    (yyval.node) = new ConstInteger((yyvsp[0].integer)); 
}
#line 2030 "sintatico.tab.c"
    break;

  case 54: /* val: FLOAT  */
#line 348 "sintatico.y"
               { 
    (yyval.node) = new ConstDouble((yyvsp[0].flt)); 
}
#line 2038 "sintatico.tab.c"
    break;

  case 55: /* val: IDENT  */
#line 352 "sintatico.y"
                { 
    int reads = read_counts[(yyvsp[0].name)];
    int loops = loop_change_counts[(yyvsp[0].name)];
    int ifs = if_change_counts[(yyvsp[0].name)]; 

    if (declared_vars.count((yyvsp[0].name))) {
        if (memory_string.count((yyvsp[0].name))) {
             (yyval.node) = new Load((yyvsp[0].name), memory_string[(yyvsp[0].name)], true, reads, loops, ifs);
        }
        else if (memory_float.count((yyvsp[0].name))) {
             double val = memory_float[(yyvsp[0].name)];
             (yyval.node) = new Load((yyvsp[0].name), val, true, reads, loops, ifs); 
        } 
        else if (memory_int.count((yyvsp[0].name))) {
             (yyval.node) = new Load((yyvsp[0].name), memory_int[(yyvsp[0].name)], true, reads, loops, ifs);
        } 
        else if (memory_bool.count((yyvsp[0].name))) {
             bool val = memory_bool[(yyvsp[0].name)];
             (yyval.node) = new Load((yyvsp[0].name), val, true, reads, loops, ifs);
        }
        else {
             (yyval.node) = new Load((yyvsp[0].name), 0, false, reads, loops, ifs);
        }
    } 
    else {
        (yyval.node) = new ConstString((yyvsp[0].name));
    }
}
#line 2071 "sintatico.tab.c"
    break;

  case 56: /* val: IDENT ']' indice '['  */
#line 381 "sintatico.y"
                                    { 
    int indexVal = (yyvsp[-1].node)->getIntValue();
    int reads = read_counts[(yyvsp[-3].name)];
    int loops = loop_change_counts[(yyvsp[-3].name)];
    
    if (memory_vector_int.count((yyvsp[-3].name)) && memory_vector_int[(yyvsp[-3].name)].count(indexVal)) {
         int val = memory_vector_int[(yyvsp[-3].name)][indexVal];
         (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops);
    } 
    else if (memory_vector_float.count((yyvsp[-3].name)) && memory_vector_float[(yyvsp[-3].name)].count(indexVal)) {
         double val = memory_vector_float[(yyvsp[-3].name)][indexVal];
         (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops);
    }
    else if (memory_vector_string.count((yyvsp[-3].name)) && memory_vector_string[(yyvsp[-3].name)].count(indexVal)) {
         string val = memory_vector_string[(yyvsp[-3].name)][indexVal];
         (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops);
    }
    else if (memory_vector_bool.count((yyvsp[-3].name)) && memory_vector_bool[(yyvsp[-3].name)].count(indexVal)) {
         bool val = memory_vector_bool[(yyvsp[-3].name)][indexVal];
         (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops);
    }
    else {
         (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, 0, false, reads, loops);
    }
}
#line 2101 "sintatico.tab.c"
    break;

  case 57: /* read: READ_S '{' rdexpr '}' READ_E  */
#line 407 "sintatico.y"
                                         {
     (yyval.node) = new Read((yyvsp[-2].node));
}
#line 2109 "sintatico.tab.c"
    break;

  case 58: /* rdexpr: rditem  */
#line 411 "sintatico.y"
                     {
     (yyval.node) = new ReadSeq((yyvsp[0].node));
}
#line 2117 "sintatico.tab.c"
    break;

  case 59: /* rdexpr: rdexpr rditem  */
#line 415 "sintatico.y"
                                 {
     (yyvsp[-1].node)->append((yyvsp[0].node));  
     (yyval.node) = (yyvsp[-1].node);
}
#line 2126 "sintatico.tab.c"
    break;

  case 60: /* rditem: tpvar '@' IDENT  */
#line 420 "sintatico.y"
                                  {
     read_counts[(yyvsp[0].name)]++; 
     (yyval.node) = new ReadVar((yyvsp[-2].name), (yyvsp[0].name));
}
#line 2135 "sintatico.tab.c"
    break;

  case 61: /* rditem: tpvar '@' IDENT ']' indice '['  */
#line 425 "sintatico.y"
                                                      {
       int indexVal = (yyvsp[-1].node)->getIntValue();
       vec_read_counts[(yyvsp[-3].name)][indexVal]++;
       (yyval.node) = new ReadVector((yyvsp[-5].name), (yyvsp[-3].name), (yyvsp[-1].node));
}
#line 2145 "sintatico.tab.c"
    break;

  case 62: /* tpvar: DECL_IT  */
#line 431 "sintatico.y"
                {
     (yyval.name) = (char*)"int";
}
#line 2153 "sintatico.tab.c"
    break;

  case 63: /* tpvar: DECL_FT  */
#line 435 "sintatico.y"
                {
     (yyval.name) = (char*)"float";
}
#line 2161 "sintatico.tab.c"
    break;

  case 64: /* tpvar: DECL_ST  */
#line 439 "sintatico.y"
                {
     (yyval.name) = (char*)"string";
}
#line 2169 "sintatico.tab.c"
    break;

  case 65: /* show: SHOW_S '{' showLST '}' SHOW_E  */
#line 443 "sintatico.y"
                                            {
     (yyval.node) = new Print((yyvsp[-2].node));
}
#line 2177 "sintatico.tab.c"
    break;

  case 66: /* showLST: showITM  */
#line 447 "sintatico.y"
                        {
     (yyval.node) = new PrintSeq((yyvsp[0].node));
}
#line 2185 "sintatico.tab.c"
    break;

  case 67: /* showLST: showLST showITM  */
#line 451 "sintatico.y"
                                       {
     (yyvsp[-1].node)->append((yyvsp[0].node));    
     (yyval.node) = (yyvsp[-1].node);
}
#line 2194 "sintatico.tab.c"
    break;

  case 68: /* showITM: atstring  */
#line 456 "sintatico.y"
                        {
     (yyval.node) = (yyvsp[0].node); 
}
#line 2202 "sintatico.tab.c"
    break;

  case 69: /* showITM: varshow  */
#line 460 "sintatico.y"
                       {
     (yyval.node) = (yyvsp[0].node);
}
#line 2210 "sintatico.tab.c"
    break;

  case 70: /* varshow: '%' IDENT '\\'  */
#line 464 "sintatico.y"
                             {
     int reads = read_counts[(yyvsp[-1].name)]; 
     int loops = loop_change_counts[(yyvsp[-1].name)];
     int ifs = if_change_counts[(yyvsp[-1].name)];

     if (memory_string.count((yyvsp[-1].name))) {
          (yyval.node) = new Load((yyvsp[-1].name), memory_string[(yyvsp[-1].name)], true, reads, loops, ifs);
     }
     else if (memory_float.count((yyvsp[-1].name))) {
          double val = memory_float[(yyvsp[-1].name)];
          (yyval.node) = new Load((yyvsp[-1].name), val, true, reads, loops, ifs);
     }
     else if (memory_int.count((yyvsp[-1].name))) {
          (yyval.node) = new Load((yyvsp[-1].name), memory_int[(yyvsp[-1].name)], true, reads, loops, ifs);
     } 
     else if (memory_bool.count((yyvsp[-1].name))) {
          bool val = memory_bool[(yyvsp[-1].name)];
          (yyval.node) = new Load((yyvsp[-1].name), val, true, reads, loops, ifs);
     }
     else {
          (yyval.node) = new Load((yyvsp[-1].name), 0, false, reads, loops, ifs);
     }
}
#line 2238 "sintatico.tab.c"
    break;

  case 71: /* varshow: '%' IDENT ']' atstring '[' '\\'  */
#line 488 "sintatico.y"
                                                   {
     int idx = (yyvsp[-2].node)->getIntValue();
     int reads = vec_read_counts[(yyvsp[-4].name)][idx]; 
     int loops = vec_loop_counts[(yyvsp[-4].name)][idx];
     int ifs = vec_if_counts[(yyvsp[-4].name)][idx];

     if (memory_vector_string.count((yyvsp[-4].name)) && memory_vector_string[(yyvsp[-4].name)].count(idx)) {
          string val = memory_vector_string[(yyvsp[-4].name)][idx];
          (yyval.node) = new LoadVector((yyvsp[-4].name), (yyvsp[-2].node), idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_int.count((yyvsp[-4].name)) && memory_vector_int[(yyvsp[-4].name)].count(idx)) {
          int val = memory_vector_int[(yyvsp[-4].name)][idx];
          (yyval.node) = new LoadVector((yyvsp[-4].name), (yyvsp[-2].node), idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_float.count((yyvsp[-4].name)) && memory_vector_float[(yyvsp[-4].name)].count(idx)) {
          double val = memory_vector_float[(yyvsp[-4].name)][idx];
          (yyval.node) = new LoadVector((yyvsp[-4].name), (yyvsp[-2].node), idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_bool.count((yyvsp[-4].name)) && memory_vector_bool[(yyvsp[-4].name)].count(idx)) {
          bool val = memory_vector_bool[(yyvsp[-4].name)][idx];
          (yyval.node) = new LoadVector((yyvsp[-4].name), (yyvsp[-2].node), idx, val, true, loops, ifs);
     }
     else {
          (yyval.node) = new LoadVector((yyvsp[-4].name), (yyvsp[-2].node), idx, 0, false, reads, loops, ifs);
     }
}
#line 2269 "sintatico.tab.c"
    break;

  case 72: /* atstring: IDENT  */
#line 515 "sintatico.y"
                     {
     (yyval.node) = new ConstString((yyvsp[0].name)); 
}
#line 2277 "sintatico.tab.c"
    break;

  case 73: /* atstring: INTEGER  */
#line 519 "sintatico.y"
                        {
     (yyval.node) = new ConstInteger((yyvsp[0].integer));
}
#line 2285 "sintatico.tab.c"
    break;

  case 74: /* atstring: '='  */
#line 523 "sintatico.y"
               {
     (yyval.node) = new ConstString("=");
}
#line 2293 "sintatico.tab.c"
    break;

  case 75: /* atstring: '@'  */
#line 527 "sintatico.y"
               {
     (yyval.node) = new ConstString("@");
}
#line 2301 "sintatico.tab.c"
    break;

  case 76: /* atstring: ';'  */
#line 531 "sintatico.y"
               {
     (yyval.node) = new ConstString(";");
}
#line 2309 "sintatico.tab.c"
    break;

  case 77: /* atstring: ':'  */
#line 535 "sintatico.y"
               {
     (yyval.node) = new ConstString(":");
}
#line 2317 "sintatico.tab.c"
    break;

  case 78: /* atstring: '('  */
#line 540 "sintatico.y"
               {
     (yyval.node) = new ConstString("(");
}
#line 2325 "sintatico.tab.c"
    break;

  case 79: /* atstring: ')'  */
#line 544 "sintatico.y"
               {
     (yyval.node) = new ConstString(")");
}
#line 2333 "sintatico.tab.c"
    break;

  case 80: /* atstring: '{'  */
#line 548 "sintatico.y"
               {
     (yyval.node) = new ConstString("{");
}
#line 2341 "sintatico.tab.c"
    break;

  case 81: /* atstring: '}'  */
#line 552 "sintatico.y"
               {
     (yyval.node) = new ConstString("}");
}
#line 2349 "sintatico.tab.c"
    break;

  case 82: /* atstring: '['  */
#line 556 "sintatico.y"
               {
     (yyval.node) = new ConstString("[");
}
#line 2357 "sintatico.tab.c"
    break;

  case 83: /* atstring: ']'  */
#line 560 "sintatico.y"
               {
     (yyval.node) = new ConstString("]");
}
#line 2365 "sintatico.tab.c"
    break;

  case 84: /* atstring: '+'  */
#line 564 "sintatico.y"
               {
     (yyval.node) = new ConstString("+");
}
#line 2373 "sintatico.tab.c"
    break;

  case 85: /* atstring: '-'  */
#line 568 "sintatico.y"
               {
     (yyval.node) = new ConstString("-");
}
#line 2381 "sintatico.tab.c"
    break;

  case 86: /* atstring: '*'  */
#line 572 "sintatico.y"
               {
     (yyval.node) = new ConstString("*");
}
#line 2389 "sintatico.tab.c"
    break;

  case 87: /* atstring: '/'  */
#line 576 "sintatico.y"
               {
     (yyval.node) = new ConstString("/");
}
#line 2397 "sintatico.tab.c"
    break;

  case 88: /* indice: IDENT  */
#line 580 "sintatico.y"
                   {
       (yyval.node) = new Load((yyvsp[0].name));
}
#line 2405 "sintatico.tab.c"
    break;

  case 89: /* indice: INTEGER  */
#line 584 "sintatico.y"
                      {
     (yyval.node) = new ConstInteger((yyvsp[0].integer));
}
#line 2413 "sintatico.tab.c"
    break;

  case 90: /* arit: expr  */
#line 588 "sintatico.y"
            {
     (yyval.node) = (yyvsp[0].node); 
}
#line 2421 "sintatico.tab.c"
    break;

  case 91: /* expr: expr '+' term  */
#line 592 "sintatico.y"
                         {
     (yyval.node) = new BinaryOp((yyvsp[-2].node), '+', (yyvsp[0].node));
}
#line 2429 "sintatico.tab.c"
    break;

  case 92: /* expr: expr '-' term  */
#line 596 "sintatico.y"
                         {
     (yyval.node) = new BinaryOp((yyvsp[-2].node), '-', (yyvsp[0].node));
}
#line 2437 "sintatico.tab.c"
    break;

  case 93: /* expr: term  */
#line 600 "sintatico.y"
            {
     (yyval.node) = (yyvsp[0].node);
}
#line 2445 "sintatico.tab.c"
    break;

  case 94: /* term: term '*' factor  */
#line 604 "sintatico.y"
                           {
     (yyval.node) = new BinaryOp((yyvsp[-2].node), '*', (yyvsp[0].node));
}
#line 2453 "sintatico.tab.c"
    break;

  case 95: /* term: term '/' factor  */
#line 608 "sintatico.y"
                           {
     (yyval.node) = new BinaryOp((yyvsp[-2].node), '/', (yyvsp[0].node));
}
#line 2461 "sintatico.tab.c"
    break;

  case 96: /* term: factor  */
#line 612 "sintatico.y"
              {
     (yyval.node) = (yyvsp[0].node);
}
#line 2469 "sintatico.tab.c"
    break;

  case 97: /* factor: '(' expr ')'  */
#line 616 "sintatico.y"
                     {
     (yyval.node) = (yyvsp[-1].node);
}
#line 2477 "sintatico.tab.c"
    break;

  case 98: /* factor: FLOAT  */
#line 620 "sintatico.y"
                    {
     (yyval.node) = new ConstDouble((yyvsp[0].flt));
}
#line 2485 "sintatico.tab.c"
    break;

  case 99: /* factor: INTEGER  */
#line 624 "sintatico.y"
                     {
     (yyval.node) = new ConstInteger((yyvsp[0].integer));
}
#line 2493 "sintatico.tab.c"
    break;

  case 100: /* factor: IDENT  */
#line 628 "sintatico.y"
                   {
     int reads = read_counts[(yyvsp[0].name)];
     int loops = loop_change_counts[(yyvsp[0].name)];
     int ifs = if_change_counts[(yyvsp[0].name)];

     if (declared_vars.count((yyvsp[0].name))) {
        if (memory_string.count((yyvsp[0].name))) {
             (yyval.node) = new Load((yyvsp[0].name), memory_string[(yyvsp[0].name)], true, reads, loops, ifs);
        }
        else if (memory_float.count((yyvsp[0].name))) {
             double val = memory_float[(yyvsp[0].name)];
             (yyval.node) = new Load((yyvsp[0].name), val, true, reads, loops, ifs);
        }
        else if (memory_int.count((yyvsp[0].name))) {
             (yyval.node) = new Load((yyvsp[0].name), memory_int[(yyvsp[0].name)], true, reads, loops, ifs);
        } 
        else {
             (yyval.node) = new Load((yyvsp[0].name), 0, false, reads, loops, ifs);
        }
    } 
    else {
        (yyval.node) = new ConstString((yyvsp[0].name));
    }
}
#line 2522 "sintatico.tab.c"
    break;

  case 101: /* factor: IDENT ']' indice '['  */
#line 653 "sintatico.y"
                                     {
     int indexVal = (yyvsp[-1].node)->getIntValue();
     
     int reads = vec_read_counts[(yyvsp[-3].name)][indexVal];
     int loops = vec_loop_counts[(yyvsp[-3].name)][indexVal];
     int ifs = vec_if_counts[(yyvsp[-3].name)][indexVal];

     if (memory_vector_int.count((yyvsp[-3].name)) && memory_vector_int[(yyvsp[-3].name)].count(indexVal)) {
          int val = memory_vector_int[(yyvsp[-3].name)][indexVal];

          (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops, ifs);
     } 
     else if (memory_vector_float.count((yyvsp[-3].name)) && memory_vector_float[(yyvsp[-3].name)].count(indexVal)) {
          double val = memory_vector_float[(yyvsp[-3].name)][indexVal];
          (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops, ifs);
     }
     else if (memory_vector_string.count((yyvsp[-3].name)) && memory_vector_string[(yyvsp[-3].name)].count(indexVal)) {
          string val = memory_vector_string[(yyvsp[-3].name)][indexVal];
          (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops, ifs);
     }
     else if (memory_vector_bool.count((yyvsp[-3].name)) && memory_vector_bool[(yyvsp[-3].name)].count(indexVal)) {
          bool val = memory_vector_bool[(yyvsp[-3].name)][indexVal];
          (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, val, true, reads, loops, ifs);
     }
     else {
          (yyval.node) = new LoadVector((yyvsp[-3].name), (yyvsp[-1].node), indexVal, 0, false, reads, loops, ifs);
     }
}
#line 2555 "sintatico.tab.c"
    break;


#line 2559 "sintatico.tab.c"

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

#line 682 "sintatico.y"
