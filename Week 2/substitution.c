#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int qarg, char *arg[])
{
    // n de argumentos
    if (qarg != 2) // o proprio sistema operacional diz o n de argumentos, separados por ' ', que
                   // usuario passou
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *chave = arg[1]; // key

    // VERIFICAÇÃO APENAS
    // ------------------------------------------------------------------------
    // 26 caracteres
    if (strlen(chave) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(chave[i])) // se caracteres são letras
        {
            printf("Key must only contain letters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++) // se não há repetição
        {
            if (toupper(chave[i]) == toupper(chave[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    // ------------------------------------------------------------------------

    // plaintext
    char texto[50];
    printf("plaintext: ");
    scanf(" %[^\n]", texto);

    // decodificar
    printf("ciphertext: ");
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isalpha(texto[i])) // alfabético
        {
            if (isupper(texto[i])) // maiúsculo
            {
                int index = texto[i] - 'A';          // indice do "alfabeto" da letra na chave
                printf("%c", toupper(chave[index])); // converter para maiúsculas
            }
            else
            {
                int index = texto[i] - 'a';
                printf("%c", tolower(chave[index]));
            }
        }
        else
        {
            printf("%c", texto[i]);
        }
    }
    printf("\n");

    return 0;
}
