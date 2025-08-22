# Comandos

## Compativel com dispositivos moveis
```html
<head>
  <meta name="viewport" content="inicial-scale=1, width=device-width">
  <title>meta</title>
</head>
```

## Tags de parágrafo para abrir e fechar um parágrafo 
```html
<p>…texto…</p>  
```
> <p>…texto…</p> 

--- 
## Cabeçalhos e links:

```html
<h1>Meu título</h1>
<a href="https://www.exemplo.com">Link</a>
```

> <h1>Meu título</h1>
> <a href="https://www.exemplo.com">Link</a>

- Cabeçalhos (<'h1> até <'h6>) definem títulos hierárquicos: <'h1> é o maior e mais importante, <'h6> o menor.

- A tag <'a> cria um link. O atributo href define para onde o link vai levar.

### Link entre varias pags da web
```html
<body>
  Visite  <a href="image.html">Harvard</a>
</body>
```
<body>
  Visite  <a href="image.html">Harvard</a>
</body>

--- 
## Formulário com atributos:
```html
<form action="https://www.google.com/search" method="get">
  <input autocomplete="off" autofocus name="q" placeholder="Buscar" type="search">
  <button>Pesquisar</button> <!-- <input type="submit" value="Pesquisa"> -->
</form>
```
<form action="https://www.google.com/search" method="get">
  <input autocomplete="off" autofocus name="q" placeholder="Buscar" type="search">
  <button>Pesquisar</button>
  <input type="submit" value="Pesquisa">
</form>


- <'form> cria um formulário.

- action indica para onde os dados serão enviados (no exemplo, para o Google).

- method="get" envia os dados pela URL.

- <'input> cria campos de entrada:

- autocomplete="off" desativa sugestões automáticas.

- autofocus faz o cursor já começar nesse campo.

- name="q" define o nome da variável enviada.

- placeholder="Buscar" mostra um texto de sugestão dentro do campo.

- type="search" estiliza o input como barra de busca.

- 'button> envia o formulário.

--- 
## Validação com regex (pattern):
```html
<input name="email" type="email" pattern=".+@.+\.edu" placeholder="Email">
```
<input name="email" type="email" pattern=".+@.+\.edu" placeholder="Email">

- O atributo pattern=".+@.+\.edu" exige que o email termine com .edu.

- Exemplo válido: raquel@faculdade.edu.

- Se não seguir esse padrão, o navegador bloqueia o envio do formulário.

## Imagem
```html
<img src="https://via.placeholder.com/150" alt="Imagem exemplo">
```

- `<img>` insere imagens.

- `src` define a URL ou caminho do arquivo.

- `alt` é o texto alternativo (mostrado se a imagem não carregar e usado por leitores de tela).

## Lista
```html
<ul>
  <li>Item 1</li>
  <li>Item 2</li>
</ul>

<ol>
  <li>Primeiro</li>
  <li>Segundo</li>
</ol>
```
<ul>
  <li>Item 1</li>
  <li>Item 2</li>
</ul>

<ol>
  <li>Primeiro</li>
  <li>Segundo</li>
</ol>

- ``<ul>`` cria uma lista não ordenada (com marcadores).

- ``<ol>`` cria uma lista ordenada (numerada).

- ``<li>`` representa cada item da lista.

## Vídeos e Áudios
```html
<video controls>
  <source src="video.mp4" type="video/mp4">
</video>

<audio controls>
  <source src="musica.mp3" type="audio/mpeg">
</audio>
```
<video controls>
  <source src="video.mp4" type="video/mp4">
</video>

<audio controls>
  <source src="musica.mp3" type="audio/mpeg">
</audio>

- <'video> e <'audio> inserem mídia.

- controls adiciona os botões de play/pause.

- <'source> indica o arquivo e o tipo.

