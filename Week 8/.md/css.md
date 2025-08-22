# Comandos

## CSS Inline (direto na tag)
```html
<p style="color: blue; font-size: 30px;">Texto azul e maior</p>
```
<p style="color: blue; font-size: 30px;">Texto azul e maior</p>

- O atributo style aplica CSS diretamente ao elemento.

- color: blue; muda a cor do texto.

- font-size: 18px; aumenta o tamanho da fonte.

## CSS em <'style> dentro do HTML
```html
<head>
  <style>
    h1 {
      color: red;
      text-align: center;
    }
  </style>
</head>

<h1>Título centralizado em vermelho</h1>
```

<head>
  <style>
    h1 {
      color: red;
      text-align: center;
    }
  </style>
</head>

<h1>Título centralizado em vermelho</h1>

- O bloco <'style> permite aplicar regras de estilo para várias tags.

- h1 { ... } aplica estilo a todos os <'h1> da página.

- text-align: center; centraliza o texto.

## Classes e IDs
```html
<style>
  .destaque {
    background-color: yellow;
    color: black;
  }
  #especial {
    font-weight: bold;
    color: green;
  }
</style>

<p class="destaque">Texto com fundo amarelo</p>
<p id="especial">Texto verde e em negrito</p>
```
<style>
  .destaque {
    background-color: yellow;
    color: black;
  }
  #especial {
    font-weight: bold;
    color: green;
  }
</style>

<p class="destaque">Texto com fundo amarelo</p>
<p id="especial">Texto verde e em negrito</p>

- .classe estiliza todos os elementos com class="...".

- #id estiliza apenas o elemento com id="...".

## Para chamar o codigo do arquivo .css
```html
<head>
  <link href="style.css" rel="styleheet">
  <title>css</title>
</head>
```

## Bootstrap
```html
<head>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
  <title>favorites</title>
</head>
```
Visite a <a href="https://getbootstrap.com/docs/4.1/getting-started/introduction/" >documentação do Bootstrap</a>

- Similar às bibliotecas de terceiros que podemos aproveitar no Python, existem bibliotecas de terceiros chamadas frameworks que podemos utilizar com nossos arquivos HTML.
- Bootstrap é uma dessas estruturas que podemos usar para embelezar nosso HTML e aperfeiçoar facilmente elementos de design de forma que nossas páginas fiquem mais legíveis.