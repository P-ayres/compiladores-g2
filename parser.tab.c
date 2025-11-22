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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* yyout vem do main.c (arquivo de saída) */
extern FILE* yyout;

/* ===== Helpers de string p/ “geração de código” ===== */
static char* strclone(const char* s){
    if(!s) return NULL;
    size_t n = strlen(s);
    char* r = (char*)malloc(n+1);
    memcpy(r, s, n+1);
    return r;
}

static char* cat2(const char* a,const char* b){
    size_t na = a ? strlen(a) : 0;
    size_t nb = b ? strlen(b) : 0;
    char* r = (char*)malloc(na + nb + 1);
    if(a) memcpy(r,     a,  na);
    if(b) memcpy(r+na,  b,  nb);
    r[na+nb] = '\0';
    return r;
}

static char* cat3(const char* a,const char* b,const char* c){
    char* t = cat2(a,b);
    char* r = cat2(t,c);
    free(t);
    return r;
}

static void append(char** base, const char* add){
    char* t = cat2(*base ? *base : "", add ? add : "");
    if(*base) free(*base);
    *base = t;
}

/* Indenta um bloco de código em 4 espaços por linha (para Python) */
static char* indent_block(const char* s){
    if(!s || !*s) return strclone("    pass\n"); /* bloco vazio → pass */

    size_t n = strlen(s);
    /* margem de segurança: até ~5x o tamanho original */
    char* r = (char*)malloc(n * 5 + 8);
    char* p = r;
    const char* q = s;

    /* primeira linha sempre começa indentada */
    *p++ = ' '; *p++ = ' '; *p++ = ' '; *p++ = ' ';

    for(; *q; ++q){
        *p++ = *q;
        if(*q == '\n' && *(q+1) != '\0'){
            *p++ = ' '; *p++ = ' '; *p++ = ' '; *p++ = ' ';
        }
    }

    *p = '\0';
    return r;
}

/* Acumulador do Python final */
static char* G_OUT = NULL;

int yylex(void);

/* Mensagem de erro mais “profissional”, com número da linha */
void yyerror(const char* s){
    extern int yylineno;
    fprintf(stderr,"[syntax] %s na linha %d\n", s, yylineno);
}

