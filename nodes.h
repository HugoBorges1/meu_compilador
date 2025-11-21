#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

extern int yylineno;

using namespace std;

// Classe base para todos os nós da árvore
class Node {
protected:
    vector<Node*> children;
    int lineno;

public:
    Node() {
        lineno = yylineno;
    }

    // Adiciona um filho à lista de filhos deste nó
    void append(Node *n) {
        if (n != NULL)
            children.push_back(n);
    }

    vector<Node*>& getChildren() {
        return children;
    }

    // Etiqueta para visualização no Graphviz
    virtual string astLabel() {
        return "Node";
    }
};

// --- Estruturas Básicas ---

// Representa um bloco de código (vários comandos)
class Block : public Node {
public:
    string astLabel() override { return "Block"; }
};

// Raiz do programa
class Program : public Node {
public:
    Program(Node *stmts) {
        this->append(stmts);
    }

    // Método recursivo para imprimir a árvore no formato DOT
    void printAstRecursive(Node *n) {
        if (!n) return;
        cout << "N" << (long)n << " [label=\"" << n->astLabel() << "\"];" << endl;

        for (Node *c : n->getChildren()) {
            cout << "N" << (long)n << " -- " << "N" << (long)c << ";" << endl;
            printAstRecursive(c);
        }
    }

    void printAST() {
        cout << "graph AST {" << endl;
        cout << "  node [shape=box, fontname=\"Arial\"];" << endl;
        printAstRecursive(this);
        cout << "}" << endl;
    }

    string astLabel() override { return "Program"; }
};

// --- Declarações ---

// Declaração Simples: it variavel
class VarDecl : public Node {
    string type;
    string name;
public:
    VarDecl(string type, string name) : type(type), name(name) {}
    string astLabel() override { return "Decl: " + type + " " + name; }
};

// Declaração de Vetor: it vetor ]10[
class VectorDecl : public Node {
    string type;
    string name;
    int size;
public:
    VectorDecl(string type, string name, int size) : type(type), name(name), size(size) {}
    string astLabel() override { return "VecDecl: " + type + " " + name + "[" + to_string(size) + "]"; }
};

// --- Variáveis e Literais ---

// Uso de variável (Load)
class Load : public Node {
    string name;
public:
    Load(string name) : name(name) {}
    string astLabel() override { return "Load: " + name; }
};

// Uso de vetor: vetor ]indice[
class VectorLoad : public Node {
    string name;
public:
    VectorLoad(string name, Node* index) : name(name) { this->append(index); }
    string astLabel() override { return "VecLoad: " + name; }
};

// Constantes
class ConstInt : public Node {
    int val;
public:
    ConstInt(int v) : val(v) {}
    string astLabel() override { return to_string(val); }
};

class ConstFloat : public Node {
    float val;
public:
    ConstFloat(float v) : val(v) {}
    string astLabel() override { return to_string(val); }
};

class ConstString : public Node {
    string val;
public:
    ConstString(string v) : val(v) {}
    string astLabel() override { return "\\\"" + val + "\\\""; }
};

class ConstBool : public Node {
    bool val;
public:
    ConstBool(bool v) : val(v) {}
    string astLabel() override { return val ? "TRUE" : "FALSE"; }
};

// --- Operações ---

// Atribuição: var = expr
class Store : public Node {
    string name;
public:
    Store(string name, Node* expr) : name(name) { this->append(expr); }
    string astLabel() override { return "Assign: " + name; }
};

// Atribuição Vetor: var ]idx[ = expr
class VectorStore : public Node {
    string name;
public:
    VectorStore(string name, Node* index, Node* expr) : name(name) {
        this->append(index);
        this->append(expr);
    }
    string astLabel() override { return "VecAssign: " + name; }
};

// Operações Binárias (+, -, *, /, AND, OR, >, <, etc.)
class BinaryOp : public Node {
    string op;
public:
    BinaryOp(Node* left, string op, Node* right) : op(op) {
        this->append(left);
        this->append(right);
    }
    string astLabel() override { return "Op: " + op; }
};

// --- Controle de Fluxo ---

// IF ... EL ... SE
class IfNode : public Node {
public:
    IfNode(Node* cond, Node* thenBlock, Node* elseBlock = nullptr) {
        this->append(cond);
        this->append(thenBlock);
        if (elseBlock) this->append(elseBlock);
    }
    string astLabel() override { return "IF"; }
};

// Loop Definido (FOR): LO 10 : it a++ OP
class ForLoop : public Node {
    int iterations;
    string iteratorName;
public:
    ForLoop(int iter, string iterName, Node* body) : iterations(iter), iteratorName(iterName) {
        this->append(body);
    }
    string astLabel() override { return "FOR (" + to_string(iterations) + "x) iter: " + iteratorName; }
};

// Loop Condicional (WHILE): LO cond OP
class WhileLoop : public Node {
public:
    WhileLoop(Node* cond, Node* body) {
        this->append(cond);
        this->append(body);
    }
    string astLabel() override { return "WHILE"; }
};

class BreakNode : public Node {
public:
    string astLabel() override { return "BREAK"; }
};

// --- Entrada e Saída ---

class PrintNode : public Node {
public:
    PrintNode(Node* content) { this->append(content); }
    string astLabel() override { return "SHOW"; }
};

class ReadNode : public Node {
public:
    ReadNode(Node* targets) { this->append(targets); }
    string astLabel() override { return "READ"; }
};