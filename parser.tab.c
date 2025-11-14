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

/* ===== Helpers de string para geração de código ===== */
static char* strclone(const char* s){ if(!s) return NULL; size_t n=strlen(s); char* r=(char*)malloc(n+1); memcpy(r,s,n+1); return r; }
static char* cat2(const char* a,const char* b){ size_t na=a?strlen(a):0, nb=b?strlen(b):0; char* r=(char*)malloc(na+nb+1); if(a) memcpy(r,a,na); if(b) memcpy(r+na,b,nb); r[na+nb]='\0'; return r; }
static char* cat3(const char* a,const char* b,const char* c){ char* t=cat2(a,b); char* r=cat2(t,c); free(t); return r; }
static void append(char** base, const char* add){ char* t=cat2(*base?*base:"", add?add:""); if(*base) free(*base); *base=t; }

/* Indenta todas as linhas de s com `spaces` espaços, devolve nova string */
static char* indent_text(const char* s, int spaces){
    if(!s) return NULL;
    size_t len = strlen(s);
    /* contador de linhas para estimativa */
    size_t extra = 0;
    for(const char* q = s; *q; ++q) if(*q == '\n') extra++;
    int sp = spaces;
    /* cria prefixo */
    char* prefix = (char*)malloc(sp+1);
    for(int i=0;i<sp;i++) prefix[i]=' ';
    prefix[sp]='\0';
    /* construir resultado: à cada linha não-vazia, adicionar prefixo */
    char* out = (char*)malloc(len + extra*sp + 1 + 16);
    out[0] = '\0';
    char linebuf[4096];
    const char* start = s;
    while(*start){
        const char* nl = strchr(start, '\n');
        size_t linelen;
        if(nl) linelen = nl - start;
        else linelen = strlen(start);
        if(linelen == 0){
            /* linha vazia: apenas adiciona '\n' */
            if(nl){
                strcat(out, "\n");
                start = nl + 1;
                continue;
            } else break;
        }

        if(linelen >= sizeof(linebuf)-1) linelen = sizeof(linebuf)-2;
        memcpy(linebuf, start, linelen);
        linebuf[linelen] = '\0';
        /* concat prefix + linha + '\n' (se houver) */
        char* t = cat3(prefix, linebuf, nl ? "\n" : "");
        char* old = out;
        out = cat2(out, t);
        free(old);
        free(t);
        if(nl) start = nl + 1;
        else break;
    }
    free(prefix);
    return out;
}

/* Indentação */
static char* indent_once(const char* s){ return indent_text(s, 4); }

/* Acumulador do resultado final */
static char* G_OUT = NULL;

int yylex(void);
void yyerror(const char* s){ fprintf(stderr,"[syntax] %s\n", s); }

