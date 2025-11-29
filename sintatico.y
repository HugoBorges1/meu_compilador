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

std::map<std::string, double> memory_float; 
std::map<std::string, std::map<int, double>> memory_vector_float;

std::map<std::string, bool> memory_bool;
std::map<std::string, std::map<int, bool>> memory_vector_bool;

std::map<std::string, int> read_counts;
std::map<std::string, int> loop_change_counts;
std::map<std::string, int> if_change_counts; 

std::set<std::string> declared_vars;
std::set<std::string> declared_floats;

int inside_loop = 0;
int inside_if = 0;

%}

%define parse.error verbose 

%token READ_S READ_E SHOW_E SHOW_S DECL_IT DECL_FT ICR CMP_AND CMP_OR CMP_MEI CMP_MAI DECL_ST 
%token IF_S IF_E ELSE_S ELSE_E LOOP_S LOOP_E LOOP_P CMP_MAQ CMP_DIF CMP_MEQ CMP_IG DECL_BL BOOL_F BOOL_T
%token<integer> INTEGER
%token<flt> FLOAT
%token<name> IDENT

%type<node> stmts stmt atrib arit expr term factor prog atstring decl if loop comblock exprlog termlog faclog perexpr
%type<node> show varshow rdexpr rditem read indice comp val showITM showLST safeblock ifblock
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
     declared_floats.insert($name);
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
     declared_floats.insert($name);
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
     
     if (inside_loop == 0 && inside_if == 0) {
          if (sVal != "") {
               memory_string[$id] = sVal;
          } 
          else if (declared_floats.count($id)) {
               double val = $at->getDoubleValue();
               memory_float[$id] = val;
          }
          else {
               int val = $at->getIntValue();
               memory_int[$id] = val;
          }
     }

     if (inside_loop > 0) {
          loop_change_counts[$id]++;
     }
     if (inside_if > 0) {
          if_change_counts[$id]++;
     }

     $$ = new Store($id, $at);
}

atrib : IDENT[id] '=' BOOL_T {
     if (inside_loop == 0 && inside_if == 0) {
          memory_bool[$id] = true; 
     }
     
     if (inside_loop > 0) loop_change_counts[$id]++;
     if (inside_if > 0) if_change_counts[$id]++;

     $$ = new Store($id, new ConstBoolean(true));
}

atrib : IDENT[id] '=' BOOL_F {
     if (inside_loop == 0 && inside_if == 0) {
          memory_bool[$id] = false; 
     }
     
     if (inside_loop > 0) loop_change_counts[$id]++;
     if (inside_if > 0) if_change_counts[$id]++;

     $$ = new Store($id, new ConstBoolean(false));
}

atrib : IDENT[id] ']'indice[idx]'[' '=' arit[at] {
     int indexVal = $idx->getIntValue();
     string strVal = $at->getStringValue();
     
     if (inside_loop == 0 && inside_if == 0) {
          if (strVal != "") {
               memory_vector_string[$id][indexVal] = strVal;
          } 
          else if (declared_floats.count($id)) {
               double val = $at->getDoubleValue();
               memory_vector_float[$id][indexVal] = val;
          }
          else {
               int intVal = $at->getIntValue();
               memory_vector_int[$id][indexVal] = intVal;
          }
     }

     if (inside_loop > 0) loop_change_counts[$id]++;
     if (inside_if > 0) if_change_counts[$id]++;

     $$ = new StoreVector($id, $idx, $at, indexVal, true);
}

atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_T {
     int indexVal = $idx->getIntValue();
     
     if (inside_loop == 0 && inside_if == 0) {
          memory_vector_bool[$id][indexVal] = true;
     }

     if (inside_loop > 0) loop_change_counts[$id]++;
     if (inside_if > 0) if_change_counts[$id]++;
     
     $$ = new StoreVector($id, $idx, new ConstBoolean(true), indexVal, true);
}

atrib : IDENT[id] ']'indice[idx]'[' '=' BOOL_F {
     int indexVal = $idx->getIntValue();
     
     if (inside_loop == 0 && inside_if == 0) {
          memory_vector_bool[$id][indexVal] = false;
     }

     if (inside_loop > 0) loop_change_counts[$id]++;
     if (inside_if > 0) if_change_counts[$id]++;
     
     $$ = new StoreVector($id, $idx, new ConstBoolean(false), indexVal, true);
} 

safeblock : { inside_loop++; } comblock[bc] { inside_loop--; $$ = $bc; } ;