#line 147 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TRAINER = 3,                    /* TRAINER  */
  YYSYMBOL_POKEBALL = 4,                   /* POKEBALL  */
  YYSYMBOL_BATTLE = 5,                     /* BATTLE  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_TALLGRASS = 7,                  /* TALLGRASS  */
  YYSYMBOL_JOURNEY = 8,                    /* JOURNEY  */
  YYSYMBOL_SHOUT = 9,                      /* SHOUT  */
  YYSYMBOL_EVOLVE = 10,                    /* EVOLVE  */
  YYSYMBOL_TRUE = 11,                      /* TRUE  */
  YYSYMBOL_FALSE = 12,                     /* FALSE  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_NUMBER = 14,                    /* NUMBER  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_UMINUS = 30,                    /* UMINUS  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_items = 41,                     /* items  */
  YYSYMBOL_item = 42,                      /* item  */
  YYSYMBOL_func_decl = 43,                 /* func_decl  */
  YYSYMBOL_opt_param_list = 44,            /* opt_param_list  */
  YYSYMBOL_param_list = 45,                /* param_list  */
  YYSYMBOL_var_decl = 46,                  /* var_decl  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_stmt = 48,                      /* stmt  */
  YYSYMBOL_print = 49,                     /* print  */
  YYSYMBOL_if = 50,                        /* if  */
  YYSYMBOL_opt_else = 51,                  /* opt_else  */
  YYSYMBOL_while = 52,                     /* while  */
  YYSYMBOL_for = 53,                       /* for  */
  YYSYMBOL_for_init = 54,                  /* for_init  */
  YYSYMBOL_return = 55,                    /* return  */
  YYSYMBOL_expr = 56,                      /* expr  */
  YYSYMBOL_call = 57,                      /* call  */
  YYSYMBOL_opt_arg_list = 58,              /* opt_arg_list  */
  YYSYMBOL_arg_list = 59,                  /* arg_list  */
  YYSYMBOL_primary = 60                    /* primary  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
       2,     2,     2,    38,     2,     2,     2,    29,     2,     2,
      32,    33,    27,    25,    34,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      23,    22,    24,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   126,   127,   131,   132,   133,   138,   158,
     159,   163,   164,   169,   182,   183,   187,   188,   189,   190,
     191,   192,   193,   198,   204,   225,   226,   240,   260,   298,
     309,   315,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   331,   332,   334,   335,   339,
     351,   352,   356,   357,   361,   362,   363,   364,   365,   366
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TRAINER", "POKEBALL",
  "BATTLE", "ELSE", "TALLGRASS", "JOURNEY", "SHOUT", "EVOLVE", "TRUE",
  "FALSE", "IDENT", "NUMBER", "STRING", "EQ", "NE", "LE", "GE", "AND",
  "OR", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS",
  "NOT", "'('", "')'", "','", "';'", "'{'", "'}'", "'!'", "$accept",
  "program", "items", "item", "func_decl", "opt_param_list", "param_list",
  "var_decl", "block", "stmt", "print", "if", "opt_else", "while", "for",
  "for_init", "return", "expr", "call", "opt_arg_list", "arg_list",
  "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,    -9,     3,     6,     8,     9,    10,    -1,   -94,   -94,
     -17,   -94,   -94,    -1,    -1,    59,    -1,    17,   137,   -94,
     -94,   -94,   -94,   -94,     4,   -94,   -94,   -94,    21,   160,
     -94,   -94,    25,    37,    -1,    -1,    22,    -1,   310,    -1,
      -1,   -94,   220,   -94,   101,   -94,   -94,   -94,   -94,   -94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   -94,    47,    -1,   238,   256,    48,    30,
     274,   310,   310,    42,    43,   -94,   -94,   350,   350,    -6,
      -6,   338,   324,    -6,    -6,     7,     7,   -94,   -94,   -94,
     -94,    45,    46,   180,    40,    40,    57,    -1,   -94,   -94,
      -1,    40,    68,   -94,    76,   -94,    -1,   200,   310,   -94,
     -94,    40,   -94,   310,    -1,   -94,   292,    40,   -94
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
      58,    54,    55,     0,     0,     0,     0,     0,     2,     4,
       5,     6,    22,     7,     0,    17,    18,    19,     0,     0,
      47,    48,     0,     0,     0,     0,     0,     0,    30,     0,
      50,    45,     0,    15,     0,    46,     1,     3,    16,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     9,     0,     0,     0,     0,     0,
       0,    31,    52,     0,    51,    59,    14,    34,    35,    38,
      39,    33,    32,    36,    37,    40,    41,    42,    43,    44,
      11,     0,    10,     0,     0,     0,     0,     0,    23,    49,
       0,     0,     0,    13,    25,    27,     0,     0,    53,     8,
      12,     0,    24,    29,     0,    26,     0,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,    69,   -15,   -94,   -94,   -94,   -94,   -93,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,    -7,   -94,   -94,
     -94,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    17,    18,    19,    20,    91,    92,    21,    22,    23,
      24,    25,   112,    26,    27,    69,    28,    29,    30,    73,
      74,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,   104,   105,    47,    32,    39,    41,    42,   109,    45,
       8,     9,    10,    11,    12,    40,    33,    46,   115,    58,
      59,    60,    61,    62,   118,    13,    68,    66,    67,    47,
      70,    14,    71,    72,    60,    61,    62,    16,    34,    48,
      35,    36,    37,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    49,    64,    93,    65,
      90,    96,     1,     2,     3,    97,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    99,    15,   100,   101,   106,
     102,   110,   111,     0,    44,    13,     0,     0,     0,     0,
     107,    14,     0,   108,     0,    15,    43,    16,     0,   113,
       0,     0,     0,     0,     1,     2,     3,   116,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    15,    76,    16,
       1,     2,     3,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,    16,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,    63,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,   103,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,   114,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,    75,    50,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,    94,    50,    51,    52,    53,    54,    55,     0,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,    95,
      50,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,    98,    50,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,   117,    50,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      50,    51,    52,    53,    54,     0,     0,    56,    57,    58,
      59,    60,    61,    62,    50,    51,    52,    53,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    52,    53,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    62
};

static const yytype_int8 yycheck[] =
{
       7,    94,    95,    18,    13,    22,    13,    14,   101,    16,
      11,    12,    13,    14,    15,    32,    13,     0,   111,    25,
      26,    27,    28,    29,   117,    26,     4,    34,    35,    44,
      37,    32,    39,    40,    27,    28,    29,    38,    32,    35,
      32,    32,    32,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    35,    32,    65,    22,
      13,    13,     3,     4,     5,    35,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    33,    36,    34,    33,    22,
      34,    13,     6,    -1,    15,    26,    -1,    -1,    -1,    -1,
      97,    32,    -1,   100,    -1,    36,    37,    38,    -1,   106,
      -1,    -1,    -1,    -1,     3,     4,     5,   114,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    -1,    38,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    33,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    33,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    33,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    33,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    33,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      16,    17,    18,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    26,    32,    36,    38,    40,    41,    42,
      43,    46,    47,    48,    49,    50,    52,    53,    55,    56,
      57,    60,    13,    13,    32,    32,    32,    32,    56,    22,
      32,    56,    56,    37,    41,    56,     0,    42,    35,    35,
      16,    17,    18,    19,    20,    21,    23,    24,    25,    26,
      27,    28,    29,    35,    32,    22,    56,    56,     4,    54,
      56,    56,    56,    58,    59,    33,    37,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      13,    44,    45,    56,    33,    33,    13,    35,    33,    33,
      34,    33,    34,    35,    47,    47,    22,    56,    56,    47,
      13,     6,    51,    56,    35,    47,    56,    33,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    44,
      44,    45,    45,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    51,    51,    52,    53,    54,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     0,
       1,     1,     3,     5,     3,     2,     2,     1,     1,     1,
       2,     2,     1,     4,     6,     0,     2,     5,     9,     4,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     4,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     3
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
  case 2: /* program: items  */
