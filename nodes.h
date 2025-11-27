#include<vector>
#include<string>
#include<iostream>
#include<set>
#include<map>

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
    
    virtual int getIntValue() { 
        return 0; 
    }

    virtual string getStringValue() { 
        return ""; 
    }

    friend class Program;
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

        string getStringValue() override {
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

        int getIntValue() override {
            return value;
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
            return value ? "NOTTHELIES" : "NOTTHETRUTH";
        }
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
            return "DeclVar " + type + ":" + name;
        }

        string getName() {
            return name;
        }

        string getType() {
            return type;
        }
};

class Load: public Node {
    protected:
        string name;
        int currentVal; 
        string currentStr; 
        bool isString;    
        bool hasValue;  
    public:
        Load(string name, int val = 0, bool hasVal = false){
            this->name = name;
            this->currentVal = val;
            this->hasValue = hasVal;
            this->isString = false;
        }

        Load(string name, string val, bool hasVal = false){
            this->name = name;
            this->currentStr = val;
            this->hasValue = hasVal;
            this->isString = true;
        }

    string astLabel() override {
        if (hasValue) {
            if (isString)
                return name + "\\n(" + currentStr + ")";
            else
                return name + "\\n(" + to_string(currentVal) + ")";
        }
        else
            return name;
    }
    
    string getName() {
        return name;
    }

    string getStringValue() override {
        return (hasValue && isString) ? currentStr : "";
    }

    int getIntValue() override {
        return (hasValue && !isString) ? currentVal : 0;
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
            return "DeclVector " + type + ":" + name + "]" + to_string(size) + "[";
        }

        string getName() { return name; }

        string getType() { return type; }
        
        int getSize() { return size; }
};

class StoreVector: public Node {
    protected:
        string name;
        int index;     
        bool hasIndex; 
    public:
        StoreVector(string name, Node *idxNode, Node *expr, int resolvedIdx = 0, bool hasIdx = false){
            this->name = name;
            this->index = resolvedIdx;
            this->hasIndex = hasIdx;
            this->append(expr);
        }

        string astLabel() override {
            if (hasIndex) {
                return "store_array " + name + " ]" + to_string(index) + "[";
            }
            return "store_array " + name;
        }

        string getName() { return name; }
        int getIndex() { return index; }
};

class LoadVector: public Node {
    protected:
        string name;
        int resolvedIndex;
        int resolvedInt;
        string resolvedStr; 
        bool resolvedBool;
        
  
        bool isString;      
        bool isBool;       
        bool hasInfo;

    public:
        LoadVector(string name, Node *index){
            this->name = name;
            this->hasInfo = false;
        }

        LoadVector(string name, Node *index, int idxVal, int val, bool info){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedInt = val;
            this->isString = false;
            this->isBool = false;
            this->hasInfo = info;
            
            if (info) this->append(new ConstInteger(val));
        }

        LoadVector(string name, Node *index, int idxVal, string val, bool info){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedStr = val;
            this->isString = true;
            this->isBool = false;
            this->hasInfo = info;

            if (info) this->append(new ConstString(val));
        }

        LoadVector(string name, Node *index, int idxVal, bool val, bool info){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedBool = val;
            this->isString = false;
            this->isBool = true; 
            this->hasInfo = info;
            if (info) this->append(new ConstBoolean(val));
        }

        string astLabel() override {
            return "load_array " + name + " ]" + to_string(resolvedIndex) + "[";
        }

        string getName() { return name; }
        int getIndex() { return resolvedIndex; }

        int getIntValue() override { return (hasInfo && !isString && !isBool) ? resolvedInt : 0; }
        string getStringValue() override { return (hasInfo && isString) ? resolvedStr : ""; }
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

        int getIntValue() override {
            int v1 = children[0]->getIntValue();
            int v2 = children[1]->getIntValue();
            
            if (oper == '+') return v1 + v2;
            if (oper == '-') return v1 - v2;
            if (oper == '*') return v1 * v2;
            if (oper == '/') return v2 != 0 ? v1 / v2 : 0;
            return 0;
        }

