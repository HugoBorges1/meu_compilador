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

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
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
    INTEGER = 258,                 /* INTEGER  */
    FLOAT = 259,                   /* FLOAT  */
    IDENT = 260,                   /* IDENT  */
    READ_S = 261,                  /* READ_S  */
    READ_E = 262,                  /* READ_E  */
    SHOW_E = 263,                  /* SHOW_E  */
    SHOW_S = 264,                  /* SHOW_S  */
    DECL_IT = 265,                 /* DECL_IT  */
    DECL_FT = 266,                 /* DECL_FT  */
    ICR = 267,                     /* ICR  */
    CMP_AND = 268,                 /* CMP_AND  */
    CMP_OR = 269,                  /* CMP_OR  */
    CMP_MEI = 270,                 /* CMP_MEI  */
    CMP_MAI = 271,                 /* CMP_MAI  */
    DECL_ST = 272,                 /* DECL_ST  */
    IF_S = 273,                    /* IF_S  */
    IF_E = 274,                    /* IF_E  */
    ELSE_S = 275,                  /* ELSE_S  */
    ELSE_E = 276,                  /* ELSE_E  */
    LOOP_S = 277,                  /* LOOP_S  */
    LOOP_E = 278,                  /* LOOP_E  */
    LOOP_P = 279,                  /* LOOP_P  */
    CMP_MAQ = 280,                 /* CMP_MAQ  */
    CMP_DIF = 281,                 /* CMP_DIF  */
    CMP_MEQ = 282,                 /* CMP_MEQ  */
    CMP_IG = 283,                  /* CMP_IG  */
    DECL_BL = 284,                 /* DECL_BL  */
    BOOL_F = 285,                  /* BOOL_F  */
    BOOL_T = 286                   /* BOOL_T  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "sintatico.y"

     int integer;
     float flt;
     char *name;
     Node *node;

#line 102 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
