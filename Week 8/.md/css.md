# Comandos

## CSS Inline (direto na tag)
```
<p style="color: blue; font-size: 30px;">Texto azul e maior</p>
```
<p style="color: blue; font-size: 30px;">Texto azul e maior</p>

- O atributo style aplica CSS diretamente ao elemento.

- color: blue; muda a cor do texto.

- font-size: 18px; aumenta o tamanho da fonte.

## CSS em <'style> dentro do HTML
```
<style>
  h1 {
    color: red;
    text-align: center;
  }
</style>

<h1>Título centralizado em vermelho</h1>
```
<style>
  h1 {
    color: red;
    text-align: center;
  }
</style>

<h1>Título centralizado em vermelho</h1>

- O bloco <'style> permite aplicar regras de estilo para várias tags.

- h1 { ... } aplica estilo a todos os <'h1> da página.

- text-align: center; centraliza o texto.

## Classes e IDs
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
