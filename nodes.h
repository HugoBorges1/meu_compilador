#include<vector>
#include<string>
#include<iostream>
#include<set>

extern int yylineno;

using namespace std;

class Program;

class Node{
protected:
    vector<Node*> children;
    int lineno;

public:
    Node() {
        lineno = yylineno;
    }

    int getLineNo() {
        return lineno;
    }

    void append(Node *n) {
        children.push_back(n);
    }

    vector<Node*>& getChildren() {
        return children;
    }

    virtual string astLabel() {
        return "";
    }

    friend class Program;
};

class VarDecl: public Node {
    protected:
        string name;
        string type;
    public:
        VarDecl(string name, string type){
            this->name = name;
            this->type = type;
        }

        string astLabel() override {
            return "decl " + type + " " + name;
        }

        string getName() {
            return name;
        }
};

class Load: public Node {
    protected:
        string name;
    public:
        Load(string name){
            this->name = name;
        }

    string astLabel() override {
        return name;
    }

    
    string getName() {
        return name;
    }
};

class Store: public Node {
    protected:
        string name;
    public:
        Store(string name, Node *expr){
            this->name = name;
            this->append(expr);
        }

        string astLabel() override {
            string r;
            r.append("store ");
            r.append(name);
            return r;
        }

        string getName() {
            return name;
        }
        
};

class VectorDecl: public Node {
    protected:
        string name;
        string type;
        int size;
    public:
        VectorDecl(string name, int size, string type){
            this->name = name;
            this->size = size;
            this->type = type;
        }

        string astLabel() override {
            return "decl_array " + type + " " + name + "[" + to_string(size) + "]";
        }

        string getName() { return name; }
};

class StoreVector: public Node {
    protected:
        string name;
    public:
        StoreVector(string name, Node *index, Node *expr){
            this->name = name;
            this->append(index);
            this->append(expr);  
        }

        string astLabel() override {
            return "store_array " + name;
        }

        string getName() { return name; }
};

class LoadVector: public Node {
    protected:
        string name;
    public:
        LoadVector(string name, Node *index){
            this->name = name;
            this->append(index); 
        }

        string astLabel() override {
            return "load_array " + name;
        }

        string getName() { return name; }
};

class ConstString: public Node {
    protected:
        string value;
    public:
        ConstString(string value) {
            this->value = value;
        }

        string astLabel() override {
            return value; 
        }
};

class ConstInteger: public Node {
    protected:
        int value;
    public:
        ConstInteger(int value) {
            this->value = value;
        }
        
        string astLabel() override {
            return to_string(value);
        }
};

class ConstDouble: public Node {
    protected:
        double value;
    public:
        ConstDouble(double value) {
            this->value = value;
        }

        string astLabel() override {
            return to_string(value);
        }
};

class ConstBoolean: public Node {
    protected:
        bool value;
    public:
        ConstBoolean(bool value) {
            this->value = value;
        }

        string astLabel() override {
            return value ? "true" : "false";
        }
};

class BinaryOp: public Node {
    protected:
        char oper;
    public:
        BinaryOp(Node *left, char oper, Node *right) {
            this->oper = oper;
            this->append(left);
            this->append(right);
        }

        string astLabel() override {
            string r;
            r.push_back(oper);
            return r;
        }
};

class PrintSeq: public Node {
    public:
        PrintSeq(Node *n) {
            this->append(n);
        }

        string astLabel() override {
            return "seq_print";
        }
};

class Print: public Node {
    protected:
    public:
        Print(Node *seq) {
            this->append(seq);
        }
    
    string astLabel() override {
        return "print";
    }
};

class ReadSeq: public Node {
    protected:
    public:
        ReadSeq(Node *n) { 
            this->append(n); 
        }
        
        string astLabel() override {
            return "seq_read";
        }
};

class ReadVector: public Node {
    protected:
        string name;
        string type;
    public:
        ReadVector(string type, string name, Node *index) {
            this->type = type;
            this->name = name;
            this->append(index); 
        }

        string astLabel() override {
            return "read_array (" + type + ") " + name;
        }
};

class ReadVar: public Node {
    protected:
        string name;
        string type;
    public:
        ReadVar(string type, string name) {
            this->type = type;
            this->name = name;
        }

        string astLabel() override {
            return "read_var (" + type + ") " + name;
        }
};

