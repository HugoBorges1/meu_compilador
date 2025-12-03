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

        int getIntValue() override { return (int)value; }
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
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = false;
            this->isBool = false;
            
            if (hasVal) this->append(new ConstInteger(val));
        }

        Load(string name, string val, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentStr = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = true;
            this->isDouble = false;
            this->isBool = false;

            if (hasVal) this->append(new ConstString(val));
        }

        Load(string name, double val, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentDouble = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = true; 
            this->isBool = false;

            if (hasVal) this->append(new ConstDouble(val));
        }

        Load(string name, bool val, bool hasVal = false, int reads = 0, int loops = 0, int ifs = 0){
            this->name = name;
            this->currentBool = val;
            this->hasValue = hasVal;
            this->readCount = reads;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isDouble = false;
            this->isBool = true;

            if (hasVal) this->append(new ConstBoolean(val));
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
        if (hasValue && isDouble) {
            return currentDouble;
        }
        
        if (hasValue && !isString && !isBool) {
            return (double)currentVal;
        }
    
        return 0.0; 
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
        int readCount;
        int loopChangeCount;
        int ifChangeCount;

        bool hasIndex; 
    public:
        StoreVector(string name, Node *idxNode, Node *expr, int resolvedIdx, bool hasIdx, int r=0, int l=0, int i=0){
            this->name = name;
            this->index = resolvedIdx;
            this->hasIndex = hasIdx;
            this->readCount = r;
            this->loopChangeCount = l;
            this->ifChangeCount = i;
            
            this->append(expr);
        }

        string astLabel() override {
            string label = "StoreVector " + name;
            if (hasIndex) {
                label += " ]" + to_string(index) + "[";
            }

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
            this->isDouble = false;
            
            if (info) this->append(new ConstInteger(val));
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
            this->isDouble = false;

            if (info) this->append(new ConstString(val));
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
            
            if (info) this->append(new ConstDouble(val));
        }

        LoadVector(string name, Node *index, int idxVal, bool val, bool info, int loops = 0, int ifs = 0){
            this->name = name;
            this->resolvedIndex = idxVal;
            this->resolvedBool = val;
            this->loopChangeCount = loops;
            this->ifChangeCount = ifs;
            this->isString = false;
            this->isBool = true; 
            this->isDouble = false;
            this->hasInfo = info;

            if (info) this->append(new ConstBoolean(val));
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
            return (hasInfo && !isString && !isDouble && !isBool) ? resolvedInt : 0;
        }

        string getStringValue() override { 
            return (hasInfo && isString) ? resolvedStr : ""; 
        }

        double getDoubleValue() override { 

            if (hasInfo && isDouble) {
                return resolvedDouble;
            }

            if (hasInfo && !isString && !isBool){
                return (double)resolvedInt;
            }
                
            return 0.0; 
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
            if (oper == '/') return (v2 != 0.0) ? (v1 / v2) : 0.0;

            return 0.0;
        }

        string getStringValue() override {
        if (oper == '+') {

            string s1 = children[0]->getStringValue();
            string s2 = children[1]->getStringValue();
            

            bool isS1String = (s1 != "");
            bool isS2String = (s2 != "");


            if (isS1String || isS2String) {
                if (!isS1String) s1 = to_string(children[0]->getIntValue()); 
                if (!isS2String) s2 = to_string(children[1]->getIntValue());
                return s1 + s2;
            }
            double val = this->getDoubleValue(); 

            if (val == (int)val) return to_string((int)val);
            return to_string(val);
        }
        return "";
    }

    char getOper() { return oper; }


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
            return "Compare [" + oper + "]";
        }

        string getOper() { return oper; }
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
            return "TrueBlock";
        }
};

class BlockFalse: public Node {
    protected: 
    public:
        BlockFalse(Node *stmts) {
            this->append(stmts);
        }
        string astLabel() override {
            return "ElseBlock";
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
            return "whileLOOP";
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
            BinaryOp* bin = dynamic_cast<BinaryOp*>(n);
            string leftType = inferType(bin->getChildren()[0]);
            string rightType = inferType(bin->getChildren()[1]);

            if (leftType == "string" || rightType == "string") { 
                return "string"; 
            }
            
            if (leftType == "float" || rightType == "float") {
                return "float"; 
            }
            
            if (leftType == "int" && rightType == "int") {
                return "int"; 
            }
            
            return "unknown";
        }

        Load* load = dynamic_cast<Load*>(n);
        if (load) {
            if (declaredVars.count(load->getName())) {
                return declaredVars[load->getName()];
            }
            return "unknown";
        }

        LoadVector* loadVec = dynamic_cast<LoadVector*>(n);
        if (loadVec) {
            if (declaredVars.count(loadVec->getName())) {
                return declaredVars[loadVec->getName()];
            }
            return "unknown";
        }