#line 108 "parser.y"
          {
      /* junta tudo gerado pelas regras */
      append(&G_OUT, (yyvsp[0].str));

      /* se houver uma função def main(...), adiciona auto-execução em Python */
      if (G_OUT && strstr(G_OUT, "def main(") != NULL) {
          append(&G_OUT, "\n\nif __name__ == '__main__':\n");
          append(&G_OUT, "    main()\n");
      }

      if (!yyout) yyout = stdout;
      fprintf(yyout, "%s\n", G_OUT ? G_OUT : "");
      free(G_OUT); G_OUT = NULL;
      free((yyvsp[0].str));
    }
#line 1329 "parser.tab.c"
    break;

  case 3: /* items: items item  */
#line 126 "parser.y"
                         { (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str)); free((yyvsp[-1].str)); free((yyvsp[0].str)); }
#line 1335 "parser.tab.c"
    break;

  case 4: /* items: item  */
#line 127 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1341 "parser.tab.c"
    break;

  case 5: /* item: func_decl  */
#line 131 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1347 "parser.tab.c"
    break;

  case 6: /* item: var_decl  */
#line 132 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1353 "parser.tab.c"
    break;

  case 7: /* item: stmt  */
#line 133 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1359 "parser.tab.c"
    break;

  case 8: /* func_decl: TRAINER IDENT '(' opt_param_list ')' block  */
