# 📚 CS50 Lecture 5 - Estruturas de Dados

## 🎯 Visão Geral

Esta semana você aprenderá sobre **estruturas de dados** - formas de organizar dados na memória de maneira eficiente. Pense nisso como diferentes formas de armazenar suas roupas: em pilhas, em gavetas, penduradas, etc.

---

## 📊 O que são Estruturas de Dados?

**Estruturas de dados** são formas de organizar e armazenar informações na memória do computador. Existem muitas maneiras diferentes de fazer isso, cada uma com suas vantagens e desvantagens.

### Tipos Abstratos de Dados
São estruturas que podemos imaginar conceitualmente antes de implementá-las no código.

---

## 🔄 Filas (Queues)

### Conceito
Uma **fila** funciona como a fila do banco: **primeiro a entrar, primeiro a sair** (FIFO - First In First Out).

### Operações Principais
- **Enqueue**: adicionar um item ao final da fila
- **Dequeue**: remover um item do início da fila

### Visualização
```
[1] [2] [3] [4] [5]  ← entrada (enqueue)
 ↑
saída (dequeue)
```

### Código Exemplo
```c
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
}
queue;
```

---

## 📚 Pilhas (Stacks)

### Conceito
Uma **pilha** funciona como uma pilha de pratos: **último a entrar, primeiro a sair** (LIFO - Last In First Out).

### Operações Principais
- **Push**: colocar um item no topo da pilha
- **Pop**: remover um item do topo da pilha

### Visualização
```
       [5]  ← topo (push/pop)
       [4]
       [3]
       [2]
       [1]
```

### Código Exemplo
```c
const int CAPACITY = 50;

typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;
```

---

## 🔧 Redimensionando Arrays

### O Problema
Arrays em C têm tamanho fixo. Se você precisa adicionar mais elementos, precisa criar um array maior e copiar tudo.

### Visualização do Processo

**1. Array Original:**
```
[1] [2] [3]
```

**2. Criar Novo Array Maior:**
```
[1] [2] [3]
[?] [?] [?] [?]  ← novo array com "lixo"
```

**3. Copiar Valores:**
```
[1] [2] [3]
[1] [2] [3] [?]  ← valores copiados
```

**4. Adicionar Novo Valor:**
```
[1] [2] [3]
[1] [2] [3] [4]  ← array completo
```

### Código com `realloc`
```c
// Array de tamanho 3
int *list = malloc(3 * sizeof(int));

// Redimensionar para tamanho 4
int *tmp = realloc(list, 4 * sizeof(int));
list = tmp;

// Adicionar novo número
list[3] = 4;
```

### ⚠️ Desvantagem
- **O(n)** para redimensionar (precisa copiar todos os elementos)
- Usa memória extra temporariamente

---

## 🔗 Listas Encadeadas (Linked Lists)

### Conceito
Uma **lista encadeada** armazena dados em diferentes locais da memória, conectados por **ponteiros**.

### Visualização

**Valores na Memória:**
```
Memória:
[1] → [2] → [3] → NULL
```

**Com Ponteiros:**
```
┌─────┐    ┌─────┐    ┌─────┐
│  1  │───▶│  2  │───▶│  3  │───▶ NULL
└─────┘    └─────┘    └─────┘
```

### Estrutura de um Nó (Node)
```c
typedef struct node
{
    int number;        // valor armazenado
    struct node *next; // ponteiro para o próximo nó
}
node;
```

### Operador Seta (`->`)
O operador `->` é usado para acessar campos de uma struct através de um ponteiro:
```c
n->number = 5;  // equivale a (*n).number = 5
n->next = NULL;
```

### Inserindo no Início (Prepend)
```c
// Criar novo nó
node *n = malloc(sizeof(node));
n->number = 5;
n->next = NULL;

// Inserir no início
n->next = list;
list = n;
```

**Visualização passo a passo:**
```
1. Lista vazia:      NULL

2. Adicionar 1:      [1] → NULL

3. Adicionar 2:      [2] → [1] → NULL

4. Adicionar 3:      [3] → [2] → [1] → NULL
```

### Inserindo no Final (Append)
```c
// Percorrer até o fim
for (node *ptr = list; ptr != NULL; ptr = ptr->next)
{
    if (ptr->next == NULL)
    {
        ptr->next = n;
        break;
    }
}
```

### ⚙️ Complexidade
- **Inserir no início**: O(1) - instantâneo
- **Inserir no final**: O(n) - precisa percorrer toda a lista
- **Buscar**: O(n) - busca linear

### ✅ Vantagens
- Tamanho dinâmico (cresce conforme necessário)
- Inserção rápida no início

### ❌ Desvantagens
- Usa mais memória (ponteiros)
- Não permite acesso direto ao índice
- Busca binária não é possível

---

## 🌳 Árvores Binárias de Busca (Binary Search Trees)

### Conceito
Uma **árvore binária de busca** combina o melhor dos arrays (busca rápida) com listas (tamanho dinâmico).

### Visualização
```
       4
      / \
     3   5
    / \   \
   1   2   7
            \
             6
```

**Regra**: valores menores à esquerda, maiores à direita.

