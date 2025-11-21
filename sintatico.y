%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "nodes.h"

int yyerror(const char *s);
int yylex(void);
int errorc = 0;
%}

%define parse.error verbose 

/* Definicao da Union atualizada com boolean */
%union {
     int integer;
     float flt;
     int boolean; /* Adicionado para suportar valores lógicos (0 ou 1) */
     char *name;
     Node *node;
}

/* Tokens com valores tipados */
%token<integer> INTEGER
%token<flt> FLOAT 
%token<name> IDENT
/* Tokens booleanos agora podem ter valor semântico se desejado, 
   mas como são palavras reservadas fixas, podemos tratar direto na regra ou no léxico.
   Aqui vou manter simples, tratando nas regras gramaticais. */

/* Tokens de controle */
%token READ_S READ_E SHOW_E SHOW_S DECL_IT DECL_FT ICR 
%token CMP_AND CMP_OR CMP_MEI CMP_MAI
%token DECL_ST IF_S IF_E ELSE_S ELSE_E LOOP_S LOOP_E LOOP_P 
%token CMP_MAQ CMP_DIF CMP_MEQ CMP_IG DECL_BL BOOL_F BOOL_T

/* Tipos de retorno (Nodes) para os não-terminais */
%type<node> prog stmts stmt decl atrib loop if show read arit
%type<node> cond exprlog termlog faclog comp perexpr cmpl val
%type<node> rdexpr tpvar scont termst mistl string varshow atstring
%type<node> expr term factor comblock

%start prog

%%

/* --- Raiz do Programa --- */
prog : stmts                    
     { 
        if (errorc > 0) {
            // Se houver erro, não imprime a árvore
        } else {
            // Cria a raiz e imprime a AST
            Program *p = new Program($1);
            p->printAST(); 
        }
     }   
     ;                             

/* --- Lista de Comandos --- */
stmts : stmt stmts 
      { 
          // Insere o stmt no início da lista de filhos do bloco stmts
          $2->getChildren().insert($2->getChildren().begin(), $1); 
          $$ = $2; 
      }
      | stmt   
      { 
          // Cria um novo bloco e adiciona o primeiro stmt
          $$ = new Block(); 
          $$->append($1); 
      }
      ;

stmt : atrib { $$ = $1; }
     | if    { $$ = $1; }
     | show  { $$ = $1; }
     | read  { $$ = $1; }
     | loop  { $$ = $1; }
     | arit  { $$ = $1; }
     | decl  { $$ = $1; }
     ;

/* --- Declarações --- */
decl : DECL_IT IDENT ']' INTEGER '[' { $$ = new VectorDecl("int", $2, $4); }
     | DECL_ST IDENT ']' INTEGER '[' { $$ = new VectorDecl("string", $2, $4); }
     | DECL_FT IDENT ']' INTEGER '[' { $$ = new VectorDecl("float", $2, $4); }
     | DECL_BL IDENT ']' INTEGER '[' { $$ = new VectorDecl("bool", $2, $4); }
     | DECL_ST IDENT                 { $$ = new VarDecl("string", $2); }
     | DECL_IT IDENT                 { $$ = new VarDecl("int", $2); }
     | DECL_FT IDENT                 { $$ = new VarDecl("float", $2); }
     | DECL_BL IDENT                 { $$ = new VarDecl("bool", $2); }
     ;

/* --- Atribuições --- */
atrib : IDENT '=' arit                  { $$ = new Store($1, $3); }
      | IDENT ']' atstring '[' '=' arit { $$ = new VectorStore($1, $3, $6); }
      
      /* Atribuições de booleanos usando os tokens específicos */
      | IDENT '=' BOOL_T                { $$ = new Store($1, new ConstBool(true)); }
      | IDENT '=' BOOL_F                { $$ = new Store($1, new ConstBool(false)); }
      | IDENT ']'atstring'[' '=' BOOL_T { $$ = new VectorStore($1, $3, new ConstBool(true)); }
      | IDENT ']'atstring'[' '=' BOOL_F { $$ = new VectorStore($1, $3, new ConstBool(false)); }
      ;

/* --- Loops --- */
loop : LOOP_S INTEGER ':' DECL_IT IDENT ICR LOOP_E '|' comblock '|'
     { 
        // Loop definido (FOR): LO 10 : it a++ OP
        $$ = new ForLoop($2, $5, $9);
     }
     | LOOP_S cond LOOP_E '|' comblock '|'
     { 
        // Loop condicional (WHILE)
        $$ = new WhileLoop($2, $5);
     }
     | LOOP_S cond LOOP_E '|' comblock LOOP_P '|'
     { 
        // Loop condicional com Break (PARE)
        $5->append(new BreakNode());
        $$ = new WhileLoop($2, $5);
     }
     ;

/* --- Condicional IF --- */
if : IF_S cond IF_E '|' comblock '|'
     { $$ = new IfNode($2, $5); }
   | IF_S cond IF_E '|' comblock '|' ELSE_S comblock ELSE_E
     { $$ = new IfNode($2, $5, $8); }
   ;

/* --- Expressões Lógicas --- */
cond : exprlog { $$ = $1; }
     ;

exprlog : termlog { $$ = $1; }
        | exprlog CMP_OR termlog { $$ = new BinaryOp($1, "OR", $3); }
        ;

termlog : faclog { $$ = $1; }
        | termlog CMP_AND faclog { $$ = new BinaryOp($1, "AND", $3); }
        ;

