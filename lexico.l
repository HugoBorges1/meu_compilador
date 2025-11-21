%{
#include <stdio.h>

class Node;

#include "sintatico.tab.h" 
int yyerror(const char *s);

char *build_file_name;
int errorcount=0;
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


[0-9]+ { 
    yylval.integer = atoi(yytext);
    return INTEGER;  
}

[0-9]+\.[0-9]+  { 
    yylval.flt = atof(yytext);
    return FLOAT; 
}
[a-zA-Z_][a-zA-Z_0-9]*  { 
    yylval.name = strndup(yytext, yyleng);
    return IDENT; 
}

.                           { return yytext[0]; }

%%

int yyerror(const char *s) {
    fprintf(stderr, "%d:%d: %s\n", 
        yylineno, 0, s);
    errorcount++;
    return 1;
}

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        fprintf(stderr, "Sintaxe: %s nome_do_programa\n",
            argv[0]);
        return 1;
    }

    build_file_name = argv[1];
    yyin = fopen(build_file_name, "r");
    if (yyin == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s.\n", build_file_name);
        return 1;
    }

    //yydebug = 1;
    yyparse();

    if (yyin)
        fclose(yyin);
    
    return errorcount;
}