### Estrutura de um Nó
```c
typedef struct node
{
    int number;
    struct node *left;   // filho à esquerda
    struct node *right;  // filho à direita
}
node;
```

### Exemplo de Construção
```c
// Criar raiz
node *tree = NULL;
node *n = malloc(sizeof(node));
n->number = 4;
n->left = NULL;
n->right = NULL;
tree = n;

// Adicionar à esquerda (3 < 4)
n = malloc(sizeof(node));
n->number = 3;
tree->left = n;

// Adicionar à direita (5 > 4)
n = malloc(sizeof(node));
n->number = 5;
tree->right = n;
```

### ⚙️ Complexidade
- **Busca**: O(log n) - quando balanceada
- **Inserção**: O(log n)

### ✅ Vantagens
- Busca muito rápida (quando balanceada)
- Tamanho dinâmico

---

## 📖 Dicionários

**Dicionários** armazenam pares de **chave-valor**, como um dicionário real (palavra → definição).

### Exemplo Conceitual
```
"apple"  → 1
"berry"  → 2
"cherry" → 3
```

---

## #️⃣ Hashing e Tabelas Hash

### Hash Function
Uma **função hash** converte um valor grande em um índice pequeno.

**Exemplo Simples:**
```c
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';  // primeira letra
}
```

**Resultado:**
```
"luigi" → 11 (L é a 11ª letra)
"mario" → 12 (M é a 12ª letra)
```

### Hash Table (Tabela Hash)
Uma **tabela hash** é um array de listas encadeadas.

### Visualização
```
0 (A) →
1 (B) →
...
11 (L) → [Luigi] → [Link] → [Lakitu] → NULL
12 (M) → [Mario] → NULL
...
25 (Z) →
```

### Colisões
Quando dois valores caem no mesmo índice, usamos uma lista encadeada.

### ⚙️ Complexidade
- **Busca**: O(n) no pior caso
- **Busca**: O(1) se bem distribuído

---

## 🌲 Tries

### Conceito
**Tries** são árvores onde cada nó é um array, geralmente usado para armazenar palavras.

### Visualização (palavra "TOAD")
```
       [ T O A D . . . ]
         ↓
       [ O A D . . . ]
         ↓
       [ A D . . . ]
         ↓
       [ D . . . ]
         ↓
       [fim]
```

### Compartilhando Prefixos ("TOAD" e "TOM")
```
       [ T O A D . . . ]
         ↓
       [ O A D M . . ]
         ↓       ↓
    [A D .]   [M .]
      ↓         ↓
    [D .]     [fim]
      ↓
    [fim]
```

### ⚙️ Complexidade
- **Busca**: O(1) - tempo constante!

### ❌ Desvantagem
- Usa **MUITA** memória (26 nós por letra para o alfabeto)

---

## 📊 Comparação de Complexidades

| Estrutura | Busca | Inserção | Memória |
|-----------|-------|----------|---------|
| Array | O(n) | O(n)* | Baixa |
| Lista Encadeada | O(n) | O(1)† | Média |
| Árvore Binária | O(log n) | O(log n) | Média |
| Hash Table | O(n)‡ | O(1) | Alta |
| Trie | O(1) | O(1) | Muito Alta |

\* redimensionar  
† no início  
‡ depende da distribuição

---

## 🎯 Resumo Visual

```
FILA (Queue):     FIFO → [1][2][3][4][5] →
                          ↑           ↑
                       dequeue    enqueue

PILHA (Stack):    LIFO → [5]
                         [4]
                         [3]  ← push/pop
                         [2]
                         [1]

LISTA:            [1]→[2]→[3]→NULL

ÁRVORE:               4
                     / \
                    2   6
                   / \ / \
                  1  3 5  7

HASH TABLE:       A → [Alice]→[Amy]→NULL
                  B → [Bob]→NULL
                  C → [Carol]→NULL

TRIE:             [H]
                   ↓
                  [E]
                   ↓
                  [L]
                   ↓
                  [L]
                   ↓
                  [O]
```

---

## 💡 Dicas Importantes

1. **Sempre libere a memória** com `free()` quando usar `malloc()`
2. **Use `->` para ponteiros** e `.` para structs diretos
3. **Escolha a estrutura certa** para seu problema:
   - Precisa de ordem? → Fila ou Pilha
   - Precisa de busca rápida? → Árvore ou Hash
   - Tem muito texto? → Trie (se tiver memória)
   - Tamanho fixo? → Array
   - Tamanho dinâmico? → Lista

---

## 🔍 Quando Usar Cada Estrutura?

**Array**: Quando você sabe o tamanho e precisa de acesso por índice  
**Lista Encadeada**: Quando o tamanho muda muito  
**Pilha**: Para desfazer ações (Ctrl+Z), navegação de histórico  
**Fila**: Para processamento em ordem (impressora, filas de atendimento)  
**Árvore**: Para busca rápida com dados hierárquicos  
**Hash Table**: Para buscar por chaves (dicionários, caches)  
**Trie**: Para autocompletar palavras, verificação ortográfica

---

## ✨ Próximos Passos

Na próxima semana, você aprenderá Python, onde muitas dessas estruturas já vêm prontas (listas, dicionários, etc.)!

**Continue praticando! 🚀**