        string getStringValue() override {
            if (oper == '+') {
                return children[0]->getStringValue() + children[1]->getStringValue();
            }
            return "";
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

class ForStmt: public Node {
    public:
        ForStmt(string iteratorName, int limit, Node *body) {
            this->append(new VarDecl(iteratorName, "int"));
            this->append(new ConstInteger(limit));
            this->append(body);
        }

        string astLabel() override {
            return "ForLoop";
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

class SemanticVarDecl {
private:
    map<string, string> declaredVars;
    map<string, int> declaredArraySizes; 

    string inferType(Node* n) {
        if (dynamic_cast<ConstBoolean*>(n)) return "bool";
        if (dynamic_cast<ConstInteger*>(n)) return "int";
        if (dynamic_cast<ConstDouble*>(n)) return "float";
        if (dynamic_cast<ConstString*>(n)) return "string";
        if (dynamic_cast<CompOp*>(n)) return "bool";

        if (dynamic_cast<BinaryOp*>(n)) {
            return "not_bool"; 
        }

        Load* load = dynamic_cast<Load*>(n);
        if (load) {
            if (declaredVars.count(load->getName())) return declaredVars[load->getName()];
            return "unknown";
        }

        LoadVector* loadVec = dynamic_cast<LoadVector*>(n);
        if (loadVec) {
            if (declaredVars.count(loadVec->getName())) return declaredVars[loadVec->getName()];
            return "unknown";
        }

        return "unknown";
    }

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
                declaredVars[decl->getName()] = decl->getType();
            }
        }

        VectorDecl *vecDecl = dynamic_cast<VectorDecl*>(n);
        if (vecDecl != NULL){
            if (declaredVars.count(vecDecl->getName()) > 0) {
                cerr << "Erro: Array '" << vecDecl->getName() << "' ja declarado.\n";
            } else {
                declaredVars[vecDecl->getName()] = vecDecl->getType();
                declaredArraySizes[vecDecl->getName()] = vecDecl->getSize();
            }
        }

        Load *load = dynamic_cast<Load*>(n);
        if (load != NULL){
            if (declaredVars.count(load->getName()) == 0) {
                cerr << "Erro Semantico (Linha " << load->getLineNo() << "): Variavel '" << load->getName() << "' usada mas nao declarada.\n";
            }
        }
        
        LoadVector *loadVec = dynamic_cast<LoadVector*>(n);
        if (loadVec != NULL){
            if (declaredVars.count(loadVec->getName()) == 0) {
                cerr << "Erro: Tentativa de ler array '" << loadVec->getName() << "' nao declarado.\n";
            } else {
                if (declaredArraySizes.count(loadVec->getName())) {
                    int size = declaredArraySizes[loadVec->getName()];
                    int idx = loadVec->getIndex();
                    if (idx < 0 || idx >= size) {
                        cerr << "Erro Semantico (Linha " << loadVec->getLineNo() << "): "
                             << "Indice " << idx << " fora dos limites do vetor '" << loadVec->getName() 
                             << "' (Tamanho: " << size << ").\n";
                    }
                }
            }
        }

        Store *store = dynamic_cast<Store*>(n);
        if (store != NULL){
            string varName = store->getName();
             if (declaredVars.count(varName) == 0) {
                cerr << "Erro Semantico (Linha " << store->getLineNo() << "): Tentativa de atribuir valor a '" << varName << "' que nao foi declarada.\n";
            } else {
                string varType = declaredVars[varName];
                
                bool isBoolTarget = (varType == "bool" || varType == "boolean" || varType == "bl");

                if (isBoolTarget) {
                    if (!store->getChildren().empty()) {
                        Node* expr = store->getChildren()[0];
                        string exprType = inferType(expr);

                        if (exprType != "bool") {
                            cerr << "Erro Semantico (Linha " << store->getLineNo() << "): "
                                 << "Variavel booleana '" << varName << "' so pode receber NOTTHELIES ou NOTTHETRUTH (ou expressoes booleanas).\n";
                        }
                    }
                }
            }
        }

        StoreVector *storeVec = dynamic_cast<StoreVector*>(n);
        if (storeVec != NULL){
            string varName = storeVec->getName();
            if (declaredVars.count(varName) == 0) {
                cerr << "Erro: Tentativa de atribuir em array '" << varName << "' nao declarado.\n";
            } else {
                if (declaredArraySizes.count(varName)) {
                    int size = declaredArraySizes[varName];
                    int idx = storeVec->getIndex();
                    if (idx < 0 || idx >= size) {
                        cerr << "Erro Semantico (Linha " << storeVec->getLineNo() << "): "
                             << "Indice " << idx << " fora dos limites do vetor '" << varName 
                             << "' (Tamanho: " << size << ").\n";
                    }
                }

                string varType = declaredVars[varName];
                bool isBoolTarget = (varType == "bool" || varType == "boolean" || varType == "bl");

                if (isBoolTarget) {
                   
                    if (!storeVec->getChildren().empty()) {
                        Node* expr = storeVec->getChildren()[0];
                        string exprType = inferType(expr);

                        if (exprType != "bool") {
                            cerr << "Erro Semantico (Linha " << storeVec->getLineNo() << "): "
                                << "Vetor booleano '" << varName << "' so pode receber valores booleanos.\n";
                        }
                    }
                }
            }
        }
    }

    void printFoundVars(){
        cout << "--- Tabela de Simbolos ---\n";
        for(auto const& [name, type] : declaredVars) {
            cout << "Declarada: " << name << " (" << type << ")\n";
        }
    }
};