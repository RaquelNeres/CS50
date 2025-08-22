# Resumo

## Ler arquivo CSV básico
```python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)  # Pula o cabeçalho
    
    for row in reader:
        print(row[1])  # Imprime segunda coluna
```

- `csv.reader()` lê cada linha do arquivo CSV.
- `next(reader)` pula a primeira linha (cabeçalho).
- `row[1]` acessa a segunda coluna (índice 1).


## DictReader - Leitura por nome de coluna
```python
import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    
    for row in reader:
        print(row["language"])  # Usa nome da coluna
```

> **Vantagem**: Não depende da posição da coluna, usa o nome do cabeçalho.

- `csv.DictReader()` trata cada linha como um dicionário.
- `row["language"]` acessa pela chave (nome da coluna).


## Contar ocorrências com dicionário
```python
import csv

counts = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# Imprimir contagens
for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
```

- Cria um dicionário `counts` para armazenar as contagens.
- Verifica se a chave já existe antes de incrementar.
- Usa f-strings para formatação da saída.


## Ordenar contagens
```python
# Ordenar por chave (alfabético)
for favorite in sorted(counts):
    print(f"{favorite}: {counts[favorite]}")

# Ordenar por valor (mais populares primeiro)
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite}: {counts[favorite]}")
```

- `sorted(counts)` ordena alfabeticamente.
- `key=counts.get` ordena pelos valores do dicionário.
- `reverse=True` ordena do maior para o menor.


## Counter - Biblioteca Collections
```python
import csv
from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()
    
    for row in reader:
        counts[row["language"]] += 1

for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
```

> **Counter** simplifica a contagem automática.

- `Counter()` cria um contador especializado.
- `most_common()` retorna os itens ordenados por frequência.


## Conectar ao banco SQLite
```bash
sqlite3 favorites.db
```

```sql
.mode csv
.import favorites.csv favorites
.schema
```

- `sqlite3 favorites.db` abre/cria o banco de dados.
- `.mode csv` configura modo CSV.
- `.import` importa dados do CSV para uma tabela.
- `.schema` mostra a estrutura das tabelas.


## SELECT - Consultar dados
```sql
-- Selecionar todas as colunas
SELECT * FROM favorites;

-- Selecionar coluna específica
SELECT language FROM favorites;

-- Contar registros
SELECT COUNT(*) FROM favorites;

-- Valores únicos
SELECT DISTINCT language FROM favorites;
```

> `SELECT` é o comando fundamental para consultar dados.

- `*` seleciona todas as colunas.
- `COUNT(*)` conta o número de registros.
- `DISTINCT` remove duplicatas.

## WHERE - Filtrar dados
```sql
-- Filtro simples
SELECT COUNT(*) FROM favorites WHERE language = 'C';

-- Múltiplas condições com AND
SELECT COUNT(*) FROM favorites WHERE language = 'C' AND problem = 'Hello, World';

-- Múltiplas condições com OR
SELECT COUNT(*) FROM favorites WHERE language = 'C' OR language = 'Python';

-- Busca por padrão
SELECT COUNT(*) FROM favorites WHERE problem LIKE 'Hello, %';
```

- `WHERE` adiciona condições de filtro.
- `AND` / `OR` combinam múltiplas condições.
- `LIKE` permite busca por padrões (`%` é curinga).

## GROUP BY e ORDER BY
```sql
-- Agrupar por linguagem
SELECT language, COUNT(*) FROM favorites GROUP BY language;

-- Ordenar por contagem (crescente)
SELECT language, COUNT(*) FROM favorites 
GROUP BY language ORDER BY COUNT(*);

-- Ordenar decrescente com alias
SELECT language, COUNT(*) AS n FROM favorites 
GROUP BY language ORDER BY n DESC;

-- Limitar resultados
SELECT language, COUNT(*) AS n FROM favorites 
GROUP BY language ORDER BY n DESC LIMIT 5;
```

- `GROUP BY` agrupa registros por valores iguais.
- `ORDER BY` ordena os resultados.
- `AS` cria um alias (apelido) para a coluna.
- `DESC` ordena em ordem decrescente.
- `LIMIT` limita o número de resultados.


