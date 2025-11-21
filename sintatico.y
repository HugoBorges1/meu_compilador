%{
#include <stdio.h>
#include "nodes.h"
int yyerror(const char *s);
int yylex(void);
int errorc = 0;
%}

%define parse.error verbose 

%token<integer> INTEGER
%token<flt> FLOAT 
%token<name> IDENT

%token INTEGER FLOAT IDENT READ_S READ_E SHOW_E SHOW_S DECL_IT DECL_FT ICR CMP_AND CMP_OR CMP_MEI CMP_MAI
%token DECL_ST IF_S IF_E ELSE_S ELSE_E LOOP_S LOOP_E LOOP_P CMP_MAQ CMP_DIF CMP_MEQ CMP_IG DECL_BL BOOL_F BOOL_T

%type<node> factor term expr stmt stmts prog

%start prog

%union {
     int integer;
     float flt;
     char *name;
     Node *node;
} 

%%

prog : stmts                    {if (errorc > 0)
                                    printf("%d erro(s) encontrado(s)\n", errorc);
                                else
                                    printf("Algortimo LIMPO reconhecido\n");
                                }   
     ;                             


stmts : stmt stmts
      | stmt   
      ;

stmt : atrib
     | if
     | show
     | read
     | loop
     | arit
     | decl
     ;

decl : DECL_IT IDENT ']' INTEGER '['
     | DECL_ST IDENT ']' INTEGER '['
     | DECL_FT IDENT ']' INTEGER '['
     | DECL_BL IDENT ']' INTEGER '['
     | DECL_ST IDENT 
     | DECL_IT IDENT
     | DECL_FT IDENT
     | DECL_BL IDENT
     ;

atrib : IDENT '=' arit
      | IDENT ']' atstring '[' '=' arit
      | IDENT '=' BOOL_T
      | IDENT '=' BOOL_F
      | IDENT ']'atstring'[' '=' BOOL_T
      | IDENT ']'atstring'[' '=' BOOL_F
      ;

loop : LOOP_S INTEGER ':' DECL_IT IDENT ICR LOOP_E '|' comblock '|'
     | LOOP_S cond LOOP_E '|' comblock '|'
     | LOOP_S cond LOOP_E '|' comblock LOOP_P '|'
     ;

if : IF_S cond IF_E '|' comblock '|'
   | IF_S cond IF_E '|' comblock '|' ELSE_S comblock ELSE_E
   ;

cond : exprlog
     ;

exprlog : termlog
        | exprlog CMP_OR termlog
        ;

termlog : faclog
        | termlog CMP_AND faclog
        ;

faclog : perexpr
       | comp
       ;

comp : perexpr cmpl perexpr
     ;

perexpr : val
        | '(' exprlog ')'
        ;

cmpl : CMP_MAQ
     | CMP_MEQ
     | CMP_IG
     | CMP_MAI
     | CMP_MEI
     | CMP_DIF
     ;

val : INTEGER
    | FLOAT
    | IDENT
    | IDENT ']'atstring'['
    ;

read : READ_S '{' rdexpr '}' READ_E 
     ;

rdexpr : tpvar '@' IDENT
       | tpvar '@' IDENT rdexpr
       | tpvar '@' IDENT ']' atstring '['
       | tpvar '@' IDENT ']' atstring '[' rdexpr
       ;

tpvar : DECL_IT
      | DECL_FT
      | DECL_ST
      | DECL_BL
      ;

show : SHOW_S '{' scont '}' SHOW_E
     ;

scont : string
      | termst
      ;

termst : mistl
       | mistl string
       ;

mistl : varshow                          
      | string varshow                
      | mistl varshow                 
      | mistl string varshow         
      ;

string : atstring
       | string atstring
       ;

varshow : '%' IDENT '\\'
        | '%' IDENT ']' atstring '[' '\\'
        ;

atstring : IDENT
         | INTEGER
         ;

arit : expr
     | expr error               
     ;

expr : expr '+' term
     | expr '-' term
     | term
     ;

term : term '*' factor
     | term '/' factor
     | factor
     ;

factor : '(' expr ')'
       | FLOAT
       | INTEGER
       | IDENT
       | IDENT ']'atstring'['
       ;

comblock : comblock stmt
         | stmt
         ;

%%

int yywrap(){
    return 1;
}

int yyerror(const char *s) {
    errorc++;
    printf("erro %d: %s\n", errorc, s);
    return 1;
}

int main() {
    yyparse();
}