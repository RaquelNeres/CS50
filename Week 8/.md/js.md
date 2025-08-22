# Exemplos

## Declaração de variáveis
```
<script>
  let nome = "Raquel";
  const idade = 19;
</script>
```

- let cria uma variável que pode mudar.

- const cria uma constante que não muda.

- O JavaScript não exige tipagem explícita (diferente do C).

## Exibir mensagem (alert)
```
<script>
  alert("Bem-vinda ao meu site!");
</script>
```

- Exibe uma caixinha pop-up no navegador.
- Bom pra testes rápidos, mas cuidado: atrapalha se usado em excesso.

## Manipular o DOM (Document Object Model)
```html
<h1 id="titulo">Olá!</h1>
<button onclick="mudarTexto()">Clique aqui</button>

<script>
  function mudarTexto() {
    document.getElementById("titulo").innerHTML = "Você clicou no botão!";
  }
</script>
```

(Clique no botão e o texto mudaria!)

- document.getElementById("...") pega um elemento do HTML.

- .innerHTML muda o conteúdo dentro dele.

- onclick="..." executa uma função quando o botão é clicado.

OU (para mudar a cor da pag ao elemento ser clicado)

```html
<body>
    <button id="red">R</button>
    <button id="green">G</button>
    <button id="blue">B</button>
    <script>

        let body = document.querySelector('body');
        document.querySelector('#red').addEventListener('click', function() {
            body.style.backgroundColor = 'red';
        });
        document.querySelector('#green').addEventListener('click', function() {
            body.style.backgroundColor = 'green';
        });
        document.querySelector('#blue').addEventListener('click', function() {
            body.style.backgroundColor = 'blue';
        });

    </script>
</body>
```

## Eventos de teclado
```html
<input id="campo" placeholder="Digite algo">

<script>
  document.getElementById("campo").onkeyup = function() {
    alert("Você digitou: " + this.value);
  };
</script>
```

- .onkeyup dispara quando o usuário solta uma tecla.

- this.value pega o texto digitado no input.

## Condicionais e loops
```html
<script>
  for (let i = 1; i <= 3; i++) {
    console.log("Número " + i);
  }

  let idade = 19;
  if (idade >= 18) {
    console.log("Maior de idade");
  } else {
    console.log("Menor de idade");
  }
</script>
```

- console.log(...) escreve mensagens no console do navegador (f12 → aba console).

## Intervalo de tempo de execução
```html
<head>
  <script>

      // Alterna a visibilidade da saudação
      function blink()
      {
          let body = document.querySelector('body');
          if (body.style.visibility == 'hidden')
          {
              body.style.visibility = 'visible';
          }
          else
          {
              body.style.visibility = 'hidden';
          }
      }

      // Pisca a cada 500ms
      window.setInterval(blink, 500);

  </script>
  <title>blink</title>
</head>
<body>
  hello, world
</body>
```

- Esse exemplo pisca  o texto em um intervalo de tempo
- `window.setInterval(blink, 500)` recebe a função a ser chamada e o periodo de espera(milissegundos) entre as chamadas de função 

