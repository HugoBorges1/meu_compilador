%{
#include "nodes.h"
int yyerror(const char *s);
int yylex(void);
%}

%define parse.error verbose 

%token READ_S READ_E SHOW_E SHOW_S DECL_IT DECL_FT ICR CMP_AND CMP_OR CMP_MEI CMP_MAI DECL_ST 
%token IF_S IF_E ELSE_S ELSE_E LOOP_S LOOP_E LOOP_P CMP_MAQ CMP_DIF CMP_MEQ CMP_IG DECL_BL BOOL_F BOOL_T
%token<integer> INTEGER
%token<flt> FLOAT
%token<name> IDENT

%type<node> stmts stmt atrib arit expr term factor prog atstring decl if loop comblock exprlog termlog faclog perexpr
%type<node> show scont termst mistl string varshow rdexpr rditem read indice
%type<name> tpvar cmpl

%start prog

%union {
     int integer;
     float flt;
     char *name;
     Node *node;
} 

%%

prog : stmts {    
     Program pg($stmts);
     pg.printAST();

     SemanticVarDecl vd;
     vd.check(&pg);
     vd.printFoundVars();
}                          

stmts : stmts[ss] stmt {
     $ss->append($stmt);
     $$ = $ss;
}

stmts : stmt {
     $$ = new Stmts($stmt);
}

stmt : atrib
     | if
     | show
     | read
     | loop
     | arit
     | decl
     ;

decl : DECL_IT IDENT[name] ']' INTEGER[size] '[' {
     $$ = new VectorDecl($name, $size, "int");
}

decl : DECL_ST IDENT[name] ']' INTEGER[size] '[' {
     $$ = new VectorDecl($name, $size, "string");
}

decl : DECL_FT IDENT[name] ']' INTEGER[size] '[' {
     $$ = new VectorDecl($name, $size, "float");
}

decl : DECL_BL IDENT[name] ']' INTEGER[size] '[' {
     $$ = new VectorDecl($name, $size, "boolean");
}

decl : DECL_IT IDENT[name] {
     $$ = new VarDecl($name, "int");
}

decl : DECL_FT IDENT[name] {
     $$ = new VarDecl($name, "float");
}

decl : DECL_BL IDENT[name] {
     $$ = new VarDecl($name, "bool");
}

decl : DECL_ST IDENT[name] {
     $$ = new VarDecl($name, "string");
}

atrib : IDENT[id] '=' arit[at] {
     $$ = new Store($id, $at);
}

atrib : IDENT[id] '=' BOOL_T {
     $$ = new Store($id,  new ConstBoolean(true));
}

atrib : IDENT[id] '=' BOOL_F {
     $$ = new Store($id,  new ConstBoolean(false));
}

atrib : IDENT[id] ']'indice[idx]'[' '=' arit[at] {
     $$ = new StoreVector($id, $idx, $at);
}

atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_T{
     $$ = new StoreVector($id, $idx, new ConstBoolean(true));
}

atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_F{
     $$ = new StoreVector($id, $idx, new ConstBoolean(false));
}   

loop : LOOP_S INTEGER ':' DECL_IT IDENT ICR LOOP_E '|' comblock '|'
     | LOOP_S exprlog LOOP_E '|' comblock '|'
     | LOOP_S exprlog LOOP_E '|' comblock LOOP_P '|'
     ;

if : IF_S exprlog IF_E '|' comblock '|'
   | IF_S exprlog IF_E '|' comblock '|' ELSE_S comblock ELSE_E
   ;

comblock : comblock stmt
         | stmt
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
    | IDENT ']'indice'['
    ;

read : READ_S '{' rdexpr[rdx] '}' READ_E {
     $$ = new Read($rdx);
}


rdexpr : rditem[itm] {
     $$ = new ReadSeq($itm);
}

rdexpr : rdexpr[lst] rditem[itm] {
     $lst->append($itm);  
     $$ = $lst;
}

rditem : tpvar[typ] '@' IDENT[id] {
     $$ = new ReadVar($typ, $id);
}

rditem : tpvar[typ] '@' IDENT[id] ']' indice[idx] '[' {
       $$ = new ReadVector($typ, $id, $idx);
}

tpvar : DECL_IT {
     $$ = (char*)"int";
}

tpvar : DECL_FT {
     $$ = (char*)"float";
}

tpvar : DECL_ST {
     $$ = (char*)"string";
}
     
tpvar : DECL_BL {
     $$ = (char*)"bool";
}

show : SHOW_S '{' scont[Sseq] '}' SHOW_E {
     $$ = new Print($Sseq);
}

scont : string[str] {
     $$ = $str;
}

scont : termst[trs] {
     $$ = $trs;
}

termst : mistl[msl] {
     $$ = $msl;
}

termst : mistl[msl] string[str] {
     $msl->append($str);
     $$ = $msl;
}

mistl : varshow[vsh] {
     $$ = new PrintSeq($vsh);
}                       

mistl : string[str] varshow[vsh] {
     $str->append($vsh);
     $$ = $str;
}              

mistl : mistl[msl] varshow[vsh] {
     $msl->append($vsh);
     $$ = $msl;
}               

mistl : mistl[msl] string[str] varshow[vsh] {
      $msl->append($str); 
      $msl->append($vsh); 
      $$ = $msl;
}


string : atstring[ats] {
     $$ = new PrintSeq($ats);
}

string : string[str] atstring[ats] {
     $str->append($ats);
     $$ = $str;
}


varshow : '%' IDENT[id] '\\' {
     $$ = new Load($id);
}

varshow : '%' IDENT[id] ']' atstring[ats] '[' '\\' {
     $$ = new LoadVector($id, $ats);
}

atstring : IDENT[id] {
     $$ = new ConstString($id); 
}

atstring : INTEGER[int] {
     $$ = new ConstInteger($int);
}
         
indice : IDENT[id] {
       $$ = new Load($id);
}

indice : INTEGER[int] {
     $$ = new ConstInteger($int);
}
     
arit : expr {
     $$ = $expr; 
}

expr : expr[e1] '+' term {
     $$ = new BinaryOp($e1, '+', $term);
}

expr : expr[e1] '-' term {
     $$ = new BinaryOp($e1, '-', $term);
}

expr : term {
     $$ = $term;
}

term : term[t1] '*' factor {
     $$ = new BinaryOp($t1, '*', $factor);
}

term : term[t1] '/' factor {
     $$ = new BinaryOp($t1, '/', $factor);
}
     
term : factor {
     $$ = $factor;
}

factor : '(' expr ')'{
     $$ = $expr;
}

factor : FLOAT[flt] {
     $$ = new ConstDouble($flt);
}

factor : INTEGER[int]{
     $$ = new ConstInteger($int);
}

factor : IDENT[id] {
     $$ = new Load($id);
}
       
factor : IDENT[id] ']'indice[idx]'[' {
     $$ = new LoadVector($id, $idx);
}

%%