## INSERT - Inserir dados
```sql
INSERT INTO favorites (language, problem) VALUES ('SQL', 'Fiftyville');
```

> `INSERT INTO` adiciona novos registros à tabela.

- Especifica as colunas entre parênteses.
- `VALUES` contém os valores a serem inseridos.


## UPDATE - Atualizar dados
```sql
UPDATE favorites SET language = 'JavaScript' WHERE language = 'JS';
```

> ⚠️ **Cuidado**: Sempre use `WHERE` com `UPDATE` para evitar alterar todos os registros.


## DELETE - Deletar dados
```sql
DELETE FROM favorites WHERE language IS NULL;
```

> ⚠️ **Cuidado**: Sempre use `WHERE` com `DELETE` para evitar apagar todos os registros.


## JOIN - Unir tabelas
```sql
SELECT * FROM shows
JOIN ratings ON shows.id = ratings.show_id
WHERE rating >= 6.0
LIMIT 10;
```

> `JOIN` combina dados de múltiplas tabelas relacionadas.

- `ON` especifica como as tabelas se relacionam.
- Geralmente usa chaves primárias e estrangeiras.


## Consultas aninhadas (Subqueries)
```sql
SELECT title FROM shows
WHERE id IN (
    SELECT show_id FROM ratings
    WHERE rating >= 6.0
    LIMIT 10
);
```

- A consulta interna (`SELECT show_id...`) executa primeiro.
- `IN` verifica se o valor está na lista retornada pela subconsulta.


## Criar índices para performance
```sql
CREATE INDEX title_index ON shows (title);
CREATE INDEX name_index ON people (name);
```

> Índices aceleram consultas mas ocupam mais espaço.

- `CREATE INDEX` cria uma estrutura otimizada para buscas.
- Use em colunas frequentemente consultadas.


## SQL em Python com CS50
```python
from cs50 import SQL

# Conectar ao banco
db = SQL("sqlite:///favorites.db")

# Consulta segura com placeholder
favorite = input("Favorite: ")
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE language = ?", favorite)

# Acessar resultado
row = rows[0]
print(row["n"])
```

> Sempre use `?` como placeholder para evitar SQL injection.

- `SQL()` conecta ao banco de dados.
- `("sqlite:///favorites.db")` fornece ao python a localização do arquivo de banco de dados
- `db.execute()` executa comandos SQL.
- `?` é substituído pelo valor da variável de forma segura.


## ⚠️ SQL Injection - Nunca faça isso!
```python
# ❌ INSEGURO - Vulnerável a ataques
query = f"SELECT * FROM users WHERE name = '{user_input}'"
db.execute(query)

# ✅ SEGURO - Use placeholders
db.execute("SELECT * FROM users WHERE name = ?", user_input)
```

> **SQL Injection**: Atacante pode inserir código SQL malicioso na entrada.

- Nunca use f-strings ou concatenação direta em SQL.
- Sempre use placeholders (`?`) para valores do usuário.
    - proteção contra códigos maliciosos 


## Tipos de dados SQLite
```sql
CREATE TABLE example (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    score REAL,
    data BLOB,
    created_at NUMERIC
);
```

- `INTEGER`: Números inteiros
- `TEXT`: Strings/texto
- `REAL`: Números decimais
- `BLOB`: Dados binários
- `NUMERIC`: Números formatados (datas)
- `PRIMARY KEY`: Chave primária única
- `NOT NULL`: Campo obrigatório


## Transações para evitar problemas
```sql
BEGIN TRANSACTION;
UPDATE accounts SET balance = balance - 100 WHERE id = 1;
UPDATE accounts SET balance = balance + 100 WHERE id = 2;
COMMIT;
```

> Transações garantem que operações relacionadas sejam executadas juntas.

- `BEGIN TRANSACTION`: Inicia transação
- `COMMIT`: Confirma todas as alterações
- `ROLLBACK`: Desfaz alterações se algo der errado