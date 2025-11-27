%{
#include "nodes.h"
#include <map>
#include <string>

int yyerror(const char *s);
int yylex(void);

std::map<std::string, int> memory_int;
std::map<std::string, std::map<int, int>> memory_vector_int;
std::map<std::string, std::string> memory_string;
std::map<std::string, std::map<int, std::string>> memory_vector_string;
std::set<std::string> declared_vars;
std::map<std::string, std::map<int, bool>> memory_vector_bool;

%}

%define parse.error verbose 

%token READ_S READ_E SHOW_E SHOW_S DECL_IT DECL_FT ICR CMP_AND CMP_OR CMP_MEI CMP_MAI DECL_ST 
%token IF_S IF_E ELSE_S ELSE_E LOOP_S LOOP_E LOOP_P CMP_MAQ CMP_DIF CMP_MEQ CMP_IG DECL_BL BOOL_F BOOL_T
%token<integer> INTEGER
%token<flt> FLOAT
%token<name> IDENT

%type<node> stmts stmt atrib arit expr term factor prog atstring decl if loop comblock exprlog termlog faclog perexpr
%type<node> show scont termst mistl string varshow rdexpr rditem read indice comp val
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
     declared_vars.insert($name);
     $$ = new VectorDecl($name, $size, "int");
}

decl : DECL_ST IDENT[name] ']' INTEGER[size] '[' {
     declared_vars.insert($name);
     $$ = new VectorDecl($name, $size, "string");
}

decl : DECL_FT IDENT[name] ']' INTEGER[size] '[' {
     declared_vars.insert($name);
     $$ = new VectorDecl($name, $size, "float");
}

decl : DECL_BL IDENT[name] ']' INTEGER[size] '[' {
     declared_vars.insert($name);
     $$ = new VectorDecl($name, $size, "boolean");
}

decl : DECL_IT IDENT[name] {
     declared_vars.insert($name);
     $$ = new VarDecl($name, "int");
}

decl : DECL_FT IDENT[name] {
     declared_vars.insert($name);
     $$ = new VarDecl($name, "float");
}

decl : DECL_BL IDENT[name] {
     declared_vars.insert($name);
     $$ = new VarDecl($name, "bool");
}

decl : DECL_ST IDENT[name] {
     declared_vars.insert($name);
     $$ = new VarDecl($name, "string");
}

atrib : IDENT[id] '=' arit[at] {
     string sVal = $at->getStringValue();
     if (sVal != "") {
          memory_string[$id] = sVal;
     } else {
          int val = $at->getIntValue(); 
          memory_int[$id] = val;
     }
     $$ = new Store($id, $at);
}

atrib : IDENT[id] '=' BOOL_T {
     $$ = new Store($id,  new ConstBoolean(true));
}

atrib : IDENT[id] '=' BOOL_F {
     $$ = new Store($id,  new ConstBoolean(false));
}

atrib : IDENT[id] ']'indice[idx]'[' '=' arit[at] {
     int indexVal = $idx->getIntValue();
     string strVal = $at->getStringValue();

     if (strVal != "") {
          memory_vector_string[$id][indexVal] = strVal;
          $$ = new StoreVector($id, $idx, $at, indexVal, true);
     } 
     else {
          int intVal = $at->getIntValue();
          memory_vector_int[$id][indexVal] = intVal;
          $$ = new StoreVector($id, $idx, $at, indexVal, true);
     }
}

atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_T {
     int indexVal = $idx->getIntValue();
     memory_vector_bool[$id][indexVal] = true;
     $$ = new StoreVector($id, $idx, new ConstBoolean(true), indexVal, true);
}


atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_F {
     int indexVal = $idx->getIntValue();
     memory_vector_bool[$id][indexVal] = false;
     $$ = new StoreVector($id, $idx, new ConstBoolean(false), indexVal, true);
}  

loop : LOOP_S INTEGER[lim] ':' DECL_IT IDENT[id] ICR LOOP_E '|' comblock[bc] '|' {
     $$ = new ForStmt($id, $lim, $bc);
}

loop : LOOP_S exprlog[exl] LOOP_E '|' comblock[bc] '|' {
     $$ = new LoopStmt($exl, $bc);
}

