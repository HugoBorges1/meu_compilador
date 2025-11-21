%{
#include <stdio.h>
#include "sintatico.tab.h" 
%}

%option yylineno

%%

[ \t\n\r]                   {}
"+"                         { return '+'; }
"-"                         { return '-'; }
"*"                         { return '*'; }
"/"                         { return '/'; }
"("                         { return '('; }
")"                         { return ')'; }
"{"                         { return '{'; }
"}"                         { return '}'; }
"|"                         { return '|'; }
"%"                         { return '%'; }
"\\"                        { return '\\'; }
"@"                         { return '@'; }
":"                         { return ':'; }       

"++"                        { return ICR; }
"RE"                        { return READ_S; }
"AD"                        { return READ_E; }
"SH"                        { return SHOW_S; }
"OW"                        { return SHOW_E; }
"it"                        { return DECL_IT; }
"st"                        { return DECL_ST; }
"ft"                        { return DECL_FT; }
"bl"                        { return DECL_BL; }
"I"                         { return IF_S; }
"F"                         { return IF_E; }
"EL"                        { return ELSE_S; }
"SE"                        { return ELSE_E; }
"LO"                        { return LOOP_S; }
"OP"                        { return LOOP_E; }
"NOTTHETRUTH"               { return BOOL_F; }
"NOTTHELIES"                { return BOOL_T; }
"PARE"                      { return LOOP_P; }


"E"                         { return CMP_AND; }
"OU"                        { return CMP_OR; }
"MAIOR_QUE"                 { return CMP_MAQ; }
"MENOR_QUE"                 { return CMP_MEQ; }
"IGUAL_A"                   { return CMP_IG; }
"DIFERENTE_DE"              { return CMP_DIF; }
"MAIOR_OU_IGUAL_A"          { return CMP_MEI; }
"MENOR_OU_IGUAL_A"          { return CMP_MAI; }


[0-9]+                      { return INTEGER; }
[0-9]+\;[0-9]+              { return FLOAT; }
[a-zA-Z_][a-zA-Z0-9_]*      { return IDENT; }

.                           { return yytext[0]; }

%%
