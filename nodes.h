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

    virtual double getDoubleValue() { 
        return 0.0; 
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

        double getDoubleValue() override { 
            return (double)value; 
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

        double getDoubleValue() override { 
            return value; 
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
            return "DeclVar " + type + ": " + name;
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
        string currentStr;

        int currentVal; 
        int readCount;
        int loopChangeCount;
        int ifChangeCount;

        double currentDouble;

        bool currentBool; 
        bool isString;    
        bool isDouble;   
        bool isBool;      
        bool hasValue;  

    public:
        Load(string name, int val = 0, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentVal = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = false;
            this->isBool = false;
            
            if (hasVal && loopChangeCount == 0) this->append(new ConstInteger(val));
        }

        Load(string name, string val, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentStr = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->ifChangeCount = ifs;
            this->isString = true;
            this->isDouble = false;
            this->isBool = false;

            if (hasVal && loopChangeCount == 0) this->append(new ConstString(val));
        }

        Load(string name, double val, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentDouble = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = true; 
            this->isBool = false;

            if (hasVal && loopChangeCount == 0) this->append(new ConstDouble(val));
        }

        Load(string name, bool val, bool hasVal = false, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentBool = val;
            this->hasValue = hasVal;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = false;
            this->isBool = true;

            if (hasVal && loopChangeCount == 0) this->append(new ConstBoolean(val));
        }

    string astLabel() override {
        string label = "LoadVar " + name; 
        if (readCount > 0) {
            label += " | changedByRead(" + to_string(readCount) + ")";
        }

        if (loopChangeCount > 0) {
            label += " | changedByFor(" + to_string(loopChangeCount) + ")";
        }

        if (ifChangeCount > 0) {
            label += " | changedByIF(" + to_string(ifChangeCount) + ")";
        }
        return label;
    }
    
    string getName() { 
        return name; 
    }

    string getStringValue() override { 
        return (hasValue && isString) ? currentStr : ""; 
    }

    int getIntValue() override { 
        return (hasValue && !isString && !isDouble && !isBool) ? currentVal : 0; 
    }

    double getDoubleValue() override { 
        return (hasValue && isDouble) ? currentDouble : 0.0;
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
            return "DeclVector " + type + ": " + name + "]" + to_string(size) + "[";
        }

        string getName() { 
            return name; 
        }

        string getType() { 
            return type; 
        }
        
        int getSize() { 
            return size; 
        }
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
                return "StoreVector " + name + " ]" + to_string(index) + "[";
            }
            return "StoreVector " + name;
        }

        string getName() { 
            return name; 
        }

        int getIndex() { 
            return index; 
        }
};

class LoadVector: public Node {
    protected:
        string name;
        string resolvedStr; 

        int resolvedIndex;
        int resolvedInt;
        int readCount;
        int loopChangeCount;
        int ifChangeCount;

        double resolvedDouble;

        bool resolvedBool;
        bool isString;      
        bool isBool;  
        bool isDouble;     
        bool hasInfo;

    public:
        LoadVector(string name, Node *index, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->hasInfo = false;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
        }

        LoadVector(string name, Node *index, int idxVal, int val, bool info, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedInt = val;
            this->hasInfo = info;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isBool = false;
            
            if (info && loopChangeCount == 0) this->append(new ConstInteger(val));
        }

        LoadVector(string name, Node *index, int idxVal, string val, bool info, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedStr = val;
            this->hasInfo = info;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = true;
            this->isBool = false;

            if (info && loopChangeCount == 0) this->append(new ConstString(val));
        }

        LoadVector(string name, Node *index, int idxVal, double val, bool info, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedDouble = val;
            this->hasInfo = info;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isBool = false;
            this->isDouble = true;
            
            if (info && loopChangeCount == 0) this->append(new ConstDouble(val));
        }

        LoadVector(string name, Node *index, int idxVal, bool val, bool info, int loops = 0, int ifs = 0){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedBool = val;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isBool = true; 
            this->hasInfo = info;

            if (info && loopChangeCount == 0) this->append(new ConstBoolean(val));
        }

        string astLabel() override {
            string label = "LoadVector " + name + " ]" + to_string(resolvedIndex) + "[";
            
            if (readCount > 0) {
                label += " | changedByRead(" + to_string(readCount) + ")";
            }

            if (loopChangeCount > 0) {
                label += " | changedByFor(" + to_string(loopChangeCount) + ")";
            }

            if (ifChangeCount > 0) {
                label += " | changedByIF(" + to_string(ifChangeCount) + ")";
            }
            
            return label;
        }

