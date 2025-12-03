# Front-end do Compilador LIMPO (Linguagem Integrada Modular Programável Ordinária)

## Visão Geral
Este repositório contém a implementação do *front-end* de um compilador para a linguagem **LIMPO**. O projeto é oriundo da matéria de compiladores na universidade.

O sistema utiliza **Flex** para análise léxica, **Bison** para análise sintática e **C++** para a construção da Árvore Sintática Abstrata (AST) e verificação semântica.

## Especificação da Linguagem

### Tipos de Dados e Literais
* **Inteiro (`it`):** Suporta valores numéricos inteiros.
* **Ponto Flutuante (`ft`):** Utiliza o caractere **ponto e vírgula (;)** como separador decimal (ex: `6;54`).
* **String (`st`):** Cadeias de caracteres sem limite de tamanho predefinido .
* **Booleano (`bl`):** Utiliza as palavras reservadas `NOTTHELIES` (verdadeiro) e `NOTTHETRUTH` (falso) .

### Estruturas de Dados
* **Vetores:** A declaração utiliza colchetes invertidos para definição de tamanho.
    * Sintaxe: `tipo nome_variavel ]tamanho[`.

### Controle de Fluxo
* **Condicional:**
    * Estrutura `I ... F` (equivalente ao *if*) e `EL ... SE` (equivalente ao *else*).
    * Operadores de comparação verbosos: `MAIOR_QUE`, `MENOR_QUE`, `IGUAL_A`, `DIFERENTE_DE`.
* **Repetição:**
    * Estrutura `LO ... OP`. Suporta laços condicionais (estilo *while*) e iterativos definidos (estilo *for*).

### Entrada e Saída
* **Leitura:** Bloco `RE { ... } AD`.
* **Impressão:** Bloco `SH { ... } OW`.

## Arquitetura do Compilador

### 1. Análise Léxica (`lexico.l`)
Responsável pela tokenização do código fonte. O analisador gerencia contagem de linhas e identificação de erros de caracteres inválidos.

### 2. Análise Sintática (`sintatico.y`)
Define a gramática livre de contexto e mapeia a memória:
* Mantém mapas em memória (`memory_int`, `memory_float`, etc.) para realizar a avaliação imediata de constantes e expressões durante a análise.
* Constrói a Árvore Sintática Abstrata (AST) através da instanciação de nós C++.

### 3. Árvore Sintática Abstrata e Semântica (`nodes.h`)
Define a hierarquia de classes da AST e encapsula a lógica de verificação semântica na classe `SemanticVarDecl`.

#### Funcionalidades da Análise Semântica:
* **Verificação de Tipos:** Garante consistência em operações (ex: impede operações aritméticas inválidas com strings ou atribuição de tipos incompatíveis).
* **Verificação de Limites:** Realiza validação estática de acesso a vetores, impedindo leitura/escrita em índices fora do tamanho declarado.
* **Detecção de Divisão por Zero:** Identifica e reporta tentativas de divisão por zero literais no código.
* **Verificação de Escopo:** Valida declarações prévias de variáveis e impede redeclarações.

## Profiling Estático

Este front-end é a capacidade de gerar metadados de **profiling** diretamente nos nós da AST. O compilador rastreia a frequência de uso das variáveis dentro de estruturas de controle.

Os nós `Load` e `LoadVector` armazenam e exibem na AST:
* Quantidade de leituras da variável (`changedByRead`).
* Quantidade de modificações dentro de laços de repetição (`changedByFor`).
* Quantidade de modificações dentro de condicionais (`changedByIF`).

Esta funcionalidade permite uma análise visual da complexidade e do comportamento das variáveis ao gerar o grafo da árvore.

## Estrutura de Arquivos

* `lexico.l`: Definições do analisador léxico (Flex).
* `sintatico.y`: Definições da gramática e ações semânticas (Bison).
* `nodes.h`: Definições das classes da AST e verificador semântico (C++).
* `Makefile`: Scripts de compilação e execução.

## Visualização
O compilador gera a saída da AST em formato compatível com **Graphviz**, permitindo a visualização gráfica da estrutura do programa analisado através do método `printAST()`.