loop : LOOP_S exprlog[cond] LOOP_E '|' comblock[bc] LOOP_P '|' {
     $$ = new LoopStmt($cond, $bc);
}

if : IF_S exprlog[cond] IF_E '|' comblock[bc] '|' {
   $$ = new IfStmt($cond, $bc);
}

if : IF_S exprlog[cond] IF_E '|' comblock[bT] '|' ELSE_S comblock[bF] ELSE_E {
   $$ = new IfStmt($cond, $bT, $bF);
}

comblock : comblock[lst] stmt {
     $lst->append($stmt);
     $$ = $lst;
}

comblock : stmt {
     $$ = new Stmts($stmt);
}

exprlog : termlog { 
     $$ = $1;
}

exprlog : exprlog[e1] CMP_OR termlog[e2] {
     $$ = new CompOp($e1, "OR", $e2);
}

termlog : faclog { 
     $$ = $1; 
}

termlog : termlog[t1] CMP_AND faclog[f1] {
     $$ = new CompOp($t1, "AND", $f1);
}

faclog : perexpr { 
     $$ = $1; 
}

faclog : comp[cmp] { 
     $$ = $cmp;
}

comp : perexpr[e1] cmpl[op] perexpr[e2] {
     $$ = new CompOp($e1, $op, $e2);
}

perexpr : val[vl] { 
     $$ = $vl; 
}

perexpr : '(' exprlog[exl] ')' { 
     $$ = $exl; 
}

cmpl : CMP_MAQ { 
     $$ = (char*)">"; 
}

cmpl : CMP_MEQ { 
     $$ = (char*)"<"; 
}

cmpl : CMP_IG  { 
     $$ = (char*)"=="; 
}

cmpl : CMP_MAI { 
     $$ = (char*)">="; 
}

cmpl : CMP_MEI { 
     $$ = (char*)"<="; 
}

cmpl : CMP_DIF { 
     $$ = (char*)"!="; 
}

val : INTEGER[i] { 
    $$ = new ConstInteger($i); 
}

val : FLOAT[f] { 
    $$ = new ConstDouble($f); 
}

/* Substitua a regra val : IDENT (linha ~50) */
val : IDENT[id] { 
    if (declared_vars.count($id)) {
        if (memory_string.count($id)) {
             $$ = new Load($id, memory_string[$id], true);
        }
        else if (memory_int.count($id)) {
             $$ = new Load($id, memory_int[$id], true);
        } 
        else {
             $$ = new Load($id);
        }
    } 
    else {
        $$ = new ConstString($id);
    }
}

val : IDENT[id] ']' indice[idx] '[' { 
    $$ = new LoadVector($id, $idx); 
}

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
     int idx = $ats->getIntValue();

     if (memory_vector_string.count($id) && memory_vector_string[$id].count(idx)) {
          string val = memory_vector_string[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true);
     } else if (memory_vector_int.count($id) && memory_vector_int[$id].count(idx)) {
          int val = memory_vector_int[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true);
     } else if (memory_vector_bool.count($id) && memory_vector_bool[$id].count(idx)) {
          bool val = memory_vector_bool[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true);
     } else {
          $$ = new LoadVector($id, $ats, idx, 0, false);
     }
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
    if (declared_vars.count($id)) {
        if (memory_string.count($id)) {
             $$ = new Load($id, memory_string[$id], true);
        }
        else if (memory_int.count($id)) {
             $$ = new Load($id, memory_int[$id], true);
        } 
        else {
             $$ = new Load($id);
        }
    } 
    else {
        $$ = new ConstString($id);
    }
}
       
factor : IDENT[id] ']'indice[idx]'[' {
     int indexVal = $idx->getIntValue();
     
     if (memory_vector_string.count($id) && memory_vector_string[$id].count(indexVal)) {
          string val = memory_vector_string[$id][indexVal];
          $$ = new LoadVector($id, $idx, indexVal, val, true);
     }

     else if (memory_vector_int.count($id) && memory_vector_int[$id].count(indexVal)) {
          int val = memory_vector_int[$id][indexVal];
          $$ = new LoadVector($id, $idx, indexVal, val, true);
     } 
     else {
          $$ = new LoadVector($id, $idx);
     }
}

%%