#line 139 "parser.y"
      {
        /* $6 é o corpo sem chaves */
        char* body = indent_block((yyvsp[0].str));
        char* hdr  = cat3("def ", (yyvsp[-4].str), "(");
        char* hdr2 = cat3(hdr, (yyvsp[-2].str) ? (yyvsp[-2].str) : "", "):\n");
        char* all  = cat2(hdr2, body);

        (yyval.str) = all;

        free(hdr);
        free(hdr2);
        free(body);
        free((yyvsp[-4].str));
        if((yyvsp[-2].str)) free((yyvsp[-2].str));
        if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1380 "parser.tab.c"
    break;

  case 9: /* opt_param_list: %empty  */
#line 158 "parser.y"
                         { (yyval.str) = NULL; }
#line 1386 "parser.tab.c"
    break;

  case 10: /* opt_param_list: param_list  */
#line 159 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1392 "parser.tab.c"
    break;

  case 11: /* param_list: IDENT  */
#line 163 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1398 "parser.tab.c"
    break;

  case 12: /* param_list: param_list ',' IDENT  */
#line 164 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), ", ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1404 "parser.tab.c"
    break;

  case 13: /* var_decl: POKEBALL IDENT '=' expr ';'  */
#line 170 "parser.y"
      {
        char* t = cat3((yyvsp[-3].str), " = ", (yyvsp[-1].str));
        char* u = cat2(t, "\n");
        free(t);
        free((yyvsp[-3].str));
        free((yyvsp[-1].str));
        (yyval.str) = u;
      }
#line 1417 "parser.tab.c"
    break;

  case 14: /* block: '{' items '}'  */
#line 182 "parser.y"
                         { (yyval.str) = (yyvsp[-1].str); }
#line 1423 "parser.tab.c"
    break;

  case 15: /* block: '{' '}'  */
#line 183 "parser.y"
                         { (yyval.str) = NULL; }
#line 1429 "parser.tab.c"
    break;

  case 16: /* stmt: print ';'  */
#line 187 "parser.y"
                         { char* t = cat2((yyvsp[-1].str), "\n"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1435 "parser.tab.c"
    break;

  case 17: /* stmt: if  */
#line 188 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1441 "parser.tab.c"
    break;

  case 18: /* stmt: while  */
#line 189 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1447 "parser.tab.c"
    break;

  case 19: /* stmt: for  */
#line 190 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1453 "parser.tab.c"
    break;

  case 20: /* stmt: return ';'  */
#line 191 "parser.y"
                         { char* t = cat2((yyvsp[-1].str), "\n"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1459 "parser.tab.c"
    break;

  case 21: /* stmt: expr ';'  */
#line 192 "parser.y"
                         { char* t = cat2((yyvsp[-1].str), "\n"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1465 "parser.tab.c"
    break;

  case 22: /* stmt: block  */
#line 193 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1471 "parser.tab.c"
    break;

  case 23: /* print: SHOUT '(' expr ')'  */
#line 199 "parser.y"
      { char* t = cat3("print(", (yyvsp[-1].str), ")"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1477 "parser.tab.c"
    break;

  case 24: /* if: BATTLE '(' expr ')' block opt_else  */
#line 205 "parser.y"
      {
        char* body = indent_block((yyvsp[-1].str));
        char* hdr  = cat3("if ", (yyvsp[-3].str), ":\n");
        char* u    = cat2(hdr, body);
        char* v    = (yyvsp[0].str) ? cat2(u, (yyvsp[0].str)) : u;

        (yyval.str) = v;

        free(hdr);
        free(body);
        free((yyvsp[-3].str));
        if((yyvsp[-1].str)) free((yyvsp[-1].str));
        if((yyvsp[0].str)){
          free(u);
          free((yyvsp[0].str));
        }
      }
#line 1499 "parser.tab.c"
    break;

  case 25: /* opt_else: %empty  */
#line 225 "parser.y"
                         { (yyval.str) = NULL; }
#line 1505 "parser.tab.c"
    break;

  case 26: /* opt_else: ELSE block  */
#line 227 "parser.y"
      {
        char* body = indent_block((yyvsp[0].str));
        char* hdr  = strclone("else:\n");
        char* all  = cat2(hdr, body);
        (yyval.str) = all;
        free(hdr);
        free(body);
        if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1519 "parser.tab.c"
    break;

  case 27: /* while: TALLGRASS '(' expr ')' block  */
#line 241 "parser.y"
      {
        char* body = indent_block((yyvsp[0].str));
        char* hdr  = cat3("while ", (yyvsp[-2].str), ":\n");
        char* all  = cat2(hdr, body);
        (yyval.str) = all;
        free(hdr);
        free(body);
        free((yyvsp[-2].str));
        if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1534 "parser.tab.c"
    break;

  case 28: /* for: JOURNEY '(' for_init ';' expr ';' expr ')' block  */
#line 261 "parser.y"
      {
        /* init */
        char* init_line = cat2((yyvsp[-6].str), "\n");

        /* corpo do bloco */
        char* body      = indent_block((yyvsp[0].str));

        /* incremento */
        char* inc_line  = cat2((yyvsp[-2].str), "\n");
        char* inc_body  = indent_block(inc_line);

        /* while header */
        char* hdr       = cat3("while ", (yyvsp[-4].str), ":\n");
        char* loop      = cat2(hdr, body);
        char* loop2     = cat2(loop, inc_body);

        /* código final: init + loop */
        char* all       = cat2(init_line, loop2);
        (yyval.str) = all;

        free(init_line);
        free(body);
        free(inc_line);
        free(inc_body);
        free(hdr);
        free(loop);
        free(loop2);

        free((yyvsp[-6].str));
        free((yyvsp[-4].str));
        free((yyvsp[-2].str));
        if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1572 "parser.tab.c"
    break;

  case 29: /* for_init: POKEBALL IDENT '=' expr  */
#line 299 "parser.y"
      {
        char* t = cat3((yyvsp[-2].str), " = ", (yyvsp[0].str));
        free((yyvsp[-2].str));
        free((yyvsp[0].str));
        (yyval.str) = t;
      }
#line 1583 "parser.tab.c"
    break;

  case 30: /* return: EVOLVE expr  */
#line 310 "parser.y"
      { char* t = cat3("return ", (yyvsp[0].str), ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1589 "parser.tab.c"
    break;

  case 31: /* expr: IDENT '=' expr  */
#line 315 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " = ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1595 "parser.tab.c"
    break;

  case 32: /* expr: expr OR expr  */
#line 317 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " or ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1601 "parser.tab.c"
    break;

  case 33: /* expr: expr AND expr  */
#line 318 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " and ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1607 "parser.tab.c"
    break;

  case 34: /* expr: expr EQ expr  */
#line 319 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " == ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1613 "parser.tab.c"
    break;

  case 35: /* expr: expr NE expr  */
#line 320 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " != ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1619 "parser.tab.c"
    break;

  case 36: /* expr: expr '<' expr  */
#line 321 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " < ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1625 "parser.tab.c"
    break;

  case 37: /* expr: expr '>' expr  */
#line 322 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " > ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1631 "parser.tab.c"
    break;

  case 38: /* expr: expr LE expr  */
#line 323 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " <= ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1637 "parser.tab.c"
    break;

  case 39: /* expr: expr GE expr  */
#line 324 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " >= ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1643 "parser.tab.c"
    break;

  case 40: /* expr: expr '+' expr  */
#line 325 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " + ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1649 "parser.tab.c"
    break;

  case 41: /* expr: expr '-' expr  */
#line 326 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " - ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1655 "parser.tab.c"
    break;

  case 42: /* expr: expr '*' expr  */
#line 327 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " * ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1661 "parser.tab.c"
    break;

  case 43: /* expr: expr '/' expr  */
#line 328 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " / ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1667 "parser.tab.c"
    break;

  case 44: /* expr: expr '%' expr  */
#line 329 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " % ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1673 "parser.tab.c"
    break;

  case 45: /* expr: '-' expr  */
#line 331 "parser.y"
                         { char* t = cat3("-", (yyvsp[0].str), ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1679 "parser.tab.c"
    break;

  case 46: /* expr: '!' expr  */
#line 332 "parser.y"
                         { char* t = cat3("not ", (yyvsp[0].str), ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1685 "parser.tab.c"
    break;

  case 47: /* expr: call  */
#line 334 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1691 "parser.tab.c"
    break;

  case 48: /* expr: primary  */
#line 335 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1697 "parser.tab.c"
    break;

  case 49: /* call: IDENT '(' opt_arg_list ')'  */
#line 340 "parser.y"
      {
        char* t = cat3((yyvsp[-3].str), "(", (yyvsp[-1].str) ? (yyvsp[-1].str) : "");
        char* u = cat3(t, ")", "");
        (yyval.str) = u;
        free(t);
        free((yyvsp[-3].str));
        if((yyvsp[-1].str)) free((yyvsp[-1].str));
      }
#line 1710 "parser.tab.c"
    break;

  case 50: /* opt_arg_list: %empty  */
#line 351 "parser.y"
                         { (yyval.str) = NULL; }
#line 1716 "parser.tab.c"
    break;

  case 51: /* opt_arg_list: arg_list  */
#line 352 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1722 "parser.tab.c"
    break;

  case 52: /* arg_list: expr  */
#line 356 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1728 "parser.tab.c"
    break;

  case 53: /* arg_list: arg_list ',' expr  */
#line 357 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), ", ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1734 "parser.tab.c"
    break;

  case 54: /* primary: NUMBER  */
#line 361 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1740 "parser.tab.c"
    break;

  case 55: /* primary: STRING  */
#line 362 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1746 "parser.tab.c"
    break;

  case 56: /* primary: TRUE  */
#line 363 "parser.y"
                         { (yyval.str) = strclone("True"); }
#line 1752 "parser.tab.c"
    break;

  case 57: /* primary: FALSE  */
#line 364 "parser.y"
                         { (yyval.str) = strclone("False"); }
#line 1758 "parser.tab.c"
    break;

  case 58: /* primary: IDENT  */
#line 365 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1764 "parser.tab.c"
    break;

  case 59: /* primary: '(' expr ')'  */
#line 366 "parser.y"
                         { char* t = cat3("(", (yyvsp[-1].str), ")"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1770 "parser.tab.c"
    break;


#line 1774 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 369 "parser.y"