class Read: public Node {
    public:
        Read(Node *seq) {
            this->append(seq); 
        }
    
        string astLabel() override {
            return "read";
        }
};

class Stmts: public Node {
    protected:
    public:
        Stmts(Node *expr) {
            this->append(expr);
        }

    string astLabel() override {
        return "stmts";
    }
};

class Program: public Node {
    protected:
        void printAstRecursive(Node *n) {
            cout << "N" << (long)(n) << 
                    "[label=\"" << n->astLabel() << "\"]" <<
                    "\n";

            for(Node *c : n->children) {
                cout << "N" << (long)(n) << "--" <<
                        "N" << (long)(c) << "\n";
                printAstRecursive(c);
            }
        }
    public:
        Program(Node *stmts) {
            this->append(stmts);
        }

        void printAST(){
            cout << "graph {\n";
            cout << "N" << (long)(this)
                 << "[label=\"Program\"]\n";
            cout << "N" << (long)(this) << "--"
                 << "N" << (long)(children[0])
                 << "\n";
            printAstRecursive(children[0]);
            cout << "}\n";
        }

            string astLabel() override {
                return "program";
            }
};

class CompOp: public Node {
    protected:
        string oper;
    public:
        CompOp(Node *left, string oper, Node *right) {
            this->oper = oper;
            this->append(left);
            this->append(right);
        }

        string astLabel() override {
            return "compare";
        }
};

class IfStmt: public Node {
    public:
        IfStmt(Node *cond, Node *block) {
            this->append(cond);
            this->append(block);
        }

        IfStmt(Node *cond, Node *blockTrue, Node *blockFalse) {
            this->append(cond);
            this->append(blockTrue);
            this->append(blockFalse);
        }

        string astLabel() override {
            return "if";
        }
};

class LoopStmt: public Node {
    public:
        LoopStmt(Node *cond, Node *block) {
            this->append(cond);
            this->append(block);
        }

        string astLabel() override {
            return "Loop";
        }
};

class SemanticVarDecl {
private:
    set<string> declaredVars;
public:
    void check(Node *n){
        for(Node *c : n->getChildren()){
            check(c);
        } 

        VarDecl *decl = dynamic_cast<VarDecl*>(n);
        if (decl != NULL){
            if (declaredVars.count(decl->getName()) > 0) {
                cerr << "Erro Semantico: Variavel '" << decl->getName() << "' ja foi declarada anteriormente.\n";
            } else {
                declaredVars.insert(decl->getName());
            }
        }

        Load *load = dynamic_cast<Load*>(n);
        if (load != NULL){
            if (declaredVars.count(load->getName()) == 0) {
                cerr << "Erro Semantico (Linha " << load->getLineNo() << "): Variavel '" << load->getName() << "' usada mas nao declarada.\n";
            }
        }

        Store *store = dynamic_cast<Store*>(n);
        if (store != NULL){
             if (declaredVars.count(store->getName()) == 0) {
                cerr << "Erro Semantico (Linha " << store->getLineNo() << "): Tentativa de atribuir valor a '" << store->getName() << "' que nao foi declarada.\n";
            }
        }

        VectorDecl *vecDecl = dynamic_cast<VectorDecl*>(n);
        if (vecDecl != NULL){
            if (declaredVars.count(vecDecl->getName()) > 0) {
                cerr << "Erro: Array '" << vecDecl->getName() << "' ja declarado.\n";
            } else {
                declaredVars.insert(vecDecl->getName());
            }
        }

        StoreVector *storeVec = dynamic_cast<StoreVector*>(n);
        if (storeVec != NULL){
            if (declaredVars.count(storeVec->getName()) == 0) {
                cerr << "Erro: Tentativa de atribuir em array '" << storeVec->getName() << "' nao declarado.\n";
            }
        }

        LoadVector *loadVec = dynamic_cast<LoadVector*>(n);
        if (loadVec != NULL){
            if (declaredVars.count(loadVec->getName()) == 0) {
                cerr << "Erro: Tentativa de ler array '" << loadVec->getName() << "' nao declarado.\n";
            }
        }
    }

    void printFoundVars(){
        cout << "--- Tabela de Simbolos ---\n";
        for(string v : declaredVars) {
            cout << "Declarada: " << v << "\n";
        }
    }
};