// get_string and printf with %s

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // nutella
    string answer = get_string("What's your name? "); // abreviação desnecessaria :^ (ja que teve a semana 0 pra introduzir as pessoas nesse mundo da programação)
    printf("hello, %s\n", answer);

    // raiz
    char nome[51];
    printf("Qual seu nome? ");
    scanf("%s", nome);   // aloca o input na variavel 'nome' que nem no assembly    MOV
    printf("Olá, %s\n", nome);
}