#line 142 "parser.tab.c"

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
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
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
  YYSYMBOL_if_stmt = 50,                   /* if_stmt  */
  YYSYMBOL_opt_else = 51,                  /* opt_else  */
  YYSYMBOL_while_stmt = 52,                /* while_stmt  */
  YYSYMBOL_for_stmt = 53,                  /* for_stmt  */
  YYSYMBOL_for_init = 54,                  /* for_init  */
  YYSYMBOL_return_stmt = 55,               /* return_stmt  */
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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

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
      33,    34,    27,    25,    35,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
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
       0,   102,   102,   112,   113,   117,   118,   119,   120,   125,
     142,   143,   147,   148,   153,   159,   171,   177,   178,   179,
     180,   181,   182,   183,   189,   196,   217,   218,   233,   249,
     270,   276,   282,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   298,   299,   301,   302,
     306,   315,   316,   320,   321,   325,   326,   327,   328,   329,
     330
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
  "NOT", "';'", "'('", "')'", "','", "'{'", "'}'", "'!'", "$accept",
  "program", "items", "item", "func_decl", "opt_param_list", "param_list",
  "var_decl", "block", "stmt", "print", "if_stmt", "opt_else",
  "while_stmt", "for_stmt", "for_init", "return_stmt", "expr", "call",
  "opt_arg_list", "arg_list", "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,    -9,     4,   -26,   -15,   -13,    -3,   143,   -91,   -91,
     -17,   -91,   -91,   143,   -91,   143,    57,   143,    24,   135,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     295,   -91,   -91,    -1,    13,   143,   143,    22,   143,   295,
     143,   143,   -91,   166,   -91,    99,   -91,   -91,   -91,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,    23,   143,   185,   204,    25,     5,   223,   295,
     295,     6,    20,   -91,   -91,   335,   335,   -14,   -14,   323,
     309,   -14,   -14,    -6,    -6,   -91,   -91,   -91,   -91,     7,
      28,   261,     3,     3,    35,   143,   -91,   -91,   143,     3,
      45,   -91,    53,   -91,   143,   278,   295,   -91,   -91,     3,
     -91,   295,   143,   -91,   242,     3,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    57,    58,
      59,    55,    56,     0,     8,     0,     0,     0,     0,     2,
       4,     5,     6,    23,     7,    17,    18,    19,    20,    21,
      22,    48,    49,     0,     0,     0,     0,     0,     0,    31,
       0,    51,    46,     0,    16,     0,    47,     1,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     0,    32,
      53,     0,    52,    60,    15,    35,    36,    39,    40,    34,
      33,    37,    38,    41,    42,    43,    44,    45,    12,     0,
      11,     0,     0,     0,     0,     0,    24,    50,     0,     0,
       0,    14,    26,    28,     0,     0,    54,     9,    13,     0,
      25,    30,     0,    27,     0,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,    58,   -18,   -91,   -91,   -91,   -91,   -90,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,    -7,   -91,   -91,
     -91,   -91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    18,    19,    20,    21,    89,    90,    22,    23,    24,
      25,    26,   110,    27,    28,    67,    29,    30,    31,    71,
      72,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    48,   102,   103,    33,    40,    42,    35,    43,   107,
      46,    57,    58,    59,    60,    61,    41,    34,    36,   113,
      37,    59,    60,    61,    47,   116,    66,    48,    64,    65,
      38,    68,    62,    69,    70,    63,    88,    95,    94,    16,
      97,    99,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    98,    91,   104,   108,   109,
       1,     2,     3,   100,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,   105,    14,
      15,   106,     0,    16,    44,    17,     0,   111,     0,     0,
       0,     0,     1,     2,     3,   114,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,    14,    15,     0,     0,    16,    74,    17,     1,     2,
       3,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     8,     9,    10,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,    14,    15,    13,
       0,    16,     0,    17,     0,     0,    15,     0,     0,     0,
       0,    17,    49,    50,    51,    52,    53,    54,     0,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,     0,
      73,    49,    50,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,    92,
      49,    50,    51,    52,    53,    54,     0,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,     0,    93,    49,
      50,    51,    52,    53,    54,     0,    55,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,    96,    49,    50,
      51,    52,    53,    54,     0,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,     0,   115,    49,    50,    51,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,     0,     0,   101,    49,    50,    51,    52,    53,    54,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
     112,    49,    50,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,    49,    50,    51,    52,    53,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    49,
      50,    51,    52,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    51,    52,     0,     0,     0,    55,    56,
      57,    58,    59,    60,    61
};