loop : LOOP_S INTEGER[lim] ':' DECL_IT IDENT[id] ICR LOOP_E '|' safeblock[bc] '|' {
     $$ = new ForStmt($lim, $id, $bc);
}

loop : LOOP_S exprlog[exl] LOOP_E '|' safeblock[bc] '|' {
     $$ = new LoopStmt($exl, $bc);
}

loop : LOOP_S exprlog[cond] LOOP_E '|' safeblock[bc] LOOP_P '|' {
     $$ = new LoopStmt($cond, $bc);
}

ifblock : { inside_if++; } comblock[bc] { inside_if--; $$ = $bc; } ;

if : IF_S exprlog[cond] IF_E '|' ifblock[bc] '|' {
   $$ = new IfStmt($cond, $bc);
}

if : IF_S exprlog[cond] IF_E '|' ifblock[bT] '|' ELSE_S ifblock[bF] ELSE_E {
   $$ = new IfStmt($cond, $bT, $bF);
}

comblock : comblock[lst] stmt {
     $lst->append($stmt);
     $$ = $lst;
}

comblock : stmt {
     $$ = new Stmts($stmt);
}

exprlog : termlog[trm] { 
     $$ = $trm;
}

exprlog : exprlog[e1] CMP_OR termlog[e2] {
     $$ = new CompOp($e1, "OU", $e2);
}

termlog : faclog[fcl] { 
     $$ = $fcl; 
}

termlog : termlog[t1] CMP_AND faclog[f1] {
     $$ = new CompOp($t1, "E", $f1);
}

faclog : perexpr[prx] { 
     $$ = $prx; 
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
     $$ = (char*)"MAIOR_QUE"; 
}

cmpl : CMP_MEQ { 
     $$ = (char*)"MENOR_QUE"; 
}

cmpl : CMP_IG  { 
     $$ = (char*)"IGUAL_A"; 
}

cmpl : CMP_MAI { 
     $$ = (char*)"MAIOR_OU_IGUAL_A"; 
}

cmpl : CMP_MEI { 
     $$ = (char*)"MENOR_OU_IGUAL_A"; 
}

cmpl : CMP_DIF { 
     $$ = (char*)"DIFERENTE_DE"; 
}

val : INTEGER[i] { 
    $$ = new ConstInteger($i); 
}

val : FLOAT[f] { 
    $$ = new ConstDouble($f); 
}

val : IDENT[id] { 
    int reads = read_counts[$id];
    int loops = loop_change_counts[$id];
    
    if (declared_vars.count($id)) {
        if (memory_int.count($id)) {
             $$ = new Load($id, memory_int[$id], true, reads, loops);
        }
        else if (memory_float.count($id)) {
             double val = memory_float[$id];
             $$ = new Load($id, val, true, reads, loops); 
        } 
        else if (memory_int.count($id)) {
             $$ = new Load($id, memory_int[$id], true, reads, loops);
        } 
        else {
             $$ = new Load($id, 0, false, reads, loops);
        }
    } 
    else {
        $$ = new ConstString($id);
    }
}

val : IDENT[id] ']' indice[idx] '[' { 
    int indexVal = $idx->getIntValue();
    int reads = read_counts[$id];
    int loops = loop_change_counts[$id];
    
    if (memory_vector_int.count($id) && memory_vector_int[$id].count(indexVal)) {
         int val = memory_vector_int[$id][indexVal];
         $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops);
    } 
    else if (memory_vector_float.count($id) && memory_vector_float[$id].count(indexVal)) {
         double val = memory_vector_float[$id][indexVal];
         $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops);
    }
    else if (memory_vector_string.count($id) && memory_vector_string[$id].count(indexVal)) {
         string val = memory_vector_string[$id][indexVal];
         $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops);
    }
    else if (memory_vector_bool.count($id) && memory_vector_bool[$id].count(indexVal)) {
         bool val = memory_vector_bool[$id][indexVal];
         $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops);
    }
    else {
         $$ = new LoadVector($id, $idx, indexVal, 0, false, reads, loops);
    }
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
     read_counts[$id]++; 
     $$ = new ReadVar($typ, $id);
}

