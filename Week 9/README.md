
# CS50 – Semana 9: Flask, Python e SQL

## ✅ Flask: Estrutura Básica
- **Flask** é um micro framework em Python para criar aplicações web.
- **Código básico:**

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "Hello, world!"

if __name__ == "__main__":
    app.run()
```

### 🔹 Comandos importantes
- `Flask(__name__)` → Cria o app Flask (para que saiba onde está a aplicação).
- `@app.route("/")` → Define a rota.
- `index()` → Função que será executada quando acessarmos essa rota.
- `app.run()` → Inicia o servidor.


## ✅ Templates HTML com Flask
- **Renderizando HTML:**

```python
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")
```

- **Templates** ficam em uma pasta chamada `templates/`.


## ✅ Passando variáveis para HTML
```python
@app.route("/")
def index():
    name = "Raquel"
    return render_template("index.html", name=name)
```
- Caso seja um GET (primeira vez que a página é carregada), ele retorna o template index.html (a página com o formulário).

No HTML:
```html
<h1>Hello, {{ name }}!</h1>
```


## ✅ CSS e Arquivos Estáticos
- Criar pasta `static/` para CSS, imagens, JS.
- Exemplo no HTML:
```html
<link rel="stylesheet" href="{{ url_for('static', filename='style.css') }}">
```


## ✅ Formularios com Flask
```python
from flask import request

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form.get("username")
        return f"Bem-vindo, {username}!"
    return render_template("login.html")
```
- Verifica se a requisição é do tipo POST (significa que o formulário foi enviado).
- `request.form.get("name")` → Pega o valor do campo `name` enviado pelo formulário.
- `render_template("greet.html", name=...)` → Renderiza o template greet.html e envia a variável name para ele.

## ✅ Flask e Banco de Dados (SQL)
- Usando **SQLite** com Flask:
```python
import sqlite3

conn = sqlite3.connect("banco.db")
cursor = conn.cursor()
cursor.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT)")
conn.commit()
conn.close()
```


## ✅ ORM com SQLAlchemy
```python
from flask_sqlalchemy import SQLAlchemy

app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///banco.db"
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(100), nullable=False)
```


## ✅ Sessões no Flask
```python
from flask import session

app.secret_key = "segredo"

@app.route("/login", methods=["POST"])
def login():
    session["user"] = request.form.get("username")
    return "Login feito!"
```


## ✅ Deploy no Flask
- **Debug Mode:** `app.run(debug=True)`
- **Servidor de produção:** usar **Gunicorn** ou outro WSGI.


### 🔹 Principais Comandos Resumidos
---
| Comando/Conceito      | Descrição |
|------------------------|-----------|
| `Flask(__name__)`      | Cria o app |
| `@app.route()`         | Define rotas |
| `render_template()`    | Renderiza HTML |
| `request.form.get()`   | Pega dados do formulário |
| `session["key"]`       | Armazena sessão |
| `sqlite3.connect()`    | Conecta ao banco SQLite |
| `SQLAlchemy`           | ORM para banco de dados |
| `debug=True`           | Ativa modo debug |

---

📌 Flask. Route. Decorators. Requests, Responses. Sessions. Cookies.