faclog : perexpr { $$ = $1; }
       | comp    { $$ = $1; }
       ;

comp : perexpr cmpl perexpr { $$ = new BinaryOp($1, $2->astLabel(), $3); }
     ;

perexpr : val { $$ = $1; }
        | '(' exprlog ')' { $$ = $2; }
        ;

/* Operadores de Comparação */
cmpl : CMP_MAQ { $$ = new BinaryOp(NULL, ">", NULL); } // Nó dummy para carregar a string
     | CMP_MEQ { $$ = new BinaryOp(NULL, "<", NULL); }
     | CMP_IG  { $$ = new BinaryOp(NULL, "==", NULL); }
     | CMP_MAI { $$ = new BinaryOp(NULL, ">=", NULL); }
     | CMP_MEI { $$ = new BinaryOp(NULL, "<=", NULL); }
     | CMP_DIF { $$ = new BinaryOp(NULL, "!=", NULL); }
     ;

/* Valores Primitivos e Variáveis */
val : INTEGER { $$ = new ConstInt($1); }
    | INTEGER ';' INTEGER { 
        // Suporte a float com sintaxe LIMPO (ex: 2;50)
        float f = (float)$1 + ((float)$3 / 100.0);
        $$ = new ConstFloat(f); 
      }
    | FLOAT   { $$ = new ConstFloat($1); }
    | IDENT   { $$ = new Load($1); }
    | IDENT ']'atstring'[' { $$ = new VectorLoad($1, $3); }
    
    /* Suporte a literais booleanos em expressões */
    | BOOL_T  { $$ = new ConstBool(true); }
    | BOOL_F  { $$ = new ConstBool(false); }
    ;

/* --- Leitura (READ) --- */
read : READ_S '{' rdexpr '}' READ_E { $$ = new ReadNode($3); }
     ;

rdexpr : tpvar '@' IDENT { 
           // Cria um bloco para a leitura
           $$ = new Block();
           // Cria uma declaração implícita/uso para a leitura
           $$->append(new VarDecl("input", $3)); 
       }
       | tpvar '@' IDENT rdexpr { 
           // Adiciona ao bloco existente de leitura
           $4->getChildren().insert($4->getChildren().begin(), new VarDecl("input", $3));
           $$ = $4;
       }
       | tpvar '@' IDENT ']' atstring '[' { 
           $$ = new Block();
           $$->append(new VectorLoad($3, $5));
       }
       | tpvar '@' IDENT ']' atstring '[' rdexpr {
           $7->getChildren().insert($7->getChildren().begin(), new VectorLoad($3, $5));
           $$ = $7;
       }
       ;

tpvar : DECL_IT { $$ = NULL; }
      | DECL_FT { $$ = NULL; }
      | DECL_ST { $$ = NULL; }
      | DECL_BL { $$ = NULL; }
      ;

/* --- Escrita (SHOW) --- */
show : SHOW_S '{' scont '}' SHOW_E { $$ = new PrintNode($3); }
     ;

scont : string { $$ = $1; }
      | termst { $$ = $1; }
      ;

termst : mistl { $$ = $1; }
       | mistl string { 
           $1->append($2);
           $$ = $1;
       }
       ;

mistl : varshow { 
           Block* b = new Block(); 
           b->append($1); 
           $$ = b; 
      }                          
      | string varshow { 
           Block* b = new Block();
           b->append($1); b->append($2);
           $$ = b;
      }                
      | mistl varshow {
           $1->append($2); 
           $$ = $1;
      }                 
      | mistl string varshow {
           $1->append($2); $1->append($3); 
           $$ = $1;
      }         
      ;

string : atstring { 
           // Converte identificador ou número em nó de string literal para impressão
           $$ = new ConstString($1->astLabel()); 
       }
       | string atstring { 
           // Concatenação simplificada para a árvore
           $$ = $1;
       }
       ;

varshow : '%' IDENT '\\' { $$ = new Load($2); }
        | '%' IDENT ']' atstring '[' '\\' { $$ = new VectorLoad($2, $4); }
        ;

atstring : IDENT  { $$ = new Load($1); }
         | INTEGER { $$ = new ConstInt($1); }
         ;

/* --- Aritmética --- */
arit : expr       { $$ = $1; }
     | expr error { $$ = $1; yyerrok; }               
     ;

expr : expr '+' term { $$ = new BinaryOp($1, "+", $3); }
     | expr '-' term { $$ = new BinaryOp($1, "-", $3); }
     | term          { $$ = $1; }
     ;

term : term '*' factor { $$ = new BinaryOp($1, "*", $3); }
     | term '/' factor { $$ = new BinaryOp($1, "/", $3); }
     | factor          { $$ = $1; }
     ;

factor : '(' expr ')'          { $$ = $2; }
       | INTEGER ';' INTEGER   { 
           float f = (float)$1 + ((float)$3 / 100.0);
           $$ = new ConstFloat(f); 
       }
       | FLOAT                 { $$ = new ConstFloat($1); }
       | INTEGER               { $$ = new ConstInt($1); }
       | IDENT                 { $$ = new Load($1); }
       | IDENT ']'atstring'['  { $$ = new VectorLoad($1, $3); }
       ;

comblock : comblock stmt { 
             $1->append($2); 
             $$ = $1; 
         }
         | stmt { 
             $$ = new Block(); 
             $$->append($1); 
         }
         ;

%%
/* Main no lexico.l */