        string getName() { 
            return name; 
        }

        int getIndex() { 
            return resolvedIndex; 
        }

        int getIntValue() override { 
            return (hasInfo && !isString && !isBool) ? resolvedInt : 0; 
        }

        string getStringValue() override { 
            return (hasInfo && isString) ? resolvedStr : ""; 
        }
        double getDoubleValue() override { 
            return (hasInfo && isDouble) ? resolvedDouble : 0.0; 
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

        int getIntValue() override {
            int v1 = children[0]->getIntValue();
            int v2 = children[1]->getIntValue();
            
            if (oper == '+') return v1 + v2;
            if (oper == '-') return v1 - v2;
            if (oper == '*') return v1 * v2;
            if (oper == '/') return v2 != 0 ? v1 / v2 : 0;

            return 0;
        }

        double getDoubleValue() override {
            double v1 = children[0]->getDoubleValue();
            double v2 = children[1]->getDoubleValue();
            
            if (oper == '+') return v1 + v2;
            if (oper == '-') return v1 - v2;
            if (oper == '*') return v1 * v2;
            if (oper == '/') return v2 != 0.0 ? v1 / v2 : 0.0;

            return 0.0;
        }

        string getStringValue() override {
            if (oper == '+') {
                return children[0]->getStringValue() + children[1]->getStringValue();
            }
            return "";
        }
};

class PrintSeq: public Node {
    protected:
    public:
        PrintSeq(Node *n) {
            this->append(n);
        }

        string astLabel() override {
            return "BlockShow";
        }
};

class Print: public Node {
    protected:
    public:
        Print(Node *seq) {
            this->append(seq);
        }
    
    string astLabel() override {
        return "Show";
    }
};

class ReadSeq: public Node {
    protected:
    public:
        ReadSeq(Node *n) { 
            this->append(n); 
        }
        
        string astLabel() override {
            return "ReadBlock";
        }
};

class ReadVector: public Node {
    protected:
        string name;
        string type;
        string indexName; 
    public:
        ReadVector(string type, string name, Node *index) {
            this->type = type;
            this->name = name;
            this->indexName = index->astLabel(); 
        }

        string astLabel() override {
            return "ReadVector (" + type + ") " + name + " ]" + indexName + "[";
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
            return "ReadVar (" + type + ") " + name;
        }
};

class Read: public Node {
    protected:
    public:
        Read(Node *seq) {
            this->append(seq); 
        }
    
        string astLabel() override {
            return "Read";
        }
};

class Stmts: public Node {
    protected:
    public:
        Stmts(Node *expr) {
            this->append(expr);
        }

    string astLabel() override {
        return "Stmts";
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
            return "compare [" + oper + "]";
        }
};

class IfCondition: public Node {
    protected:
    public:
        IfCondition(Node *expression) {
            this->append(expression);
        }
        string astLabel() override {
            return "Condition";
        }
};

class BlockTrue: public Node {
    protected: 
    public:
        BlockTrue(Node *stmts) {
            this->append(stmts);
        }
        string astLabel() override {
            return "True Block";
        }
};

class BlockFalse: public Node {
    protected: 
    public:
        BlockFalse(Node *stmts) {
            this->append(stmts);
        }
        string astLabel() override {
            return "Else Block";
        }
};

class IfStmt: public Node {
    protected: 
    public:
        IfStmt(Node *cond, Node *block) {
            this->append(new IfCondition(cond));
            this->append(new BlockTrue(block));
        }

        IfStmt(Node *cond, Node *blockTrue, Node *blockFalse) {
            this->append(new IfCondition(cond));
            this->append(new BlockTrue(blockTrue));
            this->append(new BlockFalse(blockFalse));
        }

        string astLabel() override {
            return "IF";
        }
};

class ForStmt: public Node {
    protected: 
    public:
        ForStmt(int limit, string iteratorName, Node *body) {
            this->append(new ConstInteger(limit));
            this->append(new VarDecl(iteratorName, "int"));
            this->append(body);
        }

        string astLabel() override {
            return "ForLOOP";
        }
};

class LoopStmt: public Node {
    protected: 
    public:
        LoopStmt(Node *cond, Node *block) {
            this->append(cond);
            this->append(block);
        }

        string astLabel() override {
            return "LOOP";
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
                return "Program";
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