static const yytype_int8 yycheck[] =
{
       7,    19,    92,    93,    13,    22,    13,    33,    15,    99,
      17,    25,    26,    27,    28,    29,    33,    13,    33,   109,
      33,    27,    28,    29,     0,   115,     4,    45,    35,    36,
      33,    38,    33,    40,    41,    22,    13,    32,    13,    36,
      34,    34,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    35,    63,    22,    13,     6,
       3,     4,     5,    35,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    95,    32,
      33,    98,    -1,    36,    37,    38,    -1,   104,    -1,    -1,
      -1,    -1,     3,     4,     5,   112,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    38,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    26,
      -1,    36,    -1,    38,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    16,    17,    18,    19,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    16,
      17,    18,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    26,    32,    33,    36,    38,    40,    41,
      42,    43,    46,    47,    48,    49,    50,    52,    53,    55,
      56,    57,    60,    13,    13,    33,    33,    33,    33,    56,
      22,    33,    56,    56,    37,    41,    56,     0,    42,    16,
      17,    18,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    33,    22,    56,    56,     4,    54,    56,    56,
      56,    58,    59,    34,    37,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    13,    44,
      45,    56,    34,    34,    13,    32,    34,    34,    35,    34,
      35,    32,    47,    47,    22,    56,    56,    47,    13,     6,
      51,    56,    32,    47,    56,    34,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      44,    44,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    51,    52,    53,
      54,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       0,     1,     1,     3,     5,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     6,     0,     2,     5,     9,
       4,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       3
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
#line 102 "parser.y"
          {
      append(&G_OUT, (yyvsp[0].str));
      if (!yyout) yyout = stdout;
      fprintf(yyout, "%s", G_OUT ? G_OUT : "");
      free(G_OUT); G_OUT = NULL;
      free((yyvsp[0].str));
    }
#line 1317 "parser.tab.c"
    break;

  case 3: /* items: items item  */
#line 112 "parser.y"
                         { (yyval.str) = cat2((yyvsp[-1].str), (yyvsp[0].str)); free((yyvsp[-1].str)); free((yyvsp[0].str)); }
#line 1323 "parser.tab.c"
    break;

  case 4: /* items: item  */
#line 113 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1329 "parser.tab.c"
    break;

  case 5: /* item: func_decl  */
#line 117 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1335 "parser.tab.c"
    break;

  case 6: /* item: var_decl  */
#line 118 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1341 "parser.tab.c"
    break;

  case 7: /* item: stmt  */
#line 119 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1347 "parser.tab.c"
    break;

  case 8: /* item: ';'  */
#line 120 "parser.y"
                         { (yyval.str) = strclone(""); }
#line 1353 "parser.tab.c"
    break;

  case 9: /* func_decl: TRAINER IDENT '(' opt_param_list ')' block  */
#line 126 "parser.y"
      {
        char* hdr;
        if ((yyvsp[-2].str))
            hdr = cat3("def ", (yyvsp[-4].str), "(");
        else
            hdr = cat3("def ", (yyvsp[-4].str), "(");
        char* hdr2 = cat3(hdr, (yyvsp[-2].str) ? (yyvsp[-2].str) : "", "):\n");
        /* block já vem indentado uma vez */
        char* all  = cat2(hdr2, (yyvsp[0].str) ? (yyvsp[0].str) : "");
        (yyval.str) = all;
        free(hdr); free(hdr2);
        free((yyvsp[-4].str)); if((yyvsp[-2].str)) free((yyvsp[-2].str)); if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1371 "parser.tab.c"
    break;

  case 10: /* opt_param_list: %empty  */
#line 142 "parser.y"
                         { (yyval.str) = NULL; }
#line 1377 "parser.tab.c"
    break;

  case 11: /* opt_param_list: param_list  */
#line 143 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1383 "parser.tab.c"
    break;

  case 12: /* param_list: IDENT  */
#line 147 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1389 "parser.tab.c"
    break;

  case 13: /* param_list: param_list ',' IDENT  */
#line 148 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), ", ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1395 "parser.tab.c"
    break;

  case 14: /* var_decl: POKEBALL IDENT '=' expr ';'  */
#line 154 "parser.y"
      { char* t = cat3((yyvsp[-3].str), " = ", (yyvsp[-1].str)); char* u = cat3(t, "\n", ""); free(t); free((yyvsp[-3].str)); free((yyvsp[-1].str)); (yyval.str) = u; }
#line 1401 "parser.tab.c"
    break;

  case 15: /* block: '{' items '}'  */
#line 159 "parser.y"
                       {
        char* in = (yyvsp[-1].str); 
        if (!in) {
            /* bloco vazio => pass */
            (yyval.str) = strclone("    pass\n");
        } else {
            /* indentar o conteúdo uma vez */
            char* ind = indent_once(in);
            (yyval.str) = ind;
            free(in);
        }
    }
#line 1418 "parser.tab.c"
    break;

  case 16: /* block: '{' '}'  */
#line 171 "parser.y"
                        { (yyval.str) = strclone("    pass\n"); }
#line 1424 "parser.tab.c"
    break;

  case 17: /* stmt: print  */
#line 177 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1430 "parser.tab.c"
    break;

  case 18: /* stmt: if_stmt  */
#line 178 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1436 "parser.tab.c"
    break;

  case 19: /* stmt: while_stmt  */
#line 179 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1442 "parser.tab.c"
    break;

  case 20: /* stmt: for_stmt  */
#line 180 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1448 "parser.tab.c"
    break;

  case 21: /* stmt: return_stmt  */
#line 181 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1454 "parser.tab.c"
    break;

  case 22: /* stmt: expr  */
#line 182 "parser.y"
                          { char* t = cat3((yyvsp[0].str), "\n", ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1460 "parser.tab.c"
    break;

  case 23: /* stmt: block  */
#line 183 "parser.y"
                          { (yyval.str) = (yyvsp[0].str); }
#line 1466 "parser.tab.c"
    break;

  case 24: /* print: SHOUT '(' expr ')'  */
#line 190 "parser.y"
      { char* t = cat3("print(", (yyvsp[-1].str), ")\n"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1472 "parser.tab.c"
    break;

  case 25: /* if_stmt: BATTLE '(' expr ')' block opt_else  */
#line 197 "parser.y"
      {
        char* hdr = cat3("if ", (yyvsp[-3].str), ":\n");
        char* body = (yyvsp[-1].str) ? (yyvsp[-1].str) : strclone("    pass\n");
        char* mid;
        if ((yyvsp[0].str)) {
            mid = cat2(hdr, body);
            char* all = cat2(mid, (yyvsp[0].str));
            (yyval.str) = all;
            free(mid);
            free(hdr); free(body); free((yyvsp[-3].str)); free((yyvsp[-1].str)); free((yyvsp[0].str));
        } else {
            mid = cat2(hdr, body);
            (yyval.str) = mid;
            free(hdr); free(body); free((yyvsp[-3].str)); free((yyvsp[-1].str));
        }
      }
#line 1493 "parser.tab.c"
    break;

  case 26: /* opt_else: %empty  */
#line 217 "parser.y"
                         { (yyval.str) = NULL; }
#line 1499 "parser.tab.c"
    break;

  case 27: /* opt_else: ELSE block  */
#line 218 "parser.y"
                         {
        /* $2 já vem indentado (começa com 4 espaços) - queremos:
           else:
               <conteúdo do bloco>
        */
        char* hdr = strclone("else:\n");
        char* both = cat2(hdr, (yyvsp[0].str));
        free(hdr);
        (yyval.str) = both;
        free((yyvsp[0].str));
    }
#line 1515 "parser.tab.c"
    break;

  case 28: /* while_stmt: TALLGRASS '(' expr ')' block  */
#line 234 "parser.y"
      {
        char* hdr = cat3("while ", (yyvsp[-2].str), ":\n");
        char* body = (yyvsp[0].str) ? (yyvsp[0].str) : strclone("    pass\n");
        char* all = cat2(hdr, body);
        (yyval.str) = all;
        free(hdr); free(body); free((yyvsp[-2].str)); free((yyvsp[0].str));
      }
#line 1527 "parser.tab.c"
    break;

  case 29: /* for_stmt: JOURNEY '(' for_init ';' expr ';' expr ')' block  */
#line 250 "parser.y"
      {
        /* $3 = init (string sem '\n' necessariamente), $5 = cond, $7 = inc, $9 = block (indentado) */
        char* init = (yyvsp[-6].str) ? cat3((yyvsp[-6].str), "\n", "") : strclone("");
        char* hdr = cat3("while ", (yyvsp[-4].str), ":\n");
        char* body = (yyvsp[0].str) ? (yyvsp[0].str) : strclone("    pass\n");
        /* inserir inc como última instrução do bloco, indentada mais uma vez */
        char* incline = cat3((yyvsp[-2].str), "\n", "");
        char* inc_ind = indent_once(incline); /* inc_ind já com 4 espaços */
        /* body já começa com 4 espaços; concatenar inc_ind ao final de body */
        char* body_with_inc = cat2(body, inc_ind);
        char* all_mid = cat2(hdr, body_with_inc);
        char* all = cat2(init, all_mid);
        (yyval.str) = all;
        free(init); free(hdr); free(body); free(incline); free(inc_ind); free(body_with_inc);
        free((yyvsp[-6].str)); free((yyvsp[-4].str)); free((yyvsp[-2].str)); if((yyvsp[0].str)) free((yyvsp[0].str));
      }
#line 1548 "parser.tab.c"
    break;

  case 30: /* for_init: POKEBALL IDENT '=' expr  */
#line 271 "parser.y"
      { char* t = cat3((yyvsp[-2].str), " = ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1554 "parser.tab.c"
    break;

  case 31: /* return_stmt: EVOLVE expr  */
#line 277 "parser.y"
      { char* t = cat3("return ", (yyvsp[0].str), "\n"); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1560 "parser.tab.c"
    break;

  case 32: /* expr: IDENT '=' expr  */
#line 282 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " = ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1566 "parser.tab.c"
    break;

  case 33: /* expr: expr OR expr  */
#line 284 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " or ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1572 "parser.tab.c"
    break;

  case 34: /* expr: expr AND expr  */
#line 285 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " and ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1578 "parser.tab.c"
    break;

  case 35: /* expr: expr EQ expr  */
#line 286 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " == ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1584 "parser.tab.c"
    break;

  case 36: /* expr: expr NE expr  */
#line 287 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " != ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1590 "parser.tab.c"
    break;

  case 37: /* expr: expr '<' expr  */
#line 288 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " < ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1596 "parser.tab.c"
    break;

  case 38: /* expr: expr '>' expr  */
#line 289 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " > ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1602 "parser.tab.c"
    break;

  case 39: /* expr: expr LE expr  */
#line 290 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " <= ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1608 "parser.tab.c"
    break;

  case 40: /* expr: expr GE expr  */
#line 291 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " >= ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1614 "parser.tab.c"
    break;

  case 41: /* expr: expr '+' expr  */
#line 292 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " + ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1620 "parser.tab.c"
    break;

  case 42: /* expr: expr '-' expr  */
#line 293 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " - ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1626 "parser.tab.c"
    break;

  case 43: /* expr: expr '*' expr  */
#line 294 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " * ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1632 "parser.tab.c"
    break;

  case 44: /* expr: expr '/' expr  */
#line 295 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " / ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1638 "parser.tab.c"
    break;

  case 45: /* expr: expr '%' expr  */
#line 296 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), " % ",  (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1644 "parser.tab.c"
    break;

  case 46: /* expr: '-' expr  */
#line 298 "parser.y"
                         { char* t = cat3("-", (yyvsp[0].str), ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1650 "parser.tab.c"
    break;

  case 47: /* expr: '!' expr  */
#line 299 "parser.y"
                         { /* !x -> not x */ char* t = cat3("not ", (yyvsp[0].str), ""); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1656 "parser.tab.c"
    break;

  case 48: /* expr: call  */
#line 301 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1662 "parser.tab.c"
    break;

  case 49: /* expr: primary  */
#line 302 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1668 "parser.tab.c"
    break;

  case 50: /* call: IDENT '(' opt_arg_list ')'  */
#line 307 "parser.y"
      {
        char* t = cat3((yyvsp[-3].str), "(", (yyvsp[-1].str) ? (yyvsp[-1].str) : "");
        char* u = cat3(t, ")", "");
        (yyval.str) = u; free(t); free((yyvsp[-3].str)); if((yyvsp[-1].str)) free((yyvsp[-1].str));
      }
#line 1678 "parser.tab.c"
    break;

  case 51: /* opt_arg_list: %empty  */
#line 315 "parser.y"
                         { (yyval.str) = NULL; }
#line 1684 "parser.tab.c"
    break;

  case 52: /* opt_arg_list: arg_list  */
#line 316 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1690 "parser.tab.c"
    break;

  case 53: /* arg_list: expr  */
#line 320 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1696 "parser.tab.c"
    break;

  case 54: /* arg_list: arg_list ',' expr  */
#line 321 "parser.y"
                         { char* t = cat3((yyvsp[-2].str), ", ", (yyvsp[0].str)); free((yyvsp[-2].str)); free((yyvsp[0].str)); (yyval.str) = t; }
#line 1702 "parser.tab.c"
    break;

  case 55: /* primary: NUMBER  */
#line 325 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1708 "parser.tab.c"
    break;

  case 56: /* primary: STRING  */
#line 326 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1714 "parser.tab.c"
    break;

  case 57: /* primary: TRUE  */
#line 327 "parser.y"
                         { (yyval.str) = strclone("True"); }
#line 1720 "parser.tab.c"
    break;

  case 58: /* primary: FALSE  */
#line 328 "parser.y"
                         { (yyval.str) = strclone("False"); }
#line 1726 "parser.tab.c"
    break;

  case 59: /* primary: IDENT  */
#line 329 "parser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1732 "parser.tab.c"
    break;

  case 60: /* primary: '(' expr ')'  */
#line 330 "parser.y"
                         { char* t = cat3("(", (yyvsp[-1].str), ")"); free((yyvsp[-1].str)); (yyval.str) = t; }
#line 1738 "parser.tab.c"
    break;


#line 1742 "parser.tab.c"

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

#line 333 "parser.y"