rditem : tpvar[typ] '@' IDENT[id] ']' indice[idx] '[' {
       read_counts[$id]++; 
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

show : SHOW_S '{' showLST[lista] '}' SHOW_E {
     $$ = new Print($lista);
}

showLST : showITM[item] {
     $$ = new PrintSeq($item);
}

showLST : showLST[lista] showITM[item] {
     $lista->append($item);    
     $$ = $lista;
}

showITM : atstring[txt] {
     $$ = $txt; 
}

showITM : varshow[var] {
     $$ = $var;
}

varshow : '%' IDENT[id] '\\' {
     int reads = read_counts[$id]; 
     int loops = loop_change_counts[$id];
     int ifs = if_change_counts[$id];

     if (memory_string.count($id)) {
          $$ = new Load($id, memory_string[$id], true, reads, loops, ifs);
     }
     else if (memory_float.count($id)) {
          double val = memory_float[$id];
          $$ = new Load($id, val, true, reads, loops, ifs);
     }
     else if (memory_int.count($id)) {
          $$ = new Load($id, memory_int[$id], true, reads, loops, ifs);
     } 
     else if (memory_bool.count($id)) {
          bool val = memory_bool[$id];
          $$ = new Load($id, val, true, reads, loops, ifs);
     }
     else {
          $$ = new Load($id, 0, false, reads, loops, ifs);
     }
}

varshow : '%' IDENT[id] ']' atstring[ats] '[' '\\' {
     int idx = $ats->getIntValue();
     int reads = read_counts[$id];
     int loops = loop_change_counts[$id];
     int ifs = if_change_counts[$id];

     if (memory_vector_string.count($id) && memory_vector_string[$id].count(idx)) {
          string val = memory_vector_string[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_int.count($id) && memory_vector_int[$id].count(idx)) {
          int val = memory_vector_int[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_float.count($id) && memory_vector_float[$id].count(idx)) {
          double val = memory_vector_float[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true, reads, loops, ifs);
     }
     else if (memory_vector_bool.count($id) && memory_vector_bool[$id].count(idx)) {
          bool val = memory_vector_bool[$id][idx];
          $$ = new LoadVector($id, $ats, idx, val, true, reads, loops, ifs);
     }
     else {
          $$ = new LoadVector($id, $ats, idx, 0, false, reads, loops, ifs);
     }
}

atstring : IDENT[id] {
     $$ = new ConstString($id); 
}

atstring : INTEGER[int] {
     $$ = new ConstInteger($int);
}

atstring : '=' {
     $$ = new ConstString("=");
}

atstring : '@' {
     $$ = new ConstString("@");
}

atstring : ';' {
     $$ = new ConstString(";");
}

atstring : ':' {
     $$ = new ConstString(":");
}


atstring : '(' {
     $$ = new ConstString("(");
}

atstring : ')' {
     $$ = new ConstString(")");
}

atstring : '{' {
     $$ = new ConstString("{");
}

atstring : '}' {
     $$ = new ConstString("}");
}

atstring : '[' {
     $$ = new ConstString("[");
}

atstring : ']' {
     $$ = new ConstString("]");
}

atstring : '+' {
     $$ = new ConstString("+");
}

atstring : '-' {
     $$ = new ConstString("-");
}

atstring : '*' {
     $$ = new ConstString("*");
}

atstring : '/' {
     $$ = new ConstString("/");
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
     int reads = read_counts[$id];
     int loops = loop_change_counts[$id];
     int ifs = if_change_counts[$id];

     if (declared_vars.count($id)) {
        if (memory_string.count($id)) {
             $$ = new Load($id, memory_string[$id], true, reads, loops, ifs);
        }
        else if (memory_float.count($id)) {
             double val = memory_float[$id];
             $$ = new Load($id, val, true, reads, loops, ifs);
        }
        else if (memory_int.count($id)) {
             $$ = new Load($id, memory_int[$id], true, reads, loops, ifs);
        } 
        else {
             $$ = new Load($id, 0, false, reads, loops, ifs);
        }
    } 
    else {
        $$ = new ConstString($id);
    }
}
       
factor : IDENT[id] ']'indice[idx]'[' {
     int indexVal = $idx->getIntValue();
     
     int reads = read_counts[$id];
     int loops = loop_change_counts[$id];
     int ifs = if_change_counts[$id];

     if (memory_vector_string.count($id) && memory_vector_string[$id].count(indexVal)) {
          string val = memory_vector_string[$id][indexVal];
          $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops, ifs);
     }
     else if (memory_vector_float.count($id) && memory_vector_float[$id].count(indexVal)) {
          double val = memory_vector_float[$id][indexVal];
          $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops, ifs);
     }
     else if (memory_vector_int.count($id) && memory_vector_int[$id].count(indexVal)) {
          int val = memory_vector_int[$id][indexVal];
          $$ = new LoadVector($id, $idx, indexVal, val, true, reads, loops, ifs);
     } 
     else {
          $$ = new LoadVector($id, $idx, indexVal, 0, false, reads, loops, ifs);
     }
}

%%