        return "unknown";
    }
    bool containsNonStringVariables(Node* n) {
        Load* load = dynamic_cast<Load*>(n);
        if (load) {
            if (declaredVars.count(load->getName())) {
                string type = declaredVars[load->getName()];
                if (type != "string") return true; 
            }
            return false;
        }

        LoadVector* loadVec = dynamic_cast<LoadVector*>(n);
        if (loadVec) {
            if (declaredVars.count(loadVec->getName())) {
                string type = declaredVars[loadVec->getName()];
                if (type != "string") return true;
            }
            return false;
        }

        BinaryOp* bin = dynamic_cast<BinaryOp*>(n);
        if (bin) {
            bool leftBad = containsNonStringVariables(bin->getChildren()[0]);
            bool rightBad = containsNonStringVariables(bin->getChildren()[1]);
            return leftBad || rightBad;
        }

        return false;
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

        BinaryOp *bin = dynamic_cast<BinaryOp*>(n);
        if (bin != NULL) {
            string t1 = inferType(bin->getChildren()[0]);
            string t2 = inferType(bin->getChildren()[1]);

            if (t1 == "string" || t2 == "string") {
                if (bin->getOper() != '+') {
                    cerr << "Erro Semantico (Linha " << bin->getLineNo() << "): "
                         << "Operacao invalida. Strings so suportam concatenacao (+).\n";
                }
            }
        }

        CompOp *comp = dynamic_cast<CompOp*>(n);
        if (comp != NULL) {
            string t1 = inferType(comp->getChildren()[0]);
            string t2 = inferType(comp->getChildren()[1]);

            if ((t1 == "string" && t2 != "string") || (t1 != "string" && t2 == "string")) {
                cerr << "Erro Semantico (Linha " << comp->getLineNo() << "): "
                     << "Comparacao invalida entre " << t1 << " e " << t2 << ".\n";
            }
            
            if ((t1 == "bool" || t2 == "bool") && 
                 comp->getOper() != "IGUAL_A" && 
                 comp->getOper() != "DIFERENTE_DE" &&
                 comp->getOper() != "OU" &&     
                 comp->getOper() != "E")        
            {
                 cerr << "Erro Semantico (Linha " << comp->getLineNo() << "): "
                      << "Booleanos so podem ser comparados com IGUAL ou DIFERENTE.\n";
            }
        }


        if (bin != NULL && bin->getOper() == '/') {
            Node* rightChild = bin->getChildren()[1];
            
            ConstInteger* constInt = dynamic_cast<ConstInteger*>(rightChild);
            if (constInt && constInt->getIntValue() == 0) {
                cerr << "Erro Semantico (Linha " << bin->getLineNo() << "): Divisao por zero detectada.\n";
            }

            ConstDouble* constDbl = dynamic_cast<ConstDouble*>(rightChild);
            if (constDbl && constDbl->getDoubleValue() == 0.0) {
                 cerr << "Erro Semantico (Linha " << bin->getLineNo() << "): Divisao por zero detectada.\n";
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
                
                Node* expr = (!store->getChildren().empty()) ? store->getChildren()[0] : NULL;

                if (varType == "int" && expr != NULL) {
                    string exprType = inferType(expr);
                    if (exprType == "float") {
                        cerr << "Warning (Linha " << store->getLineNo() << "): "
                             << "Atribuicao de float para a variavel inteira '" << varName 
                             << "'. O valor sera truncado.\n";
                        
                    }
                }

                if (varType == "string") {
                    if (expr && containsNonStringVariables(expr)) {
                        cerr << "Erro Semantico (Linha " << store->getLineNo() << "): "
                             << "Variavel string '" << varName << "' nao pode receber variaveis de outros tipos.\n";
                    }
                }

                else if (varType == "bool" || varType == "boolean" || varType == "bl") {
                    if (expr) {
                        string exprType = inferType(expr);
                        if (exprType != "bool") {
                            cerr << "Erro Semantico (Linha " << store->getLineNo() << "): "
                                 << "Variavel booleana '" << varName << "' so pode receber booleanos.\n";
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
                if (declaredArraySizes.count(varName) > 0) {
                    int size = declaredArraySizes[varName];
                    int idx = storeVec->getIndex();
                    if (idx < 0 || idx >= size) {
                        cerr << "Erro Semantico (Linha " << storeVec->getLineNo() << "): "
                             << "Indice " << idx << " fora dos limites.\n";
                    }
                }

                string varType = declaredVars[varName];

                Node* expr = (!storeVec->getChildren().empty()) ? storeVec->getChildren()[0] : NULL;

                if (varType == "int" && expr != NULL) {
                    string exprType = inferType(expr);
                    
                    if (exprType == "float") {
                        cerr << "Warning (Linha " << storeVec->getLineNo() << "): "
                             << "Atribuicao de float para o vetor de inteiros '" << varName 
                             << "'. O valor sera truncado.\n";
                    }
                }

                else if (varType == "string") {
                    if (expr != NULL) {
                        if (containsNonStringVariables(expr)) {
                            cerr << "Erro Semantico (Linha " << storeVec->getLineNo() << "): "
                                 << "Vetor string '" << varName << "' nao pode receber variaveis de outros tipos.\n";
                        }
                    }
                }
                
                else if (varType == "bool" || varType == "boolean" || varType == "bl") {
                    if (expr != NULL) {
                        string exprType = inferType(expr);
                        if (exprType != "bool") {
                            cerr << "Erro Semantico (Linha " << storeVec->getLineNo() << "): "
                                << "Vetor booleano '" << varName << "' so pode receber booleanos.\n";
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