// Função para mostrar mensagem
function mostrarMensagem() {
    document.getElementById("mensagem").innerText = "🎉 Você clicou no botão!";
}

// Exemplo de validação simples
document.getElementById("cadastroForm").addEventListener("submit", function(event) {
    event.preventDefault(); // impede envio real só para teste
    alert("Cadastro realizado com sucesso! ✅");
});
