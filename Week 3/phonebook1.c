// Implements a phone book with structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];

    people[0].name = "Yuliia";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
};


// Pessoa[] pessoas = new Pessoa[3]; // cria um array de 3 posições

// // ainda não existem objetos Pessoa, só o espaço para 3 referências
// pessoas[0] = new Pessoa(); // aqui sim você cria o objeto
// pessoas[0].nome = "Maria";
// pessoas[0].idade = 18;
// pessoas[0].sexo = 'F';
// pessoas[0].cpf = "123.456.789-00";
