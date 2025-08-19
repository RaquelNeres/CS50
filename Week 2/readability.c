#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char texto[500];
    int letras = 0, palavras = 1, frases = 0; // palavra começa em 1

    printf("Text: ");
    scanf("%499[^\n]", texto); // continua mesmo com espaço até uma quebra de linha (\n)

    // strlen pra ver todas as letras
    // quando tiver " " quer dizer que é entre uma palabra e outra, ou seja, uma palavra

    for (int i = 0, f = (int) strlen(texto); i < f; i++)
    {
        if (isalpha(texto[i])) // conta letra
        {
            letras++;
        }

        if (texto[i] == ' ') // conta palavra
        {
            palavras++;
        }

        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?') // conta frase
        {
            frases++;
        }
    }

    float L = ((float) letras / palavras) * 100;
    float S = ((float) frases / palavras) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
